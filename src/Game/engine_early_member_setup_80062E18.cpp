typedef unsigned long u32;
struct Handle_801F7F10 { u32 word; Handle_801F7F10(); ~Handle_801F7F10(); };
struct H0:Handle_801F7F10 { H0() { word=0; } ~H0(); };
struct Handle_80020B90:H0 { Handle_80020B90(int) { word=0; } ~Handle_80020B90(); };
struct Handle_80020478:Handle_801F7F10 { Handle_80020478(int) { word=0; } ~Handle_80020478(); };
extern "C" { extern char __vt__23ContainerLayer_80044168[],lbl_802B4200[],lbl_802B435C[],lbl_802B0330[],__vt__17CActorScriptAgent[]; extern float game_vec3_zero[3],game_quat_identity[4]; extern const float lbl_80378570; extern u32 lbl_8037767C; void __ct__18Breakable_802EC810Fv(void*); void __ct__15Object_8005E258Fv(void*); }
struct ContainerBase_802563CC { u32 unknown00[2]; void* vtable; char unknown0C[0x60-0xC]; ContainerBase_802563CC(); };
struct ContainerLayer_80044168:ContainerBase_802563CC { ContainerLayer_80044168(){ vtable=__vt__23ContainerLayer_80044168; } ~ContainerLayer_80044168(); };
struct Agent_8002B5F4 {u32 unknown00[2];void*vtable;char unknown0C[0x90-0xC];Agent_8002B5F4();~Agent_8002B5F4();};
struct Object_8005E258 {u32 unknown00;void*secondaryVtable;char unknown08[0x15C-8];signed char field15C;unsigned char field15D;char unknown15E[2];Object_8005E258(){__ct__15Object_8005E258Fv(this);}~Object_8005E258();};
struct H1:Handle_801F7F10 {H1(){word=0;}~H1();};
struct H2:H1 {H2(){word=0;}~H2();};
struct H3:H2 {H3(){word=0;}~H3();};
struct H4:H3 {H4(){word=0;}~H4();};
struct H5:H4 {H5(){word=0;}~H5();};
struct H6:H5 {H6(int){word=0;}~H6();};
struct CActorScriptAgent:Agent_8002B5F4,Object_8005E258 {u32 unknown1F0;H6 handle1F4;unsigned char field1F8;CActorScriptAgent();};
CActorScriptAgent::CActorScriptAgent():handle1F4((vtable=__vt__17CActorScriptAgent,secondaryVtable=__vt__17CActorScriptAgent+0xB4,field15C=-1,field15D=0,0)){field1F8=0;}
