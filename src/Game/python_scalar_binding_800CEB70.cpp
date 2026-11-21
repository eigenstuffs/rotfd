/* Scalar method binding; see docs/notes/game-python-scalar-bindings.md. */
#include "Game/python_scalar_bindings.h"
extern "C" const char lbl_802A2D30[];
struct ScalarPrefix_800CEB70 { char unknown[8]; };
struct ScalarView_800CEB70:ScalarPrefix_800CEB70 {
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual signed char slot1C();
};

extern "C" FactoryPyObject* fn_800CEB70(FactoryPyObject*, FactoryPyObject* args) {
    ScalarView_800CEB70* self;
    FactoryPyObject* parsed = 0;
    if (!PyArg_ParseTuple(args, lbl_802A2D30, &parsed)) return 0;
    if (fn_800CD864(parsed, (void**)&self, lbl_80318988[0x1C / 4], 1) == -1) return 0;
    return PyInt_FromLong(self->slot1C());
}
