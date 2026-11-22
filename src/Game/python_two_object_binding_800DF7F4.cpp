#include "Game/python_scalar_bindings.h"
extern "C" FactoryPyObject* PyFloat_FromDouble(double);
extern "C" const char lbl_802A5AA4[];
struct PairPrefix_800DF7F4 { char unknown[8]; };
struct PairView_800DF7F4:PairPrefix_800DF7F4 {
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
    virtual void slot44(void*);
};

extern "C" FactoryPyObject* fn_800DF7F4(FactoryPyObject*, FactoryPyObject* args) {
    PairView_800DF7F4* self;
    void* other;
    FactoryPyObject* parsed0 = 0;
    FactoryPyObject* parsed1 = 0;
    if (!PyArg_ParseTuple(args, lbl_802A5AA4, &parsed0, &parsed1)) return 0;
    if (fn_800CD864(parsed0, (void**)&self, lbl_80318988[0x4C / 4], 1) == -1) return 0;
    if (fn_800CD864(parsed1, (void**)&other, lbl_80318988[0x64 / 4], 1) == -1) return 0;
    self->slot44(other);
    ++_Py_NoneStruct.references;
    return &_Py_NoneStruct;
}
