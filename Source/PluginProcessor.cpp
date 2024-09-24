/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
FearneSynthAudioProcessor::FearneSynthAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  juce::AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", juce::AudioChannelSet::stereo(), true)
                     #endif
                       )
#endif
{
}

FearneSynthAudioProcessor::~FearneSynthAudioProcessor()
{
}

//==============================================================================
const juce::String FearneSynthAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool FearneSynthAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool FearneSynthAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool FearneSynthAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double FearneSynthAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int FearneSynthAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int FearneSynthAudioProcessor::getCurrentProgram()
{
    return 0;
}

void FearneSynthAudioProcessor::setCurrentProgram (int index)
{
}

const juce::String FearneSynthAudioProcessor::getProgramName (int index)
{
    return {};
}

void FearneSynthAudioProcessor::changeProgramName (int index, const juce::String& newName)
{
}

//==============================================================================
void FearneSynthAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    voiceManager_.setSampleRate(sampleRate);
    delayArray_.initBuffers(sampleRate, 2.5);
}

void FearneSynthAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool FearneSynthAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    juce::ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    // Some plugin hosts, such as certain GarageBand versions, will only
    // load plugins that support stereo bus layouts.
    if (layouts.getMainOutputChannelSet() != juce::AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void FearneSynthAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    //midi processing
    if (!midiMessages.isEmpty())
    {
        for (const auto messageList : midiMessages)
        {
            auto message = messageList.getMessage();

            if (message.isNoteOn()) {
                voiceManager_.noteOn(message.getNoteNumber(), message.getVelocity());
            }
            else if (message.isNoteOff()) {
                voiceManager_.noteOff(message.getNoteNumber());
            }
            else if (message.isPitchWheel()) {
                int pitchBend = message.getPitchWheelValue();
                if (pitchBend == 0) pitchBend += 1;
                voiceManager_.pitchBend(static_cast<float>(pitchBend - 8192) * midiPitchBendRange);
            }
        }
    }

    int bufferLength = buffer.getNumSamples();
    float* bufferLeft = buffer.getWritePointer(0);
    float* bufferRight = buffer.getWritePointer(1);
    std::array<float, 2> currentSample = {0.0, 0.0};

    //audio processing
    for (int i = 0; i < bufferLength; i++) {
        //synth
        currentSample = {0.0, 0.0};
        currentSample = voiceManager_.getNextSample();

        //delay
        if (delayActive) { currentSample = delayArray_.getNextSample(currentSample); }
        
        //output
        bufferLeft[i] = currentSample[0] * synthGlobalLevel;
        bufferRight[i] = currentSample[1] * synthGlobalLevel;
    }
}

//route ui values
void FearneSynthAudioProcessor::interfaceControlRouting(InterfaceRoutingAddresses f_routingDestination, float f_value) {
    if (f_routingDestination > _ROUTING_VOICE_MANAGER_START && f_routingDestination < _ROUTING_VOICE_MANAGER_END) {
        voiceManager_.interfaceControlRouting(f_routingDestination, f_value);
    }
    else if (f_routingDestination > _ROUTING_DELAY_ARRAY_START && f_routingDestination < _ROUTING_DELAY_ARRAY_END) {
        delayArray_.interfaceControlRouting(f_routingDestination, f_value);
    }
    else if (f_routingDestination == SYNTH_GLOBAL_LEVEL) {
        synthGlobalLevel = f_value;
    }
    else if (f_routingDestination == SYNTH_GLOBAL_MIDI_PB_RANGE) {
        midiPitchBendRange = f_value / 8191.0;
    }
    else if (f_routingDestination == SYNTH_GLOBAL_DELAY_ACTIVE) {
        delayActive = static_cast<int>(f_value + std::numeric_limits<float>::epsilon());
    }
}

void FearneSynthAudioProcessor::killDelay() {
    delayArray_.killDelay();
}

//propogate all values from the new preset/initial load
void FearneSynthAudioProcessor::propogatePresetValues(const std::array<float, _ROUTING_ARRAY_END>& f_presetValues) {
    for (int i = 0; i < _ROUTING_ARRAY_END; ++i) {
        interfaceControlRouting(static_cast<InterfaceRoutingAddresses>(i), f_presetValues[i]);
    }
}

//==============================================================================
bool FearneSynthAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

juce::AudioProcessorEditor* FearneSynthAudioProcessor::createEditor()
{
    return new FearneSynthAudioProcessorEditor (*this);
}

//==============================================================================
void FearneSynthAudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void FearneSynthAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new FearneSynthAudioProcessor();
}
