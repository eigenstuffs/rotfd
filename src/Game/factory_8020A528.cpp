// Reconstructed factory and observed constructor initialization.
// See docs/notes/game-factory-specials.md; opaque fields retain their offsets.
extern "C" {
extern char lbl_801EF5C8[];
void *fn_801EFA1C(void *,unsigned long,const char *,const char *,int,int);
extern const char lbl_802AE024[];
extern const char lbl_802AE1E8[];
void __ct__13Manipulator_ZFv(void *);
struct FactoryView {
    unsigned char prefix[8]; const void *vtable;
    unsigned char reserved_c[0x698];
    int field_6a4;
    unsigned char reserved_6a8[0x40];
    int field_6e8;
    unsigned char reserved_6ec[0x160];
    int field_84c;
    unsigned char reserved_850[0xC0];
    int field_910;
};
extern const char lbl_802E9EA0[];
extern const char lbl_802E9F48[];
inline void initialize_base(FactoryView *p) { __ct__13Manipulator_ZFv(p); p->vtable=lbl_802E9F48; }

// DynamicAnim1_Z.h:67; allocation0x914.
FactoryView *fn_8020A528()
{
    FactoryView *p=(FactoryView *)fn_801EFA1C(lbl_801EF5C8,0x914,lbl_802AE024,lbl_802AE1E8,67,4);
    if(p) {
        initialize_base(p);
        p->vtable=lbl_802E9EA0;
        p->field_6a4=0;
        p->field_6e8=0;
        p->field_84c=0;
        p->field_910=0;
    }
    return p;
}
}
