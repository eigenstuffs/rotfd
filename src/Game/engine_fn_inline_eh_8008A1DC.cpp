#include "Game/costume_native_operation_records.h"
/* Original engine destruction with compiler-emitted exception metadata.
 * See docs/notes/game-engine-fn-inline-eh.md. */
extern "C" {
    extern char lbl_801EF5C8[], lbl_802B92B0[];
    void fn_801EF610(void*,void*);
    void fn_8009009C(void*,int);
}
struct InlineRoot {
    void*vtable;
    ~InlineRoot() {
        vtable=lbl_802B92B0;
        fn_8009009C(this,0);
    }
};
struct InlineBase:InlineRoot {
    ~InlineBase() {
        vtable=&lbl_802B8B10;
    }
};
static inline void dispose(void*p)throw() {
    fn_801EF610(lbl_801EF5C8,p);
}
extern "C" void*fn_8008A1DC(InlineBase*self,int flag) {
    if(self) {
        self->vtable=&lbl_802B8AF0;
        self->~InlineBase();
        if((short)flag>0)dispose(self);
    }
    return self;
}
