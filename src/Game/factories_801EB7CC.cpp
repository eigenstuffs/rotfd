// Recovered engine allocation-and-construction factory fragment.
// Header strings identify registrations, not complete original translation units.
extern "C" {
extern char lbl_801EF5C8[];
void *fn_801EFA1C(void *, unsigned long, const char *, const char *, int, int);
extern const char lbl_802ACF20[];
extern const char lbl_802AD0D8[];
void *fn_8026F078(void *);

// SkelGC_Z.h:20; allocation size 0x7C.
void *fn_801EB7CC()
{
    void *object = fn_801EFA1C(lbl_801EF5C8, 0x7C, lbl_802ACF20,
                              lbl_802AD0D8, 20, 4);
    if (object)
        object = fn_8026F078(object);
    return object;
}
}
