/* Early event 0xD9 target: release the first valid owned handle whose node key and value match; otherwise log. */
typedef unsigned long Word;
struct Handle_801F7F10{union{Word value;struct{signed int tag:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct Key{Word value;bool operator==(const Key&o)const{return value==o.value;}bool operator==(Word o)const{return value==o;}};
struct Node{char unknown00[0x60];Key key60;char unknown64[8];Key value6C;};
struct Entry{Node*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct Manager{int count,capacity;Entry*entries;};
extern "C" struct Context{char unknown00[0x110];void*logger;char unknown114[4];Manager*manager;}lbl_801E9D24;
inline Node*resolve(const Handle_801F7F10&h){int index=h.bits.index;signed char t=h.bits.tag;Manager*m=lbl_801E9D24.manager;signed char tag=m->entries[index].getTag();if(tag==t)return m->entries[index].object;return 0;}
extern "C"{Word fn_801F7EB8(const Handle_801F7F10*);void fn_80255678(Node*);void fn_801FA014(void*,const char*,...);extern const char lbl_8029A714[];}
struct Owner{char unknown00[0x170];int count;int capacity;Handle_801F7F10*handles;};
extern "C" void fn_8003D49C(Owner*self,const Key&key,Word value){
 for(int i=0;i<self->count;i++){
  if(fn_801F7EB8(&self->handles[i])&&resolve(self->handles[i])->key60==key&&resolve(self->handles[i])->value6C==value){fn_80255678(resolve(self->handles[i]));return;}
 }
 fn_801FA014(lbl_801E9D24.logger,lbl_8029A714);
}
