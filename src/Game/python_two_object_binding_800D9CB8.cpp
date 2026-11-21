/* Two-object binding; see docs/notes/game-python-two-object-bindings.md. */
#include "Game/python_scalar_bindings.h"
extern "C" FactoryPyObject* PyFloat_FromDouble(double);
extern "C" const char lbl_802A4E64[];
struct PairPrefix_800D9CB8 { char unknown[8]; };
struct PairView_800D9CB8:PairPrefix_800D9CB8 {
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
    virtual void slot40(void*);
};

extern "C" FactoryPyObject* fn_800D9CB8(FactoryPyObject*, FactoryPyObject* args) {
    PairView_800D9CB8* self;
    void* other;
    FactoryPyObject* parsed0 = 0;
    FactoryPyObject* parsed1 = 0;
    if (!PyArg_ParseTuple(args, lbl_802A4E64, &parsed0, &parsed1)) return 0;
    if (fn_800CD864(parsed0, (void**)&self, lbl_80318988[0x20 / 4], 1) == -1) return 0;
    if (fn_800CD864(parsed1, (void**)&other, lbl_80318988[0x64 / 4], 1) == -1) return 0;
    self->slot40(other);
    ++_Py_NoneStruct.references;
    return &_Py_NoneStruct;
}
