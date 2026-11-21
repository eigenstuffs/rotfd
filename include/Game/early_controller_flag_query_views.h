#ifndef GAME_EARLY_CONTROLLER_FLAG_QUERY_VIEWS_H
#define GAME_EARLY_CONTROLLER_FLAG_QUERY_VIEWS_H
struct ControlFlagObject;
struct ControlFlagHandle{union{unsigned long value;struct{signed int tag:8;signed int index:24;}bits;};};
struct ControlFlagEntry{ControlFlagObject*object;char unknown04[8];signed char tag;char unknown0D[3];};
struct ControlFlagManager{int count,capacity;ControlFlagEntry*entries;};
struct ControlFlagContext{char unknown00[0x118];ControlFlagManager*manager;};
extern "C" ControlFlagContext lbl_801E9D24;
struct ControlFlagObject{char unknown00[0x30];unsigned long long actorControlFlags;unsigned long long flags;char unknown40[0x30];ControlFlagHandle controller;};
inline ControlFlagObject*resolveControlFlag(const ControlFlagHandle&h){ControlFlagEntry*entry=&lbl_801E9D24.manager->entries[h.bits.index];if(entry->tag==h.bits.tag)return entry->object;return 0;}
inline signed char flagSet(unsigned long long flags,unsigned long long mask){if(flags&mask)return 1;return 0;}
extern "C" signed char fn_8007D604(void*,int);

#endif
