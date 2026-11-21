#ifndef GAME_EARLY_OWNER_POINTER_FLAG_VIEWS_H
#define GAME_EARLY_OWNER_POINTER_FLAG_VIEWS_H
// Observed storage and virtual interfaces; no table identities are emitted.
struct PointerOwner;
struct PointerHandle{union{unsigned long value;struct{signed int tag:8;signed int index:24;}bits;};};
struct PointerEntry{PointerOwner*object;char unknown04[8];signed char tag;char unknown0D[3];};
struct PointerManager{int count,capacity;PointerEntry*entries;};
struct PointerContext{char unknown00[0x118];PointerManager*manager;};
extern "C" PointerContext lbl_801E9D24;
struct PointerOwner{unsigned long id;char unknown04[0x2C];unsigned long long actorFlags,flags;char unknown40[0x18];PointerHandle owner;char unknown5C[0x19C];void*registration;char unknown1FC[0x194];signed char selected;char unknown391[0x33];PointerOwner*selection;char unknown3C8[0xA];signed char available;};
inline PointerOwner*resolvePointer(const PointerHandle&h){PointerEntry*entry=&lbl_801E9D24.manager->entries[h.bits.index];if(entry->tag==h.bits.tag)return entry->object;return 0;}
struct PointerPrefix{char unknown00[4];};
struct PointerQuery:PointerPrefix{virtual void slot0();virtual void slot1();virtual void slot2();virtual PointerOwner*getResource();virtual void slot4();virtual void slot5();virtual void slot6();virtual void slot7();virtual const PointerHandle*getHandle();};
extern "C"{extern PointerQuery*lbl_803776B8;extern const char lbl_8029C79C[];PointerOwner*fn_80024960(void*);PointerOwner*fn_8005E9A0();unsigned long fn_801F948C(void*,const char*);}
struct PointerName{unsigned long value;PointerName(const char*text){value=fn_801F948C(this,text);}};

struct PointerMainPrefix{char unknown00[8];};
struct PointerMain:PointerMainPrefix{
virtual void mainSlot0();
virtual void mainSlot1();
virtual void mainSlot2();
virtual void mainSlot3();
virtual void mainSlot4();
virtual void mainSlot5();
virtual void mainSlot6();
virtual void mainSlot7();
virtual void mainSlot8();
virtual void mainSlot9();
virtual void mainSlot10();
virtual void mainSlot11();
virtual void mainSlot12();
virtual void mainSlot13();
virtual void mainSlot14();
virtual void mainSlot15();
virtual void mainSlot16();
virtual void mainSlot17();
virtual void mainSlot18();
virtual void mainSlot19();
virtual void mainSlot20();
virtual void mainSlot21();
virtual void mainSlot22();
virtual void mainSlot23();
virtual void mainSlot24();
virtual void mainSlot25();
virtual void mainSlot26();
virtual void mainSlot27();
virtual void mainSlot28();
virtual void mainSlot29();
virtual void mainSlot30();
virtual void mainSlot31();
virtual void mainSlot32();
virtual void mainSlot33();
virtual void mainSlot34();
virtual void mainSlot35();
virtual void mainSlot36();
virtual void mainSlot37();
virtual void mainSlot38();
virtual void mainSlot39();
virtual void mainSlot40();
virtual void mainSlot41();
virtual void mainSlot42();
virtual void mainSlot43();
virtual void mainSlot44();
virtual void mainSlot45();
virtual void mainSlot46();
virtual void mainSlot47();
virtual void mainSlot48();
virtual void mainSlot49();
virtual void mainSlot50();
virtual void mainSlot51();
virtual void mainSlot52();
virtual void mainSlot53();
virtual void mainSlot54();
virtual void mainSlot55();
virtual void mainSlot56();
virtual void mainSlot57();
virtual void mainSlot58();
virtual void mainSlot59();
virtual void mainSlot60();
virtual void mainSlot61();
virtual void mainSlot62();
virtual void mainSlot63();
virtual void mainSlot64();
virtual void mainSlot65();
virtual void mainSlot66();
virtual void mainSlot67();
virtual void mainSlot68();
char unknown0C[0x84];};
struct PointerComposite:PointerMain,PointerQuery{};
extern "C" {signed char fn_8009FD38(PointerOwner*);void fn_8006B470(PointerQuery*,PointerOwner*,int);}

#endif
