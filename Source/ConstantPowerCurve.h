/*
  ==============================================================================

    ConstantPowerCurve.h
    Created: 14 May 2023 6:48:00pm
    Author:  Ellie

  ==============================================================================
*/

#pragma once
#include <array>
#include "PiDef.h"

class ConstantPowerCurve {
public:
    ConstantPowerCurve();

    void setInputRange(float f_inputMin, float f_inputMax);
    void setPosition(float f_panPosition);

    float getChannelMultiplier(bool f_channel) const;

private:
    float scaleInput(float input);

    float inputMin, inputMax, outputMin, outputMax;

    std::array<float, 2> constantPowerChannelMultiplier;
};