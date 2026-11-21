// Bind the nine letter/puzzle record slots: look up the "Letter%d" and
// "Puzzle%d" scene objects, and copy each one's related model handle into the
// "BoxTop" / "Box_Bottom" slots of the owner's record node target arrays.
// Format strings live in the shared pool lbl_8029C8E0 ("Letter%d" +0x0,
// "Puzzle%d" +0xC, "Box_Bottom" +0x18), owned by native_readable_pools_8029C8E0.cpp;
// data member pointers keep the original pooled base + offset addressing.
typedef unsigned long Word;
struct Handle_801F7F10{union{Word word;struct{signed int tag:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct Node;
struct Entry{Node*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct Manager{char unknown00[8];Entry*entries;};
extern "C" struct Context{char unknown00[0x118];Manager*manager;char unknown11C[0x28];void*names;char unknown148[4];void*scope;}lbl_801E9D24;
struct Name;
extern "C"{
void fn_801F86C8(Manager*,const void*,int);
extern char lbl_801EF5C8[];
void fn_801EF610(void*,void*);
Word fn_801F948C(void*,const char*);
int sprintf(char*,const char*,...);
int fn_801F4AC8(void*,const Name*);
extern const char lbl_80378904[7]; // "BoxTop"
}
struct Pool{char letter[12];char puzzle[12];char boxBottom[12];char positions[0x84];};
extern "C" const Pool lbl_8029C8E0;
inline const char*letterFormat(const Pool*p){const char(Pool::*m)[12]=&Pool::letter;return p->*m;}
inline const char*puzzleFormat(const Pool*p){const char(Pool::*m)[12]=&Pool::puzzle;return p->*m;}
inline const char*boxBottomName(const Pool*p){const char(Pool::*m)[12]=&Pool::boxBottom;return p->*m;}
struct Handle_8001FF78:Handle_801F7F10{
 Handle_8001FF78(){word=0;}~Handle_8001FF78(){}
 static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}
};
struct Handle_800723F4:Handle_8001FF78{
 Handle_800723F4(const Handle_800723F4&h){word=h.word;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_800723F4(){}
 static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}
};
struct Name{Word word;Name(const char*s){word=fn_801F948C(this,s);}};
extern "C" Handle_800723F4 fn_802631B0(void*,const Name&);
inline Node*resolve(const Handle_801F7F10&h){int index=h.bits.index;Manager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.bits.tag?m->entries[index].object:0;}
inline Node*resolveIf(const Handle_801F7F10&h){Entry*e=&lbl_801E9D24.manager->entries[h.bits.index];if(e->tag==h.bits.tag)return e->object;return 0;}
struct Node{
 char unknown00[0x38];Handle_801F7F10*slots;char unknown3C[0x38];Handle_801F7F10 model74;
 char unknown78[0x40];Handle_801F7F10 related;char unknownBC[0x134];Handle_801F7F10 target;
 const Handle_801F7F10&model()const{return resolve(related)->model74;}
 void setModel(const Handle_801F7F10&s){fn_801F86C8(lbl_801E9D24.manager,&model74,-1);model74.word=s.word;fn_801F86C8(lbl_801E9D24.manager,&s,1);}
};
struct InputNode{char unknown00[0x64];Handle_801F7F10 handle;};
struct Record{short id;InputNode*node;float x,y,z;};
struct Self{char unknown00[0x74];Record records[9];};

extern "C" void fn_80071F48(Self*self){
 const Pool*const s=&lbl_8029C8E0;
 for(unsigned short i=0;i<9;++i){
  char puzzle[8],letter[8];
  sprintf(letter,letterFormat(s),i);
  sprintf(puzzle,puzzleFormat(s),i);
  Handle_800723F4 first(fn_802631B0(lbl_801E9D24.scope,Name(letter)));
  Handle_800723F4 second(fn_802631B0(lbl_801E9D24.scope,Name(puzzle)));
  Node*firstNode=resolve(fn_802631B0(lbl_801E9D24.scope,Name(letter)));
  Node*secondNode=resolveIf(fn_802631B0(lbl_801E9D24.scope,Name(puzzle)));
  const Handle_801F7F10&firstValue=firstNode->model();
  const Handle_801F7F10&secondValue=secondNode->model();
  int firstIndex=fn_801F4AC8(lbl_801E9D24.names,&Name(lbl_80378904));
  int secondIndex=fn_801F4AC8(lbl_801E9D24.names,&Name(boxBottomName(s)));
  Handle_801F7F10*firstSlots=resolve(resolve(self->records[i].node->handle)->target)->slots;
  const Handle_801F7F10&firstHandle=firstSlots[firstIndex];
  Handle_801F7F10*secondSlots=resolve(resolve(self->records[i].node->handle)->target)->slots;
  const Handle_801F7F10&secondHandle=secondSlots[secondIndex];
  resolve(firstHandle)->setModel(firstValue);
  resolve(secondHandle)->setModel(secondValue);
 }
}
