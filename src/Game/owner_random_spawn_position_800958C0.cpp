/* Owner action step: resets the actor's vector at 0x144, wakes the
   controller, and with a random chance wakes the actor returned by
   fn_80059AA4 and places it at the position of the actor's query target.
   The returned handle type has an inline destructor, as in
   actor_random_resource_spawn_8005DD34.cpp. */
struct ActorIndex{int value;ActorIndex(int v):value(v){}operator const int&()const{return value;}};
typedef unsigned long Word;
struct Handle_801F7F10{union{Word word;struct{signed int tag:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct SpawnHandle:Handle_801F7F10{~SpawnHandle(){}};
struct Point{float x,y,z;Point(){}Point(float a,float b,float c):x(a),y(b),z(c){}Point(const Point&o):x(o.x),y(o.y),z(o.z){}};
struct Target{char unknown00[0x30];Point position;};
struct Prefix{char unknown00[8];};
struct Node:Prefix{
 virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1C();virtual void slot20();virtual void slot24();virtual void slot28();virtual void slot2C();virtual void slot30();virtual void slot34();
 char unknown0C[0x2C];unsigned long long flags;
};
struct Entity{char unknown00[0x124];Target*target;};
struct Entry{void*object;char unknown04[8];signed char tag;char unknown0D[3];bool matchesTag(signed char t)const{return tag==t;}};
struct EntryArray{Entry*p;Entry&operator[](int i)const{return p[i];}};
struct Manager{int count,capacity;EntryArray entries;};
struct Primary;
struct Scene{char unknown00[0x15058];Primary*primary;};
extern "C" struct Globals{char unknown00[0x118];Manager*manager;char unknown11C[8];Scene*scene;}lbl_801E9D24;
inline void*resolve(const Handle_801F7F10&h){Manager*m=lbl_801E9D24.manager;const ActorIndex index(h.bits.index);const signed char tag=h.bits.tag;if(m->entries[index].matchesTag(tag))return m->entries[index].object;return 0;}
struct Actor:Prefix{
 virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1C();virtual void slot20();virtual void slot24();virtual void slot28();virtual void slot2C();virtual void slot30();virtual void slot34();virtual void slot38();virtual void slot3C();virtual void slot40();virtual void slot44();virtual void slot48();virtual void slot4C();virtual void slot50();virtual void slot54();virtual void slot58();virtual void slot5C();virtual void slot60();virtual void slot64();virtual void slot68();virtual void slot6C();virtual void slot70();virtual void slot74();virtual void slot78();virtual void slot7C();virtual void slot80();virtual void slot84();virtual void slot88();virtual void slot8C();virtual void slot90();virtual void slot94();virtual void slot98();virtual Handle_801F7F10*query(int);
 char unknown0C[0x138];Point vector144;char unknown150[0x224];float value374;
};
struct Owner{char unknown00[8];Actor*actor;Node*controller;};
extern "C"{float fn_801F1200();SpawnHandle fn_80059AA4(Primary*);void fn_802554F4(Node*);void fn_80254BB4(Node*,const Point&);extern const float lbl_80378C38,lbl_80378C3C;}
extern "C" void fn_800958C0(Owner*self){
 Actor*actor=self->actor;
 float y=actor->value374;
 actor->vector144=Point(lbl_80378C38,y,lbl_80378C38);
 self->controller->flags|=0x20000ULL;
 self->controller->slot34();
 if(fn_801F1200()<lbl_80378C3C){
  Node*node=(Node*)resolve(fn_80059AA4(lbl_801E9D24.scene->primary));
  if(node){
   node->flags|=0x20000ULL;
   node->slot34();
   Target*target=((Entity*)resolve(*self->actor->query(0)))->target;
   Point position(target->position.x,target->position.y,target->position.z);
   fn_80254BB4(node,position);
   fn_802554F4(node);
  }
 }
}
