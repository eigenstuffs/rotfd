#include "Game/python_owner_factories.h"

extern "C" void* __ct__13Node_802417BCFv(void*);

static inline void nodeFactoryPointerString(char* out, FactorySize& value,
                                           FactoryType* type) {
    char reversed[32];
    char* next = reversed;
    if (value) {
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

static inline FactoryPyObject* nodeFactoryPointerObject(FactorySize& value,
                                                       FactoryType* type) {
    if (!value) {
        ++_Py_NoneStruct.references;
        return &_Py_NoneStruct;
    }
    char text[512];
    nodeFactoryPointerString(text, value, type);
    return PyString_FromString(text);
}

extern "C" FactoryPyObject* fn_800CE754(FactoryPyObject*, FactoryPyObject* args) {
    register const char* pool = lbl_802A2AA0;
    if (!PyArg_ParseTuple(args, pool + 0x238))
        return 0;
    FactorySize object = (FactorySize)fn_801EFA1C(
        lbl_801EF5C8, 0x138, pool + 0x174, pool + 0x60, 0x35F, 4);
    if (object)
        object = (FactorySize)__ct__13Node_802417BCFv((void*)object);
    return nodeFactoryPointerObject(object, lbl_80318988[0xC8 / 4]);
}
