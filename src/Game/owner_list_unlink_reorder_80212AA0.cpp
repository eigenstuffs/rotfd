/* Unlink and reinsert owners in a mode-sorted doubly linked list.
 * Reconstructed native four-byte retained Handles and observed link offsets.
 * Capture the manager before its const index and signed generation tag.
 * The ordinary unreferenced weak ListHandle destructor remains uncredited.
 */
struct ListIndex{int value;ListIndex(int v):value(v){}operator const int&()const{return value;}};
typedef unsigned long u32;
struct Object;
struct Entry {Object* object;u32 unknown[2];signed char generation;char pad[3];signed char getGeneration()const{return generation;}bool matchesGeneration(signed char tag)const{return generation==tag;}};
struct EntryArray{Entry*p;Entry& operator[](int i)const{return p[i];}};
struct Manager {int count,capacity;EntryArray entries;};
struct Globals {char unknown[0x118];Manager* manager;};
extern "C" {extern Globals lbl_801E9D24;void fn_801F86C8(Manager*,const void*,short);void* fn_801F7EB8(const void*);}
struct Handle_801F7F10 {union {u32 value;struct{signed int generation:8;signed int index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct ListHandle:Handle_801F7F10 {
 ListHandle(){value=0;}~ListHandle(){}
 ListHandle(const ListHandle&h){value=h.value;fn_801F86C8(lbl_801E9D24.manager,&h,1);}
 ListHandle& operator=(const ListHandle& h){fn_801F86C8(lbl_801E9D24.manager,this,-1);value=h.value;fn_801F86C8(lbl_801E9D24.manager,&h,1);return *this;}
 Object* get()const {Manager*m=lbl_801E9D24.manager;const ListIndex index(bits.index);const signed char generation=bits.generation;if(m->entries[index].matchesGeneration(generation))return m->entries[index].object;return 0;}
};
struct Object {char unknown[0xC];ListHandle prev,next;int mode;};
struct List {
 ListHandle head,tail;signed char state;
 void append(const ListHandle&h){h.get()->prev=tail;if(!fn_801F7EB8(&tail))head=h;else tail.get()->next=h;tail=h;}
};
extern "C" void fn_80212AA0(List*,const ListHandle&);

extern "C" void fn_80212AA0(List* self,const ListHandle& h){
 Object* node=h.get();
 if(!fn_801F7EB8(&node->prev)&&!fn_801F7EB8(&node->next))return;
 if(h.get()==self->head.get()){
  self->head=node->next;
  if(fn_801F7EB8(&self->head))self->head.get()->prev=ListHandle();
  else self->tail=ListHandle();
 }else if(h.get()==self->tail.get()){
  if(fn_801F7EB8(&node->prev)){
   node->prev.get()->next=ListHandle();
   self->tail=node->prev;
  }else{self->head=ListHandle();self->tail=ListHandle();}
 }else{
  node->prev.get()->next=node->next;
  node->next.get()->prev=node->prev;
 }
 node->prev=ListHandle();node->next=ListHandle();
}

extern "C" void fn_80212FC4(List*self,const ListHandle&h){
 int mode=h.get()->mode;
 if(mode==9){
  if(h.get()!=self->tail.get()) {fn_80212AA0(self,h);self->append(h);}
  else return;
 }
 fn_80212AA0(self,h);
 if(!fn_801F7EB8(&self->head)){self->append(h);return;}
 if(self->tail.get()->mode<=mode){self->append(h);return;}
 ListHandle cursor(self->head);
 while(cursor.get()->mode<mode)cursor=cursor.get()->next;
 if(cursor.get()==self->head.get())self->head=h;
 else{h.get()->prev=cursor.get()->prev;cursor.get()->prev.get()->next=h;}
 h.get()->next=cursor;
 cursor.get()->prev=h;
}
