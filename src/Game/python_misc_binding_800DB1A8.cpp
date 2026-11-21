/* Miscellaneous object binding; see docs/notes/game-python-misc-bindings.md. */
#include "Game/python_scalar_bindings.h"
extern "C" long PyInt_AsLong(FactoryPyObject*);
extern "C" const char lbl_802A5150[];
struct MiscPrefix_800DB1A8 { char unknown[8]; };
struct MiscView_800DB1A8:MiscPrefix_800DB1A8 {
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
    virtual void slot68(long);
};
extern "C" FactoryPyObject* fn_800DB1A8(FactoryPyObject*, FactoryPyObject* args) {
    MiscView_800DB1A8* self;
    FactoryPyObject* parsed = 0;
    FactoryPyObject* number = 0;
    if (!PyArg_ParseTuple(args, lbl_802A5150, &parsed, &number)) return 0;
    if (fn_800CD864(parsed, (void**)&self, lbl_80318988[0x20 / 4], 1) == -1) return 0;
    long value = PyInt_AsLong(number);
    self->slot68(value);
    ++_Py_NoneStruct.references;
    return &_Py_NoneStruct;
}
