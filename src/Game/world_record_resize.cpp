// Native construction/destruction around record-array resizing.
// Template-dependent code emission reverses these definitions in the object.
#include "world_records_internal.h"
extern "C" {
extern char lbl_8028F698[];
void* fn_8028FAF4(void*,void*,u32,u32);
void* fn_8028FF24(void*,u32);
void fn_8028FD50(void*,void*,u32);
}
inline void* operator new(unsigned long,void* p){return p;}
template<class T> inline void storage(WorldRecordArray<T>* self,int size) {
    if (size) {
        if(self->data) self->data=(T*)fn_8028FAF4(lbl_8028F698,self->data,self->capacity*sizeof(T),size*sizeof(T));
        else self->data=(T*)fn_8028FF24(lbl_8028F698,size*sizeof(T));
    } else if(self->data) {
        fn_8028FD50(lbl_8028F698,self->data,self->capacity*sizeof(T));
        self->data=0;
    }
    self->capacity=size;
}
extern "C" void fn_801E3868(WorldRecordArray<WorldRecord1C>* self,int size,signed char keep) {
    if(size>self->count) {
        if(size>self->capacity||!keep) storage(self,size);
        for(int i=self->count;i<size;++i) new(&self->data[i]) WorldRecord1C;
        self->count=size;
    } else if(size<self->count) {
        for(int i=self->count-1;i>=size;--i) self->data[i].~WorldRecord1C();
        if(keep) self->count=size;
        else {storage(self,size);self->count=size;}
    }
}

extern "C" void fn_801E3614(WorldRecordArray<WorldRecord14>* self,int size,signed char keep) {
    if(size>self->count) {
        if(size>self->capacity||!keep) storage(self,size);
        for(int i=self->count;i<size;++i) new(&self->data[i]) WorldRecord14;
        self->count=size;
    } else if(size<self->count) {
        for(int i=self->count-1;i>=size;--i) self->data[i].~WorldRecord14();
        if(keep) self->count=size;
        else {storage(self,size);self->count=size;}
    }
}
