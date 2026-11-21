/* Native indexed pointer wrapper; see docs/notes/game-python-global-pointer-binding.md. */
#include "Game/python_indexed_pointer_encoding.h"
extern "C" void* volatile lbl_80377548;
extern "C" const char lbl_802A2B64[];
inline FactoryPyObject*globalPointerObject(void*pointer,FactoryType*type){if(!pointer){++_Py_NoneStruct.references;return &_Py_NoneStruct;}char text[512];indexedPointerString(text,pointer,type);return PyString_FromString(text);}
extern "C" FactoryPyObject* fn_800CDC54(FactoryPyObject*,FactoryPyObject*args){
 if(!PyArg_ParseTuple(args,lbl_802A2B64))return 0;
 void*pointer=lbl_80377548;
 return globalPointerObject(pointer,lbl_80318988[0x5c/4]);
}
