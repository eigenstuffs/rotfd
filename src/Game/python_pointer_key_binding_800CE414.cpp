#include "Game/python_scalar_bindings.h"
extern "C" unsigned long fn_801F948C(void*,const char*);
struct NameKey{unsigned long word;NameKey(const char*name){word=fn_801F948C(this,name);}NameKey(const NameKey& other):word(other.word){}};
extern "C" const char lbl_802A2C6C[];
extern "C" void fn_802072D4(void*,const NameKey&,int);
extern "C" FactoryPyObject* fn_800CE414(FactoryPyObject*,FactoryPyObject* args){
 void* self;
 const char* name;
 FactoryPyObject* parsed=0;
 if(!PyArg_ParseTuple(args,lbl_802A2C6C,&parsed,&name))return 0;
 if(fn_800CD864(parsed,&self,lbl_80318988[0x5c/4],1)==-1)return 0;
 fn_802072D4(self,NameKey(name),0);
 ++_Py_NoneStruct.references;return &_Py_NoneStruct;
}
