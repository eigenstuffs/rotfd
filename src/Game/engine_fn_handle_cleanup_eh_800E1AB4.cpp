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
extern "C" char lbl_802C8630[];
extern "C" {
    extern char lbl_802C867C[];
    void fn_8009009C(void*,int);
}
struct Root {
    void*vtable;
    unsigned int unknown04,value08,value0C;
    ~Root() {
        vtable=lbl_802C867C;
        value08=0;
        value0C=0;
        fn_8009009C(this,0);
    }
};
struct Group {
    char unknown00[0x8C];
    H3 handle8C;
    H3 handle90;
};
struct View:Root {
    Group group10;
};
extern "C" void*fn_800E1AB4(View*self,int flag) {
    if(self) {
        self->vtable=lbl_802C8630;
        self->group10.~Group();
        static_cast<Root*>(self)->~Root();
        if((short)flag>0)dispose(self);
    }
    return self;
}
