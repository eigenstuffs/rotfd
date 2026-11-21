/* Native handle generation lookup from a virtual query. */
#include "Game/python_scalar_bindings.h"
struct QueryHandle{signed int generation:8; signed int index:24;};
struct QueryObject{char unknown[0x20];long value;};
struct QueryEntry{QueryObject* object;char unknown4[8];signed char generation;char unknownD[3];signed char getGeneration()const{return generation;}};
struct QueryManager{char unknown[8];QueryEntry* entries;};
extern "C" struct{char unknown[0x118];QueryManager* manager;} lbl_801E9D24;
inline QueryObject* resolveQuery(const QueryHandle&h){
 int index=h.index;QueryManager*m=lbl_801E9D24.manager;int generation=m->entries[index].getGeneration();return generation==h.generation?m->entries[index].object:0;
}
struct QueryPrefix{char unknown[8];};
struct QueryView:QueryPrefix{
virtual void slot08();
virtual void slot0C();
virtual void slot10();
virtual void slot14();
virtual void slot18();
virtual void slot1C();
virtual void slot20();
virtual void slot24();
virtual void slot28();
virtual void slot2C();
virtual void slot30();
virtual void slot34();
virtual void slot38();
virtual void slot3C();
virtual void slot40();
virtual void slot44();
virtual void slot48();
virtual void slot4C();
virtual void slot50();
virtual void slot54();
virtual void slot58();
virtual void slot5C();
virtual void slot60();
virtual void slot64();
virtual void slot68();
virtual void slot6C();
virtual void slot70();
virtual void slot74();
virtual const QueryHandle* slot78(int);
};
extern "C" long PyInt_AsLong(FactoryPyObject*);
extern "C" const char lbl_802A5878[];
extern "C" FactoryPyObject* fn_800DE87C(FactoryPyObject*,FactoryPyObject*args){
 QueryView*self;
 FactoryPyObject*parsed=0;
 FactoryPyObject*indexObject=0;
 long index=-1;
 if(!PyArg_ParseTuple(args,lbl_802A5878,&parsed,&indexObject))return 0;
 if(fn_800CD864(parsed,(void**)&self,lbl_80318988[0x48/4],1)==-1)return 0;
 if(indexObject)index=PyInt_AsLong(indexObject);
 return factoryPointerObject(resolveQuery(*self->slot78(index)),lbl_80318988[0xd4/4]);
}
