// Reconstructed factory and observed constructor initialization.
// See docs/notes/game-factory-specials.md; opaque fields retain their offsets.
extern "C" {
extern char lbl_801EF5C8[];
void *fn_801EFA1C(void *,unsigned long,const char *,const char *,int,int);
extern const char lbl_802AE024[];
extern const char lbl_802AE1D4[];
void __ct__13Manipulator_ZFv(void *);
struct FactoryView {
    unsigned char prefix[8]; const void *vtable;
    unsigned char reserved_c[0x958];
    int field_964;
    unsigned char reserved_968[0xC4];
    int field_a2c;
    unsigned char reserved_a30[0x160];
    int field_b90;
};
extern const char lbl_802E9EF8[];
extern const char lbl_802E9F48[];
inline void initialize_base(FactoryView *p) { __ct__13Manipulator_ZFv(p); p->vtable=lbl_802E9F48; }

// DynamicAnim2_Z.h:82; allocation0xB9C.
FactoryView *fn_8020A4A4()
{
    FactoryView *p=(FactoryView *)fn_801EFA1C(lbl_801EF5C8,0xB9C,lbl_802AE024,lbl_802AE1D4,82,4);
    if(p) {
        initialize_base(p);
        p->vtable=lbl_802E9EF8;
        p->field_964=0;
        p->field_a2c=0;
        p->field_b90=0;
    }
    return p;
}
}
