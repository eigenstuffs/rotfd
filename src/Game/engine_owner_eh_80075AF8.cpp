typedef unsigned long u32;
extern "C" {
    extern char lbl_801EF5C8[],lbl_802EBE80[],lbl_802EBE28[],__vt__13Manipulator_Z[];
    void fn_801EF610(void*,void*);
    void __dt__11Activable_ZFv(void*,int);
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
struct H4:H3 {
};
struct H5:H4 {
};
struct Table {
    char unknown00[0x4C];
    void(*notify)(void*);
};
struct Root {
    u32 unknown00[2];
    Table*vtable;
    char unknown0C[0x18];
    ~Root() {
        vtable=(Table*)__vt__13Manipulator_Z;
        __dt__11Activable_ZFv(this,0);
    }
};
struct InlineBase:Root {
    H5 handle24;
    H1 handle28;
    ~InlineBase() {
        vtable=(Table*)lbl_802EBE28;
    }
};
struct Object_80075AF8:InlineBase {
    char unknown2C[0x50];
    H5 handle7C;
    ~Object_80075AF8();
    static void operator delete(void*p)throw() {
        fn_801EF610(lbl_801EF5C8,p);
    }
};
struct Prefix {
    u32 unknown00[2];
};
struct View:Prefix {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void notify();
};
Object_80075AF8::~Object_80075AF8() {
    vtable=(Table*)lbl_802EBE80;
    ((View*)this)->notify();
}
