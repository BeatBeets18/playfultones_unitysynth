//
// Created by Bence Kovács on 07/04/2024.
//

#ifdef __cplusplus
extern "C" {
#endif

UNITY_INTERFACE_EXPORT void UNITY_INTERFACE_API showEditor()
{
    juce::MessageManager::callAsync([](){
        if(playfultones::UnityWrapper::pluginProcessor == nullptr)
            return;

        playfultones::UnityWrapper::editorWrapper = std::make_unique<playfultones::EditorWrapper>
            (*playfultones::UnityWrapper::pluginProcessor);

        playfultones::UnityWrapper::editorWrapper->setVisible(true);
        playfultones::UnityWrapper::editorWrapper->onWindowClose = []()
        {
            if(playfultones::UnityWrapper::pluginProcessor != nullptr && playfultones::UnityWrapper::editorWrapper != nullptr)
            {
                playfultones::UnityWrapper::pluginProcessor->editorBeingDeleted (playfultones::UnityWrapper::editorWrapper->getEditor());
                playfultones::UnityWrapper::editorWrapper.reset();
            }
        };
    });
}

UNITY_INTERFACE_EXPORT void UNITY_INTERFACE_API closeEditor()
{
    if(playfultones::UnityWrapper::editorWrapper != nullptr)
    {
        playfultones::UnityWrapper::editorWrapper->closeButtonPressed();
    }
}

#ifdef __cplusplus
}
#endif

namespace playfultones {

namespace UnityWrapper
{
    std::unique_ptr<EditorWrapper> editorWrapper = nullptr;
    juce::AudioProcessor* pluginProcessor = nullptr;
}

EditorWrapper::EditorWrapper (juce::AudioProcessor& p)
: DocumentWindow ("Dev editor", juce::LookAndFeel::getDefaultLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId), DocumentWindow::allButtons)
, processor(p)
{
    if(playfultones::UnityWrapper::pluginProcessor == nullptr)
        return;

    editor.reset(playfultones::UnityWrapper::pluginProcessor->createEditor());
    if(editor == nullptr)
        return;

    setContentOwned (editor.get(), true);
    setUsingNativeTitleBar (true);
    centreWithSize (600, 400);
    setResizable(true, true);
}

EditorWrapper::~EditorWrapper() = default;

void EditorWrapper::closeButtonPressed()
{
    onWindowClose();
}

juce::AudioProcessorEditor* EditorWrapper::getEditor() const
{
    return editor.get();
}

}