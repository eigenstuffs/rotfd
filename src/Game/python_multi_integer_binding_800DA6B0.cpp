/* Multiple integer/object argument binding; see docs/notes/game-python-multi-integer-bindings.md. */
#include "Game/python_scalar_bindings.h"
extern "C" long PyInt_AsLong(FactoryPyObject*);
extern "C" const char lbl_802A4FC0[];
extern "C" void fn_80257700(void*, long, long);

extern "C" FactoryPyObject* fn_800DA6B0(FactoryPyObject*,FactoryPyObject* args){
    void* native0;
    FactoryPyObject* arg0 = 0;
    FactoryPyObject* arg1 = 0;
    FactoryPyObject* arg2 = 0;
    long value1;
    long value2=0;
    if(!PyArg_ParseTuple(args,lbl_802A4FC0, &arg0, &arg1, &arg2))return 0;
    if(fn_800CD864(arg0,(void**)&native0,lbl_80318988[0x20/4],1)==-1)return 0;
    value1=PyInt_AsLong(arg1);
    if(arg2)value2=PyInt_AsLong(arg2);
    fn_80257700(native0, value1, value2);
    ++_Py_NoneStruct.references;
    return &_Py_NoneStruct;
}
