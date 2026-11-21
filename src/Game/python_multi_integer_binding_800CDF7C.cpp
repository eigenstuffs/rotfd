/* Multiple integer/object argument binding; see docs/notes/game-python-multi-integer-bindings.md. */
#include "Game/python_scalar_bindings.h"
extern "C" long PyInt_AsLong(FactoryPyObject*);
extern "C" const char lbl_802A2BD4[];
extern "C" void fn_8001F90C(const char*, const char*, const char*);

extern "C" FactoryPyObject* fn_800CDF7C(FactoryPyObject*,FactoryPyObject* args){
    const char* arg0;
    const char* arg1;
    const char* arg2;
    if(!PyArg_ParseTuple(args,lbl_802A2BD4, &arg0, &arg1, &arg2))return 0;

    fn_8001F90C(arg0, arg1, arg2);
    ++_Py_NoneStruct.references;
    return &_Py_NoneStruct;
}
