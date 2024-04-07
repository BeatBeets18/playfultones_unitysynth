/** BEGIN_JUCE_MODULE_DECLARATION
ID:               playfultones_unitysynth
vendor:           Playful Tones
version:          1.0.0
name:             playfultones_unitysynth
description:      Wrapper class for synth plugins used in Unity.
website:          https://github.com/playfultones
license:          GPL-3.0
dependencies:     juce_audio_basics
END_JUCE_MODULE_DECLARATION
*/
#pragma once
#define PLAYFULTONES_UNITYSYNTH_H_INCLUDED

#include <juce_audio_basics/juce_audio_basics.h>

#include "src/UnityInterfaceHelpers.h"
#include "src/UnitySynth.h"
#include "src/UnityLogger.h"
