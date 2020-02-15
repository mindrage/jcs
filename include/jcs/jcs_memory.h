/*
 jcs_memory.h
 Used as a memory allocator wrapper.

 Author: Mindrage (Ivan Roksandic)

 Change Log:
 2020-02-15: Created File for initial setup.

 */

#ifndef JCS_MEMORY_H
#define JCS_MEMORY_H

#include "jcs_def.h"


#ifdef __cplusplus
#extern "C"
{
#endif

typedef void (J_PTR *jMemoryFree)(void* ptr);

typedef void* (J_PTR *jMemoryAllocate)(usize size);

typedef void* (J_PTR* jMemoryAllocateArray)(usize count, usize size);

typedef void* (J_PTR *jMemoryReallocate)(void* ptr, usize size);

typedef void* (J_PTR *jMemoryCopy)(void* to, const void* from, usize size);

typedef void* (J_PTR *jMemoryMove)(void* to, const void* from, usize size);

typedef void* (J_PTR *jMemorySet)(void* ptr, int value, usize size);

typedef int (J_PTR *jMemoryCompare)(const void* first, const void* second, usize size);



typedef struct JMemory {
    jMemoryFree free;
    jMemoryAllocate malloc;
    jMemoryAllocateArray calloc;
    jMemoryReallocate realloc;
    jMemoryCopy memcpy;
    jMemoryMove memmove;
    jMemorySet memset;
    jMemoryCompare memcmp;
} JMemory;


#ifdef JCS_IMPLEMENTATION

#include <stdlib.h>
#include <string.h>

J_ATTR JMemory
J_CALL jMemoryDefault() {
    JMemory memory;

    memory.free = (jMemoryFree) free;
    memory.malloc = (jMemoryAllocate) malloc;
    memory.calloc = (jMemoryAllocateArray) calloc;
    memory.realloc = (jMemoryReallocate) realloc;
    memory.memcpy = (jMemoryCopy) memcpy;
    memory.memmove = (jMemoryMove) memmove;
    memory.memset = (jMemorySet) memset;
    memory.memcmp = (jMemoryCompare) memcmp;

    return memory;
}
#endif


#ifdef __cplusplus
} // extern "C"
#endif // __cplusplus


#endif //JCS_MEMORY_H
