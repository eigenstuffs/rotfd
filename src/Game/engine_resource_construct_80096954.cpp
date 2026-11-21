/* Original engine native construction with guarded consumer migration with compiler-emitted exception metadata.
 * See docs/notes/game-engine-resource-construct.md. */
typedef unsigned long u32;
extern "C" {void fn_800989C0(void*);void*fn_801EFA1C(void*,int,void*,void*,int,int);extern char lbl_801EF5C8[];}
struct Object_80098A70 {u32 unknown00[2];void*vtable;char unknown0C[0x318-0xC];void*secondaryTable;char unknown31C[0x344-0x31C];void*storage344;char unknown348[8];float value350;char unknown354[0x370-0x354];float value370,value374,value378;char unknown37C[0x394-0x37C];float value394,value398;char unknown39C[0x3B4-0x39C];float value3B4;char unknown3B8[0x3D0-0x3B8];float value3D0;char unknown3D4[4];float value3D8,value3DC,value3E0;char unknown3E4[4];Object_80098A70(){fn_800989C0(this);}~Object_80098A70();};
typedef char BaseSizeCheck[sizeof(Object_80098A70)==0x3E8?1:-1];
extern "C" {extern char lbl_802B9D24[],lbl_8029DF18[],lbl_8029DF28[];extern const float lbl_80378C78;extern const float lbl_80378C7C;extern const float lbl_80378C80;extern const float lbl_80378C84;}
struct Object_80096954:Object_80098A70 {int index3E8;Object_80096954();};
Object_80096954::Object_80096954(){vtable=lbl_802B9D24;secondaryTable=lbl_802B9D24+0x170;index3E8=-1;storage344=fn_801EFA1C(lbl_801EF5C8,36,lbl_8029DF18,lbl_8029DF28,32,4);value394=lbl_80378C78;value398=lbl_80378C78;value350=lbl_80378C7C;value378=lbl_80378C80;value374=lbl_80378C84;}
