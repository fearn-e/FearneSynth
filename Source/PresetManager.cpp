/*
  ==============================================================================

    PresetManager.cpp
    Created: 14 May 2023 3:46:27am
    Author:  Ellie

  ==============================================================================
*/

#include "PresetManager.h"

PresetManager::PresetManager() {
    //set default preset values for Default and User1/2/3 presets
    for (int p = 0; p < 4; ++p) {
        //default voice values
        for (int i = 0; i < synthBankSize; ++i) {
            presetInterfaceValues[p][ENV_ATTACK_UI_0 + i] = 0.1f;
            presetInterfaceValues[p][ENV_ATTACK_REAL_0 + i] = 0.0213847f;
            presetInterfaceValues[p][ENV_DECAY_UI_0 + i] = 0.45f;
            presetInterfaceValues[p][ENV_DECAY_REAL_0 + i] = 0.305818f;
            presetInterfaceValues[p][ENV_SUSTAIN_0 + i] = 0.6f;
            presetInterfaceValues[p][ENV_RELEASE_UI_0 + i] = 0.54f;
            presetInterfaceValues[p][ENV_RELEASE_REAL_0 + i] = 0.606117f;
            presetInterfaceValues[p][OSC_WAVESHAPE_0 + i] = 0.0f;
            presetInterfaceValues[p][OSC_LEVEL_0 + i] = 0.0f;
            presetInterfaceValues[p][OSC_PAN_0 + i] = 0.0f;
            presetInterfaceValues[p][OSC_DETUNE_NOTES_0 + i] = 0.0f;
            presetInterfaceValues[p][OSC_DETUNE_CENTS_0 + i] = 0.0f;
        }
        //overwrite first oscillator to be sine wave
        presetInterfaceValues[p][OSC_WAVESHAPE_0] = 1.0f;
        presetInterfaceValues[p][OSC_LEVEL_0] = 1.0f;
        //default delay values
        for (int i = 0; i < delayBankSize; ++i) {
            presetInterfaceValues[p][DELAY_UNIT_OUTPUT_LEVEL_0 + i] = 0.0f;
            presetInterfaceValues[p][DELAY_UNIT_TIME_LEFT_0 + i] = 0.25f;
            presetInterfaceValues[p][DELAY_UNIT_TIME_RIGHT_0 + i] = 0.25f;
        }
        presetInterfaceValues[p][DELAY_FEEDBACK_AMOUNT] = 0.0f;
        presetInterfaceValues[p][DELAY_WET_SIGNAL_PERCENTAGE] = 50.0f;
        //default global values
        presetInterfaceValues[p][SYNTH_GLOBAL_DELAY_ACTIVE] = 0.0f;
        presetInterfaceValues[p][SYNTH_GLOBAL_LEVEL] = 0.717f;
        presetInterfaceValues[p][SYNTH_GLOBAL_MIDI_PB_RANGE] = 2.0f;
    }

    //floaty triangles
    presetInterfaceValues[4] = { -4.31602e+08, 0.662791, 0.534884, 0.616279, 0.1, 1.54132, 0.582998, 1.08232, 0.0213847, 0.45, 0.45, 0.372093, 0.45, 0.305818, 0.305818, 0.169157, 0.305818, 0.6, 0.42, 0.41, 0.6, 0.674419, 0.709302, 0.686047, 0.54, 1.68374, 2.19497, 1.83933, 0.606117, 4, 4, 2, 0, 1, 0.68, 0.18, 0, 0, -16, 15, 0, 0, 0, 0, 0, 0, -0.28, -0.09, 0, -4.31602e+08, -4.31602e+08, 20, 0, 0.81, 0, 0, 0.464, 0.25, 0.25, 0.643, 0.25, 0.25, -4.31602e+08, 0, 0.717, 12 };
    //full bodied bass
    presetInterfaceValues[5] = { -4.31602e+08, 0.0116279, 0, 0, 0.1, 0.0109241, 0.01, 0.01, 0.0213847, 0.45, 0.45, 0.45, 0.45, 0.305818, 0.305818, 0.305818, 0.305818, 0.85, 1, 0.6, 0.6, 0, 0, 0, 0.54, 0.01, 0.01, 0.01, 0.606117, 2, 1, 3, 0, 1, 0.82, 0.68, 0, 0, 0, 0, 0, 0, -12, 12, 0, 0, 0, 0, 0, -4.31602e+08, -4.31602e+08, 50, 0, 0, 0, 0, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, -4.31602e+08, 0, 0.527273, 2 };
    //major square
    presetInterfaceValues[6] = { -4.31602e+08, 0.197674, 0.209302, 0.1, 0.1, 0.0449293, 0.049081, 0.0213847, 0.0213847, 0.337209, 0.244186, 0.45, 0.45, 0.129759, 0.0639831, 0.305818, 0.305818, 0.38, 0.41, 0.6, 0.6, 0.54, 0.54, 0.54, 0.54, 0.606117, 0.606117, 0.606117, 0.606117, 2, 2, 2, 0, 0.59, 0.5, 0.55, 0, 0, 0, 0, 0, 0, 4, 7, 0, 0, 0, 0, 0, -4.31602e+08, -4.31602e+08, 50, 0, 0, 0, 0, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, -4.31602e+08, 0, 0.717, 2 };
    //soft pad
    presetInterfaceValues[7] = { -4.31602e+08, 0.267442, 0.244186, 0.290698, 0.302326, 0.0763543, 0.0639831, 0.0911175, 0.0995373, 0.313953, 0.383721, 0.337209, 0.383721, 0.108735, 0.184788, 0.129759, 0.184788, 0.76, 0.74, 0.73, 0.71, 0.686047, 0.686047, 0.686047, 0.709302, 1.83933, 1.83933, 1.83933, 2.19497, 1, 1, 1, 1, 1, 1, 1, 1, 8, -29, 27, -8, 0, 0, 0, 0, 0, 0.19, -0.05, 0.29, -4.31602e+08, -4.31602e+08, 50, 0, 0, 0, 0, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, -4.31602e+08, 0, 0.717, 2 };
    //sparks
    presetInterfaceValues[8] = { -4.31602e+08, 0.1, 0.1, 0.139535, 0.1, 0.0213847, 0.0213847, 0.0288808, 0.0213847, 0.116279, 0.162791, 0.104651, 0.232558, 0.0242014, 0.0344649, 0.0221542, 0.0585708, 0, 0, 0, 0, 0.116279, 0.162791, 0.104651, 0.22093, 0.0242014, 0.0344649, 0.0221542, 0.0536164, 2, 3, 1, 2, 1, 0.55, 0.95, 0.55, 0, 0, -18, 18, 0, 0, -12, 0, 0.14, 0, 0.14, -0.19, -4.31602e+08, -4.31602e+08, 25, 0.67, 0.56, 0.35, 0.27, 0.287, 0.243, 0.145, 0.286, 0.245, 0.144, -4.31602e+08, 1, 0.745455, 2 };
    //spooky echoes
    presetInterfaceValues[9] = { -4.31602e+08, 0.162791, 0.170312, 0.1, 0.1, 0.0344649, 0.0364928, 0.0213847, 0.0213847, 0.430233, 0.395349, 0.45, 0.45, 0.263154, 0.201864, 0.305818, 0.305818, 0.31, 0.29, 0.6, 0.6, 0.569767, 0.546512, 0.54, 0.54, 0.76001, 0.636871, 0.606117, 0.606117, 3, 3, 0, 0, 1, 0.59, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -0.07, 0.64, 0, 0, -4.31602e+08, -4.31602e+08, 50, 0.28, 1, 1, 1, 0.5, 0.125, 0.25, 0.75, 0.333, 0.25, -4.31602e+08, 1, 0.717, 2 };
    //sub bass
    presetInterfaceValues[10] = { -4.31602e+08, 0, 0, 0, 0.1, 0.01, 0.01, 0.01, 0.0213847, 0.267442, 0.45, 0.45, 0.45, 0.0763543, 0.305818, 0.305818, 0.305818, 1, 1, 0.6, 0.6, 0, 0, 0, 0.54, 0.01, 0.01, 0.01, 0.606117, 1, 0, 0, 0, 1, 1, 0.68, 0, 0, 0, 0, 0, 0, 0, 12, 0, 0, 0, 0, 0, -4.31602e+08, -4.31602e+08, 50, 0, 0, 0, 0, 0.25, 0.25, 0.25, 0.25, 0.25, 0.25, -4.31602e+08, 0, 0.963636, 2 };
}

void PresetManager::interactPreset(PresetManagerInstructions instruction, PresetManagerInstructions preset, std::array<float, _ROUTING_ARRAY_END>& f_liveValues) {
    switch (instruction) {
    case PRESET_LOAD:
        f_liveValues = presetInterfaceValues[preset - PRESET_DEFAULT]; break;
    case PRESET_SAVE:
        presetInterfaceValues[preset - PRESET_DEFAULT] = f_liveValues; break;
    }
}