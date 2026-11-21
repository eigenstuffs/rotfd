// Recovered engine allocation-and-construction factory fragment.
// Header strings identify registrations, not complete original translation units.
extern "C" {
extern char lbl_801EF5C8[];
void *fn_801EFA1C(void *, unsigned long, const char *, const char *, int, int);
extern const char lbl_802AE024[];
extern const char lbl_802AE20C[];
void *fn_80253428(void *);

// UserDefine_Z.h:44; allocation size 0x18.
void *fn_8020A68C()
{
    void *object = fn_801EFA1C(lbl_801EF5C8, 0x18, lbl_802AE024,
                              lbl_802AE20C, 44, 4);
    if (object)
        object = fn_80253428(object);
    return object;
}
}
