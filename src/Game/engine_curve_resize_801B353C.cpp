#include "Game/registry_abi_tables.h"
extern "C" {
    extern char lbl_8028F698[],lbl_801EF5C8[],__vt__24CurveRecordBase_802E9E08[];
    void *fn_8028FAF4(void*,void*,int,int);
    void *fn_8028FF24(void*,int);
    void fn_8028FD50(void*,void*,int);
    void fn_801EF610(void*,void*);
}
inline void*operator new(unsigned long,void*p) {
    return p;
}
template <int N> struct Element_801B353C {
    char data[N];
    ~Element_801B353C() {
    }
};
template <class T> struct Pool_801B353C {
    int count,capacity;
    T*data;
    Pool_801B353C() {
        count=0;
        capacity=0;
        data=0;
    }
    ~Pool_801B353C() {
        if(data) {
            for(int i=0; i<count; i++)data[i].~T();
            if(data) {
                fn_8028FD50(lbl_8028F698,data,capacity*sizeof(T));
                data=0;
            }
            data=0;
        }
    }
};
struct CurveBase_801B1088 {
    unsigned short flags,unknown;
    CurveBase_801B1088();
    ~CurveBase_801B1088();
};
template <int N> struct Curve_801B353C:CurveBase_801B1088 {
    Pool_801B353C<Element_801B353C<N> > records;
    Curve_801B353C() {
    }
    ~Curve_801B353C() {
    }
};
struct RecordRoot_801B353C {
    int first;
    short id,unknown;
    void*vtable;
    RecordRoot_801B353C() {
        vtable=__vt__24CurveRecordBase_802E9E08;
        first=0;
        id=-1;
    }
    ~RecordRoot_801B353C() {
    }
};
template <class T> struct Array_801B353C {
    int count,capacity;
    T*data;
    inline void reserve(int n) {
        if(n) {
            if(data)data=(T*)fn_8028FAF4(lbl_8028F698,data,capacity*sizeof(T),n*sizeof(T));
            else data=(T*)fn_8028FF24(lbl_8028F698,n*sizeof(T));
        }
        else if(data) {
            fn_8028FD50(lbl_8028F698,data,capacity*sizeof(T));
            data=0;
        }
        capacity=n;
    }
};
extern "C" {
    
    void fn_801B27AC(void*,int);
}
template <class T> struct ActionArray_801B353C {
    int count,capacity;
    T*data;
    ActionArray_801B353C() {
    }
    ~ActionArray_801B353C() {
        if(data) {
            for(int i=0; i<count; i++)data[i].~T();
            if(data) {
                fn_8028FD50(lbl_8028F698,data,capacity*sizeof(T));
                data=0;
            }
            data=0;
        }
    }
};
struct ActionEntry_801B353C {
    int type,index,unknown;
    ~ActionEntry_801B353C() {
    }
};
struct ActionRow_801B353C {
    int prefix;
    ActionArray_801B353C<ActionEntry_801B353C> entries;
    ~ActionRow_801B353C() {
    }
};
struct WorldActionCurve_801F7560:CurveBase_801B1088 {
    ActionArray_801B353C<ActionRow_801B353C> rows;
    WorldActionCurve_801F7560() {
        rows.count=0;
        rows.capacity=0;
        rows.data=0;
    }
    virtual ~WorldActionCurve_801F7560();
    static void operator delete(void*p) {
        fn_801EF610(lbl_801EF5C8,p);
    }
};
struct RecordBase_801B353C:RecordRoot_801B353C {
    RecordBase_801B353C() {
        vtable=&lbl_802E9DD8;
    }
    ~RecordBase_801B353C() {
    }
};
struct Record_801B353C:RecordBase_801B353C {
    Curve_801B353C<20> a,b,c;
    WorldActionCurve_801F7560 action;
    Record_801B353C() {
    }
    ~Record_801B353C() {
    }
};
extern "C" void fn_801B353C(Array_801B353C<Record_801B353C>*self,int n,signed char keep) {
    int j;
    if(n>self->count) {
        if(n>self->capacity||!keep)self->reserve(n);
        for(int i=self->count; i<n; i++)new(&self->data[i]) Record_801B353C;
        self->count=n;
    }
    else if(n<self->count) {
        for(j=self->count-1; j>=n; --j)fn_801B27AC(&self->data[j],-1);
        if(keep)self->count=n;
        else {
            self->reserve(n);
            self->count=n;
        }
    }
}
