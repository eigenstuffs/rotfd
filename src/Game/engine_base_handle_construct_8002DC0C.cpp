typedef unsigned long u32;
struct Handle_801F7F10 {u32 word;Handle_801F7F10();~Handle_801F7F10();};
struct Zero1:Handle_801F7F10 {Zero1(){word=0;}~Zero1();};
struct Zero2:Zero1 {Zero2(){word=0;}~Zero2();};
struct Zero3:Zero2 {Zero3(){word=0;}~Zero3();};
struct Zero4:Zero3 {Zero4(){word=0;}~Zero4();};
struct Handle_8002B67C:Handle_801F7F10 {Handle_8002B67C(int){word=0;}~Handle_8002B67C();};
struct Handle_8002DE2C:Zero3 {Handle_8002DE2C(int=0){word=0;}~Handle_8002DE2C();};
struct Handle_8002DDAC:Zero4 {Handle_8002DDAC(){word=0;}~Handle_8002DDAC();};
struct Handle_80020834:Zero1 {Handle_80020834(int){word=0;}~Handle_80020834();};
struct Handle_800723F4:Zero1 {Handle_800723F4(int=0){word=0;}~Handle_800723F4();};
extern "C" char lbl_802B1C74[];
struct ContainerBase_802563CC {u32 unknown00[2];void*vtable;char unknown0C[0x60-0xC];ContainerBase_802563CC();~ContainerBase_802563CC();};
struct Object_8002DC0C:ContainerBase_802563CC {Handle_8002B67C handle60;u32 field64;char unknown68[4];Handle_8002DE2C handle6C,handle70,handle74;Handle_8002DDAC handle78;Handle_8002DE2C handle7C,handle80,handle84,handle88;Handle_8002DDAC handle8C;Handle_8002DE2C handle90;unsigned char byte94;Object_8002DC0C();};
Object_8002DC0C::Object_8002DC0C():handle60((vtable=lbl_802B1C74,0)),handle6C((field64=0,0)){byte94=0;}
