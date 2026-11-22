typedef unsigned long u32;
struct Handle_801F7F10 { u32 word; Handle_801F7F10(); ~Handle_801F7F10(); };
struct H0:Handle_801F7F10 { H0() { word=0; } ~H0(); };
struct Handle_80020B90:H0 { Handle_80020B90(int) { word=0; } ~Handle_80020B90(); };
struct Handle_80020478:Handle_801F7F10 { Handle_80020478(int) { word=0; } ~Handle_80020478(); };
extern "C" { extern char __vt__23ContainerLayer_80044168[],lbl_802B4200[],lbl_802B435C[],lbl_802B0330[],__vt__17CActorScriptAgent[]; extern float game_vec3_zero[3],game_quat_identity[4]; extern const float lbl_80378570; extern u32 lbl_8037767C; void __ct__18Breakable_802EC810Fv(void*); void __ct__15Object_8005E258Fv(void*); }
struct ContainerBase_802563CC { u32 unknown00[2]; void* vtable; char unknown0C[0x60-0xC]; ContainerBase_802563CC(); };
struct ContainerLayer_80044168:ContainerBase_802563CC { ContainerLayer_80044168(){ vtable=__vt__23ContainerLayer_80044168; } ~ContainerLayer_80044168(); };
struct Object_80020F2C { u32 unknown00[2];void*vtable;char unknown0C[0x88-0xC];Object_80020F2C(){__ct__18Breakable_802EC810Fv(this);}~Object_80020F2C(); };
struct Agent_80021260:Object_80020F2C {
    Handle_80020B90 handle88,handle8C;float quat90[4],pointA0[3],pointAC[3];u32 fieldB8;Handle_80020B90 handleBC;
    Agent_80021260();~Agent_80021260();
};
inline Agent_80021260::Agent_80021260():handle88((vtable=lbl_802B0330,0)),handle8C(0),handleBC((quat90[0]=game_quat_identity[0],quat90[1]=game_quat_identity[1],quat90[2]=game_quat_identity[2],quat90[3]=game_quat_identity[3],pointA0[0]=game_vec3_zero[0],pointA0[1]=game_vec3_zero[1],pointA0[2]=game_vec3_zero[2],pointAC[0]=game_vec3_zero[0],pointAC[1]=game_vec3_zero[1],pointAC[2]=game_vec3_zero[2],fieldB8=0,0)) {}
extern "C" {extern u32 lbl_80377560;void fn_80022E28();extern char lbl_802B01A4[];}
struct Object_80022DAC:Agent_80021260 {Object_80022DAC(){vtable=lbl_802B01A4;}~Object_80022DAC();};
extern "C" void fn_80022CAC(){lbl_80377560=0;fn_80022E28();Object_80022DAC local;}
