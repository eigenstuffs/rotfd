/* fn_8026B038: world-owner slot 0x1C override. Runs BaseObject_Z::slot1C,
   then forwards slot 0x1C to every live handle the owner holds: the arrays at
   +0x0C, +0x24 and +0xC100 (validity-checked), the scalar handle at +0x30,
   the two fixed eight-handle arrays at +0xC110 and +0xC140, and the two
   validity-checked handles at +0xC164/+0xC168. Layout as in
   src/Game/world_reference_callbacks.cpp. */
struct Handle { signed int tag : 8, index : 24; };
struct ObjectPrefix { char unknown[8]; };
struct Object : ObjectPrefix {
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1C();
};
struct Entry {
    Object* object;
    char unknown[8];
    signed char tag;
    char tail[3];
};
struct Manager {
    int count, capacity;
    Entry* entries;
    inline Object* get(const Handle& h)
    {
        Entry* e = entries + h.index;
        return e->tag == h.tag ? e->object : 0;
    }
};
struct Global { char unknown[0x118]; Manager* manager; };
struct Array { int count, capacity; Handle* data; };
struct Fixed {
    Handle data[8];
    int count;
    Handle& operator[](unsigned int i) { return data[i]; }
};
struct Owner {
    char base[0xC];
    Array a0C, a18, a24;
    Handle h30;
    char unknown34[0xC100 - 0x34];
    Array aC100;
    int unknownC10C;
    Fixed fC110;
    Array aC134;
    Fixed fC140;
    Handle hC164, hC168;
};
typedef char CheckOwner[sizeof(Owner) == 0xC16C ? 1 : -1];
extern "C" {
extern Global lbl_801E9D24;
unsigned int fn_801F7EB8(const Handle*);
signed char slot1C__12BaseObject_ZFv(void*);
}

extern "C" signed char fn_8026B038(Owner* self)
{
    if (!slot1C__12BaseObject_ZFv(self))
        return 0;
    int i;
    for (i = 0; i < self->a0C.count; i++) {
        if (fn_801F7EB8(&self->a0C.data[i]))
            lbl_801E9D24.manager->get(self->a0C.data[i])->slot1C();
    }
    for (i = 0; i < self->a24.count; i++) {
        if (fn_801F7EB8(&self->a24.data[i]))
            lbl_801E9D24.manager->get(self->a24.data[i])->slot1C();
    }
    for (i = 0; i < self->aC100.count; i++) {
        if (fn_801F7EB8(&self->aC100.data[i]))
            lbl_801E9D24.manager->get(self->aC100.data[i])->slot1C();
    }
    if (fn_801F7EB8(&self->h30))
        lbl_801E9D24.manager->get(self->h30)->slot1C();
    for (i = 0; i < self->fC110.count; i++)
        lbl_801E9D24.manager->get(self->fC110[i])->slot1C();
    for (i = 0; i < self->fC140.count; i++)
        lbl_801E9D24.manager->get(self->fC140[i])->slot1C();
    if (fn_801F7EB8(&self->hC164))
        lbl_801E9D24.manager->get(self->hC164)->slot1C();
    if (fn_801F7EB8(&self->hC168))
        lbl_801E9D24.manager->get(self->hC168)->slot1C();
    return 1;
}
