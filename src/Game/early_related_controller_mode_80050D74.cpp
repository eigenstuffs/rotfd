/* Related controller/name mode; see docs/notes/game-early-related-controller-mode.md. */
typedef unsigned long Word;
struct Handle{union{Word value;struct{signed int tag:8,index:24;}bits;};};
struct Controller{char unknown00;};
struct Node{char unknown00[0x60];Handle target;char unknown64[0xC];Handle actor;char unknown74[0x3C];Handle*child;char unknownB4[0x264];Controller controller;};
struct Entry{Node*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct Manager{int count,capacity;Entry*entries;};
struct Scene{char unknown00[0x15058];Node*owner;};
struct Related{char unknown00[0x1C];Handle*handle;};
extern "C" struct Context{char unknown00[0x118];Manager*manager;char unknown11C[8];Scene*scene;char unknown128[0x14];Related*related;}lbl_801E9D24;
inline Node*resolve(const Handle&h){int index=h.bits.index;Manager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();if(tag==h.bits.tag)return m->entries[index].object;return 0;}
extern "C"{Word fn_801F7EB8(const Handle*);void fn_8007D6A0(Controller*,int);void fn_800A64E0(Node*,int);Word fn_801F948C(void*,const char*);extern const char lbl_8037858C[4];}
struct Name{Word value;Name(){}Name(const char*s){value=fn_801F948C(this,s);}Name(const Name&n){value=n.value;}};
extern "C"void fn_800A6234(Node*,signed char,const Name&);
extern "C"void fn_80050D74(void*,signed char state){
 Name name;
 if(!state){
  const Handle*h=&resolve(*resolve(*lbl_801E9D24.related->handle)->child)->actor;
  Node*actor;if(fn_801F7EB8(h))actor=resolve(*h);else actor=0;
  fn_8007D6A0(&actor->controller,6);
  fn_800A64E0(resolve(lbl_801E9D24.scene->owner->target),1);
  Node*target=resolve(lbl_801E9D24.scene->owner->target);
  name=Name(lbl_8037858C);fn_800A6234(target,1,name);
 }else{
  const Handle*h=&resolve(*resolve(*lbl_801E9D24.related->handle)->child)->actor;
  Node*actor;if(fn_801F7EB8(h))actor=resolve(*h);else actor=0;
  fn_8007D6A0(&actor->controller,0);
  fn_800A64E0(resolve(lbl_801E9D24.scene->owner->target),0);
  Node*target=resolve(lbl_801E9D24.scene->owner->target);
  name=Name(lbl_8037858C);fn_800A6234(target,0,name);
 }
}
