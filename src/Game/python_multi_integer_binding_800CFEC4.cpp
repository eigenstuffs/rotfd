/* Multiple integer/object argument binding; see docs/notes/game-python-multi-integer-bindings.md. */
#include "Game/python_scalar_bindings.h"
extern "C" long PyInt_AsLong(FactoryPyObject*);
extern "C" const char lbl_802A2F7C[];
extern "C" void fn_802002A4(void*, long, void*, void*);

extern "C" FactoryPyObject* fn_800CFEC4(FactoryPyObject*,FactoryPyObject* args){
    void* native0;
    void* native1;
    void* native2;
    FactoryPyObject* arg0 = 0;
    FactoryPyObject* arg1 = 0;
    FactoryPyObject* arg2 = 0;
    FactoryPyObject* arg3 = 0;
    if(!PyArg_ParseTuple(args,lbl_802A2F7C, &arg0, &arg1, &arg2, &arg3))return 0;
    if(fn_800CD864(arg0,(void**)&native0,lbl_80318988[0x1C/4],1)==-1)return 0;
    long value1=PyInt_AsLong(arg1);
    if(fn_800CD864(arg2,(void**)&native1,lbl_80318988[0xAC/4],1)==-1)return 0;
    if(fn_800CD864(arg3,(void**)&native2,lbl_80318988[0xA4/4],1)==-1)return 0;
    fn_802002A4(native0, value1, native1, native2);
    ++_Py_NoneStruct.references;
    return &_Py_NoneStruct;
}
