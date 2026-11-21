typedef unsigned long Word;
struct Handle_801F7F10{union{Word word;struct{signed int tag:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct Node{};struct Entry{Node*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};struct Manager{char unknown00[8];Entry*entries;};
struct Controller{};struct Mode{char unknown00[0x60];Handle_801F7F10 target;char unknown64[0x8C];int kind,subkind;};struct Scene{char unknown00[0x15058];Mode*mode;};
extern "C"struct Global{char unknown00[0x118];Manager*manager;char unknown11C[8];Scene*scene;}lbl_801E9D24;
extern "C"{void fn_801F86C8(Manager*,const Handle_801F7F10*,int);extern char lbl_801EF5C8[];void fn_801EF610(void*,void*);}
struct Handle_8001FF78:Handle_801F7F10{Handle_8001FF78(){word=0;}~Handle_8001FF78(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80020B90:Handle_8001FF78{Handle_80020B90(const Handle_80020B90&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_80020B90(){}Handle_80020B90&operator=(const Handle_80020B90&h){fn_801F86C8(lbl_801E9D24.manager,this,-1);word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);return*this;}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Input{Word unknown00;Handle_80020B90 handle;};
struct Agent{char unknown00[0x1EC];Handle_80020B90 first,second;char unknown1F4[0x34];int state;char unknown22C[0xEC];Controller controller;};
struct Name{Word word;Name(const char*);};
extern "C"{Agent*fn_8007D074(Input*);void fn_8007626C(Agent*,int);Agent*fn_8005E90C();signed char fn_8007D604(Controller*,int);void fn_8007D6A0(Controller*,int);void fn_800A64E0(Node*,int);Word fn_801F948C(Name*,const char*);void fn_800A6234(Node*,int,const Name&);extern const char lbl_80378810[4];}
inline Name::Name(const char*s){word=fn_801F948C(this,s);}
inline Node*resolve(const Handle_801F7F10&h){int index=h.bits.index;Manager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.bits.tag?m->entries[index].object:0;}
inline void select(Agent*a,Handle_80020B90 first,Handle_80020B90 second){a->first=first;a->second=second;}
extern "C"void fn_8006D2DC(Input*first,Input*second){
 Agent*a=fn_8007D074(first);fn_8007626C(a,4);a->state=1;const Handle_80020B90&sourceFirst=first->handle;{Handle_80020B90 firstCopy(sourceFirst);const Handle_80020B90&sourceSecond=second->handle;Handle_80020B90 secondCopy(sourceSecond);a->first=firstCopy;a->second=secondCopy;}
 if(lbl_801E9D24.scene->mode->kind!=5||lbl_801E9D24.scene->mode->subkind!=2){
  if(!fn_8007D604(&fn_8005E90C()->controller,51))fn_8007D6A0(&fn_8005E90C()->controller,6);
  fn_800A64E0(resolve(lbl_801E9D24.scene->mode->target),1);
  Node*target=resolve(lbl_801E9D24.scene->mode->target);
  Name name(lbl_80378810);fn_800A6234(target,1,Name(name));
 }
}
