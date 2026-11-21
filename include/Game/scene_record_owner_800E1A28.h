#ifndef GAME_SCENE_RECORD_OWNER_800E1A28_H
#define GAME_SCENE_RECORD_OWNER_800E1A28_H
typedef unsigned long u32;
extern "C" { void fn_80090084(void*); void __ct__15Record_800218F8Fv(void*); extern char lbl_802C867C[],lbl_802C8630[]; }
struct Root {void*vtable;unsigned char enabled;char unknown05[3];Root(){fn_80090084(this);}~Root();};
struct Object_800E172C:Root {
    u32 value08,value0C;
    Object_800E172C(u32 a,u32 b){vtable=lbl_802C867C;value08=0;value0C=0;value08=a;value0C=b;}
    ~Object_800E172C();
};
struct Group { char unknown00[0x94];Group(int){__ct__15Record_800218F8Fv(this);}~Group(); };
struct Object_800E1A28:Object_800E172C {
    Group group10;u32 valueA4;Object_800E1A28(u32,u32);
};
#endif
