/*
  ==============================================================================

    VoiceManager.cpp
    Created: 25 Apr 2023 12:15:25am
    Author:  Ellie

  ==============================================================================
*/

#include "VoiceManager.h"

VoiceManager::VoiceManager(int f_numVoices, int f_numBenchVoices, double f_sampleRate) : voices(f_numVoices + f_numBenchVoices), sampleCounter(0) {
    // assign a voice index to every free voice
    for (int i = 0; i < f_numVoices; i++) {
        freeVoices.push(i);
    }
    // assign a voice index to every bench voice - these are used for quick release tail ends when stealing a voice
    for (int i = 0; i < f_numBenchVoices; i++) {
        benchVoices.push(f_numVoices + i);
    }

    setSampleRate(f_sampleRate);
}

void VoiceManager::setSampleRate(double f_sampleRate) {
    for (auto& voice : voices) {
        voice.setSampleRate(f_sampleRate);
    }
}

void VoiceManager::interfaceControlRouting(InterfaceRoutingAddresses f_routingDestination, float f_value) {
    //route ui values
    for (auto& voice : voices) {
        voice.interfaceControlRouting(f_routingDestination, f_value);
    }
}

void VoiceManager::noteOn(int f_midiPitch, int f_midiVelocity) {
    if (!freeVoices.empty()) { //a voice is available
        // note: voice stealing in RELEASE state already possible since voices are freed up at noteOff, not when release is over
        //get the voice that's been free for longest from the list
        int voiceIndex = freeVoices.front();
        //unmark voice as free
        freeVoices.pop();
        //mark voice as active
        activeVoices.push_back(voiceIndex);
        //send note on message to voice
        voices[voiceIndex].noteOn(f_midiPitch, static_cast<float>(f_midiPitch), static_cast<float>(f_midiVelocity), sampleCounter);
    } else { //adds extra voice stealing for when all voices are active

        //get voice that's been active for longest from list - voice A
        int stolenVoiceIndex = activeVoices.front();
        //get voice that's been free for longest in the bench voice list - voice B
        int replacementVoiceIndex = benchVoices.front();

        //unmark voice A as active
        activeVoices.pop_front();
        //unmark voice B as bench
        benchVoices.pop();
        //mark voice B as active
        activeVoices.push_back(replacementVoiceIndex);
        //mark voice A as bench
        benchVoices.push(stolenVoiceIndex);

        //tell voice A to quickly shut itself off - a few hundred samples of a release tail
        voices[stolenVoiceIndex].stolenSwitchToBench(sampleCounter);
        //send voice B the new note on message
        voices[replacementVoiceIndex].noteOn(f_midiPitch, static_cast<float>(f_midiPitch), static_cast<float>(f_midiVelocity), sampleCounter);
        
        //voice B has now fully replaced voice A in the main voice list
        //voice A has become a bench voice, and will be fully ready to take over a stolen voice itself very shortly
    }
}

void VoiceManager::noteOff(int f_midiPitch) {
    for (int i = 0; i < static_cast<int>(voices.size()); ++i) {
        Voice& currentVoice = voices[i];
        //test each voice if it is active and has the same pitch as the noteoff message
        if (currentVoice.isActive() && currentVoice.getCurrentPitch() == f_midiPitch) {
            //send voice a note off message
            currentVoice.noteOff(sampleCounter);
            //mark voice as free
            freeVoices.push(i);
            // Find the voice index in active voice list and remove it
            for (auto it = activeVoices.begin(); it != activeVoices.end(); ++it) {
                if (*it == i) {
                    activeVoices.erase(it);
                    break; //no need to look further
                }
            }
            //this removes all voices tagged with the same midi pitch as the note off message, not just one
            //robust if there is ever an event where a voice is accidentally missed
        }
    }
}

void VoiceManager::pitchBend(float f_midiPitchBend) {
    for (auto& voice : voices) {
        voice.setPitchBend(f_midiPitchBend);
    }
}

std::array<float, 2> VoiceManager::getNextSample() {
    std::array<float, 2> sampleValue = {0.0, 0.0};
    std::array<float, 2> tempValue = { 0.0, 0.0 };
    //combine outputs from every voice, only iterate over active voices for speed
    for (auto& voice : voices) {
        if (voice.isActive()) {
            tempValue = voice.getNextSample(sampleCounter);
            sampleValue[0] += tempValue[0];
            sampleValue[1] += tempValue[1];
        }
    }
    ++sampleCounter;
    return sampleValue;
}