/*
  ==============================================================================

    VoiceManager.h
    Created: 25 Apr 2023 12:15:25am
    Author:  Ellie

  ==============================================================================
*/

#pragma once

#include <vector>
#include <queue>
#include <deque>
#include "Voice.h"
#include "EnumDefs.h"

class VoiceManager {
public:
    VoiceManager(int f_numVoices = 8, int f_numBenchVoices = 2, double f_sampleRate = 44100);

    void setSampleRate(double f_sampleRate);
    void interfaceControlRouting(InterfaceRoutingAddresses f_routingDestination, float f_value);
    void noteOn(int f_midiPitch, int f_midiVelocity);
    void noteOff(int f_midiPitch);
    void pitchBend(float f_midiPitchBend);

    std::array<float, 2> getNextSample();

private:
    std::size_t sampleCounter;

    std::queue<int> freeVoices;
    std::deque<int> activeVoices;
    std::queue<int> benchVoices;
    std::vector<Voice> voices;
};