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
template <int N> struct Element_801B2AC8 {
    char data[N];
    ~Element_801B2AC8() {
    }
};
template <class T> struct Pool_801B2AC8 {
    int count,capacity;
    T*data;
    Pool_801B2AC8() {
        count=0;
        capacity=0;
        data=0;
    }
    ~Pool_801B2AC8() {
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
template <int N> struct Curve_801B2AC8:CurveBase_801B1088 {
    Pool_801B2AC8<Element_801B2AC8<N> > records;
    Curve_801B2AC8() {
    }
    ~Curve_801B2AC8() {
    }
};
struct RecordRoot_801B2AC8 {
    int first;
    short id,unknown;
    void*vtable;
    RecordRoot_801B2AC8() {
        vtable=__vt__24CurveRecordBase_802E9E08;
        first=0;
        id=-1;
    }
    ~RecordRoot_801B2AC8() {
    }
};
template <class T> struct Array_801B2AC8 {
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
}
struct Object_801B2AC8 {
    char pad[8];
    void*vtable;
    Curve_801B2AC8<16> a,b,c,d,e;
    Curve_801B2AC8<20> f,g;
    Curve_801B2AC8<16> h;
};
extern "C" Object_801B2AC8 *fn_801B2AC8(Object_801B2AC8*self,short release) {
    if(self) {
        self->vtable=lbl_802E9E14;
        self->h.~Curve_801B2AC8();
        self->g.~Curve_801B2AC8();
        self->f.~Curve_801B2AC8();
        self->e.~Curve_801B2AC8();
        self->d.~Curve_801B2AC8();
        self->c.~Curve_801B2AC8();
        self->b.~Curve_801B2AC8();
        self->a.~Curve_801B2AC8();
        if(release>0)fn_801EF610(lbl_801EF5C8,self);
    }
    return self;
}
