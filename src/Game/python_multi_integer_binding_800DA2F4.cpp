#include "Game/python_scalar_bindings.h"
extern "C" long PyInt_AsLong(FactoryPyObject*);
extern "C" const char lbl_802A4F14[];
extern "C" void fn_80257528(void*, long);

extern "C" FactoryPyObject* fn_800DA2F4(FactoryPyObject*,FactoryPyObject* args){
    void* native0;
    FactoryPyObject* arg0 = 0;
    FactoryPyObject* arg1 = 0;
    long value1=0;
    if(!PyArg_ParseTuple(args,lbl_802A4F14, &arg0, &arg1))return 0;
    if(fn_800CD864(arg0,(void**)&native0,lbl_80318988[0x20/4],1)==-1)return 0;
    if(arg1)value1=PyInt_AsLong(arg1);
    fn_80257528(native0, value1);
    ++_Py_NoneStruct.references;
    return &_Py_NoneStruct;
}
