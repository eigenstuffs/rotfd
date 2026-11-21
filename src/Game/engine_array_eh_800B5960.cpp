/* Original engine destruction with compiler-emitted exception metadata.
 * See docs/notes/game-engine-array-eh.md. */
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
struct Object_800B5960 {
    int count,capacity;
    H1*data;
    ~Object_800B5960();
    static void operator delete(void*p)throw() {
        fn_801EF610(lbl_801EF5C8,p);
    }
};
Object_800B5960::~Object_800B5960() {
    if(data) {
        for(int i=0; i<count; i++)data[i].~H1();
        if(data) {
            fn_8028FD50(lbl_8028F698,data,capacity*sizeof(H1));
            data=0;
        }
        data=0;
    }
}
