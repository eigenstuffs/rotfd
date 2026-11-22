#include "Game/agent_classes.h"
// ComplexAgent.h factory establishes the 0x200-byte opaque object storage.
extern "C" {
extern unsigned long lbl_80377728;
void fn_80062DB0();
void __ct__15Object_80065C60Fv(void*);

void fn_80065C24()
{
    unsigned long object[0x200 / 4];
    lbl_80377728 = 0;
    fn_80062DB0();
    __ct__15Object_80065C60Fv(object);
    reinterpret_cast<CComplexAgent*>(object)->CComplexAgent::~CComplexAgent();
}
}
