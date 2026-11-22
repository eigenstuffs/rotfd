typedef unsigned long Word;
struct Handle_801F7F10{union{Word word;struct{signed int tag:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct Node;struct Entry{Node*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};struct Manager{int count,capacity;Entry*entries;};
extern "C" struct Context{char unknown00[0x118];Manager*manager;}lbl_801E9D24;
extern "C"{extern char lbl_801EF5C8[];void fn_801EF610(void*,void*);void fn_801F86C8(Manager*,const Handle_801F7F10*,short);}
struct Handle_8001FF78:Handle_801F7F10{Handle_8001FF78(){word=0;}~Handle_8001FF78(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80027528:Handle_8001FF78{Handle_80027528(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}Handle_80027528(const Handle_80027528&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_80027528(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Prefix{char unknown00[8];};
struct Node:Prefix{
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
virtual void stop40(int);
virtual void stop44(int);
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
virtual void slot98();
virtual const Handle_801F7F10& getChild(int);
char unknown0C[0x14];Handle_801F7F10 handle;char unknown24[0xFC];Word flags;const Handle_801F7F10&getHandle()const{return handle;}
};
inline Node*resolve(const Handle_801F7F10&h){int index=h.bits.index;Manager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.bits.tag?m->entries[index].object:0;}
struct Vec{float x,y,z;Vec(){}Vec(float a,float b,float c):x(a),y(b),z(c){}Vec&operator=(const Vec&v){x=v.x;y=v.y;z=v.z;return*this;}};
struct Owner{char unknown00[0x24];Handle_801F7F10 handle;char unknown28[0xA0];int counter;char unknownCC[4];int mode;char unknownD4[4];float d8,dc,e0,e4;unsigned char first,second;char unknownEA[2];float ec,f0;Vec position;char unknown100[0xC];unsigned char active;char unknown10D[0xB];Vec target;char unknown124[0x84];Vec previous,stored;float c0,c4;char unknown1C8[4];float cc,d0,d4,d8second;};
extern "C"{void fn_80076D98(Owner*,Vec*);void fn_80076F60(Owner*);extern const float lbl_8037899C,lbl_803789A4,lbl_803789A8,lbl_803789AC,lbl_803789B0,lbl_803789B4,lbl_803789CC,lbl_803789D0,lbl_803789D4;}
extern "C" void fn_8007626C(Owner*self,int mode){
 if(self->mode==mode)return;self->mode=mode;
 switch(mode){
 case 2:{
  self->d0=lbl_803789B0;self->d4=lbl_803789B4;
  self->d8=lbl_8037899C;self->dc=lbl_803789CC;self->e0=lbl_803789D0;self->first=0;self->second=0;self->f0=lbl_8037899C;self->active=1;self->e4=lbl_803789D4;self->counter=70;
  Node*node=resolve(resolve(self->handle)->getChild(0));node->flags&=~0x40000UL;
  Vec point;fn_80076D98(self,&point);Vec target(point);target.y+=lbl_803789CC;self->target=target;self->position=self->target;
  Handle_80027528 held(node->getHandle());resolve(held)->stop40(-1);node->flags|=0x40000UL;fn_80076F60(self);
  break;
 }
 case 0:{
  self->first=0;self->f0=lbl_8037899C;self->second=0;self->ec=lbl_803789AC;self->active=0;self->e4=lbl_803789A8;self->counter=70;
  Handle_80027528 held(resolve(resolve(self->handle)->getChild(0))->getHandle());resolve(held)->stop44(-1);break;
 }
 case 1:{
  self->previous=self->position;self->d8=lbl_8037899C;self->dc=lbl_803789A4;self->e0=lbl_8037899C;self->first=0;self->second=0;self->active=0;break;
 }
 case 3:{
  self->d8second=self->cc;self->d0=self->c0;self->d4=self->c4;
  self->d8=lbl_8037899C;self->dc=lbl_803789CC;self->e0=lbl_803789D0;self->first=0;self->second=0;self->f0=lbl_8037899C;self->active=1;self->e4=lbl_803789D4;self->counter=70;
  Node*node=resolve(resolve(self->handle)->getChild(0));self->target=self->stored;self->position=self->target;
  Handle_80027528 held(node->getHandle());resolve(held)->stop40(-1);fn_80076F60(self);break;
 }
 case 4:self->previous=self->position;break;
 }
}
