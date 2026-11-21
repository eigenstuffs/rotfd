// Recovered engine allocation-and-construction factory fragment.
// Header strings identify registrations, not complete original translation units.
extern "C" {
extern char lbl_801EF5C8[];
void *fn_801EFA1C(void *, unsigned long, const char *, const char *, int, int);
extern const char lbl_802AE024[];
extern const char lbl_802AE310[];
extern const char lbl_802AE31C[];
void *fn_801CFAB0(void *);
void *__ct__13Node_802417BCFv(void *);

// Node_Z.h:249; allocation size 0x138.
void *fn_8020AE04()
{
    void *object = fn_801EFA1C(lbl_801EF5C8, 0x138, lbl_802AE024,
                              lbl_802AE310, 249, 4);
    if (object)
        object = __ct__13Node_802417BCFv(object);
    return object;
}

// Points_Z.h:50; allocation size 0x8C.
void *fn_8020AE5C()
{
    void *object = fn_801EFA1C(lbl_801EF5C8, 0x8C, lbl_802AE024,
                              lbl_802AE31C, 50, 4);
    if (object)
        object = fn_801CFAB0(object);
    return object;
}
}
