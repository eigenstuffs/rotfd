#include "Game/callback_handle_transfers_internal.h"
extern "C" {
    void __ct__15Handle_801F7F10Fv(void*);
    void __dt__15Handle_801F7F10Fv(void*,int);
    void fn_801F86C8(void*,const void*,int);
    void fn_8025A324(void*,void*);
    void fn_8022F624(void*,const void*);
}
struct PairNativeHandle {
    unsigned long word;
    PairNativeHandle(){
        __ct__15Handle_801F7F10Fv(this);
    }
    ~PairNativeHandle(){
        __dt__15Handle_801F7F10Fv(this,0);
    }
};
struct PairHandleLayer1:PairNativeHandle{
    PairHandleLayer1(){
        word=0;
    }
};
struct PairHandleLayer2:PairHandleLayer1{
    PairHandleLayer2(){
        word=0;
    }
};
struct PairHandleLayer3:PairHandleLayer2{
    PairHandleLayer3(){
        word=0;
    }
};
struct PairReturnedHandle:PairHandleLayer3 {
    PairReturnedHandle(const CallbackRelatedHandle&value){
        word=*(const unsigned long*)&value;
        fn_801F86C8(lbl_801E9D24.manager,&value,1);
    }
};
struct PairCopiedHandle:PairHandleLayer3 {
    PairCopiedHandle(const PairReturnedHandle&value){
        word=value.word;
        fn_801F86C8(lbl_801E9D24.manager,&value,1);
    }
};
extern "C" void fn_80258E48(CallbackTransferOwner*self,void*value){
    fn_8025A324(self,value);
    const CallbackRelatedHandle&source=self->handle70;
    PairCopiedHandle temp((PairReturnedHandle(source)));
    fn_8022F624(resolveRelated(self->handle80),&temp);
}
