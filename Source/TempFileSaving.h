/*
  ==============================================================================

    TempFileSaving.h
    Created: 16 May 2023 7:33:48am
    Author:  Ellie

  ==============================================================================
*/

#pragma once

#include <fstream>
#include <iostream>
#include "EnumDefs.h"
#include <array>

class TempFileSaving {
public:
    void writePresetToFile(std::array<float, _ROUTING_ARRAY_END> f_activeInterfaceValues,
        int f_presetNumber);
};