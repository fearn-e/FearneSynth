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

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "PluginEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
FearneSynthAudioProcessorEditor::FearneSynthAudioProcessorEditor (FearneSynthAudioProcessor& owner)
    : AudioProcessorEditor(owner), audioProcessor(owner)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    juce__groupComponent10.reset (new juce::GroupComponent ("new group",
                                                            TRANS("out")));
    addAndMakeVisible (juce__groupComponent10.get());

    juce__groupComponent10->setBounds (696, 64, 48, 136);

    juce__groupComponent8.reset (new juce::GroupComponent ("new group",
                                                           TRANS("vol")));
    addAndMakeVisible (juce__groupComponent8.get());

    juce__groupComponent8->setBounds (8, 96, 48, 104);

    juce__groupComponent5.reset (new juce::GroupComponent ("new group",
                                                           TRANS("pan")));
    addAndMakeVisible (juce__groupComponent5.get());

    juce__groupComponent5->setBounds (56, 96, 112, 48);

    juce__groupComponent7.reset (new juce::GroupComponent ("new group",
                                                           TRANS("dry/wet")));
    addAndMakeVisible (juce__groupComponent7.get());
    juce__groupComponent7->setColour (juce::GroupComponent::textColourId, juce::Colours::white);

    juce__groupComponent7->setBounds (512, 64, 168, 48);

    juce__groupComponent6.reset (new juce::GroupComponent ("new group",
                                                           TRANS("feedback")));
    addAndMakeVisible (juce__groupComponent6.get());

    juce__groupComponent6->setBounds (288, 64, 168, 48);

    juce__groupComponent.reset (new juce::GroupComponent ("new group",
                                                          TRANS("detune")));
    addAndMakeVisible (juce__groupComponent.get());

    juce__groupComponent->setBounds (56, 144, 112, 56);

    juce__label.reset (new juce::Label ("new label",
                                        TRANS("load:")));
    addAndMakeVisible (juce__label.get());
    juce__label->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label->setJustificationType (juce::Justification::centredLeft);
    juce__label->setEditable (false, false, false);
    juce__label->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label->setBounds (512, 16, 48, 24);

    juce__groupComponent2.reset (new juce::GroupComponent ("new group",
                                                           TRANS("delay 1")));
    addAndMakeVisible (juce__groupComponent2.get());

    juce__groupComponent2->setBounds (288, 112, 128, 88);

    juce__groupComponent3.reset (new juce::GroupComponent ("new group",
                                                           TRANS("delay 2")));
    addAndMakeVisible (juce__groupComponent3.get());

    juce__groupComponent3->setBounds (416, 112, 128, 88);

    juce__groupComponent4.reset (new juce::GroupComponent ("new group",
                                                           TRANS("delay 3")));
    addAndMakeVisible (juce__groupComponent4.get());

    juce__groupComponent4->setBounds (544, 112, 128, 88);

    ui_presetSave1.reset (new juce::TextButton ("Save User Preset 1"));
    addAndMakeVisible (ui_presetSave1.get());
    ui_presetSave1->setButtonText (TRANS("1"));
    ui_presetSave1->addListener (this);
    ui_presetSave1->setColour (juce::TextButton::buttonColourId, juce::Colour (0xff4b2e2e));
    ui_presetSave1->setColour (juce::TextButton::buttonOnColourId, juce::Colour (0xffd24d6c));

    ui_presetSave1->setBounds (360, 16, 24, 24);

    ui_presetSave2.reset (new juce::TextButton ("Save User Preset 2"));
    addAndMakeVisible (ui_presetSave2.get());
    ui_presetSave2->setButtonText (TRANS("2"));
    ui_presetSave2->addListener (this);
    ui_presetSave2->setColour (juce::TextButton::buttonColourId, juce::Colour (0xff4b2e2e));
    ui_presetSave2->setColour (juce::TextButton::buttonOnColourId, juce::Colour (0xffd24d6c));

    ui_presetSave2->setBounds (392, 16, 24, 24);

    ui_presetSave3.reset (new juce::TextButton ("Save User Preset 3"));
    addAndMakeVisible (ui_presetSave3.get());
    ui_presetSave3->setButtonText (TRANS("3"));
    ui_presetSave3->addListener (this);
    ui_presetSave3->setColour (juce::TextButton::buttonColourId, juce::Colour (0xff4b2e2e));
    ui_presetSave3->setColour (juce::TextButton::buttonOnColourId, juce::Colour (0xffd24d6c));

    ui_presetSave3->setBounds (424, 16, 24, 24);

    ui_presetSaveCancel.reset (new juce::TextButton ("Cancel User Preset Save"));
    addAndMakeVisible (ui_presetSaveCancel.get());
    ui_presetSaveCancel->setButtonText (TRANS("cancel"));
    ui_presetSaveCancel->addListener (this);
    ui_presetSaveCancel->setColour (juce::TextButton::buttonColourId, juce::Colour (0xff4b2e2e));
    ui_presetSaveCancel->setColour (juce::TextButton::buttonOnColourId, juce::Colour (0xffd24d6c));

    ui_presetSaveCancel->setBounds (456, 16, 48, 24);

    ui_presetSaveShow.reset (new juce::TextButton ("Show User Preset Save"));
    addAndMakeVisible (ui_presetSaveShow.get());
    ui_presetSaveShow->setButtonText (TRANS("save preset"));
    ui_presetSaveShow->addListener (this);
    ui_presetSaveShow->setColour (juce::TextButton::buttonColourId, juce::Colour (0xff4b2e2e));
    ui_presetSaveShow->setColour (juce::TextButton::buttonOnColourId, juce::Colour (0xffd24d6c));

    ui_presetSaveShow->setBounds (360, 16, 144, 24);

    ui_oscWaveshape.reset (new juce::ComboBox ("Selected Oscillator Waveshape"));
    addAndMakeVisible (ui_oscWaveshape.get());
    ui_oscWaveshape->setEditableText (false);
    ui_oscWaveshape->setJustificationType (juce::Justification::centredLeft);
    ui_oscWaveshape->setTextWhenNothingSelected (juce::String());
    ui_oscWaveshape->setTextWhenNoChoicesAvailable (TRANS("error_no_osc"));
    ui_oscWaveshape->addItem (TRANS("select waveshape"), 1);
    ui_oscWaveshape->addItem (TRANS("sine"), 2);
    ui_oscWaveshape->addItem (TRANS("square"), 3);
    ui_oscWaveshape->addItem (TRANS("saw"), 4);
    ui_oscWaveshape->addItem (TRANS("triangle"), 5);
    ui_oscWaveshape->addListener (this);

    ui_oscWaveshape->setBounds (16, 72, 152, 24);

    ui_oscAttackSeconds.reset (new juce::Slider ("Selected Oscillator Attack in Seconds"));
    addAndMakeVisible (ui_oscAttackSeconds.get());
    ui_oscAttackSeconds->setRange (0, 1, 0);
    ui_oscAttackSeconds->setSliderStyle (juce::Slider::LinearBar);
    ui_oscAttackSeconds->setTextBoxStyle (juce::Slider::NoTextBox, false, 80, 20);
    ui_oscAttackSeconds->addListener (this);

    ui_oscAttackSeconds->setBounds (176, 80, 88, 24);

    ui_oscDecaySeconds.reset (new juce::Slider ("Selected Oscillator Decay in Seconds"));
    addAndMakeVisible (ui_oscDecaySeconds.get());
    ui_oscDecaySeconds->setRange (0, 1, 0);
    ui_oscDecaySeconds->setSliderStyle (juce::Slider::LinearBar);
    ui_oscDecaySeconds->setTextBoxStyle (juce::Slider::NoTextBox, false, 80, 20);
    ui_oscDecaySeconds->addListener (this);

    ui_oscDecaySeconds->setBounds (176, 112, 88, 24);

    ui_oscSustainLevel.reset (new juce::Slider ("Selected Oscillator Sustain Level"));
    addAndMakeVisible (ui_oscSustainLevel.get());
    ui_oscSustainLevel->setRange (0, 1, 0.01);
    ui_oscSustainLevel->setSliderStyle (juce::Slider::LinearBar);
    ui_oscSustainLevel->setTextBoxStyle (juce::Slider::TextBoxLeft, false, 80, 20);
    ui_oscSustainLevel->addListener (this);

    ui_oscSustainLevel->setBounds (176, 144, 88, 16);

    ui_oscReleaseSeconds.reset (new juce::Slider ("Selected Oscillator Release in Seconds"));
    addAndMakeVisible (ui_oscReleaseSeconds.get());
    ui_oscReleaseSeconds->setRange (0, 1, 0);
    ui_oscReleaseSeconds->setSliderStyle (juce::Slider::LinearBar);
    ui_oscReleaseSeconds->setTextBoxStyle (juce::Slider::NoTextBox, false, 80, 20);
    ui_oscReleaseSeconds->addListener (this);

    ui_oscReleaseSeconds->setBounds (176, 168, 88, 24);

    ui_oscLevel.reset (new juce::Slider ("Selected Oscillator Level"));
    addAndMakeVisible (ui_oscLevel.get());
    ui_oscLevel->setTooltip (TRANS("Level"));
    ui_oscLevel->setRange (0, 1, 0.01);
    ui_oscLevel->setSliderStyle (juce::Slider::LinearBarVertical);
    ui_oscLevel->setTextBoxStyle (juce::Slider::NoTextBox, false, 80, 20);
    ui_oscLevel->addListener (this);

    ui_oscLevel->setBounds (20, 112, 24, 80);

    ui_oscSelect0.reset (new juce::TextButton ("Select Oscillator 0"));
    addAndMakeVisible (ui_oscSelect0.get());
    ui_oscSelect0->setButtonText (TRANS("osc a"));
    ui_oscSelect0->setRadioGroupId (1);
    ui_oscSelect0->addListener (this);
    ui_oscSelect0->setColour (juce::TextButton::buttonColourId, juce::Colour (0xff4b2e2e));
    ui_oscSelect0->setColour (juce::TextButton::buttonOnColourId, juce::Colour (0xffd24d6c));

    ui_oscSelect0->setBounds (16, 16, 48, 24);

    ui_oscSelect1.reset (new juce::TextButton ("Select Oscillator 1"));
    addAndMakeVisible (ui_oscSelect1.get());
    ui_oscSelect1->setButtonText (TRANS("osc b"));
    ui_oscSelect1->setRadioGroupId (1);
    ui_oscSelect1->addListener (this);
    ui_oscSelect1->setColour (juce::TextButton::buttonColourId, juce::Colour (0xff4b2e2e));
    ui_oscSelect1->setColour (juce::TextButton::buttonOnColourId, juce::Colour (0xffd24d6c));

    ui_oscSelect1->setBounds (72, 16, 48, 24);

    ui_oscSelect2.reset (new juce::TextButton ("Select Oscillator 2"));
    addAndMakeVisible (ui_oscSelect2.get());
    ui_oscSelect2->setButtonText (TRANS("osc c"));
    ui_oscSelect2->setRadioGroupId (1);
    ui_oscSelect2->addListener (this);
    ui_oscSelect2->setColour (juce::TextButton::buttonColourId, juce::Colour (0xff4b2e2e));
    ui_oscSelect2->setColour (juce::TextButton::buttonOnColourId, juce::Colour (0xffd24d6c));

    ui_oscSelect2->setBounds (128, 16, 48, 24);

    ui_oscSelect3.reset (new juce::TextButton ("Select Oscillator 3"));
    addAndMakeVisible (ui_oscSelect3.get());
    ui_oscSelect3->setButtonText (TRANS("osc d"));
    ui_oscSelect3->setRadioGroupId (1);
    ui_oscSelect3->addListener (this);
    ui_oscSelect3->setColour (juce::TextButton::buttonColourId, juce::Colour (0xff4b2e2e));
    ui_oscSelect3->setColour (juce::TextButton::buttonOnColourId, juce::Colour (0xffd24d6c));

    ui_oscSelect3->setBounds (184, 16, 48, 24);

    ui_globalLevel.reset (new juce::Slider ("Global Level"));
    addAndMakeVisible (ui_globalLevel.get());
    ui_globalLevel->setRange (0, 1, 0);
    ui_globalLevel->setSliderStyle (juce::Slider::LinearBarVertical);
    ui_globalLevel->setTextBoxStyle (juce::Slider::NoTextBox, false, 80, 20);
    ui_globalLevel->addListener (this);

    ui_globalLevel->setBounds (704, 80, 32, 112);

    ui_presetLoad.reset (new juce::ComboBox ("Load Preset"));
    addAndMakeVisible (ui_presetLoad.get());
    ui_presetLoad->setEditableText (false);
    ui_presetLoad->setJustificationType (juce::Justification::centredLeft);
    ui_presetLoad->setTextWhenNothingSelected (juce::String());
    ui_presetLoad->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    ui_presetLoad->addItem (TRANS("default"), 1);
    ui_presetLoad->addItem (TRANS("user preset 1"), 2);
    ui_presetLoad->addItem (TRANS("user preset 2"), 3);
    ui_presetLoad->addItem (TRANS("user preset 3"), 4);
    ui_presetLoad->addItem (TRANS("floaty triangles"), 5);
    ui_presetLoad->addItem (TRANS("full bodied bass"), 6);
    ui_presetLoad->addItem (TRANS("major square"), 7);
    ui_presetLoad->addItem (TRANS("soft pad"), 8);
    ui_presetLoad->addItem (TRANS("sparks"), 9);
    ui_presetLoad->addItem (TRANS("spooky echoes"), 10);
    ui_presetLoad->addItem (TRANS("sub bass"), 11);
    ui_presetLoad->addListener (this);

    ui_presetLoad->setBounds (552, 16, 184, 24);

    ui_pitchBendRange.reset (new juce::Slider ("Pitch Bend Range"));
    addAndMakeVisible (ui_pitchBendRange.get());
    ui_pitchBendRange->setRange (0, 24, 1);
    ui_pitchBendRange->setSliderStyle (juce::Slider::LinearBar);
    ui_pitchBendRange->setTextBoxStyle (juce::Slider::TextBoxAbove, false, 40, 24);
    ui_pitchBendRange->addListener (this);

    ui_pitchBendRange->setBounds (304, 16, 32, 24);

    ui_oscPan.reset (new juce::Slider ("new slider"));
    addAndMakeVisible (ui_oscPan.get());
    ui_oscPan->setRange (-50, 50, 1);
    ui_oscPan->setSliderStyle (juce::Slider::LinearBar);
    ui_oscPan->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 24);
    ui_oscPan->addListener (this);

    ui_oscPan->setBounds (64, 112, 96, 24);

    ui_oscDetuneCents.reset (new juce::Slider ("Detune Cents"));
    addAndMakeVisible (ui_oscDetuneCents.get());
    ui_oscDetuneCents->setRange (-100, 100, 1);
    ui_oscDetuneCents->setSliderStyle (juce::Slider::LinearBar);
    ui_oscDetuneCents->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 24);
    ui_oscDetuneCents->addListener (this);

    ui_oscDetuneCents->setBounds (116, 160, 44, 32);

    ui_oscDetuneNotes.reset (new juce::Slider ("Detune Notes"));
    addAndMakeVisible (ui_oscDetuneNotes.get());
    ui_oscDetuneNotes->setRange (-24, 24, 1);
    ui_oscDetuneNotes->setSliderStyle (juce::Slider::LinearBar);
    ui_oscDetuneNotes->setTextBoxStyle (juce::Slider::TextBoxBelow, false, 80, 24);
    ui_oscDetuneNotes->addListener (this);

    ui_oscDetuneNotes->setBounds (64, 160, 44, 32);

    ui_delayActiveToggle.reset (new juce::TextButton ("Delay Active Toggle"));
    addAndMakeVisible (ui_delayActiveToggle.get());
    ui_delayActiveToggle->setButtonText (TRANS("delay"));
    ui_delayActiveToggle->addListener (this);
    ui_delayActiveToggle->setColour (juce::TextButton::buttonColourId, juce::Colour (0xff4b2e2e));
    ui_delayActiveToggle->setColour (juce::TextButton::buttonOnColourId, juce::Colour (0xffd24d6c));

    ui_delayActiveToggle->setBounds (456, 80, 56, 24);

    ui_delayFeedbackAmount.reset (new juce::Slider ("Delay Feedback Amount"));
    addAndMakeVisible (ui_delayFeedbackAmount.get());
    ui_delayFeedbackAmount->setRange (0, 1.1, 0.01);
    ui_delayFeedbackAmount->setSliderStyle (juce::Slider::LinearBar);
    ui_delayFeedbackAmount->setTextBoxStyle (juce::Slider::TextBoxLeft, false, 80, 20);
    ui_delayFeedbackAmount->addListener (this);

    ui_delayFeedbackAmount->setBounds (296, 80, 152, 24);

    ui_delayWetAmount.reset (new juce::Slider ("Delay Wet Amount"));
    addAndMakeVisible (ui_delayWetAmount.get());
    ui_delayWetAmount->setRange (0, 100, 1);
    ui_delayWetAmount->setSliderStyle (juce::Slider::LinearBar);
    ui_delayWetAmount->setTextBoxStyle (juce::Slider::TextBoxLeft, false, 80, 20);
    ui_delayWetAmount->addListener (this);

    ui_delayWetAmount->setBounds (520, 80, 152, 24);

    ui_delayTimeLeft0.reset (new juce::Slider ("Delay Time Left 0"));
    addAndMakeVisible (ui_delayTimeLeft0.get());
    ui_delayTimeLeft0->setRange (0, 2500, 1);
    ui_delayTimeLeft0->setSliderStyle (juce::Slider::LinearBar);
    ui_delayTimeLeft0->setTextBoxStyle (juce::Slider::TextBoxLeft, false, 80, 20);
    ui_delayTimeLeft0->addListener (this);

    ui_delayTimeLeft0->setBounds (304, 136, 72, 24);

    ui_delayTimeLeft1.reset (new juce::Slider ("Delay Time Left 1"));
    addAndMakeVisible (ui_delayTimeLeft1.get());
    ui_delayTimeLeft1->setRange (0, 2500, 1);
    ui_delayTimeLeft1->setSliderStyle (juce::Slider::LinearBar);
    ui_delayTimeLeft1->setTextBoxStyle (juce::Slider::TextBoxLeft, false, 80, 20);
    ui_delayTimeLeft1->addListener (this);

    ui_delayTimeLeft1->setBounds (432, 136, 72, 24);

    ui_delayTimeLeft2.reset (new juce::Slider ("Delay Time Left 2"));
    addAndMakeVisible (ui_delayTimeLeft2.get());
    ui_delayTimeLeft2->setRange (0, 2500, 1);
    ui_delayTimeLeft2->setSliderStyle (juce::Slider::LinearBar);
    ui_delayTimeLeft2->setTextBoxStyle (juce::Slider::TextBoxLeft, false, 80, 20);
    ui_delayTimeLeft2->addListener (this);

    ui_delayTimeLeft2->setBounds (560, 136, 72, 24);

    ui_delayTimeRight0.reset (new juce::Slider ("Delay Time Right 0"));
    addAndMakeVisible (ui_delayTimeRight0.get());
    ui_delayTimeRight0->setRange (0, 2500, 1);
    ui_delayTimeRight0->setSliderStyle (juce::Slider::LinearBar);
    ui_delayTimeRight0->setTextBoxStyle (juce::Slider::TextBoxLeft, false, 80, 20);
    ui_delayTimeRight0->addListener (this);

    ui_delayTimeRight0->setBounds (304, 160, 72, 24);

    ui_delayTimeRight1.reset (new juce::Slider ("Delay Time Right 1"));
    addAndMakeVisible (ui_delayTimeRight1.get());
    ui_delayTimeRight1->setRange (0, 2500, 1);
    ui_delayTimeRight1->setSliderStyle (juce::Slider::LinearBar);
    ui_delayTimeRight1->setTextBoxStyle (juce::Slider::TextBoxLeft, false, 80, 20);
    ui_delayTimeRight1->addListener (this);

    ui_delayTimeRight1->setBounds (432, 160, 72, 24);

    ui_delayTimeRight2.reset (new juce::Slider ("Delay Time Right 2"));
    addAndMakeVisible (ui_delayTimeRight2.get());
    ui_delayTimeRight2->setRange (0, 2500, 1);
    ui_delayTimeRight2->setSliderStyle (juce::Slider::LinearBar);
    ui_delayTimeRight2->setTextBoxStyle (juce::Slider::TextBoxLeft, false, 80, 20);
    ui_delayTimeRight2->addListener (this);

    ui_delayTimeRight2->setBounds (560, 160, 72, 24);

    ui_delayUnitOutputLevel0.reset (new juce::Slider ("Delay Unit Output Level 0"));
    addAndMakeVisible (ui_delayUnitOutputLevel0.get());
    ui_delayUnitOutputLevel0->setRange (0, 1, 0.01);
    ui_delayUnitOutputLevel0->setSliderStyle (juce::Slider::LinearBarVertical);
    ui_delayUnitOutputLevel0->setTextBoxStyle (juce::Slider::NoTextBox, false, 80, 20);
    ui_delayUnitOutputLevel0->addListener (this);

    ui_delayUnitOutputLevel0->setBounds (384, 128, 24, 64);

    ui_delayUnitOutputLevel2.reset (new juce::Slider ("Delay Unit Output Level 2"));
    addAndMakeVisible (ui_delayUnitOutputLevel2.get());
    ui_delayUnitOutputLevel2->setRange (0, 1, 0.01);
    ui_delayUnitOutputLevel2->setSliderStyle (juce::Slider::LinearBarVertical);
    ui_delayUnitOutputLevel2->setTextBoxStyle (juce::Slider::NoTextBox, false, 80, 20);
    ui_delayUnitOutputLevel2->addListener (this);

    ui_delayUnitOutputLevel2->setBounds (640, 128, 24, 64);

    ui_delayUnitOutputLevel1.reset (new juce::Slider ("Delay Unit Output Level 1"));
    addAndMakeVisible (ui_delayUnitOutputLevel1.get());
    ui_delayUnitOutputLevel1->setRange (0, 1, 0.01);
    ui_delayUnitOutputLevel1->setSliderStyle (juce::Slider::LinearBarVertical);
    ui_delayUnitOutputLevel1->setTextBoxStyle (juce::Slider::NoTextBox, false, 80, 20);
    ui_delayUnitOutputLevel1->addListener (this);

    ui_delayUnitOutputLevel1->setBounds (512, 128, 24, 64);

    ui_oscDecayLabel.reset (new juce::Label ("Decay Label",
                                             TRANS("999ms")));
    addAndMakeVisible (ui_oscDecayLabel.get());
    ui_oscDecayLabel->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    ui_oscDecayLabel->setJustificationType (juce::Justification::centred);
    ui_oscDecayLabel->setEditable (false, false, false);
    ui_oscDecayLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    ui_oscDecayLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    ui_oscDecayLabel->setBounds (176, 112, 88, 24);

    ui_oscAttackLabel.reset (new juce::Label ("Attack Label",
                                              TRANS("20.0s\n")));
    addAndMakeVisible (ui_oscAttackLabel.get());
    ui_oscAttackLabel->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    ui_oscAttackLabel->setJustificationType (juce::Justification::centred);
    ui_oscAttackLabel->setEditable (false, false, false);
    ui_oscAttackLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    ui_oscAttackLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    ui_oscAttackLabel->setBounds (176, 80, 88, 24);

    ui_oscReleaseLabel.reset (new juce::Label ("Release Label",
                                               TRANS("7.05s")));
    addAndMakeVisible (ui_oscReleaseLabel.get());
    ui_oscReleaseLabel->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    ui_oscReleaseLabel->setJustificationType (juce::Justification::centred);
    ui_oscReleaseLabel->setEditable (false, false, false);
    ui_oscReleaseLabel->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    ui_oscReleaseLabel->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    ui_oscReleaseLabel->setBounds (176, 168, 88, 24);

    juce__label2.reset (new juce::Label ("new label",
                                         TRANS("pb range:")));
    addAndMakeVisible (juce__label2.get());
    juce__label2->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label2->setJustificationType (juce::Justification::centredLeft);
    juce__label2->setEditable (false, false, false);
    juce__label2->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label2->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label2->setBounds (232, 16, 72, 25);

    juce__groupComponent9.reset (new juce::GroupComponent ("new group",
                                                           TRANS("adsr")));
    addAndMakeVisible (juce__groupComponent9.get());

    juce__groupComponent9->setBounds (168, 64, 104, 136);

    juce__label3.reset (new juce::Label ("new label",
                                         TRANS("L")));
    addAndMakeVisible (juce__label3.get());
    juce__label3->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label3->setJustificationType (juce::Justification::centredLeft);
    juce__label3->setEditable (false, false, false);
    juce__label3->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label3->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label3->setBounds (288, 136, 24, 24);

    juce__label4.reset (new juce::Label ("new label",
                                         TRANS("R")));
    addAndMakeVisible (juce__label4.get());
    juce__label4->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label4->setJustificationType (juce::Justification::centredLeft);
    juce__label4->setEditable (false, false, false);
    juce__label4->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label4->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label4->setBounds (288, 160, 24, 24);

    juce__label5.reset (new juce::Label ("new label",
                                         TRANS("L")));
    addAndMakeVisible (juce__label5.get());
    juce__label5->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label5->setJustificationType (juce::Justification::centredLeft);
    juce__label5->setEditable (false, false, false);
    juce__label5->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label5->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label5->setBounds (416, 136, 24, 24);

    juce__label6.reset (new juce::Label ("new label",
                                         TRANS("R")));
    addAndMakeVisible (juce__label6.get());
    juce__label6->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label6->setJustificationType (juce::Justification::centredLeft);
    juce__label6->setEditable (false, false, false);
    juce__label6->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label6->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label6->setBounds (416, 160, 24, 24);

    juce__label7.reset (new juce::Label ("new label",
                                         TRANS("L")));
    addAndMakeVisible (juce__label7.get());
    juce__label7->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label7->setJustificationType (juce::Justification::centredLeft);
    juce__label7->setEditable (false, false, false);
    juce__label7->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label7->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label7->setBounds (544, 136, 24, 24);

    juce__label8.reset (new juce::Label ("new label",
                                         TRANS("R")));
    addAndMakeVisible (juce__label8.get());
    juce__label8->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    juce__label8->setJustificationType (juce::Justification::centredLeft);
    juce__label8->setEditable (false, false, false);
    juce__label8->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    juce__label8->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    juce__label8->setBounds (544, 160, 24, 24);

    ui_tempSave.reset (new juce::TextButton ("Temp Save"));
    addAndMakeVisible (ui_tempSave.get());
    ui_tempSave->addListener (this);

    ui_tempSave->setBounds (16, 304, 96, 24);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (752, 208);


    //[Constructor] You can add your own custom stuff here..

    //disable mouse clicks for labels which are over sliders
    ui_oscAttackLabel->setInterceptsMouseClicks(false, false);
    ui_oscDecayLabel->setInterceptsMouseClicks(false, false);
    ui_oscReleaseLabel->setInterceptsMouseClicks(false, false);

    //turn on toggle states for relevant ui elements
    ui_oscSelect0->setClickingTogglesState(true);
    ui_oscSelect0->setToggleState(true, juce::dontSendNotification);
    ui_oscSelect1->setClickingTogglesState(true);
    ui_oscSelect2->setClickingTogglesState(true);
    ui_oscSelect3->setClickingTogglesState(true);
    ui_delayActiveToggle->setClickingTogglesState(true);
    //hide preset saving menu
    showPresetSaving(0);

    //load default preset
    ui_presetLoad->setSelectedItemIndex(0, juce::dontSendNotification);
    presetManager_.interactPreset(PRESET_LOAD, PRESET_DEFAULT, activeInterfaceValues);

    //send default preset values through to processing engine
    audioProcessor.propogatePresetValues(activeInterfaceValues);

    audioProcessor.killDelay();

    //update UI elements with default preset values
    updateOscillatorValues(0);
    updateDelayValues();
    ui_globalLevel->setValue(activeInterfaceValues[SYNTH_GLOBAL_LEVEL]);
    ui_pitchBendRange->setValue(activeInterfaceValues[SYNTH_GLOBAL_MIDI_PB_RANGE]);

    //[/Constructor]
}

FearneSynthAudioProcessorEditor::~FearneSynthAudioProcessorEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    juce__groupComponent10 = nullptr;
    juce__groupComponent8 = nullptr;
    juce__groupComponent5 = nullptr;
    juce__groupComponent7 = nullptr;
    juce__groupComponent6 = nullptr;
    juce__groupComponent = nullptr;
    juce__label = nullptr;
    juce__groupComponent2 = nullptr;
    juce__groupComponent3 = nullptr;
    juce__groupComponent4 = nullptr;
    ui_presetSave1 = nullptr;
    ui_presetSave2 = nullptr;
    ui_presetSave3 = nullptr;
    ui_presetSaveCancel = nullptr;
    ui_presetSaveShow = nullptr;
    ui_oscWaveshape = nullptr;
    ui_oscAttackSeconds = nullptr;
    ui_oscDecaySeconds = nullptr;
    ui_oscSustainLevel = nullptr;
    ui_oscReleaseSeconds = nullptr;
    ui_oscLevel = nullptr;
    ui_oscSelect0 = nullptr;
    ui_oscSelect1 = nullptr;
    ui_oscSelect2 = nullptr;
    ui_oscSelect3 = nullptr;
    ui_globalLevel = nullptr;
    ui_presetLoad = nullptr;
    ui_pitchBendRange = nullptr;
    ui_oscPan = nullptr;
    ui_oscDetuneCents = nullptr;
    ui_oscDetuneNotes = nullptr;
    ui_delayActiveToggle = nullptr;
    ui_delayFeedbackAmount = nullptr;
    ui_delayWetAmount = nullptr;
    ui_delayTimeLeft0 = nullptr;
    ui_delayTimeLeft1 = nullptr;
    ui_delayTimeLeft2 = nullptr;
    ui_delayTimeRight0 = nullptr;
    ui_delayTimeRight1 = nullptr;
    ui_delayTimeRight2 = nullptr;
    ui_delayUnitOutputLevel0 = nullptr;
    ui_delayUnitOutputLevel2 = nullptr;
    ui_delayUnitOutputLevel1 = nullptr;
    ui_oscDecayLabel = nullptr;
    ui_oscAttackLabel = nullptr;
    ui_oscReleaseLabel = nullptr;
    juce__label2 = nullptr;
    juce__groupComponent9 = nullptr;
    juce__label3 = nullptr;
    juce__label4 = nullptr;
    juce__label5 = nullptr;
    juce__label6 = nullptr;
    juce__label7 = nullptr;
    juce__label8 = nullptr;
    ui_tempSave = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void FearneSynthAudioProcessorEditor::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (juce::Colour (0xff0c160b));

    {
        int x = 0, y = 0, width = 752, height = 208;
        juce::Colour fillColour = juce::Colour (0xff230e14);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
    }

    {
        float x = 8.0f, y = 8.0f, width = 320.0f, height = 40.0f;
        juce::Colour fillColour = juce::Colours::crimson;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRoundedRectangle (x, y, width, height, 5.000f);
    }

    {
        float x = 260.0f, y = 164.0f, width = 44.0f, height = 8.0f;
        juce::Colour fillColour1 = juce::Colour (0xff665858), fillColour2 = juce::Colour (0xff623737);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setGradientFill (juce::ColourGradient (fillColour1,
                                             0.0f - 260.0f + x,
                                             0.0f - 164.0f + y,
                                             fillColour2,
                                             752.0f - 260.0f + x,
                                             208.0f - 164.0f + y,
                                             false));
        g.fillRoundedRectangle (x, y, width, height, 10.000f);
    }

    {
        float x = 696.0f, y = 64.0f, width = 40.0f, height = 136.0f;
        juce::Colour fillColour = juce::Colours::crimson;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRoundedRectangle (x, y, width, height, 5.000f);
    }

    {
        float x = 288.0f, y = 64.0f, width = 392.0f, height = 137.0f;
        juce::Colour fillColour = juce::Colours::crimson;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRoundedRectangle (x, y, width, height, 5.000f);
    }

    {
        float x = 8.0f, y = 63.0f, width = 264.0f, height = 137.0f;
        juce::Colour fillColour = juce::Colours::crimson;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRoundedRectangle (x, y, width, height, 5.000f);
    }

    {
        float x = 260.0f, y = 92.0f, width = 44.0f, height = 8.0f;
        juce::Colour fillColour1 = juce::Colour (0xff665858), fillColour2 = juce::Colour (0xff623737);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setGradientFill (juce::ColourGradient (fillColour1,
                                             0.0f - 260.0f + x,
                                             0.0f - 92.0f + y,
                                             fillColour2,
                                             752.0f - 260.0f + x,
                                             208.0f - 92.0f + y,
                                             false));
        g.fillRoundedRectangle (x, y, width, height, 10.000f);
    }

    {
        float x = 668.0f, y = 92.0f, width = 44.0f, height = 8.0f;
        juce::Colour fillColour1 = juce::Colour (0xff665858), fillColour2 = juce::Colour (0xff623737);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setGradientFill (juce::ColourGradient (fillColour1,
                                             0.0f - 668.0f + x,
                                             0.0f - 92.0f + y,
                                             fillColour2,
                                             752.0f - 668.0f + x,
                                             208.0f - 92.0f + y,
                                             false));
        g.fillRoundedRectangle (x, y, width, height, 10.000f);
    }

    {
        float x = 668.0f, y = 164.0f, width = 44.0f, height = 8.0f;
        juce::Colour fillColour1 = juce::Colour (0xff665858), fillColour2 = juce::Colour (0xff623737);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setGradientFill (juce::ColourGradient (fillColour1,
                                             0.0f - 668.0f + x,
                                             0.0f - 164.0f + y,
                                             fillColour2,
                                             752.0f - 668.0f + x,
                                             208.0f - 164.0f + y,
                                             false));
        g.fillRoundedRectangle (x, y, width, height, 10.000f);
    }

    {
        float x = 220.0f, y = 36.0f, width = 8.0f, height = 48.0f;
        juce::Colour fillColour1 = juce::Colour (0xff665858), fillColour2 = juce::Colour (0xff623737);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setGradientFill (juce::ColourGradient (fillColour1,
                                             0.0f - 220.0f + x,
                                             0.0f - 36.0f + y,
                                             fillColour2,
                                             752.0f - 220.0f + x,
                                             208.0f - 36.0f + y,
                                             false));
        g.fillRoundedRectangle (x, y, width, height, 10.000f);
    }

    {
        float x = 52.0f, y = 36.0f, width = 8.0f, height = 48.0f;
        juce::Colour fillColour1 = juce::Colour (0xff665858), fillColour2 = juce::Colour (0xff623737);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setGradientFill (juce::ColourGradient (fillColour1,
                                             0.0f - 52.0f + x,
                                             0.0f - 36.0f + y,
                                             fillColour2,
                                             752.0f - 52.0f + x,
                                             208.0f - 36.0f + y,
                                             false));
        g.fillRoundedRectangle (x, y, width, height, 10.000f);
    }

    {
        float x = 696.0f, y = 64.0f, width = 48.0f, height = 136.0f;
        juce::Colour fillColour1 = juce::Colour (0xff665858), fillColour2 = juce::Colour (0xff623737);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setGradientFill (juce::ColourGradient (fillColour1,
                                             0.0f - 696.0f + x,
                                             0.0f - 64.0f + y,
                                             fillColour2,
                                             752.0f - 696.0f + x,
                                             208.0f - 64.0f + y,
                                             false));
        g.fillRoundedRectangle (x, y, width, height, 5.000f);
    }

    {
        float x = 352.0f, y = 8.0f, width = 392.0f, height = 40.0f;
        juce::Colour fillColour1 = juce::Colour (0xff665858), fillColour2 = juce::Colour (0xff623737);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setGradientFill (juce::ColourGradient (fillColour1,
                                             0.0f - 352.0f + x,
                                             0.0f - 8.0f + y,
                                             fillColour2,
                                             752.0f - 352.0f + x,
                                             208.0f - 8.0f + y,
                                             false));
        g.fillRoundedRectangle (x, y, width, height, 5.000f);
    }

    {
        float x = 288.0f, y = 64.0f, width = 392.0f, height = 137.0f;
        juce::Colour fillColour1 = juce::Colour (0xff665858), fillColour2 = juce::Colour (0xff623737);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setGradientFill (juce::ColourGradient (fillColour1,
                                             0.0f - 288.0f + x,
                                             0.0f - 64.0f + y,
                                             fillColour2,
                                             752.0f - 288.0f + x,
                                             208.0f - 64.0f + y,
                                             false));
        g.fillRoundedRectangle (x, y, width, height, 5.000f);
    }

    {
        float x = 8.0f, y = 8.0f, width = 336.0f, height = 40.0f;
        juce::Colour fillColour1 = juce::Colour (0xff665858), fillColour2 = juce::Colour (0xff623737);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setGradientFill (juce::ColourGradient (fillColour1,
                                             0.0f - 8.0f + x,
                                             0.0f - 8.0f + y,
                                             fillColour2,
                                             752.0f - 8.0f + x,
                                             208.0f - 8.0f + y,
                                             false));
        g.fillRoundedRectangle (x, y, width, height, 5.000f);
    }

    {
        float x = 8.0f, y = 63.0f, width = 264.0f, height = 137.0f;
        juce::Colour fillColour1 = juce::Colour (0xff665858), fillColour2 = juce::Colour (0xff623737);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setGradientFill (juce::ColourGradient (fillColour1,
                                             0.0f - 8.0f + x,
                                             0.0f - 63.0f + y,
                                             fillColour2,
                                             752.0f - 8.0f + x,
                                             208.0f - 63.0f + y,
                                             false));
        g.fillRoundedRectangle (x, y, width, height, 5.000f);
    }

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void FearneSynthAudioProcessorEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void FearneSynthAudioProcessorEditor::buttonClicked (juce::Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == ui_presetSave1.get())
    {
        //[UserButtonCode_ui_presetSave1] -- add your button handler code here..
        showPresetSaving(0);

        presetManager_.interactPreset(PRESET_SAVE, PRESET_USER_1, activeInterfaceValues);
        ui_presetLoad->setSelectedItemIndex((PRESET_USER_1 - PRESET_DEFAULT), juce::dontSendNotification);
        //[/UserButtonCode_ui_presetSave1]
    }
    else if (buttonThatWasClicked == ui_presetSave2.get())
    {
        //[UserButtonCode_ui_presetSave2] -- add your button handler code here..
        showPresetSaving(0);

        presetManager_.interactPreset(PRESET_SAVE, PRESET_USER_2, activeInterfaceValues);
        ui_presetLoad->setSelectedItemIndex((PRESET_USER_2 - PRESET_DEFAULT), juce::dontSendNotification);
        //[/UserButtonCode_ui_presetSave2]
    }
    else if (buttonThatWasClicked == ui_presetSave3.get())
    {
        //[UserButtonCode_ui_presetSave3] -- add your button handler code here..
        showPresetSaving(0);

        presetManager_.interactPreset(PRESET_SAVE, PRESET_USER_3, activeInterfaceValues);
        ui_presetLoad->setSelectedItemIndex((PRESET_USER_3 - PRESET_DEFAULT), juce::dontSendNotification);
        //[/UserButtonCode_ui_presetSave3]
    }
    else if (buttonThatWasClicked == ui_presetSaveCancel.get())
    {
        //[UserButtonCode_ui_presetSaveCancel] -- add your button handler code here..
        showPresetSaving(0);
        //[/UserButtonCode_ui_presetSaveCancel]
    }
    else if (buttonThatWasClicked == ui_presetSaveShow.get())
    {
        //[UserButtonCode_ui_presetSaveShow] -- add your button handler code here..
        showPresetSaving(1);
        //[/UserButtonCode_ui_presetSaveShow]
    }
    else if (buttonThatWasClicked == ui_oscSelect0.get())
    {
        //[UserButtonCode_ui_oscSelect0] -- add your button handler code here..
        updateOscillatorValues(0);
        //[/UserButtonCode_ui_oscSelect0]
    }
    else if (buttonThatWasClicked == ui_oscSelect1.get())
    {
        //[UserButtonCode_ui_oscSelect1] -- add your button handler code here..
        updateOscillatorValues(1);
        //[/UserButtonCode_ui_oscSelect1]
    }
    else if (buttonThatWasClicked == ui_oscSelect2.get())
    {
        //[UserButtonCode_ui_oscSelect2] -- add your button handler code here..
        updateOscillatorValues(2);
        //[/UserButtonCode_ui_oscSelect2]
    }
    else if (buttonThatWasClicked == ui_oscSelect3.get())
    {
        //[UserButtonCode_ui_oscSelect3] -- add your button handler code here..
        updateOscillatorValues(3);
        //[/UserButtonCode_ui_oscSelect3]
    }
    else if (buttonThatWasClicked == ui_delayActiveToggle.get())
    {
        //[UserButtonCode_ui_delayActiveToggle] -- add your button handler code here..
        displayDelayUI();
        //[/UserButtonCode_ui_delayActiveToggle]
    }
    else if (buttonThatWasClicked == ui_tempSave.get())
    {
        //[UserButtonCode_ui_tempSave] -- add your button handler code here..
        //tempFileSaving_.writePresetToFile(activeInterfaceValues, 99);
        //[/UserButtonCode_ui_tempSave]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}

void FearneSynthAudioProcessorEditor::comboBoxChanged (juce::ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == ui_oscWaveshape.get())
    {
        //[UserComboBoxCode_ui_oscWaveshape] -- add your combo box handling code here..

        //change which oscillator values are displayed

        activeInterfaceValues[OSC_WAVESHAPE_0 + selectedOscillator] = static_cast<float>(ui_oscWaveshape->getSelectedItemIndex());

        audioProcessor.interfaceControlRouting(static_cast<InterfaceRoutingAddresses>(
            OSC_WAVESHAPE_0 + selectedOscillator), static_cast<float>(ui_oscWaveshape->getSelectedItemIndex()));

        displayOscillatorUI();

        //[/UserComboBoxCode_ui_oscWaveshape]
    }
    else if (comboBoxThatHasChanged == ui_presetLoad.get())
    {
        //[UserComboBoxCode_ui_presetLoad] -- add your combo box handling code here..

        //loads the selected preset values into activeInterfaceValues
        presetManager_.interactPreset(PRESET_LOAD, static_cast<PresetManagerInstructions>(
            PRESET_DEFAULT + ui_presetLoad->getSelectedItemIndex()), activeInterfaceValues);

        //update UI displays
        updateOscillatorValues(selectedOscillator);
        updateDelayValues();
        ui_globalLevel->setValue(activeInterfaceValues[SYNTH_GLOBAL_LEVEL]);
        ui_pitchBendRange->setValue(activeInterfaceValues[SYNTH_GLOBAL_MIDI_PB_RANGE]);

        //send new values to processing engine
        audioProcessor.propogatePresetValues(activeInterfaceValues);

        audioProcessor.killDelay();
        //[/UserComboBoxCode_ui_presetLoad]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}

void FearneSynthAudioProcessorEditor::sliderValueChanged (juce::Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == ui_oscAttackSeconds.get())
    {
        //[UserSliderCode_ui_oscAttackSeconds] -- add your slider handling code here..

        //since we're using log scaling for the ADSR time values, saves both the UI value and the scaled value
        float uiVal = static_cast<float>(ui_oscAttackSeconds->getValue());
        float scaleduiVal = scaleTimeControlValue(uiVal);
        activeInterfaceValues[ENV_ATTACK_UI_0 + selectedOscillator] = uiVal;
        activeInterfaceValues[ENV_ATTACK_REAL_0 + selectedOscillator] = scaleduiVal;
        audioProcessor.interfaceControlRouting(static_cast<InterfaceRoutingAddresses>(ENV_ATTACK_REAL_0 + selectedOscillator), scaleduiVal);

        ui_oscAttackLabel->setText(formatFloat(activeInterfaceValues[ENV_ATTACK_REAL_0 + selectedOscillator]), juce::dontSendNotification);

        //[/UserSliderCode_ui_oscAttackSeconds]
    }
    else if (sliderThatWasMoved == ui_oscDecaySeconds.get())
    {
        //[UserSliderCode_ui_oscDecaySeconds] -- add your slider handling code here..

        //since we're using log scaling for the ADSR time values, saves both the UI value and the scaled value
        float uiVal = static_cast<float>(ui_oscDecaySeconds->getValue());
        float scaleduiVal = scaleTimeControlValue(uiVal);
        activeInterfaceValues[ENV_DECAY_UI_0 + selectedOscillator] = uiVal;
        activeInterfaceValues[ENV_DECAY_REAL_0 + selectedOscillator] = scaleduiVal;
        audioProcessor.interfaceControlRouting(static_cast<InterfaceRoutingAddresses>(ENV_DECAY_REAL_0 + selectedOscillator), scaleduiVal);

        ui_oscDecayLabel->setText(formatFloat(activeInterfaceValues[ENV_DECAY_REAL_0 + selectedOscillator]), juce::dontSendNotification);

        //[/UserSliderCode_ui_oscDecaySeconds]
    }
    else if (sliderThatWasMoved == ui_oscSustainLevel.get())
    {
        //[UserSliderCode_ui_oscSustainLevel] -- add your slider handling code here..

        activeInterfaceValues[ENV_SUSTAIN_0 + selectedOscillator] = static_cast<float>(ui_oscSustainLevel->getValue());
        audioProcessor.interfaceControlRouting(static_cast<InterfaceRoutingAddresses>(ENV_SUSTAIN_0 + selectedOscillator), static_cast<float>(ui_oscSustainLevel->getValue()));

        //[/UserSliderCode_ui_oscSustainLevel]
    }
    else if (sliderThatWasMoved == ui_oscReleaseSeconds.get())
    {
        //[UserSliderCode_ui_oscReleaseSeconds] -- add your slider handling code here..

        //since we're using log scaling for the ADSR time values, saves both the UI value and the scaled value
        float uiVal = static_cast<float>(ui_oscReleaseSeconds->getValue());
        float scaleduiVal = scaleTimeControlValue(uiVal);
        activeInterfaceValues[ENV_RELEASE_UI_0 + selectedOscillator] = uiVal;
        activeInterfaceValues[ENV_RELEASE_REAL_0 + selectedOscillator] = scaleduiVal;
        audioProcessor.interfaceControlRouting(static_cast<InterfaceRoutingAddresses>(ENV_RELEASE_REAL_0 + selectedOscillator), scaleduiVal);

        ui_oscReleaseLabel->setText(formatFloat(activeInterfaceValues[ENV_RELEASE_REAL_0 + selectedOscillator]), juce::dontSendNotification);

        //[/UserSliderCode_ui_oscReleaseSeconds]
    }
    else if (sliderThatWasMoved == ui_oscLevel.get())
    {
        //[UserSliderCode_ui_oscLevel] -- add your slider handling code here..
        activeInterfaceValues[OSC_LEVEL_0 + selectedOscillator] = static_cast<float>(ui_oscLevel->getValue());
        audioProcessor.interfaceControlRouting(static_cast<InterfaceRoutingAddresses>(OSC_LEVEL_0 + selectedOscillator), static_cast<float>(ui_oscLevel->getValue()));
        //[/UserSliderCode_ui_oscLevel]
    }
    else if (sliderThatWasMoved == ui_globalLevel.get())
    {
        //[UserSliderCode_ui_globalLevel] -- add your slider handling code here..
        activeInterfaceValues[SYNTH_GLOBAL_LEVEL] = static_cast<float>(ui_globalLevel->getValue());
        audioProcessor.interfaceControlRouting(SYNTH_GLOBAL_LEVEL, activeInterfaceValues[SYNTH_GLOBAL_LEVEL]);
        //[/UserSliderCode_ui_globalLevel]
    }
    else if (sliderThatWasMoved == ui_pitchBendRange.get())
    {
        //[UserSliderCode_ui_pitchBendRange] -- add your slider handling code here..
        activeInterfaceValues[SYNTH_GLOBAL_MIDI_PB_RANGE] = static_cast<float>(ui_pitchBendRange->getValue());
        audioProcessor.interfaceControlRouting(SYNTH_GLOBAL_MIDI_PB_RANGE, activeInterfaceValues[SYNTH_GLOBAL_MIDI_PB_RANGE]);
        //[/UserSliderCode_ui_pitchBendRange]
    }
    else if (sliderThatWasMoved == ui_oscPan.get())
    {
        //[UserSliderCode_ui_oscPan] -- add your slider handling code here..
        activeInterfaceValues[OSC_PAN_0 + selectedOscillator] = static_cast<float>(ui_oscPan->getValue());
        audioProcessor.interfaceControlRouting(static_cast<InterfaceRoutingAddresses>(OSC_PAN_0 + selectedOscillator), static_cast<float>(ui_oscPan->getValue()));
        //[/UserSliderCode_ui_oscPan]
    }
    else if (sliderThatWasMoved == ui_oscDetuneCents.get())
    {
        //[UserSliderCode_ui_oscDetuneCents] -- add your slider handling code here..
        activeInterfaceValues[OSC_DETUNE_CENTS_0 + selectedOscillator] = static_cast<float>(ui_oscDetuneCents->getValue() / 100.0);
        audioProcessor.interfaceControlRouting(static_cast<InterfaceRoutingAddresses>(OSC_DETUNE_CENTS_0 + selectedOscillator), static_cast<float>((ui_oscDetuneCents->getValue() / 100.0)));
        //[/UserSliderCode_ui_oscDetuneCents]
    }
    else if (sliderThatWasMoved == ui_oscDetuneNotes.get())
    {
        //[UserSliderCode_ui_oscDetuneNotes] -- add your slider handling code here..
        activeInterfaceValues[OSC_DETUNE_NOTES_0 + selectedOscillator] = static_cast<float>(ui_oscDetuneNotes->getValue());
        audioProcessor.interfaceControlRouting(static_cast<InterfaceRoutingAddresses>(OSC_DETUNE_NOTES_0 + selectedOscillator), static_cast<float>(ui_oscDetuneNotes->getValue()));
        //[/UserSliderCode_ui_oscDetuneNotes]
    }
    else if (sliderThatWasMoved == ui_delayFeedbackAmount.get())
    {
        //[UserSliderCode_ui_delayFeedbackAmount] -- add your slider handling code here..
        float uiVal = static_cast<float>(ui_delayFeedbackAmount->getValue());
        activeInterfaceValues[DELAY_FEEDBACK_AMOUNT] = uiVal;
        audioProcessor.interfaceControlRouting(DELAY_FEEDBACK_AMOUNT, uiVal);
        //[/UserSliderCode_ui_delayFeedbackAmount]
    }
    else if (sliderThatWasMoved == ui_delayWetAmount.get())
    {
        //[UserSliderCode_ui_delayWetAmount] -- add your slider handling code here..
        float uiVal = static_cast<float>(ui_delayWetAmount->getValue());
        activeInterfaceValues[DELAY_WET_SIGNAL_PERCENTAGE] = uiVal;
        audioProcessor.interfaceControlRouting(DELAY_WET_SIGNAL_PERCENTAGE, uiVal);
        //[/UserSliderCode_ui_delayWetAmount]
    }
    else if (sliderThatWasMoved == ui_delayTimeLeft0.get())
    {
        //[UserSliderCode_ui_delayTimeLeft0] -- add your slider handling code here..
        float uiVal = static_cast<float>(ui_delayTimeLeft0->getValue() / 1000.0);
        activeInterfaceValues[DELAY_UNIT_TIME_LEFT_0] = uiVal;
        audioProcessor.interfaceControlRouting(DELAY_UNIT_TIME_LEFT_0, uiVal);
        //[/UserSliderCode_ui_delayTimeLeft0]
    }
    else if (sliderThatWasMoved == ui_delayTimeLeft1.get())
    {
        //[UserSliderCode_ui_delayTimeLeft1] -- add your slider handling code here..
        float uiVal = static_cast<float>(ui_delayTimeLeft1->getValue() / 1000.0);
        activeInterfaceValues[DELAY_UNIT_TIME_LEFT_1] = uiVal;
        audioProcessor.interfaceControlRouting(DELAY_UNIT_TIME_LEFT_1, uiVal);
        //[/UserSliderCode_ui_delayTimeLeft1]
    }
    else if (sliderThatWasMoved == ui_delayTimeLeft2.get())
    {
        //[UserSliderCode_ui_delayTimeLeft2] -- add your slider handling code here..
        float uiVal = static_cast<float>(ui_delayTimeLeft2->getValue() / 1000.0);
        activeInterfaceValues[DELAY_UNIT_TIME_LEFT_LAST] = uiVal;
        audioProcessor.interfaceControlRouting(DELAY_UNIT_TIME_LEFT_LAST, uiVal);
        //[/UserSliderCode_ui_delayTimeLeft2]
    }
    else if (sliderThatWasMoved == ui_delayTimeRight0.get())
    {
        //[UserSliderCode_ui_delayTimeRight0] -- add your slider handling code here..
        float uiVal = static_cast<float>(ui_delayTimeRight0->getValue() / 1000.0);
        activeInterfaceValues[DELAY_UNIT_TIME_RIGHT_0] = uiVal;
        audioProcessor.interfaceControlRouting(DELAY_UNIT_TIME_RIGHT_0, uiVal);
        //[/UserSliderCode_ui_delayTimeRight0]
    }
    else if (sliderThatWasMoved == ui_delayTimeRight1.get())
    {
        //[UserSliderCode_ui_delayTimeRight1] -- add your slider handling code here..
        float uiVal = static_cast<float>(ui_delayTimeRight1->getValue() / 1000.0);
        activeInterfaceValues[DELAY_UNIT_TIME_RIGHT_1] = uiVal;
        audioProcessor.interfaceControlRouting(DELAY_UNIT_TIME_RIGHT_1, uiVal);
        //[/UserSliderCode_ui_delayTimeRight1]
    }
    else if (sliderThatWasMoved == ui_delayTimeRight2.get())
    {
        //[UserSliderCode_ui_delayTimeRight2] -- add your slider handling code here..
        float uiVal = static_cast<float>(ui_delayTimeRight2->getValue() / 1000.0);
        activeInterfaceValues[DELAY_UNIT_TIME_RIGHT_LAST] = uiVal;
        audioProcessor.interfaceControlRouting(DELAY_UNIT_TIME_RIGHT_LAST, uiVal);
        //[/UserSliderCode_ui_delayTimeRight2]
    }
    else if (sliderThatWasMoved == ui_delayUnitOutputLevel0.get())
    {
        //[UserSliderCode_ui_delayUnitOutputLevel0] -- add your slider handling code here..
        float uiVal = static_cast<float>(ui_delayUnitOutputLevel0->getValue());
        activeInterfaceValues[DELAY_UNIT_OUTPUT_LEVEL_0] = uiVal;
        audioProcessor.interfaceControlRouting(DELAY_UNIT_OUTPUT_LEVEL_0, uiVal);
        //[/UserSliderCode_ui_delayUnitOutputLevel0]
    }
    else if (sliderThatWasMoved == ui_delayUnitOutputLevel2.get())
    {
        //[UserSliderCode_ui_delayUnitOutputLevel2] -- add your slider handling code here..
        float uiVal = static_cast<float>(ui_delayUnitOutputLevel2->getValue());
        activeInterfaceValues[DELAY_UNIT_OUTPUT_LEVEL_LAST] = uiVal;
        audioProcessor.interfaceControlRouting(DELAY_UNIT_OUTPUT_LEVEL_LAST, uiVal);
        //[/UserSliderCode_ui_delayUnitOutputLevel2]
    }
    else if (sliderThatWasMoved == ui_delayUnitOutputLevel1.get())
    {
        //[UserSliderCode_ui_delayUnitOutputLevel1] -- add your slider handling code here..
        float uiVal = static_cast<float>(ui_delayUnitOutputLevel1->getValue());
        activeInterfaceValues[DELAY_UNIT_OUTPUT_LEVEL_1] = uiVal;
        audioProcessor.interfaceControlRouting(DELAY_UNIT_OUTPUT_LEVEL_1, uiVal);
        //[/UserSliderCode_ui_delayUnitOutputLevel1]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...

void FearneSynthAudioProcessorEditor::updateOscillatorValues(int f_targetOscillator) {
    //update all synth UI elements with new values from selected oscillator
    selectedOscillator = f_targetOscillator;
    ui_oscWaveshape->setSelectedItemIndex(static_cast<int>(activeInterfaceValues[OSC_WAVESHAPE_0 + selectedOscillator] + std::numeric_limits<float>::epsilon()), juce::dontSendNotification);
    ui_oscAttackSeconds->setValue(activeInterfaceValues[ENV_ATTACK_UI_0 + selectedOscillator], juce::dontSendNotification);
    ui_oscDecaySeconds->setValue(activeInterfaceValues[ENV_DECAY_UI_0 + selectedOscillator], juce::dontSendNotification);
    ui_oscSustainLevel->setValue(activeInterfaceValues[ENV_SUSTAIN_0 + selectedOscillator], juce::dontSendNotification);
    ui_oscReleaseSeconds->setValue(activeInterfaceValues[ENV_RELEASE_UI_0 + selectedOscillator], juce::dontSendNotification);
    ui_oscLevel->setValue(activeInterfaceValues[OSC_LEVEL_0 + selectedOscillator], juce::dontSendNotification);
    ui_oscPan->setValue(activeInterfaceValues[OSC_PAN_0 + selectedOscillator], juce::dontSendNotification);
    ui_oscDetuneCents->setValue(activeInterfaceValues[OSC_DETUNE_CENTS_0 + selectedOscillator] * 100.0, juce::dontSendNotification);
    ui_oscDetuneNotes->setValue(activeInterfaceValues[OSC_DETUNE_NOTES_0 + selectedOscillator], juce::dontSendNotification);

    ui_oscAttackLabel->setText(formatFloat(activeInterfaceValues[ENV_ATTACK_REAL_0 + selectedOscillator]), juce::dontSendNotification);
    ui_oscDecayLabel->setText(formatFloat(activeInterfaceValues[ENV_DECAY_REAL_0 + selectedOscillator]), juce::dontSendNotification);
    ui_oscReleaseLabel->setText(formatFloat(activeInterfaceValues[ENV_RELEASE_REAL_0 + selectedOscillator]), juce::dontSendNotification);

    //call check if current oscillator is active, update UI colours accordingly
    displayOscillatorUI();
}

void FearneSynthAudioProcessorEditor::updateDelayValues() {
    //update all delay UI elements with new values
    ui_delayActiveToggle->setToggleState(static_cast<int>(activeInterfaceValues[SYNTH_GLOBAL_DELAY_ACTIVE]), juce::dontSendNotification);
    ui_delayFeedbackAmount->setValue(activeInterfaceValues[DELAY_FEEDBACK_AMOUNT], juce::dontSendNotification);
    ui_delayWetAmount->setValue(activeInterfaceValues[DELAY_WET_SIGNAL_PERCENTAGE], juce::dontSendNotification);
    ui_delayUnitOutputLevel0->setValue(activeInterfaceValues[DELAY_UNIT_OUTPUT_LEVEL_0], juce::dontSendNotification);
    ui_delayUnitOutputLevel1->setValue(activeInterfaceValues[DELAY_UNIT_OUTPUT_LEVEL_1], juce::dontSendNotification);
    ui_delayUnitOutputLevel2->setValue(activeInterfaceValues[DELAY_UNIT_OUTPUT_LEVEL_LAST], juce::dontSendNotification);
    ui_delayTimeLeft0->setValue((activeInterfaceValues[DELAY_UNIT_TIME_LEFT_0] * 1000), juce::dontSendNotification);
    ui_delayTimeLeft1->setValue((activeInterfaceValues[DELAY_UNIT_TIME_LEFT_1] * 1000), juce::dontSendNotification);
    ui_delayTimeLeft2->setValue((activeInterfaceValues[DELAY_UNIT_TIME_LEFT_LAST] * 1000), juce::dontSendNotification);
    ui_delayTimeRight0->setValue((activeInterfaceValues[DELAY_UNIT_TIME_RIGHT_0] * 1000), juce::dontSendNotification);
    ui_delayTimeRight1->setValue((activeInterfaceValues[DELAY_UNIT_TIME_RIGHT_1] * 1000), juce::dontSendNotification);
    ui_delayTimeRight2->setValue((activeInterfaceValues[DELAY_UNIT_TIME_RIGHT_LAST] * 1000), juce::dontSendNotification);

    //call check if delay is active, updates UI colours accordingly
    displayDelayUI();
}

void FearneSynthAudioProcessorEditor::displayDelayUI() {
    //activate/deactive delay processing
    bool delayActive = ui_delayActiveToggle->getToggleState();
    activeInterfaceValues[SYNTH_GLOBAL_DELAY_ACTIVE] = delayActive;
    audioProcessor.interfaceControlRouting(SYNTH_GLOBAL_DELAY_ACTIVE, delayActive);

    //change opacity of delay UI elements to show if it is active or not
    float displayAlpha = (static_cast<float>(delayActive) + 1.0) / 2.0;
    ui_delayFeedbackAmount->setAlpha(displayAlpha);
    ui_delayWetAmount->setAlpha(displayAlpha);
    ui_delayUnitOutputLevel0->setAlpha(displayAlpha);
    ui_delayUnitOutputLevel1->setAlpha(displayAlpha);
    ui_delayUnitOutputLevel2->setAlpha(displayAlpha);
    ui_delayTimeLeft0->setAlpha(displayAlpha);
    ui_delayTimeLeft1->setAlpha(displayAlpha);
    ui_delayTimeLeft2->setAlpha(displayAlpha);
    ui_delayTimeRight0->setAlpha(displayAlpha);
    ui_delayTimeRight1->setAlpha(displayAlpha);
    ui_delayTimeRight2->setAlpha(displayAlpha);
}

void FearneSynthAudioProcessorEditor::displayOscillatorUI() {
    //check if current oscillator is on or off
    float currentWaveshape = activeInterfaceValues[OSC_WAVESHAPE_0 + selectedOscillator];
    float displayAlpha = 1.0;
    if (currentWaveshape == INACTIVE) {
        displayAlpha = 0.5;
    }
    //change opacity of synth UI elements to show if it is active or not
    ui_oscAttackSeconds->setAlpha(displayAlpha);
    ui_oscDecaySeconds->setAlpha(displayAlpha);
    ui_oscSustainLevel->setAlpha(displayAlpha);
    ui_oscReleaseSeconds->setAlpha(displayAlpha);
    ui_oscLevel->setAlpha(displayAlpha);
    ui_oscPan->setAlpha(displayAlpha);
    ui_oscDetuneCents->setAlpha(displayAlpha);
    ui_oscDetuneNotes->setAlpha(displayAlpha);
    }

void FearneSynthAudioProcessorEditor::showPresetSaving(bool show) {
    //toggle preset saving UI staging
    ui_presetSave1->setVisible(show);
    ui_presetSave2->setVisible(show);
    ui_presetSave3->setVisible(show);
    ui_presetSaveCancel->setVisible(show);
    ui_presetSaveShow->setVisible(1 - show);
}

juce::String FearneSynthAudioProcessorEditor::formatFloat(float f_value) {
    //format float values for ADSR time displays
    if (f_value < 1.0f) {
        int msValue = static_cast<int>((f_value + std::numeric_limits<float>::epsilon()) * 1000.0);
        return juce::String::formatted("%dms", msValue);
    }
    else if (f_value < 10.0f) {
        return juce::String::formatted("%.2fs", f_value);
    }
    else {
        return juce::String::formatted("%.1fs", f_value);
    }
}

float FearneSynthAudioProcessorEditor::scaleTimeControlValue(float f_controlValue) {
    //scale a time value logarithmically so that a single UI slider can provide fine control for low values and
    //coarse control for high values - useful for ADSR
    float minLog = static_cast<float>(std::log(0.01)); // Log of min value, 10ms
    float maxLog = static_cast<float>(std::log(20.0)); // Log of max value, 20s

    // Interpolate between minLog and maxLog based on controlValue
    float interpolatedLog = static_cast<float>((1.0 - f_controlValue) * minLog + f_controlValue * maxLog);

    // Convert back to linear scale
    return std::exp(interpolatedLog);
}

//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="FearneSynthAudioProcessorEditor"
                 componentName="" parentClasses="public juce::AudioProcessorEditor"
                 constructorParams="FearneSynthAudioProcessor&amp; owner" variableInitialisers="AudioProcessorEditor(owner), audioProcessor(owner)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="752" initialHeight="208">
  <BACKGROUND backgroundColour="ff0c160b">
    <RECT pos="0 0 752 208" fill="solid: ff230e14" hasStroke="0"/>
    <ROUNDRECT pos="8 8 320 40" cornerSize="5.0" fill="solid: ffdc143c" hasStroke="0"/>
    <ROUNDRECT pos="260 164 44 8" cornerSize="10.0" fill="linear: 0 0, 752 208, 0=ff665858, 1=ff623737"
               hasStroke="0"/>
    <ROUNDRECT pos="696 64 40 136" cornerSize="5.0" fill="solid: ffdc143c" hasStroke="0"/>
    <ROUNDRECT pos="288 64 392 137" cornerSize="5.0" fill="solid: ffdc143c"
               hasStroke="0"/>
    <ROUNDRECT pos="8 63 264 137" cornerSize="5.0" fill="solid: ffdc143c" hasStroke="0"/>
    <ROUNDRECT pos="260 92 44 8" cornerSize="10.0" fill="linear: 0 0, 752 208, 0=ff665858, 1=ff623737"
               hasStroke="0"/>
    <ROUNDRECT pos="668 92 44 8" cornerSize="10.0" fill="linear: 0 0, 752 208, 0=ff665858, 1=ff623737"
               hasStroke="0"/>
    <ROUNDRECT pos="668 164 44 8" cornerSize="10.0" fill="linear: 0 0, 752 208, 0=ff665858, 1=ff623737"
               hasStroke="0"/>
    <ROUNDRECT pos="220 36 8 48" cornerSize="10.0" fill="linear: 0 0, 752 208, 0=ff665858, 1=ff623737"
               hasStroke="0"/>
    <ROUNDRECT pos="52 36 8 48" cornerSize="10.0" fill="linear: 0 0, 752 208, 0=ff665858, 1=ff623737"
               hasStroke="0"/>
    <ROUNDRECT pos="696 64 48 136" cornerSize="5.0" fill="linear: 0 0, 752 208, 0=ff665858, 1=ff623737"
               hasStroke="0"/>
    <ROUNDRECT pos="352 8 392 40" cornerSize="5.0" fill="linear: 0 0, 752 208, 0=ff665858, 1=ff623737"
               hasStroke="0"/>
    <ROUNDRECT pos="288 64 392 137" cornerSize="5.0" fill="linear: 0 0, 752 208, 0=ff665858, 1=ff623737"
               hasStroke="0"/>
    <ROUNDRECT pos="8 8 336 40" cornerSize="5.0" fill="linear: 0 0, 752 208, 0=ff665858, 1=ff623737"
               hasStroke="0"/>
    <ROUNDRECT pos="8 63 264 137" cornerSize="5.0" fill="linear: 0 0, 752 208, 0=ff665858, 1=ff623737"
               hasStroke="0"/>
  </BACKGROUND>
  <GROUPCOMPONENT name="new group" id="de5251d340cc489b" memberName="juce__groupComponent10"
                  virtualName="" explicitFocusOrder="0" pos="696 64 48 136" title="out"/>
  <GROUPCOMPONENT name="new group" id="406b5a823b30a70f" memberName="juce__groupComponent8"
                  virtualName="" explicitFocusOrder="0" pos="8 96 48 104" title="vol"/>
  <GROUPCOMPONENT name="new group" id="f811d40a84651a4c" memberName="juce__groupComponent5"
                  virtualName="" explicitFocusOrder="0" pos="56 96 112 48" title="pan"/>
  <GROUPCOMPONENT name="new group" id="f1ecc453b42c2f5a" memberName="juce__groupComponent7"
                  virtualName="" explicitFocusOrder="0" pos="512 64 168 48" textcol="ffffffff"
                  title="dry/wet"/>
  <GROUPCOMPONENT name="new group" id="ef5b01974b48d073" memberName="juce__groupComponent6"
                  virtualName="" explicitFocusOrder="0" pos="288 64 168 48" title="feedback"/>
  <GROUPCOMPONENT name="new group" id="cadadf0cc20a16bd" memberName="juce__groupComponent"
                  virtualName="" explicitFocusOrder="0" pos="56 144 112 56" title="detune"/>
  <LABEL name="new label" id="87978325f819dea6" memberName="juce__label"
         virtualName="" explicitFocusOrder="0" pos="512 16 48 24" edTextCol="ff000000"
         edBkgCol="0" labelText="load:" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <GROUPCOMPONENT name="new group" id="3ad410628052c10a" memberName="juce__groupComponent2"
                  virtualName="" explicitFocusOrder="0" pos="288 112 128 88" title="delay 1"/>
  <GROUPCOMPONENT name="new group" id="eb9ee7d3636507eb" memberName="juce__groupComponent3"
                  virtualName="" explicitFocusOrder="0" pos="416 112 128 88" title="delay 2"/>
  <GROUPCOMPONENT name="new group" id="6b5f83e529d2157b" memberName="juce__groupComponent4"
                  virtualName="" explicitFocusOrder="0" pos="544 112 128 88" title="delay 3"/>
  <TEXTBUTTON name="Save User Preset 1" id="94c9f5dd480c106f" memberName="ui_presetSave1"
              virtualName="" explicitFocusOrder="0" pos="360 16 24 24" bgColOff="ff4b2e2e"
              bgColOn="ffd24d6c" buttonText="1" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <TEXTBUTTON name="Save User Preset 2" id="58be30e9237c7e73" memberName="ui_presetSave2"
              virtualName="" explicitFocusOrder="0" pos="392 16 24 24" bgColOff="ff4b2e2e"
              bgColOn="ffd24d6c" buttonText="2" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <TEXTBUTTON name="Save User Preset 3" id="8386e25b69607e9" memberName="ui_presetSave3"
              virtualName="" explicitFocusOrder="0" pos="424 16 24 24" bgColOff="ff4b2e2e"
              bgColOn="ffd24d6c" buttonText="3" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <TEXTBUTTON name="Cancel User Preset Save" id="ae239a1f481b690a" memberName="ui_presetSaveCancel"
              virtualName="" explicitFocusOrder="0" pos="456 16 48 24" bgColOff="ff4b2e2e"
              bgColOn="ffd24d6c" buttonText="cancel" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <TEXTBUTTON name="Show User Preset Save" id="4576b5127b147699" memberName="ui_presetSaveShow"
              virtualName="" explicitFocusOrder="0" pos="360 16 144 24" bgColOff="ff4b2e2e"
              bgColOn="ffd24d6c" buttonText="save preset" connectedEdges="0"
              needsCallback="1" radioGroupId="0"/>
  <COMBOBOX name="Selected Oscillator Waveshape" id="4c8dec447fce318d" memberName="ui_oscWaveshape"
            virtualName="" explicitFocusOrder="0" pos="16 72 152 24" editable="0"
            layout="33" items="select waveshape&#10;sine&#10;square&#10;saw&#10;triangle"
            textWhenNonSelected="" textWhenNoItems="error_no_osc"/>
  <SLIDER name="Selected Oscillator Attack in Seconds" id="2ee6319e2d294240"
          memberName="ui_oscAttackSeconds" virtualName="" explicitFocusOrder="0"
          pos="176 80 88 24" min="0.0" max="1.0" int="0.0" style="LinearBar"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <SLIDER name="Selected Oscillator Decay in Seconds" id="b968831c96104bd6"
          memberName="ui_oscDecaySeconds" virtualName="" explicitFocusOrder="0"
          pos="176 112 88 24" min="0.0" max="1.0" int="0.0" style="LinearBar"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <SLIDER name="Selected Oscillator Sustain Level" id="bf2020b35ea7d8e"
          memberName="ui_oscSustainLevel" virtualName="" explicitFocusOrder="0"
          pos="176 144 88 16" min="0.0" max="1.0" int="0.01" style="LinearBar"
          textBoxPos="TextBoxLeft" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <SLIDER name="Selected Oscillator Release in Seconds" id="4ad68ff83bfe4edd"
          memberName="ui_oscReleaseSeconds" virtualName="" explicitFocusOrder="0"
          pos="176 168 88 24" min="0.0" max="1.0" int="0.0" style="LinearBar"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <SLIDER name="Selected Oscillator Level" id="43f6d29e8df802a" memberName="ui_oscLevel"
          virtualName="" explicitFocusOrder="0" pos="20 112 24 80" tooltip="Level"
          min="0.0" max="1.0" int="0.01" style="LinearBarVertical" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <TEXTBUTTON name="Select Oscillator 0" id="33a65d0880c2ba7c" memberName="ui_oscSelect0"
              virtualName="" explicitFocusOrder="0" pos="16 16 48 24" bgColOff="ff4b2e2e"
              bgColOn="ffd24d6c" buttonText="osc a" connectedEdges="0" needsCallback="1"
              radioGroupId="1"/>
  <TEXTBUTTON name="Select Oscillator 1" id="bab44d636db17a14" memberName="ui_oscSelect1"
              virtualName="" explicitFocusOrder="0" pos="72 16 48 24" bgColOff="ff4b2e2e"
              bgColOn="ffd24d6c" buttonText="osc b" connectedEdges="0" needsCallback="1"
              radioGroupId="1"/>
  <TEXTBUTTON name="Select Oscillator 2" id="3be77676d9f948c1" memberName="ui_oscSelect2"
              virtualName="" explicitFocusOrder="0" pos="128 16 48 24" bgColOff="ff4b2e2e"
              bgColOn="ffd24d6c" buttonText="osc c" connectedEdges="0" needsCallback="1"
              radioGroupId="1"/>
  <TEXTBUTTON name="Select Oscillator 3" id="81001097fd75f6fc" memberName="ui_oscSelect3"
              virtualName="" explicitFocusOrder="0" pos="184 16 48 24" bgColOff="ff4b2e2e"
              bgColOn="ffd24d6c" buttonText="osc d" connectedEdges="0" needsCallback="1"
              radioGroupId="1"/>
  <SLIDER name="Global Level" id="c862bd23ebfbfe32" memberName="ui_globalLevel"
          virtualName="" explicitFocusOrder="0" pos="704 80 32 112" min="0.0"
          max="1.0" int="0.0" style="LinearBarVertical" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <COMBOBOX name="Load Preset" id="908bf142e639fdc6" memberName="ui_presetLoad"
            virtualName="" explicitFocusOrder="0" pos="552 16 184 24" editable="0"
            layout="33" items="default&#10;user preset 1&#10;user preset 2&#10;user preset 3&#10;floaty triangles&#10;full bodied bass&#10;major square&#10;soft pad&#10;sparks&#10;spooky echoes&#10;sub bass"
            textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <SLIDER name="Pitch Bend Range" id="3327eff8187950d8" memberName="ui_pitchBendRange"
          virtualName="" explicitFocusOrder="0" pos="304 16 32 24" min="0.0"
          max="24.0" int="1.0" style="LinearBar" textBoxPos="TextBoxAbove"
          textBoxEditable="1" textBoxWidth="40" textBoxHeight="24" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="new slider" id="d372903ddcf545ac" memberName="ui_oscPan"
          virtualName="" explicitFocusOrder="0" pos="64 112 96 24" min="-50.0"
          max="50.0" int="1.0" style="LinearBar" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="24" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="Detune Cents" id="69b2355e19cffdc1" memberName="ui_oscDetuneCents"
          virtualName="" explicitFocusOrder="0" pos="116 160 44 32" min="-100.0"
          max="100.0" int="1.0" style="LinearBar" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="24" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="Detune Notes" id="8186e83a6804bdf" memberName="ui_oscDetuneNotes"
          virtualName="" explicitFocusOrder="0" pos="64 160 44 32" min="-24.0"
          max="24.0" int="1.0" style="LinearBar" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="24" skewFactor="1.0"
          needsCallback="1"/>
  <TEXTBUTTON name="Delay Active Toggle" id="e68c07007719b2bb" memberName="ui_delayActiveToggle"
              virtualName="" explicitFocusOrder="0" pos="456 80 56 24" bgColOff="ff4b2e2e"
              bgColOn="ffd24d6c" buttonText="delay" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <SLIDER name="Delay Feedback Amount" id="b20e705a7271b3cd" memberName="ui_delayFeedbackAmount"
          virtualName="" explicitFocusOrder="0" pos="296 80 152 24" min="0.0"
          max="1.1" int="0.01" style="LinearBar" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="Delay Wet Amount" id="b9620ad6c523b91d" memberName="ui_delayWetAmount"
          virtualName="" explicitFocusOrder="0" pos="520 80 152 24" min="0.0"
          max="100.0" int="1.0" style="LinearBar" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="Delay Time Left 0" id="8765f5e7cd0a5dbd" memberName="ui_delayTimeLeft0"
          virtualName="" explicitFocusOrder="0" pos="304 136 72 24" min="0.0"
          max="2500.0" int="1.0" style="LinearBar" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="Delay Time Left 1" id="7bce9f5185f1352b" memberName="ui_delayTimeLeft1"
          virtualName="" explicitFocusOrder="0" pos="432 136 72 24" min="0.0"
          max="2500.0" int="1.0" style="LinearBar" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="Delay Time Left 2" id="95f6ccb78f6579d7" memberName="ui_delayTimeLeft2"
          virtualName="" explicitFocusOrder="0" pos="560 136 72 24" min="0.0"
          max="2500.0" int="1.0" style="LinearBar" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="Delay Time Right 0" id="f188092fd5c936e7" memberName="ui_delayTimeRight0"
          virtualName="" explicitFocusOrder="0" pos="304 160 72 24" min="0.0"
          max="2500.0" int="1.0" style="LinearBar" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="Delay Time Right 1" id="89828967f67f70ef" memberName="ui_delayTimeRight1"
          virtualName="" explicitFocusOrder="0" pos="432 160 72 24" min="0.0"
          max="2500.0" int="1.0" style="LinearBar" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="Delay Time Right 2" id="1ae303159e7fb381" memberName="ui_delayTimeRight2"
          virtualName="" explicitFocusOrder="0" pos="560 160 72 24" min="0.0"
          max="2500.0" int="1.0" style="LinearBar" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="Delay Unit Output Level 0" id="114f731cde5ece4a" memberName="ui_delayUnitOutputLevel0"
          virtualName="" explicitFocusOrder="0" pos="384 128 24 64" min="0.0"
          max="1.0" int="0.01" style="LinearBarVertical" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="Delay Unit Output Level 2" id="365ae0a51edc0d29" memberName="ui_delayUnitOutputLevel2"
          virtualName="" explicitFocusOrder="0" pos="640 128 24 64" min="0.0"
          max="1.0" int="0.01" style="LinearBarVertical" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="Delay Unit Output Level 1" id="286ed7534094654f" memberName="ui_delayUnitOutputLevel1"
          virtualName="" explicitFocusOrder="0" pos="512 128 24 64" min="0.0"
          max="1.0" int="0.01" style="LinearBarVertical" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="Decay Label" id="83f9db3b5d6fc92c" memberName="ui_oscDecayLabel"
         virtualName="" explicitFocusOrder="0" pos="176 112 88 24" edTextCol="ff000000"
         edBkgCol="0" labelText="999ms" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="Attack Label" id="b3266840326efab1" memberName="ui_oscAttackLabel"
         virtualName="" explicitFocusOrder="0" pos="176 80 88 24" edTextCol="ff000000"
         edBkgCol="0" labelText="20.0s&#10;" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="Release Label" id="7c05846b286ea88f" memberName="ui_oscReleaseLabel"
         virtualName="" explicitFocusOrder="0" pos="176 168 88 24" edTextCol="ff000000"
         edBkgCol="0" labelText="7.05s" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="bc8ad934f9a0c899" memberName="juce__label2"
         virtualName="" explicitFocusOrder="0" pos="232 16 72 25" edTextCol="ff000000"
         edBkgCol="0" labelText="pb range:" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <GROUPCOMPONENT name="new group" id="3600e2058a5021dc" memberName="juce__groupComponent9"
                  virtualName="" explicitFocusOrder="0" pos="168 64 104 136" title="adsr"/>
  <LABEL name="new label" id="d89bb90a0c409eaa" memberName="juce__label3"
         virtualName="" explicitFocusOrder="0" pos="288 136 24 24" edTextCol="ff000000"
         edBkgCol="0" labelText="L" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="f117dd2ae3383ea9" memberName="juce__label4"
         virtualName="" explicitFocusOrder="0" pos="288 160 24 24" edTextCol="ff000000"
         edBkgCol="0" labelText="R" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="644f0c3f24e8cd06" memberName="juce__label5"
         virtualName="" explicitFocusOrder="0" pos="416 136 24 24" edTextCol="ff000000"
         edBkgCol="0" labelText="L" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="df2a6fa285397d16" memberName="juce__label6"
         virtualName="" explicitFocusOrder="0" pos="416 160 24 24" edTextCol="ff000000"
         edBkgCol="0" labelText="R" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="75a5f0c44200bc1f" memberName="juce__label7"
         virtualName="" explicitFocusOrder="0" pos="544 136 24 24" edTextCol="ff000000"
         edBkgCol="0" labelText="L" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="24efc7d551f521de" memberName="juce__label8"
         virtualName="" explicitFocusOrder="0" pos="544 160 24 24" edTextCol="ff000000"
         edBkgCol="0" labelText="R" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="Temp Save" id="3e896ddfeb0db20f" memberName="ui_tempSave"
              virtualName="" explicitFocusOrder="0" pos="16 304 96 24" buttonText="Temp Save"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

