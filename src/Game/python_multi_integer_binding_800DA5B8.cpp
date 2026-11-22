#include "Game/python_scalar_bindings.h"
extern "C" long PyInt_AsLong(FactoryPyObject*);
extern "C" const char lbl_802A4F9C[];
extern "C" void fn_80257828(void*, long, long, long);

extern "C" FactoryPyObject* fn_800DA5B8(FactoryPyObject*,FactoryPyObject* args){
    void* native0;
    FactoryPyObject* arg0 = 0;
    FactoryPyObject* arg1 = 0;
    FactoryPyObject* arg2 = 0;
    FactoryPyObject* arg3 = 0;
    long value1;
    long value2;
    long value3=0;
    if(!PyArg_ParseTuple(args,lbl_802A4F9C, &arg0, &arg1, &arg2, &arg3))return 0;
    if(fn_800CD864(arg0,(void**)&native0,lbl_80318988[0x20/4],1)==-1)return 0;
    value1=PyInt_AsLong(arg1);
    value2=PyInt_AsLong(arg2);
    if(arg3)value3=PyInt_AsLong(arg3);
    fn_80257828(native0, value1, value2, value3);
    ++_Py_NoneStruct.references;
    return &_Py_NoneStruct;
}
