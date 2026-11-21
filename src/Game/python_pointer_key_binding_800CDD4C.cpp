#include "Game/python_scalar_bindings.h"
inline FactoryPyObject* reversePointerObject(FactoryType* type, void* pointer){
 if(!pointer){++_Py_NoneStruct.references;return &_Py_NoneStruct;}
 char text[512];factoryPointerString(text,pointer,type);return PyString_FromString(text);
}

extern "C" unsigned long fn_801F948C(void*,const char*);
struct NameKey{unsigned long word;NameKey(const char*name){word=fn_801F948C(this,name);}NameKey(const NameKey& other):word(other.word){}};
extern "C" const char lbl_802A2B8C[];
extern "C" void* fn_80020500(NameKey);
extern "C" FactoryPyObject* fn_800CDD4C(FactoryPyObject*,FactoryPyObject* args){
 const char* name;
 if(!PyArg_ParseTuple(args,lbl_802A2B8C,&name))return 0;
 return reversePointerObject(lbl_80318988[0x28/4],fn_80020500(NameKey(NameKey(name))));
}
