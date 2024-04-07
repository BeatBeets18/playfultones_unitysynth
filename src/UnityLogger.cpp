//
// Created by Bence Kovács on 07/04/2024.
//

UNITY_INTERFACE_EXPORT void UNITY_INTERFACE_API setLogCallback(LogCallback callback){
    playfultones::UnityWrapper::log_callback = callback;
}

namespace playfultones
{
    UnityLogger::UnityLogger (bool shouldWriteToConsole)
    : writeToConsole(shouldWriteToConsole)
    {
    }

    UnityLogger::~UnityLogger() = default;

    void UnityLogger::logMessage (const juce::String& message)
    {
        if (playfultones::UnityWrapper::log_callback != nullptr)
            playfultones::UnityWrapper::log_callback(message.toRawUTF8());

        if(! writeToConsole)
            return;

        juce::Logger::outputDebugString(message);
    }

    namespace UnityWrapper
    {
        LogCallback log_callback = nullptr;
    }
}