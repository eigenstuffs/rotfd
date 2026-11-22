#include "Game/python_scalar_bindings.h"
extern "C" long PyInt_AsLong(FactoryPyObject*);
extern "C" const char lbl_802A57AC[];
extern "C" signed char fn_8025CF84(void*, void*, void*, int);

extern "C" FactoryPyObject* fn_800DE194(FactoryPyObject*,FactoryPyObject* args){
    void* native0;
    void* native1;
    void* native2;
    FactoryPyObject* arg0 = 0;
    FactoryPyObject* arg1 = 0;
    FactoryPyObject* arg2 = 0;
    if(!PyArg_ParseTuple(args,lbl_802A57AC, &arg0, &arg1, &arg2))return 0;
    if(fn_800CD864(arg0,(void**)&native0,lbl_80318988[0x40/4],1)==-1)return 0;
    if(fn_800CD864(arg1,(void**)&native1,lbl_80318988[0x98/4],1)==-1)return 0;
    if(fn_800CD864(arg2,(void**)&native2,lbl_80318988[0x90/4],1)==-1)return 0;
    return PyInt_FromLong(fn_8025CF84(native0, native1, native2, 0));
}
