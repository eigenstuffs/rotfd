typedef unsigned int u32;
extern "C" {
    extern char lbl_8028F698[];
    void*fn_8028FAF4(void*,void*,int,int);
    void*fn_8028FF24(void*,int);
    void fn_8028FD50(void*,void*,int);
    void fn_801F86C8(void*,const void*,int);
}
struct Globals_801D21A4 {
    char unknown[0x118];
    void*manager;
};
extern "C" Globals_801D21A4 lbl_801E9D24;
inline void*operator new(unsigned long,void*p) {
    return p;
}
struct Handle_801F7F10 {
    u32 word;
    Handle_801F7F10();
    ~Handle_801F7F10();
};
struct Zero1_801D21A4:Handle_801F7F10 {
    Zero1_801D21A4() {
        word=0;
    }
    Zero1_801D21A4(const Zero1_801D21A4&h) {
        word=0;
        word=h.word;
        fn_801F86C8(lbl_801E9D24.manager,&h,1);
    }
    ~Zero1_801D21A4() {
    }
};
struct Zero2_801D21A4:Zero1_801D21A4 {
    Zero2_801D21A4() {
        word=0;
    }
    Zero2_801D21A4(const Zero2_801D21A4&h):Zero1_801D21A4(h) {
    }
    ~Zero2_801D21A4() {
    }
};
template<class T>struct Array_801D21A4 {
    int count,capacity;
    T*data;
    const T&operator[](int i)const {
        return data[i];
    }
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
        int i;
        if(n>count) {
            if(n>capacity||!keep)reserve(n);
            for(i=count; i<n; ++i)new(&data[i])T;
            count=n;
        }
        else if(n<count) {
            for(i=count-1; i>=n; --i)data[i].~T();
            if(keep)count=n;
            else {
                reserve(n);
                count=n;
            }
        }
    }
    void append(const T&value) {
        if(count+1>capacity) {
            int n=capacity+32;
            if(n) {
                if(data)data=(T*)fn_8028FAF4(lbl_8028F698,data,capacity*sizeof(T),n*sizeof(T));
                else data=(T*)fn_8028FF24(lbl_8028F698,n*sizeof(T));
            }
            else if(data) {
                fn_8028FD50(lbl_8028F698,data,capacity*sizeof(T));
                data=0;
            }
            capacity+=32;
        }
        new(&data[count++])T(value);
    }
};
extern "C" void fn_801D21A4(Array_801D21A4<Zero2_801D21A4>*self,int n) {
    if(n<self->count)self->resize(n,0);
    else self->reserve(n);
}
