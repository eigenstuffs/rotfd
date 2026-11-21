/* Original engine lifetime and record routines.
* See docs/notes/game-engine-pool-lifetime.md. */
extern "C" {
    extern char lbl_8028F698[],lbl_801EF5C8[];
    void fn_8028FD50(void*,void*,int);
    void fn_801EF610(void*,void*);
}
template<int N>struct Element_801D4E14{
    char data[N];
    ~Element_801D4E14(){
    }
};
template<class T>struct Pool_801D4E14{
    int count,capacity;
    T*data;
    ~Pool_801D4E14(){
        if(data){
            for(int i=0;i<count;i++)data[i].~T();
            if(data){
                fn_8028FD50(lbl_8028F698,data,capacity*sizeof(T));
                data=0;
            }data=0;
        }
    }
};
extern "C" {
    extern char lbl_802EA558[];
    void fn_80243E90(void*,int);
}
struct Object_801D4E14{
    char pad[8];
    void*vtable;
    char padc[0x68];
    Pool_801D4E14<Element_801D4E14<12> > first;
    Pool_801D4E14<Element_801D4E14<248> > second;
};
extern "C" Object_801D4E14 *fn_801D4E14(Object_801D4E14*self,short release){
    if(self){
        self->vtable=lbl_802EA558;
        self->second.~Pool_801D4E14();
        self->first.~Pool_801D4E14();
        fn_80243E90(self,0);
        if(release>0)fn_801EF610(lbl_801EF5C8,self);
    }return self;
}
