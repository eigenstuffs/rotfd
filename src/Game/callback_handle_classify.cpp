#include "Game/callback_handle_transfers_internal.h"
struct CallbackClassifyNative {
    unsigned long word;
    CallbackClassifyNative();
    ~CallbackClassifyNative();
};
extern "C" {
    void __ct__15Handle_801F7F10Fv(void*);
    void __dt__15Handle_801F7F10Fv(void*,int);
    void fn_801F86C8(void*,const void*,int);
    void fn_80200034(void*,const CallbackRelatedHandle*);
    signed char*fn_8025318C(void*,int*);
    int strcmp(const char*,const char*);
    extern const char lbl_802AEB80[];
}
inline CallbackClassifyNative::CallbackClassifyNative(){
    __ct__15Handle_801F7F10Fv(this);
}
inline CallbackClassifyNative::~CallbackClassifyNative(){
    __dt__15Handle_801F7F10Fv(this,0);
}
struct CallbackClassifyZero:CallbackClassifyNative {
    CallbackClassifyZero(){
        word=0;
    }
};
struct CallbackClassifyCopy:CallbackClassifyZero {
    CallbackClassifyCopy(const CallbackRelatedHandle&source){
        word=*(const unsigned long*)&source;
        fn_801F86C8(lbl_801E9D24.manager,&source,1);
    }
};
struct CallbackClassifyTarget {
    char unknown0[0x2C];
    CallbackRelatedHandle handle2C;
};
extern "C" void fn_80257E04(void*owner,const CallbackRelatedHandle*incoming){
    CallbackTransferOwner*self=(CallbackTransferOwner*)owner;
    if(fn_801F7EB8(&self->handle64))fn_80200034(resolveRelated(*incoming),&self->handle64);
    fn_80200104(resolveRelated(*incoming),&self->handle58);
    const CallbackRelatedHandle&related=((CallbackClassifyTarget*)resolveRelated(self->handle58))->handle2C;
    CallbackClassifyCopy copy(related);
    if(fn_801F7EB8((const CallbackRelatedHandle*)&copy)){
        int length;
        if(strcmp((const char*)fn_8025318C(resolveRelated(*(const CallbackRelatedHandle*)&copy),&length),lbl_802AEB80)==0)self->flags|=0x1000000ULL;
    }
}
