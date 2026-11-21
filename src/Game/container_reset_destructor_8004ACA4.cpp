// Native handle temporary lifetimes and observed container reset fields.
typedef unsigned long u32;
extern "C" {
extern const char lbl_802B4634[],lbl_802B4B50[],__vt__23ContainerLayer_80044168[],lbl_802EC720[];
extern char lbl_801E9D24[];void fn_801F86C8(void*,const void*,int);
extern char lbl_801EF5C8[],lbl_8028F698[];
void fn_801EF610(void*,void*);void fn_8028FD50(void*,void*,int);
}
struct Handle_801F7F10 {u32 value;Handle_801F7F10();~Handle_801F7F10();
Handle_801F7F10&operator=(const Handle_801F7F10&o){fn_801F86C8(*(void**)(lbl_801E9D24+0x118),this,-1);value=o.value;fn_801F86C8(*(void**)(lbl_801E9D24+0x118),&o,1);return *this;}};
struct H1:Handle_801F7F10 {~H1(){}};
struct H2:H1 {~H2(){}};
struct H3:H2 {~H3(){}};
struct H4:H3 {~H4(){}};
struct H5:H4 {~H5(){}};
struct Element {u32 value;~Element(){}};
struct Pool {int size,capacity;Element*data;
 ~Pool(){if(data){for(int i=0;i<size;i++)data[i].~Element();if(data){fn_8028FD50(lbl_8028F698,data,capacity*4);data=0;}data=0;}}
};
struct Object_8025F0D8 {u32 unknown[2];const void*vtable;char unknown0C[0x3C];~Object_8025F0D8();static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct ContainerPrefix:Object_8025F0D8 {Pool pool;u32 unknown54;H2 handle58;char unknown5C[4];~ContainerPrefix(){vtable=lbl_802EC720;}};
struct Handle_8002B67C:Handle_801F7F10 {Handle_8002B67C(){value=0;}~Handle_8002B67C(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct ZeroHandle:Handle_801F7F10 {ZeroHandle(){value=0;}~ZeroHandle(){}};
struct Handle_80020B90:ZeroHandle {Handle_80020B90(){value=0;}~Handle_80020B90(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct ContainerLayer:ContainerPrefix {char unknown60[8];~ContainerLayer(){vtable=__vt__23ContainerLayer_80044168;}};
struct ContainerDerived:ContainerLayer {char unknown68[8];~ContainerDerived(){vtable=lbl_802B4B50;}};
struct Vec3 {float x,y,z;Vec3&operator=(const Vec3&o){x=o.x;y=o.y;z=o.z;return *this;}};struct Quat {float x,y,z,w;Quat&operator=(const Quat&o){x=o.x;y=o.y;z=o.z;w=o.w;return *this;}};
extern "C" {extern const Vec3 game_vec3_zero;extern const Quat game_quat_identity;}
struct Object_8004ACA4:ContainerDerived {Handle_8002B67C handle70;Handle_80020B90 handle74,handle78;Vec3 first,second;Quat rotation;~Object_8004ACA4();};
Object_8004ACA4::~Object_8004ACA4(){vtable=lbl_802B4634;handle70=Handle_8002B67C();handle74=Handle_80020B90();handle78=Handle_80020B90();first=game_vec3_zero;second=game_vec3_zero;rotation=game_quat_identity;}
