#ifndef GAME_PYTHON_INDEXED_POINTER_ENCODING_H
#define GAME_PYTHON_INDEXED_POINTER_ENCODING_H
#include "Game/python_scalar_bindings.h"
inline void indexedPointerString(char* out, void* pointer, FactoryType* type) {
    char reversed[32];
    char* next = reversed;
    FactorySize value = (FactorySize)pointer;
    if (pointer) {
        while (value) {
            *next++ = lbl_802C1EE4[value & 15];
            value >>= 4;
        }
        *next = '_';
        while (next >= reversed)
            *out++ = *next--;
        strcpy(out, type->name);
    } else {
        strcpy(out, lbl_80379704);
    }
}

inline FactoryPyObject*indexedPointerObject(register void*pointer,FactoryType*type){if(!pointer){++_Py_NoneStruct.references;return &_Py_NoneStruct;}char text[512];indexedPointerString(text,pointer,type);return PyString_FromString(text);}

#endif
