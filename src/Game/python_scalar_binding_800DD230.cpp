#include "Game/python_scalar_bindings.h"
extern "C" const char lbl_802A5614[];
struct ScalarPrefix_800DD230 { char unknown[8]; };
struct ScalarView_800DD230:ScalarPrefix_800DD230 {
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
    virtual void slot68();
    virtual void slot6C();
    virtual void slot70();
    virtual void slot74();
    virtual void slot78();
    virtual void slot7C();
    virtual void slot80();
    virtual void slot84();
    virtual void slot88();
    virtual void slot8C();
    virtual void slot90();
    virtual void slot94();
    virtual void slot98();
    virtual void slot9C();
    virtual void slotA0();
    virtual void slotA4();
    virtual long slotA8();
};

extern "C" FactoryPyObject* fn_800DD230(FactoryPyObject*, FactoryPyObject* args) {
    ScalarView_800DD230* self;
    FactoryPyObject* parsed = 0;
    if (!PyArg_ParseTuple(args, lbl_802A5614, &parsed)) return 0;
    if (fn_800CD864(parsed, (void**)&self, lbl_80318988[0x3C / 4], 1) == -1) return 0;
    return PyInt_FromLong(self->slotA8());
}
