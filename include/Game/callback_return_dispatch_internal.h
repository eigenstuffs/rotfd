#ifndef GAME_CALLBACK_RETURN_DISPATCH_INTERNAL_H
#define GAME_CALLBACK_RETURN_DISPATCH_INTERNAL_H
// Partial callback interfaces and value-handle lifetimes.
#include "Game/callback_related_dispatch_internal.h"
extern "C" {
    void __ct__15Handle_801F7F10Fv(void*);
    void __dt__15Handle_801F7F10Fv(void*,int);
    void fn_801F86C8(void*,const void*,int);
}
struct DispatchReturnHandle {
    unsigned long word;
    DispatchReturnHandle(){
        __ct__15Handle_801F7F10Fv(this);
    }
    ~DispatchReturnHandle(){
        __dt__15Handle_801F7F10Fv(this,0);
    }
};
struct DispatchNativeHandle {
    unsigned long word;
    DispatchNativeHandle(){
        __ct__15Handle_801F7F10Fv(this);
    }
    ~DispatchNativeHandle(){
        __dt__15Handle_801F7F10Fv(this,0);
    }
};
struct DispatchHandleLayer:DispatchNativeHandle {
    DispatchHandleLayer(){
        word=0;
    }
};
struct DispatchHandleCopy:DispatchHandleLayer {
    DispatchHandleCopy(const DispatchReturnHandle&value){
        word=value.word;
        fn_801F86C8(lbl_801E9D24.manager,&value,1);
    }
};
struct DispatchCallbackOwner{
    char unknown0[0x60];
    CallbackRelatedHandle handle60;
};
extern "C" DispatchReturnHandle fn_80257B70(DispatchCallbackOwner*,int);
struct DispatchCallbackTarget:CallbackRelatedStorage8 {
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1C();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2C();
    virtual void slot30(const DispatchHandleCopy*,void*,void*);
    virtual void slot34(const DispatchHandleCopy*,void*,void*);
};
#endif
