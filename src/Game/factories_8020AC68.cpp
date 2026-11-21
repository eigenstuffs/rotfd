// Recovered engine allocation-and-construction factory fragment.
// Header strings identify registrations, not complete original translation units.
extern "C" {
extern char lbl_801EF5C8[];
void *fn_801EFA1C(void *, unsigned long, const char *, const char *, int, int);
extern const char lbl_802AE024[];
extern const char lbl_802AE2D4[];
extern const char lbl_802AE2E4[];
extern const char lbl_802AE2F0[];
void *__ct__21MaterialAnim_802EC000Fv(void *);
void *fn_8024E18C(void *);
void *__ct__19SplineZone_8024E5CCFv(void *);

// SplineZone_Z.h:115; allocation size 0xD8.
void *fn_8020AC68()
{
    void *object = fn_801EFA1C(lbl_801EF5C8, 0xD8, lbl_802AE024,
                              lbl_802AE2D4, 115, 4);
    if (object)
        object = __ct__19SplineZone_8024E5CCFv(object);
    return object;
}

// Spline_Z.h:118; allocation size 0xA0.
void *fn_8020ACC0()
{
    void *object = fn_801EFA1C(lbl_801EF5C8, 0xA0, lbl_802AE024,
                              lbl_802AE2E4, 118, 4);
    if (object)
        object = fn_8024E18C(object);
    return object;
}

// MaterialAnim_Z.h:77; allocation size 0xBC.
void *fn_8020AD18()
{
    void *object = fn_801EFA1C(lbl_801EF5C8, 0xBC, lbl_802AE024,
                              lbl_802AE2F0, 77, 4);
    if (object)
        object = __ct__21MaterialAnim_802EC000Fv(object);
    return object;
}
}
