#ifndef GAME_OWNER_CLEANUP_VIRTUAL_VIEW_80095F4C_H
#define GAME_OWNER_CLEANUP_VIRTUAL_VIEW_80095F4C_H
/* Partial observed cleanup view. Original full class table remains external. */
typedef unsigned long u32;
struct Resource_80095F4C {virtual ~Resource_80095F4C();};
namespace CleanupLayout_80095F4C {
struct Primary {u32 unknown00[2];virtual void*cleanup(int);char unknown0C[0x30c];};
struct Secondary {virtual void*cleanup(int);virtual void hook_80096518();char unknown04[0x28];};
}
struct OwnerCleanupVirtualView_80095F4C:CleanupLayout_80095F4C::Primary,CleanupLayout_80095F4C::Secondary {
 virtual void hook_80096518();virtual void*cleanup(int);
 Resource_80095F4C**resources;
};
typedef char CheckOwnerPrimary_80095F4C[sizeof(CleanupLayout_80095F4C::Primary)==0x318?1:-1];
typedef char CheckOwnerSecondary_80095F4C[sizeof(CleanupLayout_80095F4C::Secondary)==0x2C?1:-1];
#endif
