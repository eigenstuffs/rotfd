extern "C" {
extern char lbl_801EF5C8[];
void *fn_801EFA1C(void *,unsigned long,const char *,const char *,int,int);
extern const char lbl_802AE024[];
extern const char lbl_802AE034[];
void __ct__13Manipulator_ZFv(void *);
struct FactoryView {
    unsigned char prefix[8]; const void *vtable;
    unsigned char reserved_c[0x14];
    int field_20;
    int field_24;
    int field_28;
    int field_2c;
};
extern const char lbl_802EAED0[];

// ConsoleInterp_Z.h:28; allocation0x30.
FactoryView *fn_802092A8()
{
    FactoryView *p=(FactoryView *)fn_801EFA1C(lbl_801EF5C8,0x30,lbl_802AE024,lbl_802AE034,28,4);
    if(p) {
        __ct__13Manipulator_ZFv(p);
        p->vtable=lbl_802EAED0;
        p->field_20=0;
        p->field_24=0;
        p->field_28=0;
        p->field_2c=-1;
    }
    return p;
}
}
