/*
 jcs_context.h
 Acts as the main container for all instances.

 Author: Mindrage (Ivan Roksandic)

 Change Log:
 2020-02-15: Created File for initial setup.

 */

#ifndef JCS_CONTEXT_H
#define JCS_CONTEXT_H

#include "jcs_def.h"
#include "jcs_memory.h"

typedef struct JContext {
    JMemory memory;
} JContext;

J_ATTR JContext *
J_CALL jContextCreate(JMemory memory);


J_ATTR JResult
J_CALL jContextDelete(JContext *context);


////////////////////////////////////////////////////////////////////////////
#ifdef JCS_IMPLEMENTATION // Required for Header - Only implementation    //
////////////////////////////////////////////////////////////////////////////

JContext*
jContextCreate(JMemory memory)
{
    // TODO: ADD null checks to all memory functions.

    JContext* jcs = memory.malloc(sizeof(JContext));

    if(!jcs) {
        return NULL;
    }

    jcs->memory = memory;

    return jcs;
}


JResult
jContextDelete(JContext* context) {
    // TODO: Add code for cleanup / deletion
    JMemory memory = context->memory;

    memory.free(context);

    if(context != NULL) {
        return J_ERROR;
    }

    return J_OK;
}


////////////////////////////////////////////////////////////////////////////
#endif // JCS_IMPLEMENTATION // Only needed header only implementation    //
////////////////////////////////////////////////////////////////////////////


#endif //JCS_JCS_CONTEXT_H
