typedef unsigned long Word;
struct Handle_801F7F10 { union {Word word;struct {signed int tag:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct Node;struct Entry{Node*object;Word unknown04,unknown08;signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};struct Manager{int count,capacity;Entry*entries;};
struct SceneRecord{char unknown00[0x14];Handle_801F7F10 handle;char unknown18[0x34];};struct Service{char unknown00[8];const Handle_801F7F10*handle;};struct Context{char unknown00[0x114];SceneRecord*records;Manager*manager;Service*service;};
extern "C"{extern Context lbl_801E9D24;extern char lbl_801EF5C8[];void fn_801EF610(void*,void*);void fn_801F86C8(Manager*,const Handle_801F7F10*,short);}
struct Handle_8001FF78:Handle_801F7F10 {Handle_8001FF78(){word=0;}~Handle_8001FF78(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80020C04:Handle_8001FF78 {Handle_80020C04(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_80020C04(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Zero1_AF08:Handle_801F7F10{Zero1_AF08(){word=0;}~Zero1_AF08(){}};struct Zero2_AF08:Zero1_AF08{Zero2_AF08(){word=0;}~Zero2_AF08(){}};struct Zero3_AF08:Zero2_AF08{Zero3_AF08(){word=0;}~Zero3_AF08(){}};struct Zero4_AF08:Zero3_AF08{Zero4_AF08(){word=0;}~Zero4_AF08(){}};
struct Handle_80075D64:Zero4_AF08 {Handle_80075D64(){word=0;}~Handle_80075D64(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}Handle_80075D64&operator=(const Handle_80075D64&h){fn_801F86C8(lbl_801E9D24.manager,this,-1);word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);return*this;}};
struct Handle_80027614:Zero1_AF08 {Handle_80027614(){word=0;}~Handle_80027614(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Copy27614_AF08:Handle_80027614 {Copy27614_AF08(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Copy27614_AF08(){}};
struct Record{char opaque[0x44];};extern "C"{void fn_8007B464(void*);void __construct_array(void*,void(*)(void*),void*,Word,Word);}
struct HandleOwner_8007B3C8{int selected;Handle_80075D64 handle;char unknown08[0x14];Record records[4];HandleOwner_8007B3C8(){__construct_array(records,fn_8007B464,0,sizeof(Record),4);selected=-1;handle=Handle_80075D64();}~HandleOwner_8007B3C8(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Vec{float x,y,z;Vec(){}Vec(float a,float b,float c):x(a),y(b),z(c){}Vec(const Vec&v):x(v.x),y(v.y),z(v.z){}Vec&operator=(const Vec&v){x=v.x;y=v.y;z=v.z;return*this;}};
struct Transform{char unknown00[0x30];Vec position;};
struct NodePrefix{char unknown00[8];};struct Node:NodePrefix{virtual void slot8();virtual void slotC();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1C();virtual void slot20();virtual void slot24();virtual void slot28();virtual void slot2C();virtual void slot30();virtual void slot34();virtual void slot38();virtual void slot3C();virtual void slot40();virtual void slot44();virtual void slot48();virtual void slot4C();virtual void slot50();virtual void slot54();virtual void slot58();virtual void slot5C();virtual void slot60();virtual void slot64();virtual void slot68();virtual void slot6C();virtual void slot70();virtual void slot74();virtual void slot78();virtual void slot7C();virtual void slot80();virtual void slot84();virtual void slot88();virtual void slot8C();virtual void slot90();virtual void slot94();virtual void slot98();virtual void slot9C();virtual void slotA0();virtual void slotA4();virtual void slotA8();virtual void slotAC();virtual void slotB0();virtual void slotB4();virtual void slotB8();virtual void slotBC();virtual void slotC0();virtual void slotC4();virtual void slotC8();virtual void slotCC();virtual void slotD0();virtual void slotD4();virtual void slotD8();virtual void slotDC();virtual void slotE0();virtual void slotE4();virtual void slotE8();virtual void slotEC();virtual void slotF0();virtual void slotF4();virtual void slotF8();virtual void slotFC();virtual void slot100();virtual void slot104();virtual void slot108();virtual void slot10C();virtual void slot110();virtual void slot114();virtual void slot118();virtual void slot11C();virtual void slot120();virtual void slot124();virtual void slot128();virtual void slot12C();virtual void slot130();virtual void slot134();virtual void slot138();virtual void slot13C();virtual Word selection();char unknown0C[0x10];Handle_801F7F10 handle1C;char unknown20[0x98];float valueB8;char unknownBC[0x68];Transform*transform;char unknown128[0xD4];Vec position;};
inline Node*resolve(const Handle_801F7F10&h){int index=h.bits.index;Manager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.bits.tag?m->entries[index].object:0;}
struct Owner{char unknown00[0x20];int index;Handle_801F7F10 handle;char unknown28[0xC4];float amount;char unknownF0[4];Vec current;char unknown100[0x18];Vec previous;char unknown124[0x58];int active;};
/* Both original dispatcher branches write distance at +0x3C. */
struct Query{signed char flag;char unknown01[0x1B];float first,second;char unknown24[0x14];float last;float distance;};
extern "C"{void fn_80076D98(Owner*,Vec*);signed char fn_80269DE0(Node*,const Vec*,HandleOwner_8007B3C8*,Word);int fn_80242C34(Node*,Vec*,const Vec*,const HandleOwner_8007B3C8*,Query*);float fn_80079C34(Owner*);float fn_80285124(float,float);void fn_80078D88(Owner*,Vec*);extern const float lbl_80378A64,lbl_80378A68,lbl_803789A8,lbl_8037899C,lbl_803789EC,lbl_803789AC;}
/* This inline scope owns the copied handle through resolution. */
inline Node*copyResolve(const Handle_801F7F10&h){Copy27614_AF08 held(h);return resolve(held);}
extern "C" void fn_8007AF08(Owner*self){
 const Handle_801F7F10&source=*lbl_801E9D24.service->handle;Handle_80020C04 held(source);
 HandleOwner_8007B3C8 result;
 Node*target=resolve(self->handle);Vec position;fn_80076D98(self,&position);Node*service=resolve(held);
 if(fn_80269DE0(service,&position,&result,target->selection())){
  Node*mesh=resolve(result.handle);Query query;query.flag=0;Vec from(target->position);fn_80242C34(mesh,&position,&from,&result,&query);
  if(query.first<=lbl_80378A64){
   float value=query.second;const Handle_801F7F10&input=resolve(lbl_801E9D24.records[self->index].handle)->handle1C;Node*actor=copyResolve(input);actor->valueB8=value;
   float amount;if(query.last<lbl_80378A68){float scaled=lbl_8037899C;float first=query.last-lbl_803789A8;float second=fn_80079C34(self);if(lbl_8037899C!=first||lbl_8037899C!=second)scaled=lbl_803789EC*fn_80285124(first,second);amount=scaled;}else amount=lbl_803789AC;
   if(amount<=self->amount)self->amount=amount;else self->amount=amount;self->active=1;
  }else{
   if(self->active){self->active=0;fn_80078D88(self,&self->previous);}
   const Vec&v=resolve(lbl_801E9D24.records[self->index].handle)->transform->position;self->previous=Vec(v.x,v.y,v.z);self->current=self->previous;
  }
 }else{self->active=1;self->amount=lbl_803789AC;}
}
