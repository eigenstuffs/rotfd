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
template<int N>struct Element_801D020C {
    char bytes[N];
    Element_801D020C() {
    }
    ~Element_801D020C() {
    }
};
template<class T>struct Array_801D020C {
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
struct Stream_801D020C {
    void*current;
};
struct Owner_801D020C {
    char unknown[0x24];
    Array_801D020C<Element_801D020C<2> > first;
    Array_801D020C<Element_801D020C<28> > second;
};
extern "C" void fn_80243DE4(Owner_801D020C*,Stream_801D020C*);
extern "C" void fn_801D020C(Owner_801D020C*self,Stream_801D020C*stream) {
    fn_80243DE4(self,stream);
    int count;
    stream->current=fn_801E9F40(&count,stream->current,4);
    self->first.resize(count,0);
    self->second.resize(count,0);
    stream->current=fn_801E9F40(self->first.data,stream->current,count*sizeof(Element_801D020C<2>));
    stream->current=fn_801E9F40(self->second.data,stream->current,count*sizeof(Element_801D020C<28>));
}
