/* Group resource discovery, binding and scoped Handle arrays.
 * See docs/notes/game-engine-group-resource-setup.md. */
#include "Game/engine_group_resource_setup.h"

typedef unsigned long Word;
struct Handle_801F7F10{union{Word word;struct{signed int tag:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
inline void*operator new(Word,void*p){return p;}
namespace GroupResourceSetup {
struct Node;
struct Entry{Node*object;Word unknown04[2];signed char tag;char unknown0D[3];};struct Manager{Word unknown00[2];Entry*entries;};
struct Globals{char unknown00[0x118];Manager*manager;char unknown11C[8];void*engine;};
extern "C"{extern Globals lbl_801E9D24;extern char lbl_8028F698[];extern const char lbl_802AD8C4[];void fn_801F86C8(Manager*,const Handle_801F7F10*,int);void*fn_801F7EB8(const Handle_801F7F10*);Word fn_801F948C(void*,const char*);void*fn_8028FAF4(void*,void*,Word,Word);void*fn_8028FF24(void*,Word);void fn_8028FD50(void*,void*,Word);}
struct ReturnHandle:Handle_801F7F10{};
struct Copy0:Handle_801F7F10{Copy0(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}};
struct Zero1:Handle_801F7F10{Zero1(){word=0;}~Zero1(){}};
struct Copy1:Zero1{Copy1(){}Copy1(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}Copy1(const Copy1&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}};
struct Resource:Zero1{Resource(const Copy1&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}Resource&operator=(const Copy1&h){fn_801F86C8(lbl_801E9D24.manager,this,-1);word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);return*this;}};
struct ArrayHandle:Zero1{~ArrayHandle(){}ArrayHandle(){}ArrayHandle(const Handle_801F7F10&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}};
struct Key{Word word;Key(){word=0;}Key(const char*s){word=fn_801F948C(this,s);}};
template<class T>struct Array{int count,capacity;T*data;Array(){count=0;capacity=0;data=0;}~Array(){if(data){for(int i=0;i<count;++i)data[i].~T();storage(0);data=0;}}void storage(int n){if(n){if(data)data=(T*)fn_8028FAF4(lbl_8028F698,data,capacity*sizeof(T),n*sizeof(T));else data=(T*)fn_8028FF24(lbl_8028F698,n*sizeof(T));}else if(data){fn_8028FD50(lbl_8028F698,data,capacity*sizeof(T));data=0;}}void append(const Handle_801F7F10&h){if(count+1>capacity){storage(capacity+100);capacity+=100;}new(data+count++)T(h);}};
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
 virtual void setContext(const Handle_801F7F10&);
 char unknown0C[0x10];Handle_801F7F10 related1C;
};
inline Node*resolve(const Handle_801F7F10&h){Entry*e=lbl_801E9D24.manager->entries+h.bits.index;if(e->tag==h.bits.tag)return e->object;return 0;}
struct RelatedEntry{Node*object;Word unknown04[2];signed char tag;char unknown0D[3];};struct RelatedManager{Word unknown00[2];RelatedEntry*entries;};
inline Node*resolveRelated(const Handle_801F7F10&h){RelatedEntry*e=((RelatedManager*)lbl_801E9D24.manager)->entries+h.bits.index;if(e->tag==h.bits.tag)return e->object;return 0;}
struct Group{Word unknown00;Handle_801F7F10 context04;Word unknown08;Handle_801F7F10 owner0C;char unknown10[0xB4];Array<ArrayHandle>resources;char unknownD0[0x18];signed char updatingE8;};
typedef char HandleSize[(sizeof(Handle_801F7F10)==4)?1:-1];
typedef char EntrySize[(sizeof(Entry)==16)?1:-1];
typedef char NodeSize[(sizeof(Node)==32)?1:-1];
typedef char ArraySize[(sizeof(Array<ArrayHandle>)==12)?1:-1];
typedef char GroupSize[(sizeof(Group)==0xEC)?1:-1];
extern "C"{void fn_8026A128(Node*,Array<ArrayHandle>*,int);signed char fn_802433A4(Node*,Key&);ReturnHandle fn_80260868(void*,const Key&,int);void fn_801FD4EC(Group*,const Handle_801F7F10&,const Key&);}
inline void apply(Group*self,const Handle_801F7F10&h,Key key=Key()){fn_801FD4EC(self,h,key);}
extern "C"void fn_801FDD60(Group*self){
 const Handle_801F7F10&originalContext=self->context04;Copy0 context(originalContext);
 Array<ArrayHandle>fourteen;fn_8026A128(resolve(self->owner0C),&fourteen,14);
 int i;Key key;
 for(i=0;i<fourteen.count;++i){
  if(!fn_802433A4(resolveRelated(resolve(fourteen.data[i])->related1C),key))key=Key(lbl_802AD8C4);
  Resource resource(Copy1(fn_80260868(lbl_801E9D24.engine,key,0)));
  if(!fn_801F7EB8(&resource))key=Key(lbl_802AD8C4);
  if(!fn_801F7EB8(&resource))resource=Copy1(fn_80260868(lbl_801E9D24.engine,key,0));
  if(fn_801F7EB8(&resource)){resolve(resource)->setOwner(fourteen.data[i]);self->resources.append(resource);}
 }
 Array<ArrayHandle>five;fn_8026A128(resolve(self->owner0C),&five,5);for(i=0;i<five.count;++i)apply(self,five.data[i]);
 Array<ArrayHandle>three;fn_8026A128(resolve(self->owner0C),&three,3);for(i=0;i<three.count;++i)apply(self,three.data[i]);
 Array<ArrayHandle>six;fn_8026A128(resolve(self->owner0C),&six,6);for(i=0;i<six.count;++i)apply(self,six.data[i]);
 Array<ArrayHandle>eighteen;fn_8026A128(resolve(self->owner0C),&eighteen,18);for(i=0;i<eighteen.count;++i)apply(self,eighteen.data[i]);
 self->updatingE8=1;
 for(i=0;i<self->resources.count;++i)resolve(self->resources.data[i])->setContext(context);
 self->updatingE8=0;
}
}
