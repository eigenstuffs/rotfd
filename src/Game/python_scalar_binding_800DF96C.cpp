#include "Game/python_scalar_bindings.h"
extern "C" const char lbl_802A5AE8[];
struct ScalarView_800DF96C;
extern "C" signed char fn_80255618(ScalarView_800DF96C*);

extern "C" FactoryPyObject* fn_800DF96C(FactoryPyObject*, FactoryPyObject* args) {
    ScalarView_800DF96C* self;
    FactoryPyObject* parsed = 0;
    if (!PyArg_ParseTuple(args, lbl_802A5AE8, &parsed)) return 0;
    if (fn_800CD864(parsed, (void**)&self, lbl_80318988[0x4C / 4], 1) == -1) return 0;
    return PyInt_FromLong(fn_80255618(self));
}
