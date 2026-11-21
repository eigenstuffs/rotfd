#include "world_curve_arrays_internal.h"
struct RenderRecord40 { unsigned char bytes[40]; };
struct RenderRecordOwnerView {
    unsigned char unknown[0xDA00];
    WorldCurveArray<RenderRecord40> records;
};
template<class T> inline void reserveRecords(WorldCurveArray<T>*a,int n){
    if(n){
        if(a->data)a->data=(T*)fn_8028FAF4(lbl_8028F698,a->data,a->capacity*sizeof(T),n*sizeof(T));
        else a->data=(T*)fn_8028FF24(lbl_8028F698,n*sizeof(T));
    }else if(a->data){
        fn_8028FD50(lbl_8028F698,a->data,a->capacity*sizeof(T));a->data=0;
    }
}
template<class T> inline void resizeRecords(WorldCurveArray<T>*a,int n){
    if(n>a->count){
        if(n>a->capacity){reserveRecords(a,n);a->capacity=n;}
        for(int i=a->count;i<n;++i)new(a->data+i)T;
        a->count=n;
    }else if(n<a->count){
        for(int i=a->count-1;i>=n;--i)a->data[i].~T();
        a->count=n;
    }
}
extern "C" void fn_801E81AC(RenderRecordOwnerView*self){resizeRecords(&self->records,0);}
