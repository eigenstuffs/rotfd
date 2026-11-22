typedef unsigned long u32;
extern "C" {void*fn_801EFA1C(void*,int,void*,void*,int,int);extern char lbl_801EF5C8[];extern float game_vec3_zero[3];void __ct__15Object_800272F0Fv(void*);void __ct__4CFSMFv(void*);void __ct__15Record_800218F8Fv(void*);void __ct__15Object_8009A9D8Fv(void*);void fn_8009D964(void*);void fn_800A8EB4(void*);}
struct LodMove_Z {u32 unknown00[2];void*vtable;char unknown0C[0x318-0xC];LodMove_Z();~LodMove_Z();};
struct ObjectThrow_Z {u32 unknown00[2];void*vtable;char unknown0C[0x1F8-0xC];ObjectThrow_Z(){__ct__15Object_800272F0Fv(this);}~ObjectThrow_Z();};
struct CFSM {void*secondaryTable;char unknown04[0x2C-4];CFSM(){__ct__4CFSMFv(this);}~CFSM();};
struct Record_800218F8 {char unknown[0x94];Record_800218F8(int){__ct__15Record_800218F8Fv(this);}~Record_800218F8();};
struct CActorMove {char unknown0[0x8];void* vtable;char unknownC[0x30C];void* secondaryTable;char unknown31C[0x28];void* storage344;char unknown348[0xC];float value354;char unknown358[0xC];float value364;float value368;float value36C;char unknown370[0x20];CActorMove(){__ct__15Object_8009A9D8Fv(this);}~CActorMove();};
struct CScriptMove {char unknown0[0x8];void* vtable;char unknownC[0x30C];void* secondaryTable;char unknown31C[0x28];void* storage344;char unknown348[0xB0];CScriptMove(){fn_8009D964(this);}~CScriptMove();};
struct CRBObjBaseMove {char unknown0[0x8];void* vtable;char unknownC[0x30C];void* secondaryTable;char unknown31C[0x28];void* storage344;char unknown348[0x24];float value36C;char unknown370[0x2C];float value39C;char unknown3A0[0x10];CRBObjBaseMove(){fn_800A8EB4(this);}~CRBObjBaseMove();};
extern "C" {extern char __vt__11CMediumMove[],lbl_8029E9C0[],lbl_8029E9D0[];}
struct Object_800A3FB4:CScriptMove {void*storage3F8;Object_800A3FB4();};
Object_800A3FB4::Object_800A3FB4(){vtable=__vt__11CMediumMove;secondaryTable=__vt__11CMediumMove+0x170;storage3F8=0;storage3F8=fn_801EFA1C(lbl_801EF5C8,16,lbl_8029E9C0,lbl_8029E9D0,34,4);}
