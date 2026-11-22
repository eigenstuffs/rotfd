typedef unsigned long u32;
struct Handle_801F7F10 {u32 word;Handle_801F7F10();~Handle_801F7F10();};
struct Manager;struct Context {char unknown00[0x118];Manager*manager;};
extern "C" {extern Context lbl_801E9D24;void fn_801F86C8(Manager*,const Handle_801F7F10*,short);void fn_801EF610(void*,void*);extern char lbl_801EF5C8[],lbl_802EBE28[],lbl_802EBE80[];extern float game_vec4_zero[4];extern const float lbl_803789A8;void __ct__20ObjectsRoot_80213EBCFv(void*);}
struct ZeroHandle1_80075C2C:Handle_801F7F10 {ZeroHandle1_80075C2C(){word=0;}~ZeroHandle1_80075C2C(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct ZeroHandle2_80075C2C:ZeroHandle1_80075C2C {ZeroHandle2_80075C2C(){word=0;}~ZeroHandle2_80075C2C(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct ZeroHandle3_80075C2C:ZeroHandle2_80075C2C {ZeroHandle3_80075C2C(){word=0;}~ZeroHandle3_80075C2C(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct ZeroHandle4_80075C2C:ZeroHandle3_80075C2C {ZeroHandle4_80075C2C(){word=0;}~ZeroHandle4_80075C2C(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80025B74:ZeroHandle4_80075C2C {Handle_80025B74(int=0){word=0;}~Handle_80025B74(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_8002B67C:Handle_801F7F10 {Handle_8002B67C(){word=0;}~Handle_8002B67C();};
struct ObjectsRoot_80213EBC {u32 unknown00[2];void*vtable;char unknown0C[0x20-0xC];ObjectsRoot_80213EBC(){__ct__20ObjectsRoot_80213EBCFv(this);}~ObjectsRoot_80213EBC();};
struct Object_80075DE4:ObjectsRoot_80213EBC {int index20;Handle_80025B74 handle24;Handle_8002B67C handle28;char unknown2C[0x6C-0x2C];Object_80075DE4():handle24((vtable=lbl_802EBE28,0)){index20=-1;Handle_80025B74 empty;fn_801F86C8(lbl_801E9D24.manager,&handle24,-1);handle24.word=empty.word;fn_801F86C8(lbl_801E9D24.manager,&empty,1);}~Object_80075DE4();};
struct Object_80075C2C:Object_80075DE4 {float point6C[3],value78;Handle_80025B74 handle7C;Object_80075C2C();};
Object_80075C2C::Object_80075C2C():handle7C((vtable=lbl_802EBE80,point6C[0]=game_vec4_zero[0],point6C[1]=game_vec4_zero[1],point6C[2]=game_vec4_zero[2],value78=lbl_803789A8,0)){}
