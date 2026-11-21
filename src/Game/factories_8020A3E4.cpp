// Recovered engine allocation-and-construction factory fragment.
// Header strings identify registrations, not complete original translation units.
extern "C" {
extern char lbl_801EF5C8[];
void *fn_801EFA1C(void *, unsigned long, const char *, const char *, int, int);
extern const char lbl_802AE024[];
extern const char lbl_802AE1AC[];
void *__ct__20QueueGroups_802EBDA0Fv(void *);

// SequenceMixAnim_Z.h:43; allocation size 0x188.
void *fn_8020A3E4()
{
    void *object = fn_801EFA1C(lbl_801EF5C8, 0x188, lbl_802AE024,
                              lbl_802AE1AC, 43, 4);
    if (object)
        object = __ct__20QueueGroups_802EBDA0Fv(object);
    return object;
}
}
