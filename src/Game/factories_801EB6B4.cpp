// Recovered engine allocation-and-construction factory fragment.
// Header strings identify registrations, not complete original translation units.
extern "C" {
extern char lbl_801EF5C8[];
void *fn_801EFA1C(void *, unsigned long, const char *, const char *, int, int);
extern const char lbl_802ACF20[];
extern const char lbl_802AD0C0[];
extern const char lbl_802AD0CC[];
void *fn_8026C174(void *);
void *fn_8026E7C4(void *);

// MeshGC_Z.h:37; allocation size 0x11C.
void *fn_801EB6B4()
{
    void *object = fn_801EFA1C(lbl_801EF5C8, 0x11C, lbl_802ACF20,
                              lbl_802AD0C0, 37, 4);
    if (object)
        object = fn_8026E7C4(object);
    return object;
}

// LodGC_Z.h:43; allocation size 0x138.
void *fn_801EB70C()
{
    void *object = fn_801EFA1C(lbl_801EF5C8, 0x138, lbl_802ACF20,
                              lbl_802AD0CC, 43, 4);
    if (object)
        object = fn_8026C174(object);
    return object;
}
}
