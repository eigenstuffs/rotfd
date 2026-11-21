/* Void method binding; see docs/notes/game-python-void-bindings.md. */
#include "Game/python_scalar_bindings.h"
extern "C" const char lbl_802A5424[];
struct VoidPrefix_800DC3F4 { char unknown[8]; };
struct VoidView_800DC3F4:VoidPrefix_800DC3F4 {
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
};

extern "C" FactoryPyObject* fn_800DC3F4(FactoryPyObject*, FactoryPyObject* args) {
    VoidView_800DC3F4* self;
    FactoryPyObject* parsed = 0;
    if (!PyArg_ParseTuple(args, lbl_802A5424, &parsed)) return 0;
    if (fn_800CD864(parsed, (void**)&self, lbl_80318988[0xCC / 4], 1) == -1) return 0;
    self->slot8C();
    ++_Py_NoneStruct.references;
    return &_Py_NoneStruct;
}
