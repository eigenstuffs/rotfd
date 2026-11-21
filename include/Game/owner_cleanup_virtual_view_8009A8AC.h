#ifndef GAME_OWNER_CLEANUP_VIRTUAL_VIEW_8009A8AC_H
#define GAME_OWNER_CLEANUP_VIRTUAL_VIEW_8009A8AC_H

/* Inferred ABI view of the observed deleting cleanup slot at offset 8. */
namespace CleanupLayout_8009A8AC {
struct Prefix {unsigned long unknown00[2];};
struct Primary:Prefix {virtual void* cleanup(int);char unknown0C[0x30C];};
struct Secondary {virtual void* cleanup(int);virtual void hook();char unknown04[0x28];};
}
struct OwnerCleanupVirtualView_8009A8AC:CleanupLayout_8009A8AC::Primary,CleanupLayout_8009A8AC::Secondary {
 virtual void hook(); virtual void*cleanup(int);
 void**resources;
};

#endif
