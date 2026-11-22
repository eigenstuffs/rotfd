typedef unsigned long Word;
extern "C" {void fn_801EF610(void*,void*);extern char lbl_801EF5C8[];void fn_801F86C8(void*,const void*,int);extern const float lbl_80378204,lbl_80378208,lbl_8037820C,lbl_803781F0,lbl_80378210,lbl_80378214,lbl_80378218,lbl_8037821C,lbl_80378220,lbl_80378228,lbl_8037822C,lbl_80378230,lbl_80378234;}
struct Globals_800221DC{char unknown00[0x118];void*manager;};extern "C" Globals_800221DC lbl_801E9D24;
struct Handle_801F7F10{Word value;Handle_801F7F10();~Handle_801F7F10();};
struct RecordZero1_800221DC:Handle_801F7F10{RecordZero1_800221DC(){value=0;}~RecordZero1_800221DC(){}};
struct RecordZero2_800221DC:RecordZero1_800221DC{RecordZero2_800221DC(){value=0;}~RecordZero2_800221DC(){}};
struct Handle_80021B54:RecordZero2_800221DC{Handle_80021B54(){value=0;}~Handle_80021B54(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}Handle_80021B54&operator=(const Handle_80021B54&from){Globals_800221DC*globals=&lbl_801E9D24;fn_801F86C8(globals->manager,this,-1);value=from.value;fn_801F86C8(globals->manager,&from,1);return *this;}};
struct Vector_800221DC{float x,y,z;Vector_800221DC&operator=(const Vector_800221DC&from){x=from.x;y=from.y;z=from.z;return *this;}};extern "C" Vector_800221DC game_vec3_zero;
struct Record_800221DC{float f00,f04,f08,f0C,f10,f14,f18,f1C,f20,f24,f28,f2C;Vector_800221DC p30,p3C;int index48;Vector_800221DC p4C;float f58;Vector_800221DC p5C;char unknown68[0x24];Handle_80021B54 first,second;
void defaults(){
f00=lbl_80378204;f04=lbl_80378208;f28=lbl_8037820C;f2C=lbl_803781F0;
f10=f14=lbl_80378210;f18=f1C=lbl_80378214;f0C=lbl_80378218;
p30=p3C=game_vec3_zero;f08=f24=f20=lbl_8037821C;index48=-1;
p4C=p5C=game_vec3_zero;f58=lbl_80378220;
first=second=Handle_80021B54();
}};
extern "C" void fn_800221DC(void*,Record_800221DC*out){out->defaults();out->f08=lbl_80378228;out->f00=lbl_80378204;out->f04=lbl_8037822C;out->f18=out->f1C=lbl_80378230;out->f10=out->f14=lbl_80378234;out->f0C=lbl_80378218;}
