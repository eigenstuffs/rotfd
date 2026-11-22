typedef unsigned long u32;
struct Registry;struct Globals{char unknown[0x118];Registry*registry;};
extern "C" {extern Globals lbl_801E9D24;extern char lbl_801EF5C8[];void fn_801EF610(void*,void*);}
struct Prefix {u32 unknown00[2];};
struct Agent_80044118:Prefix {
 void* vtable; ~Agent_80044118();char unknown0C[0x70-0xC];
 Agent_80044118();
};
struct Handle_801F7F10 {u32 value;Handle_801F7F10();~Handle_801F7F10();static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
extern "C" void fn_801F86C8(Registry*,const Handle_801F7F10*,int);
struct Handle_8002B67C:Handle_801F7F10{Handle_8002B67C(){value=0;}~Handle_8002B67C(){}
 Handle_8002B67C&operator=(const Handle_8002B67C&other){fn_801F86C8(lbl_801E9D24.registry,this,-1);value=other.value;fn_801F86C8(lbl_801E9D24.registry,&other,1);return *this;}};
struct Handle_8001FF78:Handle_801F7F10{Handle_8001FF78(){value=0;}~Handle_8001FF78(){}};
struct Handle_80020B90:Handle_8001FF78{Handle_80020B90(){value=0;}~Handle_80020B90(){}
 Handle_80020B90&operator=(const Handle_80020B90&other){fn_801F86C8(lbl_801E9D24.registry,this,-1);value=other.value;fn_801F86C8(lbl_801E9D24.registry,&other,1);return *this;}};
struct Vec3{float x,y,z;Vec3();Vec3&operator=(const Vec3&o){x=o.x;y=o.y;z=o.z;return *this;}};
struct Quat{float w,x,y,z;Quat();Quat&operator=(const Quat&o){w=o.w;x=o.x;y=o.y;z=o.z;return *this;}};
extern "C"{extern const Vec3 game_vec3_zero;extern const Quat game_quat_identity;extern char __vt__14TeleportVolume[];}
inline Vec3::Vec3(){x=game_vec3_zero.x;y=game_vec3_zero.y;z=game_vec3_zero.z;}
inline Quat::Quat(){w=game_quat_identity.w;x=game_quat_identity.x;y=game_quat_identity.y;z=game_quat_identity.z;}
struct TeleportVolume:Agent_80044118{
 Handle_8002B67C reference70;Handle_80020B90 reference74,reference78,reference7C;u32 unknown80;Vec3 position84,position90;Quat rotation9C;signed char fieldAC,fieldAD;char paddingAE[2];u32 fieldB0,fieldB4;void*target,*resource;
 TeleportVolume();~TeleportVolume();
 static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}
};
TeleportVolume::~TeleportVolume(){
 vtable=__vt__14TeleportVolume;
 reference70=Handle_8002B67C();
 reference74=Handle_80020B90();
 reference78=Handle_80020B90();
 position84=game_vec3_zero;position90=game_vec3_zero;rotation9C=game_quat_identity;
 fieldAC=0;fieldAD=0;fieldB0=0;fieldB4=0;
}
