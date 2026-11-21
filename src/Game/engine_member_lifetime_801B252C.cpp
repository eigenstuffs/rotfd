/* Original engine lifetime and record routines.
* See docs/notes/game-engine-member-lifetime.md. */
extern "C" {
    extern char lbl_8028F698[],lbl_801EF5C8[];
    void fn_8028FD50(void*,void*,int);
    void fn_801EF610(void*,void*);
}
template<int N>struct Element_801B252C{
    char data[N];
    ~Element_801B252C(){
    }
}
;
template<class T>struct Pool_801B252C{
    int count,capacity;
    T*data;
    ~Pool_801B252C(){
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
    extern char lbl_802E9DE8[],lbl_802E9E40[],__vt__17Resource_802E9E20[];
    void fn_801B29F8(void*,int);
    void fn_801B26DC(void*,int);
}
struct Curve_801B252C:CurveBase_801B1088{
    Pool_801B252C<Element_801B252C<16> > records;
    ~Curve_801B252C(){
    }
}
;
struct Record_801B252C{
    char pad[8];
    void*vtable;
    Curve_801B252C curve;
    ~Record_801B252C(){
        vtable=lbl_802E9E40;
    }
}
;
struct BaseObject_Z{
    char pad[8];
    void*vtable;
    ~BaseObject_Z();
}
;
struct Resource_801B252C:BaseObject_Z{
    ~Resource_801B252C(){
        vtable=__vt__17Resource_802E9E20;
    }
}
;
struct Object_801B252C:Resource_801B252C{
    char first[12],second[12];
    Pool_801B252C<Record_801B252C> records;
}
;
extern "C" Object_801B252C *fn_801B252C(Object_801B252C*self,short release){
    if(self){
        self->vtable=lbl_802E9DE8;
        self->records.~Pool_801B252C();
        fn_801B29F8(self->second,-1);
        fn_801B26DC(self->first,-1);
        self->Resource_801B252C::~Resource_801B252C();
        if(release>0)fn_801EF610(lbl_801EF5C8,self);
    }
    return self;
}
