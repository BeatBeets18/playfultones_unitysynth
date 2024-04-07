#pragma once

#ifdef __cplusplus
extern "C" {
#endif
    UNITY_INTERFACE_EXPORT void* UNITY_INTERFACE_API getInstance();
    UNITY_INTERFACE_EXPORT void  UNITY_INTERFACE_API noteOn(void* ptr, int noteNumber, float velocity);
    UNITY_INTERFACE_EXPORT void  UNITY_INTERFACE_API noteOff(void* ptr, int noteNumber);
#ifdef __cplusplus
}
#endif

namespace playfultones
{
struct UnitySynth
{
public:
    UnitySynth(juce::MidiKeyboardState&);
    virtual ~UnitySynth();
    virtual void initialize();
    virtual void noteOn(int channel, int noteNumber, float velocity);
    virtual void noteOff(int channel, int noteNumber, float velocity);
private:
    juce::MidiKeyboardState& _keyboardState;
};

namespace UnityWrapper
{
    extern UnitySynth* instance;
}
}
