#ifndef GAME_EARLY_NATIVE_RECORD_CONSTRUCTOR_VIEWS_H
#define GAME_EARLY_NATIVE_RECORD_CONSTRUCTOR_VIEWS_H
typedef unsigned long Word;
extern "C" {void fn_801EF610(void*,void*);extern char lbl_801EF5C8[];void fn_801F86C8(void*,const void*,int);extern const float lbl_80378204,lbl_80378208,lbl_8037820C,lbl_803781F0,lbl_80378210,lbl_80378214,lbl_80378218,lbl_8037821C,lbl_80378220;}
struct Globals{char unknown00[0x118];void*manager;};extern "C" Globals lbl_801E9D24;
struct Handle_801F7F10{Word value;Handle_801F7F10();~Handle_801F7F10();};
struct RecordZero153A:Handle_801F7F10{RecordZero153A(){value=0;}~RecordZero153A(){}};
struct RecordZero153B:RecordZero153A{RecordZero153B(){value=0;}~RecordZero153B(){}};
struct Handle_80021B54:RecordZero153B{Handle_80021B54(){value=0;}~Handle_80021B54(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}Handle_80021B54&operator=(const Handle_80021B54&from){Globals*globals=&lbl_801E9D24;fn_801F86C8(globals->manager,this,-1);value=from.value;fn_801F86C8(globals->manager,&from,1);return *this;}};
struct Vector{float x,y,z;Vector&operator=(const Vector&from){x=from.x;y=from.y;z=from.z;return *this;}};extern "C" Vector game_vec3_zero;
struct Record_800218F8{float f00,f04,f08,f0C,f10,f14,f18,f1C,f20,f24,f28,f2C;Vector p30,p3C;int index48;Vector p4C;float f58;Vector p5C;char unknown68[0x24];Handle_80021B54 first,second;Record_800218F8();};
#endif
