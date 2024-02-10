#ifndef ROVER_PYTHON_DLL_EXPORTS
#define ROVER_PYTHON_DLL_EXPORTS

#ifdef _MSC_VER
  #define ROVER_EXTERN
  #if defined(ROVER_BUILD_DLL)
    #define ROVER_EXPORT_DLL __declspec(dllexport)
  #elif defined(ROVER_USE_DLL)
    #define ROVER_EXPORT_DLL __declspec(dllimport)
  #else
    #define ROVER_EXPORT_DLL
  #endif
#else
  #if defined(ROVER_BUILD_DLL) || defined(ROVER_USE_DLL)
    #define ROVER_EXTERN extern
    #define ROVER_EXPORT_DLL __attribute__((visibility ("default")))
  #else
    #define ROVER_EXTERN
    #define ROVER_EXPORT_DLL
  #endif
#endif

#endif
