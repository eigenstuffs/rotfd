/* Original callback factory setup; each distinct callback owns its slot. */
struct FactoryCallback;
struct FactoryController {
    virtual void slot08();
    virtual void slot0C();
    virtual void configure(int);
    char unknown04[0x28];
};
struct FactoryOwner {
    char unknown00[0x20];
    FactoryController controller;
    FactoryCallback** slots;
};
extern "C" {
extern unsigned char lbl_801EF5C8[];
extern const char lbl_802AB880[],lbl_802AB890[];
void* fn_801EFA1C(void*,unsigned int,const char*,const char*,int,int);
void fn_8007D8EC(FactoryController*,FactoryCallback**);
void fn_8007D6A0(FactoryController*,int);
FactoryCallback* fn_800E9560(FactoryCallback*,FactoryOwner*);
FactoryCallback* fn_800E9F38(FactoryCallback*,FactoryOwner*);
FactoryCallback* fn_800EA5DC(FactoryCallback*,FactoryOwner*);
FactoryCallback* fn_800EAAC8(FactoryCallback*,FactoryOwner*);
FactoryCallback* fn_800EADEC(FactoryCallback*,FactoryOwner*);
FactoryCallback* fn_800EB294(FactoryCallback*,FactoryOwner*);
FactoryCallback* fn_800EBA08(FactoryCallback*,FactoryOwner*);
FactoryCallback* fn_800EBD7C(FactoryCallback*,FactoryOwner*);
FactoryCallback* fn_800EC2B8(FactoryCallback*,FactoryOwner*);
FactoryCallback* fn_800EC054(FactoryCallback*,FactoryOwner*);
FactoryCallback* fn_800EC8D8(FactoryCallback*,FactoryOwner*);
FactoryCallback* fn_800ECDD8(FactoryCallback*,FactoryOwner*);
FactoryCallback* fn_800EDC38(FactoryCallback*,FactoryOwner*);
FactoryCallback* fn_800ED75C(FactoryCallback*,FactoryOwner*);
FactoryCallback* fn_800ED2B4(FactoryCallback*,FactoryOwner*);
FactoryCallback* fn_800EE1A4(FactoryCallback*,FactoryOwner*);
FactoryCallback* fn_800EE620(FactoryCallback*,FactoryOwner*);
FactoryCallback* fn_800EEAFC(FactoryCallback*,FactoryOwner*);
FactoryCallback* fn_800EEFFC(FactoryCallback*,FactoryOwner*);
FactoryCallback* fn_800EF4B0(FactoryCallback*,FactoryOwner*);
FactoryCallback* fn_800EB75C(FactoryCallback*,FactoryOwner*);
FactoryCallback* fn_800E9648(FactoryCallback*,FactoryOwner*);
FactoryCallback* fn_800E9B14(FactoryCallback*,FactoryOwner*);
FactoryCallback* fn_800EC674(FactoryCallback*,FactoryOwner*);
}
extern "C" void fn_800F06B4(FactoryOwner* self) {
    {
        FactoryCallback* callback = (FactoryCallback*)fn_801EFA1C(
            lbl_801EF5C8, 16, lbl_802AB880, lbl_802AB890, 51, 4);
        if (callback) callback = fn_800E9560(callback,self);
        self->slots[0] = callback;
    }
    {
        FactoryCallback* callback = (FactoryCallback*)fn_801EFA1C(
            lbl_801EF5C8, 20, lbl_802AB880, lbl_802AB890, 52, 4);
        if (callback) callback = fn_800E9F38(callback,self);
        self->slots[5] = callback;
    }
    {
        FactoryCallback* callback = (FactoryCallback*)fn_801EFA1C(
            lbl_801EF5C8, 16, lbl_802AB880, lbl_802AB890, 53, 4);
        if (callback) callback = fn_800EA5DC(callback,self);
        self->slots[6] = callback;
    }
    {
        FactoryCallback* callback = (FactoryCallback*)fn_801EFA1C(
            lbl_801EF5C8, 16, lbl_802AB880, lbl_802AB890, 54, 4);
        if (callback) callback = fn_800EAAC8(callback,self);
        self->slots[7] = callback;
    }
    {
        FactoryCallback* callback = (FactoryCallback*)fn_801EFA1C(
            lbl_801EF5C8, 16, lbl_802AB880, lbl_802AB890, 55, 4);
        if (callback) callback = fn_800EADEC(callback,self);
        self->slots[8] = callback;
    }
    {
        FactoryCallback* callback = (FactoryCallback*)fn_801EFA1C(
            lbl_801EF5C8, 16, lbl_802AB880, lbl_802AB890, 56, 4);
        if (callback) callback = fn_800EB294(callback,self);
        self->slots[9] = callback;
    }
    {
        FactoryCallback* callback = (FactoryCallback*)fn_801EFA1C(
            lbl_801EF5C8, 16, lbl_802AB880, lbl_802AB890, 57, 4);
        if (callback) callback = fn_800EBA08(callback,self);
        self->slots[10] = callback;
    }
    {
        FactoryCallback* callback = (FactoryCallback*)fn_801EFA1C(
            lbl_801EF5C8, 20, lbl_802AB880, lbl_802AB890, 58, 4);
        if (callback) callback = fn_800EBD7C(callback,self);
        self->slots[1] = callback;
    }
    {
        FactoryCallback* callback = (FactoryCallback*)fn_801EFA1C(
            lbl_801EF5C8, 32, lbl_802AB880, lbl_802AB890, 59, 4);
        if (callback) callback = fn_800EC2B8(callback,self);
        self->slots[2] = callback;
    }
    {
        FactoryCallback* callback = (FactoryCallback*)fn_801EFA1C(
            lbl_801EF5C8, 16, lbl_802AB880, lbl_802AB890, 60, 4);
        if (callback) callback = fn_800EC054(callback,self);
        self->slots[3] = callback;
    }
    {
        FactoryCallback* callback = (FactoryCallback*)fn_801EFA1C(
            lbl_801EF5C8, 16, lbl_802AB880, lbl_802AB890, 61, 4);
        if (callback) callback = fn_800EC8D8(callback,self);
        self->slots[11] = callback;
    }
    {
        FactoryCallback* callback = (FactoryCallback*)fn_801EFA1C(
            lbl_801EF5C8, 16, lbl_802AB880, lbl_802AB890, 62, 4);
        if (callback) callback = fn_800ECDD8(callback,self);
        self->slots[12] = callback;
    }
    {
        FactoryCallback* callback = (FactoryCallback*)fn_801EFA1C(
            lbl_801EF5C8, 24, lbl_802AB880, lbl_802AB890, 63, 4);
        if (callback) callback = fn_800EDC38(callback,self);
        self->slots[13] = callback;
    }
    {
        FactoryCallback* callback = (FactoryCallback*)fn_801EFA1C(
            lbl_801EF5C8, 16, lbl_802AB880, lbl_802AB890, 64, 4);
        if (callback) callback = fn_800ED75C(callback,self);
        self->slots[14] = callback;
    }
    {
        FactoryCallback* callback = (FactoryCallback*)fn_801EFA1C(
            lbl_801EF5C8, 16, lbl_802AB880, lbl_802AB890, 65, 4);
        if (callback) callback = fn_800ED2B4(callback,self);
        self->slots[15] = callback;
    }
    {
        FactoryCallback* callback = (FactoryCallback*)fn_801EFA1C(
            lbl_801EF5C8, 20, lbl_802AB880, lbl_802AB890, 66, 4);
        if (callback) callback = fn_800EE1A4(callback,self);
        self->slots[16] = callback;
    }
    {
        FactoryCallback* callback = (FactoryCallback*)fn_801EFA1C(
            lbl_801EF5C8, 16, lbl_802AB880, lbl_802AB890, 67, 4);
        if (callback) callback = fn_800EE620(callback,self);
        self->slots[19] = callback;
    }
    {
        FactoryCallback* callback = (FactoryCallback*)fn_801EFA1C(
            lbl_801EF5C8, 24, lbl_802AB880, lbl_802AB890, 68, 4);
        if (callback) callback = fn_800EEAFC(callback,self);
        self->slots[17] = callback;
    }
    {
        FactoryCallback* callback = (FactoryCallback*)fn_801EFA1C(
            lbl_801EF5C8, 16, lbl_802AB880, lbl_802AB890, 69, 4);
        if (callback) callback = fn_800EEFFC(callback,self);
        self->slots[18] = callback;
    }
    {
        FactoryCallback* callback = (FactoryCallback*)fn_801EFA1C(
            lbl_801EF5C8, 16, lbl_802AB880, lbl_802AB890, 70, 4);
        if (callback) callback = fn_800EF4B0(callback,self);
        self->slots[20] = callback;
    }
    {
        FactoryCallback* callback = (FactoryCallback*)fn_801EFA1C(
            lbl_801EF5C8, 20, lbl_802AB880, lbl_802AB890, 71, 4);
        if (callback) callback = fn_800EB75C(callback,self);
        self->slots[21] = callback;
    }
    {
        FactoryCallback* callback = (FactoryCallback*)fn_801EFA1C(
            lbl_801EF5C8, 16, lbl_802AB880, lbl_802AB890, 74, 4);
        if (callback) callback = fn_800E9648(callback,self);
        self->slots[22] = callback;
    }
    {
        FactoryCallback* callback = (FactoryCallback*)fn_801EFA1C(
            lbl_801EF5C8, 16, lbl_802AB880, lbl_802AB890, 75, 4);
        if (callback) callback = fn_800E9B14(callback,self);
        self->slots[23] = callback;
    }
    {
        FactoryCallback* callback = (FactoryCallback*)fn_801EFA1C(
            lbl_801EF5C8, 16, lbl_802AB880, lbl_802AB890, 76, 4);
        if (callback) callback = fn_800EC674(callback,self);
        self->slots[4] = callback;
    }
    fn_8007D8EC(&self->controller,self->slots);
    self->controller.configure(24);
    fn_8007D6A0(&self->controller,0);
}
