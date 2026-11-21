/* Miscellaneous object binding; see docs/notes/game-python-misc-bindings.md. */
#include "Game/python_scalar_bindings.h"
extern "C" long PyInt_AsLong(FactoryPyObject*);
extern "C" const char lbl_802A5914[];
extern "C" const float lbl_80379710;
struct MiscPrefix_800DED2C { char unknown[8]; };
struct MiscView_800DED2C:MiscPrefix_800DED2C {
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
    virtual void slot80(long, float);
};
extern "C" FactoryPyObject* fn_800DED2C(FactoryPyObject*, FactoryPyObject* args) {
    MiscView_800DED2C* self;
    float delay = lbl_80379710;
    FactoryPyObject* parsed = 0;
    FactoryPyObject* number = 0;
    if (!PyArg_ParseTuple(args, lbl_802A5914, &parsed, &number, &delay)) return 0;
    if (fn_800CD864(parsed, (void**)&self, lbl_80318988[0x48 / 4], 1) == -1) return 0;
    long value = PyInt_AsLong(number);
    self->slot80(value, delay);
    ++_Py_NoneStruct.references;
    return &_Py_NoneStruct;
}
