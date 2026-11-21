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
struct Handle_80020478 : Handle_801F7F10 {
    Handle_80020478() { value = 0; }
    ~Handle_80020478();
};
struct Handle_80021BCC : Handle_80020478 {
    Handle_80021BCC() { value = 0; }
    ~Handle_80021BCC();
};
struct Handle_800B92F0 : Handle_80021BCC {
    Handle_800B92F0() { value = 0; }
    ~Handle_800B92F0();
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
    Handle_800B92F0 member48;
    u32 unknown4C;
    ScreenBase_800B9368() {}
    virtual ~ScreenBase_800B9368();
    virtual void slotC();
};

struct LoadingScreen_800B9214 : ScreenBase_800B9368 {
 Handle_800B92F0 resource; signed char active;
 LoadingScreen_800B9214(){ active=1; }
 virtual ~LoadingScreen_800B9214(); virtual void slotC();
};
struct LoadingScreen_800C0600 : LoadingScreen_800B9214 {
 LoadingScreen_800C0600(){ active=0; }
 virtual ~LoadingScreen_800C0600(); virtual void slotC();
};
extern "C" {
void* fn_801EFA1C(void*,unsigned long,const char*,const char*,int,int);
extern const char lbl_802A0E78[],lbl_802A0EAC[];
}
inline void* operator new(unsigned long,void* p){return p;}
