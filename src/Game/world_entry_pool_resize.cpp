#include "world_curve_arrays_internal.h"
template<class T> struct LoadArray {int count,capacity;T*data;};
template<class T> inline void storage(LoadArray<T>*a,int n){
    if(n){
        if(a->data)a->data=(T*)fn_8028FAF4(lbl_8028F698,a->data,a->capacity*sizeof(T),n*sizeof(T));
        else a->data=(T*)fn_8028FF24(lbl_8028F698,n*sizeof(T));
    }else if(a->data){fn_8028FD50(lbl_8028F698,a->data,a->capacity*sizeof(T));a->data=0;}
    a->capacity=n;
}
template<class T> inline void resize(LoadArray<T>*a,int n){
    int i;
    if(n>a->count){
        storage(a,n);
        for(i=a->count;i<n;++i)new(a->data+i)T;
        a->count=n;
    }else if(n<a->count){
        for(i=a->count-1;i>=n;--i)a->data[i].~T();
        storage(a,n);a->count=n;
    }
}

struct WorldEntry16 {u32 field0;int field4;u32 unknown8,unknownC;WorldEntry16(){field0=0;field4=-1;}};
struct WorldPoolBits:LoadArray<u32>{int bits;void setSize(int n){bits=n;if(n &&(n>>5)+1>count)resize((LoadArray<u32>*)this,(bits>>5)+1);}};
struct WorldEntryPool {LoadArray<WorldEntry16> entries;WorldPoolBits occupied;int limit;};
static inline void resizeEntries(LoadArray<WorldEntry16>*a,int n){
    if(n>a->count){
        storage(a,n);
        for(int i=a->count;i<n;++i)new(a->data+i)WorldEntry16;
        a->count=n;
    }else if(n<a->count){storage(a,n);a->count=n;}
}
extern "C" void fn_80207DE4(void*,int,int);
extern "C" void fn_801E9A24(WorldEntryPool*self,int n){
    resizeEntries(&self->entries,n);
    self->occupied.setSize(n);
    fn_80207DE4(&self->occupied,self->limit,n-1);
    self->limit=n;
}

// The pool has no element cleanup when its record storage shrinks.
typedef char CheckWorldEntry16[sizeof(WorldEntry16)==16?1:-1];
typedef char CheckWorldEntryPool[sizeof(WorldEntryPool)==0x20?1:-1];
