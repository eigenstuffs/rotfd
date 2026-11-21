typedef unsigned long u32;
extern "C" {
extern const char lbl_802B4CC4[],lbl_802ED000[],lbl_802EC720[];
extern char lbl_801EF5C8[],lbl_8028F698[];
void fn_801EF610(void*,void*);void fn_8028FD50(void*,void*,int);
}
struct Handle_801F7F10 {u32 value;~Handle_801F7F10();};
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
struct ContainerLayer:ContainerPrefix {~ContainerLayer(){vtable=lbl_802ED000;}};
struct Handle_80024844 {u32 value;~Handle_80024844();};
struct HandlePool {int size,capacity;H3*data;~HandlePool(){if(data){for(int i=0;i<size;i++)data[i].~H3();if(data){fn_8028FD50(lbl_8028F698,data,capacity*4);data=0;}data=0;}}};
inline void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}
struct Blob {};
struct Item {char unknown[20];Blob*a;Blob*b;Blob*c;};
struct Group {int count;char unknown4[40];Item*data;char unknown30[100];};
struct Vec3 {float x,y,z;Vec3&operator=(const Vec3&o){x=o.x;y=o.y;z=o.z;return *this;}};struct Quat {float x,y,z,w;Quat&operator=(const Quat&o){x=o.x;y=o.y;z=o.z;w=o.w;return *this;}};
extern "C" {extern const Vec3 game_vec3_zero;extern const Quat game_quat_identity;}
struct Agent_80052520:ContainerLayer {H4 handle60,handle64;H1 handle68;char unknown6C[0xCC];Group*groups;char unknown13C[0x138];HandlePool array274,array280;Handle_80024844 fixed28C[10],fixed2B4[5];char unknown2C8[8];Vec3 position;Quat rotation;char unknown2EC[12];H2 handle2F8,handle2FC,handle300,handle304,handle308,handle30C,handle310;~Agent_80052520();};
Agent_80052520::~Agent_80052520(){vtable=lbl_802B4CC4;if(groups){for(int i=0;i<8;i++){for(int j=0;j<groups[i].count;j++){if(groups[i].data[j].a)delete groups[i].data[j].a;if(groups[i].data[j].b)delete groups[i].data[j].b;if(groups[i].data[j].c)delete groups[i].data[j].c;}if(groups[i].data)delete groups[i].data;}delete groups;}position=game_vec3_zero;rotation=game_quat_identity;}
typedef char GroupSize[(sizeof(Group)==0x94)?1:-1];
typedef char ItemSize[(sizeof(Item)==0x20)?1:-1];
