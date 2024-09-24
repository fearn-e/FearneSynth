/*
  ==============================================================================

    DelayUnit.h
    Created: 14 May 2023 5:49:37pm
    Author:  Ellie

  ==============================================================================
*/

#pragma once

#include <array>
#include <JuceHeader.h>

constexpr int channelCount = 2;

class DelayUnit {
public:
    DelayUnit();

    void initBuffer(double f_sampleRate, float f_maxDelaySeconds);
    void clearBuffer(bool resetIndices);

    void setDelayTime(int channel, float f_delaySeconds);
    void setFeedbackAmount(float f_feedbackAmount);
    void setUnitOutputLevel(float f_unitOutputLevel);

    std::array<float, 2> getNextSample(std::array<float, 2> f_originalSample, std::array<float, 2> f_feedbackSample);

private:
    float feedbackAmount, unitOutputLevel;
    
    double sampleRate;

    std::size_t bufferSize;
    std::array<std::size_t, 2> delaySamples;
    std::array<std::size_t, 2> readIndex;
    std::size_t writeIndex;

    juce::AudioSampleBuffer circularBuffer;
};