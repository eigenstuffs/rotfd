/* Original engine inline base construction with compiler-emitted exception metadata.
 * See docs/notes/game-engine-inline-base-construct.md. */
typedef unsigned long u32;
struct Handle_801F7F10 { u32 word; Handle_801F7F10(); ~Handle_801F7F10(); };
struct H0:Handle_801F7F10 { H0() { word=0; } ~H0(); };
struct Handle_80020B90:H0 { Handle_80020B90(int) { word=0; } ~Handle_80020B90(); };
struct Handle_80020478:Handle_801F7F10 { Handle_80020478(int) { word=0; } ~Handle_80020478(); };
extern "C" { extern char __vt__23ContainerLayer_80044168[],lbl_802B4200[],lbl_802B435C[],lbl_802B0330[],lbl_802B6468[]; extern float game_vec3_zero[3],game_quat_identity[4]; extern const float lbl_80378570; extern u32 lbl_8037767C; void __ct__18Breakable_802EC810Fv(void*); void __ct__15Object_8005E258Fv(void*); }
extern "C" void __ct__22ContainerBase_802563CCFv(void*);
struct RootContainer { u32 unknown00[2]; void* vtable; char unknown0C[0x60-0xC]; RootContainer(){__ct__22ContainerBase_802563CCFv(this);} ~RootContainer(); };
struct ContainerLayer_80044168:RootContainer { ContainerLayer_80044168(){ vtable=__vt__23ContainerLayer_80044168; } ~ContainerLayer_80044168(); };
struct Agent_8004FAE8:ContainerLayer_80044168 {
    Handle_80020478 handle60;u32 field64;
    Agent_8004FAE8();
};
Agent_8004FAE8::Agent_8004FAE8():handle60((vtable=lbl_802B4200,0)) { field64=0;lbl_8037767C=0; }
