typedef unsigned long u32;
extern "C" {void __ct__15Object_8005E258Fv(void*);extern char lbl_802B6140[];}
struct Handle_801F7F10 {u32 word;Handle_801F7F10();~Handle_801F7F10();};
struct H1:Handle_801F7F10 {H1(){word=0;}~H1();};
struct Handle_80021B54:H1 {Handle_80021B54(int){word=0;word=0;}~Handle_80021B54();};
struct Handle_8002B67C:Handle_801F7F10 {Handle_8002B67C(){word=0;}~Handle_8002B67C();};
struct Handle_80020B90:H1 {Handle_80020B90(){word=0;}~Handle_80020B90();};
struct ContainerBase_802563CC {u32 unknown00[2];void*vtable;char unknown0C[0x60-0xC];ContainerBase_802563CC();~ContainerBase_802563CC();};
struct Object_8005E258 {u32 unknown00;void*secondaryVtable;char unknown08[0x160-8];Object_8005E258(){__ct__15Object_8005E258Fv(this);}~Object_8005E258();};
extern "C" Object_8005E258*lbl_803776B8;
struct Agent_80061AC0:ContainerBase_802563CC,Object_8005E258 {char unknown1C0[0x1CC-0x1C0];u32 field1CC,field1D0,field1D4;char unknown1D8[0x1EC-0x1D8];Handle_80021B54 handle1EC;Handle_8002B67C handle1F0;Handle_80020B90 handle1F4;u32 field1F8;Agent_80061AC0();};
Agent_80061AC0::Agent_80061AC0():handle1EC((vtable=lbl_802B6140,secondaryVtable=lbl_802B6140+0x74,field1CC=0,field1D0=0,field1D4=0,0)){field1F8=0;lbl_803776B8=this;}
