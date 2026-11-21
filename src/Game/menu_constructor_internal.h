#ifndef ROTFD_MENU_CONSTRUCTOR_INTERNAL_H
#define ROTFD_MENU_CONSTRUCTOR_INTERNAL_H

// Native inheritance view for construction. Original dispatch tables remain external.
#include "menu_base_native_internal.h"
struct MenuElementsInit {
    int count, capacity;
    void* data;
    MenuElementsInit() : count(0), capacity(0), data(0) {}
};
struct MenuColor3 { float x,y,z; void set(float a,float b,float c){x=a;y=b;z=c;} };
struct MenuColor4 { float x,y,z,w; void set(float a,float b,float c,float d){x=a;y=b;z=c;w=d;} };
struct Menu2D_80216C9C : MenuBase_8021D7E4 {
    MenuHandle2 handle4C;
    unsigned char startLine;
    char unknown51[0x13];
    float scale;
    MenuElementsInit elements;
    MenuHandle2 bitmap;
    float pulse;
    unsigned char font;
    char unknown7D[3];
    MenuColor3 alternate,start,end,startSelect,endSelect;
    MenuColor4 grey;
    Menu2D_80216C9C();
    virtual ~Menu2D_80216C9C();
};
typedef char CheckMenu2DConstructor[sizeof(Menu2D_80216C9C)==0xCC?1:-1];
struct Menu3D_802193C0 : MenuBase_8021D7E4 {
    MenuHandle2 handle4C;
    unsigned char startLine;
    char unknown51[0x13];
    float scale;
    MenuElementsInit elements;
    MenuHandle2 bitmap;
    float pulse;
    unsigned char font;
    char unknown7D[3];
    MenuColor3 start,end,startSelect,endSelect;
    MenuColor4 grey;
    Menu3D_802193C0();
    virtual ~Menu3D_802193C0();
};
typedef char CheckMenu3DConstructor[sizeof(Menu3D_802193C0)==0xC0?1:-1];

#endif
