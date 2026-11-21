/* Original engine lifetime and record routines.
* See docs/notes/game-engine-pool-lifetime.md. */
extern "C" {
    extern char lbl_8028F698[],lbl_801EF5C8[];
    void fn_8028FD50(void*,void*,int);
    void fn_801EF610(void*,void*);
}
template<int N>struct Element_801CA954{
    char data[N];
    ~Element_801CA954(){
    }
};
template<class T>struct RecordPool_801CA954{
    int count,capacity;
    T*data;
    ~RecordPool_801CA954(){
        if(data){
            for(int i=0;i<count;i++)data[i].~T();
            if(data){
                fn_8028FD50(lbl_8028F698,data,capacity*sizeof(T));
                data=0;
            }data=0;
        }
    }
};
struct Pair_801CA954:RecordPool_801CA954<Element_801CA954<2> >{
    RecordPool_801CA954<Element_801CA954<2> > second;
    char tail[8];
    ~Pair_801CA954(){
    }
};
struct Pool_801CA954{
    int count,capacity;
    Pair_801CA954*data;
    ~Pool_801CA954();
    static void operator delete(void*p){
        fn_801EF610(lbl_801EF5C8,p);
    }
};
Pool_801CA954::~Pool_801CA954(){
    if(data){
        for(int i=0;i<count;i++)data[i].~Pair_801CA954();
        if(data){
            fn_8028FD50(lbl_8028F698,data,capacity*sizeof(Pair_801CA954));
            data=0;
        }data=0;
    }
}
