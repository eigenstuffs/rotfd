// Dispatch corresponding generation-checked child records by array position.
struct PairedDispatchIdentity { union {unsigned long value;struct {signed int generation:8;signed int index:24;}bits;}; };
// Root prefix and initial virtual slots agree with the accepted spatial root.
struct RootStorage_80207414 {unsigned long unknown00,identity;};
struct BaseObject_Z : RootStorage_80207414 {
 BaseObject_Z();virtual ~BaseObject_Z();virtual void slot0C(unsigned long);virtual void slot10();virtual void slot14();virtual void slot18();virtual signed char slot1C();
};
struct PairedDispatchObject:BaseObject_Z {
 virtual void slot20();virtual void slot24();virtual void slot28();virtual void slot2C();
 virtual void dispatch(void*,PairedDispatchObject*);
};
struct HandleIndex {const int value;HandleIndex(int v):value(v){}operator int()const{return value;}};
struct PairedDispatchEntry { PairedDispatchObject* object; unsigned long name,unknown08;signed char generation;char unknown0D[3];bool matchesGeneration(signed char g)const{return generation==g;}PairedDispatchObject*getObject()const{return object;}};
struct PairedDispatchEntries {PairedDispatchEntry*p;PairedDispatchEntry&operator[](const HandleIndex&i)const{return p[i];}};
struct PairedDispatchManager {int count,capacity;PairedDispatchEntries entries;};
struct PairedDispatchOwner {char unknown00[0x80];int count,capacity;PairedDispatchIdentity*handles;};
struct PairedDispatchOther {char unknown00[0x6C];PairedDispatchIdentity*handles;};
extern "C" struct {char unknown00[0x118];PairedDispatchManager*manager;}lbl_801E9D24;
static inline PairedDispatchObject* resolvePaired(const PairedDispatchIdentity& handle)
{
    PairedDispatchManager*manager=lbl_801E9D24.manager;
    const HandleIndex index(handle.bits.index);
    const signed char generation=handle.bits.generation;
    if(manager->entries[index].matchesGeneration(generation))return manager->entries[index].getObject();return 0;
}
extern "C" void fn_8024CEDC(PairedDispatchOwner*self,void* argument,PairedDispatchOther*other)
{
    for(int i=0;i<self->count;++i){
        PairedDispatchObject* first=resolvePaired(self->handles[i]);
        first->dispatch(argument,resolvePaired(other->handles[i]));
    }
}

typedef char PairedIdentitySize[(sizeof(PairedDispatchIdentity)==4)?1:-1];
typedef char PairedRootSize[(sizeof(BaseObject_Z)==12)?1:-1];
typedef char PairedEntrySize[(sizeof(PairedDispatchEntry)==16)?1:-1];
typedef char PairedManagerSize[(sizeof(PairedDispatchManager)==12)?1:-1];
typedef char PairedOwnerSize[(sizeof(PairedDispatchOwner)==0x8C)?1:-1];
typedef char PairedOtherSize[(sizeof(PairedDispatchOther)==0x70)?1:-1];
