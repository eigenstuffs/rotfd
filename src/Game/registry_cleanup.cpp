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
static inline int equals(const u32&a,const u32&b){return a==b;}
static inline u32&at(Pool<u32>*p,int i){return p->data[i];}
extern "C" {
char fn_801F5E14(RegistryBase*r){
 int i=r->tables.limit==0?-1:fn_80207B94(&r->tables.flags,1,0);
 while(i>=0){
  fn_802082C4(&r->tables.data[i]);
  u32*value=fn_80208240(&r->tables.data[i]);
  while(value){
   Object*obj;{SmartHandle h;fn_801F8114(&h,lbl_801E9D24.context,*value);obj=fn_801F7EB8(&h);__dt__15Handle_801F7F10Fv(&h,-1);}
   if(obj)obj->release();
   value=fn_80208240(&r->tables.data[i]);
  }
  i=i+1>=r->tables.limit?-1:fn_80207B94(&r->tables.flags,1,i+1);
 }
 return 1;
}
char fn_801F5F28(RegistryBase*r,const u32*a,const u32*b,long*out,char create){
 *out=r->first.limit==0?-1:fn_80207B94(&r->first.flags,1,0);
 while(*out>=0){
  if(equals(*a,at(&r->first,*out))&&equals(*b,at(&r->second,*out)))return 1;
  *out=*out+1>=r->first.limit?-1:fn_80207B94(&r->first.flags,1,*out+1);
 }
 if(create){u32 va=*a;fn_801F6330(&r->first,&va);u32 vb=*b;fn_801F6330(&r->second,&vb);*out=fn_801F6038(&r->tables);}
 return 0;
}
}
