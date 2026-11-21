/* Queued agent events: mode codes 5/6, spawn-and-track (0x1B), retire tracked (0x1C),
 * the 0x8D state machine on the target's state byte and the 0x85 hand-off check.
 * Distinct StateView<N> handle views reproduce the original per-check handle reloads. */
typedef unsigned long Word;typedef unsigned long long Wide;
struct Handle_801F7F10{union{Word word;struct{signed int tag:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct Manager;
extern "C"{extern char lbl_801EF5C8[];extern char lbl_8028F698[];void fn_801EF610(void*,void*);void fn_801F86C8(Manager*,const Handle_801F7F10*,int);Word fn_801F7EB8(const Handle_801F7F10*);
 void*fn_8028FAF4(void*,void*,int,int);void*fn_8028FF24(void*,int);void fn_8028FD50(void*,void*,int);void*memcpy(void*,const void*,unsigned long);}
inline void*operator new(unsigned long,void*p){return p;}
struct Key{Word value;bool operator==(const Key&o)const{return value==o.value;}};
struct NodePrefix{char unknown00[8];};
struct Node:NodePrefix{
 virtual void slot02();virtual void slot03();virtual void slot04();virtual void slot05();virtual void slot06();virtual void slot07();virtual void slot08();virtual void slot09();virtual void slot10();virtual void slot11();virtual void slot12();
 virtual void activate();
 virtual void retire();
 virtual void slot15();virtual void slot16();virtual void slot17();virtual void slot18();virtual void slot19();virtual void slot20();virtual void slot21();virtual void slot22();virtual void slot23();virtual void slot24();virtual void slot25();virtual void slot26();virtual void slot27();virtual void slot28();virtual void slot29();
 virtual void bind(Node*,Word);
 char unknown0C[0x2C];Wide flags;char unknown40[0x20];Key key;};
struct State{char unknown00[0x415];unsigned char state;};
struct Counter{char unknown00[1];};
struct Target{char unknown00[0x1AC];Handle_801F7F10 handle;char unknown1B0[0x168];Counter counter;};
struct Plot{char unknown00[0xA4];Handle_801F7F10*target;};
struct Plots{char unknown00[0x1C];Handle_801F7F10*handle;};
struct Entry{void*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct Manager{int count,capacity;Entry*entries;};
struct Scene{char unknown00[0x15058];void*first;};
extern "C" struct Context{char unknown00[0x118];Manager*manager;char unknown11C[8];Scene*scene;char unknown128[0x14];Plots*plots;}lbl_801E9D24;
inline void*resolve(const Handle_801F7F10&h){int index=h.bits.index;signed char t=h.bits.tag;Manager*m=lbl_801E9D24.manager;signed char tag=m->entries[index].getTag();if(tag==t)return m->entries[index].object;return 0;}
struct SE{State*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};struct SM{int count,capacity;SE*entries;};
template<int N>struct StateView{signed int tag:8,index:24;};
template<int N>inline State*resolveState(const Handle_801F7F10&handle){const StateView<N>&h=(const StateView<N>&)handle;int index=h.index;signed char t=h.tag;SM*m=(SM*)lbl_801E9D24.manager;signed char tag=m->entries[index].getTag();if(tag==t)return m->entries[index].object;return 0;}
struct Handle_80020478:Handle_801F7F10{Handle_80020478(){word=0;}~Handle_80020478(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80020834:Handle_80020478{Handle_80020834(){word=0;}Handle_80020834(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}Handle_80020834(const Handle_80020834&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_80020834(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80024844:Handle_80020834{Handle_80024844(){word=0;}Handle_80024844(const Handle_80020834&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}Handle_80024844(const Handle_80024844&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_80024844(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}
 Handle_80024844&operator=(const Handle_80024844&h){fn_801F86C8(lbl_801E9D24.manager,this,-1);word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);return*this;}};
struct Zero1_373BC:Handle_801F7F10{Zero1_373BC(){word=0;}~Zero1_373BC(){}};
struct Zero2_373BC:Zero1_373BC{Zero2_373BC(){word=0;}~Zero2_373BC(){}};
struct Zero3_373BC:Zero2_373BC{Zero3_373BC(){word=0;}~Zero3_373BC(){}};
struct Handle_80025BF4:Zero3_373BC{Handle_80025BF4(){word=0;}~Handle_80025BF4(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80025B74:Handle_80025BF4{Handle_80025B74(){word=0;}~Handle_80025B74(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80038014:Handle_80025B74{Handle_80038014(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}Handle_80038014(const Handle_80038014&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_80038014(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80021C40:Handle_801F7F10{Handle_80021C40(){word=0;}~Handle_80021C40(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80021BCC:Handle_80021C40{Handle_80021BCC(){word=0;}~Handle_80021BCC(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80021B54:Handle_80021BCC{Handle_80021B54(){word=0;}~Handle_80021B54(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct HandleArray{int count,capacity;Handle_80024844*data;
 void push(const Handle_80024844&h){
  if(count+1>capacity){int n=capacity+8;
   if(n){if(data)data=(Handle_80024844*)fn_8028FAF4(lbl_8028F698,data,capacity*4,n*4);else data=(Handle_80024844*)fn_8028FF24(lbl_8028F698,n*4);}
   else if(data){fn_8028FD50(lbl_8028F698,data,capacity*4);data=0;}
   capacity+=8;}
  new(&data[count++])Handle_80024844(h);}
 void remove(int i){(&data[i])->~Handle_80024844();memcpy(&data[i],&data[i]+1,(--count-i)*4);}
};
struct Event{char unknown00[8];Key key;char unknown0C[0x18];Word value;};
struct SelfPrefix{char unknown00[8];};
struct Self:SelfPrefix{
 virtual void slot02();virtual void slot03();virtual void slot04();virtual void slot05();virtual void slot06();virtual void slot07();virtual void slot08();virtual void slot09();virtual void slot10();virtual void slot11();virtual void slot12();virtual void slot13();
 virtual void finish();
 virtual void slot15();virtual void slot16();virtual void slot17();virtual void slot18();virtual void slot19();virtual void slot20();virtual void slot21();virtual void slot22();virtual void slot23();virtual void slot24();virtual void slot25();
 virtual void setMode(int);
 char unknown0C[0x1C];Handle_801F7F10 owner;float time;char unknown30[0x28];Handle_801F7F10 source;char unknown5C[0x14];Handle_801F7F10 target;char unknown74[0x14];HandleArray items;
};
struct Name{Word word;};
extern "C"{signed char fn_8025E9FC(Self*,int);Event*fn_8025E548(Self*);void fn_80286058(Self*,int);Handle_80024844 fn_80058778(void*,const Name&,int);void fn_802554F4(Node*);
 void fn_80038098(State*,const Handle_801F7F10&);void fn_80257828(Self*,int,int,int);void fn_80255D88(Self*,int,int,int,int);void fn_8007D6A0(Counter*,int);extern const float lbl_80378458;}
extern "C" void fn_800373BC(Self*self){
 if(fn_8025E9FC(self,5))self->setMode(0x86);
 if(fn_8025E9FC(self,6))self->setMode(0);
 if(fn_8025E9FC(self,0x1B)){
  Handle_80024844 node;
  while(fn_8025E9FC(self,0x1B)){
   if(self->time>=lbl_80378458)return;
   Event*event=fn_8025E548(self);
   node=fn_80058778(lbl_801E9D24.scene->first,*(Name*)&event->key,1);
   if(fn_801F7EB8(&node)){
    self->items.push(node);
    ((Node*)resolve(node))->bind((Node*)resolve(self->source),event->value);
    fn_802554F4((Node*)resolve(node));
    ((Node*)resolve(node))->flags|=0x20000ULL;
    ((Node*)resolve(node))->activate();
   }
   fn_80286058(self,0x1B);
  }
 }
 if(fn_8025E9FC(self,0x1C)){
  Handle_80024844 unused;
  while(fn_8025E9FC(self,0x1C)){
   if(self->time>=lbl_80378458)return;
   Event*event=fn_8025E548(self);
   for(int i=0;i<self->items.count;i++){
    if(((Node*)resolve(self->items.data[i]))->key==event->key){
     ((Node*)resolve(self->items.data[i]))->retire();
     self->items.remove(i);
     break;
    }
   }
   fn_80286058(self,0x1C);
  }
 }
 if(fn_8025E9FC(self,0x8D)){
  if(resolveState<1>(self->target)->state==4)self->finish();
  else if(resolveState<2>(self->target)->state==3){
   fn_80038098((State*)resolve(self->target),Handle_80021B54());
   resolveState<1>(self->target)->state=4;
   fn_80257828(self,0x20,0x8D,0);
   fn_80255D88(self,0x25,0xF,0,0);
   Target*t=(Target*)resolve(*((Plot*)resolve(*lbl_801E9D24.plots->handle))->target);
   if(fn_801F7EB8(&t->handle))fn_8007D6A0(&t->counter,0x1C);
  }else if(resolveState<3>(self->target)->state==2){
   resolveState<4>(self->target)->state=3;
   fn_80255D88(self,0x24,0xF,0,0);
   fn_80257828(self,0x9B,0x8D,0);
  }
 }
 if(resolveState<1>(self->target)->state!=0&&resolveState<2>(self->target)->state!=4&&fn_8025E9FC(self,0x85)){
  Handle_80020834 owner=Handle_80020834(self->owner);
  if(!(((Node*)resolve(owner))->flags&0x2000000ULL)){
   Target*t=(Target*)resolve(*((Plot*)resolve(*lbl_801E9D24.plots->handle))->target);
   const Handle_801F7F10&source=t->handle;Handle_80038014 current=Handle_80038014(source);
   const Handle_801F7F10&target=self->target;
   if(resolve(current)!=resolve(Handle_80038014(target))){
    resolveState<1>(self->target)->state=4;
    fn_80257828(self,0x20,0x8D,0);
    fn_80255D88(self,0x25,0,0,0);
   }
  }
 }
}
