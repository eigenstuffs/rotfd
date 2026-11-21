// Native TeleportVolume constructor and the observed prefix/member layout.
// The virtual table and undefined methods remain original fallback; see unit notes.
typedef unsigned long u32;
struct Prefix {u32 unknown00[2];};
struct Agent_80044118:Prefix {
 virtual ~Agent_80044118();char unknown0C[0x70-0xC];
 Agent_80044118();
};
struct Handle_801F7F10 {u32 value;Handle_801F7F10();~Handle_801F7F10();};
struct Handle_8002B67C:Handle_801F7F10{Handle_8002B67C(){value=0;}~Handle_8002B67C();};
struct Handle_8001FF78:Handle_801F7F10{Handle_8001FF78(){value=0;}~Handle_8001FF78();};
struct Handle_80020B90:Handle_8001FF78{Handle_80020B90(){value=0;}~Handle_80020B90();};
struct Vec3{float x,y,z;Vec3();};
struct Quat{float w,x,y,z;Quat();};
extern "C"{extern const Vec3 game_vec3_zero;extern const Quat game_quat_identity;extern char __vt__14TeleportVolume[];}
inline Vec3::Vec3(){x=game_vec3_zero.x;y=game_vec3_zero.y;z=game_vec3_zero.z;}
inline Quat::Quat(){w=game_quat_identity.w;x=game_quat_identity.x;y=game_quat_identity.y;z=game_quat_identity.z;}
struct TeleportVolume:Agent_80044118{
 Handle_8002B67C reference70;Handle_80020B90 reference74,reference78,reference7C;u32 unknown80;Vec3 position84,position90;Quat rotation9C;signed char fieldAC,fieldAD;char paddingAE[2];u32 fieldB0,fieldB4;void*target,*resource;
 TeleportVolume();virtual ~TeleportVolume();
};
TeleportVolume::TeleportVolume(){fieldAC=0;fieldAD=0;fieldB0=0;fieldB4=0;}
