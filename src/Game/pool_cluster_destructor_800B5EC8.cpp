/* Typed pool cleanup with original compiler exception metadata.
 * See docs/notes/game-pool-cluster-destructors.md. */
typedef unsigned long u32;
extern "C" {
extern char lbl_801EF5C8[], lbl_8028F698[], lbl_802BD920[], lbl_802B8460[];
void fn_801EF610(void*, void*);
void fn_8028FD50(void*, void*, int);
}
struct Record_800B6080 {char unknown00[0x40];~Record_800B6080();};
struct Element4 {u32 word;~Element4(){}};
struct Element38 {char unknown00[0x38];~Element38(){}};
template<class T> struct Pool {
    int size, capacity;
    T*data;
    ~Pool(){if(data){for(int i=0;i<size;i++)data[i].~T();if(data){fn_8028FD50(lbl_8028F698,data,capacity*sizeof(T));data=0;}data=0;}}
};
struct Base {
    const void*vtable;
    Pool<Element38> records04;
    u32 unknown10;
    ~Base(){vtable=lbl_802B8460;}
};
struct Object_800B5EC8:Base {
    Pool<Element4> records14;
    Pool<Record_800B6080*> records20;
    ~Object_800B5EC8();
    static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}
};
Object_800B5EC8::~Object_800B5EC8(){vtable=lbl_802BD920;for(int i=0;i<records20.size;i++)delete records20.data[i];}
