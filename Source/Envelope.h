/*
  ==============================================================================

    Envelope.h
    Created: 25 Apr 2023 12:15:40am
    Author:  Ellie

  ==============================================================================
*/


#pragma once
#include <cstddef>
#include "EnumDefs.h"

class Envelope {
public:
    Envelope(std::size_t f_attack = 2205, std::size_t f_decay = 17640, float f_sustain = 0.5, std::size_t f_release = 26460);

    void setAttack(std::size_t f_attackSamples);
    void setDecay(std::size_t f_decaySamples);
    void setSustain(float f_sustainLevel);
    void setRelease(std::size_t f_releaseSamples);

    int getState() const;

    void noteOn(const std::size_t& f_sampleCounter);
    void noteOff(const std::size_t& f_sampleCounter);
    void stolenQuickOff(const std::size_t& f_sampleCounter);

    float getNextSample(const std::size_t& f_sampleCounter);

private:
    std::size_t attackSamples, decaySamples, releaseSamples, stolenReleaseSamples;
    float sustainLevel;

    EnvelopeState state;

    float levelMultiplier, stateStartLevel;
    std::size_t stateStartSample;

    void setStateStartValues(const std::size_t& f_sampleCounter);

};

