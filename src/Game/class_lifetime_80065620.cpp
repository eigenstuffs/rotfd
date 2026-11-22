#include "Game/agent_cleanup_virtual_view_8006565C.h"
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
    reinterpret_cast<ObjectCleanupVirtualView_8006565C*>(object)->ObjectCleanupVirtualView_8006565C::cleanup(-1);
}
}
