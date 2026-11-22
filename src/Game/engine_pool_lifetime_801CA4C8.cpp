extern "C" {
    extern char lbl_8028F698[],lbl_801EF5C8[];
    void fn_8028FD50(void*,void*,int);
    void fn_801EF610(void*,void*);
}
template<int N>struct Element_801CA4C8{
    char data[N];
    ~Element_801CA4C8(){
    }
};
template<class T>struct Pool_801CA4C8{
    int count,capacity;
    T*data;
    ~Pool_801CA4C8(){
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
    extern char __vt__19CameraZone_802EA180[];
    void fn_801CA6B8(void*,int);
}
struct ShortVector_801CA4C8:Pool_801CA4C8<Element_801CA4C8<2> >{
    ~ShortVector_801CA4C8(){
    }
};
struct Object_801CA4C8{
    char pad[8];
    void*vtable;
    char padc[0xcc];
    Pool_801CA4C8<Element_801CA4C8<0x44> > first;
    Pool_801CA4C8<ShortVector_801CA4C8> second;
};
extern "C" Object_801CA4C8 *fn_801CA4C8(Object_801CA4C8*self,short release){
    if(self){
        self->vtable=__vt__19CameraZone_802EA180;
        self->second.~Pool_801CA4C8();
        self->first.~Pool_801CA4C8();
        fn_801CA6B8(self,0);
        if(release>0)fn_801EF610(lbl_801EF5C8,self);
    }return self;
}
