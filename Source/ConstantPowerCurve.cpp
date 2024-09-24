/*
  ==============================================================================

    ConstantPowerCurve.cpp
    Created: 14 May 2023 6:48:00pm
    Author:  Ellie

  ==============================================================================
*/

#include "ConstantPowerCurve.h"
//useful for things such as pans, dry/wet ratios, etc - where 1 value needs to be scaled to 2 channels and
//maintain a constant power curve

ConstantPowerCurve::ConstantPowerCurve() : 
    inputMin(-1.0), inputMax(1.0), outputMin(0.0), outputMax(2.0), 
    constantPowerChannelMultiplier({0.0, 0.0}) {

    setPosition(0.0);
}

//set the range inputs will be arriving in and should be scaled from
void ConstantPowerCurve::setInputRange(float f_inputMin, float f_inputMax) {
    inputMin = f_inputMin;
    inputMax = f_inputMax;
}


void ConstantPowerCurve::setPosition(float f_position) {
    if (f_position >= inputMin && f_position <= inputMax)
    {
        f_position = scaleInput(f_position);
        //calculate coefficient from UI slider position
        float constantPowerCoefficient = (PI * f_position) / 4.0;

        //uses the coefficient to calculate multipliers for channels 0 and 1 to achieve a constant power effect
        constantPowerChannelMultiplier[0] = cos(constantPowerCoefficient);
        constantPowerChannelMultiplier[1] = sin(constantPowerCoefficient);
    }
}

float ConstantPowerCurve::scaleInput(float input) {
    // Normalize input value to range [0, 1]
    float normalized = (input - inputMin) / (inputMax - inputMin);

    // Scale normalized value to output range
    float output = outputMin + normalized * (outputMax - outputMin);

    return output;
}

float ConstantPowerCurve::getChannelMultiplier(bool f_channel) const {
    return constantPowerChannelMultiplier[f_channel];
}