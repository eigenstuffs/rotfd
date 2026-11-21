#include "Game/engine_skin_callback_startup.h"

typedef unsigned long u32;
extern "C" {
    extern const char lbl_802EC720[],lbl_802EC798[],lbl_802ED000[],lbl_802ECAF8[];
    extern char lbl_8028F698[];
    extern int lbl_80378058;
    void fn_8028FD50(void*,void*,int);
    void fn_80258948();
}
struct Handle_801F7F10 {
    u32 value;
    Handle_801F7F10();
    ~Handle_801F7F10();
};
struct SkinStartupHandle1:Handle_801F7F10 {
    SkinStartupHandle1(){
        value=0;
    }
    ~SkinStartupHandle1(){
    }
};
struct SkinStartupHandle2:SkinStartupHandle1 {
    SkinStartupHandle2(){
        value=0;
    }
    ~SkinStartupHandle2(){
    }
};
struct SkinStartupHandle3:SkinStartupHandle2 {
    SkinStartupHandle3(){
        value=0;
    }
    ~SkinStartupHandle3(){
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
struct SkinStartupElement {
    u32 value;
    ~SkinStartupElement(){
    }
};
struct SkinStartupPool {
    int size,capacity;
    SkinStartupElement*data;
    ~SkinStartupPool(){
        if(data){
            for(int i=0;i<size;i++)data[i].~SkinStartupElement();
            if(data){
                fn_8028FD50(lbl_8028F698,data,capacity*4);
                data=0;
            }
            data=0;
        }
    }
};
struct ContainerBase_802563CC:Object_8025F0D8 {
    SkinStartupPool pool;
    int unknown54;
    SkinStartupHandle2 handle58;
    char unknown5C[4];
    ContainerBase_802563CC();
    ~ContainerBase_802563CC(){
        vtable=lbl_802EC720;
    }
};
struct SkinStartupResource:ContainerBase_802563CC {
    SkinStartupResource(){
        vtable=lbl_802ED000;
    }
    ~SkinStartupResource(){
        vtable=lbl_802ED000;
    }
};
struct CallbackPair_802EC798:SkinStartupResource {
    SkinStartupHandle2 handle60;
    SkinStartupHandle3 handle64;
    int index68;
    CallbackPair_802EC798();
    ~CallbackPair_802EC798(){vtable=lbl_802EC798;}
};
struct MemberPointer{long adjustment,offset;void*function;};
extern "C" {extern const MemberPointer lbl_802ECAB0;void fn_8025E714(void*,const MemberPointer&);}
struct SkinAgent_802ECAF8:CallbackPair_802EC798 {
    SkinAgent_802ECAF8(){vtable=lbl_802ECAF8;flags|=2ULL;flags&=~0x200ULL;}
    ~SkinAgent_802ECAF8(){vtable=lbl_802ECAF8;}
};
typedef char SkinStartupPairSizeCheck[(sizeof(CallbackPair_802EC798)==0x70)?1:-1];

extern "C" void fn_8025B158(){
    lbl_80378058=0;
    fn_80258948();
    SkinAgent_802ECAF8 temporary;
    MemberPointer callback=lbl_802ECAB0;
    fn_8025E714(&temporary,callback);
}
