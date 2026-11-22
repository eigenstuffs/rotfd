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
struct Object_800B5A34 {
    int count,capacity;
    Array<H1>*data;
    ~Object_800B5A34();
    static void operator delete(void*p)throw() {
        fn_801EF610(lbl_801EF5C8,p);
    }
};
Object_800B5A34::~Object_800B5A34() {
    if(data) {
        for(int i=0; i<count; i++)data[i].~Array<H1>();
        if(data) {
            fn_8028FD50(lbl_8028F698,data,capacity*sizeof(Array<H1>));
            data=0;
        }
        data=0;
    }
}
