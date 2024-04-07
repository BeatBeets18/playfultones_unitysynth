//
// Created by Bence Kovács on 07/04/2024.
//

#ifndef PLAYFULTONES_UNITYLOGGER_H
#define PLAYFULTONES_UNITYLOGGER_H

typedef void (*LogCallback)(const char*);

#ifdef __cplusplus
extern "C" {
#endif
/**
 * @brief Sets the logger callback. Call this method from the C# code to receive logger messages
 * from the native plugin.
 */
UNITY_INTERFACE_EXPORT void UNITY_INTERFACE_API setLogCallback(LogCallback callback);
#ifdef __cplusplus
}
#endif


namespace playfultones
{
    namespace UnityWrapper {
        /**
         * The callback instance in the C# code that should be invoked when a new message is logged.
         */
        extern LogCallback log_callback;
    }

    /**
     * @brief A simple logger class that can print messages to the console output,
     * as well as to a managed callback in the C# code.
     */
    class UnityLogger : public juce::Logger
    {
    public:
        explicit UnityLogger(bool shouldWriteToConsole = true);
        ~UnityLogger() override;
        void logMessage(const juce::String& message) override;
    private:
        const bool writeToConsole = false;
        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(UnityLogger)
    };
}

#endif //PLAYFULTONES_UNITYLOGGER_H
