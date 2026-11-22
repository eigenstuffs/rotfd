struct Storage_801C3D98 {
    char pad[8];
};
struct Object_801C3D98:Storage_801C3D98{
    virtual void slot08();
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
    virtual void slot44();
    virtual void slot48();
    virtual void first(float);
    virtual void second(float);
    char padC[0x20];
    unsigned char flags;
};
extern "C" void fn_801C3D98(Object_801C3D98 *self,float amount){
    if(self->flags&2)self->first(amount);
    if(self->flags&1)self->second(amount);
}
