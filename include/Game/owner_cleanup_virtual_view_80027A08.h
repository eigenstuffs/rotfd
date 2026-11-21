#ifndef GAME_OWNER_CLEANUP_VIRTUAL_VIEW_80027A08_H
#define GAME_OWNER_CLEANUP_VIRTUAL_VIEW_80027A08_H
/* Observed deleting-cleanup ABI, exposed through a partial virtual view.
 * The complete CHookMove hierarchy and original 396-byte vtable remain external.
 * The compiler owns both this-adjusting entry points; no thunk body is supplied.
 * CFSM callbacks lie at secondary offset 0x2C, owner offset 0x344. */
typedef unsigned long u32;
struct FactoryCallback {virtual ~FactoryCallback();};
namespace CleanupLayout_80027A08 {
struct Primary {u32 unknown00[2];virtual void*cleanup(int);char unknown0C[0x30c];};
struct Secondary {virtual void*cleanup(int);virtual void configureCallbacks();char unknown04[0x28];FactoryCallback**callbacks;};
}
struct OwnerCleanupVirtualView_80027A08:CleanupLayout_80027A08::Primary,CleanupLayout_80027A08::Secondary {
 virtual void configureCallbacks();virtual void*cleanup(int);
};
typedef char CheckOwnerPrimary_80027A08[sizeof(CleanupLayout_80027A08::Primary)==0x318?1:-1];
typedef char CheckOwnerSecondary_80027A08[sizeof(CleanupLayout_80027A08::Secondary)==0x30?1:-1];
#endif
