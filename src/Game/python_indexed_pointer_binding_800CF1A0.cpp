#include "Game/python_indexed_pointer_encoding.h"
extern "C" const char lbl_802A2E0C[];
extern "C" long PyInt_AsLong(FactoryPyObject*);
struct Owner{char unknown[176];unsigned long*values;};
extern "C" FactoryPyObject*fn_800CF1A0(FactoryPyObject*,FactoryPyObject*args){
 void*self;FactoryPyObject*parsed=0;FactoryPyObject*indexObject=0;
 if(!PyArg_ParseTuple(args,lbl_802A2E0C,&parsed,&indexObject))return 0;
 if(fn_800CD864(parsed,&self,lbl_80318988[0x1c/4],1)==-1)return 0;
 long index=PyInt_AsLong(indexObject);
 unsigned long*pointer=&((Owner*)self)->values[index];
return indexedPointerObject(pointer,lbl_80318988[184/4]);
}
