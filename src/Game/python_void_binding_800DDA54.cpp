#include "Game/python_scalar_bindings.h"
extern "C" const char lbl_802A56B8[];
struct VoidPrefix_800DDA54 { char unknown[8]; };
struct VoidView_800DDA54:VoidPrefix_800DDA54 {
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
};

extern "C" FactoryPyObject* fn_800DDA54(FactoryPyObject*, FactoryPyObject* args) {
    VoidView_800DDA54* self;
    FactoryPyObject* parsed = 0;
    if (!PyArg_ParseTuple(args, lbl_802A56B8, &parsed)) return 0;
    if (fn_800CD864(parsed, (void**)&self, lbl_80318988[0x40 / 4], 1) == -1) return 0;
    self->slot18();
    ++_Py_NoneStruct.references;
    return &_Py_NoneStruct;
}
