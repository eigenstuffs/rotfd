/* Multiple integer/object argument binding; see docs/notes/game-python-multi-integer-bindings.md. */
#include "Game/python_scalar_bindings.h"
extern "C" long PyInt_AsLong(FactoryPyObject*);
extern "C" const char lbl_802A2E80[];
extern "C" signed char fn_80200CBC(void*, long, signed char);

extern "C" FactoryPyObject* fn_800CF690(FactoryPyObject*,FactoryPyObject* args){
    void* native0;
    FactoryPyObject* arg0 = 0;
    FactoryPyObject* arg1 = 0;
    FactoryPyObject* arg2 = 0;
    long value1;
    signed char value2=1;
    if(!PyArg_ParseTuple(args,lbl_802A2E80, &arg0, &arg1, &arg2))return 0;
    if(fn_800CD864(arg0,(void**)&native0,lbl_80318988[0x1C/4],1)==-1)return 0;
    value1=PyInt_AsLong(arg1);
    if(arg2)value2=PyInt_AsLong(arg2);
    return PyInt_FromLong(fn_80200CBC(native0, value1, value2));
}
