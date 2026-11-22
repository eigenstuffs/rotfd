typedef unsigned long u32;
struct Handle_801F7F10 {u32 word;Handle_801F7F10();~Handle_801F7F10();};
struct ZeroHandle:Handle_801F7F10 {ZeroHandle(){word=0;}~ZeroHandle();};
struct Handle_80020B90:ZeroHandle {Handle_80020B90(int){word=0;}~Handle_80020B90();};
struct Handle_8002B67C:Handle_801F7F10 {Handle_8002B67C(int){word=0;}~Handle_8002B67C();};
extern "C" {extern char __vt__23ContainerLayer_80044168[],lbl_802B4B50[],lbl_802B47AC[],lbl_802B46F0[],lbl_802B4634[],lbl_802B4404[],lbl_802B414C[];extern float game_vec3_zero[3],game_quat_identity[4];extern const float lbl_80378570;void __ct__22ContainerBase_802563CCFv(void*);}
struct RootContainer {u32 unknown00[2];void*vtable;char unknown0C[0x60-0xC];RootContainer(){__ct__22ContainerBase_802563CCFv(this);}~RootContainer();};
struct ContainerLayer_80044168:RootContainer {ContainerLayer_80044168(){vtable=__vt__23ContainerLayer_80044168;}~ContainerLayer_80044168();};
struct Agent_80044118:ContainerLayer_80044168 {char unknown60[8];unsigned char enabled68;char unknown69[7];Agent_80044118(){vtable=lbl_802B4B50;enabled68=1;}~Agent_80044118();};
typedef char AgentLayoutCheck[sizeof(Agent_80044118)==0x70?1:-1];
struct Object_8004904C:Agent_80044118 {Handle_80020B90 handle70;float value74,point78[3];Object_8004904C();};
Object_8004904C::Object_8004904C():handle70((vtable=lbl_802B47AC,0)){value74=lbl_80378570;point78[0]=game_vec3_zero[0];point78[1]=game_vec3_zero[1];point78[2]=game_vec3_zero[2];}
