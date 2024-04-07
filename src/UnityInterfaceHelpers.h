#if JUCE_MSVC
    #ifndef UNITY_INTERFACE_API
        #define UNITY_INTERFACE_API __stdcall
    #endif
    #ifndef UNITY_INTERFACE_EXPORT
        #define UNITY_INTERFACE_EXPORT __declspec(dllexport)
    #endif
#else
    #ifndef UNITY_INTERFACE_API
        #define UNITY_INTERFACE_API
    #endif
    #ifndef UNITY_INTERFACE_EXPORT
        #define UNITY_INTERFACE_EXPORT __attribute__ ((visibility ("default")))
    #endif
#endif