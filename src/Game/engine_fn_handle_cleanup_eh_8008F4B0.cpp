#include "Game/state_native_operation_records_selected.h"
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
struct View:Root {
    char unknown04[0x3C];
    H4 handle40;
};
extern "C" void*fn_8008F4B0(View*self,int flag) {
    if(self) {
        self->vtable=&lbl_802B8ED4;
        self->handle40.~H4();
        static_cast<Root*>(self)->~Root();
        if((short)flag>0)dispose(self);
    }
    return self;
}
