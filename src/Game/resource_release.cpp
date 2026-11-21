/* Resource reference marking reconstructed from GSQE78. */
typedef unsigned long u32;
struct RefEntry {int type;u32 reference,unknown;};
template<class T>struct RefArray {u32 prefix;int size,capacity;T*data;T&operator[](int i){return data[i];}};
struct RefRow:RefArray<RefEntry>{};
struct ActionList:RefArray<RefRow>{u32 extra;};
struct ObjectPrefix {u32 unknown[2];};
struct Object:ObjectPrefix {virtual void slot8();virtual void slotC();virtual void slot10();virtual void slot14();virtual void slot18();virtual void release();};
struct SmartHandle {signed int type:8;signed int index:24;};
struct ObjectSlot {Object*object;u32 unknown[2];signed char type;};
struct StringSlot {char text[128];char marked;};
struct Context {int size,capacity;ObjectSlot*data;char unknown[0xC8];StringSlot*strings;};
struct GameGlobals {char unknown[0x118];Context*context;};
extern "C" {extern GameGlobals lbl_801E9D24;void fn_801F8114(SmartHandle*,Context*,u32);void __ct__15Handle_801F7F10Fv(SmartHandle*);void fn_801F86C8(Context*,SmartHandle*,char);void __dt__15Handle_801F7F10Fv(SmartHandle*,short);Object*fn_801F7EB8(SmartHandle*);}
static inline Object*get(SmartHandle*h){ObjectSlot*s=&lbl_801E9D24.context->data[h->index];return s->type==h->type?s->object:0;}
extern "C" void fn_801F7154(ActionList*o){
 for(int i=0;i<o->size;++i){
  RefRow*row=&(*o)[i];
  for(int j=0;j<row->size;++j){
   RefEntry*entry=&(*row)[j];int type=entry->type;
   if(type==14||type==16||type==23||type==25||type==33||type==15){
    SmartHandle h,temp;fn_801F8114(&temp,lbl_801E9D24.context,entry->reference);__ct__15Handle_801F7F10Fv(&h);h=temp;fn_801F86C8(lbl_801E9D24.context,&temp,1);__dt__15Handle_801F7F10Fv(&temp,-1);
    if(fn_801F7EB8(&h))get(&h)->release();
    __dt__15Handle_801F7F10Fv(&h,0);
   }else if(type==17||type==18||type==19)lbl_801E9D24.context->strings[entry->reference].marked=1;
  }
 }
}
