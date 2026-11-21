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
struct Element:H2 {
    char unknown04[0xD0];
    ~Element() {
    }
};
struct Object_800A5F24 {
    int count,capacity;
    Element*data;
    ~Object_800A5F24();
    static void operator delete(void*p)throw() {
        fn_801EF610(lbl_801EF5C8,p);
    }
};
Object_800A5F24::~Object_800A5F24() {
    if(data) {
        for(int i=0; i<count; i++)data[i].~Element();
        if(data) {
            fn_8028FD50(lbl_8028F698,data,capacity*sizeof(Element));
            data=0;
        }
        data=0;
    }
}
