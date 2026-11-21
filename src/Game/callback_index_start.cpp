#include "Game/callback_related_dispatch_internal.h"
struct IndexStartNative {
    unsigned long word;
    IndexStartNative();
    ~IndexStartNative();
};
extern "C" {
    void __ct__15Handle_801F7F10Fv(void*);
    void __dt__15Handle_801F7F10Fv(void*,int);
    void fn_801F86C8(void*,const void*,int);
    void fn_801C6DE0(void*,void*,void*,const IndexStartNative&,int);
    void fn_802022FC(void*);
    void fn_801C5180(void*);
}
inline IndexStartNative::IndexStartNative(){
    __ct__15Handle_801F7F10Fv(this);
}
inline IndexStartNative::~IndexStartNative(){
    __dt__15Handle_801F7F10Fv(this,0);
}
struct IndexStartZero:IndexStartNative {
    IndexStartZero(){
        word=0;
    }
};
struct IndexStartZero2:IndexStartZero {
    IndexStartZero2(){
        word=0;
    }
};
struct IndexStartZero3:IndexStartZero2 {
    IndexStartZero3(){
        word=0;
    }
};
struct IndexStartCopy:IndexStartZero3 {
    IndexStartCopy(const CallbackRelatedHandle&source){
        word=*(const unsigned long*)&source;
        fn_801F86C8(lbl_801E9D24.manager,&source,1);
    }
};
struct IndexStartOwner {
    char unknown0[4];
    CallbackRelatedHandle own;
    char unknown8[0x30];
    unsigned long long flags;
    char unknown40[0x20];
    CallbackRelatedHandle handle60;
    int index;
    unsigned long state;
    CallbackRelatedHandle handle6C;
};
extern "C" void fn_8025D1C8(IndexStartOwner*self,int index){
    self->index=index;
    if(!(self->flags&0x80000ULL)){
        const CallbackRelatedHandle&own=self->own;
        IndexStartCopy copy(own);
        void*target=resolveRelated(self->handle6C);
        fn_801C6DE0(target,(char*)resolveRelated(self->handle60)+0xC,&self->state,copy,self->index);
    }
    if(self->flags&0x100000ULL)fn_802022FC(resolveRelated(self->handle60));
    fn_801C5180(resolveRelated(self->handle6C));
    self->flags|=0x80000ULL;
}
