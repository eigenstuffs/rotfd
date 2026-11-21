/* Void method binding; see docs/notes/game-python-void-bindings.md. */
#include "Game/python_scalar_bindings.h"
extern "C" const char lbl_802A54F0[];
struct VoidPrefix_800DCA1C { char unknown[8]; };
struct VoidView_800DCA1C:VoidPrefix_800DCA1C {
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
};

extern "C" FactoryPyObject* fn_800DCA1C(FactoryPyObject*, FactoryPyObject* args) {
    VoidView_800DCA1C* self;
    FactoryPyObject* parsed = 0;
    if (!PyArg_ParseTuple(args, lbl_802A54F0, &parsed)) return 0;
    if (fn_800CD864(parsed, (void**)&self, lbl_80318988[0xD0 / 4], 1) == -1) return 0;
    self->slot30();
    ++_Py_NoneStruct.references;
    return &_Py_NoneStruct;
}
