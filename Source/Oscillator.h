/*
  ==============================================================================

    Oscillator.h
    Created: 25 Apr 2023 12:15:35am
    Author:  Ellie

  ==============================================================================
*/

#pragma once

#include "PiDef.h"

enum Waveshape { INACTIVE, SINE, SQUARE, SAW, TRIANGLE };

class Oscillator {
public:
    Oscillator(Waveshape f_waveshape = INACTIVE);

    void setWaveshape(Waveshape f_waveshape);
    void noteOn(float f_velocity);
    void setLevel(float f_level);
    bool isActive() const;
    float getNextSample(float f_phase);

private:
    Waveshape waveshape;
    float level;
    float velocity;
    float productLevel;
    bool active;
};
