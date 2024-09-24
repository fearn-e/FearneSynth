/*
  ==============================================================================

    Oscillator.cpp
    Created: 25 Apr 2023 12:15:35am
    Author:  Ellie

  ==============================================================================
*/

#include <cmath>
#include "Oscillator.h"

Oscillator::Oscillator(Waveshape f_waveshape) : active(0), level(0.0), velocity(0.0), productLevel(0.0), waveshape(f_waveshape) {}

void Oscillator::setWaveshape(Waveshape f_waveshape) {
    waveshape = f_waveshape;
}

void Oscillator::noteOn(float f_velocity) {
    if (waveshape == INACTIVE) {
        active = false;
    }
    else {
        active = true;
        velocity = f_velocity;
        productLevel = f_velocity * level / 4; // divide by 4 to avoid going over 1.0 gain at this lowest level stage
    }
}

void Oscillator::setLevel(float f_level) {
    level = f_level;
    productLevel = velocity * f_level / 4;
}

bool Oscillator::isActive() const {
    return active;
}

float Oscillator::getNextSample(float f_phase) {
    float sample = 0.0;
    switch(waveshape) {
    case INACTIVE:
        break; // do nothing, sample already 0.0
    case SINE:
        sample = std::sin(2 * PI * f_phase);
        break;
    case SQUARE:
        sample = (f_phase < 0.5) ? 1.0 : -1.0;
        break;
    case SAW:
        sample = (2.0 * f_phase) - 1.0;
        break;
    case TRIANGLE:
        sample = (4.0 * std::abs(f_phase - 0.5)) - 1.0;
        break;
    }
    return sample * productLevel;
}
