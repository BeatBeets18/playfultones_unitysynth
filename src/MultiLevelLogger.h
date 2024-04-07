//
// Created by Bence Kovács on 07/04/2024.
//

#ifndef PLAYFULTONES_MULTILEVELLOGGER_H
#define PLAYFULTONES_MULTILEVELLOGGER_H

typedef void (*LogCallback)(const char*);

#ifdef __cplusplus
extern "C" {
#endif
/**
 * @brief Sets the logger callback. Call this method from the C# code to receive logger messages
 * from the native plugin.
 */
UNITY_INTERFACE_EXPORT void UNITY_INTERFACE_API setLogCallback(LogCallback callback);
/**
 * @brief Sets the error callback. Call this method from the C# code to receive error messages
 * from the native plugin.
 */
UNITY_INTERFACE_EXPORT void UNITY_INTERFACE_API setErrorCallback(LogCallback callback);
/**
 * @brief Sets the warning callback. Call this method from the C# code to receive warning messages
 * from the native plugin.
 */
UNITY_INTERFACE_EXPORT void UNITY_INTERFACE_API setWarningCallback(LogCallback callback);
#ifdef __cplusplus
}
#endif

namespace playfultones
{
    /**
     * A simple logger class that can print messages to the console output,
     * as well as to a managed callback in the C# code. This logger supports
     * different levels of messages such as errors, warnings, and general logs.
     */
    class MultiLevelLogger : public juce::Logger
    {
    public:
        MultiLevelLogger();
        ~MultiLevelLogger() override;

        void logMessage(const juce::String& message) override;
        static void logError(const juce::String& message);
        static void logWarning(const juce::String& message);

    private:
        static void writeToLogImpl(const juce::String& message, LogCallback callback);
    };

    namespace UnityWrapper {
        extern LogCallback logCallback;
        extern LogCallback errorLogCallback;
        extern LogCallback warningLogCallback;
    }
}

#endif // PLAYFULTONES_MULTILEVELLOGGER_H
