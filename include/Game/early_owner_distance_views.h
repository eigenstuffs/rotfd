#ifndef GAME_EARLY_OWNER_DISTANCE_VIEWS_H
#define GAME_EARLY_OWNER_DISTANCE_VIEWS_H
struct EarlyOwnerResource;
struct EarlyOwnerHandle{union{unsigned long value;struct{signed int tag:8;signed int index:24;}bits;};};
struct EarlyOwnerEntry{EarlyOwnerResource*object;char unknown04[8];signed char tag;char unknown0D[3];};
struct EarlyOwnerManager{int count,capacity;EarlyOwnerEntry*entries;};
struct EarlyOwnerSubsystem{char unknown00[0x15058];void*distance;};
struct EarlyOwnerContext{char unknown00[0x118];EarlyOwnerManager*manager;char unknown11C[8];EarlyOwnerSubsystem*subsystem;};
extern "C" EarlyOwnerContext lbl_801E9D24;
struct EarlyOwnerResource{char unknown00[0x58];EarlyOwnerHandle owner;};
inline EarlyOwnerResource*resolveEarlyOwner(const EarlyOwnerHandle&handle){EarlyOwnerEntry*entry=&lbl_801E9D24.manager->entries[handle.bits.index];if(entry->tag==handle.bits.tag)return entry->object;return 0;}
extern "C" {float fn_80058350(void*,EarlyOwnerResource*,EarlyOwnerResource*);extern const float lbl_803786A4;}
#endif
