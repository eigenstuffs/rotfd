/* Multiple integer/object argument binding; see docs/notes/game-python-multi-integer-bindings.md. */
#include "Game/python_scalar_bindings.h"
extern "C" long PyInt_AsLong(FactoryPyObject*);
extern "C" const char lbl_802A2E64[];
struct MultiWord_800CF578{unsigned long word;MultiWord_800CF578(const MultiWord_800CF578& other):word(other.word){}};
extern "C" signed char fn_802017D8(void*, long, MultiWord_800CF578, long);

extern "C" FactoryPyObject* fn_800CF578(FactoryPyObject*,FactoryPyObject* args){
    void* native0;
    MultiWord_800CF578* native1;
    FactoryPyObject* arg0 = 0;
    FactoryPyObject* arg1 = 0;
    FactoryPyObject* arg2 = 0;
    FactoryPyObject* arg3 = 0;
    long value1;
    long value3=0;
    if(!PyArg_ParseTuple(args,lbl_802A2E64, &arg0, &arg1, &arg2, &arg3))return 0;
    if(fn_800CD864(arg0,(void**)&native0,lbl_80318988[0x1C/4],1)==-1)return 0;
    value1=PyInt_AsLong(arg1);
    if(fn_800CD864(arg2,(void**)&native1,lbl_80318988[0xD8/4],1)==-1)return 0;
    if(arg3)value3=PyInt_AsLong(arg3);
    return PyInt_FromLong(fn_802017D8(native0, value1, *native1, value3));
}
