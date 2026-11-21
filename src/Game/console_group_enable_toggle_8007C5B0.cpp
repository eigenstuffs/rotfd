/* Console-selected service group enable toggle (fn_8007C5B0). Based on the earlier
 * scratch/sdk_scene_actor_group_toggle_8007c5b0 reconstruction; the resolve helper uses the
 * ActorIndex/matchesTag form from owner_handle_selection_80030A08.cpp, which fixes the
 * register coloring of the CSE'd owner lookups in the loop conditions. */
typedef unsigned long Word;
struct Handle_801F7F10{union{Word word;struct{signed int tag:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct Point{float x,y,z;void set(float a,float b,float c){x=a;y=b;z=c;}Point(const Point&p){set(p.x,p.y,p.z);}};
struct Node;struct ActorIndex{int value;ActorIndex(int v):value(v){}operator const int&()const{return value;}};struct Entry{Node*object;Word unknown04,unknown08;signed char tag;char unknown0D[3];bool matchesTag(signed char t)const{return tag==t;}};struct EntryArray{Entry*p;Entry&operator[](int i)const{return p[i];}};struct Manager{int count,capacity;EntryArray entries;};
struct Console{char unknown00[0x860];int state;char unknown864[0x41];signed char enabled;char unknown8A6[0x12];float selection;};
struct Records{char unknown00[0x214];signed char count;const Handle_801F7F10&at(int i)const{return *(const Handle_801F7F10*)((const char*)this+i*0x4C+0x14);}};
struct Service{Handle_801F7F10 targets[4];signed char enabled[12];const Handle_801F7F10*owners;};
struct Context{char unknown00[0x110];Console*console;Records*records;Manager*manager;char unknown11C[0x20];Service*service;};
extern "C"{extern Context lbl_801E9D24;extern char lbl_801EF5C8[];void fn_801EF610(void*,void*);void fn_801F86C8(Manager*,const Handle_801F7F10*,short);Word fn_801F7EB8(const Handle_801F7F10*);int fn_801FF834(Service*,int);}
struct Handle_8001FF78:Handle_801F7F10{Handle_8001FF78(){word=0;}~Handle_8001FF78(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80020C04:Handle_8001FF78{Handle_80020C04(){word=0;}~Handle_80020C04(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_8002B67C:Handle_801F7F10{Handle_8002B67C(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_8002B67C(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80021BCC:Handle_8001FF78{Handle_80021BCC(){word=0;}~Handle_80021BCC(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80020834:Handle_8001FF78{Handle_80020834(){word=0;}~Handle_80020834(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_8002D518:Handle_80020834{Handle_8002D518(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_8002D518(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_8002D590:Handle_80021BCC{Handle_8002D590(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_8002D590(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80020B90:Handle_8001FF78{Handle_80020B90(){word=0;}Handle_80020B90(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_80020B90(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}Handle_80020B90&operator=(const Handle_80020B90&h){fn_801F86C8(lbl_801E9D24.manager,this,-1);word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);return*this;}};
struct Zero1_7C5B0:Handle_801F7F10{Zero1_7C5B0(){word=0;}~Zero1_7C5B0(){}};struct Zero2_7C5B0:Zero1_7C5B0{Zero2_7C5B0(){word=0;}~Zero2_7C5B0(){}};struct Zero3_7C5B0:Zero2_7C5B0{Zero3_7C5B0(){word=0;}~Zero3_7C5B0(){}};
struct Handle_80025BF4:Zero3_7C5B0{Handle_80025BF4(){word=0;}~Handle_80025BF4(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80025B74:Handle_80025BF4{Handle_80025B74(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_80025B74(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
extern "C"{void*__ct__19HandleCopy_80040B14FRC15Handle_801F7F10(void*,const Handle_801F7F10&);void*__ct__19HandleCopy_80040920FRC15Handle_801F7F10(void*,const Handle_801F7F10&);}
struct Object_80040AA4{Word word;Object_80040AA4(const Handle_801F7F10&h,int){__ct__19HandleCopy_80040B14FRC15Handle_801F7F10(this,h);}Object_80040AA4(const Handle_801F7F10&h){__ct__19HandleCopy_80040920FRC15Handle_801F7F10(this,h);}~Object_80040AA4();const Handle_801F7F10&handle()const{return *(const Handle_801F7F10*)this;}};
struct Transform{char unknown00[0x30];Point position;};struct Prefix{char unknown00[8];};struct Node:Prefix{
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
virtual const Handle_801F7F10*getHandle(int);
virtual void slot7C();
virtual void slot80();
virtual void slot84();
virtual void slot88();
virtual void slot8C();
virtual void slot90();
virtual void slot94();
virtual void slot98();
virtual const Handle_801F7F10*getRelated(int);
virtual int getType();
char unknown0C[0x14];int type;char unknown24[0x4C];Handle_801F7F10 pose;char unknown74[0x24];const Handle_801F7F10*groups;char unknown9C[8];const Handle_801F7F10*members;char unknownA8[8];const Handle_801F7F10*children;char unknownB4[0x28];int count;char unknownE0[0x44];Transform*transform;};
inline Node*resolve(const Handle_801F7F10&h){Manager*m=lbl_801E9D24.manager;const ActorIndex index(h.bits.index);const signed char tag=h.bits.tag;if(m->entries[index].matchesTag(tag))return m->entries[index].object;return 0;}
extern "C"{void fn_80201B14(Node*,int);void fn_80201A14(Node*,int);void fn_8023D100(Node*,const Point&);void fn_802139D8(Node*);void fn_80213A18(Node*);}
extern "C" int fn_8007C5B0(){
 if(lbl_801E9D24.console->state<2)return 0;
 if(!lbl_801E9D24.console->enabled)return 0;
 int index=(int)lbl_801E9D24.console->selection;
 if(index>=lbl_801E9D24.records->count)return 0;
 Handle_80020C04 unused;
 int slot=fn_801FF834(lbl_801E9D24.service,index);if(slot<0)return 0;
 const Handle_801F7F10&original=lbl_801E9D24.service->owners[slot];Handle_8002B67C owner(original);
 signed char enabled=lbl_801E9D24.service->enabled[index];
 if(fn_801F7EB8(&owner)){
  int i;
  for(i=0;i<resolve(owner)->count;++i){
   if(fn_801F7EB8(&resolve(owner)->children[i])&&resolve(resolve(owner)->children[i])->getType()==index){
    if(enabled)fn_80201B14(resolve(owner),i);else fn_80201A14(resolve(owner),i);
   }
  }
  if(enabled){
   const Handle_801F7F10&original1=resolve(owner)->groups[(unsigned int)index];Handle_8002D518 group(original1);
   const Handle_801F7F10&original2=*resolve(group)->getHandle(index);Handle_8002D590 resource(original2);
   const Handle_801F7F10&original3=lbl_801E9D24.records->at(resolve(resource)->type);Handle_80020B90 configured(original3);
   Handle_80020B90 positionOwner;
   if(fn_801F7EB8(&configured))positionOwner=configured;
   if(!fn_801F7EB8(&positionOwner))return 0;
   Point position(resolve(positionOwner)->transform->position);
   if(fn_801F7EB8(&owner)){
    Object_80040AA4 child(Object_80040AA4(resolve(owner)->children[0],0).handle());
    const Handle_801F7F10&original4=resolve(child.handle())->pose;Handle_80025B74 related(original4);
    if(fn_801F7EB8(&related)){
     const Handle_801F7F10&original5=*resolve(related)->getRelated(0);Handle_80020B90 target(original5);
     fn_8023D100(resolve(target),position);
    }
   }
   fn_802139D8(resolve(lbl_801E9D24.service->targets[index]));
  }else fn_80213A18(resolve(lbl_801E9D24.service->targets[index]));
  if(resolve(owner)->count!=0&&i==resolve(owner)->count){
   for(int j=0;j<resolve(owner)->count;++j){
    if(fn_801F7EB8(&resolve(owner)->members[j])){
     if(enabled)fn_80201B14(resolve(owner),j);else fn_80201A14(resolve(owner),j);
    }
   }
  }
 }else{
  if(enabled)fn_802139D8(resolve(lbl_801E9D24.service->targets[index]));else fn_80213A18(resolve(lbl_801E9D24.service->targets[index]));
 }
 lbl_801E9D24.service->enabled[index]=!lbl_801E9D24.service->enabled[index];return 1;
}
