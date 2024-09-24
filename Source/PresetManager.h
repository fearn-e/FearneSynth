/*
  ==============================================================================

    PresetManager.h
    Created: 14 May 2023 3:46:27am
    Author:  Ellie

  ==============================================================================
*/

#pragma once
#include <array>
#include "EnumDefs.h"

// num of presets in drop down
static constexpr std::size_t presetCount = 11;

class PresetManager {
public:
    PresetManager();

    void interactPreset(PresetManagerInstructions instruction, 
        PresetManagerInstructions preset, 
        std::array<float, _ROUTING_ARRAY_END>& f_liveValues);

private:
    std::array<std::array<float, _ROUTING_ARRAY_END>, presetCount> presetInterfaceValues;
};