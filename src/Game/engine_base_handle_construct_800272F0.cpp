typedef unsigned long u32;
extern "C" {void __ct__13Manipulator_ZFv(void*);extern char __vt__12ObjectMove_Z[];void __ct__4CFSMFv(void*);extern char lbl_801EF5C8[];void*fn_801EFA1C(void*,int,void*,void*,int,int);extern float game_vec3_zero[3];}
struct Manipulator_Z {u32 unknown00[2];void*vtable;char unknown0C[0x20-0xC];Manipulator_Z(){__ct__13Manipulator_ZFv(this);}~Manipulator_Z();};
struct Handle_801F7F10 {u32 word;Handle_801F7F10();~Handle_801F7F10();};
struct Zero1:Handle_801F7F10 {Zero1(){word=0;}~Zero1();};
struct Zero2:Zero1 {Zero2(){word=0;}~Zero2();};
struct Zero3:Zero2 {Zero3(){word=0;}~Zero3();};
struct Handle_80020B90:Zero1 {Handle_80020B90(int=0){word=0;}~Handle_80020B90();};
struct Handle_80020834:Zero1 {Handle_80020834(){word=0;}~Handle_80020834();};
struct Handle_80021B54:Zero2 {Handle_80021B54(){word=0;}~Handle_80021B54();};
struct Handle_8002759C:Zero2 {Handle_8002759C(int){word=0;}~Handle_8002759C();};
struct Handle_800274B0:Zero2 {Handle_800274B0(){word=0;}~Handle_800274B0();};
struct Handle_80025BF4:Zero3 {Handle_80025BF4(){word=0;}~Handle_80025BF4();};
struct Array_80027688 {int count,capacity;void*data;Array_80027688(){count=0;capacity=0;data=0;}~Array_80027688();};
struct Array_80027740 {int count,capacity;void*data;Array_80027740(){count=0;capacity=0;data=0;}~Array_80027740();};
struct Array_8002781C {int count,capacity;void*data;Array_8002781C(){count=0;capacity=0;data=0;}~Array_8002781C();};
struct Array_800278D4 {int count,capacity;void*data;Array_800278D4(){count=0;capacity=0;data=0;}~Array_800278D4();};
struct ZeroWord {u32 word;ZeroWord(){word=0;}};
struct ObjectMove_Z:Manipulator_Z {
 Handle_80020B90 handle20;Handle_80020834 handle24;Handle_80021B54 handle28;char unknown2C[0xC];
 Array_800278D4 array38;Array_8002781C array44;Array_800278D4 array50;Array_80027740 array5C;Handle_80020B90 handle68;Array_80027688 array6C;ZeroWord field78;
 char unknown7C[0x12C-0x7C];Handle_80020B90 handle12C;char unknown130[0x168-0x130];
 ObjectMove_Z():handle20((vtable=__vt__12ObjectMove_Z,0)){}~ObjectMove_Z();
};
typedef char BaseSizeCheck[sizeof(ObjectMove_Z)==0x168?1:-1];
struct CFSM {void*secondaryTable;char unknown04[0x2C-4];CFSM(){__ct__4CFSMFv(this);}~CFSM();};
extern "C" char lbl_802EB7C0[];
struct Object_800272F0:ObjectMove_Z {Handle_8002759C handle168;Handle_800274B0 handle16C;char unknown170[0x10];Handle_80021B54 handle180;Handle_80025BF4 handle184;char unknown188[0x24];Handle_80025BF4 handle1AC,handle1B0;Object_800272F0();};
Object_800272F0::Object_800272F0():handle168((vtable=lbl_802EB7C0,0)){}
