/* Original engine native construction with guarded consumer migration with compiler-emitted exception metadata.
 * See docs/notes/game-engine-derived-handle-construct.md. */
typedef unsigned long u32;
extern "C" {void __ct__13Manipulator_ZFv(void*);extern char __vt__24ManipulatorDraw_802BC9D0[],lbl_802C8E88[];extern const float lbl_80379800;}
struct ObjectsRootView {u32 unknown00[2];void*vtable;char unknown0C[0x20-0xC];ObjectsRootView(){__ct__13Manipulator_ZFv(this);}~ObjectsRootView();};
struct ManipulatorDraw_802BC9D0:ObjectsRootView {ManipulatorDraw_802BC9D0(){vtable=__vt__24ManipulatorDraw_802BC9D0;}~ManipulatorDraw_802BC9D0();};
struct Handle_801F7F10 {u32 word;Handle_801F7F10();~Handle_801F7F10();};
struct ZeroHandle:Handle_801F7F10 {ZeroHandle(){word=0;}~ZeroHandle();};
struct Handle_80020B90:ZeroHandle {Handle_80020B90(int){word=0;}~Handle_80020B90();};
struct Object_800E6EF4:ManipulatorDraw_802BC9D0 {u32 field20;Handle_80020B90 handle24;float value28,value2C,value30;unsigned char field34;Object_800E6EF4();};
Object_800E6EF4::Object_800E6EF4():handle24((vtable=lbl_802C8E88,field20=0,0)){value28=lbl_80379800;value2C=lbl_80379800;value30=lbl_80379800;field34=1;field20=6;}
