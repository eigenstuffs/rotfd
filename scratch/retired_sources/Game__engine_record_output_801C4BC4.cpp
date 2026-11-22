/* Original engine record and output routines.
 * See docs/notes/game-engine-record-output.md. */
typedef unsigned int u32;
struct Handle_801F7F10 {
    u32 word;
    Handle_801F7F10();
    ~Handle_801F7F10();
};
struct Globals_801C4BC4 {
    char unknown[0x114];
    char*viewports;
    void*manager;
};
extern "C" Globals_801C4BC4 lbl_801E9D24;
extern "C" {
    void fn_801F86C8(void*,const void*,short);
    void fn_801E1F3C(void*,const void*);
    void fn_802139D8(void*);
}
struct Layer1_801C4BC4:Handle_801F7F10 {
    Layer1_801C4BC4() {
        word=0;
    }
    ~Layer1_801C4BC4() {
    }
};
struct Layer2_801C4BC4:Layer1_801C4BC4 {
    Layer2_801C4BC4() {
        word=0;
    }
    ~Layer2_801C4BC4() {
    }
};
struct Copy_801C4BC4:Layer2_801C4BC4 {
    Copy_801C4BC4(const Handle_801F7F10&h) {
        word=h.word;
        fn_801F86C8(lbl_801E9D24.manager,&h,1);
    }
    ~Copy_801C4BC4() {
    }
};
struct Owner_801C4BC4 {
    u32 first;
    Handle_801F7F10 identity;
    char unknown8[0x54];
    int index;
};
extern "C" void fn_801C4BC4(Owner_801C4BC4*self) {
    if(self->index>=0) {
        const Handle_801F7F10&identity=self->identity;
        Copy_801C4BC4 copy(identity);
        fn_801E1F3C(lbl_801E9D24.viewports+self->index*0x4C,&copy);
    }
    fn_802139D8(self);
}
