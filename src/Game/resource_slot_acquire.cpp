#include "resource_slot_internal.h"
extern "C" void __ct__15BitSet_80207EE8Fv(void*);
template<class T> struct SlotGrowthArray {
    int size, capacity;
    T* data;

    const int& count(){return size;}
    T& operator[](int index) {
        T* base = data;
        return base[index];
    }

    void storage(int count) {
        if (count) {
            if (data)
                data = (T*)fn_8028FAF4(lbl_8028F698, data,
                                      capacity * sizeof(T), count * sizeof(T));
            else
                data = (T*)fn_8028FF24(lbl_8028F698, count * sizeof(T));
        } else if (data) {
            fn_8028FD50(lbl_8028F698, data, capacity * sizeof(T));
            data = 0;
        }
    }

    void resize(int count) {
        int i;
        if (count > size) {
            storage(count);
            capacity = count;
            for (i = size; i < count; ++i)
                new (data + i) T;
            size = count;
        } else if (count < size) {
            for (i = size - 1; i >= count; --i)
                data[i].~T();
            storage(count);
            capacity = count;
            size = count;
        }
    }
};

struct SlotGrowthBits : SlotGrowthArray<u32> {
    int bits;
    SlotGrowthBits(){__ct__15BitSet_80207EE8Fv(this);}
    void resizeBits(int n){bits=n;if(n && (n>>5)+1>size)resize((bits>>5)+1);}
    void set(int i){data[i>>5]|=1UL<<(i&31);}
};
struct SlotGrowthName {u32 value;SlotGrowthName(){value=0;}bool operator==(const u32& other)const{return value==other;}};
struct SlotGrowthHandles : SlotGrowthArray<ResetHandle2> {
    SlotGrowthHandles(){size=0;capacity=0;data=0;}
};
struct SlotGrowthRecord {
    SlotGrowthName name;int references;SlotGrowthBits occupied;SlotGrowthHandles slots;
};
struct SlotGrowthPool {
    SlotGrowthArray<SlotGrowthRecord> records;SlotGrowthBits occupied;int limit,live;
    int first(){return limit==0?-1:fn_80207B94(&occupied,1,0);}
    int next(int i){return i+1>=limit?-1:fn_80207B94(&occupied,1,i+1);}
    int vacant(){return limit==0?-1:fn_80207B94(&occupied,0,0);}
};

extern "C" {
int fn_801E69EC(SlotGrowthPool*);
OwnerHandle fn_80263308(void*,const u32*);
void fn_80207DE4(void*,int,int);
void* memset(void*,int,unsigned long);
char* strcat(char*,const char*);
extern const char lbl_802ACED0[];
}
struct AcquireHandle : OwnerHandle {
    AcquireHandle(const ResetCopy1& h){value=h.value;fn_801F86C8(lbl_801E9D24.manager,&h,1);}
};
struct AcquireEntity : Activable_Z {
    OwnerHandle handle1C,handle20;
    const OwnerHandle& first(){return handle1C;}
    const OwnerHandle& second(){return handle20;}
};
struct SlotFactory : Activable_Z {
    virtual void slot2C();
    virtual void slot30(ResetHandle2*,OwnerHandle*);
};
struct SlotLookupGlobals {char unknown[0x14C];void* lookup;};
extern "C" int fn_801E5FDC(SlotGrowthPool*self,const u32*name,int count,OwnerHandle*out){
    AcquireHandle resource(ResetCopy1(fn_80263308(((SlotLookupGlobals*)&lbl_801E9D24)->lookup,name)));
    char buffer[128];buffer[0]=0;strcat(buffer,lbl_802ACED0);
    if(!fn_801F7EB8(&resource))return -1;
    *out=((AcquireEntity*)resource.get())->first();
    ResetCopy1 factory(((AcquireEntity*)resource.get())->second());
    int index=self->first();
    while(index>=0){
        if(self->records[index].name==*name){
            if(count>self->records[index].slots.count()){
                int old=self->records[index].slots.count();
                self->records[index].slots.resize(count);
                self->records[index].occupied.resizeBits(count);
                for(int i=old;i<count;++i){
                    SlotFactory* f=(SlotFactory*)factory.get();
                    f->slot30(&self->records[index].slots[i],out);
                }
                fn_80207DE4(&self->records[index].occupied,old,count);
            }
            ++self->records[index].references;
            return index;
        }
        index=self->next(index);
    }
    int created=fn_801E69EC(self);
    self->records[created].name.value=*name;
    self->records[created].references=1;
    self->records[created].slots.resize(count);
    self->records[created].occupied.resizeBits(count);
    SlotGrowthBits& bits=self->records[created].occupied;
    if(bits.size)memset(bits.data,0,bits.size*4);
    for(int i=0;i<count;++i){
        SlotFactory* f=(SlotFactory*)factory.get();
        f->slot30(&self->records[created].slots[i],out);
    }
    return created;
}
