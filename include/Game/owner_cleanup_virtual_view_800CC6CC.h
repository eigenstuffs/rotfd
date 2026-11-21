#ifndef GAME_OWNER_CLEANUP_VIRTUAL_VIEW_800CC6CC_H
#define GAME_OWNER_CLEANUP_VIRTUAL_VIEW_800CC6CC_H
/* Partial observed cleanup view. Original full class table remains external. */
typedef unsigned long u32;
struct Resource_800CC6CC {virtual ~Resource_800CC6CC();};
namespace CleanupLayout_800CC6CC {
struct Primary {u32 unknown00[2];virtual void*cleanup(int);char unknown0C[0x30c];};
struct Secondary {virtual void*cleanup(int);virtual void hook_800CCED8();char unknown04[0x28];};
}
struct OwnerCleanupVirtualView_800CC6CC:CleanupLayout_800CC6CC::Primary,CleanupLayout_800CC6CC::Secondary {
 virtual void hook_800CCED8();virtual void*cleanup(int);
 Resource_800CC6CC**resources;
};
typedef char CheckOwnerPrimary_800CC6CC[sizeof(CleanupLayout_800CC6CC::Primary)==0x318?1:-1];
typedef char CheckOwnerSecondary_800CC6CC[sizeof(CleanupLayout_800CC6CC::Secondary)==0x2C?1:-1];
#endif
