#include "Game/python_scalar_bindings.h"
extern "C" long PyInt_AsLong(FactoryPyObject*);
extern "C" const char lbl_802A5004[];
extern "C" signed char fn_80257220(void*, long, void*);

extern "C" FactoryPyObject* fn_800DA884(FactoryPyObject*,FactoryPyObject* args){
    void* native0;
    void* native1;
    FactoryPyObject* arg0 = 0;
    FactoryPyObject* arg1 = 0;
    FactoryPyObject* arg2 = 0;
    if(!PyArg_ParseTuple(args,lbl_802A5004, &arg0, &arg1, &arg2))return 0;
    if(fn_800CD864(arg0,(void**)&native0,lbl_80318988[0x20/4],1)==-1)return 0;
    long value1=PyInt_AsLong(arg1);
    if(fn_800CD864(arg2,(void**)&native1,lbl_80318988[0xB4/4],1)==-1)return 0;
    return PyInt_FromLong(fn_80257220(native0, value1, native1));
}
