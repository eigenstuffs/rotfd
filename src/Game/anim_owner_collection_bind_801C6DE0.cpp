/* fn_801C6DE0: bind an animation owner to its collection/target/flags handles
 * and, on first use, copy the collection's records into the owner, attach each
 * record's node (named child lookup through the target for unlinked records),
 * relink selected nodes, create the per-index and per-retained "PlayAnim"
 * handle/pair entries, clear the state bytes and finish with the inlined
 * reset (fn_801C6C94 body).
 * Native Handle_801F7F10 ctor/dtor stay external; Zero1/Ref/Child are the
 * zero-initialising inline layers (their weak dtors are discarded at link).
 * Register allocation depends on the resolver shapes: if/return (resolve),
 * conditional-expression (resolveOr) and member-template (resolveMember)
 * variants are used at the original call sites, and the first records.add
 * argument goes through Array::operator[].
 * Flags: GC/1.3.2 -O4,p -Cpp_exceptions off -use_lmw_stmw on (C++, no extab). */
typedef unsigned long Word;
inline void*operator new(unsigned long,void*p){return p;}
struct Handle_801F7F10{union{Word word;struct{signed int tag:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();template<class T>T*get()const;};
struct Entry{void*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct Manager{int count,capacity;Entry*entries;};
struct Context{char unknown00[0x118];Manager*manager;};
extern "C"{
extern Context lbl_801E9D24;
extern char lbl_8028F698[];
extern const char lbl_8037A404[4];
extern const char lbl_802ACAEC[];
extern const float lbl_8037A3D0;
void fn_801F86C8(Manager*,const void*,int);
void*fn_801F7EB8(const Handle_801F7F10*);
Word fn_801F948C(void*,const char*);
void fn_8028FD50(void*,void*,int);
void*fn_8028FAF4(void*,void*,int,int);
void*fn_8028FF24(void*,int);
Handle_801F7F10 fn_801B52EC(Manager*,const char*);
}
template<class T>inline T*Handle_801F7F10::get()const{int index=bits.index;Manager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();if(tag==bits.tag)return (T*)m->entries[index].object;return 0;}
template<class T>inline T*resolveMember(const Handle_801F7F10&h){return h.get<T>();}
template<class T>inline T*resolve(const Handle_801F7F10&h){int index=h.bits.index;Manager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();if(tag==h.bits.tag)return (T*)m->entries[index].object;return 0;}
template<class T>inline T*resolveOr(const Handle_801F7F10&h){int index=h.bits.index;Manager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.bits.tag?(T*)m->entries[index].object:0;}
struct Zero1:Handle_801F7F10{Zero1(){word=0;}~Zero1(){}};
struct Ref:Zero1{
 Ref(){word=0;}
 Ref(const Ref&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}
 Ref(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}
 ~Ref(){}
 Ref&operator=(const Ref&h){fn_801F86C8(lbl_801E9D24.manager,this,-1);word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);return*this;}
};
struct Child:Ref{
 Child(){word=0;}
 Child(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}
 ~Child(){}
 Child&operator=(const Child&h){fn_801F86C8(lbl_801E9D24.manager,this,-1);word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);return*this;}
};
struct Param:Handle_801F7F10{
 Param&operator=(const Param&h){fn_801F86C8(lbl_801E9D24.manager,this,-1);word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);return*this;}
};
struct Name{Word word;Name(const char*text){word=fn_801F948C(this,text);}bool operator!=(const Name&o)const{return word!=o.word;}bool operator==(const Name&o)const{return word==o.word;}};
template<class T>struct Array{
 int count,capacity;T*data;
 void resize(int n){if(n){if(data)data=(T*)fn_8028FAF4(lbl_8028F698,data,capacity*sizeof(T),n*sizeof(T));else data=(T*)fn_8028FF24(lbl_8028F698,n*sizeof(T));}else if(data){fn_8028FD50(lbl_8028F698,data,capacity*sizeof(T));data=0;}}
 T&operator[](int i){return data[i];}
 void grow(){if(count+1>capacity){resize(capacity+16);capacity+=16;}}
 void add(const T&v){grow();new(data+count++)T(v);}
 void add(){grow();new(data+count++)T();}
};
struct Record{Name name;Name key;int link;signed char active;Ref object;Ref h14;Ref retained;};
struct IndexRecord{int index;Word unknown04;Ref h8;Ref hc;Ref h10;};
struct Selected{Word unknown00;short index;char unknown06[0x46];};
struct Collection{char unknown00[0x18];Array<Selected>selected;char unknown24[0xC];Array<Record>records;Array<IndexRecord>indices;};
struct Named{Name name;};
struct Linker{char unknown00[0x130];Ref h130;void setH130(const Handle_801F7F10&p){h130=p;}};
struct NodePrefix{char unknown00[8];};
struct Node:NodePrefix{
 virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1C();virtual void slot20();virtual void slot24();virtual void slot28();virtual void slot2C();virtual void slot30(Ref&,const Ref&);
 char unknown0C[0x10];Ref h1c;Ref h20;
};
struct Target{char unknown00[0x30];Ref h30;};
struct Flagged{char unknown00[0xC];Word flags;};
struct Linked{char unknown00[0x20];Ref related;};
struct OwnerPrefix{char unknown00[0x20];};
struct Owner:OwnerPrefix{
 Array<Child>handles;Array<Ref>pairs;Array<Record>records;Param collection,target,flags;Word unknown50;float time;Word unknown58;int actorIndex;unsigned short flags60;signed char b62,b63,b64,b65;
 void reset();
};
extern "C"{
void fn_802139D8(Owner*);
Ref*fn_80240F28(Node*);
void fn_8023E994(Node*,Ref*,int);
void fn_802408BC(Node*,Ref,int);
Ref fn_8026A494(Target*,const Name&);
void fn_80269FE0(Target*);
void fn_8023D648(Node*);
void fn_8023E1B4(Node*);
void fn_8023232C(Node*,const Ref*);
void fn_8023297C(Node*,const Ref*,int,int);
}
inline void Owner::reset(){
 Collection*resource=resolveOr<Collection>(collection);
 if(resource){
  fn_802139D8(this);
  for(int i=0;i<resource->indices.count;++i)resolve<Flagged>(resolve<Linked>(records.data[resource->indices.data[i].index].object)->related)->flags|=1;
 }
}
extern "C" void fn_801C6DE0(Owner*self,const Param&target,const Param&collection,const Param&flags,int actorIndex){
 self->collection=collection;
 self->actorIndex=actorIndex;
 self->target=target;
 self->flags=flags;
 self->time=lbl_8037A3D0;
 Collection*col=resolve<Collection>(self->collection);
 Target*tgt=resolve<Target>(self->target);
 if(self->records.count==0){
  int i;
  for(i=0;i<col->records.count;i++){
   self->records.add(col->records[i]);
   if(col->records.data[i].active){
    Ref unused(*fn_80240F28(resolve<Node>(col->records.data[i].object)));
   }else{
    Ref obj(col->records.data[i].object);
    fn_8023E994(resolve<Node>(obj),&self->records.data[i].object,0);
    Linker*l=resolveOr<Linker>(self->records.data[i].object);
    l->setH130(flags);
   }
  }
  for(i=0;i<self->records.count;i++){
   if(!self->records.data[i].active){
    if(!fn_801F7EB8(&self->records.data[i].h14)){
     int link=self->records.data[i].link;
     if(link<0){
      const Ref&h30=tgt->h30;
      Ref t(h30);
      if(self->records.data[i].name!=Name(lbl_8037A404))t=fn_8026A494(tgt,self->records.data[i].name);
      fn_802408BC(resolve<Node>(t),self->records.data[i].object,0);
     }else{
      fn_802408BC(resolve<Node>(self->records.data[link].object),self->records.data[i].object,0);
     }
    }else{
     fn_802408BC(resolve<Node>(self->records.data[i].h14),self->records.data[i].object,0);
    }
   }
  }
  for(i=0;i<col->selected.count;i++){
   Node*a=resolve<Node>(self->records.data[col->selected.data[i].index].object);
   Linker*b=resolveMember<Linker>(a->h1c);
   for(int j=0;j<self->records.count;j++){
    if(resolve<Named>(b->h130)->name==self->records.data[j].key){
     b->h130=self->records.data[j].object;
     break;
    }
   }
  }
  fn_80269FE0(tgt);
  for(i=0;i<col->indices.count;i++){
   Node*a=resolve<Node>(self->records.data[col->indices.data[i].index].object);
   a->h1c=col->indices.data[i].hc;
   fn_8023D648(a);
   Ref t;
   if(fn_801F7EB8(&col->indices.data[i].h10))resolve<Node>(col->indices.data[i].h10)->slot30(t,a->h1c);
   a->h20=t;
   fn_8023D648(a);
   fn_8023E1B4(a);
   a->slot14();
   if(!fn_801F7EB8(&col->indices.data[i].h8))continue;
   self->handles.add();
   int k=self->handles.count-1;
   self->handles[k]=fn_801B52EC(lbl_801E9D24.manager,lbl_802ACAEC);
   self->pairs.add(col->indices.data[i].h8);
   fn_8023232C(resolve<Node>(self->handles.data[k]),&self->records.data[col->indices.data[i].index].object);
   fn_8023297C(resolve<Node>(self->handles.data[k]),&self->pairs.data[k],0,1);
  }
  for(i=0;i<col->records.count;i++){
   if(fn_801F7EB8(&col->records.data[i].retained)){
    Ref t(col->records.data[i].object);
    self->handles.add();
    int k=self->handles.count-1;
    self->handles[k]=fn_801B52EC(lbl_801E9D24.manager,lbl_802ACAEC);
    Node*o=resolveMember<Node>(self->handles.data[k]);
    self->pairs.add(col->records.data[i].retained);
    fn_8023232C(o,&t);
    fn_8023297C(o,&self->pairs.data[k],0,1);
   }
  }
  self->b62=0;self->b63=0;self->b64=0;self->b65=0;
  self->reset();
 }
}
