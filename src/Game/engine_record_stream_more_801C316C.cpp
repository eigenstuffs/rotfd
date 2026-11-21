/* Original engine lifetime and record routines.
 * See docs/notes/game-engine-record-stream-more.md. */
extern "C" {
    extern char lbl_8028F698[];
    void*fn_8028FAF4(void*,void*,int,int);
    void*fn_8028FF24(void*,int);
    void fn_8028FD50(void*,void*,int);
    void*memset(void*,int,unsigned long);
    void*fn_801E9F40(void*,void*,int);
}
inline void*operator new(unsigned long,void*p) {
    return p;
}
template<int N>struct Element_801C316C {
    char bytes[N];
    Element_801C316C() {
    }
    ~Element_801C316C() {
    }
};
template<class T>struct Array_801C316C {
    int count,capacity;
    T*data;
    void reserve(int n) {
        if(n) {
            if(data)data=(T*)fn_8028FAF4(lbl_8028F698,data,capacity*sizeof(T),n*sizeof(T));
            else data=(T*)fn_8028FF24(lbl_8028F698,n*sizeof(T));
        }
        else if(data) {
            fn_8028FD50(lbl_8028F698,data,capacity*sizeof(T));
            data=0;
        }
        capacity=n;
    }
    void resize(int n,signed char keep) {
        if(n>count) {
            if(n>capacity||!keep)reserve(n);
            for(int i=count; i<n; ++i)new(&data[i])T;
            count=n;
        }
        else if(n<count) {
            for(int i=count-1; i>=n; --i)data[i].~T();
            if(keep)count=n;
            else {
                reserve(n);
                count=n;
            }
        }
    }
};
struct Stream_801C316C {
    void*current;
};
struct Owner_801C316C {
    char unknown[0x40];
    Array_801C316C<Element_801C316C<32> > records;
};
extern "C" void fn_801F2CB4(void*,void*,int);
extern "C" void fn_801C316C(Owner_801C316C*self,void*stream) {
    int count;
    fn_801F2CB4(stream,&count,4);
    self->records.resize(count,0);
    for(int i=0; i<count; ++i)fn_801F2CB4(stream,&self->records.data[i],32);
}
