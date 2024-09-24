/*
  ==============================================================================

    EnumDefs.h
    Created: 13 May 2023 12:35:26am
    Author:  Ellie

  ==============================================================================
*/

#pragma once

//bank sizes for the synth and delay
static constexpr std::size_t synthBankSize = 4;
static const std::size_t delayBankSize = 3;

//routing address information for values sent from the UI to the processing engine
enum InterfaceRoutingAddresses {
    _ROUTING_VOICE_MANAGER_START,
    ENV_ATTACK_UI_0,            ENV_ATTACK_UI_1, ENV_ATTACK_UI_2,           ENV_ATTACK_UI_LAST,
    ENV_ATTACK_REAL_0,          ENV_ATTACK_REAL_1, ENV_ATTACK_REAL_2,       ENV_ATTACK_REAL_LAST,
    ENV_DECAY_UI_0,             ENV_DECAY_UI_1, ENV_DECAY_UI_2,             ENV_DECAY_UI_LAST,
    ENV_DECAY_REAL_0,           ENV_DECAY_REAL_1, ENV_DECAY_REAL_2,         ENV_DECAY_REAL_LAST,
    ENV_SUSTAIN_0,              ENV_SUSTAIN_1, ENV_SUSTAIN_2,               ENV_SUSTAIN_LAST, 
    ENV_RELEASE_UI_0,           ENV_RELEASE_UI_1, ENV_RELEASE_UI_2,         ENV_RELEASE_UI_LAST,
    ENV_RELEASE_REAL_0,         ENV_RELEASE_REAL_1, ENV_RELEASE_REAL_2,     ENV_RELEASE_REAL_LAST,
    OSC_WAVESHAPE_0,            OSC_WAVESHAPE_1, OSC_WAVESHAPE_2,           OSC_WAVESHAPE_LAST,
    OSC_LEVEL_0,                OSC_LEVEL_1, OSC_LEVEL_2,                   OSC_LEVEL_LAST,
    OSC_PAN_0,                  OSC_PAN_1, OSC_PAN_2,                       OSC_PAN_LAST,
    OSC_DETUNE_NOTES_0,         OSC_DETUNE_NOTES_1, OSC_DETUNE_NOTES_2,     OSC_DETUNE_NOTES_LAST,
    OSC_DETUNE_CENTS_0,         OSC_DETUNE_CENTS_1, OSC_DETUNE_CENTS_2,     OSC_DETUNE_CENTS_LAST,
    _ROUTING_VOICE_MANAGER_END,

    _ROUTING_DELAY_ARRAY_START,
    DELAY_WET_SIGNAL_PERCENTAGE,
    DELAY_FEEDBACK_AMOUNT,
    DELAY_UNIT_OUTPUT_LEVEL_0,  DELAY_UNIT_OUTPUT_LEVEL_1,                  DELAY_UNIT_OUTPUT_LEVEL_LAST,
    DELAY_UNIT_TIME_LEFT_0,     DELAY_UNIT_TIME_LEFT_1,                     DELAY_UNIT_TIME_LEFT_LAST,
    DELAY_UNIT_TIME_RIGHT_0,    DELAY_UNIT_TIME_RIGHT_1,                    DELAY_UNIT_TIME_RIGHT_LAST,
    _ROUTING_DELAY_ARRAY_END,

    SYNTH_GLOBAL_DELAY_ACTIVE,
    SYNTH_GLOBAL_LEVEL,
    SYNTH_GLOBAL_MIDI_PB_RANGE,

    _ROUTING_ARRAY_END
};

enum PresetManagerInstructions {
    PRESET_LOAD, PRESET_SAVE,
    PRESET_DEFAULT, PRESET_USER_1, PRESET_USER_2, PRESET_USER_3
};

enum EnvelopeState {
  ATTACK = 0,
  DECAY = 1,
  SUSTAIN = 2,
  RELEASE = 3,
  STOLEN = 4,
  IDLE = 5
};