// Recovered engine allocation-and-construction factory fragment.
// Header strings identify registrations, not complete original translation units.
extern "C" {
extern char lbl_801EF5C8[];
void *fn_801EFA1C(void *, unsigned long, const char *, const char *, int, int);
extern const char lbl_802ACF20[];
extern const char lbl_802AD0F0[];
void *fn_8026D944(void *);

// MaterialGC_Z.h:21; allocation size 0x7C.
void *fn_801EBA70()
{
    void *object = fn_801EFA1C(lbl_801EF5C8, 0x7C, lbl_802ACF20,
                              lbl_802AD0F0, 21, 4);
    if (object)
        object = fn_8026D944(object);
    return object;
}
}
