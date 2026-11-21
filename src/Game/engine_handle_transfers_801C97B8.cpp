/* Original engine lifetime and record routines.
 * See docs/notes/game-engine-handle-transfers.md. */
typedef unsigned int u32;
struct Globals_801C97B8 {
    char unknown[0x118];
    void*manager;
    char unknown11C[4];
    void*renderer;
};
extern "C" Globals_801C97B8 lbl_801E9D24;
extern "C" {
    void __ct__15Handle_801F7F10Fv(void*);
    void __dt__15Handle_801F7F10Fv(void*,int);
    void fn_801F86C8(void*,const void*,int);
    void fn_8023A6D8(void*,const void*);
}
struct Word_801C97B8 {
    u32 word;
};
struct Native_801C97B8 {
    u32 word;
    Native_801C97B8() {
        __ct__15Handle_801F7F10Fv(this);
    }
    ~Native_801C97B8() {
        __dt__15Handle_801F7F10Fv(this,0);
    }
};
struct Layer_801C97B8:Native_801C97B8 {
    Layer_801C97B8() {
        word=0;
    }
};
struct First_801C97B8:Layer_801C97B8 {
    First_801C97B8(const Word_801C97B8&v) {
        word=v.word;
        fn_801F86C8(lbl_801E9D24.manager,&v,1);
    }
};
struct Second_801C97B8:Layer_801C97B8 {
    Second_801C97B8(const First_801C97B8&v) {
        word=v.word;
        fn_801F86C8(lbl_801E9D24.manager,&v,1);
    }
};
struct Owner_801C97B8 {
    u32 unknown0;
    Word_801C97B8 handle;
};
extern "C" void fn_801C97B8(Owner_801C97B8*self) {
    const Word_801C97B8&handle=self->handle;
    Second_801C97B8 value((First_801C97B8(handle)));
    fn_8023A6D8(lbl_801E9D24.renderer,&value);
}
