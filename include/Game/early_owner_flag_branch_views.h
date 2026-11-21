#ifndef GAME_EARLY_OWNER_FLAG_BRANCH_VIEWS_H
#define GAME_EARLY_OWNER_FLAG_BRANCH_VIEWS_H

struct FlagObject;
struct FlagHandle{union{unsigned long value;struct{signed int tag:8;signed int index:24;}bits;};};
struct FlagEntry{FlagObject*object;char unknown04[8];signed char tag;char unknown0D[3];};
struct FlagManager{int count,capacity;FlagEntry*entries;};
struct FlagContext{char unknown00[0x118];FlagManager*manager;};
extern "C" FlagContext lbl_801E9D24;
struct FlagObject{char unknown00[0x30];unsigned long long actorFlags;unsigned long long flags;char unknown40[0x30];FlagHandle controller;};
inline FlagObject*resolveFlag(const FlagHandle&h){FlagEntry*entry=&lbl_801E9D24.manager->entries[h.bits.index];if(entry->tag==h.bits.tag)return entry->object;return 0;}
inline signed char flagSet(unsigned long long flags,unsigned long long mask){if(flags&mask)return 1;return 0;}
extern "C" FlagObject*fn_8005E90C();

#endif
