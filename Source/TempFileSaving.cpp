/*
  ==============================================================================

    TempFileSaving.cpp
    Created: 16 May 2023 7:33:48am
    Author:  Ellie

  ==============================================================================
*/

#include "TempFileSaving.h"

void TempFileSaving::writePresetToFile(std::array<float, _ROUTING_ARRAY_END> f_activeInterfaceValues,
    int f_presetNumber) {

    std::ofstream file("preset_temp_save.txt");
    if (!file) {
        std::cerr << "Could not open file for writing: " << "preset_temp_save.txt" << "\n";
        return;
    }

    file << "presetInterfaceValues[XXX] = { ";
    for (int i = 0; i < _ROUTING_ARRAY_END; ++i) {
        //file << "presetInterfaceValues[" << f_presetNumber << "][" << i << "] = " << f_activeInterfaceValues[i] << ";\n";
        file << f_activeInterfaceValues[i] << ", ";
    }
    file << "};";
}