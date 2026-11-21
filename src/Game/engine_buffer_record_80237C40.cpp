struct BufferRecordResetStorage {unsigned int a,b;};
struct BufferRecordResetOwner:BufferRecordResetStorage {virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1C();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2C();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3C();
    virtual void slot40();
    virtual void slot44();};
extern "C" {void slot18__11Activable_ZFv(BufferRecordResetOwner*);void fn_80213920(BufferRecordResetOwner*,int);}
extern "C" void fn_80237C40(BufferRecordResetOwner* self)
{
    slot18__11Activable_ZFv(self);
    fn_80213920(self, 7);
    self->slot44();
    self->slot34();
}
