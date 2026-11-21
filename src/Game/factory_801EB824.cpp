// Reconstructed factory and observed constructor initialization.
// See docs/notes/game-factory-specials.md; opaque fields retain their offsets.
extern "C" {
extern char lbl_801EF5C8[];
void *fn_801EFA1C(void *,unsigned long,const char *,const char *,int,int);
extern const char lbl_802ACF20[];
extern const char lbl_802AD0E4[];
void fn_8024D47C(void *);
struct FactoryView {
    unsigned char prefix[8]; const void *vtable;
    unsigned char reserved_c[0x8C];
    int field_98;
    int field_9c;
    int field_a0;
};
extern const char lbl_802ED400[];

// SkinGC_Z.h:42; allocation0xA4.
FactoryView *fn_801EB824()
{
    FactoryView *p=(FactoryView *)fn_801EFA1C(lbl_801EF5C8,0xA4,lbl_802ACF20,lbl_802AD0E4,42,4);
    if(p) {
        fn_8024D47C(p);
        p->vtable=lbl_802ED400;
        p->field_98=0;
        p->field_9c=0;
        p->field_a0=0;
    }
    return p;
}
}
