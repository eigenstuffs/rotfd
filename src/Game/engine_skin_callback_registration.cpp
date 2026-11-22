#include "Game/skin_member_protocol.h"
struct SkinActionVtable {const void*typeInfo;long thisOffset;void(*slots[29])();};
extern "C" SkinActionVtable lbl_802ECAF8;

typedef unsigned long u32;
extern "C" {
    extern const char lbl_802EC720[],lbl_802EC798[],lbl_802ED000[];
    extern char lbl_8028F698[];
    extern int lbl_80378058;
    void fn_8028FD50(void*,void*,int);
    void fn_80258948();
}
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
extern "C" void fn_8025E714(void*,const SkinActionMemberPointer&);
struct SkinAgent_802ECAF8:CallbackPair_802EC798 {
    SkinAgent_802ECAF8(){vtable=&lbl_802ECAF8;flags|=2ULL;flags&=~0x200ULL;}
    ~SkinAgent_802ECAF8(){vtable=&lbl_802ECAF8;}
};
typedef char SkinStartupPairSizeCheck[(sizeof(CallbackPair_802EC798)==0x70)?1:-1];

extern "C" void fn_8025B158(){
    lbl_80378058=0;
    fn_80258948();
    SkinAgent_802ECAF8 temporary;
    SkinActionMemberPointer callback=&SkinCallbackPMFView::slot78;
    fn_8025E714(&temporary,callback);
}

extern "C" int fn_8025ACF0(SkinActionOwner* self, int event, SkinActionCallback* callback) {
    int result = 1;
    switch (event) {
    case 0:
        fn_8025EF34(self, &SkinCallbackPMFView::slot78, -1);
        return 1;
    case 1:
        fn_8025EEB4(self, &SkinCallbackPMFView::slot78);
        return 1;
    case 2:
        fn_8025EB70(self, &SkinCallbackPMFView::slot78);
        return 1;
    case 3:
        if (callback)
            return (signed char)((callback->flags28 >> 2) & 1);
        callback = fn_8025F074(self, &SkinCallbackPMFView::slot78);
        if (callback)
            return (signed char)((callback->flags28 >> 2) & 1);
        return 0;
    case 4:
        if (callback)
            return (signed char)(callback->flags28 & 1);
        callback = fn_8025F074(self, &SkinCallbackPMFView::slot78);
        if (callback)
            return (signed char)(callback->flags28 & 1);
        return 0;
    case 5:
        return 1;
    case 6:
        if (callback)
            return callback->index2A;
        return -9999;
    }

    lbl_8037808C = 0;
    lbl_80378090 = 0;
    lbl_80378094 = -1;
    if (event == 8 || event == 7)
        fn_8025F4F4(callback, 0, lbl_802AEBF0);
    if (event == 11 && callback->index2A == -1)
        return 1;
    fn_8025F658(callback, lbl_80378090);
    int action;
    if (event >= 14)
        action = event + callback->index2A * 2;
    else
        action = event;
    switch (action) {
    case 7:
        fn_8025F694(callback,lbl_8037808C);
    case 8:
        break;
    case 11: {
        int ready=0;
        if(fn_8025E9FC(self,0x40)&&!fn_8025E9FC(self,0x3F))ready=1;
        result=ready;
        break;
    }
    case 12:
        fn_8023297C(resolve(lbl_801E9D24.manager,self->target64),&fn_80257B70(self,0),0,1);
        break;
    case 14:
        result=fn_8025E9FC(self,0x3F);
        break;
    case 15: {
        fn_802601C8(lbl_801E9D24.actions,self,0x40);
        SkinActionCopyHandle target(fn_80257B70(self,5));
        fn_8023297C(resolve(lbl_801E9D24.manager,self->target64),&target,0,1);
        fn_802073BC(self,0x40,self,resolve(lbl_801E9D24.manager,target)->value30,lbl_8037B520);
        break;
    }
    default:
        result=2;
        break;
    }
    fn_8025F620(callback, lbl_80378090);
    return result;
}
// Complete physical vtable view; original external identities are retained.
typedef void (*SkinActionVirtualSlot)();
extern "C" {
void __dt__23CallbackTailOwnerSecondFv();
void slot0C__12BaseObject_ZFUl();
void slot10__12BaseObject_ZFv();
void slot14__12BaseObject_ZFv();
void fn_8025885C();
void fn_80257C78();
void fn_8025A9E0();
void fn_8025A9E8();
void fn_8025A9F0();
void fn_8025AA5C();
void fn_802573E4();
void fn_80257338();
void fn_80258654();
void fn_80257FF0();
void fn_80257E04();
void fn_80257D20();
void slot48__7Agent_ZFv();
void slot4C__7Agent_ZFv();
void slot50__7Agent_ZFv();
void slot54__7Agent_ZFv();
void slot58__7Agent_ZFv();
void slot5C__7Agent_ZFv();
void slot60__7Agent_ZFv();
void slot64__15AnimatedAgent_ZFv();
void slot68__15AnimatedAgent_ZFv();
void slot6C__7Agent_ZFv();
void slot70__7Agent_ZFv();
void slot74__15AnimatedAgent_ZFv();
SkinActionVtable lbl_802ECAF8 = {0,0,{
    (SkinActionVirtualSlot)__dt__23CallbackTailOwnerSecondFv,
    (SkinActionVirtualSlot)slot0C__12BaseObject_ZFUl,
    (SkinActionVirtualSlot)slot10__12BaseObject_ZFv,
    (SkinActionVirtualSlot)slot14__12BaseObject_ZFv,
    (SkinActionVirtualSlot)fn_8025885C,
    (SkinActionVirtualSlot)fn_80257C78,
    (SkinActionVirtualSlot)fn_8025A9E0,
    (SkinActionVirtualSlot)fn_8025A9E8,
    (SkinActionVirtualSlot)fn_8025A9F0,
    (SkinActionVirtualSlot)fn_8025AA5C,
    (SkinActionVirtualSlot)fn_802573E4,
    (SkinActionVirtualSlot)fn_80257338,
    (SkinActionVirtualSlot)fn_80258654,
    (SkinActionVirtualSlot)fn_80257FF0,
    (SkinActionVirtualSlot)fn_80257E04,
    (SkinActionVirtualSlot)fn_80257D20,
    (SkinActionVirtualSlot)slot48__7Agent_ZFv,
    (SkinActionVirtualSlot)slot4C__7Agent_ZFv,
    (SkinActionVirtualSlot)slot50__7Agent_ZFv,
    (SkinActionVirtualSlot)slot54__7Agent_ZFv,
    (SkinActionVirtualSlot)slot58__7Agent_ZFv,
    (SkinActionVirtualSlot)slot5C__7Agent_ZFv,
    (SkinActionVirtualSlot)slot60__7Agent_ZFv,
    (SkinActionVirtualSlot)slot64__15AnimatedAgent_ZFv,
    (SkinActionVirtualSlot)slot68__15AnimatedAgent_ZFv,
    (SkinActionVirtualSlot)slot6C__7Agent_ZFv,
    (SkinActionVirtualSlot)slot70__7Agent_ZFv,
    (SkinActionVirtualSlot)slot74__15AnimatedAgent_ZFv,
    (SkinActionVirtualSlot)fn_8025ACF0
}};
}
typedef char SkinActionVtableSize[sizeof(SkinActionVtable)==124?1:-1];

