// Recovered engine allocation-and-construction factory fragment.
// Header strings identify registrations, not complete original translation units.
extern "C" {
extern char lbl_801EF5C8[];
void *fn_801EFA1C(void *, unsigned long, const char *, const char *, int, int);
extern const char lbl_802AE024[];
extern const char lbl_802AE184[];
void *__ct__15Object_80075C2CFv(void *);

// CameraEngineZone_Z.h:76; allocation size 0xC4.
void *fn_8020A324()
{
    void *object = fn_801EFA1C(lbl_801EF5C8, 0xC4, lbl_802AE024,
                              lbl_802AE184, 76, 4);
    if (object)
        object = __ct__15Object_80075C2CFv(object);
    return object;
}
}
