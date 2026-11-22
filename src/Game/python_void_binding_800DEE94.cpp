#include "Game/python_scalar_bindings.h"
extern "C" const char lbl_802A5950[];
struct VoidPrefix_800DEE94 { char unknown[8]; };
struct VoidView_800DEE94:VoidPrefix_800DEE94 {
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
};

extern "C" FactoryPyObject* fn_800DEE94(FactoryPyObject*, FactoryPyObject* args) {
    VoidView_800DEE94* self;
    FactoryPyObject* parsed = 0;
    if (!PyArg_ParseTuple(args, lbl_802A5950, &parsed)) return 0;
    if (fn_800CD864(parsed, (void**)&self, lbl_80318988[0x48 / 4], 1) == -1) return 0;
    self->slot34();
    ++_Py_NoneStruct.references;
    return &_Py_NoneStruct;
}
