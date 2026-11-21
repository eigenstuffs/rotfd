// Recovered hierarchy command forwarding and member removal.
typedef unsigned long u32;
struct Handle_801F7F10;
struct CommandHandleRef {
    union {
        u32 value;
        struct { signed int generation : 8; signed int index : 24; } bits;
    };
    CommandHandleRef& operator=(const Handle_801F7F10&);
};
struct Handle_801F7F10 {
    Handle_801F7F10();
    ~Handle_801F7F10();
    u32 value;
};
struct CommandObjectStorage { char unused[8]; };
// The two used methods occupy original vtable offsets 0x30 and 0x13C.
struct CommandObject : CommandObjectStorage {
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
    virtual void reset();
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
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void slot54();
    virtual void slot55();
    virtual void slot56();
    virtual void slot57();
    virtual void slot58();
    virtual void slot59();
    virtual void slot60();
    virtual void slot61();
    virtual void slot62();
    virtual void slot63();
    virtual void slot64();
    virtual void slot65();
    virtual void slot66();
    virtual void slot67();
    virtual void slot68();
    virtual void slot69();
    virtual void slot70();
    virtual void slot71();
    virtual void slot72();
    virtual void slot73();
    virtual void slot74();
    virtual void slot75();
    virtual void slot76();
    virtual void command(u32, u32, CommandHandleRef*);
};

struct CommandEntry {
    CommandObject* object;
    u32 unused[2];
    signed char generation;
    char pad[3];
};
struct CommandManagerStorage {
    u32 unknown[2];
    CommandEntry* entries;
    char unusedC[0x24 - 0xC];
};
struct CommandManager : CommandManagerStorage { virtual void flush(); };
struct CommandGlobals { char unused[0x118]; CommandManager* manager; };
struct CommandList { int count, capacity; CommandHandleRef* data; };
struct CommandHolder {
    char unused[0xC];
    CommandHandleRef owner;
    char unused10[0x80];
    CommandList second, assigned, third;
};
extern "C" {
extern CommandGlobals lbl_801E9D24;
u32 fn_801F7EB8(CommandHandleRef*);
void fn_801F86C8(CommandManager*, const void*, short);
void fn_8025BF0C(CommandObject*, CommandHandleRef*);
void fn_801FD3EC(CommandHolder*, CommandHandleRef*);
}
static inline CommandObject* resolve(const CommandHandleRef& handle) {
    CommandEntry* entry = lbl_801E9D24.manager->entries + handle.bits.index;
    return entry->generation == handle.bits.generation ? entry->object : 0;
}
struct CommandZeroLayer : Handle_801F7F10 {
    CommandZeroLayer() { value = 0; }
};
struct CommandOwnedHandle : CommandZeroLayer {
    CommandOwnedHandle(const CommandHandleRef& source) {
        value = source.value;
        fn_801F86C8(lbl_801E9D24.manager, &source, 1);
    }
};
template<int N> struct CommandEmptyHandle : CommandEmptyHandle<N - 1> {
    CommandEmptyHandle() { value = 0; }
};
template<> struct CommandEmptyHandle<0> : Handle_801F7F10 {};
// A native nontrivial value parameter uses the compiler's hidden pointer ABI.
extern "C" void fn_801FC514(CommandHolder*, CommandOwnedHandle);
inline CommandHandleRef& CommandHandleRef::operator=(const Handle_801F7F10& source) {
    fn_801F86C8(lbl_801E9D24.manager, this, -1);
    value = source.value;
    fn_801F86C8(lbl_801E9D24.manager, &source, 1);
    return *this;
}

extern "C" u32 fn_80200CBC(CommandHolder* self, int index, signed char flush) {
    resolve(self->second.data[index])->reset();
    if (fn_801F7EB8(&self->third.data[index]))
        resolve(self->third.data[index])->reset();
    if (fn_801F7EB8(&self->third.data[index])) {
        self->assigned.data[index] = CommandEmptyHandle<5>();
        fn_8025BF0C(resolve(self->second.data[index]), &self->assigned.data[index]);
        fn_801FD3EC(self, &self->third.data[index]);
        fn_801FC514(self, CommandOwnedHandle(self->third.data[index]));
        if (flush)
            lbl_801E9D24.manager->flush();
    }
    return 1;
}
extern "C" void fn_80200C38(CommandHolder* self, u32 a, u32 b, int index) {
    resolve(self->assigned.data[index])->command(a, b, &self->owner);
}
