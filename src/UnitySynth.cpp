#ifdef __cplusplus
extern "C" {
#endif

UNITY_INTERFACE_EXPORT void UNITY_INTERFACE_API noteOn(int noteNumber, float velocity)
{
    if(playfultones::UnityWrapper::instance == nullptr)
        return;
    playfultones::UnityWrapper::instance->noteOn(1, noteNumber, velocity);
}

UNITY_INTERFACE_EXPORT void UNITY_INTERFACE_API noteOff(int noteNumber)
{
    if(playfultones::UnityWrapper::instance == nullptr)
        return;
    playfultones::UnityWrapper::instance->noteOff(1, noteNumber, 1);
}

#ifdef __cplusplus
}
#endif


namespace playfultones::UnityWrapper
{
    playfultones::UnitySynth* instance = nullptr;
}

playfultones::UnitySynth::UnitySynth(juce::MidiKeyboardState& state)
: _keyboardState(state)
{
}

playfultones::UnitySynth::~UnitySynth()
{
    if(UnityWrapper::instance == this)
        UnityWrapper::instance = nullptr;
}

void playfultones::UnitySynth::initialize()
{
    UnityWrapper::instance = this;
}

void playfultones::UnitySynth::noteOn(int channel, int noteNumber, float velocity)
{
    _keyboardState.noteOn(channel, noteNumber, velocity);
}

void playfultones::UnitySynth::noteOff(int channel, int noteNumber, float velocity)
{
    _keyboardState.noteOff(channel, noteNumber, velocity);
}
