#include "Game/engine_single_callback_startup.h"

typedef unsigned long u32;
extern "C" {
    extern const char lbl_802EC720[],lbl_802EC798[],lbl_802ED000[],lbl_802ECA18[];
    extern char lbl_8028F698[];
    extern int lbl_80378050;
    void fn_8028FD50(void*,void*,int);
    void fn_80258948();
}
struct Handle_801F7F10 {
    u32 value;
    Handle_801F7F10();
    ~Handle_801F7F10();
};
struct SingleStartupHandle1:Handle_801F7F10 {
    SingleStartupHandle1(){
        value=0;
    }
    ~SingleStartupHandle1(){
    }
};
struct SingleStartupHandle2:SingleStartupHandle1 {
    SingleStartupHandle2(){
        value=0;
    }
    ~SingleStartupHandle2(){
    }
};
struct SingleStartupHandle3:SingleStartupHandle2 {
    SingleStartupHandle3(){
        value=0;
    }
    ~SingleStartupHandle3(){
    }
};
// Partial layout views preserve the native construction and unused backup chain.
struct Object_8025F0D8 {
    u32 unknown[2];
    const void*vtable;
    char unknown0C[0x2C];
    unsigned long long flags;
    char unknown40[8];
    ~Object_8025F0D8();
};
struct SingleStartupElement {
    u32 value;
    ~SingleStartupElement(){
    }
};
struct SingleStartupPool {
    int size,capacity;
    SingleStartupElement*data;
    ~SingleStartupPool(){
        if(data){
            for(int i=0;i<size;i++)data[i].~SingleStartupElement();
            if(data){
                fn_8028FD50(lbl_8028F698,data,capacity*4);
                data=0;
            }
            data=0;
        }
    }
};
struct ContainerBase_802563CC:Object_8025F0D8 {
    SingleStartupPool pool;
    int unknown54;
    SingleStartupHandle2 handle58;
    char unknown5C[4];
    ContainerBase_802563CC();
    ~ContainerBase_802563CC(){
        vtable=lbl_802EC720;
    }
};
struct SingleStartupResource:ContainerBase_802563CC {
    SingleStartupResource(){
        vtable=lbl_802ED000;
    }
    ~SingleStartupResource(){
        vtable=lbl_802ED000;
    }
};
struct CallbackPair_802EC798:SingleStartupResource {
    SingleStartupHandle2 handle60;
    SingleStartupHandle3 handle64;
    int index68;
    CallbackPair_802EC798();
    ~CallbackPair_802EC798(){vtable=lbl_802EC798;}
};
// The empty vtable layer leaves the member receiver live through construction.
struct SingleStartupVtable {
    SingleStartupVtable(CallbackPair_802EC798* owner) {
        owner->vtable = lbl_802ECA18;
    }
};
// The existing external destructor consumes this common prefix with flag -1.
struct Object_80021064:CallbackPair_802EC798,SingleStartupVtable {
    SingleStartupHandle3 handle70;
    Object_80021064():SingleStartupVtable(this) { flags |= 1ULL; }
    ~Object_80021064();
};
typedef char SingleStartupPairSize[(sizeof(CallbackPair_802EC798)==0x70)?1:-1];
typedef char SingleStartupObjectSize[(sizeof(Object_80021064)==0x78)?1:-1];
struct MemberPointer{long adjustment,offset;void*function;};
extern "C"{extern const MemberPointer lbl_802EC9D0;void fn_8025E714(void*,const MemberPointer&);}
extern "C" void fn_8025A930() {
    lbl_80378050 = 0;
    fn_80258948();
    Object_80021064 temporary;
    MemberPointer callback = lbl_802EC9D0;
    fn_8025E714(&temporary, callback);
}
