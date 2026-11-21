/* Actor record-key existence query; see docs/notes/game-actor-record-key-exists.md. */
typedef unsigned long Word;
struct Handle_801F7F10 {union{Word value;struct{signed int tag:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();int getIndex()const{return bits.index;}int getTag()const{return bits.tag;}};
struct Entry {void*object;char prefix[8];signed char tag;char tail[3];int getTag()const{return tag;}};
struct Manager {int count,capacity;Entry*entries;};
struct Globals {char prefix[0x118];Manager*manager;char prefix11C[0x28];void*records;};
extern "C" {extern char lbl_801EF5C8[];void fn_801EF610(void*,void*);extern Globals lbl_801E9D24;void fn_801F86C8(Manager*,const Handle_801F7F10*,int);void*fn_801F7EB8(const Handle_801F7F10*);Handle_801F7F10 fn_801F5C04(void*,int,int);}
struct Handle_8001FF78:Handle_801F7F10 {Handle_8001FF78(){value=0;}~Handle_8001FF78(){} static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80042FA4:Handle_8001FF78 {Handle_80042FA4(const Handle_801F7F10&h){value=h.value;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_80042FA4(){} static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
inline void* resolve(const Handle_801F7F10&h){int index=h.getIndex();Manager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();return tag==h.getTag()?m->entries[index].object:0;}
struct Actor {char prefix[0x68];int record;};
struct Self {char prefix[0x24];Handle_801F7F10 actor;Actor*getActor(){return (Actor*)resolve(actor);}};
extern "C" int fn_8009C12C(Self*self,int key){
 Actor*actor=self->getActor();
 if(actor->record>=0){
  Handle_80042FA4 handle(fn_801F5C04(lbl_801E9D24.records,actor->record,key));
  if(fn_801F7EB8(&handle))return 1;
 }
 return 0;
}
