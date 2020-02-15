/*
 jcs_def.h
 Include general definition for all files.

 Author: Mindrage (Ivan R)

 Change Log:
 2020-02-15: Added definitions for types.

 */

#ifndef JCS_DEF_H_
#define JCS_DEF_H_

#ifdef __cplusplus
#extern "C"
{
#endif

#include "jcs_platform.h"

typedef uint8_t  u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef float f32;
typedef double f64;

typedef size_t usize;
typedef size_t isize;

typedef u8 JFlags8;
typedef u16 JFlags16;
typedef u32 JFlags32;
typedef u64 JFlags64;


typedef enum JBool {
    J_TRUE = 1,
    J_FALSE = 0
} JBool;

typedef enum JType {
    J_U8 = 0x01,
    J_U16 = 0x02,
    J_U32 = 0x03,
    J_U64 = 0x04,
    J_I8 = 0x05,
    J_I16 = 0x06,
    J_I32 = 0x07,
    J_I64 = 0x08,
    J_SIZE = 0x09,
    J_USIZE = 0x0A,
    J_F32 = 0x0B,
    J_F64 = 0x0C,
    J_VOID = 0x0D
} JType;

typedef enum JTypeFlagBits {
    J_CONST = 0x01,
    J_REF = 0x01,
    J_UNIQUE = 0x02,
} JTypeFlagBits;

typedef u8 JTypeFlags;

typedef enum JGroup {
    J_STRUCT = 0x01,
    J_UNION = 0x02,
    J_TUPLE = 0x03,
    J_GENERIC = 0x04,
    J_ENUM = 0x08
} JGroup;


typedef enum JResult {
    J_OK = 0,
    J_WARNING = 1,
    J_ERROR = -1
} JResult;

typedef enum JBlockFlagBits {
    // Determined a new scope for local variables
    J_BLOCK_SCOPE = 0x01,
    // Determines if a block is yieldable.
    J_BLOCK_YIELD = 0x02,
    // Makes the block repeating by calling another block that is yieldable example a range(1, 3, 0);
    J_BLOCK_ITERATE = 0x04,
    // Makes the entire block act as a match/switch/if/else block, jump based on conditions.
    J_BLOCK_BRANCH = 0x08,
    // Assmumes that the content of the block cannot have upvalues, aka if its a Closure or async block.
    J_BLOCK_ISOLATE = 0x10,
    // Assumes that the block has input parameters.
    J_BLOCK_PARAMS = 0x20,
    // Assumes a block to be a function or something.
    J_BLOCK_CALLABLE = 0x40
} JBlockFlagBits;

typedef JFlags8 JBlockFlags;


#ifdef __cplusplus
} // extern "C"
#endif

#endif