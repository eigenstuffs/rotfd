typedef unsigned long u32;
struct Handle_801F7F10 { u32 word; Handle_801F7F10(); ~Handle_801F7F10(); };
struct H0:Handle_801F7F10 { H0() { word=0; } ~H0(); };
struct Handle_80020B90:H0 { Handle_80020B90(int) { word=0; } ~Handle_80020B90(); };
struct Handle_80020478:Handle_801F7F10 { Handle_80020478(int) { word=0; } ~Handle_80020478(); };
extern "C" { extern char __vt__23ContainerLayer_80044168[],lbl_802B4200[],lbl_802B435C[],lbl_802B0330[],__vt__17CActorScriptAgent[]; extern float game_vec3_zero[3],game_quat_identity[4]; extern const float lbl_80378570; extern u32 lbl_8037767C; void __ct__18Breakable_802EC810Fv(void*); void __ct__15Object_8005E258Fv(void*); }
extern "C" void __ct__22ContainerBase_802563CCFv(void*);
struct RootContainer { u32 unknown00[2]; void* vtable; char unknown0C[0x60-0xC]; RootContainer(){__ct__22ContainerBase_802563CCFv(this);} ~RootContainer(); };
struct ContainerLayer_80044168:RootContainer { ContainerLayer_80044168(){ vtable=__vt__23ContainerLayer_80044168; } ~ContainerLayer_80044168(); };
struct Agent_8004E90C:ContainerLayer_80044168 {
    Handle_80020B90 handle60;float field64;float point68[3];
    Agent_8004E90C();
};
Agent_8004E90C::Agent_8004E90C():handle60((vtable=lbl_802B435C,0)) { field64=lbl_80378570;point68[0]=game_vec3_zero[0];point68[1]=game_vec3_zero[1];point68[2]=game_vec3_zero[2]; }
