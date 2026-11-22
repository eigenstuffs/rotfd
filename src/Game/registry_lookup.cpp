typedef unsigned long u32;
struct HashTable { int cursor,capacity,count; void**slots; };
struct BitFlags { int size,capacity; u32*words; int bits; };
template<class T>struct Pool {int size,capacity;T*data;BitFlags flags;int limit,count;};
struct RegistryBase {HashTable root;Pool<u32>first,second;Pool<HashTable>tables;const void*vtable;};
struct SmartHandle {unsigned int type:8;unsigned int value:24;};
struct GameGlobals {char unknown[0x118];void*context;};
struct IntegerKey {int tag;const void*vtable;int value;};
extern "C" {
extern GameGlobals lbl_801E9D24;
void fn_80208BFC(IntegerKey*,int);
char fn_802082E8(HashTable*,IntegerKey*,u32**);
void fn_801F8114(SmartHandle*,void*,u32);
void fn_801F5C04(SmartHandle*out,RegistryBase*r,int index,u32 keyValue){
 IntegerKey key;fn_80208BFC(&key,keyValue);u32*found;
 if(!fn_802082E8(&r->tables.data[index],&key,&found)){out->value=0;*(char*)out=0;}
 else fn_801F8114(out,lbl_801E9D24.context,*found);
}
}
