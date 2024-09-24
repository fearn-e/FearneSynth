/*
  ==============================================================================

    DelayArray.cpp
    Created: 14 May 2023 5:50:02pm
    Author:  Ellie

  ==============================================================================
*/

#include "DelayArray.h"

DelayArray::DelayArray() : dryAmount(1.0), wetAmount(0.0), wetSample( {0.0, 0.0} ), delayUnitBank_(), dryWetScaler_() {
    dryWetScaler_.setInputRange(0.0, 100.0);
}

void DelayArray::initBuffers(double f_sampleRate, float f_maxDelaySeconds) {
    //create circular buffers
    for (int i = 0; i < delayUnitBank_.size(); ++i) {
        delayUnitBank_[i].initBuffer(f_sampleRate, f_maxDelaySeconds);
    }
}

void DelayArray::interfaceControlRouting(InterfaceRoutingAddresses f_routingDestination, float f_value) {
    //route ui messages
    if (f_routingDestination >= DELAY_UNIT_OUTPUT_LEVEL_0 && f_routingDestination <= DELAY_UNIT_OUTPUT_LEVEL_LAST) {
        delayUnitBank_[f_routingDestination - DELAY_UNIT_OUTPUT_LEVEL_0].setUnitOutputLevel(f_value);

    } else if (f_routingDestination >= DELAY_UNIT_TIME_LEFT_0 && f_routingDestination <= DELAY_UNIT_TIME_LEFT_LAST) {
        delayUnitBank_[f_routingDestination - DELAY_UNIT_TIME_LEFT_0].setDelayTime(0, f_value);

    } else if (f_routingDestination >= DELAY_UNIT_TIME_RIGHT_0 && f_routingDestination <= DELAY_UNIT_TIME_RIGHT_LAST) {
        delayUnitBank_[f_routingDestination - DELAY_UNIT_TIME_RIGHT_0].setDelayTime(1, f_value);

    } else if (f_routingDestination == DELAY_FEEDBACK_AMOUNT) {
        delayUnitBank_[0].setFeedbackAmount(f_value);

    } else if (f_routingDestination == DELAY_WET_SIGNAL_PERCENTAGE) {
        dryWetScaler_.setPosition(f_value);
        dryAmount = dryWetScaler_.getChannelMultiplier(0);
        wetAmount = dryWetScaler_.getChannelMultiplier(1);
    }
}

void DelayArray::killDelay() {
    for (int i = 0; i < delayUnitBank_.size(); ++i) {
        delayUnitBank_[i].clearBuffer(false);
    }
}

std::array<float, 2> DelayArray::getNextSample(std::array<float, 2> f_originalSample) {
    std::array<float, 2> tempSample = { 0.0, 0.0 };

    //process first delay unit with previous output as feedback
    tempSample = delayUnitBank_[0].getNextSample(f_originalSample, wetSample);
    wetSample = tempSample;

    //process second delay unit with zero inputs as feedback
    tempSample = delayUnitBank_[1].getNextSample(tempSample, { 0.0, 0.0 });
    wetSample[0] += tempSample[0];
    wetSample[1] += tempSample[1];

    //process third delay unit with zero inputs as feedback
    tempSample = delayUnitBank_[2].getNextSample(tempSample, { 0.0, 0.0 });
    wetSample[0] += tempSample[0];
    wetSample[1] += tempSample[1];

    //combine dry and wet signals
    for (int i = 0; i < tempSample.size(); ++i) {
        tempSample[i] = (f_originalSample[i] * dryAmount) + (wetSample[i] * wetAmount);
    }

    return tempSample;
}