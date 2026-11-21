#include "Game/platform_aram_internal.h"
extern "C" {
unsigned long ARInit(unsigned long*,unsigned long);
void ARQInit();
unsigned long ARGetBaseAddress();
void ARStartDMA(unsigned long,unsigned long,unsigned long,unsigned long);
void ARQFlushQueue();
extern char lbl_801EF5C8[],lbl_801E9D24[];
extern const char lbl_802AF3E8[];
void* fn_801EFA1C(void*,unsigned long,const char*,const char*,int,unsigned long);
void fn_801EF610(void*,void*);
void fn_801FA014(void*,const char*,...);
void* memset(void*,int,unsigned long);
void fn_8028581C(PlatformAramOwner* self) {
    const char* messages=lbl_802AF3E8;
    ARInit(0,0);
    ARQInit();
    for(int i=0;i<64;++i)lbl_8035DE58[i].occupied=0;
    self->cursor00=ARGetBaseAddress();
    self->cursor04=ARGetBaseAddress();
    void* buffer=fn_801EFA1C(lbl_801EF5C8,4096,messages+0x34,messages+0x44,107,32);
    memset(buffer,0,4096);
    ARStartDMA(0,reinterpret_cast<unsigned long>(buffer),self->cursor00,4096);
    ARQFlushQueue();
    fn_801EF610(lbl_801EF5C8,buffer);
    self->cursor00+=0xBB8000;
    self->cursor04+=0x8000;
    fn_801FA014(*reinterpret_cast<void**>(lbl_801E9D24+0x110),messages+0x50);
}
}
