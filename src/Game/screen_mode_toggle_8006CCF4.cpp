typedef unsigned long Word;
struct Handle_801F7F10{union{Word word;struct{signed int tag:8,index:24;}bits;};};
struct Node{};struct Entry{Node*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};struct Manager{char unknown00[8];Entry*entries;};
struct Controller{};struct Mode{char unknown00[0x60];Handle_801F7F10 target;};struct Scene{char unknown00[0x15058];Mode*mode;};
extern "C"struct Global{char unknown00[0x118];Manager*manager;char unknown11C[8];Scene*scene;}lbl_801E9D24;
struct Agent{char unknown00[0x1AC];Handle_801F7F10 query;char unknown1B0[0x168];Controller controller;};
struct Name{Word word;Name(){}Name(const char*);};
extern "C"{Agent*fn_8005E90C();signed char fn_8007D604(Controller*,int);void fn_8007D6A0(Controller*,int);void*fn_801F7EB8(const Handle_801F7F10*);void fn_800A64E0(Node*,int);Word fn_801F948C(Name*,const char*);void fn_800A6234(Node*,int,const Name&);extern const char lbl_80378810[4];}
inline Name::Name(const char*s){word=fn_801F948C(this,s);}
inline Node*resolve(const Handle_801F7F10&h){int index=h.bits.index;Manager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.bits.tag?m->entries[index].object:0;}
extern "C"void fn_8006CCF4(signed char enable){
 Name arg;
 if(!enable){
  if(!fn_8007D604(&fn_8005E90C()->controller,51))fn_8007D6A0(&fn_8005E90C()->controller,6);
  fn_800A64E0(resolve(lbl_801E9D24.scene->mode->target),1);
  Node*target=resolve(lbl_801E9D24.scene->mode->target);
  Name name(lbl_80378810);arg=name;fn_800A6234(target,1,arg);
 }else{
  if(fn_801F7EB8(&fn_8005E90C()->query))fn_8007D6A0(&fn_8005E90C()->controller,0x18);else fn_8007D6A0(&fn_8005E90C()->controller,0);
  fn_800A64E0(resolve(lbl_801E9D24.scene->mode->target),0);
  Node*target=resolve(lbl_801E9D24.scene->mode->target);
  Name name(lbl_80378810);arg=name;fn_800A6234(target,0,arg);
 }
}
