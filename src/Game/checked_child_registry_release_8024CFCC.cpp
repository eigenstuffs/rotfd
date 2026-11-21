// Release child callbacks and both registry bindings after the base state accepts.
struct HandleIndex{const int value;HandleIndex(int v):value(v){}operator int()const{return value;}};
struct CheckedActivateHandle {signed int generation:8;signed int index:24;};
typedef unsigned long CheckedActivateWord;
struct RegistryBase;
struct RootStorage_80207414 {CheckedActivateWord unknown00;union{CheckedActivateWord identity;CheckedActivateHandle handle;};};
struct BaseObject_Z:RootStorage_80207414 {BaseObject_Z();virtual ~BaseObject_Z();virtual void slot0C(unsigned long);virtual void slot10();virtual void slot14();virtual void slot18();virtual signed char slot1C();};
struct CheckedActivateEntry {BaseObject_Z*object;CheckedActivateWord key;unsigned long unknown08;signed char generation;char unknown0D[3];bool matchesGeneration(signed char g)const{return generation==g;}BaseObject_Z*getObject()const{return object;}CheckedActivateWord getKey()const{return key;}};
struct CheckedActivateEntries{CheckedActivateEntry*p;CheckedActivateEntry&operator[](const HandleIndex&i)const{return p[i];}};
struct CheckedActivateManager {int count,capacity;CheckedActivateEntries entries;};
struct CheckedActivateOwner:BaseObject_Z {char unknown0C[0x74];int count,capacity;CheckedActivateHandle*handles;};
extern "C" {
extern struct {char unknown00[0x118];CheckedActivateManager*manager;char unknown11C[0x28];RegistryBase*first;char unknown148[0x10];RegistryBase*second;}lbl_801E9D24;
void*fn_801F7EB8(const void*);
void fn_801F6624(RegistryBase*,const CheckedActivateWord*,const CheckedActivateWord*);
}
static inline BaseObject_Z*resolveCheckedActivate(const CheckedActivateHandle&h){CheckedActivateManager*m=lbl_801E9D24.manager;const HandleIndex index(h.index);signed char generation=h.generation;if(m->entries[index].matchesGeneration(generation))return m->entries[index].getObject();return 0;}
static inline CheckedActivateWord lookupCheckedActivate(const CheckedActivateHandle&h){CheckedActivateManager*m=lbl_801E9D24.manager;const HandleIndex index(h.index);signed char generation=h.generation;int valid=0;if(index<m->count&&generation==((signed char*)m->entries.p)[index*sizeof(CheckedActivateEntry)+12])valid=1;if(valid)return *(CheckedActivateWord*)((char*)m->entries.p+index*sizeof(CheckedActivateEntry)+4);return 0;}
extern "C" signed char fn_8024CFCC(CheckedActivateOwner*self){
 if(!self->BaseObject_Z::slot1C())return 0;
 for(int i=0;i<self->count;++i)if(fn_801F7EB8(&self->handles[i]))resolveCheckedActivate(self->handles[i])->slot1C();
 CheckedActivateWord key=lookupCheckedActivate(self->handle);
 if(lbl_801E9D24.first)fn_801F6624(lbl_801E9D24.first,&self->unknown00,&key);
 if(lbl_801E9D24.second)fn_801F6624(lbl_801E9D24.second,&self->unknown00,&key);
 return 1;
}

typedef char CheckedActivateHandleSize[sizeof(CheckedActivateHandle)==4?1:-1];
typedef char CheckedActivateRootSize[sizeof(BaseObject_Z)==12?1:-1];
typedef char CheckedActivateEntrySize[sizeof(CheckedActivateEntry)==16?1:-1];
typedef char CheckedActivateOwnerSize[sizeof(CheckedActivateOwner)==0x8C?1:-1];
