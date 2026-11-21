struct Handle_801F7F10{union{unsigned long value;struct{signed int generation:8;signed int index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};struct EventVisitHandle:Handle_801F7F10{~EventVisitHandle(){}};
struct EventVisitElement:EventVisitHandle{~EventVisitElement(){}};
struct EventVisitSelf{char unknown00[0x24];Handle_801F7F10 handle;};struct EventVisitObject{char unknown00[0x130];Handle_801F7F10 parent;};struct EventVisitOwner{char unknown00[0x38];unsigned long long flags;char unknown40[0x30];Handle_801F7F10 query;};struct EventVisitStorage{char unknown00[8];};struct EventVisitQuery:EventVisitStorage{
virtual void slot8();
virtual void slotC();
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
virtual void slot78();
virtual void slot7C();
virtual void slot80();
virtual void slot84();
virtual void slot88();
virtual void slot8C();
virtual void slot90();
virtual void slot94();
virtual int getCode(const Handle_801F7F10&);
};
struct EventVisitEntry{char*object;char unknown04[8];signed char generation;char unknown0D[3];signed char getGeneration()const{return generation;}};struct EventVisitManager{char unknown00[8];EventVisitEntry*entries;};extern "C"{extern struct{char unknown00[0x118];EventVisitManager*manager;}lbl_801E9D24;extern char lbl_8028F698[];unsigned long fn_801F7EB8(const void*);void fn_8023F744(void*,void*);void fn_802073E8(void*,int,void*,float);void fn_8028FD50(void*,void*,unsigned long);}
inline unsigned long resolveEventVisit(const Handle_801F7F10&h){int index=h.bits.index;EventVisitManager*m=lbl_801E9D24.manager;int generation=m->entries[index].getGeneration();if(generation==h.bits.generation)return (unsigned long)m->entries[index].object;return 0;}
struct EventVisitArray{int count,capacity;EventVisitElement*data;EventVisitArray(){count=0;capacity=0;data=0;}EventVisitElement&get(int i){return data[i];}void storage(){if(data){fn_8028FD50(lbl_8028F698,data,capacity*sizeof(EventVisitElement));data=0;}}~EventVisitArray(){if(data){for(int i=0;i<count;++i)data[i].~EventVisitElement();storage();data=0;}}};
extern "C" void fn_8021FE84(EventVisitSelf*self,Handle_801F7F10*input,int event){if(fn_801F7EB8(&self->handle)){EventVisitArray array;fn_8023F744((void*)resolveEventVisit(*input),&array);EventVisitOwner*owner;int offset,i;for(i=0,offset=0;i<array.count;offset+=4,++i){const Handle_801F7F10&handle=*(EventVisitElement*)((char*)array.data+offset);EventVisitObject*object=(EventVisitObject*)resolveEventVisit(handle);owner=(EventVisitOwner*)resolveEventVisit(object->parent);if(owner&&(owner->flags&0x400000ULL)){int code=((EventVisitQuery*)resolveEventVisit(owner->query))->getCode(handle);fn_802073E8((void*)resolveEventVisit(self->handle),event,owner,(float)code);}}}}
