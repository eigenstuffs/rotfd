#ifndef GAME_PYTHON_OWNER_FACTORIES_H
#define GAME_PYTHON_OWNER_FACTORIES_H
#include "Game/python_binding_registration_tables.h"

// Native pointer-name encoding used by the recovered Python creation bindings.
typedef unsigned long FactorySize;
struct FactoryPyObject { int references; void* type; };
struct FactoryType { const char* name; };
extern "C" {
extern const char lbl_802A2AA0[];
extern char lbl_801EF5C8[], lbl_80379704[1];
extern FactoryType* lbl_80318988[];
extern FactoryPyObject _Py_NoneStruct;
int PyArg_ParseTuple(FactoryPyObject*, const char*, ...);
FactoryPyObject* PyString_FromString(const char*);
char* strcpy(char*, const char*);
void* fn_801EFA1C(void*, FactorySize, const char*, const char*, int, int);
}
inline void* operator new(unsigned long, void* memory) { return memory; }

inline void factoryPointerString(char* out, void* pointer, FactoryType* type) {
    char reversed[32];
    char* next = reversed;
    if (pointer) {
        FactorySize value = (FactorySize)pointer;
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
inline FactoryPyObject* factoryPointerObject(void* pointer, FactoryType* type) {
    if (!pointer) {
        ++_Py_NoneStruct.references;
        return &_Py_NoneStruct;
    }
    char text[512];
    factoryPointerString(text, pointer, type);
    return PyString_FromString(text);
}
#endif
