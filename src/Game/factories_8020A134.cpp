// Recovered engine allocation-and-construction factory fragment.
// Header strings identify registrations, not complete original translation units.
extern "C" {
extern char lbl_801EF5C8[];
void *fn_801EFA1C(void *, unsigned long, const char *, const char *, int, int);
extern const char lbl_802AE024[];
extern const char lbl_802AE150[];
extern const char lbl_802AE164[];
void *__ct__13ObjectsBounceFv(void *);
void *__ct__11ObjectsMoveFv(void *);

// ObjectsBounce_Z.h:14; allocation size 0x1A8.
void *fn_8020A134()
{
    void *object = fn_801EFA1C(lbl_801EF5C8, 0x1A8, lbl_802AE024,
                              lbl_802AE150, 14, 4);
    if (object)
        object = __ct__13ObjectsBounceFv(object);
    return object;
}

// ObjectsMove_Z.h:192; allocation size 0x1A8.
void *fn_8020A18C()
{
    void *object = fn_801EFA1C(lbl_801EF5C8, 0x1A8, lbl_802AE024,
                              lbl_802AE164, 192, 4);
    if (object)
        object = __ct__11ObjectsMoveFv(object);
    return object;
}
}
