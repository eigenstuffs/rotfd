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
struct Objects_802EB518 {u32 unknown00[2];void*vtable;char unknown0C[0x318-0xC];Objects_802EB518();~Objects_802EB518();};
struct CFSM {void*secondaryTable;char unknown04[0x2C-4];CFSM(){__ct__4CFSMFv(this);}~CFSM();};
struct Object_8009A9D8:Objects_802EB518,CFSM {char unknown344[4];Handle_80025BF4 handle348;u32 field34C;float value350,value354,point358[3],value364,value368,value36C,value370,value374,value378,value37C,value380;Object_8009A9D8();};
Object_8009A9D8::Object_8009A9D8():handle348((vtable=lbl_802BB070,secondaryTable=lbl_802BB070+0x170,0)){field34C=0;value350=lbl_80378D5C;value354=lbl_80378D60;point358[0]=game_vec3_zero[0];point358[1]=game_vec3_zero[1];point358[2]=game_vec3_zero[2];value364=lbl_80378D5C;value368=lbl_80378D5C;value36C=lbl_80378D5C;value370=lbl_80378D5C;value374=lbl_80378D5C;value378=lbl_80378D5C;value37C=lbl_80378D5C;value380=lbl_80378D5C;}
