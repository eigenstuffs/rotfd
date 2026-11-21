struct CounterHandle {
    union {
        unsigned long value;
        struct { signed int tag : 8; signed int index : 24; } bits;
    };
};

struct CounterEntry {
    void* object;
    char unknown04[8];
    signed char tag;
    char unknown0D[3];
};

struct CounterManager {
    int count, capacity;
    CounterEntry* entries;
};

struct CounterContext {
    char unknown00[0x118];
    CounterManager* manager;
};

extern "C" {
extern CounterContext lbl_801E9D24;
extern const char lbl_8029B1D0[], lbl_8029B1DC[], lbl_8029B1E8[];
unsigned long fn_801F948C(void*, const char*);
}

inline void* resolveCounter(const CounterHandle& handle)
{
    CounterEntry* entry = &lbl_801E9D24.manager->entries[handle.bits.index];
    if (entry->tag == handle.bits.tag)
        return entry->object;
    return 0;
}

struct CounterName {
    unsigned long value;
    CounterName(const char* text) { value = fn_801F948C(this, text); }
    CounterName(const CounterName& other) { value = other.value; }
};

extern "C" void fn_800A6234(void*, signed char, const CounterName&);

struct CounterItem {
    char unknown00[8];
    int patties, jellies, sandDollars;
    char unknown14[12];
};

struct CounterGroup {
    int count, peakPatties, peakJellies, peakSandDollars;
    char unknown10[0x1C];
    CounterItem* items;
    char unknown30[0x64];
};

struct CounterOwner {
    char unknown00[0x60];
    CounterHandle handle;
    char unknown64[0x8C];
    int group, item;
    char unknownF8[0x40];
    CounterGroup* groups;
    int patties, jellies, sandDollars;
};

extern "C" void fn_80055DC0(CounterOwner* self)
{
    void* target = resolveCounter(self->handle);
    fn_800A6234(target, 0, CounterName(CounterName(lbl_8029B1D0)));
    self->groups[self->group].items[self->item].patties++;

    int sum = 0;
    for (int i = 0; i < self->groups[self->group].count; i++)
        sum += self->groups[self->group].items[i].patties;
    if (sum > self->groups[self->group].peakPatties)
        self->groups[self->group].peakPatties = sum;

    self->patties++;
}

extern "C" void fn_80055EE4(CounterOwner* self, int amount)
{
    void* target = resolveCounter(self->handle);
    fn_800A6234(target, 0, CounterName(CounterName(lbl_8029B1DC)));
    if (amount > 0) {
        self->groups[self->group].items[self->item].jellies += amount;

        int sum = 0;
        for (int i = 0; i < self->groups[self->group].count; i++)
            sum += self->groups[self->group].items[i].jellies;
        if (sum > self->groups[self->group].peakJellies)
            self->groups[self->group].peakJellies = sum;
    }

    self->jellies += amount;
}

extern "C" void fn_80056014(CounterOwner* self, int amount)
{
    void* target = resolveCounter(self->handle);
    fn_800A6234(target, 0, CounterName(CounterName(lbl_8029B1E8)));
    if (amount > 0) {
        self->groups[self->group].items[self->item].sandDollars += amount;

        int sum = 0;
        for (int i = 0; i < self->groups[self->group].count; i++)
            sum += self->groups[self->group].items[i].sandDollars;
        if (sum > self->groups[self->group].peakSandDollars)
            self->groups[self->group].peakSandDollars = sum;
    }

    self->sandDollars += amount;
}
