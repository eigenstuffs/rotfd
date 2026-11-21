/* Original engine handle array reset routines.
 * See docs/notes/game-engine-handle-reset.md. */
typedef unsigned int u32;
extern "C" {
    extern char lbl_8028F698[];
    void*fn_8028FAF4(void*,void*,int,int);
    void*fn_8028FF24(void*,int);
    void fn_8028FD50(void*,void*,int);
    void*fn_801F7EB8(void*);
    void fn_802086C8(void*,int);
    void fn_80208768(void*,int);
    void fn_801E9F8C();
    extern signed char lbl_80377F90;
}
inline void*operator new(unsigned long,void*p) {
    return p;
}
struct Handle_801F7F10 {
    u32 word;
    Handle_801F7F10();
    ~Handle_801F7F10();
};
template<class T>struct Array_801B4230 {
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
    void resize(int n) {
        if(n>count) {
            if(n>capacity)reserve(n);
            for(int i=count; i<n; ++i)new(&data[i])T;
            count=n;
        }
        else if(n<count) {
            for(int i=count-1; i>=n; --i)data[i].~T();
            count=n;
        }
    }
};
struct Owner_801B4230 {
    char unknown[0xB8];
    Array_801B4230<Handle_801F7F10>handles;
    void*control;
};
extern "C" void fn_801B4230(Owner_801B4230*self) {
    self->handles.resize(0);
    if(self->control) {
        fn_802086C8(self->control,1);
        fn_80208768(self->control,1);
        self->control=0;
    }
    fn_801E9F8C();
    lbl_80377F90=1;
}
