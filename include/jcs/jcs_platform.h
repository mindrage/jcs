/*
 jcs_platform.h
 Defines standard types based on platforms.

 Change Log:
 2020-02-15: Added platforms based on vk_platform.h

 */

#ifndef JCS_PLATFORM_H_
#define JCS_PLATFORM_H_

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

#include <stddef.h>

#if defined(_WIN32)
// On Windows, Vulkan commands use the stdcall convention
    #define J_ATTR
    #define J_CALL __stdcall
    #define J_PTR  J_CALL
#elif defined(__ANDROID__) && defined(__ARM_ARCH) && __ARM_ARCH >= 7 && defined(__ARM_32BIT_STATE)
    #define J_ATTR __attribute__((pcs("aapcs-vfp")))
    #define J_CALL
    #define J_PTR  J_ATTR
#else
    // On other platforms, use the default calling convention
    #define J_ATTR
    #define J_CALL
    #define J_PTR
#endif

#include <stddef.h>

#if !defined(J_NO_STDINT_H)
    #if defined(_MSC_VER) && (_MSC_VER < 1600)
        typedef signed   __int8  int8_t;
        typedef unsigned __int8  uint8_t;
        typedef signed   __int16 int16_t;
        typedef unsigned __int16 uint16_t;
        typedef signed   __int32 int32_t;
        typedef unsigned __int32 uint32_t;
        typedef signed   __int64 int64_t;
        typedef unsigned __int64 uint64_t;
    #else
        #include <stdint.h>
    #endif
#endif // !defined(VK_NO_STDINT_H)

#ifdef __cplusplus
} // extern "C"
#endif // __cplusplus


#endif