#include "Game/teleport_virtual_callback_records.h"
// TeleportVolume startup and its explicit virtual-only ABI callback records.
// TeleportVolume.h factory at800BA9BC proves the0xC0-byte object extent.
// This startup-only view reserves the native 0xC0-byte object and its stack
// alignment. Constructor/destructor implementations and the vtable stay in
// their existing source units; no virtual method body or table is defined here.
struct TeleportVolume {
 union {double alignment;unsigned char storage[0xC0];};
 TeleportVolume();~TeleportVolume();
};
typedef TeleportVirtualCallback VirtualCallback;
extern "C" {
extern unsigned long lbl_80377868;
void fn_800440B0();
void fn_8025E714(TeleportVolume*,const VirtualCallback*);
TeleportVirtualCallback lbl_802C1150[8] = {
 {0,0x94,8},{0,0x98,8},{0,0x9C,8},
 {0,0x98,8},{0,0x98,8},{0,0x98,8},{0,0x98,8},{0,0x98,8}
};
void fn_800C7534(){
 VirtualCallback*callbacks=lbl_802C1150;
 lbl_80377868=0;fn_800440B0();
 TeleportVolume object;
 VirtualCallback first=callbacks[0];fn_8025E714(&object,&first);
 VirtualCallback second=callbacks[1];fn_8025E714(&object,&second);
 VirtualCallback third=callbacks[2];fn_8025E714(&object,&third);
}
}
