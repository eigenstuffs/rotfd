#include "Game/registry_abi_tables.h"
extern "C" {
    extern char lbl_8028F698[],lbl_801EF5C8[];
    void fn_8028FD50(void*,void*,int);
    void fn_801EF610(void*,void*);
}
template<int N>struct Element_801B27AC{
    char data[N];
    ~Element_801B27AC(){
    }
}
;
template<class T>struct Pool_801B27AC{
    int count,capacity;
    T*data;
    ~Pool_801B27AC(){
        if(data){
            for(int i=0;
            i<count;
            i++)data[i].~T();
            if(data){
                fn_8028FD50(lbl_8028F698,data,capacity*sizeof(T));
                data=0;
            }
            data=0;
        }
    }
}
;
struct CurveBase_801B1088{
    int unknown;
    ~CurveBase_801B1088();
}
;
extern "C" {
    
}
struct Curve_801B27AC:CurveBase_801B1088{
    Pool_801B27AC<Element_801B27AC<20> > records;
    ~Curve_801B27AC(){
    }
}
;
struct WorldActionCurve_801F7560{
    char data[20];
    ~WorldActionCurve_801F7560();
}
;
struct Object_801B27AC{
    char pad[8];
    void*vtable;
    Curve_801B27AC first,second,third;
    WorldActionCurve_801F7560 action;
}
;
extern "C" Object_801B27AC *fn_801B27AC(Object_801B27AC*self,short release){
    if(self){
        self->vtable=&lbl_802E9DD8;
        self->action.~WorldActionCurve_801F7560();
        self->third.~Curve_801B27AC();
        self->second.~Curve_801B27AC();
        self->first.~Curve_801B27AC();
        if(release>0)fn_801EF610(lbl_801EF5C8,self);
    }
    return self;
}
