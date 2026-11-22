extern "C" {
extern char lbl_801EF5C8[];
void *fn_801EFA1C(void *,unsigned long,const char *,const char *,int,int);
extern const char lbl_802AE024[];
extern const char lbl_802AE21C[];
void __ct__12BaseObject_ZFv(void *);
struct FactoryView {
    unsigned char prefix[8]; const void *vtable;
    int field_c;
    int field_10;
    int field_14;
};
extern const char __vt__23HandleResource_802EA820[];
extern const char __vt__17Resource_802E9E20[];
inline void initialize_base(FactoryView *p) { __ct__12BaseObject_ZFv(p); p->vtable=__vt__17Resource_802E9E20; }

// MaterialObj_Z.h:20; allocation0x18.
FactoryView *fn_8020A738()
{
    FactoryView *p=(FactoryView *)fn_801EFA1C(lbl_801EF5C8,0x18,lbl_802AE024,lbl_802AE21C,20,4);
    if(p) {
        initialize_base(p);
        p->vtable=__vt__23HandleResource_802EA820;
        p->field_c=0;
        p->field_10=0;
        p->field_14=0;
    }
    return p;
}
}
