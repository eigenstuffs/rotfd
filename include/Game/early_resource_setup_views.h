#ifndef GAME_EARLY_RESOURCE_SETUP_VIEWS_H
#define GAME_EARLY_RESOURCE_SETUP_VIEWS_H
struct Handle_801F7F10{union{unsigned long value;struct{signed int tag:8;signed int index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct SetupObject;
struct SetupEntry{SetupObject*object;char unknown04[8];signed char tag;char unknown0D[3];};
struct SetupManager{int count,capacity;SetupEntry*entries;};
struct SetupContext{char unknown00[0x118];SetupManager*manager;};
extern "C" SetupContext lbl_801E9D24;
extern "C" {void fn_801F86C8(SetupManager*,const Handle_801F7F10*,int);unsigned long fn_801F7EB8(const Handle_801F7F10*);void fn_802139D8(SetupObject*);void fn_80213A18(SetupObject*);void fn_801EF610(void*,void*);extern char lbl_801EF5C8[];}
struct Handle_80021C40:Handle_801F7F10{Handle_80021C40(){value=0;}~Handle_80021C40(){};static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80021BCC:Handle_80021C40{Handle_80021BCC(){value=0;}Handle_80021BCC(const Handle_801F7F10&h){value=h.value;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_80021BCC(){};static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80021B54:Handle_80021BCC{Handle_80021B54(const Handle_801F7F10&h){value=h.value;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_80021B54(){};static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
inline signed char validSetup(const Handle_801F7F10&h){return fn_801F7EB8(&h)!=0;}
inline SetupObject*resolveSetup(const Handle_801F7F10&h){SetupEntry*entry=&lbl_801E9D24.manager->entries[h.bits.index];if(entry->tag==h.bits.tag)return entry->object;return 0;}
struct SetupPrefix{char unknown00[8];};
struct SetupObject:SetupPrefix{
virtual void slot0();
virtual void slot1();
virtual void slot2();
virtual void slot3();
virtual void slot4();
virtual void slot5();
virtual void slot6();
virtual void slot7();
virtual void slot8();
virtual void slot9();
virtual void slot10();
virtual void slot11();
virtual void slot12();
virtual void slot13();
virtual void slot14();
virtual void slot15();
virtual void slot16();
virtual void slot17();
virtual void slot18();
virtual void slot19();
virtual void slot20();
virtual void slot21();
virtual void slot22();
virtual void slot23();
virtual void slot24();
virtual void slot25();
virtual void slot26();
virtual void slot27();
virtual void slot28();
virtual void slot29();
virtual void slot30();
virtual void ownerBind(const Handle_801F7F10&);
virtual void slot32();
virtual void slot33();
virtual void slot34();
virtual void slot35();
virtual void slot36();
virtual void slot37();
virtual void slot38();
virtual void slot39();
virtual void slot40();
virtual void slot41();
virtual void slot42();
virtual void slot43();
virtual void slot44();
virtual void slot45();
virtual void slot46();
virtual void slot47();
virtual void slot48();
virtual void slot49();
virtual void slot50();
virtual void slot51();
virtual void clearA(int,int);
virtual void clearB(int,int);
char unknown0C[0x24];unsigned long long actorFlags,flags;char unknown40[0x18];Handle_801F7F10 owner;char unknown5C[4];char script[0x190];char unknown1F0[4];Handle_801F7F10 resource;void*callback;};

extern "C" {Handle_801F7F10 fn_801B52EC(SetupManager*,const char*);void fn_8005E66C(void*);void fn_802001D4(SetupObject*,const Handle_80021B54&,int);void*fn_801EFA1C(void*,unsigned long,const char*,const char*,int,int);extern const char lbl_8029BA68[],lbl_8029BA74[],lbl_8029BA84[];extern char lbl_802B60F0[];extern const float lbl_803786D8;}
inline void assignSetup(Handle_801F7F10&d,const Handle_801F7F10&s){fn_801F86C8(lbl_801E9D24.manager,&d,-1);d.value=s.value;fn_801F86C8(lbl_801E9D24.manager,&s,1);}
struct SetupCallback{void*vtable;signed char exclusive;char unknown05[3];float duration;signed char flagsC,flagsD,flagsE;char unknown0F;void*items[30];};

inline void clearSetupFlags(const Handle_80021B54&h){resolveSetup(h)->actorFlags&=~0x200ULL;}

inline void initializeSetupCallback(SetupCallback*callback){callback->vtable=lbl_802B60F0;callback->exclusive=0;callback->duration=lbl_803786D8;callback->flagsC=0;callback->flagsD=0;callback->flagsE=0;for(unsigned char i=0;i<30;++i)callback->items[i]=0;}
#endif
