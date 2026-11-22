extern "C" {
    extern char lbl_8028F698[];
    void *fn_8028FAF4(void*,void*,int,int);
    void *fn_8028FF24(void*,int);
    void fn_8028FD50(void*,void*,int);
    void fn_801F7914(void*,void*);
    void __dt__15Handle_801F7F10Fv(void*,int);
    int fn_801EC764(int,int);
    int fn_801EC778(int,int);
}
inline void*operator new(unsigned long,void*p) {
    return p;
}
struct Handle_801F7F10 {
    unsigned int word;
    Handle_801F7F10();
    ~Handle_801F7F10();
};
struct PackedHandle_801EAC8C {
    signed int generation:8;
    signed int index:24;
};
struct Key_801EAC8C {
    Handle_801F7F10 handle;
    unsigned short index,unknown6;
    Key_801EAC8C() {
        PackedHandle_801EAC8C empty;
        empty.index=0;
        empty.generation=0;
        fn_801F7914(&handle,&empty);
        __dt__15Handle_801F7F10Fv(&empty,-1);
        index=0xffff;
    }
    ~Key_801EAC8C() {
    }
};
struct Node_801EAC8C:Key_801EAC8C {
    unsigned short prev,next;
    Node_801EAC8C() {
    }
    ~Node_801EAC8C() {
    }
};
template<class T>struct Array_801EAC8C {
    int count,capacity;
    T*data;
    T&at(int i) {
        T*base=data;
        return base[i];
    }
    inline void reserve(int n) {
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
    void destroy(int n) {
        for(int i=count-1; i>=n; --i)at(i).~T();
    }
    void resize(int n) {
        if(n>count) {
            reserve(n);
            for(int i=count; i<n; i++)new(&data[i])T;
            count=n;
        }
        else if(n<count) {
            destroy(n);
            reserve(n);
            count=n;
        }
    }
};
extern "C" void fn_801EAC8C(Array_801EAC8C<Node_801EAC8C>*self,int n) {
    int size=n+2;
    self->resize(size);
    int last=n+1;
    n+=2;
    for(int i=0; i<n; i++) {
        self->at(i).prev=fn_801EC764(i-1,0);
        self->at(i).next=fn_801EC778(i+1,last);
    }
}
