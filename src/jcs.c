#define JCS_IMPLEMENTATION
#include <jcs/jcs.h>


int main()
{
    JContext* jcs = jContextCreate(jMemoryDefault());


    if(!jContextDelete(jcs))
        return 1;

    return 0;
}