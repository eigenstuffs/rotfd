#include "Game/python_scalar_bindings.h"
extern "C" FactoryPyObject* PyFloat_FromDouble(double);
extern "C" const char lbl_802A5B74[];
struct PairPrefix_800DFC54 { char unknown[8]; };
struct PairView_800DFC54:PairPrefix_800DFC54 {
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
    virtual void slot3C(void*);
};

extern "C" FactoryPyObject* fn_800DFC54(FactoryPyObject*, FactoryPyObject* args) {
    PairView_800DFC54* self;
    void* other;
    FactoryPyObject* parsed0 = 0;
    FactoryPyObject* parsed1 = 0;
    if (!PyArg_ParseTuple(args, lbl_802A5B74, &parsed0, &parsed1)) return 0;
    if (fn_800CD864(parsed0, (void**)&self, lbl_80318988[0x50 / 4], 1) == -1) return 0;
    if (fn_800CD864(parsed1, (void**)&other, lbl_80318988[0xA8 / 4], 1) == -1) return 0;
    self->slot3C(other);
    ++_Py_NoneStruct.references;
    return &_Py_NoneStruct;
}
