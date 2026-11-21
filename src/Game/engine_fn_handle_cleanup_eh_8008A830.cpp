#include "Game/costume_native_operation_records.h"
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

extern "C" {
    extern char lbl_802B92B0[];
    void fn_8009009C(void*,int);
}
struct Root {
    void*vtable;
    ~Root() {
        vtable=lbl_802B92B0;
        fn_8009009C(this,0);
    }
};
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
struct View:Root {
    char unknown04[0x3C];
    HandleArray array40;
};
extern "C" void*fn_8008A830(View*self,int flag) {
    if(self) {
        self->vtable=&lbl_802B8A6C;
        self->array40.~HandleArray();
        static_cast<Root*>(self)->~Root();
        if((short)flag>0)dispose(self);
    }
    return self;
}
