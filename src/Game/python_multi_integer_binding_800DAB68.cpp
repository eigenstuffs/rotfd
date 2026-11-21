/* Multiple integer/object argument binding; see docs/notes/game-python-multi-integer-bindings.md. */
#include "Game/python_scalar_bindings.h"
extern "C" long PyInt_AsLong(FactoryPyObject*);
extern "C" const char lbl_802A506C[];
extern "C" signed char fn_802568F4(void*, long, long, void*);

extern "C" FactoryPyObject* fn_800DAB68(FactoryPyObject*,FactoryPyObject* args){
    void* native0;
    void* native1;
    FactoryPyObject* arg0 = 0;
    FactoryPyObject* arg1 = 0;
    FactoryPyObject* arg2 = 0;
    FactoryPyObject* arg3 = 0;
    if(!PyArg_ParseTuple(args,lbl_802A506C, &arg0, &arg1, &arg2, &arg3))return 0;
    if(fn_800CD864(arg0,(void**)&native0,lbl_80318988[0x20/4],1)==-1)return 0;
    long value1=PyInt_AsLong(arg1);
    long value2=PyInt_AsLong(arg2);
    if(fn_800CD864(arg3,(void**)&native1,lbl_80318988[0xC/4],1)==-1)return 0;
    return PyInt_FromLong(fn_802568F4(native0, value1, value2, native1));
}
