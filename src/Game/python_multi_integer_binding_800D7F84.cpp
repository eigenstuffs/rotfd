/* Multiple integer/object argument binding; see docs/notes/game-python-multi-integer-bindings.md. */
#include "Game/python_scalar_bindings.h"
extern "C" long PyInt_AsLong(FactoryPyObject*);
extern "C" const char lbl_802A4A08[];

extern "C" FactoryPyObject* fn_800D7F84(FactoryPyObject*,FactoryPyObject* args){

    if(!PyArg_ParseTuple(args,lbl_802A4A08))return 0;

    ++_Py_NoneStruct.references;
    return &_Py_NoneStruct;
}
