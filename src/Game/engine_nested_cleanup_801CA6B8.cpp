/* Original engine lifetime and record routines.
 * See docs/notes/game-engine-nested-cleanup.md. */
extern "C" {
    extern char lbl_8028F698[],lbl_801EF5C8[],lbl_802EA5B0[],lbl_802EA558[];
    void fn_8028FD50(void*,void*,int);
    void fn_801EF610(void*,void*);
    void fn_80243E90(void*,int);
}
template<int N>struct Element_801CA6B8 {
    char bytes[N];
    ~Element_801CA6B8() {
    }
};
template<class T>struct Pool_801CA6B8 {
    int count,capacity;
    T*data;
    ~Pool_801CA6B8() {
        if(data) {
            for(int i=0; i<count; ++i)data[i].~T();
            if(data) {
                fn_8028FD50(lbl_8028F698,data,capacity*sizeof(T));
                data=0;
            }
            data=0;
        }
    }
};
struct Pool_801CA954 {
    int count,capacity;
    void*data;
    ~Pool_801CA954();
};
struct NativeBase_801CA6B8 {
    unsigned int word0,word4;
    void*vtable;
    char unknownC[0x68];
};
template<class T>struct View_801CA6B8 {
    int count,capacity;
    T*data;
    void destroy() {
        ((Pool_801CA6B8<T>*)this)->~Pool_801CA6B8<T>();
    }
};
struct Base_801CA6B8:NativeBase_801CA6B8 {
    View_801CA6B8<Element_801CA6B8<12> >first;
    View_801CA6B8<Element_801CA6B8<0xF8> >second;
    char unknown8C[0x14];
    ~Base_801CA6B8() {
        vtable=lbl_802EA558;
        second.destroy();
        first.destroy();
        fn_80243E90(this,0);
    }
};
typedef Pool_801CA6B8<Element_801CA6B8<2> >ShortVector_801CA6B8;
struct Nested_801CA6B8 {
    char unknown[0x20];
    Pool_801CA6B8<ShortVector_801CA6B8>values;
    ~Nested_801CA6B8() {
    }
};
struct Owner_801CA6B8:Base_801CA6B8 {
    Pool_801CA954 pool;
    Nested_801CA6B8 nested;
};
extern "C" Owner_801CA6B8*fn_801CA6B8(Owner_801CA6B8*self,int flag) {
    if(self) {
        self->vtable=lbl_802EA5B0;
        self->nested.~Nested_801CA6B8();
        self->pool.~Pool_801CA954();
        self->Base_801CA6B8::~Base_801CA6B8();
        if((short)flag>0)fn_801EF610(lbl_801EF5C8,self);
    }
    return self;
}
