/* Resource motion-event dispatch; see docs/notes/game-resource-motion-event-dispatch.md. */
typedef unsigned long Word;typedef unsigned long long Wide;
struct Handle_801F7F10 {union{Word word;struct{signed int tag:8;signed int index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct Context {char unknown00[0x118];void*manager;};
struct ResourceEventZero2_801BE188;
extern "C" {extern Context lbl_801E9D24;void fn_801F86C8(void*,const void*,short);ResourceEventZero2_801BE188 fn_801BE46C(void*);signed char fn_801BD2F8(void*,const Handle_801F7F10&,Word,Word,void*);void fn_80038098(void*,const Handle_801F7F10&);}
struct ResourceEventZero1_801BE188:Handle_801F7F10 {ResourceEventZero1_801BE188(){word=0;}~ResourceEventZero1_801BE188(){}};
struct ResourceEventZero2_801BE188:ResourceEventZero1_801BE188 {ResourceEventZero2_801BE188(){word=0;}~ResourceEventZero2_801BE188(){}};
struct ResourceEventZero3_801BE188:ResourceEventZero2_801BE188 {ResourceEventZero3_801BE188(){word=0;}~ResourceEventZero3_801BE188(){}};
struct ResourceEventCopy1_801BE188:ResourceEventZero1_801BE188 {ResourceEventCopy1_801BE188(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~ResourceEventCopy1_801BE188(){}};
struct Point {float x,y,z;Point(const Point&p):x(p.x),y(p.y),z(p.z){}Point&operator=(const Point&p){x=p.x;y=p.y;z=p.z;return *this;}};
struct Prefix {char unknown00[8];};
struct Owner:Prefix {
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
virtual void move(void*,Word,Word);
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
virtual const Handle_801F7F10&getHandle(int);
virtual void slotA0();
virtual void slotA4();
virtual void slotA8();
virtual void slotAC();
virtual void slotB0();
virtual void slotB4();
virtual void slotB8();
virtual void slotBC();
virtual void slotC0();
virtual void slotC4();
virtual void slotC8();
virtual void slotCC();
virtual void slotD0();
virtual void slotD4();
virtual void slotD8();
virtual void slotDC();
virtual void slotE0();
virtual signed char query(Wide,Word);
virtual void slotE8();
virtual void slotEC();
virtual void slotF0();
virtual void slotF4();
virtual void slotF8();
virtual void slotFC();
virtual void slot100();
virtual void dispatchFirst(void*,Word,Word,Word);
virtual void dispatchSecond(void*,Word,Word,Word,int);
char unknown0C[0x114];Word flags;char unknown124[0x20];Point point;};
struct Entry {Owner*object;char unknown04[8];signed char tag;char unknown0D[3];};
struct Manager {char unknown00[8];Entry*entries;inline Owner*get(const Handle_801F7F10&h){Entry*e=entries+h.bits.index;return e->tag==h.bits.tag?e->object:0;}};
static inline Owner*resolve(const Handle_801F7F10&h){return ((Manager*)lbl_801E9D24.manager)->get(h);}
extern "C" void fn_801BE188(Owner*self,void*other,Word first,Word unused,Word second,Word mode){
 if(self->query(0x4000ULL,mode))self->dispatchFirst(other,first,second,mode);
 if(self->query(0x1000ULL,mode))self->dispatchSecond(other,first,second,mode,0);
 if(self->query(0x10000ULL,mode))self->move(other,second,mode);
 Owner*related=resolve(fn_801BE46C(self));
 if(related){
  Point saved(self->point);
  ResourceEventCopy1_801BE188 copy(related->getHandle(0));
  if(fn_801BD2F8(self,copy,first,second,&saved)){
   Owner*target=resolve(copy);target->flags|=0x40000;target->flags&=~0x4000;
   fn_80038098(self,ResourceEventZero3_801BE188());
   fn_80038098(related,ResourceEventZero3_801BE188());
  }else self->point=saved;
 }
}
