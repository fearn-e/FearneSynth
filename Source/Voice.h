/*
  ==============================================================================

    Voice.h
    Created: 25 Apr 2023 12:15:30am
    Author:  Ellie

  ==============================================================================
*/

#pragma once

#include <array>
#include <cmath>
#include <algorithm>
#include "Envelope.h"
#include "Oscillator.h"
#include "EnumDefs.h"
#include "ConstantPowerCurve.h"

class Voice {
public:
    Voice(double f_sampleRate = 44100);

    void interfaceControlRouting(InterfaceRoutingAddresses f_routingDestination, float f_value);

    void setSampleRate(double f_sampleRate);
    void setPitchBend(float f_pitchBendAmount);

    void noteOn(int f_currentPitch, float f_midiPitch, float f_midiVelocity, const std::size_t& f_sampleCounter);
    void noteOff(const std::size_t& f_sampleCounter);
    void stolenSwitchToBench(const std::size_t& f_sampleCounter);

    std::size_t calculateEnvelopeSampleLength(float f_lengthInSeconds);
    double calculatePhaseIncrement(std::size_t i);
    std::array<float, 2> getNextSample(const std::size_t& f_sampleCounter);

    bool isActive() const;
    int getCurrentPitch() const;

private:
    bool active;
    int currentPitch;
    double sampleRate;
    float noteValue, pitchBendAmount;

    std::array<float, synthBankSize> detuneNotesBank, detuneCentsBank;
    std::array<double, synthBankSize> phaseBank, phaseIncrementBank;
    std::array<Envelope, synthBankSize> envelopeBank_;
    std::array<Oscillator, synthBankSize> oscillatorBank_;
    std::array<ConstantPowerCurve, synthBankSize> panBank_;

    float midiToFrequency(float f_midiPitch);
};
