#include "Game/platform_aram_internal.h"
extern "C" {extern PlatformAramBytePool lbl_8035DE34;}
static inline void releaseRequest(PlatformAramSlot* base,PlatformAramRequest* request){
    for(int i=0;i<64;++i) {
        if(request==&base[i].request) {
            base[i].occupied=0;
            return;
        }
    }
}
extern "C" void fn_80285A6C(unsigned long address) {
    PlatformAramRequest* request=reinterpret_cast<PlatformAramRequest*>(address);
    int index=request->owner;
    lbl_8035DE34.release(index);
    releaseRequest(lbl_8035D528,request);
}
