typedef unsigned long u32;
extern "C" {void fn_800989C0(void*);void*fn_801EFA1C(void*,int,void*,void*,int,int);extern char lbl_801EF5C8[];}
struct Object_80098A70 {u32 unknown00[2];void*vtable;char unknown0C[0x318-0xC];void*secondaryTable;char unknown31C[0x344-0x31C];void*storage344;char unknown348[8];float value350;char unknown354[0x370-0x354];float value370,value374,value378;char unknown37C[0x394-0x37C];float value394,value398;char unknown39C[0x3B4-0x39C];float value3B4;char unknown3B8[0x3D0-0x3B8];float value3D0;char unknown3D4[4];float value3D8,value3DC,value3E0;char unknown3E4[4];Object_80098A70(){fn_800989C0(this);}~Object_80098A70();};
typedef char BaseSizeCheck[sizeof(Object_80098A70)==0x3E8?1:-1];
extern "C" {extern char lbl_802BA0BC[],lbl_8029DFF8[],lbl_8029E008[];}
struct Object_800972AC:Object_80098A70 {Object_800972AC();};
Object_800972AC::Object_800972AC(){vtable=lbl_802BA0BC;secondaryTable=lbl_802BA0BC+0x170;storage344=fn_801EFA1C(lbl_801EF5C8,24,lbl_8029DFF8,lbl_8029E008,25,4);}
