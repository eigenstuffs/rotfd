#include "Game/callback_related_dispatch_internal.h"
struct DefaultNative {
    unsigned long word;
    DefaultNative();
    ~DefaultNative();
};
extern "C" {
    void __ct__15Handle_801F7F10Fv(void*);
    void __dt__15Handle_801F7F10Fv(void*,int);
    void fn_801F86C8(void*,const void*,int);
    extern const float lbl_8037B528,lbl_8037B52C,lbl_8037B530,lbl_8037B534,lbl_8037B538,lbl_8037B53C,lbl_8037B540,lbl_8037B544,lbl_8037B548,lbl_8037B54C;
}
inline DefaultNative::DefaultNative(){
    __ct__15Handle_801F7F10Fv(this);
}
inline DefaultNative::~DefaultNative(){
    __dt__15Handle_801F7F10Fv(this,0);
}
struct DefaultZero:DefaultNative {
    DefaultZero(){
        word=0;
    }
};
struct DefaultZero2:DefaultZero {
    DefaultZero2(){
        word=0;
    }
};
struct DefaultZero3:DefaultZero2 {
    DefaultZero3(){
        word=0;
    }
};
struct DefaultHandle {
    unsigned long word;
    const DefaultHandle&operator=(const DefaultNative&source){
        fn_801F86C8(lbl_801E9D24.manager,this,-1);
        word=source.word;
        fn_801F86C8(lbl_801E9D24.manager,&source,1);
        return *this;
    }
    const DefaultHandle&operator=(const DefaultHandle&source){
        fn_801F86C8(lbl_801E9D24.manager,this,-1);
        word=source.word;
        fn_801F86C8(lbl_801E9D24.manager,&source,1);
        return *this;
    }
};
struct DefaultVector {
    float x,y,z;
    void operator=(const DefaultVector&source){
        x=source.x;
        y=source.y;
        z=source.z;
    }
};
extern "C" const DefaultVector game_vec3_zero;
struct DefaultRecord {
    float value00,value04,value08,value0C,value10,value14,value18,value1C,value20,value24,value28,value2C;
    DefaultVector vector30,vector3C;
    int index48;
    DefaultVector vector4C;
    float value58;
    DefaultVector vector5C;
    char unknown68[0x24];
    DefaultHandle handle8C,handle90;
};
extern "C" void slot90__11Throwable_ZFv(void*,DefaultRecord*self){
    self->value00=lbl_8037B528;
    self->value04=lbl_8037B52C;
    self->value28=lbl_8037B530;
    self->value2C=lbl_8037B534;
    self->value10=self->value14=lbl_8037B538;
    self->value18=self->value1C=lbl_8037B53C;
    self->value0C=lbl_8037B540;
    self->vector3C=game_vec3_zero;
    self->vector30=self->vector3C;
    self->value08=self->value24=self->value20=lbl_8037B544;
    self->index48=-1;
    self->vector5C=game_vec3_zero;
    self->vector4C=self->vector5C;
    self->value58=lbl_8037B548;
    self->handle8C=self->handle90=DefaultZero3();
    self->value08=lbl_8037B544;
    self->value00=lbl_8037B528;
    self->value04=lbl_8037B540;
    self->value18=self->value1C=lbl_8037B540;
    self->value10=self->value14=lbl_8037B54C;
}
