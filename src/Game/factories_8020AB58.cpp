// CameraZone and Occluder construction with an observed SplineZone base.
extern "C" {
extern char lbl_801EF5C8[];
void* fn_801EFA1C(void*, unsigned long, const char*, const char*, int, int);
void __ct__15BitSet_80207EE8Fv(void*);
extern const char lbl_802AE024[], lbl_802AE2B4[], lbl_802AE2C4[];
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
struct SplineZone_8024E5CC : BaseObject_Z {
    unsigned char unknown0C[0x60];
    short kind;
    unsigned char unknown6E[0x6A];
    SplineZone_8024E5CC();
    virtual ~SplineZone_8024E5CC();
};
struct ZoneList {
    int count, capacity;
    void* data;
    ZoneList() { count = 0; capacity = 0; data = 0; }
};
struct ZoneHash {
    int cursor, capacity, count;
    void* slots;
    ZoneHash() { __ct__15BitSet_80207EE8Fv(this); }
};
struct CameraZone_802EA180 : SplineZone_8024E5CC {
    ZoneList first, second;
    CameraZone_802EA180() { kind = 11; }
    virtual ~CameraZone_802EA180();
};
struct Occluder_802EA3E8 : SplineZone_8024E5CC {
    ZoneHash table;
    Occluder_802EA3E8() { kind = 10; }
    virtual ~Occluder_802EA3E8();
};
typedef char SplineZoneSizeCheck[sizeof(SplineZone_8024E5CC) == 0xD8 ? 1 : -1];
typedef char CameraZoneSizeCheck[sizeof(CameraZone_802EA180) == 0xF0 ? 1 : -1];
typedef char OccluderSizeCheck[sizeof(Occluder_802EA3E8) == 0xE8 ? 1 : -1];

extern "C" CameraZone_802EA180* fn_8020AB58() {
    void* object = fn_801EFA1C(lbl_801EF5C8, sizeof(CameraZone_802EA180),
                                 lbl_802AE024, lbl_802AE2B4, 52, 4);
    return new (object) CameraZone_802EA180;
}
extern "C" Occluder_802EA3E8* fn_8020ABE4() {
    return new (fn_801EFA1C(lbl_801EF5C8, sizeof(Occluder_802EA3E8),
                           lbl_802AE024, lbl_802AE2C4, 46, 4)) Occluder_802EA3E8;
}
