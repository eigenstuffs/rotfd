#include "Game/python_scalar_bindings.h"
extern "C" long PyInt_AsLong(FactoryPyObject*);
extern "C" const char lbl_802A3FCC[];
extern "C" signed char fn_8006B470(void*, void*, unsigned char);

extern "C" FactoryPyObject* fn_800D4F50(FactoryPyObject*, FactoryPyObject* args) {
    void* native0;
    void* native1;
    FactoryPyObject* arg0 = 0;
    FactoryPyObject* arg1 = 0;
    unsigned char arg2;
    if (!PyArg_ParseTuple(args, lbl_802A3FCC, &arg0, &arg1, &arg2)) return 0;
    if (fn_800CD864(arg0, (void**)&native0, lbl_80318988[0x84 / 4], 1) == -1) return 0;
    if (fn_800CD864(arg1, (void**)&native1, lbl_80318988[0xC8 / 4], 1) == -1) return 0;
    return PyInt_FromLong(fn_8006B470(native0, native1, arg2));
}
