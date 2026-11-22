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
extern "C" char lbl_802C8E88[];
extern "C" {
    extern char __vt__13Manipulator_Z[],__vt__24ManipulatorDraw_802BC9D0[];
    void __dt__11Activable_ZFv(void*,int);
}
struct Root {
    char opaque00[8];
    void*vtable;
    ~Root() {
        vtable=__vt__13Manipulator_Z;
        __dt__11Activable_ZFv(this,0);
    }
};
struct Draw:Root {
    ~Draw() {
        vtable=__vt__24ManipulatorDraw_802BC9D0;
    }
};
struct View:Draw {
    char unknown0C[0x18];
    H2 handle24;
};
extern "C" void*fn_800E745C(View*self,int flag) {
    if(self) {
        self->vtable=lbl_802C8E88;
        self->handle24.~H2();
        static_cast<Draw*>(self)->~Draw();
        if((short)flag>0)dispose(self);
    }
    return self;
}
