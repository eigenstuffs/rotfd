#include "Game/callback_handle_transfers_internal.h"
struct ParentTransferVirtualStorage {char unknown0[8];};
struct ParentTransferVirtual:ParentTransferVirtualStorage {
    virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();
    virtual void slot18();virtual void slot1C();virtual void slot20();virtual void slot24();
    virtual void slot28();virtual void slot2C();virtual void slot30();virtual void slot34();
    virtual void slot38();virtual void slot3C();virtual void slot40();virtual void slot44(const CallbackRelatedHandle&);
};
struct ParentTransferParent {char unknown0[0x1C];CallbackRelatedHandle handle1C;};
struct ParentTransferOwner {char unknown0[0x60];unsigned long word60;};
extern "C" {
    void fn_802560D8(void*);
    void fn_801F86C8(void*,const void*,int);
}
extern "C" void fn_80254F70(CallbackTransferOwner*self,const CallbackRelatedHandle&value){
    fn_802560D8(self);
    fn_801F86C8(lbl_801E9D24.manager,&self->handle58,-1);
    *(unsigned long*)&self->handle58=*(const unsigned long*)&value;
    fn_801F86C8(lbl_801E9D24.manager,&value,1);
    ((ParentTransferVirtual*)resolveRelated(self->handle64))->slot44(value);
    ((ParentTransferOwner*)self)->word60=*(unsigned long*)resolveRelated(((ParentTransferParent*)resolveRelated(value))->handle1C);
    ((ParentTransferVirtual*)self)->slot38();
}
