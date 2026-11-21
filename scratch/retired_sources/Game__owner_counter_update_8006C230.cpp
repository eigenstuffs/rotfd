/* Disable an owner action, update its signed counter, then register its resource. */
struct Resource {
    char unknown00[0x1F8];
    void* registration;
};
struct Prefix { int unknown00; };
struct Query : Prefix {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual Resource* getResource();
    char unknown08[0x14E];
    unsigned short amount;
};
extern "C" {
void fn_8006C508(Query*, int);
Resource* fn_8005E9A0();
void fn_80024A04(void*, Resource*);
extern Resource* lbl_803776D8;
extern Query* lbl_803776B8;
extern short lbl_8037757A, lbl_80377578;
}

extern "C" signed char fn_8006C230(Query* self)
{
    Resource* resource = self->getResource();
    fn_8006C508(self, 0);
    if (lbl_803776D8 == fn_8005E9A0()) {
        int amount = (short)self->amount;
        lbl_803776B8->getResource();
        lbl_8037757A += amount;
        if (lbl_8037757A < 0)
            lbl_8037757A = 0;
    } else {
        int amount = (short)self->amount;
        lbl_803776B8->getResource();
        lbl_80377578 += amount;
        if (lbl_80377578 < 0)
            lbl_80377578 = 0;
    }
    fn_80024A04(lbl_803776B8->getResource()->registration, resource);
    return 1;
}
