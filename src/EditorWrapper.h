//
// Created by Bence Kovács on 07/04/2024.
//

#ifndef PLAYFULTONES_EDITORWRAPPER_H
#define PLAYFULTONES_EDITORWRAPPER_H

#ifdef __cplusplus
extern "C" {
#endif
UNITY_INTERFACE_EXPORT void UNITY_INTERFACE_API showEditor();
UNITY_INTERFACE_EXPORT void UNITY_INTERFACE_API closeEditor();
#ifdef __cplusplus
}
#endif

namespace playfultones
{
    class EditorWrapper : public juce::DocumentWindow
    {
    public:
        explicit EditorWrapper (juce::AudioProcessor& proc);
        ~EditorWrapper() override;

        juce::AudioProcessorEditor* getEditor() const;

        void closeButtonPressed() override;
        std::function<void()> onWindowClose {};
    private:
        juce::AudioProcessor& processor;
        std::unique_ptr<juce::AudioProcessorEditor> editor;
        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(EditorWrapper)
    };

    namespace UnityWrapper
    {
        extern std::unique_ptr<EditorWrapper> editorWrapper;
        extern juce::AudioProcessor* pluginProcessor;
    }
}



#endif //PLAYFULTONES_EDITORWRAPPER_H
