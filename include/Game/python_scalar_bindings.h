#ifndef GAME_PYTHON_SCALAR_BINDINGS_H
#define GAME_PYTHON_SCALAR_BINDINGS_H
#include "Game/python_owner_factories.h"
extern "C" {
int fn_800CD864(FactoryPyObject*, void**, FactoryType*, int);
FactoryPyObject* PyInt_FromLong(long);
}
#endif
