/* Distance between the owners of two resources (fn_8005EAC8): the two-owner
   sibling of early_owner_distance_8005eb88.cpp. The distance service is
   captured first, then the other resource's owner handle is resolved before
   this resource's, and the scaled fn_80058350 result is returned.
   The two handle resolutions read the manager through two views so the
   entries pointer is reloaded for the second one, as in the original (see
   handle_owner_position_distance_8005EC4C.cpp). */
struct EarlyOwnerResource;
struct EarlyOwnerHandle{union{unsigned long value;struct{signed int tag:8;signed int index:24;}bits;};};
struct EarlyOwnerEntry{EarlyOwnerResource*object;char unknown04[8];signed char tag;char unknown0D[3];};
struct EarlyOwnerManager{int count,capacity;EarlyOwnerEntry*entries;};
struct EarlyOwnerTypedManager{int count,capacity;EarlyOwnerEntry*entries;};
struct EarlyOwnerSubsystem{char unknown00[0x15058];void*distance;};
struct EarlyOwnerContext{char unknown00[0x118];EarlyOwnerManager*manager;char unknown11C[8];EarlyOwnerSubsystem*subsystem;};
extern "C" EarlyOwnerContext lbl_801E9D24;
struct EarlyOwnerResource{char unknown00[0x58];EarlyOwnerHandle owner;};

inline EarlyOwnerResource*resolveEarlyOwner(const EarlyOwnerHandle&handle)
{
    EarlyOwnerEntry*entry=&lbl_801E9D24.manager->entries[handle.bits.index];
    if(entry->tag==handle.bits.tag)return entry->object;
    return 0;
}

inline EarlyOwnerResource*resolveEarlyOwnerTyped(const EarlyOwnerHandle&handle)
{
    EarlyOwnerEntry*entry=&((EarlyOwnerTypedManager*)lbl_801E9D24.manager)->entries[handle.bits.index];
    if(entry->tag==handle.bits.tag)return entry->object;
    return 0;
}

extern "C" {
float fn_80058350(void*,EarlyOwnerResource*,EarlyOwnerResource*);
extern const float lbl_803786A4;
}

extern "C" float fn_8005EAC8(EarlyOwnerResource*self,EarlyOwnerResource*other)
{
    void*distance=lbl_801E9D24.subsystem->distance;
    EarlyOwnerResource*target=resolveEarlyOwner(other->owner);
    return lbl_803786A4*fn_80058350(distance,resolveEarlyOwnerTyped(self->owner),target);
}
