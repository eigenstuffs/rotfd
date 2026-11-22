typedef unsigned long U32;
extern "C" {
    extern char lbl_8028F698[],lbl_801EF5C8[];
    void fn_8028FD50(void*,void*,int);
    void fn_801EF610(void*,void*);
    void fn_80243E90(void*,int);
}
template<int N>struct Element_801CB130{
    char data[N];
    ~Element_801CB130(){
    }
}
;
template<class T>struct Pool_801CB130{
    int count,capacity;
    T*data;
    ~Pool_801CB130(){
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
struct Handle_801F7F10{
    U32 word;
    ~Handle_801F7F10();
}
;
struct Handle0_801CB130:Handle_801F7F10{
    ~Handle0_801CB130(){
    }
}
;
struct Handle1_801CB130:Handle0_801CB130{
    ~Handle1_801CB130(){
    }
}
;
struct Handle2_801CB130:Handle1_801CB130{
    ~Handle2_801CB130(){
    }
}
;
struct Handle3_801CB130:Handle2_801CB130{
    ~Handle3_801CB130(){
    }
}
;
extern "C" {
    extern char lbl_802EA1D8[];
    void __destroy_arr(void*,void(*)(void*,int),int,int);
    void __dt__15Handle_80020B90Fv(void*,int);
}
struct Object_801CB130{
    char pad[8];
    void*vtable;
    char padc[0x68];
    Pool_801CB130<Element_801CB130<128> > first;
    char pad80[8];
    char handles88[40];
    char padb0[0x28];
    Pool_801CB130<Handle0_801CB130> second;
    Pool_801CB130<Handle1_801CB130> third;
}
;
extern "C" Object_801CB130 *fn_801CB130(Object_801CB130*self,short release){
    if(self){
        self->vtable=lbl_802EA1D8;
        self->third.~Pool_801CB130();
        self->second.~Pool_801CB130();
        __destroy_arr(self->handles88,__dt__15Handle_80020B90Fv,4,10);
        self->first.~Pool_801CB130();
        fn_80243E90(self,0);
        if(release>0)fn_801EF610(lbl_801EF5C8,self);
    }
    return self;
}
