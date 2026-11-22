/* Native handle generation lookup from a virtual query. */
#include "Game/python_scalar_bindings.h"
struct Handle_801F7F10{union{unsigned long word;struct{signed int generation:8;signed int index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct QueryObject{char unknown[0x20];long value;};
struct QueryEntry{QueryObject* object;char unknown4[8];signed char generation;char unknownD[3];signed char getGeneration()const{return generation;}};
struct QueryManager{char unknown[8];QueryEntry* entries;};
extern "C" struct{char unknown[0x118];QueryManager* manager;} lbl_801E9D24;
inline QueryObject* resolveQuery(const Handle_801F7F10&h){
 int index=h.bits.index;QueryManager*m=lbl_801E9D24.manager;int generation=m->entries[index].getGeneration();return generation==h.bits.generation?m->entries[index].object:0;
}
struct PythonIndexedReturnHandle:Handle_801F7F10{~PythonIndexedReturnHandle(){}};
extern "C" PythonIndexedReturnHandle fn_80257B70(void*,long);
extern "C" const char lbl_802A4EF4[];
extern "C" long PyInt_AsLong(FactoryPyObject*);
extern "C" FactoryPyObject*fn_800DA150(FactoryPyObject*,FactoryPyObject*args){
 void*self;
 FactoryPyObject*parsed=0;
 FactoryPyObject*indexObject=0;
 if(!PyArg_ParseTuple(args,lbl_802A4EF4,&parsed,&indexObject))return 0;
 if(fn_800CD864(parsed,&self,lbl_80318988[0x20/4],1)==-1)return 0;
 long index=PyInt_AsLong(indexObject);
 QueryObject*object=resolveQuery(fn_80257B70(self,index));
 return factoryPointerObject(object,lbl_80318988[0x60/4]);
}
