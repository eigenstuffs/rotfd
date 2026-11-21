#include "Game/callback_return_dispatch_internal.h"
struct PrimaryResetInterface:CallbackRelatedStorage8 {
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
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3C();
    virtual void slot40();
    virtual void slot44();
    virtual void slot48();
    virtual void slot4C();
    virtual void slot50();
    virtual void slot54();
    virtual void slot58();
    virtual void slot5C();
    virtual void slot60();
    virtual void slot64();
    virtual void slot68(int);
};
struct PrimaryResetOwner:DispatchCallbackOwner {
    CallbackRelatedHandle handle64;
};
extern "C" void fn_8025E588(void*);
extern "C" void fn_8023297C(void*,const DispatchHandleCopy*,int,int);
inline void primaryResetBody(PrimaryResetOwner*self){
    fn_8025E588(self);
    ((PrimaryResetInterface*)self)->slot68(0);
    if(fn_801F7EB8(&self->handle60))resolveRelated(self->handle60)->slot20(-1,1);
    DispatchHandleCopy value(fn_80257B70(self,0));
    if(!fn_801F7EB8((const CallbackRelatedHandle*)&value))return;
    if(fn_801F7EB8(&self->handle60))((DispatchCallbackTarget*)resolveRelated(self->handle60))->slot30(&value,0,0);
    else if(fn_801F7EB8(&self->handle64))fn_8023297C(resolveRelated(self->handle64),&value,0,1);
}
extern "C" void fn_80258654(PrimaryResetOwner*self){
    primaryResetBody(self);
}
