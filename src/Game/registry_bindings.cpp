typedef unsigned long u32;
struct HashTable { int cursor,capacity,count; void**slots; };
struct BitFlags { int size,capacity; u32*words; int bits; };
template<class T>struct Pool {int size,capacity;T*data;BitFlags flags;int limit,count;};
struct RegistryBase {HashTable root;Pool<u32>first,second;Pool<HashTable>tables;const void*vtable;};
struct SmartHandle {unsigned int type:8;unsigned int value:24;};
struct GameGlobals {char unknown[0x118];void*context;};
struct ObjectPrefix {u32 unknown[2];};
struct Object:ObjectPrefix {
    virtual void slot8();virtual void slotC();virtual void slot10();
    virtual void slot14();virtual void slot18();virtual void release();
};
extern "C" {
extern GameGlobals lbl_801E9D24;
void fn_801F8114(SmartHandle*,void*,u32);
Object*fn_801F7EB8(SmartHandle*);
void __dt__15Handle_801F7F10Fv(SmartHandle*,short);
int fn_80207B94(BitFlags*,int,int);
void fn_802082C4(HashTable*);
u32*fn_80208240(HashTable*);
int fn_801F6330(Pool<u32>*,const u32*);
int fn_801F6038(Pool<HashTable>*);
}
struct IntegerKey {int tag;const void*vtable;int value;};
extern "C" {
char fn_801F5F28(RegistryBase*,const u32*,const u32*,long*,char);
void __ct__15Handle_801F7F10Fv(SmartHandle*);
void fn_801B3F0C(void*,SmartHandle*,u32);
u32 fn_801F84D4(void*,SmartHandle*);
void*fn_801E9F40(void*,void*,int);
void fn_80208BFC(IntegerKey*,int);
void fn_801B417C(void*,IntegerKey*,void**);
char fn_802083C8(HashTable*,IntegerKey*,u32**,char);
void fn_802086C8(HashTable*,int);
void fn_801F6624(RegistryBase*r,const u32*a,const u32*b){
 long index;
 if(fn_801F5F28(r,a,b,&index,0)){
  fn_802082C4(&r->tables.data[index]);
  u32*value=fn_80208240(&r->tables.data[index]);
  while(value){
   Object*obj;
   {SmartHandle h;fn_801F8114(&h,lbl_801E9D24.context,*value);obj=fn_801F7EB8(&h);__dt__15Handle_801F7F10Fv(&h,-1);}
   if(obj)obj->release();
   value=fn_80208240(&r->tables.data[index]);
  }
 }
}
void fn_801F6710(RegistryBase*r,const u32*a,const u32*b){
 long index;
 fn_801F5F28(r,a,b,&index,1);
 fn_802082C4(&r->tables.data[index]);
 u32*value=fn_80208240(&r->tables.data[index]);
 while(value){
  {SmartHandle h;__ct__15Handle_801F7F10Fv(&h);fn_801B3F0C(lbl_801E9D24.context,&h,*value);*value=fn_801F84D4(lbl_801E9D24.context,&h);value=fn_80208240(&r->tables.data[index]);__dt__15Handle_801F7F10Fv(&h,-1);}
 }
}
void fn_801F67E4(RegistryBase*r,const u32*a,const u32*b,void**stream){
 IntegerKey key;long index;int count;u32*found;
 fn_801F5F28(r,a,b,&index,1);
 *stream=fn_801E9F40(&count,*stream,4);
 for(int i=0;i<count;++i){
  fn_80208BFC(&key,-1);
  *stream=fn_801E9F40(&key.value,*stream,4);
  fn_801B417C(lbl_801E9D24.context,&key,stream);
  fn_802083C8(&r->tables.data[index],&key,&found,1);
 }
}
void fn_801F68A4(RegistryBase*r){
 fn_802086C8(&r->root,1);
 int index=r->tables.limit==0?-1:fn_80207B94(&r->tables.flags,1,0);
 while(index>=0){
  fn_802086C8(&r->tables.data[index],1);
  index=index+1>=r->tables.limit?-1:fn_80207B94(&r->tables.flags,1,index+1);
 }
}
}
