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
struct QueryOwner{char unknown[0x64];QueryHandle member;};
extern "C" const char lbl_802A5A34[];
extern "C" FactoryPyObject* fn_800DF478(FactoryPyObject*,FactoryPyObject*args){
 QueryOwner* self;
 FactoryPyObject* parsed=0;
 if(!PyArg_ParseTuple(args,lbl_802A5A34,&parsed))return 0;
 if(fn_800CD864(parsed,(void**)&self,lbl_80318988[0x4c/4],1)==-1)return 0;

 return factoryPointerObject(resolveQuery(self->member),lbl_80318988[0x10/4]);
}
