#include "Game/engine_lod_dynamic_startup.h"

typedef unsigned long u32;
extern "C" {
    extern const char lbl_802EC720[],lbl_802EC798[],lbl_802ED000[],lbl_802EC958[];
    extern char lbl_8028F698[];
    extern int lbl_80378048;
    void fn_8028FD50(void*,void*,int);
    void fn_80258948();
}
struct Handle_801F7F10 {
    u32 value;
    Handle_801F7F10();
    ~Handle_801F7F10();
};
struct LodStartupHandle1:Handle_801F7F10 {
    LodStartupHandle1(){
        value=0;
    }
    ~LodStartupHandle1(){
    }
};
struct LodStartupHandle2:LodStartupHandle1 {
    LodStartupHandle2(){
        value=0;
    }
    ~LodStartupHandle2(){
    }
};
struct LodStartupHandle3:LodStartupHandle2 {
    LodStartupHandle3(){
        value=0;
    }
    ~LodStartupHandle3(){
    }
};
// Same-layout views retain the full local-object destructor chain.
struct Object_8025F0D8 {
    u32 unknown[2];
    const void*vtable;
    char unknown0C[0x2C];
    unsigned long long flags;
    char unknown40[8];
    ~Object_8025F0D8();
};
struct LodStartupElement {
    u32 value;
    ~LodStartupElement(){
    }
};
struct LodStartupPool {
    int size,capacity;
    LodStartupElement*data;
    ~LodStartupPool(){
        if(data){
            for(int i=0;i<size;i++)data[i].~LodStartupElement();
            if(data){
                fn_8028FD50(lbl_8028F698,data,capacity*4);
                data=0;
            }
            data=0;
        }
    }
};
struct ContainerBase_802563CC:Object_8025F0D8 {
    LodStartupPool pool;
    int unknown54;
    LodStartupHandle2 handle58;
    char unknown5C[4];
    ContainerBase_802563CC();
    ~ContainerBase_802563CC(){
        vtable=lbl_802EC720;
    }
};
struct LodStartupResource:ContainerBase_802563CC {
    LodStartupResource(){
        vtable=lbl_802ED000;
    }
    ~LodStartupResource(){
        vtable=lbl_802ED000;
    }
};
struct CallbackPair_802EC798:LodStartupResource {
    LodStartupHandle2 handle60;
    LodStartupHandle3 handle64;
    int index68;
    CallbackPair_802EC798();
    ~CallbackPair_802EC798(){vtable=lbl_802EC798;}
};
struct LodDynamicAgent_802EC958:CallbackPair_802EC798 {
    LodDynamicAgent_802EC958(){vtable=lbl_802EC958;flags|=0x20ULL;flags&=~0x200ULL;}
    ~LodDynamicAgent_802EC958(){vtable=lbl_802EC958;}
};
typedef char LodStartupPairSizeCheck[(sizeof(CallbackPair_802EC798)==0x70)?1:-1];

extern "C" void fn_802599D0(){
    lbl_80378048=0;
    fn_80258948();
    LodDynamicAgent_802EC958 temporary;
}
