/* Original engine lifetime and record routines.
* See docs/notes/game-engine-pool-resize.md. */
extern "C" {
    extern char lbl_8028F698[],lbl_801EF5C8[];
    void *fn_8028FAF4(void*,void*,int,int);
    void *fn_8028FF24(void*,int);
    void fn_8028FD50(void*,void*,int);
    void fn_801EF610(void*,void*);
}
inline void*operator new(unsigned long,void*p){
    return p;
}
template<int N>struct Element_801B378C{
    char data[N];
    ~Element_801B378C(){
    }
}
;
template<class T>struct Pool_801B378C{
    int count,capacity;
    T*data;
    Pool_801B378C(){
        count=0;
        capacity=0;
        data=0;
    }
    ~Pool_801B378C(){
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
template<class T>struct Vector_801B378C:Pool_801B378C<T>{
    Vector_801B378C(){
    }
    ~Vector_801B378C(){
    }
}
;
template<class T>struct Array_801B378C{
    int count,capacity;
    T*data;
    inline void reserve(int n){
        if(n){
            if(data)data=(T*)fn_8028FAF4(lbl_8028F698,data,capacity*sizeof(T),n*sizeof(T));
            else data=(T*)fn_8028FF24(lbl_8028F698,n*sizeof(T));
        }
        else if(data){
            fn_8028FD50(lbl_8028F698,data,capacity*sizeof(T));
            data=0;
        }
        capacity=n;
    }
}
;
extern "C" {
    extern char lbl_802E9E40[],__vt__24CurveRecordBase_802E9E08[];
}
struct CurveBase_801B1088{
    int unknown;
    CurveBase_801B1088();
    ~CurveBase_801B1088();
}
;
struct Curve_801B378C:CurveBase_801B1088{
    Pool_801B378C<Element_801B378C<16> > records;
    Curve_801B378C(){
    }
    ~Curve_801B378C(){
    }
}
;
struct LinkRoot_801B378C{
    int first;
    short index;
    char pad6[2];
    void*vtable;
    LinkRoot_801B378C(){
        vtable=__vt__24CurveRecordBase_802E9E08;
        first=0;
        index=-1;
    }
    ~LinkRoot_801B378C(){
    }
}
;
struct RecordBase_801B378C:LinkRoot_801B378C{
    RecordBase_801B378C(){
        vtable=lbl_802E9E40;
    }
    ~RecordBase_801B378C(){
    }
}
;
struct Record_801B378C:RecordBase_801B378C{
    Curve_801B378C curve;
    Record_801B378C(){
    }
    ~Record_801B378C(){
        vtable=lbl_802E9E40;
    }
}
;
extern "C" void fn_801B378C(Array_801B378C<Record_801B378C >*self,int n,signed char keep){
    if(n>self->count){
        if(n>self->capacity||!keep)self->reserve(n);
        for(int i=self->count;
        i<n;
        i++)new(&self->data[i]) Record_801B378C;
        self->count=n;
    }
    else if(n<self->count){
        for(int i=self->count-1;
        i>=n;
        i--)self->data[i].~Record_801B378C();
        if(keep)self->count=n;
        else{
            self->reserve(n);
            self->count=n;
        }
    }
}
