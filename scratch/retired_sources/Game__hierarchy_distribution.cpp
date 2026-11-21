// Recovered from GSQE78; the observed hierarchy range-distribution method.
// Private layouts describe only the fields and virtual slots this method uses.
typedef unsigned long u32;
struct Handle {
    union { u32 value; struct { signed int generation:8; signed int index:24; } bits; };
};
struct HandleList { int count, capacity; Handle* data; };
struct Handle_801F7F10 { Handle_801F7F10(); ~Handle_801F7F10(); u32 value; };
struct ObjectStorage { char unknown[8]; };
struct Object : ObjectStorage {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29(int);
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37(int);
    char unknown0C[0x24-0x0C];
    int offset;
};
struct ResourceEntry { Object* object; u32 unused[2]; signed char generation; char padding[3]; };
struct Manager { u32 unused[2]; ResourceEntry* entries; };
struct Dispatcher;
struct Globals {
    char unknown[0x118]; Manager* manager;
    char unknown11C[8]; Dispatcher* dispatcher;
    char unknown128[0x14]; void* groups;
};
extern "C" Globals lbl_801E9D24;
extern "C" void fn_801F86C8(Manager*, const void*, short);
struct DistributionHandle : Handle_801F7F10 {
    DistributionHandle(const Handle& source) {
        value = source.value;
        fn_801F86C8(lbl_801E9D24.manager, &source, 1);
    }
};
struct DispatcherStorage { char unknown[0x30]; };
struct Dispatcher : DispatcherStorage {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12(DistributionHandle);
};
struct HierarchyDistribution {
    u32 unused; Handle owner;
    char unknown08[0x90-8];
    HandleList first;
    HandleList second;
    HandleList third;
    HandleList fourth;
    Handle related;
    char unknownC4[0xDC-0xC4];
    int count, width, offset;
    const Handle& getOwner() const { return owner; }
};
static inline Object* resolve(const Handle& h) {
    ResourceEntry* e = lbl_801E9D24.manager->entries + h.bits.index;
    return e->generation == h.bits.generation ? e->object : 0;
}
extern "C" {
signed char fn_80206A20(HierarchyDistribution*);
int fn_801FF9C8(void*);
u32 fn_801F7EB8(Handle*);
void fn_8022CEA4(Object*, int);
void fn_802020AC(HierarchyDistribution*);
void fn_801FBFD0(HierarchyDistribution*, int, int, float);
extern const float lbl_8037A900;
void fn_8020279C(HierarchyDistribution* self, int offset, int width) {
    fn_80206A20(self);
    int available = self->second.count;
    if (available <= fn_801FF9C8(lbl_801E9D24.groups)) {
        self->width = width;
        self->offset = offset;
        for (int i = 0; i < self->count; ++i) {
            if (fn_801F7EB8(&self->third.data[i]))
                resolve(self->third.data[i])->slot37(self->offset + i % self->width);
            if (fn_801F7EB8(&self->first.data[i]))
                resolve(self->first.data[i])->slot29(self->offset + i % self->width);
        }
        fn_8022CEA4(resolve(self->related), self->width);
        resolve(self->related)->offset = self->offset;
        fn_802020AC(self);
        lbl_801E9D24.dispatcher->slot12(DistributionHandle(self->getOwner()));
        fn_801FBFD0(self, 15, 0x51, lbl_8037A900);
    }
}
}
