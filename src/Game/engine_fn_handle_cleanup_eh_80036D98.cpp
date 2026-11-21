/* Original engine destruction with compiler-emitted exception metadata.
 * See docs/notes/game-engine-fn-handle-cleanup-eh.md. */
extern "C" {
    extern char lbl_801EF5C8[];
    void fn_801EF610(void*,void*);
}
struct Handle_801F7F10 {
    unsigned int word;
    ~Handle_801F7F10();
};
struct H1:Handle_801F7F10 {
};
struct H2:H1 {
};
struct H3:H2 {
};
struct H4:H3 {
};
static inline void dispose(void*p)throw() {
    fn_801EF610(lbl_801EF5C8,p);
}
extern "C" char lbl_802B25B4[];
extern "C" {
    extern char lbl_8028F698[];
    void fn_8028FD50(void*,void*,unsigned int);
}
struct HandleArray {
    int count;
    unsigned int capacity;
    H3*data;
    ~HandleArray() {
        if(data) {
            for(int i=0; i<count; i++)data[i].~H3();
            if(data) {
                fn_8028FD50(lbl_8028F698,data,capacity*4);
                data=0;
            }
            data=0;
        }
    }
};
extern "C" void __dt__14Agent_80035294Fv(void*,int);
struct View {
    char unknown00[8];
    void*vtable;
    char unknown0C[0x7C];
    HandleArray array88;
};
extern "C" void*fn_80036D98(View*self,int flag) {
    if(self) {
        self->vtable=lbl_802B25B4;
        self->array88.~HandleArray();
        __dt__14Agent_80035294Fv(self,0);
        if((short)flag>0)dispose(self);
    }
    return self;
}
