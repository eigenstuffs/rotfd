#ifndef GAME_EARLY_OWNER_STATE_RESET_VIEWS_H
#define GAME_EARLY_OWNER_STATE_RESET_VIEWS_H
struct ResetResource;
struct ResetHandle{union{unsigned long value;struct{signed int tag:8;signed int index:24;}bits;};};
struct ResetEntry{ResetResource*object;char unknown04[8];signed char tag;char unknown0D[3];};
struct ResetManager{int count,capacity;ResetEntry*entries;};
struct ResetContext{char unknown00[0x118];ResetManager*manager;};
extern "C" ResetContext lbl_801E9D24;
inline ResetResource*resolveReset(const ResetHandle&h){ResetEntry*entry=&lbl_801E9D24.manager->entries[h.bits.index];if(entry->tag==h.bits.tag)return entry->object;return 0;}
struct ResetResourcePrefix{char unknown00[8];};
struct ResetResource:ResetResourcePrefix{
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
char unknown0C[0x2C];unsigned long long flags;char unknown40[0x18];ResetHandle owner;
};
struct ResetPrefix{char unknown00[4];};
struct ResetObject:ResetPrefix{virtual void slot0();virtual void slot1();virtual void slot2();virtual ResetResource*getResource();};
extern "C" {void fn_80069CA8(ResetObject*,ResetResource*,int);void fn_8025E8E0(ResetResource*);void fn_8025ECB4(ResetResource*);}

#endif
