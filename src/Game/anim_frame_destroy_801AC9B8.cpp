typedef unsigned long Word;

extern "C" {
extern char lbl_802E9D98[], __vt__13Manipulator_Z[];
extern char lbl_8028F698[], lbl_801EF5C8[];
void fn_8028FD50(void*, void*, unsigned long);
void fn_801EF610(void*, void*);
}

struct Activable_Z {
    Word unknown00[2];
    void* table;
    char unknown0C[0x10];
    ~Activable_Z();
};
struct Manipulator_Z : Activable_Z {
    float field1C;
    ~Manipulator_Z() { table = __vt__13Manipulator_Z; }
};
struct Handle_801F7F10 { Word word; ~Handle_801F7F10(); };
struct FrameHandle1_AC9B8 : Handle_801F7F10 { ~FrameHandle1_AC9B8() {} };
struct FrameHandle2_AC9B8 : FrameHandle1_AC9B8 { ~FrameHandle2_AC9B8() {} };
struct CurveBase_801B1088 {
    unsigned short flags, unknown;
    ~CurveBase_801B1088();
};

template<class T> struct FrameArray_AC9B8 {
    int count, capacity;
    T* data;
    ~FrameArray_AC9B8() {
        if (data) {
            for (int i = 0; i < count; ++i)
                data[i].~T();
            if (data) {
                fn_8028FD50(lbl_8028F698, data, capacity * sizeof(T));
                data = 0;
            }
            data = 0;
        }
    }
};
template<class T> struct FrameCurve_AC9B8 : CurveBase_801B1088 {
    FrameArray_AC9B8<T> rows;
    ~FrameCurve_AC9B8() {}
};
struct FrameRecord16_AC9B8 { Word fields[4]; ~FrameRecord16_AC9B8() {} };
struct FrameRecord20_AC9B8 { Word fields[5]; ~FrameRecord20_AC9B8() {} };
struct FrameRecord28_AC9B8 {
    Word prefix;
    FrameHandle2_AC9B8 handle;
    char tail[20];
    ~FrameRecord28_AC9B8() {}
};
struct FrameNestedRecord_AC9B8 {
    FrameHandle1_AC9B8 handle;
    Word tail;
    ~FrameNestedRecord_AC9B8() {}
};
struct FrameNestedRow_AC9B8 {
    Word prefix;
    FrameArray_AC9B8<FrameNestedRecord_AC9B8> rows;
    ~FrameNestedRow_AC9B8() {}
};
struct WorldActionCurve_801F7560 : CurveBase_801B1088 {
    int count, capacity;
    void* data;
    virtual ~WorldActionCurve_801F7560();
};
struct AnimFrame_801EF438 : Manipulator_Z {
    FrameHandle2_AC9B8 handle;
    Word unknown24;
    FrameCurve_AC9B8<FrameRecord20_AC9B8> a, b, c;
    FrameCurve_AC9B8<FrameRecord16_AC9B8> d;
    FrameCurve_AC9B8<FrameRecord28_AC9B8> e;
    FrameCurve_AC9B8<FrameNestedRow_AC9B8> f;
    FrameCurve_AC9B8<FrameRecord16_AC9B8> g, h;
    WorldActionCurve_801F7560 action;
    short fieldBC, unknownBE;
    float x, y, z;
};

extern "C" AnimFrame_801EF438* fn_801AC9B8(
    AnimFrame_801EF438* self, short deleting) {
    if (self) {
        self->table = lbl_802E9D98;
        self->action.WorldActionCurve_801F7560::~WorldActionCurve_801F7560();
        self->h.~FrameCurve_AC9B8<FrameRecord16_AC9B8>();
        self->g.~FrameCurve_AC9B8<FrameRecord16_AC9B8>();
        self->f.~FrameCurve_AC9B8<FrameNestedRow_AC9B8>();
        self->e.~FrameCurve_AC9B8<FrameRecord28_AC9B8>();
        self->d.~FrameCurve_AC9B8<FrameRecord16_AC9B8>();
        self->c.~FrameCurve_AC9B8<FrameRecord20_AC9B8>();
        self->b.~FrameCurve_AC9B8<FrameRecord20_AC9B8>();
        self->a.~FrameCurve_AC9B8<FrameRecord20_AC9B8>();
        self->handle.~FrameHandle2_AC9B8();
        self->Manipulator_Z::~Manipulator_Z();
        if (deleting > 0)
            fn_801EF610(lbl_801EF5C8, self);
    }
    return self;
}
