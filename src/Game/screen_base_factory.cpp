// Reconstructed from GSQE78 code and exception records. Class suffixes identify
// observed native constructors, destructors, or vtables; original names are unknown.
typedef unsigned long u32;

extern "C" {
extern char lbl_801EF5C8[];
void fn_801EF610(void*, void*);
}

struct Handle_801F7F10 {
    u32 value;
    Handle_801F7F10();
    ~Handle_801F7F10();
    static void operator delete(void* p) throw() {
        fn_801EF610(lbl_801EF5C8, p);
    }
};
struct ScreenFactoryZero1 : Handle_801F7F10 {
    ScreenFactoryZero1() { value = 0; }
    ~ScreenFactoryZero1() {}
};
struct ScreenFactoryZero2 : ScreenFactoryZero1 {
    ScreenFactoryZero2() { value = 0; }
    ~ScreenFactoryZero2() {}
};
struct ScreenFactoryHandle : ScreenFactoryZero2 {
    ScreenFactoryHandle() { value = 0; }
    ~ScreenFactoryHandle() {}
};

struct ObjectPrefix {
    u32 unknown[2];
};
struct Object_8025F0D8 : ObjectPrefix {
    Object_8025F0D8();
    virtual ~Object_8025F0D8();
    virtual void slotC();
    char unknown0C[0x3C];
    static void operator delete(void* p) throw() {
        fn_801EF610(lbl_801EF5C8, p);
    }
};
struct ScreenBase_800B9368 : Object_8025F0D8 {
    ScreenFactoryHandle member48;
    u32 unknown4C;
    ScreenBase_800B9368() {}
    virtual ~ScreenBase_800B9368();
    virtual void slotC();
};
extern "C" {
void* fn_801EFA1C(void*,unsigned long,const char*,const char*,int,int);
extern const char lbl_802AEE28[],lbl_802AEF08[];
}
inline void* operator new(unsigned long,void* p){return p;}
extern "C" ScreenBase_800B9368* fn_80261708() {
 return new(fn_801EFA1C(lbl_801EF5C8,0x50,lbl_802AEE28,lbl_802AEF08,7,4)) ScreenBase_800B9368();
}
