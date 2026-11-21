#include "Game/platform_aram_internal.h"
extern "C" {
extern PlatformAramBytePool lbl_8035DE34;
int fn_80285458(PlatformAramBytePool*,unsigned char);
void fn_80285A6C(unsigned long);
void ARQPostRequest(PlatformAramRequest*,unsigned long,unsigned long,unsigned long,unsigned long,unsigned long,unsigned long,void(*)(unsigned long));
}
static inline PlatformAramSlot* acquireRequest() {
    for(int i=0;i<64;++i) {
        if(!lbl_8035D528[i].occupied) {
            lbl_8035D528[i].occupied=1;
            return &lbl_8035D528[i];
        }
    }
    return 0;
}
extern "C" void fn_8028533C(void*,unsigned long source,unsigned long dest,unsigned long length,signed char asynchronous) {
    PlatformAramSlot* slot=acquireRequest();
    int index=fn_80285458(&lbl_8035DE34,1);
    ARQPostRequest(&slot->request,0,0,1,source,dest,length&~7UL,fn_80285A6C);
    if(!asynchronous) { while((signed char)lbl_8035DE34.isOccupied(index)){} }
}
