/*
  ==============================================================================

    Voice.cpp
    Created: 25 Apr 2023 12:15:30am
    Author:  Ellie

  ==============================================================================
*/

#include "Voice.h"

Voice::Voice(double f_sampleRate) : sampleRate(f_sampleRate), noteValue(69.0), pitchBendAmount(0.0),
active(false), currentPitch(-1), envelopeBank_(), oscillatorBank_(), panBank_(),
phaseBank({ 0.0,0.0,0.0,0.0 }), phaseIncrementBank({ 0.0,0.0,0.0,0.0 }), 
detuneCentsBank({ 0.0,0.0,0.0,0.0 }), detuneNotesBank({ 0.0,0.0,0.0,0.0 }) {
    
    oscillatorBank_[0].setWaveshape(SINE);
    for (int i = 0; i < panBank_.size(); ++i) {
        panBank_[i].setInputRange(-50.0, 50.0);
    }
}

void Voice::interfaceControlRouting(InterfaceRoutingAddresses f_routingDestination, float f_value) {
    //route ui values
    if (f_routingDestination >= ENV_ATTACK_REAL_0 && f_routingDestination <= ENV_ATTACK_REAL_LAST) {
        envelopeBank_[f_routingDestination - ENV_ATTACK_REAL_0].setAttack(calculateEnvelopeSampleLength(f_value));

    } else if (f_routingDestination >= ENV_DECAY_REAL_0 && f_routingDestination <= ENV_DECAY_REAL_LAST) {
        envelopeBank_[f_routingDestination - ENV_DECAY_REAL_0].setDecay(calculateEnvelopeSampleLength(f_value));

    } else if (f_routingDestination >= ENV_SUSTAIN_0 && f_routingDestination <= ENV_SUSTAIN_LAST) {
        envelopeBank_[f_routingDestination - ENV_SUSTAIN_0].setSustain(f_value);

    } else if (f_routingDestination >= ENV_RELEASE_REAL_0 && f_routingDestination <= ENV_RELEASE_REAL_LAST) {
        envelopeBank_[f_routingDestination - ENV_RELEASE_REAL_0].setRelease(calculateEnvelopeSampleLength(f_value));

    } else if (f_routingDestination >= OSC_WAVESHAPE_0 && f_routingDestination <= OSC_WAVESHAPE_LAST) {
        oscillatorBank_[f_routingDestination - OSC_WAVESHAPE_0].setWaveshape(static_cast<Waveshape>(f_value + std::numeric_limits<float>::epsilon()));
    
    } else if (f_routingDestination >= OSC_LEVEL_0 && f_routingDestination <= OSC_LEVEL_LAST) {
        oscillatorBank_[f_routingDestination - OSC_LEVEL_0].setLevel(f_value);

    } else if (f_routingDestination >= OSC_PAN_0 && f_routingDestination <= OSC_PAN_LAST) {
        panBank_[f_routingDestination - OSC_PAN_0].setPosition(f_value);
    
    } else if (f_routingDestination >= OSC_DETUNE_NOTES_0 && f_routingDestination <= OSC_DETUNE_NOTES_LAST) {
        detuneNotesBank[f_routingDestination - OSC_DETUNE_NOTES_0] = f_value;

    } else if (f_routingDestination >= OSC_DETUNE_CENTS_0 && f_routingDestination <= OSC_DETUNE_CENTS_LAST) {
        detuneCentsBank[f_routingDestination - OSC_DETUNE_CENTS_0] = f_value;
    }
}

void Voice::setSampleRate(double f_sampleRate) {
    sampleRate = f_sampleRate;

    for (int i = 0; i < phaseIncrementBank.size(); ++i) {
        phaseIncrementBank[i] = calculatePhaseIncrement(i);
    }
}

void Voice::setPitchBend(float f_pitchBendAmount) {
    pitchBendAmount = f_pitchBendAmount;
    for (int i = 0; i < phaseIncrementBank.size(); ++i) {
        phaseIncrementBank[i] = calculatePhaseIncrement(i);
    }
}

void Voice::noteOn(int f_currentPitch, float f_midiPitch, float f_midiVelocity, const std::size_t& f_sampleCounter) {
    noteValue = f_midiPitch;
    for (int i = 0; i < phaseIncrementBank.size(); ++i) {
        phaseIncrementBank[i] = calculatePhaseIncrement(i);
    }

    //send velocity levels to each oscillator
    float scaledVelocityLevel = f_midiVelocity / 127.0;
    for (auto& oscillator : oscillatorBank_) {
        oscillator.noteOn(scaledVelocityLevel);
    }

    //for each active oscillator, send a noteon message to its corresponding envelope
    for (int i = 0; i < envelopeBank_.size(); ++i) {
        if (oscillatorBank_[i].isActive()) {
            envelopeBank_[i].noteOn(f_sampleCounter);
        }
    }

    active = true;
    //currentPitch used for finding the correct voice for noteOff messages
    currentPitch = f_currentPitch;
}

void Voice::noteOff(const std::size_t& f_sampleCounter) {
    //for each envelope that is not already idle, send a message to set state to RELEASE
    for (auto& envelope : envelopeBank_) {
        if (envelope.getState() != IDLE) {
            envelope.noteOff(f_sampleCounter);
        }
    }
    currentPitch = -1;
}

void Voice::stolenSwitchToBench(const std::size_t& f_sampleCounter) {
    //for each envelope that is not already idle, send a message to set state to STOLEN
    for (auto& envelope : envelopeBank_) {
        if (envelope.getState() != IDLE) {
            envelope.stolenQuickOff(f_sampleCounter);
        }
    }
    currentPitch = -1;
}

std::size_t Voice::calculateEnvelopeSampleLength(float f_lengthInSeconds) {
    return static_cast<std::size_t>((f_lengthInSeconds * sampleRate) + std::numeric_limits<float>::epsilon());
}

double Voice::calculatePhaseIncrement(std::size_t i) {
    //phase increment is the value by which phase is incremented every sample in the oscillators
    return midiToFrequency(noteValue + pitchBendAmount + detuneNotesBank[i] + detuneCentsBank[i]) / sampleRate;
}

std::array<float, 2> Voice::getNextSample(const std::size_t& f_sampleCounter) {
    if (active) {
        active = std::any_of(envelopeBank_.begin(), envelopeBank_.end(), [](const auto& envelope) {
            return envelope.getState() != IDLE;
            // iterate over every envelope in envelopeBank_
            // returns true as soon as first active envelope found, returns false if no active envelopes found
        });

        if (active) {
            std::array<float, 2> sample = { 0.0, 0.0 };
            float osc_env_sum = 0.0;

            //for each envelope that is not idle, call the process functions of the relevant oscillator envelope pair
            //and add them all up, multiplied by the panning multipliers
            for (int i = 0; i < oscillatorBank_.size(); ++i) {
                if (envelopeBank_[i].getState() != IDLE) {
                    osc_env_sum = oscillatorBank_[i].getNextSample(phaseBank[i]) * envelopeBank_[i].getNextSample(f_sampleCounter);
                    sample[0] += osc_env_sum * panBank_[i].getChannelMultiplier(0);
                    sample[1] += osc_env_sum * panBank_[i].getChannelMultiplier(1);
                }
            }
            //increment phase for oscillators
            for (int i = 0; i < phaseBank.size(); ++i) {
                phaseBank[i] += phaseIncrementBank[i];
                if (phaseBank[i] >= 1.0) phaseBank[i] -= 1.0;
            }

            return sample;
        }
        else {
            //if this sample went from active envelopes to zero active envelopes, reset phase back to 0.0
            for (auto phase : phaseBank) {
                phase = 0.0;
            }
        }
    }
    return {0.0, 0.0};
}

bool Voice::isActive() const {
    return active;
}

int Voice::getCurrentPitch() const {
    return currentPitch;
}

float Voice::midiToFrequency(float f_midiPitch) {
    //clip midi pitch values (possible to go outside due to detuning and pitch bend)
    if (f_midiPitch > 127.0) f_midiPitch = 127.0;
    else if (f_midiPitch < 0.0) f_midiPitch = 0.0;
    //convert midi pitch to frequency, regular 12 tone equal temperament
    return 440.0 * std::pow(2.0, (f_midiPitch - 69.0) / 12.0);
}