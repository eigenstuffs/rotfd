/* Six event selectors and their registration lifetime.  The declared storage
 * views expose only the native prefix and handle used by this source fragment.
 * Existing object constructor/destructor entry points remain native providers.
 * Source order and deferred inlining preserve the compiler's local PMF pool. */
#include "Game/engine_late_callback_selectors.h"
extern "C" const char lbl_802AEB5C[];
#include "Game/late_screen_virtual_table.h"
extern "C" {
extern unsigned long lbl_80378018;
extern char lbl_801EF5C8[];
void fn_801EF610(void *,void *);
void fn_8025E714(void *,const LateMemberPointer &);
}
struct Handle_801F7F10 {unsigned long value;Handle_801F7F10();~Handle_801F7F10();static void operator delete(void *p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80020478:Handle_801F7F10{Handle_80020478(){value=0;}~Handle_80020478(){}};
struct Handle_80021BCC:Handle_80020478{Handle_80021BCC(){value=0;}~Handle_80021BCC(){}};
struct Handle_800B92F0:Handle_80021BCC{Handle_800B92F0(){value=0;}~Handle_800B92F0(){}};
extern "C" void *__ct__15Object_8025F0D8Fv(void *);
extern "C" void *__dt__15Object_8025F0D8Fv(void *,int);
struct NativeScreenObjectStorage {
 unsigned long prefix[2]; const void *vtable; char opaque0C[0x3C];
 NativeScreenObjectStorage(){__ct__15Object_8025F0D8Fv(this);vtable=&__vt__19ScreenBase_800B9368;}
 ~NativeScreenObjectStorage(){__dt__15Object_8025F0D8Fv(this,0);}
};
struct NativeScreenRegistrationStorage:NativeScreenObjectStorage {
 Handle_800B92F0 handle; unsigned long unknown4C;
 NativeScreenRegistrationStorage(){}
 ~NativeScreenRegistrationStorage(){vtable=&__vt__19ScreenBase_800B9368;}
};
inline void addScreenMember(void *self,LateMemberPointer member){fn_8025E714(self,member);}
extern "C" void fn_802548B8(void *){
 lbl_80378018=0;
 NativeScreenRegistrationStorage screen;
 addScreenMember(&screen,&LateSelectorOwner::slot38);
 addScreenMember(&screen,&LateSelectorOwner::slot3C);
 addScreenMember(&screen,&LateSelectorOwner::slot40);
 addScreenMember(&screen,&LateSelectorOwner::slot44);
 addScreenMember(&screen,&LateSelectorOwner::slot48);
 addScreenMember(&screen,&LateSelectorOwner::slot4C);
}
extern "C" int fn_802545FC(LateSelectorOwner* self, int event, LateCallback* callback) {
    int result = 1;
    switch (event) {
    case 0:
        fn_8025EF34(self, &LateSelectorOwner::slot38, -1);
        return 1;
    case 1:
        fn_8025EEB4(self, &LateSelectorOwner::slot38);
        return 1;
    case 2:
        fn_8025EB70(self, &LateSelectorOwner::slot38);
        return 1;
    case 3:
        if (callback)
            return (signed char)((callback->flags28 >> 2) & 1);
        callback = fn_8025F074(self, &LateSelectorOwner::slot38);
        if (callback)
            return (signed char)((callback->flags28 >> 2) & 1);
        return 0;
    case 4:
        if (callback)
            return (signed char)(callback->flags28 & 1);
        callback = fn_8025F074(self, &LateSelectorOwner::slot38);
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
        fn_8025F4F4(callback, 4, lbl_802AEB5C);
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
        fn_8025F694(callback, lbl_8037808C);
    case 8:
        break;
    case 14:
        result = fn_8025E9FC(self, 0x4B);
        break;
    case 15:
        self->slot54();
        break;
    default:
        result = 2;
        break;
    }
    fn_8025F620(callback, lbl_80378090);
    return result;
}

extern "C" int fn_80254340(LateSelectorOwner* self, int event, LateCallback* callback) {
    int result = 1;
    switch (event) {
    case 0:
        fn_8025EF34(self, &LateSelectorOwner::slot3C, -1);
        return 1;
    case 1:
        fn_8025EEB4(self, &LateSelectorOwner::slot3C);
        return 1;
    case 2:
        fn_8025EB70(self, &LateSelectorOwner::slot3C);
        return 1;
    case 3:
        if (callback)
            return (signed char)((callback->flags28 >> 2) & 1);
        callback = fn_8025F074(self, &LateSelectorOwner::slot3C);
        if (callback)
            return (signed char)((callback->flags28 >> 2) & 1);
        return 0;
    case 4:
        if (callback)
            return (signed char)(callback->flags28 & 1);
        callback = fn_8025F074(self, &LateSelectorOwner::slot3C);
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
        fn_8025F4F4(callback, 4, lbl_802AEB5C);
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
        fn_8025F694(callback, lbl_8037808C);
    case 8:
        break;
    case 14:
        result = fn_8025E9FC(self, 0x4C);
        break;
    case 15:
        self->slot58();
        break;
    default:
        result = 2;
        break;
    }
    fn_8025F620(callback, lbl_80378090);
    return result;
}

extern "C" int fn_80254084(LateSelectorOwner* self, int event, LateCallback* callback) {
    int result = 1;
    switch (event) {
    case 0:
        fn_8025EF34(self, &LateSelectorOwner::slot40, -1);
        return 1;
    case 1:
        fn_8025EEB4(self, &LateSelectorOwner::slot40);
        return 1;
    case 2:
        fn_8025EB70(self, &LateSelectorOwner::slot40);
        return 1;
    case 3:
        if (callback)
            return (signed char)((callback->flags28 >> 2) & 1);
        callback = fn_8025F074(self, &LateSelectorOwner::slot40);
        if (callback)
            return (signed char)((callback->flags28 >> 2) & 1);
        return 0;
    case 4:
        if (callback)
            return (signed char)(callback->flags28 & 1);
        callback = fn_8025F074(self, &LateSelectorOwner::slot40);
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
        fn_8025F4F4(callback, 4, lbl_802AEB5C);
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
        fn_8025F694(callback, lbl_8037808C);
    case 8:
        break;
    case 14:
        result = fn_8025E9FC(self, 0x4E);
        break;
    case 15:
        self->slot5C();
        break;
    default:
        result = 2;
        break;
    }
    fn_8025F620(callback, lbl_80378090);
    return result;
}

extern "C" int fn_80253DC8(LateSelectorOwner* self, int event, LateCallback* callback) {
    int result = 1;
    switch (event) {
    case 0:
        fn_8025EF34(self, &LateSelectorOwner::slot44, -1);
        return 1;
    case 1:
        fn_8025EEB4(self, &LateSelectorOwner::slot44);
        return 1;
    case 2:
        fn_8025EB70(self, &LateSelectorOwner::slot44);
        return 1;
    case 3:
        if (callback)
            return (signed char)((callback->flags28 >> 2) & 1);
        callback = fn_8025F074(self, &LateSelectorOwner::slot44);
        if (callback)
            return (signed char)((callback->flags28 >> 2) & 1);
        return 0;
    case 4:
        if (callback)
            return (signed char)(callback->flags28 & 1);
        callback = fn_8025F074(self, &LateSelectorOwner::slot44);
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
        fn_8025F4F4(callback, 4, lbl_802AEB5C);
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
        fn_8025F694(callback, lbl_8037808C);
    case 8:
        break;
    case 14:
        result = fn_8025E9FC(self, 0x4D);
        break;
    case 15:
        self->slot60();
        break;
    default:
        result = 2;
        break;
    }
    fn_8025F620(callback, lbl_80378090);
    return result;
}

extern "C" int fn_80253B0C(LateSelectorOwner* self, int event, LateCallback* callback) {
    int result = 1;
    switch (event) {
    case 0:
        fn_8025EF34(self, &LateSelectorOwner::slot48, -1);
        return 1;
    case 1:
        fn_8025EEB4(self, &LateSelectorOwner::slot48);
        return 1;
    case 2:
        fn_8025EB70(self, &LateSelectorOwner::slot48);
        return 1;
    case 3:
        if (callback)
            return (signed char)((callback->flags28 >> 2) & 1);
        callback = fn_8025F074(self, &LateSelectorOwner::slot48);
        if (callback)
            return (signed char)((callback->flags28 >> 2) & 1);
        return 0;
    case 4:
        if (callback)
            return (signed char)(callback->flags28 & 1);
        callback = fn_8025F074(self, &LateSelectorOwner::slot48);
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
        fn_8025F4F4(callback, 4, lbl_802AEB5C);
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
        fn_8025F694(callback, lbl_8037808C);
    case 8:
        break;
    case 14:
        result = fn_8025E9FC(self, 0x4F);
        break;
    case 15:
        self->slot64();
        break;
    default:
        result = 2;
        break;
    }
    fn_8025F620(callback, lbl_80378090);
    return result;
}

extern "C" int fn_80253850(LateSelectorOwner* self, int event, LateCallback* callback) {
    int result = 1;
    switch (event) {
    case 0:
        fn_8025EF34(self, &LateSelectorOwner::slot4C, -1);
        return 1;
    case 1:
        fn_8025EEB4(self, &LateSelectorOwner::slot4C);
        return 1;
    case 2:
        fn_8025EB70(self, &LateSelectorOwner::slot4C);
        return 1;
    case 3:
        if (callback)
            return (signed char)((callback->flags28 >> 2) & 1);
        callback = fn_8025F074(self, &LateSelectorOwner::slot4C);
        if (callback)
            return (signed char)((callback->flags28 >> 2) & 1);
        return 0;
    case 4:
        if (callback)
            return (signed char)(callback->flags28 & 1);
        callback = fn_8025F074(self, &LateSelectorOwner::slot4C);
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
        fn_8025F4F4(callback, 4, lbl_802AEB5C);
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
        fn_8025F694(callback, lbl_8037808C);
    case 8:
        break;
    case 14:
        result = fn_8025E9FC(self, 0x50);
        break;
    case 15:
        self->slot68();
        break;
    default:
        result = 2;
        break;
    }
    fn_8025F620(callback, lbl_80378090);
    return result;
}


extern "C" {
NativeScreenTable __vt__19ScreenBase_800B9368={0,0,__dt__19ScreenBase_800B9368Fv,slot0C__12BaseObject_ZFUl,slot10__12BaseObject_ZFv,slot14__12BaseObject_ZFv,slot18__12BaseObject_ZFv,fn_802537A8,fn_8025347C,fn_80253484,fn_8025348C,fn_802534B0,fn_80035224,fn_80035228,{fn_802545FC,fn_80254340,fn_80254084,fn_80253DC8,fn_80253B0C,fn_80253850},fn_802534E8,fn_802535D8,fn_800C07D0,fn_802534EC,fn_800C07D4,fn_80253584,fn_80253540};
}

typedef char CheckScreenObjectStorage[sizeof(NativeScreenObjectStorage)==0x48?1:-1];
typedef char CheckScreenRegistrationStorage[sizeof(NativeScreenRegistrationStorage)==0x50?1:-1];
typedef char CheckScreenVirtualTable[sizeof(NativeScreenTable)==0x6C?1:-1];
typedef char CheckScreenMemberPointer[sizeof(LateMemberPointer)==12?1:-1];
