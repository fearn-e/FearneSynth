/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 7.0.2

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2020 - Raw Material Software Limited.

  ==============================================================================
*/

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "PresetManager.h"
#include "EnumDefs.h"
//#include "TempFileSaving.h"
#include <cmath>
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class FearneSynthAudioProcessorEditor  : public juce::AudioProcessorEditor,
                                         public juce::Button::Listener,
                                         public juce::ComboBox::Listener,
                                         public juce::Slider::Listener
{
public:
    //==============================================================================
    FearneSynthAudioProcessorEditor (FearneSynthAudioProcessor& owner);
    ~FearneSynthAudioProcessorEditor() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void updateOscillatorValues(int f_targetOscillator);
    void updateDelayValues();
    void displayDelayUI();
    void displayOscillatorUI();
    void showPresetSaving(bool show);
    juce::String formatFloat(float f_value);
    float scaleTimeControlValue(float f_controlValue);
    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;
    void buttonClicked (juce::Button* buttonThatWasClicked) override;
    void comboBoxChanged (juce::ComboBox* comboBoxThatHasChanged) override;
    void sliderValueChanged (juce::Slider* sliderThatWasMoved) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    FearneSynthAudioProcessor& audioProcessor;
    PresetManager presetManager_;
    //TempFileSaving tempFileSaving_;
    int selectedOscillator = 0;
    std::array<float, _ROUTING_ARRAY_END> activeInterfaceValues;
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<juce::GroupComponent> juce__groupComponent10;
    std::unique_ptr<juce::GroupComponent> juce__groupComponent8;
    std::unique_ptr<juce::GroupComponent> juce__groupComponent5;
    std::unique_ptr<juce::GroupComponent> juce__groupComponent7;
    std::unique_ptr<juce::GroupComponent> juce__groupComponent6;
    std::unique_ptr<juce::GroupComponent> juce__groupComponent;
    std::unique_ptr<juce::Label> juce__label;
    std::unique_ptr<juce::GroupComponent> juce__groupComponent2;
    std::unique_ptr<juce::GroupComponent> juce__groupComponent3;
    std::unique_ptr<juce::GroupComponent> juce__groupComponent4;
    std::unique_ptr<juce::TextButton> ui_presetSave1;
    std::unique_ptr<juce::TextButton> ui_presetSave2;
    std::unique_ptr<juce::TextButton> ui_presetSave3;
    std::unique_ptr<juce::TextButton> ui_presetSaveCancel;
    std::unique_ptr<juce::TextButton> ui_presetSaveShow;
    std::unique_ptr<juce::ComboBox> ui_oscWaveshape;
    std::unique_ptr<juce::Slider> ui_oscAttackSeconds;
    std::unique_ptr<juce::Slider> ui_oscDecaySeconds;
    std::unique_ptr<juce::Slider> ui_oscSustainLevel;
    std::unique_ptr<juce::Slider> ui_oscReleaseSeconds;
    std::unique_ptr<juce::Slider> ui_oscLevel;
    std::unique_ptr<juce::TextButton> ui_oscSelect0;
    std::unique_ptr<juce::TextButton> ui_oscSelect1;
    std::unique_ptr<juce::TextButton> ui_oscSelect2;
    std::unique_ptr<juce::TextButton> ui_oscSelect3;
    std::unique_ptr<juce::Slider> ui_globalLevel;
    std::unique_ptr<juce::ComboBox> ui_presetLoad;
    std::unique_ptr<juce::Slider> ui_pitchBendRange;
    std::unique_ptr<juce::Slider> ui_oscPan;
    std::unique_ptr<juce::Slider> ui_oscDetuneCents;
    std::unique_ptr<juce::Slider> ui_oscDetuneNotes;
    std::unique_ptr<juce::TextButton> ui_delayActiveToggle;
    std::unique_ptr<juce::Slider> ui_delayFeedbackAmount;
    std::unique_ptr<juce::Slider> ui_delayWetAmount;
    std::unique_ptr<juce::Slider> ui_delayTimeLeft0;
    std::unique_ptr<juce::Slider> ui_delayTimeLeft1;
    std::unique_ptr<juce::Slider> ui_delayTimeLeft2;
    std::unique_ptr<juce::Slider> ui_delayTimeRight0;
    std::unique_ptr<juce::Slider> ui_delayTimeRight1;
    std::unique_ptr<juce::Slider> ui_delayTimeRight2;
    std::unique_ptr<juce::Slider> ui_delayUnitOutputLevel0;
    std::unique_ptr<juce::Slider> ui_delayUnitOutputLevel2;
    std::unique_ptr<juce::Slider> ui_delayUnitOutputLevel1;
    std::unique_ptr<juce::Label> ui_oscDecayLabel;
    std::unique_ptr<juce::Label> ui_oscAttackLabel;
    std::unique_ptr<juce::Label> ui_oscReleaseLabel;
    std::unique_ptr<juce::Label> juce__label2;
    std::unique_ptr<juce::GroupComponent> juce__groupComponent9;
    std::unique_ptr<juce::Label> juce__label3;
    std::unique_ptr<juce::Label> juce__label4;
    std::unique_ptr<juce::Label> juce__label5;
    std::unique_ptr<juce::Label> juce__label6;
    std::unique_ptr<juce::Label> juce__label7;
    std::unique_ptr<juce::Label> juce__label8;
    std::unique_ptr<juce::TextButton> ui_tempSave;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FearneSynthAudioProcessorEditor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

