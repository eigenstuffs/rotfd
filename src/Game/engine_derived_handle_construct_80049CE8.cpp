/* Original engine native construction with guarded consumer migration with compiler-emitted exception metadata.
 * See docs/notes/game-engine-derived-handle-construct.md. */
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
struct Object_80049CE8:Agent_80044118 {Handle_80020B90 handle70,handle74;char unknown78[0xC];float point84[3],value90,value94,value98,value9C;Object_80049CE8();};
Object_80049CE8::Object_80049CE8():handle70((vtable=lbl_802B46F0,0)),handle74(0){point84[0]=game_vec3_zero[0];point84[1]=game_vec3_zero[1];point84[2]=game_vec3_zero[2];value90=lbl_80378570;value94=lbl_80378570;value98=lbl_80378570;value9C=lbl_80378570;}
