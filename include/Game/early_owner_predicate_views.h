#ifndef GAME_EARLY_OWNER_PREDICATE_VIEWS_H
#define GAME_EARLY_OWNER_PREDICATE_VIEWS_H
struct PredicateResource;
struct PredicateHandle{union{unsigned long value;struct{signed int tag:8;signed int index:24;}bits;};};
struct PredicateEntry{PredicateResource*object;char unknown04[8];signed char tag;char unknown0D[3];};
struct PredicateManager{int count,capacity;PredicateEntry*entries;};
struct PredicateContext{char unknown00[0x118];PredicateManager*manager;};
extern "C" PredicateContext lbl_801E9D24;
inline PredicateResource*resolvePredicate(const PredicateHandle&handle){PredicateEntry*entry=&lbl_801E9D24.manager->entries[handle.bits.index];if(entry->tag==handle.bits.tag)return entry->object;return 0;}
struct PredicatePrefix{char unknown00[8];};
struct PredicateResource:PredicatePrefix{
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
virtual void slot31();
virtual void slot32();
virtual void slot33();
virtual void slot34();
virtual void slot35();
virtual void slot36();
virtual const PredicateHandle*getHandle(int);
char unknown0C[0x2C];unsigned long long flags;char unknown40[0x18];PredicateHandle owner;char unknown5C[0x14];PredicateHandle controller;char unknown74[0x138];PredicateHandle selected;
};
extern "C" {PredicateResource*fn_8005E90C();unsigned long fn_801F7EB8(const PredicateHandle*);signed char fn_800665D8(PredicateResource*,int);signed char fn_8007D604(void*,int);}
#endif
