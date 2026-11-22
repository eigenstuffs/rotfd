/* Part of the original LevelAgent.cpp: the CLevelAgent virtual members from
 * slot2C onward, with the vtable, RTTI records and adjustor thunks that the
 * compiler emits for the class.  The class hierarchy comes from the original
 * RTTI base lists; see include/Game/agent_classes.h.  The CLevelAgent members
 * that override CScriptAgent are inline, so they and their diagnostic strings
 * follow the RTTI data, in reverse slot order, as in the original. */
#include "Game/agent_classes.h"
typedef unsigned long u32;

/* Leading .rodata/.data/.sdata2 objects of this unit, ahead of the compiler's
 * RTTI data. */
extern "C" const char lbl_8029BA68[] = "CSimpleMove";
extern "C" const char lbl_8029BA74[] = "Anonymous New";
extern "C" const char lbl_8029BA84[] = "LevelAgent.cpp";
extern "C" {
struct NativeRuntimeTypeInfo;
extern NativeRuntimeTypeInfo lbl_803745B8; // CKarate
void fn_80061D18();
}
/* CKarate's single-slot vtable. */
extern "C" __declspec(section ".data") const void* const lbl_802B60F0[3] = {
    &lbl_803745B8, 0, (const void*)fn_80061D18
};
extern "C" const float lbl_803786D8 = 0.0f;
extern "C" __declspec(section ".sdata2") const char lbl_803786DC[] __attribute__((aligned(4))) = "CKarate";

struct Owner_80061AC0;
struct LevelAgentFields {char unknown00[0x1F8];Owner_80061AC0*owner;};
extern "C" {
    int fn_8025E70C(void*, void*, void*);
    extern void* lbl_80377700;
    extern void* lbl_80378028;
}

int CLevelAgent::slot2C(void* value) {
    int result;
    result = fn_8025E70C(this, value, lbl_80377700);
    if (result != -1) return result;
    result = fn_8025E70C(this, value, lbl_80378028);
    if (result != -1) return result;
    return -1;
}

struct Handle_801F7F10 {u32 word;Handle_801F7F10();~Handle_801F7F10();};
struct HandleEntry_80061AC0 {void*object;char pad[8];signed char tag;char tail[3];};
struct Manager_80061AC0 {char pad[8];HandleEntry_80061AC0*entries;};
struct Context_80061AC0 {char pad[0x110];void*logger;char*slots114;Manager_80061AC0*manager;};
extern "C" {extern Context_80061AC0 lbl_801E9D24;void fn_80024C00(Owner_80061AC0*);void fn_80024BCC(Owner_80061AC0*);void fn_801FA014(void*,const char*,...);void fn_801F86C8(Manager_80061AC0*,const Handle_801F7F10*,short);void fn_801EF610(void*,void*);extern char lbl_801EF5C8[];signed char fn_8025E9FC(void*,int);}
struct Handle_80021C40:Handle_801F7F10{Handle_80021C40(){word=0;}~Handle_80021C40(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80021BCC:Handle_80021C40{Handle_80021BCC(const Handle_801F7F10&v){word=v.word;fn_801F86C8(lbl_801E9D24.manager,&v,1);}~Handle_80021BCC(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct HandleOwnerView_80061AC0 {char unknown00[0x1F4];Handle_801F7F10 handle;};
struct Handle_80061AC0 {signed int tag:8;signed int index:24;};
static inline void*resolve(const Handle_80061AC0*h){HandleEntry_80061AC0*entry=&lbl_801E9D24.manager->entries[h->index];if(entry->tag==h->tag)return entry->object;return 0;}

inline void CLevelAgent::script14(){}
inline void*CLevelAgent::script18(){return resolve((const Handle_80061AC0*)((const char*)this+0x28));}
inline float CLevelAgent::script1C(){return *(const float*)((const char*)this+44);}
inline void*CLevelAgent::script20(){return (char*)this+444;}
inline signed char CLevelAgent::script24(int index){return fn_8025E9FC(this,index);}
inline void*CLevelAgent::script28(){return (char*)this+492;}
inline unsigned long CLevelAgent::GetHealth(){fn_801FA014(lbl_801E9D24.logger,"Warning:  Calling GetHealth on LVL_AGENT!");return -1;}
inline unsigned char CLevelAgent::GetWeaponType(){fn_801FA014(lbl_801E9D24.logger,"Warning:  Calling GetWeaponType on LVL_AGENT!");return 0;}
inline unsigned short CLevelAgent::GetWeaponDamage(){fn_801FA014(lbl_801E9D24.logger,"Warning:  Calling GetWeaponDamage on LVL_AGENT!");return 0;}
inline void CLevelAgent::script38(){}
inline void CLevelAgent::script3C(const Handle_801F7F10&value){HandleOwnerView_80061AC0*self=reinterpret_cast<HandleOwnerView_80061AC0*>(this);Handle_80021BCC h(value);fn_801F86C8(lbl_801E9D24.manager,&self->handle,-1);self->handle.word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}
inline void CLevelAgent::script40(int,int){}
inline void CLevelAgent::script44(int,void*){}
inline int CLevelAgent::script48(int){return 0;}
inline void CLevelAgent::SetHealth(unsigned long){fn_801FA014(lbl_801E9D24.logger,"Warning:  Calling SetHealth on LVL_AGENT!");}
inline void CLevelAgent::SetWeaponType(unsigned char){fn_801FA014(lbl_801E9D24.logger,"Warning:  Calling SetWeaponType on LVL_AGENT!");}
inline void CLevelAgent::SetWeaponDamage(unsigned short){fn_801FA014(lbl_801E9D24.logger,"Warning:  Calling SetWeaponDamage on LVL_AGENT!");}
inline void CLevelAgent::script58(){}
inline void CLevelAgent::script5C(){fn_80024BCC(reinterpret_cast<LevelAgentFields*>(this)->owner);}
inline void CLevelAgent::script60(){Owner_80061AC0*owner=reinterpret_cast<LevelAgentFields*>(this)->owner;if(owner)fn_80024C00(owner);}

typedef char CheckPrimarySize[(sizeof(Agent_Z)==0x60)?1:-1];
typedef char CheckSecondarySize[(sizeof(CScriptAgent)==0x160)?1:-1];
