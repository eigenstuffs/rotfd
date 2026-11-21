/* Animation channel event application and final-frame dispatch.
 * Partial views retain the observed layout of the shared event/handle records.
 * The borrowed handle lifecycle is implemented by the existing native provider.
 */
typedef unsigned long Word;
typedef unsigned short Half;
struct Handle_801F7F10 {
 union { Word value; struct { signed int tag:8,index:24; } bits; };
 Handle_801F7F10(); ~Handle_801F7F10();
};
struct Target;
struct Index{const int value;Index(int v):value(v){}operator int()const{return value;}};
struct Entry { Target*object; Word unknown04,unknown08; signed char tag; char unknown0D[3]; bool matchesTag(signed char t)const{return tag==t;} Target*getObject()const{return object;} };
struct Entries{Entry*p;Entry&operator[](const Index&i)const{return p[i];}};
struct Manager { int count,capacity; Entries entries; };
struct Event { int command; Word value,argument; float time; void*active[4]; Target*target,*actor,*owner; };
struct EventQueue { char unknown00[0xD8]; Event*events; Word unknownDC; int count;Event*getEvents(){return events;} };
struct Dispatcher;
struct Global { char unknown00[0x118]; Manager*manager; char unknown11C[0x28]; EventQueue*queue; char unknown148[0x10]; Dispatcher*dispatcher; };
extern "C" {
 extern Global lbl_801E9D24;
 Handle_801F7F10 fn_801F8114(Manager*,Word);
 void fn_801F86C8(Manager*,const Handle_801F7F10*,short);
 void*fn_801F7EB8(const Handle_801F7F10*);
 float fn_801F1200();
 extern const float lbl_8037B1E8,lbl_8037B1F8,lbl_8037B1FC;
}
struct EventZeroHandle:Handle_801F7F10 { EventZeroHandle(){value=0;} ~EventZeroHandle(){} };
struct EventHandle:EventZeroHandle {
 EventHandle(const Handle_801F7F10&from){value=from.value;fn_801F86C8(lbl_801E9D24.manager,&from,1);}
 EventHandle(const EventHandle&from){value=from.value;fn_801F86C8(lbl_801E9D24.manager,&from,1);}
 ~EventHandle(){}
};
struct DispatcherStorage { char unknown00[0x7C]; };
struct Dispatcher:DispatcherStorage {
 virtual ~Dispatcher();
 virtual void slot0C();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1C();
 virtual void slot20();virtual void slot24();virtual void slot28();virtual void slot2C();virtual void slot30();
 virtual void slot34();virtual void slot38();virtual void slot3C();virtual void slot40();virtual void slot44();
 virtual void slot48();virtual void slot4C();virtual void slot50();
 virtual void start(const EventHandle&,int,const Handle_801F7F10&,EventHandle);
 virtual void stop(const EventHandle&,const Handle_801F7F10&,float);
};
struct Curve{int unknown00,count;void*items;int unknown0C;};
struct Record4 { Word unknown00;short index;char unknown06[6];Curve position,rotation,scale,actions;Word unknown4C; };
struct Record8 { Word unknown00; short index; char unknown06[0x86]; };
struct Record1 { char unknown00[0x1C]; };
struct Cursor4 { Half a,b,c,flags; };
struct Cursor8 { Half a,b,c,d,e,f,g,h; };
struct Cursor1 { Half value; };
template<class T>struct Array { int count,capacity; T*items; };
struct Active { char unknown00[0xC]; Array<Record4>four; Array<Record8>eight; Array<Record1>one;float duration; };
struct State { Active*active; float age,weight,loopTime; Half loopCount,flags; char unknown14[0x38]; Array<Cursor4>four; Array<Cursor8>eight; Array<Cursor1>one; Word end; };
struct Target { char unknown00[0xC]; union{ unsigned char flags0C; float red; }; float green,blue; char unknown18[8]; Array<EventHandle>actors; Word unknown2C; Array<EventHandle>colors; char unknown3C[0xE4]; Word flags; char unknown124[0xC]; Handle_801F7F10 related;
 void setColor(float r,float g,float b){red=r;green=g;blue=b;}
};
struct Owner { char unknown00[0x20]; State states[4]; Handle_801F7F10 target,second,third,callback; };
inline Target*resolve(const Handle_801F7F10&h){Manager*m=lbl_801E9D24.manager;const Index index(h.bits.index);const signed char tag(h.bits.tag);if(m->entries[index].matchesTag(tag))return m->entries[index].getObject();return 0;}
extern "C" {
 void fn_801AED04(Record4*,Target*,Event*,int*,float,float,float);
 void fn_801AEE70(Record4*,Cursor4*,Target*,Event*,int*,float,float,float);
 void fn_801AE018(Record8*,Cursor8*,Target*,float);
 void fn_801F7880(Record1*,Cursor1*,Target*,float);
 void fn_8023C7C4(Target*,int,int);void fn_8023CA80(Target*,int,int);
 int fn_801F4AC8(EventQueue*,Word*);
 void fn_802073E8(Owner*,int,Target*,float);
}
/* Keep the shared volume scalar addressable; RGB and integer conversion literals
 * belong to these two event consumers and are emitted in their native pool. */
inline const float&eventVolume(){return lbl_8037B1E8;}
extern "C" {extern const float lbl_8037B1E8=1.0f;}
extern "C" short fn_801F72E4(Curve*,Event*,int*,short,float,float,float);
extern "C" void fn_801F7810(Record1*,Target*,float);
/* Emit remaining events when closing a channel before its animation duration. */
extern "C" void fn_80233450(Owner*self,int channel){
 Target*target=resolve(self->target);if(!target)return;
 State*state=&self->states[channel];Active*active=state->active;if(!active)return;
 float duration=active->duration;if(state->age>=duration)return;
 Target*owner=resolve(self->second);Target*related=resolve(owner->related);
 int i;for(i=0;i<active->four.count;++i){
  Record4*record=&active->four.items[i];int index=record->index;
  if(index<target->actors.count){Target*const actor=resolve(target->actors.items[index]);if(actor){
   EventQueue*queue=lbl_801E9D24.queue;Event*event=queue->getEvents();int&counter=queue->count;int eventIndex=counter;
   fn_801F72E4(&record->actions,event,&counter,0,state->age,duration,duration);
   int last=lbl_801E9D24.queue->count;Event*current=event+eventIndex;
   for(;eventIndex<last;++eventIndex,++current){
    current->active[0]=self->states[0].active;current->active[1]=self->states[1].active;
    current->active[2]=self->states[2].active;current->active[3]=self->states[3].active;
    current->target=target;current->actor=actor;current->owner=owner;
    if(current->command==20)fn_8023C7C4(actor,0x2000,1);
    else if(current->command==21)fn_8023CA80(actor,0x2000,1);
    else if(current->command==5)actor->flags|=0x40000;
    else if(current->command==6)actor->flags&=~0x40000;
    else if(current->command==22){
     int colorIndex=fn_801F4AC8(lbl_801E9D24.queue,&current->argument);
     Target*color=resolve(target->colors.items[colorIndex]);
     if(color){int packed=current->value;float r=(float)(packed>>16),g=(float)((packed>>8)&255),b=(float)(packed&255);r*=0.003921569f;g*=0.003921569f;b*=0.003921569f;color->setColor(r,g,b);}
    }else if(current->command==15){
     EventHandle handle=EventHandle(fn_801F8114(lbl_801E9D24.manager,current->value));
     if(fn_801F7EB8(&handle)&& (resolve(handle)->flags0C&2))lbl_801E9D24.dispatcher->stop(handle,self->second,eventVolume());
    }
    if(related)fn_802073E8(self,current->command,related,(float)(eventIndex+0x100));
   }
  }}
 }
 for(i=0;i<active->one.count;++i)fn_801F7810(&active->one.items[i],target,state->age);
}

/* Advance record cursors and apply all events emitted in the requested interval. */
extern "C" void fn_80233944(Owner*self,State*state,Target*target,float before,float end,float duration){
 Active*active=state->active;
 int count=active->four.count;
 Record4*record=active->four.items;
 Cursor4*cursor=state->four.items;
 Target*owner=resolve(self->second);
 Target*related=resolve(owner->related);
 for(int i=0;i<count;++i,++record,++cursor){
  int index=record->index;
  if(index<target->actors.count){
   EventHandle&actorHandle=target->actors.items[index];
   Target*const actor=resolve(actorHandle);
   if(actor){
    EventQueue*queue=lbl_801E9D24.queue;
    Event*event=queue->events;
    int eventIndex=queue->count;
    int*eventCount=&queue->count;
    if(state->flags&0x400)fn_801AED04(record,actor,event,eventCount,before,end,duration);
    else fn_801AEE70(record,cursor,actor,event,eventCount,before,end,duration);
    int last=lbl_801E9D24.queue->count;
    Event*current=event+eventIndex;
    for(;eventIndex<last;++eventIndex,++current){
     current->active[0]=self->states[0].active;current->active[1]=self->states[1].active;
     current->active[2]=self->states[2].active;current->active[3]=self->states[3].active;
     current->target=target;current->actor=actor;current->owner=owner;
     if(current->command==5)actor->flags|=0x40000;
     else if(current->command==6)actor->flags&=~0x40000;
     else if(current->command==14){
      EventHandle handle=EventHandle(fn_801F8114(lbl_801E9D24.manager,current->value));
      lbl_801E9D24.dispatcher->start(handle,15,self->second,actorHandle);
     }else if(current->command==15){
      EventHandle handle=EventHandle(fn_801F8114(lbl_801E9D24.manager,current->value));
      if(fn_801F7EB8(&handle)){
       if(resolve(handle)->flags0C&2)lbl_801E9D24.dispatcher->stop(handle,self->second,eventVolume());
       else lbl_801E9D24.dispatcher->stop(handle,self->second,lbl_8037B1F8);
      }
     }else if(current->command==16){
      if(fn_801F1200()<lbl_8037B1FC){
       EventHandle handle=EventHandle(fn_801F8114(lbl_801E9D24.manager,current->value));
       lbl_801E9D24.dispatcher->start(handle,15,self->second,actorHandle);
      }
     }else if(current->command==20)fn_8023C7C4(actor,0x2000,1);
     else if(current->command==21)fn_8023CA80(actor,0x2000,1);
     else if(current->command==22){
      int colorIndex=fn_801F4AC8(lbl_801E9D24.queue,&current->argument);
      Target*color=resolve(target->colors.items[colorIndex]);
      if(color){int packed=current->value;float r=(float)(packed>>16);float g=(float)((packed>>8)&255);float b=(float)(packed&255);r*=0.003921569f;g*=0.003921569f;b*=0.003921569f;color->setColor(r,g,b);}
     }
     if(related)fn_802073E8(self,current->command,related,(float)eventIndex);
    }
   }
  }
 }
 int count8=active->eight.count;int i8=0;Record8*record8=active->eight.items;Cursor8*cursor8=state->eight.items;
 for(;i8<count8;++i8,++record8,++cursor8){int index=record8->index;if(index<target->colors.count){Target*color=resolve(target->colors.items[index]);if(color)fn_801AE018(record8,cursor8,color,end);}}
 int count1=active->one.count;int i1=0;Record1*record1=active->one.items;Cursor1*cursor1=state->one.items;
 for(;i1<count1;++i1,++record1,++cursor1)fn_801F7880(record1,cursor1,target,end);
}

/* Compile-time layout contracts; these declarations emit no storage. */
typedef char HandleSize[sizeof(Handle_801F7F10)==4?1:-1];
typedef char EntrySize[sizeof(Entry)==16?1:-1];
typedef char EventSize[sizeof(Event)==44?1:-1];
typedef char CurveSize[sizeof(Curve)==16?1:-1];
typedef char Record4Size[sizeof(Record4)==0x50?1:-1];
typedef char Record8Size[sizeof(Record8)==0x8C?1:-1];
typedef char Record1Size[sizeof(Record1)==0x1C?1:-1];
typedef char Cursor4Size[sizeof(Cursor4)==8?1:-1];
typedef char Cursor8Size[sizeof(Cursor8)==16?1:-1];
typedef char Cursor1Size[sizeof(Cursor1)==2?1:-1];
typedef char StateSize[sizeof(State)==0x74?1:-1];
typedef char OwnerSize[sizeof(Owner)==0x200?1:-1];
