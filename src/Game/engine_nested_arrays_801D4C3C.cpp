extern "C" {
    extern char lbl_8028F698[],lbl_801EF5C8[];
    void*fn_8028FAF4(void*,void*,int,int);
    void*fn_8028FF24(void*,int);
    void fn_8028FD50(void*,void*,int);
    void fn_801EF610(void*,void*);
}
inline void*operator new(unsigned long,void*p) {
    return p;
}
template<int N>struct Element_801D4C3C {
    char bytes[N];
    ~Element_801D4C3C() {
    }
};
template<class T>struct Pool_801D4C3C {
    int count,capacity;
    T*data;
    Pool_801D4C3C() {
        count=0;
        capacity=0;
        data=0;
    }
    ~Pool_801D4C3C() {
        if(data) {
            for(int i=0; i<count; ++i)data[i].~T();
            if(data) {
                fn_8028FD50(lbl_8028F698,data,capacity*sizeof(T));
                data=0;
            }
            data=0;
        }
    }
};
template<class T>struct Array_801D4C3C {
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
};
struct Row_801D4C3C {
    unsigned int key;
    Pool_801D4C3C<Element_801D4C3C<8> > first,second;
    ~Row_801D4C3C() {
    }
};
extern "C" Array_801D4C3C<Row_801D4C3C>*fn_801D4C3C(Array_801D4C3C<Row_801D4C3C>*self,int flag) {
    if(self) {
        if(self->data) {
            for(int i=0; i<self->count; ++i)self->data[i].~Row_801D4C3C();
            if(self->data) {
                fn_8028FD50(lbl_8028F698,self->data,self->capacity*sizeof(Row_801D4C3C));
                self->data=0;
            }
            self->data=0;
        }
        if((short)flag>0)fn_801EF610(lbl_801EF5C8,self);
    }
    return self;
}
