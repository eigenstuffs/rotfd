typedef unsigned long u32;
extern "C" {
    extern char lbl_801EF5C8[],lbl_8028F698[];
    void fn_801EF610(void*,void*);
    void fn_8028FD50(void*,void*,int);
}
struct Handle_801F7F10 {
    u32 word;
    ~Handle_801F7F10();
};
struct H1:Handle_801F7F10 {
};
struct H2:H1 {
};
struct H3:H2 {
};
extern "C" char lbl_802B8460[];
struct Empty38 {
    char unknown00[0x38];
    ~Empty38() {
    }
};
template<class T>struct Array {
    int count,capacity;
    T*data;
    ~Array() {
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
struct Object_8007F3DC {
    void*vtable;
    Array<Empty38>array04;
    ~Object_8007F3DC();
    static void operator delete(void*p)throw() {
        fn_801EF610(lbl_801EF5C8,p);
    }
};
Object_8007F3DC::~Object_8007F3DC() {
    vtable=lbl_802B8460;
}
