// Reconstructed Txt factory and native constructor chain; original type names are partial.
extern "C" {
extern char lbl_801EF5C8[];
void* fn_801EFA1C(void*, unsigned long, const char*, const char*, int, int);
void __ct__13File_801F3E1CFv(void*);
extern const char lbl_802AE024[];
extern const char lbl_8037AA4C[8];
}
inline void* operator new(unsigned long, void* address) { return address; }
struct RootStorage_80207414 { unsigned long unknown0, identity; };
struct BaseObject_Z : RootStorage_80207414 {
    BaseObject_Z();
    virtual ~BaseObject_Z();
    virtual void slot0C(unsigned long);
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual signed char slot1C();
};
struct Resource_802E9E20 : BaseObject_Z {
    Resource_802E9E20() {}
    virtual ~Resource_802E9E20();
};
struct TxtFile {
    unsigned char storage[0x5C];
    TxtFile() { __ct__13File_801F3E1CFv(this); }
};
struct Txt_802E9E50 : Resource_802E9E20 {
    TxtFile file;
    Txt_802E9E50() {}
    virtual ~Txt_802E9E50();
};
typedef char TxtSizeCheck[sizeof(Txt_802E9E50) == 0x68 ? 1 : -1];

extern "C" Txt_802E9E50* fn_8020A608() {
    void* object = fn_801EFA1C(lbl_801EF5C8, sizeof(Txt_802E9E50),
                                 lbl_802AE024, lbl_8037AA4C, 21, 4);
    return new (object) Txt_802E9E50;
}
