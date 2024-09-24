/*
  ==============================================================================

    DelayArray.h
    Created: 14 May 2023 5:50:02pm
    Author:  Ellie

  ==============================================================================
*/

#pragma once

#include "DelayUnit.h"
#include <array>
#include <algorithm>
#include "EnumDefs.h"
#include "ConstantPowerCurve.h"

class DelayArray {
public:
    DelayArray();

    void initBuffers(double f_sampleRate, float f_maxDelaySeconds);

    void interfaceControlRouting(InterfaceRoutingAddresses f_routingDestination, float f_value);

    void killDelay();

    std::array<float, 2> getNextSample(std::array<float, 2> f_originalSample);

private:
    float dryAmount, wetAmount;
    ConstantPowerCurve dryWetScaler_;

    std::array<float, 2> wetSample;

    std::array<DelayUnit, delayBankSize> delayUnitBank_;
};