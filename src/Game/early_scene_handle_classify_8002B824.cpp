typedef unsigned long Word;
extern "C"{extern char lbl_801EF5C8[];void fn_801EF610(void*,void*);void fn_801F86C8(void*,const void*,int);void*fn_801F7EB8(const void*);}
extern "C" struct ClassifyGlobal{char unknown00[0x118];void*manager;}lbl_801E9D24;
struct Handle_801F7F10{union{Word word;struct{signed int tag:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();Handle_801F7F10&operator=(const Handle_801F7F10&h){fn_801F86C8(lbl_801E9D24.manager,this,-1);word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);return*this;}};
struct Handle_8001FF78:Handle_801F7F10{Handle_8001FF78(){word=0;}~Handle_8001FF78(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_8002BA20:Handle_8001FF78{Handle_8002BA20(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_8002BA20(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct ClassifyNode{char unknown00[0x2C];Handle_801F7F10 child;unsigned long long flags;};
struct ClassifyEntry{ClassifyNode*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct ClassifyManager{int count,capacity;ClassifyEntry*entries;};
inline ClassifyNode*resolve(const Handle_801F7F10&h){int index=h.bits.index;ClassifyManager*m=(ClassifyManager*)lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.bits.tag?m->entries[index].object:0;}
struct ClassifyOwnerPrefix{Word unknown00;Handle_801F7F10 member;};
struct ClassifyOwner:ClassifyOwnerPrefix{
virtual void slot0();
virtual void slot1();
virtual void slot2();
virtual void slot3();
virtual void slot4();
virtual void slot5();
virtual void slot6();
virtual void slot7();
virtual void slot8();
virtual void slot9();
virtual void slot10();
virtual void slot11();
virtual void slot12();
virtual void slot13();
virtual void slot14();
virtual void slot15();
virtual void slot16();
virtual void slot17();
virtual void slot18();
virtual void slot19();
virtual void slot20();
virtual void slot21();
virtual void slot22();
virtual void slot23();
virtual void event(int);char unknown0C[0x2C];unsigned long long flags;char unknown40[0x18];Handle_801F7F10 owner;char unknown5C[0x14];Handle_801F7F10 actor;char unknown74[0xC];Handle_801F7F10 target;};
extern "C"{void fn_8025A0A4(ClassifyOwner*,const Handle_801F7F10&);const char*fn_8025318C(ClassifyNode*,int*);int strcmp(const char*,const char*);extern const char lbl_80299FF0[];}
extern "C" void fn_8002B824(ClassifyOwner*self,const Handle_801F7F10&incoming){
self->event(0x86);if(!(self->flags&0x2000000ULL))fn_8025A0A4(self,incoming);self->target=incoming;
const Handle_801F7F10&source=resolve(self->owner)->child;Handle_8002BA20 copy(source);
if(fn_801F7EB8(&copy)){int length;if(strcmp(fn_8025318C(resolve(copy),&length),lbl_80299FF0)==0)self->flags|=0x1000000000000ULL;}
resolve(self->actor)->flags&=~0x200ULL;
}
