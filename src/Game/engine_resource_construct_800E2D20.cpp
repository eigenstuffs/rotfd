typedef unsigned long u32;
extern "C" {void*fn_801EFA1C(void*,int,void*,void*,int,int);extern char lbl_801EF5C8[];extern float game_vec3_zero[3];void __ct__15Object_800272F0Fv(void*);void __ct__4CFSMFv(void*);void __ct__15Record_800218F8Fv(void*);void __ct__15Object_8009A9D8Fv(void*);void fn_8009D964(void*);void fn_800A8EB4(void*);}
struct Objects_802EB518 {u32 unknown00[2];void*vtable;char unknown0C[0x318-0xC];Objects_802EB518();~Objects_802EB518();};
struct Objects_802EB7C0 {u32 unknown00[2];void*vtable;char unknown0C[0x1F8-0xC];Objects_802EB7C0(){__ct__15Object_800272F0Fv(this);}~Objects_802EB7C0();};
struct CFSM {void*secondaryTable;char unknown04[0x2C-4];CFSM(){__ct__4CFSMFv(this);}~CFSM();};
struct Record_800218F8 {char unknown[0x94];Record_800218F8(int){__ct__15Record_800218F8Fv(this);}~Record_800218F8();};
struct Object_8009AA98 {char unknown0[0x8];void* vtable;char unknownC[0x30C];void* secondaryTable;char unknown31C[0x28];void* storage344;char unknown348[0xC];float value354;char unknown358[0xC];float value364;float value368;float value36C;char unknown370[0x20];Object_8009AA98(){__ct__15Object_8009A9D8Fv(this);}~Object_8009AA98();};
struct Object_8009DAB0 {char unknown0[0x8];void* vtable;char unknownC[0x30C];void* secondaryTable;char unknown31C[0x28];void* storage344;char unknown348[0xB0];Object_8009DAB0(){fn_8009D964(this);}~Object_8009DAB0();};
struct Object_800A8F90 {char unknown0[0x8];void* vtable;char unknownC[0x30C];void* secondaryTable;char unknown31C[0x28];void* storage344;char unknown348[0x24];float value36C;char unknown370[0x2C];float value39C;char unknown3A0[0x10];Object_800A8F90(){fn_800A8EB4(this);}~Object_800A8F90();};
extern "C" {extern char lbl_802C872C[],lbl_802AAFA8[],lbl_802AAFB8[];}
struct Object_800E2D20:Objects_802EB7C0,CFSM {void*storage224;Object_800E2D20();};
Object_800E2D20::Object_800E2D20(){vtable=lbl_802C872C;secondaryTable=lbl_802C872C+0x13C;storage224=fn_801EFA1C(lbl_801EF5C8,12,lbl_802AAFA8,lbl_802AAFB8,94,4);}
