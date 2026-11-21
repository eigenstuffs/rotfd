// Recovered allocation-and-construction factory fragment.
// Original header strings identify each registration; full TU ownership is unknown.
// Constructors, diagnostic strings and allocator storage remain external.
extern "C" {
extern char lbl_801EF5C8[];
void *fn_801EFA1C(void *, unsigned long, const char *, const char *, int, int);
extern const char lbl_802A0E78[];
extern const char lbl_802A103C[];
void *fn_800C5354(void *);

// BusTicketAgent.h:12; allocation size 0x98.
void *fn_800BADC4()
{
    void *object = fn_801EFA1C(lbl_801EF5C8, 0x98, lbl_802A0E78,
                              lbl_802A103C, 12, 4);
    if (object)
        object = fn_800C5354(object);
    return object;
}
}
