/* fn_8022C6FC: insert a handle (unique) into the owner list ordered by priority,
   with a parallel flags word list and a bit-storage resize (same TU as
   fn_8022B16C/fn_8022CEAC). */
typedef unsigned long Word;
struct Handle_801F7F10{
 union{Word value;struct{signed int generation:8;signed int index:24;}bits;};
 Handle_801F7F10();~Handle_801F7F10();
 Handle_801F7F10&operator=(const Handle_801F7F10&h);
};
struct Vec3{float x,y,z;};
struct ObjectPrefix{Word unknown00[2];};
struct Object:ObjectPrefix{
virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1C();virtual void slot20();virtual void slot24();virtual void slot28();virtual void slot2C();virtual void slot30();virtual void slot34();virtual void slot38();virtual void slot3C();virtual void slot40();virtual void slot44();virtual void slot48();virtual void slot4C();virtual void slot50();virtual void slot54();virtual void slot58();virtual void slot5C();virtual void slot60();virtual void slot64();virtual void slot68();virtual void slot6C();virtual void slot70();virtual void slot74();virtual void slot78();virtual void slot7C();virtual void slot80();virtual void slot84();virtual void slot88();virtual void slot8C();virtual void slot90();virtual void slot94();virtual void slot98();virtual void slot9C();virtual void slotA0();virtual void slotA4();virtual void slotA8();virtual void slotAC();
virtual Vec3 position(int);
virtual void slotB4();virtual void slotB8();virtual void slotBC();virtual void slotC0();virtual void slotC4();virtual void slotC8();virtual void slotCC();virtual void slotD0();virtual void slotD4();virtual void slotD8();virtual void slotDC();virtual void slotE0();virtual void slotE4();virtual void slotE8();virtual void slotEC();virtual void slotF0();virtual void slotF4();virtual void slotF8();virtual void slotFC();virtual void slot100();virtual void slot104();
virtual void apply(Object*,const Vec3*,const Vec3*,int,int);
char unknown0C[8];int priority;char unknown18[0x18];unsigned long long flags;char unknown38[0x130];Handle_801F7F10 link;
};
struct RootObject{char unknown00[0xC];Handle_801F7F10 handle;};
struct Entry{Object*object;Word unknown04[2];signed char generation;char unknown0D[3];signed char getGeneration()const{return generation;}};
struct Manager{Word unknown00[2];Entry*entries;};
extern "C"{
extern struct{char unknown00[0x118];Manager*manager;}lbl_801E9D24;
extern char lbl_8028F698[];
void fn_801F86C8(Manager*,const Handle_801F7F10*,short);
void*fn_8028FAF4(void*,void*,Word,Word);
void*fn_8028FF24(void*,Word);
void fn_8028FD50(void*,void*,Word);
signed char fn_8021F2D0(Object*);
signed char fn_8021F308(Object*);
void*memmove(void*,const void*,unsigned long);
}
inline void*operator new(Word,void*address){return address;}
inline Handle_801F7F10&Handle_801F7F10::operator=(const Handle_801F7F10&h){fn_801F86C8(lbl_801E9D24.manager,this,-1);value=h.value;fn_801F86C8(lbl_801E9D24.manager,&h,1);return *this;}
static inline Object*resolve(const Handle_801F7F10&h){int index=h.bits.index;Manager*m=lbl_801E9D24.manager;int generation=m->entries[index].getGeneration();return generation==h.bits.generation?m->entries[index].object:0;}
static inline RootObject*rootLookup(const Handle_801F7F10&h){RootObject*result=0;Entry*e=lbl_801E9D24.manager->entries+h.bits.index;if(e->generation==h.bits.generation)result=(RootObject*)e->object;return result;}
struct ZeroHandle:Handle_801F7F10{ZeroHandle(){value=0;}};
struct CopiedHandle:ZeroHandle{CopiedHandle(const Handle_801F7F10&h){value=0;value=h.value;fn_801F86C8(lbl_801E9D24.manager,&h,1);}};
struct Handles{
 int count,capacity;CopiedHandle*items;
 void storage(int size){
  if(size){
   if(items)items=(CopiedHandle*)fn_8028FAF4(lbl_8028F698,items,capacity*4,size*4);
   else items=(CopiedHandle*)fn_8028FF24(lbl_8028F698,size*4);
  }else if(items){fn_8028FD50(lbl_8028F698,items,capacity*4);items=0;}
 }
 void grow(){if(count+1>capacity){storage(capacity+32);capacity+=32;}}
 void append(const Handle_801F7F10&h){grow();new(&items[count++])CopiedHandle(h);}
 void insert(int index,const Handle_801F7F10&h){grow();memmove(&items[index+1],&items[index],(count-index)*4);new(&items[index])CopiedHandle(h);++count;}
};
struct Words{
 int count,capacity;Word*items;
 void storage(int size){
  if(size){
   if(items)items=(Word*)fn_8028FAF4(lbl_8028F698,items,capacity*4,size*4);
   else items=(Word*)fn_8028FF24(lbl_8028F698,size*4);
  }else if(items){fn_8028FD50(lbl_8028F698,items,capacity*4);items=0;}
 }
 void grow(){if(count+1>capacity){storage(capacity+8);capacity+=8;}}
 void append(Word v){grow();new(&items[count++])Word(v);}
 void insert(int index,Word v){grow();memmove(&items[index+1],&items[index],(count-index)*4);new(&items[index])Word(v);++count;}
};
struct Bits{
 int count,capacity;Word*words;
 void reserve(int n){if(n){if(words)words=(Word*)fn_8028FAF4(lbl_8028F698,words,capacity*4,n*4);else words=(Word*)fn_8028FF24(lbl_8028F698,n*4);}else if(words){fn_8028FD50(lbl_8028F698,words,capacity*4);words=0;}capacity=n;}
 void resize(int n){if(n>count){reserve(n);for(int i=count;i<n;++i){}count=n;}else if(n<count){for(int i=count-1;i>=n;--i){}reserve(n);count=n;}}
};
struct Self{
 char unknown00[0x28];Handle_801F7F10 root;Handles handles;Words flags;Bits bits;int size;
 void setSize(int n){size=n;if(n&&((n>>5)+1)>bits.count)bits.resize((size>>5)+1);}
};
/* Entry-pointer form of the lookup: the inserted object is resolved this way
   (it fixes the register of the bit-storage resize count). */
inline Object*resolveB(const Handle_801F7F10&h){Entry*e=lbl_801E9D24.manager->entries+h.bits.index;if(e->generation==h.bits.generation)return e->object;return 0;}
extern "C" void fn_8022C6FC(Self*self,const Handle_801F7F10*handle,Word flags){
 int count=self->handles.count;
 int i;
 for(i=0;i<count;++i){
  Object*current=resolve(self->handles.items[i]);
  if(current==resolve(*handle))break;
 }
 if(i!=count)return;
 Object*object=resolveB(*handle);
 if(fn_8021F2D0(object)){
  flags|=2;
  Handle_801F7F10&link=object->link;link=self->root;
 }
 if((flags&4)&&fn_8021F308(object)&&(object->flags&0x1000ULL)!=0){
  Object*target=resolve(rootLookup(self->root)->handle);
  object->apply(target,&object->position(0),&object->position(0),0,1);
 }
 int priority=object->priority;
 for(i=0;i<count;++i){
  if(resolve(self->handles.items[i])->priority>priority)break;
 }
 if(count==0||i==count){
  self->handles.append(*handle);
  self->flags.append(flags);
 }else{
  self->handles.insert(i,*handle);
  self->flags.insert(i,flags);
 }
 self->setSize(self->handles.count);
}
