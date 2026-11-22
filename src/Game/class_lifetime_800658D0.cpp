#include "Game/agent_classes.h"
// SimpleAgent.h factory establishes the 0x200-byte opaque object storage.
extern "C" {
extern unsigned long lbl_80377720;
void fn_80062DB0();
void __ct__15Object_8006590CFv(void*);

void fn_800658D0()
{
    unsigned long object[0x200 / 4];
    lbl_80377720 = 0;
    fn_80062DB0();
    __ct__15Object_8006590CFv(object);
    reinterpret_cast<CSimpleAgent*>(object)->CSimpleAgent::~CSimpleAgent();
}
}
