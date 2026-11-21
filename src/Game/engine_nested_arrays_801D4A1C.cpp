/* Original engine nested-array resize and cleanup.
 * See docs/notes/game-engine-nested-arrays.md. */
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
template<int N>struct Element_801D4A1C {
    char bytes[N];
    ~Element_801D4A1C() {
    }
};
template<class T>struct Pool_801D4A1C {
    int count,capacity;
    T*data;
    Pool_801D4A1C() {
        count=0;
        capacity=0;
        data=0;
    }

};
template<class T>struct Array_801D4A1C {
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
struct Row_801D4A1C {
    unsigned int key;
    Pool_801D4A1C<Element_801D4A1C<28> > records;
    Row_801D4A1C() {
    }
};
extern "C" void fn_801D4BDC(Row_801D4A1C*,int);
extern "C" void fn_801D4A1C(Array_801D4A1C<Row_801D4A1C>*self,int n,signed char keep) {
    if(n>self->count) {
        if(n>self->capacity||!keep)self->reserve(n);
        for(int i=self->count; i<n; ++i)new(&self->data[i])Row_801D4A1C;
        self->count=n;
    }
    else if(n<self->count) {
        for(int i=self->count-1; i>=n; --i)fn_801D4BDC(&self->data[i],-1);
        if(keep)self->count=n;
        else {
            self->reserve(n);
            self->count=n;
        }
    }
}
