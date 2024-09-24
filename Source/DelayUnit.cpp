/*
  ==============================================================================

    DelayUnit.cpp
    Created: 14 May 2023 5:49:37pm
    Author:  Ellie

  ==============================================================================
*/

#include "DelayUnit.h"

DelayUnit::DelayUnit() : feedbackAmount(0.0), unitOutputLevel(0.0), readIndex({ 0,0 }), 
writeIndex(0), sampleRate(44100), delaySamples({0,0}), bufferSize(44100) {}

void DelayUnit::initBuffer(double f_sampleRate, float f_maxDelaySeconds) {
    //create circular buffers for every channel
    sampleRate = f_sampleRate;

    bufferSize = static_cast<std::size_t>((f_maxDelaySeconds * sampleRate) + std::numeric_limits<float>::epsilon());

    circularBuffer.setSize(2, bufferSize, false);

    clearBuffer(true);
}

void DelayUnit::clearBuffer(bool resetIndices) {
    //clear circular buffers
    circularBuffer.clear(0, 0, bufferSize);
    circularBuffer.clear(1, 0, bufferSize);

    if (resetIndices) {
        readIndex[0] = 0; readIndex[1] = 0; writeIndex = 0;
    }
}

void DelayUnit::setFeedbackAmount(float f_feedbackAmount) {
    feedbackAmount = f_feedbackAmount;
}

void DelayUnit::setUnitOutputLevel(float f_unitOutputLevel) {
    unitOutputLevel = f_unitOutputLevel;
}

void DelayUnit::setDelayTime(int f_channel, float f_delaySeconds) {
    //set delay time for one channel
    delaySamples[f_channel] = static_cast<std::size_t>((f_delaySeconds * sampleRate) + std::numeric_limits<float>::epsilon());
    

    if (writeIndex >= delaySamples[f_channel]) {
        readIndex[f_channel] = writeIndex - delaySamples[f_channel];
    }
    else {
        readIndex[f_channel] = bufferSize + writeIndex - delaySamples[f_channel];
    }
    
}

std::array<float, 2> DelayUnit::getNextSample(
    std::array<float, 2> f_originalSample, std::array<float, 2> f_feedbackSample) {
    
    std::array<float*, 2> buffer = { circularBuffer.getWritePointer(0), circularBuffer.getWritePointer(1) };
    std::array<float, 2> readSample = { 0.0,0.0 };

    for (int i = 0; i < channelCount; ++i) {
        //read sample from buffer
        readSample[i] = buffer[i][readIndex[i]] * unitOutputLevel;

        //if delay is 0, output the input
        if (delaySamples[i] == 0) { readSample[i] = f_originalSample[i] * unitOutputLevel; }

        //write input and feedback to buffer
        buffer[i][writeIndex] = f_originalSample[i] + (f_feedbackSample[i] * feedbackAmount);

        ++readIndex[i];
        if (readIndex[i] >= bufferSize) { readIndex[i] = 0; }
    }
    ++writeIndex;
    if (writeIndex >= bufferSize) { writeIndex = 0; }

    return readSample;
}