typedef unsigned long u32;
extern "C" {
extern char lbl_801EF5C8[], lbl_8028F698[];
void fn_801EF610(void*, void*);
void fn_8028FD50(void*, void*, int);
}
struct Handle_801F7F10 {u32 word;~Handle_801F7F10();};
struct Handle:Handle_801F7F10 {~Handle(){}};
struct Element {u32 word;~Element(){}};
template<class T> struct Pool {
    int size, capacity;
    T*data;
    ~Pool(){if(data){for(int i=0;i<size;i++)data[i].~T();if(data){fn_8028FD50(lbl_8028F698,data,capacity*sizeof(T));data=0;}data=0;}}
};
struct Record_800B6080:Pool<Pool<Handle> > {
    Pool<Handle> handles0C;
    Pool<Element> records18, records24;
    u32 unknown30;
    Pool<Element> records34;
    ~Record_800B6080();
    static void operator delete(void*p)throw(){fn_801EF610(lbl_801EF5C8,p);}
};
Record_800B6080::~Record_800B6080(){}
