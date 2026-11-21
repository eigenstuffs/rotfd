// Agent_80052520 default constructor. Byte/extab identical; the element ctor
// passed to __construct_array is the weak __ct__15Handle_80024844Fv, which is
// byte-identical (code, reloc, extab) to the original fn_800528F0.
typedef unsigned long u32;
extern "C" {
extern char lbl_801EF5C8[];
extern const char lbl_802B4CC4[],lbl_802ED000[];
extern const char lbl_8029AE08[],lbl_8029AE18[];
extern const float lbl_8037859C,lbl_803785A0;
void __ct__22ContainerBase_802563CCFv(void*);
void* fn_801EFA1C(void*,unsigned int,const char*,const char*,int,int);
}
struct Handle_801F7F10 {u32 word;Handle_801F7F10();~Handle_801F7F10();};
struct H1:Handle_801F7F10 {H1(){word=0;}~H1();};
struct H2:H1 {H2(){word=0;}~H2();};
struct H3:H2 {H3(){word=0;}~H3();};
struct Handle_8002F634:H3 {Handle_8002F634(int){word=0;}~Handle_8002F634();};
struct Handle_8002F520:H3 {Handle_8002F520(){word=0;}~Handle_8002F520();};
struct Handle_80052930:Handle_801F7F10 {Handle_80052930(){word=0;}~Handle_80052930();};
struct Handle_80024844:H2 {Handle_80024844(){word=0;}~Handle_80024844();};
struct Handle_8005287C:H1 {Handle_8005287C(){word=0;}~Handle_8005287C();};
struct Array_80036CB8 {int size,capacity;void*data;Array_80036CB8(){size=0;capacity=0;data=0;}~Array_80036CB8();};
struct Vec3 {float x,y,z;Vec3(const Vec3&o){x=o.x;y=o.y;z=o.z;}};
struct Quat {float x,y,z,w;Quat(const Quat&o){x=o.x;y=o.y;z=o.z;w=o.w;}};
extern "C" {extern const Vec3 game_vec3_zero;extern const Quat game_quat_identity;}
struct ContainerBase_802563CC {
    u32 unknown00[2];
    const void* vtable;
    char unknown0C[0x60-0xC];
    ContainerBase_802563CC();
    ~ContainerBase_802563CC();
};
struct Object_800529A0:ContainerBase_802563CC {
    Object_800529A0(){vtable=lbl_802ED000;}
    ~Object_800529A0();
};
struct Prefix{char opaque00[0x7C];};
struct Service:Prefix{
    virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();
    virtual void slot18();virtual void slot1C();virtual void slot20();virtual void slot24();
    virtual void slot28();virtual void slot2C();virtual void slot30();virtual void slot34();
    virtual void slot38();virtual void slot3C();virtual void slot40();virtual void slot44();
    virtual void slot48();virtual void slot4C();virtual void slot50();virtual void slot54();
    virtual void slot58();virtual void slot5C();virtual void slot60();virtual void slot64();
    virtual void slot68();virtual signed char slot6C();
};
struct Context{char opaque00[0x158];Service*service;};
extern "C" Context lbl_801E9D24;
struct Agent_80052520;
extern "C" void fn_80055C88(Agent_80052520*,signed char);
struct Agent_80052520:Object_800529A0 {
    Handle_8002F634 handle60;
    Handle_8002F520 handle64;
    Handle_80052930 handle68;
    char unknown6C[0x80];
    u32 fieldEC;
    int fieldF0,fieldF4,fieldF8,fieldFC,field100;
    int field104;
    int field108;
    Vec3 point10C;
    u32 field118,field11C,field120,field124,field128;
    Vec3 point12C;
    void* groups;
    char unknown13C[0x70];
    short shorts1AC[100];
    Array_80036CB8 array274,array280;
    Handle_80024844 fixed28C[10],fixed2B4[5];
    u32* slots2C8;
    u32 field2CC;
    Vec3 position;
    Quat rotation;
    unsigned char flag2EC;
    signed char flag2ED;
    u32 field2F0;
    unsigned char flag2F4,flag2F5,flag2F6;
    Handle_8005287C handle2F8,handle2FC,handle300,handle304,handle308,handle30C,handle310;
    u32 field314;
    unsigned char flag318,flag319;
    u32 field31C;
    Agent_80052520();
};
Agent_80052520::Agent_80052520():handle60((vtable=lbl_802B4CC4,0)),
    fieldEC(0),fieldF0(-1),fieldF4(-1),fieldF8(-1),fieldFC(-1),field100(-1),field104(0),field108(-1),point10C(game_vec3_zero),
    field118(0),field11C(0),field120(0),field124(0),field128(0),point12C(game_vec3_zero),
    slots2C8(0),field2CC(0),position(game_vec3_zero),rotation(game_quat_identity),flag2EC(1),flag2ED(0),field2F0(0),flag2F4(1),flag2F5(0),flag2F6(0),
    field314(0),flag318(0),flag319(0),field31C(0)
{
    point10C.x=lbl_8037859C;point10C.y=lbl_803785A0;point10C.z=lbl_8037859C;
    groups=0;
    for(unsigned char i=0;i<100;i++)shorts1AC[i]=0;
    slots2C8=(u32*)fn_801EFA1C(lbl_801EF5C8,0x14,lbl_8029AE08,lbl_8029AE18,0xba,4);
    for(int i=0;i<5;i++)slots2C8[i]=0;
    field104=5;
    signed char v=lbl_801E9D24.service->slot6C();fn_80055C88(this,!v);
}
typedef char AgentSizeCheck[(sizeof(Agent_80052520)==0x320)?1:-1];
