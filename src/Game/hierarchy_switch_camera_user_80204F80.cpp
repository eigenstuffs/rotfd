// SwitchCameraUser console command: toggles the selected group state (GSQE78 0x80204F80).
typedef unsigned long u32;
struct Handle {
    union { u32 value; struct { signed int generation:8; signed int index:24; } bits; };
};
struct Handle_801F7F10 { Handle_801F7F10(); ~Handle_801F7F10(); Handle token; };
struct ToggleZeroHandle1 : Handle_801F7F10 { ToggleZeroHandle1() { token.value = 0; } };
struct ToggleZeroHandle2 : ToggleZeroHandle1 { ToggleZeroHandle2() { token.value = 0; } };
struct HandleList { int count, capacity; Handle* data; };
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
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual int viewIndex();
    char unknownC[0x9C - 0xC]; HandleList primary; HandleList secondary;
    char unknownB4[0xDC - 0xB4]; int count;
};
struct ResourceEntry { Object* object; u32 unknown[2]; signed char generation; char padding[3]; };
struct Manager { u32 unknown[2]; ResourceEntry* entries; };
struct Groups { Handle fixed[4]; signed char flags[4]; HandleList entries; };
struct Engine {
    char unknown[0x860]; int state;
    char unknown864[0x8A5 - 0x864]; signed char active;
    char unknown8A6[0x8B8 - 0x8A6]; float selection;
};
struct Game { char unknown[0x214]; signed char count; };
struct ToggleGlobals {
    char unknown[0x110]; Engine* engine; Game* game; Manager* manager;
    char unknown11C[0x20]; Groups* groups;
};
extern "C" ToggleGlobals lbl_801E9D24;
static inline Object* lookup(Manager* manager, int index, int generation) {
    signed char& id = manager->entries[index].generation;
    return id == generation ? manager->entries[index].object : 0;
}
static inline Object* resolve(const Handle& h) {
    int generation = h.bits.generation;
    Manager* manager = lbl_801E9D24.manager;
    int index = h.bits.index;
    return lookup(manager, index, generation);
}
extern "C" {
u32 fn_801F7EB8(const void*);
void fn_801F86C8(Manager*, const void*, short);
int fn_801FF834(Groups*, int);
void fn_80201A14(Object*, int);
void fn_80201B14(Object*, int);
void fn_802139D8(Object*);
void fn_80213A18(Object*);
}
struct ToggleCopyHandle : Handle_801F7F10 {
    ToggleCopyHandle(const Handle& source) {
        token.value = source.value;
        fn_801F86C8(lbl_801E9D24.manager, &source, 1);
    }
    int getIndex() const { return token.bits.index; }
    signed char getGeneration() const { return token.bits.generation; }
    Object* operator->() const {
        Manager* manager = lbl_801E9D24.manager;
        int index = getIndex();
        signed char& id = manager->entries[index].generation;
        return id == getGeneration() ? manager->entries[index].object : 0;
    }
};
extern "C" signed char fn_80204F80() {
    if (lbl_801E9D24.engine->state < 2)
        return 0;
    if (!lbl_801E9D24.engine->active)
        return 0;
    int selection = (int)lbl_801E9D24.engine->selection;
    if (selection >= lbl_801E9D24.game->count)
        return 0;
    ToggleZeroHandle2 reserved;
    int group = fn_801FF834(lbl_801E9D24.groups, selection);
    if (group < 0)
        return 0;
    ToggleCopyHandle hierarchy(lbl_801E9D24.groups->entries.data[group]);
    signed char active = lbl_801E9D24.groups->flags[selection];
    if (fn_801F7EB8(&hierarchy)) {
        int i;
        for (i = 0; i < hierarchy->count; ++i) {
            if (fn_801F7EB8(&hierarchy->secondary.data[i])) {
                if (selection == resolve(hierarchy->secondary.data[i])->viewIndex()) {
                    if (active)
                        fn_80201B14(hierarchy.operator->(), i);
                    else
                        fn_80201A14(hierarchy.operator->(), i);
                }
            }
        }
        if (active)
            fn_802139D8(resolve(lbl_801E9D24.groups->fixed[selection]));
        else
            fn_80213A18(resolve(lbl_801E9D24.groups->fixed[selection]));
        if (hierarchy->count && i == hierarchy->count) {
            for (int j = 0; j < hierarchy->count; ++j) {
                if (fn_801F7EB8(&hierarchy->primary.data[j])) {
                    if (active)
                        fn_80201B14(hierarchy.operator->(), j);
                    else
                        fn_80201A14(hierarchy.operator->(), j);
                }
            }
        }
    } else {
        if (active)
            fn_802139D8(resolve(lbl_801E9D24.groups->fixed[selection]));
        else
            fn_80213A18(resolve(lbl_801E9D24.groups->fixed[selection]));
    }
    lbl_801E9D24.groups->flags[selection] = !lbl_801E9D24.groups->flags[selection];
    return 1;
}
