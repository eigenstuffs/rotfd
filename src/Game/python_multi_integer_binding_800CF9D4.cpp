#include "Game/python_scalar_bindings.h"
extern "C" long PyInt_AsLong(FactoryPyObject*);
extern "C" const char lbl_802A2EFC[];
extern "C" void fn_80200C38(void*, void*, void*, long);

extern "C" FactoryPyObject* fn_800CF9D4(FactoryPyObject*,FactoryPyObject* args){
    void* native0;
    void* native1;
    void* native2;
    FactoryPyObject* arg0 = 0;
    FactoryPyObject* arg1 = 0;
    FactoryPyObject* arg2 = 0;
    FactoryPyObject* arg3 = 0;
    if(!PyArg_ParseTuple(args,lbl_802A2EFC, &arg0, &arg1, &arg2, &arg3))return 0;
    if(fn_800CD864(arg0,(void**)&native0,lbl_80318988[0x1C/4],1)==-1)return 0;
    if(fn_800CD864(arg1,(void**)&native1,lbl_80318988[0xA8/4],1)==-1)return 0;
    if(fn_800CD864(arg2,(void**)&native2,lbl_80318988[0xA8/4],1)==-1)return 0;
    long value3=PyInt_AsLong(arg3);
    fn_80200C38(native0, native1, native2, value3);
    ++_Py_NoneStruct.references;
    return &_Py_NoneStruct;
}
