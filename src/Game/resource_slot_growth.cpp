#include "resource_slot_internal.h"
extern "C" void __ct__15BitSet_80207EE8Fv(void*);
template<class T> struct SlotGrowthArray {
    int size, capacity;
    T* data;

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
        if (count > size) {
            storage(count);
            capacity = count;
            for (int i = size; i < count; ++i)
                new (data + i) T;
            size = count;
        } else if (count < size) {
            for (int i = size - 1; i >= count; --i)
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
struct SlotGrowthName {u32 value;SlotGrowthName(){value=0;}};
struct SlotGrowthHandles : SlotGrowthArray<ResetHandle2> {
    SlotGrowthHandles(){size=0;capacity=0;data=0;}
};
struct SlotGrowthRecord {
    SlotGrowthName name;int references;SlotGrowthBits occupied;SlotGrowthHandles slots;
};
struct SlotGrowthPool {
    SlotGrowthArray<SlotGrowthRecord> records;SlotGrowthBits occupied;int limit,live;
    int vacant(){return limit==0?-1:fn_80207B94(&occupied,0,0);}
};
extern "C" int fn_801E69EC(SlotGrowthPool*self){
    int index=self->vacant();
    ++self->live;
    if(index==-1){
        if(self->records.size+1>self->records.capacity){
            self->records.storage(self->records.capacity+16);
            self->records.capacity+=16;
        }
        new (self->records.data+self->records.size++) SlotGrowthRecord;
        self->occupied.resizeBits(self->limit+1);
        self->occupied.set(self->limit);
        return self->limit++;
    }
    new (&self->records[index]) SlotGrowthRecord;
    self->occupied.set(index);
    return index;
}
