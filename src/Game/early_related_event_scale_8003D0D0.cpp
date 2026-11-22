typedef unsigned long Word;typedef unsigned long long Wide;
struct Handle_801F7F10{union{Word value;struct{signed int tag:8,index:24;}bits;};Handle_801F7F10();~Handle_801F7F10();};
struct Node;
struct Entry{Node*object;char unknown04[8];signed char tag;char unknown0D[3];signed char getTag()const{return tag;}};
struct Manager{int count,capacity;Entry*entries;};
struct Related{char unknown00[0x1C];Handle_801F7F10*handle;};
extern "C" struct Context{char unknown00[0x118];Manager*manager;char unknown11C[0x20];Related*related;}lbl_801E9D24;
extern "C"{void fn_801F86C8(Manager*,const Handle_801F7F10*,int);void fn_801EF610(void*,void*);extern char lbl_801EF5C8[];}
struct Handle_8001FF78:Handle_801F7F10{Handle_8001FF78(){value=0;}~Handle_8001FF78(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Handle_80020B90:Handle_8001FF78{Handle_80020B90(const Handle_80020B90&h){value=h.value;fn_801F86C8(lbl_801E9D24.manager,&h,1);}~Handle_80020B90(){}static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}};
struct Node{char unknown00[4];Handle_80020B90 self;char unknown08[4];Handle_801F7F10 parent;char unknown10[0x28];Wide flags;char unknown40[0xE0];Word mode;char unknown124[0xC];Handle_801F7F10 related;};
struct Event{int code;char unknown04[0x24];Node*subject;};
inline Node*resolve(const Handle_801F7F10&h){int index=h.bits.index;Manager*m=lbl_801E9D24.manager;int tag=m->entries[index].getTag();if(tag==h.bits.tag)return m->entries[index].object;return 0;}
extern "C"{Word fn_801F7EB8(const Handle_801F7F10*);void fn_802554F4(Node*);void fn_80255678(Node*);const Handle_801F7F10*fn_80268080(Node*,const Handle_801F7F10*);void fn_801EDAAC(Node*,float,float,float);extern const float lbl_803784D8,lbl_803784DC;}
extern "C"void fn_8003D0D0(void*,Event*event){
 if(event->code==0xD6&&fn_801F7EB8(&event->subject->related)&&(resolve(event->subject->related)->flags&0x800ULL)){
  fn_802554F4(resolve(event->subject->related));
  if((signed char)((event->subject->mode>>7)&1)){
   Handle_80020B90 copy(event->subject->self);
   fn_801EDAAC(resolve(*fn_80268080(resolve(resolve(*lbl_801E9D24.related->handle)->parent),&copy)),lbl_803784D8,lbl_803784D8,lbl_803784DC);
  }
 }
 if(event->code==0xD7&&fn_801F7EB8(&event->subject->related)&&(resolve(event->subject->related)->flags&0x800ULL))fn_80255678(resolve(event->subject->related));
}
