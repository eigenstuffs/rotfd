/* Part of the original CActorScriptAgent source: the virtual members from
 * slot160 onward, with the vtable, RTTI records and adjustor thunks that the
 * compiler emits for the class (key function: slot2C).  The members that
 * override CScriptAgent are inline, so they follow the non-inline members in
 * reverse slot order, as in the original.  The class hierarchy comes from the
 * original RTTI base lists; see include/Game/agent_classes.h. */
#include "Game/agent_classes.h"

/* Leading .rodata/.sdata2 objects of this unit, ahead of the compiler's RTTI data. */
extern "C" const char lbl_8029BBE8[] = "ObjectsBreak";
extern "C" const float lbl_80378718 = 10.0f;
extern "C" __declspec(section ".sdata2") const char lbl_8037871C[] __attribute__((aligned(4))) = "PFX_BAM";
extern "C" __declspec(section ".sdata2") const char lbl_80378724[] __attribute__((aligned(4))) = "PFX_POW";

typedef unsigned long u32;
struct MemberPointer{u32 a,b,c;};
struct Callback{char opaque00[0x28];unsigned short flags28;short index2A;};
extern "C" {extern const struct Pool{char opaque00[0xC];MemberPointer entries[5];}lbl_802B6270;extern u32 lbl_8037808C,lbl_80378090;extern int lbl_80378094;void fn_8025EF34(void*,MemberPointer,int);void fn_8025EEB4(void*,MemberPointer);void fn_8025EB70(void*,MemberPointer);Callback*fn_8025F074(void*,MemberPointer);void fn_8025F658(Callback*,int);void fn_8025F694(Callback*,u32);void fn_8025F620(Callback*,u32);}

extern "C" {signed char fn_8025E9FC(void*,int);void fn_80286058(void*,int);void fn_8025E8F8(void*);void fn_80021724(void*);}
struct Prefix{u32 unknown00,unknown04;};
struct Object:Prefix{virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1C();virtual void slot20();virtual void slot24();virtual void slot28();virtual void slot2C();virtual void slot30();virtual void slot34();};
int CActorScriptAgent::slot160(int event,void*callbackArgument){
Callback*callback=static_cast<Callback*>(callbackArgument);
const Pool*members=&lbl_802B6270;int result=1;
switch(event){
case 0:fn_8025EF34(this,members->entries[0],-1);return 1;
case 1:fn_8025EEB4(this,members->entries[1]);return 1;
case 2:fn_8025EB70(this,members->entries[2]);return 1;
case 3:if(callback)return(signed char)((callback->flags28>>2)&1);callback=fn_8025F074(this,members->entries[3]);if(callback)return(signed char)((callback->flags28>>2)&1);return 0;
case 4:if(callback)return(signed char)(callback->flags28&1);callback=fn_8025F074(this,members->entries[4]);if(callback)return(signed char)(callback->flags28&1);return 0;
case 5:return 1;
case 6:if(callback)return callback->index2A;return -9999;
}
lbl_8037808C=0;lbl_80378090=0;lbl_80378094=-1;
if(event==11&&callback->index2A==-1)return 1;
fn_8025F658(callback,0);
int action;if(event>=14)action=event+callback->index2A*2;else action=event;
switch(action){case 7:fn_8025F694(callback,lbl_8037808C);case 8:break;case 14:result=0;if(fn_8025E9FC(this,0x51)||fn_8025E9FC(this,0x52))result=1;result=(unsigned char)result;break;case 15:reinterpret_cast<Object*>(this)->slot34();break;default:result=2;break;}
fn_8025F620(callback,lbl_80378090);return result;
}


extern "C" {
    void fn_8025ED38(void*, void*, void*);
    int fn_8025E70C(void*, void*, void*);
    extern void* lbl_803775D0;
    extern void* lbl_80377708;
    extern void* lbl_80378028;
    extern void* lbl_80378030;
    extern void* lbl_80378040;
    extern void* lbl_80378050;
    extern void* lbl_80378060;
    extern void* lbl_80378080;
}

unsigned long CActorScriptAgent::slot20() { return (unsigned long)lbl_80377708; }

void CActorScriptAgent::slot24(unsigned long value) { lbl_80377708 = (void*)value; }

void CActorScriptAgent::slot28(void* value) {
    fn_8025ED38(this, value, lbl_80377708);
    fn_8025ED38(this, value, lbl_803775D0);
    fn_8025ED38(this, value, lbl_80378040);
    fn_8025ED38(this, value, lbl_80378060);
    fn_8025ED38(this, value, lbl_80378050);
    fn_8025ED38(this, value, lbl_80378030);
    fn_8025ED38(this, value, lbl_80378080);
    fn_8025ED38(this, value, lbl_80378028);
}

int CActorScriptAgent::slot2C(void* value) {
    int result;
    result = fn_8025E70C(this, value, lbl_80377708);
    if (result != -1) return result;
    result = fn_8025E70C(this, value, lbl_803775D0);
    if (result != -1) return result;
    result = fn_8025E70C(this, value, lbl_80378040);
    if (result != -1) return result;
    result = fn_8025E70C(this, value, lbl_80378060);
    if (result != -1) return result;
    result = fn_8025E70C(this, value, lbl_80378050);
    if (result != -1) return result;
    result = fn_8025E70C(this, value, lbl_80378030);
    if (result != -1) return result;
    result = fn_8025E70C(this, value, lbl_80378080);
    if (result != -1) return result;
    result = fn_8025E70C(this, value, lbl_80378028);
    if (result != -1) return result;
    return -1;
}

struct Handle_80062E18 {signed int tag:8;signed int index:24;};
struct HandleEntry_80062E18 {void*object;char pad[8];signed char tag;char tail[3];};
struct Manager_80062E18 {char pad[8];HandleEntry_80062E18*entries;};
struct Context_80062E18 {char pad[0x118];Manager_80062E18*manager;};
extern "C" Context_80062E18 lbl_801E9D24;
static inline void*resolve(const Handle_80062E18*h){HandleEntry_80062E18*entry=&lbl_801E9D24.manager->entries[h->index];if(entry->tag==h->tag)return entry->object;return 0;}
struct ActorScriptAgentFields {char unknown00[0x28];Handle_80062E18 actor28;float scalar2C;char unknown30[0x84-0x30];unsigned long value84;unsigned char value88;char unknown89;unsigned short value8A;};
static inline ActorScriptAgentFields*fields(CActorScriptAgent*self){return reinterpret_cast<ActorScriptAgentFields*>(self);}
extern "C" {int fn_8007D6A0(void*,int);void fn_8025795C(void*,int,void*);void fn_80257828(void*,int,int,int);void fn_8025A3C8(void*,const Handle_801F7F10&);void*fn_8025E50C(void*);}
inline void CActorScriptAgent::script14(){}
inline void*CActorScriptAgent::script18(){return resolve(&fields(this)->actor28);}
inline float CActorScriptAgent::script1C(){return fields(this)->scalar2C;}
inline void*CActorScriptAgent::script20(){return fn_8025E50C(this);}
inline signed char CActorScriptAgent::script24(int index){return fn_8025E9FC(this,index);}
inline unsigned long CActorScriptAgent::GetHealth(){return fields(this)->value84;}
inline unsigned char CActorScriptAgent::GetWeaponType(){return fields(this)->value88;}
inline unsigned short CActorScriptAgent::GetWeaponDamage(){return fields(this)->value8A;}
inline void CActorScriptAgent::script38(){slot68();}
inline void CActorScriptAgent::script3C(const Handle_801F7F10&value){fn_8025A3C8(this,value);}
inline void CActorScriptAgent::script40(int first,int second){fn_80257828(this,first,second,0);}
inline void CActorScriptAgent::script44(int index,void*argument){fn_8025795C(this,index,argument);}
inline int CActorScriptAgent::script48(int index){return fn_8007D6A0((char*)resolve(static_cast<const Handle_80062E18*>(script28()))+0x318,index);}
inline void CActorScriptAgent::SetHealth(unsigned long value){fields(this)->value84=value;}
inline void CActorScriptAgent::SetWeaponType(unsigned char value){fields(this)->value88=value;}
inline void CActorScriptAgent::SetWeaponDamage(unsigned short value){fields(this)->value8A=value;}
