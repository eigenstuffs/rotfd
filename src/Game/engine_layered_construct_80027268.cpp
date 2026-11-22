typedef unsigned long u32;
struct Handle_801F7F10 {u32 word;Handle_801F7F10();~Handle_801F7F10();};
struct Zero1:Handle_801F7F10 {Zero1(){word=0;}~Zero1();};
struct Zero2:Zero1 {Zero2(){word=0;}~Zero2();};
struct Zero3:Zero2 {Zero3(){word=0;}~Zero3();};
struct Handle_80021B54:Zero2 {Handle_80021B54(int){word=0;}~Handle_80021B54();};
struct Handle_80020B90:Zero1 {Handle_80020B90(int=0){word=0;}~Handle_80020B90();};
struct Handle_80025BF4:Zero3 {Handle_80025BF4(int){word=0;}~Handle_80025BF4();};
extern "C" {void __ct__15Object_800272F0Fv(void*);extern char lbl_802EB518[],lbl_802BB070[];extern float game_vec3_zero[3];extern const float lbl_80378D5C,lbl_80378D60;void __ct__4CFSMFv(void*);}
struct Objects_802EB7C0 {u32 unknown00[2];void*vtable;char unknown0C[0x1F8-0xC];Objects_802EB7C0(){__ct__15Object_800272F0Fv(this);}~Objects_802EB7C0();};
struct Objects_802EB518:Objects_802EB7C0 {Handle_80021B54 handle1F8;char unknown1FC[0x230-0x1FC];Handle_80020B90 handle230;char unknown234[0x2F8-0x234];u32 field2F8,field2FC,field300,field304,field308;unsigned char byte30C;char unknown30D[0x318-0x30D];Objects_802EB518();};
Objects_802EB518::Objects_802EB518():handle1F8((vtable=lbl_802EB518,0)){byte30C=0;field300=0;field304=0;field308=0;field2FC=0;field2F8=0;}
