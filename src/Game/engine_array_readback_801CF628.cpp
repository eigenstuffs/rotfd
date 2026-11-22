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
template<int N>struct Element_801CF628 {
    char bytes[N];
    Element_801CF628() {
    }
    ~Element_801CF628() {
    }
};
template<class T>struct Array_801CF628 {
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
struct Owner_801CF628 {
    char unknown[0xA0];
    int sourceCount;
    char unknownA4[0xD8-0xA4];
    Array_801CF628<Element_801CF628<4> > bits;
    int bitCount;
    void setCount(int n) {
        bitCount=n;
        if(n&&((n>>5)+1)>bits.count)bits.resize((bitCount>>5)+1,0);
    }
};
extern "C" void fn_801D5338(Owner_801CF628*,void**);
extern "C" void fn_801CF628(Owner_801CF628*self,void**stream) {
    fn_801D5338(self,stream);
    self->setCount(self->sourceCount);
    if(self->bits.count)memset(self->bits.data,0,self->bits.count*4);
}
