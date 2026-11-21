#ifndef GAME_ENGINE_OWNER_KEY_LOOKUP_H
#define GAME_ENGINE_OWNER_KEY_LOOKUP_H

typedef unsigned long u32;
struct Handle_801F7F10 {
 union { u32 value; struct { signed int tag:8; signed int index:24; } bits; };
 Handle_801F7F10(); ~Handle_801F7F10();
};
struct LookupHandle1 : Handle_801F7F10 { LookupHandle1(){value=0;} };
struct LookupHandle2 : LookupHandle1 { LookupHandle2(){value=0;} };
struct LookupHandle3 : LookupHandle2 { LookupHandle3(){value=0;} };
struct LookupHandle4 : LookupHandle3 { LookupHandle4(){value=0;} };
struct LookupHandle5 : LookupHandle4 { LookupHandle5(){value=0;} };
struct LookupObjectStorage { char unknown00[8]; };
struct LookupObject : LookupObjectStorage {
 virtual void slot08();
 virtual void slot0C();
 virtual void slot10();
 virtual void slot14();
 virtual void slot18();
 virtual void slot1C();
 virtual void slot20();
 virtual void slot24();
 virtual void slot28();
 virtual void slot2C();
 virtual void slot30();
 virtual void slot34();
 virtual void slot38();
 virtual void slot3C();
 virtual void slot40();
 virtual void slot44();
 virtual void slot48();
 virtual void slot4C();
 virtual void slot50();
 virtual void slot54();
 virtual void slot58();
 virtual void slot5C();
 virtual void slot60();
 virtual void slot64();
 virtual void slot68();
 virtual void slot6C();
 virtual void slot70();
 virtual void slot74();
 virtual void slot78();
 virtual void slot7C();
 virtual void slot80();
 virtual void slot84();
 virtual void slot88();
 virtual void slot8C();
 virtual void slot90();
 virtual void slot94();
 virtual void slot98();
 virtual void slot9C();
 virtual int key();
 Handle_801F7F10 related;
 char unknown10[0x98-0x10];
 Handle_801F7F10* second;
 char unknown9C[8];
 Handle_801F7F10* first;
 char unknownA8[8];
 char* handlesBytes;
 char unknownB4[0xDC-0xB4];
 int count;
};
struct LookupEntry { LookupObject* object; u32 key; int unused08; signed char tag; char unknown0D[3]; };
struct LookupManager { int count,capacity;LookupEntry* entries; };
struct LookupContext {char unknown00[0x118];LookupManager* manager;};
struct LookupOwner {char unknown00[0x14];int count,capacity;char* handlesBytes;};
extern "C" {
 extern LookupContext lbl_801E9D24;
 void fn_801F86C8(LookupManager*,const Handle_801F7F10*,short);
 u32 fn_801F7EB8(const Handle_801F7F10*);
 int fn_801FE6BC(LookupOwner*,int,Handle_801F7F10*,Handle_801F7F10*,Handle_801F7F10*);
}
typedef char CheckLookupHandleSize[sizeof(LookupHandle5)==4?1:-1];
typedef char CheckLookupObjectSize[sizeof(LookupObject)==0xE0?1:-1];
typedef char CheckLookupOwnerSize[sizeof(LookupOwner)==0x20?1:-1];
#endif
