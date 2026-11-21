#ifndef GAME_ENGINE_CALLBACK_SKIN_ACTION_H
#define GAME_ENGINE_CALLBACK_SKIN_ACTION_H
typedef unsigned long SkinActionWord;
struct SkinActionMemberPointer { SkinActionWord adjustment,tableOffset,function; };
struct SkinActionCallback {char unknown00[0x28];unsigned short flags28;short index2A;};
struct Handle_801F7F10 {
    union {unsigned long value;struct {signed int tag:8,index:24;}bits;};
    Handle_801F7F10();
    ~Handle_801F7F10();
};
struct SkinActionOwner {char unknown00[0x64];Handle_801F7F10 target64;};
struct SkinActionTarget {char unknown00[0x30];float value30;};
struct SkinActionEntry {SkinActionTarget*object;SkinActionWord unknown04,unknown08;signed char generation;char unknown0D[3];};
struct SkinActionManager {int count,capacity;SkinActionEntry*entries;};
struct SkinActionGlobals {char unknown00[0x118];SkinActionManager*manager;char unknown11C[8];void*actions;};
extern "C" void __dt__15Handle_801F7F10Fv(void*,int);
extern "C" void __ct__15Handle_801F7F10Fv(void*);
struct SkinActionReturnedHandle {unsigned long value;SkinActionReturnedHandle(){__ct__15Handle_801F7F10Fv(this);}~SkinActionReturnedHandle(){__dt__15Handle_801F7F10Fv(this,0);}};
extern "C" {
extern SkinActionGlobals lbl_801E9D24;
extern SkinActionWord lbl_8037808C,lbl_80378090;
extern int lbl_80378094;
extern float lbl_8037B520;
extern const char lbl_802AEBF0[];
void fn_8025EF34(void*,SkinActionMemberPointer,int);
void fn_8025EEB4(void*,SkinActionMemberPointer);
void fn_8025EB70(void*,SkinActionMemberPointer);
SkinActionCallback*fn_8025F074(void*,SkinActionMemberPointer);
void fn_8025F4F4(SkinActionCallback*,int,const char*);
void fn_8025F658(SkinActionCallback*,int);
void fn_8025F694(SkinActionCallback*,SkinActionWord);
void fn_8025F620(SkinActionCallback*,SkinActionWord);
signed char fn_8025E9FC(void*,int);
SkinActionReturnedHandle fn_80257B70(SkinActionOwner*,int);
void fn_801F86C8(SkinActionManager*,const Handle_801F7F10*,short);
void fn_8023297C(SkinActionTarget*,const void*,int,unsigned char);
void fn_802601C8(void*,SkinActionOwner*,int);
void fn_802073BC(SkinActionOwner*,int,SkinActionOwner*,float,float);
int fn_8025ACF0(SkinActionOwner*,int,SkinActionCallback*);
}
struct SkinActionZeroHandle:Handle_801F7F10 {SkinActionZeroHandle(){value=0;}};
struct SkinActionCopyHandle:SkinActionZeroHandle {
    SkinActionCopyHandle(const SkinActionReturnedHandle&h){value=h.value;fn_801F86C8(lbl_801E9D24.manager,(const Handle_801F7F10*)&h,1);}
};
static inline SkinActionTarget*resolve(SkinActionManager*m,const Handle_801F7F10&h){SkinActionEntry*e=&m->entries[h.bits.index];return e->generation==h.bits.tag?e->object:0;}
#endif
