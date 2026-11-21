#ifndef GAME_OWNER_RESOURCE_CALLBACK_VIEWS_H
#define GAME_OWNER_RESOURCE_CALLBACK_VIEWS_H
struct OwnerCallbackHandle {union {unsigned long value;struct{signed int tag:8;signed int index:24;}bits;};};
struct OwnerCallbackResource {char unknown00[0x38];unsigned long long flags;};
struct OwnerCallbackEntry {OwnerCallbackResource* object;char unknown04[8];signed char tag;char unknown0D[3];};
struct OwnerCallbackManager {int count,capacity;OwnerCallbackEntry* entries;};
struct OwnerCallbackContext {char unknown00[0x118];OwnerCallbackManager* manager;};
extern "C" OwnerCallbackContext lbl_801E9D24;
inline OwnerCallbackResource* resolveOwnerCallback(const OwnerCallbackHandle& handle)
{
    OwnerCallbackEntry* entry=&lbl_801E9D24.manager->entries[handle.bits.index];
    if(entry->tag==handle.bits.tag)return entry->object;
    return 0;
}
struct OwnerCallbackAgent {char unknown00[0x24];OwnerCallbackHandle owner;};
struct OwnerCallbackAction {char unknown00[8];OwnerCallbackAgent* agent;};
extern "C" void fn_8025795C(void*,int,int);
#endif
