// Recovered engine allocation-and-construction factory fragment.
// Header strings identify registrations, not complete original translation units.
extern "C" {
extern char lbl_801EF5C8[];
void *fn_801EFA1C(void *, unsigned long, const char *, const char *, int, int);
extern const char lbl_802ACF20[];
extern const char lbl_802AD0B0[];
void *fn_8026ED8C(void *);
void *fn_8026EF64(void *);

// RotShapeGC_Z.h:60; allocation size 0x48.
void *fn_801EB4D8()
{
    void *object = fn_801EFA1C(lbl_801EF5C8, 0x48, lbl_802ACF20,
                              lbl_802AD0B0, 60, 4);
    if (object)
        object = fn_8026ED8C(object);
    return object;
}

// RotShapeGC_Z.h:30; allocation size 0xCC.
void *fn_801EB530()
{
    void *object = fn_801EFA1C(lbl_801EF5C8, 0xCC, lbl_802ACF20,
                              lbl_802AD0B0, 30, 4);
    if (object)
        object = fn_8026EF64(object);
    return object;
}
}
