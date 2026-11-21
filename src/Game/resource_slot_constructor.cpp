#include "resource_slot_lifetime_internal.h"
extern "C" {
void* memset(void*,int,unsigned long);
int sprintf(char*,const char*,...);
u32 fn_801F948C(void*,const char*);
Handle_801F7F10 fn_801B550C(Manager*,const void*,const void*);
extern const char lbl_8037A5B0[5];
extern const char lbl_802ACEF0[];
}
template<class T> inline     void reserveArray(WorldCurveArray<T>* self,int n) {
        if (n) {
            if (self->data)
                self->data = (T*)fn_8028FAF4(lbl_8028F698, self->data,
                                      self->capacity * sizeof(T), n * sizeof(T));
            else
                self->data = (T*)fn_8028FF24(lbl_8028F698, n * sizeof(T));
        } else if (self->data) {
            fn_8028FD50(lbl_8028F698, self->data, self->capacity * sizeof(T));
            self->data = 0;
        }
    }

template<class T> inline void resizeArray(WorldCurveArray<T>* self,int n){
    int i;
    if(n>self->count){
        reserveArray(self,n);self->capacity=n;
        for(i=self->count;i<n;++i)new(self->data+i)T;
        self->count=n;
    }else if(n<self->count){
        for(i=self->count-1;i>=n;--i)self->data[i].~T();
        reserveArray(self,n);self->capacity=n;self->count=n;
    }
}
inline     void reserveBits(BitSet_80207EE8* self,int n) {
        if (n) {
            if (self->words)
                self->words = (u32*)fn_8028FAF4(lbl_8028F698, self->words,
                                      self->capacity * sizeof(u32), n * sizeof(u32));
            else
                self->words = (u32*)fn_8028FF24(lbl_8028F698, n * sizeof(u32));
        } else if (self->words) {
            fn_8028FD50(lbl_8028F698, self->words, self->capacity * sizeof(u32));
            self->words = 0;
        }
    }

inline void resizeWords(BitSet_80207EE8* self,int n){
    int i;
    if(n>self->count){
        reserveBits(self,n);self->capacity=n;
        for(i=self->count;i<n;++i)new(self->words+i)u32;
        self->count=n;
    }else if(n<self->count){
        for(i=self->count-1;i>=n;--i)self->words[i].~u32();
        reserveBits(self,n);self->capacity=n;self->count=n;
    }
}

static inline void resizeBits(BitSet_80207EE8*self,int n){self->bits=n;if(n&&(n>>5)+1>self->count)resizeWords(self,(self->bits>>5)+1);}
struct SlotInitName {u32 value;SlotInitName(const char*s){value=fn_801F948C(this,s);}};
struct SlotInitCopy : OwnerHandle {SlotInitCopy(const Handle_801F7F10&h){value=h.value;fn_801F86C8(lbl_801E9D24.manager,&h,1);}};
SlotResource_802EA810::SlotResource_802EA810(){
    __ct__15BitSet_80207EE8Fv(&extraOccupied);
    resizeArray(&extra,128);
    resizeBits(&extraOccupied,128);
    if(extraOccupied.count)memset(extraOccupied.words,0,extraOccupied.count*4);
    char buffer[64];
    for(int i=0;i<128;++i){
        sprintf(buffer,lbl_802ACEF0,i);
        SlotInitName type(lbl_8037A5B0);
        SlotInitName name(buffer);
        ((OwnerHandle&)extra.data[i])=SlotInitCopy(fn_801B550C(lbl_801E9D24.manager,&type,&name));
    }
}
