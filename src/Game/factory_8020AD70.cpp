// Reconstructed Bitmap factory and native Resource constructor chain.
extern "C" {
extern char lbl_801EF5C8[];
void* fn_801EFA1C(void*, unsigned long, const char*, const char*, int, int);
extern const char lbl_802AE024[];
extern const char lbl_802AE304[];
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
struct Bitmap_802EBEE0 : Resource_802E9E20 {
    unsigned char storage[0x3C];
    Bitmap_802EBEE0() { slot18(); }
    virtual ~Bitmap_802EBEE0();
    virtual void slot18();
};
typedef char BitmapSizeCheck[sizeof(Bitmap_802EBEE0) == 0x48 ? 1 : -1];

extern "C" Bitmap_802EBEE0* fn_8020AD70() {
    void* object = fn_801EFA1C(lbl_801EF5C8, sizeof(Bitmap_802EBEE0),
                                 lbl_802AE024, lbl_802AE304, 189, 4);
    return new (object) Bitmap_802EBEE0;
}
