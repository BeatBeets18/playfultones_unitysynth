//
// Created by Bence Kovács on 07/04/2024.
//

#include "MultiLevelLogger.h"

UNITY_INTERFACE_EXPORT void UNITY_INTERFACE_API setLogCallback(LogCallback callback)
{
    playfultones::UnityWrapper::logCallback = callback;
}

UNITY_INTERFACE_EXPORT void UNITY_INTERFACE_API setErrorCallback(LogCallback callback)
{
    playfultones::UnityWrapper::errorLogCallback = callback;
}

UNITY_INTERFACE_EXPORT void UNITY_INTERFACE_API setWarningCallback(LogCallback callback)
{
    playfultones::UnityWrapper::warningLogCallback = callback;
}

namespace playfultones {

MultiLevelLogger::MultiLevelLogger() = default;

MultiLevelLogger::~MultiLevelLogger() = default;

void MultiLevelLogger::logMessage(const juce::String& message)
{
    writeToLogImpl(message, UnityWrapper::logCallback);
}

void MultiLevelLogger::logError(const juce::String& message)
{
    writeToLogImpl(message, UnityWrapper::errorLogCallback);
}

void MultiLevelLogger::logWarning(const juce::String& message)
{
    writeToLogImpl(message, UnityWrapper::warningLogCallback);
}

void MultiLevelLogger::writeToLogImpl(const juce::String& message, LogCallback callback)
{
    if (callback != nullptr)
        callback(message.toRawUTF8());

    juce::Logger::outputDebugString(message);
}

namespace UnityWrapper
{
    LogCallback logCallback = nullptr;
    LogCallback errorLogCallback = nullptr;
    LogCallback warningLogCallback = nullptr;
}

}