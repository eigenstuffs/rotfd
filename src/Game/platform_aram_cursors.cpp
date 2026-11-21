#include "Game/platform_aram_internal.h"
extern "C" {
unsigned long ARGetBaseAddress();
extern char lbl_801E9D24[];
extern const char lbl_802AF3E8[];
void fn_801FA014(void*,const char*,...);
unsigned long fn_80285784(PlatformAramOwner* self,unsigned long size) {
    unsigned long result=self->cursor04;
    self->cursor04=result+((size+31)&~31UL);
    if(self->cursor04>=ARGetBaseAddress()+0xBB8000)
        fn_801FA014(*reinterpret_cast<void**>(lbl_801E9D24+0x110),lbl_802AF3E8);
    return result;
}
unsigned long fn_80285800(PlatformAramOwner* self,unsigned long size) {
    unsigned long result=self->cursor00;
    self->cursor00=result+((size+31)&~31UL);
    return result;
}
}
