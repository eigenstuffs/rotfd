typedef unsigned long u32;
extern "C" {
    extern char lbl_801EF5C8[],lbl_802B5748[];
    void fn_801EF610(void*,void*);
    void fn_80068658(void*);
}
struct Handle_801F7F10 {
    u32 word;
    ~Handle_801F7F10();
};
struct H1:Handle_801F7F10 {
};
struct H2:H1 {
};
struct H3:H2 {
};
struct Ref;
struct RefTable {
    void*unknown00[6];
    void(*destroy)(Ref*);
};
struct Ref {
    int count;
    RefTable*table;
};
inline void release(Ref*&value) {
    if(value) {
        if(--value->count==0)value->table->destroy(value);
    }
}
struct Object_8005E258 {
    u32 unknown00;
    void*vtable;
    char unknown08[0x30];
    H3 handle38;
    u32 unknown3C;
    Ref*ref40;
    char unknown44[0xC8];
    Ref*ref10C;
    Ref*ref110;
    Ref*ref114;
    Ref*ref118;
    Ref*ref11C;
    Ref*ref120;
    Ref*ref124;
    Ref*ref128;
    Ref*ref12C;
    Ref*ref130;
    Ref*ref134;
    Ref*ref138;
    Ref*ref13C;
    Ref*ref140;
    Ref*ref144;
    Ref*ref148;
    Ref*ref14C;
    ~Object_8005E258();
    static void operator delete(void*p)throw() {
        fn_801EF610(lbl_801EF5C8,p);
    }
};
Object_8005E258::~Object_8005E258() {
    vtable=lbl_802B5748;
    if(ref40&&ref148)fn_80068658(this);
    release(ref10C);
    release(ref110);
    release(ref114);
    release(ref118);
    release(ref11C);
    release(ref120);
    release(ref128);
    release(ref124);
    release(ref12C);
    release(ref130);
    release(ref134);
    release(ref138);
    release(ref13C);
    release(ref140);
    release(ref144);
    release(ref148);
    release(ref14C);
    release(ref40);
}
