/* fn_801FD4EC: choose and bind an agent resource for one group child.
 * Called by fn_801FDD60 (engine_group_resource_setup.cpp) with a default Key.
 * Looks up the requested key, then falls back to class names chosen from the
 * child's related info type (3/5/6/0x12), appends the resolved resource to
 * the group's Handle array (growth 100) after binding its owner.
 * Strings stay external: lbl_802AD848 ("NO_STAND_ON" +0x0, "CSimpleAgent"
 * +0xC, "LodDynAgent_Z" +0x1C, "LodAgent_Z" +0x2C, "AnimatedAgent_Z" +0x38,
 * "ParticlesAlwaysOn" +0x48, "SkinAgent_Z" +0x5C, "ParticlesAgent_Z" +0x68)
 * is owned by native_readable_pools_802AD848.cpp; the base is hoisted into
 * r28 as in the original. The offset-0 string is reached as (member pointer
 * to +0xC) minus 0xC, and the fn_8025318C result is bound to a local so the
 * `addi r4,r28,0` is scheduled after that call. */
typedef unsigned long Word;
struct Handle_801F7F10{union{Word word;struct{signed int tag:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
inline void*operator new(Word,void*p){return p;}
struct Node;
struct Entry{Node*object;Word unknown04[2];signed char tag;char unknown0D[3];};struct Manager{int count,capacity;Entry*entries;};
struct Globals{char unknown00[0x118];Manager*manager;char unknown11C[8];void*engine;char unknown128[0x1C];void*registry;};
extern "C"{extern Globals lbl_801E9D24;extern char lbl_8028F698[];void fn_801F86C8(Manager*,const Handle_801F7F10*,int);void*fn_801F7EB8(const Handle_801F7F10*);Word fn_801F948C(void*,const char*);void*fn_8028FAF4(void*,void*,Word,Word);void*fn_8028FF24(void*,Word);void fn_8028FD50(void*,void*,Word);}
struct ReturnHandle:Handle_801F7F10{};
struct Zero1:Handle_801F7F10{Zero1(){word=0;}~Zero1(){}};
struct Copy1:Zero1{Copy1(){}Copy1(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}Copy1(const Copy1&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}};
struct Resource:Zero1{Resource(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}Resource&operator=(const Copy1&h){fn_801F86C8(lbl_801E9D24.manager,this,-1);word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);return*this;}};
struct ArrayHandle:Zero1{~ArrayHandle(){}ArrayHandle(){}ArrayHandle(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}};
struct Key{Word word;Key(){word=0;}Key(const char*s){word=fn_801F948C(this,s);}};
template<class T>struct Array{int count,capacity;T*data;void storage(int n){if(n){if(data)data=(T*)fn_8028FAF4(lbl_8028F698,data,capacity*sizeof(T),n*sizeof(T));else data=(T*)fn_8028FF24(lbl_8028F698,n*sizeof(T));}else if(data){fn_8028FD50(lbl_8028F698,data,capacity*sizeof(T));data=0;}}void append(const Handle_801F7F10&h){if(count+1>capacity){storage(capacity+100);capacity+=100;}new(data+count++)T(h);}};
struct NodePrefix{Word unknown00[2];};struct Node:NodePrefix{
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
 virtual void setOwner(const Handle_801F7F10&);
};
struct HandleIndex{int value;HandleIndex(int v):value(v){}operator int()const{return value;}};
struct HandleBits{signed int tag:8,index:24;};
struct Agent{Key name;char unknown04[0x18];Handle_801F7F10 related1C;char unknown20[0xC];Handle_801F7F10 child2C;char unknown30[0xF0];Word flags120;};
struct Info{Key name;HandleBits handle04;char unknown08[0x64];unsigned short type6C;char unknown6E[0x2E];Word w9C,wA0,wA4;char unknownA8[0x18];int countC0,capacityC4;Handle_801F7F10*dataC8;};
inline Agent*resolve(const Handle_801F7F10&h){Entry*e=lbl_801E9D24.manager->entries+h.bits.index;if(e->tag==h.bits.tag)return(Agent*)e->object;return 0;}
inline Info*resolveInfo(const Handle_801F7F10&h){Entry*e=lbl_801E9D24.manager->entries+h.bits.index;if(e->tag==h.bits.tag)return(Info*)e->object;return 0;}
inline Node*resolveNode(const Handle_801F7F10&h){Entry*e=lbl_801E9D24.manager->entries+h.bits.index;if(e->tag==h.bits.tag)return e->object;return 0;}
struct Group{Word unknown00;Handle_801F7F10 context04;Word unknown08;Handle_801F7F10 owner0C;char unknown10[0xB4];Array<ArrayHandle>resources;};
struct Strings{char noStandOn[0xC];char simpleAgent[0x10];char lodDynAgent[0x10];char lodAgent[0xC];char animatedAgent[0x10];char particlesAlwaysOn[0x14];char skinAgent[0xC];char particlesAgent[0x13];};
extern "C"{extern const Strings lbl_802AD848;extern Key*lbl_80377F98;ReturnHandle fn_80260868(void*,const Key&,int);signed char fn_801B5230(Manager*,const Key&,const Key&);signed char fn_801F5F28(void*,const Key*,const Word*,Word*,int);const char*fn_8025318C(Node*,int*);int strcmp(const char*,const char*);}
inline Word registryKey(const HandleBits&handle){
 Manager*manager=lbl_801E9D24.manager;const HandleIndex index(handle.index);signed char generation=handle.tag;int valid=0;
 if(index<manager->count&&generation==((signed char*)manager->entries)[index*sizeof(Entry)+12])valid=1;
 return valid?*(Word*)((char*)manager->entries+index*sizeof(Entry)+4):0;
}
inline const char*simpleName(const Strings*s){const char(Strings::*m)[0x10]=&Strings::simpleAgent;return s->*m;}
inline const char*noStandOn(const Strings*s){return simpleName(s)-sizeof(s->noStandOn);}
extern "C" int fn_801FD4EC(Group*self,const Handle_801F7F10&h,const Key&key){
 const Strings*const s=&lbl_802AD848;
 Agent*agent=resolve(h);
 Resource result(fn_80260868(lbl_801E9D24.engine,key,0));
 Info*info=resolveInfo(agent->related1C);
 Key name=info->name;
 unsigned short type=info->type6C;
 if(type==6||type==3||type==5){
  const Handle_801F7F10&source=agent->child2C;Copy1 child(source);
  if(fn_801F7EB8(&child)){
   int length;
   const char*got=fn_8025318C(resolveNode(child),&length);if(strcmp(got,noStandOn(s))==0)agent->flags120|=0x200000;
  }
 }
 if(!fn_801F7EB8(&result)){
  if(type==5){
   Word parent=registryKey(info->handle04);
   Word found;
   lbl_80377F98=&agent->name;if(fn_801B5230(lbl_801E9D24.manager,agent->name,Key(s->simpleAgent)))name=agent->name;
   if(info->countC0&&resolveInfo(info->dataC8[0])->type6C==3){
    result=Copy1(fn_80260868(lbl_801E9D24.engine,name,0));
    if(!fn_801F7EB8(&result)){
     if(info->w9C||info->wA4||info->wA0)name=Key(s->lodDynAgent);
     else if(agent->flags120&0x400)name=Key(s->lodAgent);
     else if(fn_801F5F28(lbl_801E9D24.registry,&name,&parent,&found,0))name=Key(s->animatedAgent);
    }
   }else{
    lbl_80377F98=&agent->name;if(fn_801B5230(lbl_801E9D24.manager,agent->name,Key(s->simpleAgent)))name=agent->name;
    result=Copy1(fn_80260868(lbl_801E9D24.engine,name,0));
   }
  }else{
   lbl_80377F98=&agent->name;if(fn_801B5230(lbl_801E9D24.manager,agent->name,Key(s->simpleAgent)))name=agent->name;
   if(type==0x12&&fn_801F7EB8(&resolve(h)->child2C))name=Key(s->particlesAlwaysOn);
   result=Copy1(fn_80260868(lbl_801E9D24.engine,name,0));
   if(type==3&&!fn_801F7EB8(&result))name=Key(s->skinAgent);
   if(type==0x12&&!fn_801F7EB8(&result))name=Key(s->particlesAgent);
  }
 }
 if(!fn_801F7EB8(&result))result=Copy1(fn_80260868(lbl_801E9D24.engine,name,0));
 if(!fn_801F7EB8(&result))return 0;
 Copy1 owner(h);
 resolveNode(result)->setOwner(owner);
 self->resources.append(result);
 return 1;
}
