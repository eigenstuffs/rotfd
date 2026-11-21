#ifndef GAME_WORLD_CURVE_ARRAYS_INTERNAL_H
#define GAME_WORLD_CURVE_ARRAYS_INTERNAL_H
#include "objects_owner_internal.h"
// Recovered native curve ownership; class names identify observed addresses.
extern "C" {
extern char lbl_8028F698[];
void* fn_8028FAF4(void*,void*,u32,u32);
void* fn_8028FF24(void*,u32);
void fn_8028FD50(void*,void*,u32);
}
inline void* operator new(unsigned long,void* p){return p;}
struct CurveBase_801B1088 {
    unsigned short flags, unknown;
    CurveBase_801B1088();
    ~CurveBase_801B1088();
};
template<int Size> struct WorldCurveKey {char unknown[Size]; ~WorldCurveKey(){}};
template<class T> struct WorldCurveArray {
    int count,capacity; T*data;
    WorldCurveArray():count(0),capacity(0),data(0){}
    ~WorldCurveArray(){
        if(data){
            for(int i=0;i<count;++i) data[i].~T();
            if(data){fn_8028FD50(lbl_8028F698,data,capacity*sizeof(T));data=0;}
            data=0;
        }
    }
};
template<int Size> struct WorldCurve : CurveBase_801B1088 {
    WorldCurveArray<WorldCurveKey<Size> > keys;
    WorldCurve(){}
    ~WorldCurve(){}
};
struct WorldCurvePrefix {u32 unknown;short id,flags;};
struct CurveRecordBase_802E9E08 : WorldCurvePrefix {
    virtual void reset();
    CurveRecordBase_802E9E08(){unknown=0;id=-1;}
};
struct CurveRecord3C_802EA7E4 : CurveRecordBase_802E9E08 {
    WorldCurve<20> curve0C;WorldCurve<16> curve1C,curve2C;
    CurveRecord3C_802EA7E4(){}
    ~CurveRecord3C_802EA7E4();
    static void operator delete(void*p){fn_801EF610(lbl_801EF5C8,p);}
};
struct CurveRecord4C_802EA7D8 : CurveRecordBase_802E9E08 {
    WorldCurve<16> curve0C,curve1C,curve2C,curve3C;
    CurveRecord4C_802EA7D8(){}
    ~CurveRecord4C_802EA7D8();
    static void operator delete(void*p){fn_801EF610(lbl_801EF5C8,p);}
};
template<class T> struct CurveRecordArray {int count,capacity;T*data;};
template<class T> inline void storage(CurveRecordArray<T>*self,int size){
    if(size){
        if(self->data)self->data=(T*)fn_8028FAF4(lbl_8028F698,self->data,self->capacity*sizeof(T),size*sizeof(T));
        else self->data=(T*)fn_8028FF24(lbl_8028F698,size*sizeof(T));
    }else if(self->data){fn_8028FD50(lbl_8028F698,self->data,self->capacity*sizeof(T));self->data=0;}
    self->capacity=size;
}
typedef char CheckCurveBase[sizeof(CurveBase_801B1088)==4?1:-1];
typedef char CheckCurve3C[sizeof(CurveRecord3C_802EA7E4)==0x3C?1:-1];
typedef char CheckCurve4C[sizeof(CurveRecord4C_802EA7D8)==0x4C?1:-1];
#endif
