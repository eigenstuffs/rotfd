// Bounded native virtual interface view for the observed memory-card methods.
// Its secondary interface begins at+0x20; all active calls use original C ABI
// pointer entries. This view does not claim the complete original C++ class.
// The generated view table and undefined destructor thunk are unowned and
// must be discarded by normal native linking. The original full table stays.
#include "manipulator_destructor_internal.h"
struct FactoryCallback{virtual~FactoryCallback();};
struct CFSMVirtualInterfaceView {
 virtual ~CFSMVirtualInterfaceView();
 virtual void configureCallbacks();
 virtual void configure(int);
 virtual void reset();
 signed char enabled,changing;char unknown06[2];int current,previous,pending,unknown14;unsigned long long active,activeCount;int count;FactoryCallback**callbacks;
 CFSMVirtualInterfaceView();
};
struct MemCardVirtualView:ObjectsRoot_80213EBC,CFSMVirtualInterfaceView {
 virtual void configureCallbacks();
 virtual void slot18();
 virtual void slot34();
 virtual void slot38(float);
 virtual ~MemCardVirtualView();
};
typedef char CheckPrimary[(sizeof(ObjectsRoot_80213EBC)==0x20)?1:-1];
typedef char CheckSecondary[(sizeof(CFSMVirtualInterfaceView)==0x30)?1:-1];
typedef char CheckOwner[(sizeof(MemCardVirtualView)==0x50)?1:-1];
extern "C" void fn_80213920(ObjectsOwner_80213D44*,int);
extern "C" signed char fn_8007DA74(CFSMVirtualInterfaceView*,float);
extern "C" {
extern char lbl_801EF5C8[];extern const char lbl_802AB880[],lbl_802AB890[];

void* fn_801EFA1C(void*,unsigned int,const char*,const char*,int,int);
void fn_8007D8EC(CFSMVirtualInterfaceView*,FactoryCallback**);
void fn_8007D6A0(CFSMVirtualInterfaceView*,int);
FactoryCallback* fn_800E9560(FactoryCallback*,MemCardVirtualView*);
FactoryCallback* fn_800E9F38(FactoryCallback*,MemCardVirtualView*);
FactoryCallback* fn_800EA5DC(FactoryCallback*,MemCardVirtualView*);
FactoryCallback* fn_800EAAC8(FactoryCallback*,MemCardVirtualView*);
FactoryCallback* fn_800EADEC(FactoryCallback*,MemCardVirtualView*);
FactoryCallback* fn_800EB294(FactoryCallback*,MemCardVirtualView*);
FactoryCallback* fn_800EBA08(FactoryCallback*,MemCardVirtualView*);
FactoryCallback* fn_800EBD7C(FactoryCallback*,MemCardVirtualView*);
FactoryCallback* fn_800EC2B8(FactoryCallback*,MemCardVirtualView*);
FactoryCallback* fn_800EC054(FactoryCallback*,MemCardVirtualView*);
FactoryCallback* fn_800EC8D8(FactoryCallback*,MemCardVirtualView*);
FactoryCallback* fn_800ECDD8(FactoryCallback*,MemCardVirtualView*);
FactoryCallback* fn_800EDC38(FactoryCallback*,MemCardVirtualView*);
FactoryCallback* fn_800ED75C(FactoryCallback*,MemCardVirtualView*);
FactoryCallback* fn_800ED2B4(FactoryCallback*,MemCardVirtualView*);
FactoryCallback* fn_800EE1A4(FactoryCallback*,MemCardVirtualView*);
FactoryCallback* fn_800EE620(FactoryCallback*,MemCardVirtualView*);
FactoryCallback* fn_800EEAFC(FactoryCallback*,MemCardVirtualView*);
FactoryCallback* fn_800EEFFC(FactoryCallback*,MemCardVirtualView*);
FactoryCallback* fn_800EF4B0(FactoryCallback*,MemCardVirtualView*);
FactoryCallback* fn_800EB75C(FactoryCallback*,MemCardVirtualView*);
FactoryCallback* fn_800E9648(FactoryCallback*,MemCardVirtualView*);
FactoryCallback* fn_800E9B14(FactoryCallback*,MemCardVirtualView*);
FactoryCallback* fn_800EC674(FactoryCallback*,MemCardVirtualView*);
}

void MemCardVirtualView::configureCallbacks() {
    MemCardVirtualView*self=this;
    {
        FactoryCallback* callback = (FactoryCallback*)fn_801EFA1C(
            lbl_801EF5C8, 16, lbl_802AB880, lbl_802AB890, 51, 4);
        if (callback) callback = fn_800E9560(callback,self);
        self->callbacks[0] = callback;
    }
    {
        FactoryCallback* callback = (FactoryCallback*)fn_801EFA1C(
            lbl_801EF5C8, 20, lbl_802AB880, lbl_802AB890, 52, 4);
        if (callback) callback = fn_800E9F38(callback,self);
        self->callbacks[5] = callback;
    }
    {
        FactoryCallback* callback = (FactoryCallback*)fn_801EFA1C(
            lbl_801EF5C8, 16, lbl_802AB880, lbl_802AB890, 53, 4);
        if (callback) callback = fn_800EA5DC(callback,self);
        self->callbacks[6] = callback;
    }
    {
        FactoryCallback* callback = (FactoryCallback*)fn_801EFA1C(
            lbl_801EF5C8, 16, lbl_802AB880, lbl_802AB890, 54, 4);
        if (callback) callback = fn_800EAAC8(callback,self);
        self->callbacks[7] = callback;
    }
    {
        FactoryCallback* callback = (FactoryCallback*)fn_801EFA1C(
            lbl_801EF5C8, 16, lbl_802AB880, lbl_802AB890, 55, 4);
        if (callback) callback = fn_800EADEC(callback,self);
        self->callbacks[8] = callback;
    }
    {
        FactoryCallback* callback = (FactoryCallback*)fn_801EFA1C(
            lbl_801EF5C8, 16, lbl_802AB880, lbl_802AB890, 56, 4);
        if (callback) callback = fn_800EB294(callback,self);
        self->callbacks[9] = callback;
    }
    {
        FactoryCallback* callback = (FactoryCallback*)fn_801EFA1C(
            lbl_801EF5C8, 16, lbl_802AB880, lbl_802AB890, 57, 4);
        if (callback) callback = fn_800EBA08(callback,self);
        self->callbacks[10] = callback;
    }
    {
        FactoryCallback* callback = (FactoryCallback*)fn_801EFA1C(
            lbl_801EF5C8, 20, lbl_802AB880, lbl_802AB890, 58, 4);
        if (callback) callback = fn_800EBD7C(callback,self);
        self->callbacks[1] = callback;
    }
    {
        FactoryCallback* callback = (FactoryCallback*)fn_801EFA1C(
            lbl_801EF5C8, 32, lbl_802AB880, lbl_802AB890, 59, 4);
        if (callback) callback = fn_800EC2B8(callback,self);
        self->callbacks[2] = callback;
    }
    {
        FactoryCallback* callback = (FactoryCallback*)fn_801EFA1C(
            lbl_801EF5C8, 16, lbl_802AB880, lbl_802AB890, 60, 4);
        if (callback) callback = fn_800EC054(callback,self);
        self->callbacks[3] = callback;
    }
    {
        FactoryCallback* callback = (FactoryCallback*)fn_801EFA1C(
            lbl_801EF5C8, 16, lbl_802AB880, lbl_802AB890, 61, 4);
        if (callback) callback = fn_800EC8D8(callback,self);
        self->callbacks[11] = callback;
    }
    {
        FactoryCallback* callback = (FactoryCallback*)fn_801EFA1C(
            lbl_801EF5C8, 16, lbl_802AB880, lbl_802AB890, 62, 4);
        if (callback) callback = fn_800ECDD8(callback,self);
        self->callbacks[12] = callback;
    }
    {
        FactoryCallback* callback = (FactoryCallback*)fn_801EFA1C(
            lbl_801EF5C8, 24, lbl_802AB880, lbl_802AB890, 63, 4);
        if (callback) callback = fn_800EDC38(callback,self);
        self->callbacks[13] = callback;
    }
    {
        FactoryCallback* callback = (FactoryCallback*)fn_801EFA1C(
            lbl_801EF5C8, 16, lbl_802AB880, lbl_802AB890, 64, 4);
        if (callback) callback = fn_800ED75C(callback,self);
        self->callbacks[14] = callback;
    }
    {
        FactoryCallback* callback = (FactoryCallback*)fn_801EFA1C(
            lbl_801EF5C8, 16, lbl_802AB880, lbl_802AB890, 65, 4);
        if (callback) callback = fn_800ED2B4(callback,self);
        self->callbacks[15] = callback;
    }
    {
        FactoryCallback* callback = (FactoryCallback*)fn_801EFA1C(
            lbl_801EF5C8, 20, lbl_802AB880, lbl_802AB890, 66, 4);
        if (callback) callback = fn_800EE1A4(callback,self);
        self->callbacks[16] = callback;
    }
    {
        FactoryCallback* callback = (FactoryCallback*)fn_801EFA1C(
            lbl_801EF5C8, 16, lbl_802AB880, lbl_802AB890, 67, 4);
        if (callback) callback = fn_800EE620(callback,self);
        self->callbacks[19] = callback;
    }
    {
        FactoryCallback* callback = (FactoryCallback*)fn_801EFA1C(
            lbl_801EF5C8, 24, lbl_802AB880, lbl_802AB890, 68, 4);
        if (callback) callback = fn_800EEAFC(callback,self);
        self->callbacks[17] = callback;
    }
    {
        FactoryCallback* callback = (FactoryCallback*)fn_801EFA1C(
            lbl_801EF5C8, 16, lbl_802AB880, lbl_802AB890, 69, 4);
        if (callback) callback = fn_800EEFFC(callback,self);
        self->callbacks[18] = callback;
    }
    {
        FactoryCallback* callback = (FactoryCallback*)fn_801EFA1C(
            lbl_801EF5C8, 16, lbl_802AB880, lbl_802AB890, 70, 4);
        if (callback) callback = fn_800EF4B0(callback,self);
        self->callbacks[20] = callback;
    }
    {
        FactoryCallback* callback = (FactoryCallback*)fn_801EFA1C(
            lbl_801EF5C8, 20, lbl_802AB880, lbl_802AB890, 71, 4);
        if (callback) callback = fn_800EB75C(callback,self);
        self->callbacks[21] = callback;
    }
    {
        FactoryCallback* callback = (FactoryCallback*)fn_801EFA1C(
            lbl_801EF5C8, 16, lbl_802AB880, lbl_802AB890, 74, 4);
        if (callback) callback = fn_800E9648(callback,self);
        self->callbacks[22] = callback;
    }
    {
        FactoryCallback* callback = (FactoryCallback*)fn_801EFA1C(
            lbl_801EF5C8, 16, lbl_802AB880, lbl_802AB890, 75, 4);
        if (callback) callback = fn_800E9B14(callback,self);
        self->callbacks[23] = callback;
    }
    {
        FactoryCallback* callback = (FactoryCallback*)fn_801EFA1C(
            lbl_801EF5C8, 16, lbl_802AB880, lbl_802AB890, 76, 4);
        if (callback) callback = fn_800EC674(callback,self);
        self->callbacks[4] = callback;
    }
    fn_8007D8EC(&static_cast<CFSMVirtualInterfaceView&>(*self),self->callbacks);
    static_cast<CFSMVirtualInterfaceView&>(*self).configure(24);
    fn_8007D6A0(&static_cast<CFSMVirtualInterfaceView&>(*self),0);
}

void MemCardVirtualView::slot38(float delta){fn_8007DA74(&static_cast<CFSMVirtualInterfaceView&>(*this),delta);}
