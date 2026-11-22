#include "Game/agent_classes.h"
// MediumAgent.h factory establishes the 0x200-byte opaque object storage.
extern "C" {
extern unsigned long lbl_80377718;
void fn_80062DB0();
void __ct__15Object_8006565CFv(void*);

void fn_80065620()
{
    unsigned long object[0x200 / 4];
    lbl_80377718 = 0;
    fn_80062DB0();
    __ct__15Object_8006565CFv(object);
    reinterpret_cast<CMediumAgent*>(object)->CMediumAgent::~CMediumAgent();
}
}
