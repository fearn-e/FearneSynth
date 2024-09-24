/*
  ==============================================================================

    Envelope.cpp
    Created: 25 Apr 2023 12:15:40am
    Author:  Ellie

  ==============================================================================
*/

#include "Envelope.h"
#include <limits>


Envelope::Envelope(std::size_t f_attack, std::size_t f_decay, float f_sustain, std::size_t f_release) : attackSamples(f_attack), decaySamples(f_decay), sustainLevel(f_sustain), releaseSamples(f_release), state(IDLE), stolenReleaseSamples(100), levelMultiplier(0.0), stateStartLevel(0.0), stateStartSample(0) {}

void Envelope::setAttack(std::size_t f_attackSamples) {
    attackSamples = f_attackSamples;
}

void Envelope::setDecay(std::size_t f_decaySamples) {
    decaySamples = f_decaySamples;
}

void Envelope::setSustain(float f_sustainLevel) {
    sustainLevel = f_sustainLevel;
}

void Envelope::setRelease(std::size_t f_releaseSamples) {
    releaseSamples = f_releaseSamples;
}

int Envelope::getState() const {
    return state;
}

void Envelope::noteOn(const std::size_t& f_sampleCounter) {
    state = ATTACK;
    setStateStartValues(f_sampleCounter);
}

void Envelope::noteOff(const std::size_t& f_sampleCounter) {
    state = RELEASE;
    setStateStartValues(f_sampleCounter);
}

void Envelope::stolenQuickOff(const std::size_t& f_sampleCounter) {
    state = STOLEN;
    setStateStartValues(f_sampleCounter);
}

float Envelope::getNextSample(const std::size_t& f_sampleCounter) {

    if (state == IDLE) {
        levelMultiplier = 0.0;
    } else if (state == SUSTAIN) {
        levelMultiplier = sustainLevel;
    } else {
        std::size_t samplesElapsed;
        //check how many samples since ATTACK state began
        if (f_sampleCounter >= stateStartSample) {
            samplesElapsed = f_sampleCounter - stateStartSample;
        } else {
            //takes care of if there was an overflow in the std::size_t in the middle of the envelope
            samplesElapsed = (std::numeric_limits<std::size_t>::max()) - stateStartSample + f_sampleCounter + 1;
        }
        switch(state) {
        case ATTACK:
            levelMultiplier = stateStartLevel + (1.0 - stateStartLevel) * (static_cast<float>(samplesElapsed) / attackSamples);
            if (samplesElapsed >= attackSamples) {
                state = DECAY;
                levelMultiplier = 1.0;
                stateStartSample = f_sampleCounter;
            }
            break;
        case DECAY:
            levelMultiplier = sustainLevel + (1.0 - sustainLevel) * (1.0 - (static_cast<float>(samplesElapsed) / decaySamples));
            if (samplesElapsed >= decaySamples) {
                state = SUSTAIN;
                levelMultiplier = sustainLevel;
            }
            break;
        case RELEASE:
            levelMultiplier = stateStartLevel * (1.0 - (static_cast<float>(samplesElapsed) / releaseSamples));
            if (samplesElapsed >= releaseSamples) {
                state = IDLE;
                levelMultiplier = 0.0;
            }
            break;
        case STOLEN:
            levelMultiplier = stateStartLevel * (1.0 - (static_cast<float>(samplesElapsed) / stolenReleaseSamples));
            if (samplesElapsed >= stolenReleaseSamples) {
                state = IDLE;
                levelMultiplier = 0.0;
            }
            break;
        }
    }

    return levelMultiplier;
}

void Envelope::setStateStartValues(const std::size_t& f_sampleCounter) {
    stateStartSample = f_sampleCounter;
    stateStartLevel = levelMultiplier;
}