/* Actor resource-state/position dispatch; see docs/notes/game-early-actor-resource-state.md. */
typedef unsigned long Word;
struct Handle{union{Word value;struct{signed int tag:8,index:24;}bits;};};
struct Vec3{float x,y,z;void set(float a,float b,float c){x=a;y=b;z=c;}Vec3&operator=(const Vec3&v){set(v.x,v.y,v.z);return*this;}};
struct Transform{char unknown00[0x30];Vec3 position;};
struct Controller{char unknown00;};
struct Prefix{char unknown00[8];};
struct Node:Prefix{
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
virtual void slot78();
virtual void slot7C();
virtual void slot80();
virtual void slot84();
virtual void slot88();
virtual void slot8C();
virtual void slot90();
virtual void slot94();
virtual void slot98();
virtual const Handle&get(int);
char unknown0C[0x64];Handle actor;char unknown74[0x3C];Handle*child;char unknownB4[0x6C];Word flags;Transform*transform;char unknown128[0x1F0];Controller controller;char unknown319[0x2F];Vec3 position;signed char mode;
};
struct Entry{Node*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct Manager{int count,capacity;Entry*entries;};
struct Related{char unknown00[0x1C];Handle*handle;};
extern "C" struct Context{char unknown00[0x118];Manager*manager;char unknown11C[0x20];Related*related;}lbl_801E9D24;
inline Node*resolve(const Handle&h){int index=h.bits.index;Manager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();if(tag==h.bits.tag)return m->entries[index].object;return 0;}
struct Timer{char unknown00[0x24];float value;char unknown28[0x98];float current;float getValue()const{return value;}};
struct State{char unknown00[8];Node*actor;void*control;char unknown10[4];Timer*timer;};
extern "C"{signed char fn_8025E9FC(void*,int);void fn_8023DE28(Node*);void fn_8007D6A0(Controller*,int);signed char fn_8007D604(Controller*,int);Word fn_801F7EB8(const Handle*);}
extern "C"void fn_800264C4(State*self){
 if(fn_8025E9FC(self->control,0xBC)){
  resolve(self->actor->get(0))->flags|=0x100000;
  self->actor->mode=1;
  fn_8023DE28(resolve(self->actor->get(0)));
  self->actor->position=resolve(self->actor->get(0))->transform->position;
  fn_8007D6A0(&self->actor->controller,0);
 }else if(fn_8025E9FC(self->control,0xBB)){
  resolve(self->actor->get(0))->flags|=0x100000;
  fn_8023DE28(resolve(self->actor->get(0)));
 }else if(self->timer->current==self->timer->getValue())fn_8007D6A0(&self->actor->controller,0);
 if(resolve(self->actor->get(0))->flags&0x100000){
  const Handle*h=&resolve(*resolve(*lbl_801E9D24.related->handle)->child)->actor;
  Node*actor;if(fn_801F7EB8(h))actor=resolve(*h);else actor=0;
  if(!fn_8007D604(&actor->controller,0x16)&&!self->actor->mode)resolve(self->actor->get(0))->flags&=~0x100000;
 }
}
