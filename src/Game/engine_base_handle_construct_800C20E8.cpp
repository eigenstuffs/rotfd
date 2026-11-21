/* Original engine native construction with guarded consumer migration with compiler-emitted exception metadata.
 * See docs/notes/game-engine-base-handle-construct.md. */
typedef unsigned long u32;
struct Handle_801F7F10 {u32 word;Handle_801F7F10();~Handle_801F7F10();};
struct Zero1:Handle_801F7F10 {Zero1(){word=0;}~Zero1();};
struct Zero2:Zero1 {Zero2(){word=0;}~Zero2();};
struct Zero3:Zero2 {Zero3(){word=0;}~Zero3();};
struct Zero4:Zero3 {Zero4(){word=0;}~Zero4();};
struct Handle_8002B67C:Handle_801F7F10 {Handle_8002B67C(int){word=0;}~Handle_8002B67C();};
struct Handle_8002DE2C:Zero3 {Handle_8002DE2C(int=0){word=0;}~Handle_8002DE2C();};
struct Handle_8002DDAC:Zero4 {Handle_8002DDAC(){word=0;}~Handle_8002DDAC();};
struct Handle_80020834:Zero1 {Handle_80020834(int){word=0;}~Handle_80020834();};
struct Handle_800723F4:Zero1 {Handle_800723F4(int=0){word=0;}~Handle_800723F4();};
extern "C" {void __ct__13Manipulator_ZFv(void*);extern char __vt__24ManipulatorDraw_802BC9D0[],lbl_802BF6B0[];extern float game_vec3_zero[3];extern const float lbl_80379518,lbl_8037951C;}
struct ObjectsRootView {u32 unknown00[2];void*vtable;char unknown0C[0x20-0xC];ObjectsRootView(){__ct__13Manipulator_ZFv(this);}~ObjectsRootView();};
struct ManipulatorDraw_802BC9D0:ObjectsRootView {ManipulatorDraw_802BC9D0(){vtable=__vt__24ManipulatorDraw_802BC9D0;}~ManipulatorDraw_802BC9D0();};
struct Object_800C20E8:ManipulatorDraw_802BC9D0 {Handle_8002B67C handle20;u32 field24;unsigned char byte28;char unknown29[3];u32 field2C,field30,field34;char unknown38[0x60-0x38];u32 field60;char unknown64[0x564-0x64];u32 field564,field568,field56C,field570,field574,field578,field57C,field580,field584;float value588;u32 field58C,field590,field594,field598;char unknown59C[0x5EC-0x59C];float point5EC[3],point5F8[3];Handle_800723F4 handle604,handle608,handle60C;u32 field610,field614,field618,field61C,field620,field624;float value628,value62C;unsigned char byte630;Object_800C20E8();};
Object_800C20E8::Object_800C20E8():handle20((vtable=lbl_802BF6B0,0)),handle604((field24=0,byte28=0,field2C=0,field30=0,field34=0,field60=0,field564=0,field568=0,field56C=0,field570=0,field574=1,field578=0,field57C=0,field580=0,field584=0,value588=lbl_80379518,field58C=0,field590=0,field594=0,field598=0,point5EC[0]=game_vec3_zero[0],point5EC[1]=game_vec3_zero[1],point5EC[2]=game_vec3_zero[2],point5F8[0]=game_vec3_zero[0],point5F8[1]=game_vec3_zero[1],point5F8[2]=game_vec3_zero[2],0)){field610=0;field614=0;field618=0;field61C=0;field620=0;field624=0;value628=lbl_8037951C;value62C=lbl_8037951C;byte630=0;}
