/* Original engine lifetime and record routines.
 * See docs/notes/game-engine-curve-resize.md. */
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
template <int N> struct Element_801B3288 {
    char data[N];
    ~Element_801B3288() {
    }
};
template <class T> struct Pool_801B3288 {
    int count,capacity;
    T*data;
    Pool_801B3288() {
        count=0;
        capacity=0;
        data=0;
    }
    ~Pool_801B3288() {
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
template <int N> struct Curve_801B3288:CurveBase_801B1088 {
    Pool_801B3288<Element_801B3288<N> > records;
    Curve_801B3288() {
    }
    ~Curve_801B3288() {
    }
};
struct RecordRoot_801B3288 {
    int first;
    short id,unknown;
    void*vtable;
    RecordRoot_801B3288() {
        vtable=__vt__24CurveRecordBase_802E9E08;
        first=0;
        id=-1;
    }
    ~RecordRoot_801B3288() {
    }
};
template <class T> struct Array_801B3288 {
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
    extern char lbl_802E9E14[];
    void fn_801B2AC8(void*,int);
}
struct RecordBase_801B3288:RecordRoot_801B3288 {
    RecordBase_801B3288() {
        vtable=lbl_802E9E14;
    }
    ~RecordBase_801B3288() {
    }
};
struct Record_801B3288:RecordBase_801B3288 {
    Curve_801B3288<16> a,b,c,d,e;
    Curve_801B3288<20> f,g;
    Curve_801B3288<16> h;
    Record_801B3288() {
    }
    ~Record_801B3288() {
    }
};
extern "C" void fn_801B3288(Array_801B3288<Record_801B3288>*self,int n,signed char keep) {
    if(n>self->count) {
        if(n>self->capacity||!keep)self->reserve(n);
        for(int i=self->count; i<n; i++)new(&self->data[i]) Record_801B3288;
        self->count=n;
    }
    else if(n<self->count) {
        for(int i=self->count-1; i>=n; i--)fn_801B2AC8(&self->data[i],-1);
        if(keep)self->count=n;
        else {
            self->reserve(n);
            self->count=n;
        }
    }
}
