#include "Game/engine_screen_handle_registration.h"

typedef unsigned long Word;
struct Handle_801F7F10 {
    union { Word value; struct { signed int generation:8, index:24; } bits; };
    Handle_801F7F10();
    ~Handle_801F7F10();
};
struct ScreenRegistrationResource;
struct ScreenRegistrationEntry {
    ScreenRegistrationResource* object;
    Word unknown04, unknown08;
    signed char generation;
    char padding[3];
};
struct ScreenRegistrationManager {
    Word unknown00, unknown04;
    ScreenRegistrationEntry* entries;
};
struct ScreenRegistrationGlobals {
    char unknown00[0x118];
    ScreenRegistrationManager* manager;
};
extern "C" {
extern ScreenRegistrationGlobals lbl_801E9D24;
extern const char lbl_802AEFD0[], lbl_8037B6E0[7];
void fn_801F86C8(ScreenRegistrationManager*, const void*, short);
Word fn_801F948C(void*, const char*);
void fn_80238BA8(ScreenRegistrationResource*, int, int, int);
}
struct ScreenRegistrationName {
    Word value;
    ScreenRegistrationName(const char* s) { value = fn_801F948C(this, s); }
};
struct ScreenRegistrationZero : Handle_801F7F10 {
    ScreenRegistrationZero() { value = 0; }
    ~ScreenRegistrationZero() {}
};
struct ScreenRegistrationOwned : ScreenRegistrationZero {
    ScreenRegistrationOwned() { value = 0; }
    ScreenRegistrationOwned(const Handle_801F7F10& h) {
        value = h.value;
        fn_801F86C8(lbl_801E9D24.manager, &h, 1);
    }
    ScreenRegistrationOwned& operator=(const ScreenRegistrationOwned& h) {
        fn_801F86C8(lbl_801E9D24.manager, this, -1);
        value = h.value;
        fn_801F86C8(lbl_801E9D24.manager, &h, 1);
        return *this;
    }
    ~ScreenRegistrationOwned() {}
};
struct ScreenRegistrationResource {
    char unknown00[0x68];
    Word flags;
    char unknown6C[8];
    ScreenRegistrationOwned linked;
    void setLinked(const ScreenRegistrationOwned& h) { linked = h; }
};
inline ScreenRegistrationResource* resolve(const Handle_801F7F10& h) {
    ScreenRegistrationEntry* e = lbl_801E9D24.manager->entries + h.bits.index;
    return e->generation == h.bits.generation ? e->object : 0;
}
extern "C" Handle_801F7F10 fn_801B550C(ScreenRegistrationManager*,
    const ScreenRegistrationName&, const ScreenRegistrationName&);

inline void* operator new(Word, void* p) { return p; }
struct ScreenRegistrationOwner {
    char unknown00[0x9F0];
    ScreenRegistrationOwned* first;
    ScreenRegistrationOwned* second;
    int count;
};
extern "C" void fn_8027235C(ScreenRegistrationOwner* self) {
    const char* pool = lbl_802AEFD0;
    if (self->count < 32) {
        new(&self->second[self->count]) ScreenRegistrationOwned;
        new(&self->first[self->count]) ScreenRegistrationOwned;
        self->second[self->count] = ScreenRegistrationOwned(fn_801B550C(
            lbl_801E9D24.manager, ScreenRegistrationName(lbl_8037B6E0),
            ScreenRegistrationName(pool + 0xCC)));
        fn_80238BA8(resolve(self->second[self->count]), 64, 64, 12);
        self->first[self->count] = ScreenRegistrationOwned(fn_801B550C(
            lbl_801E9D24.manager, ScreenRegistrationName(pool + 0xEC),
            ScreenRegistrationName(pool + 0xDC)));
        resolve(self->first[self->count])->setLinked(self->second[self->count]);
        resolve(self->first[self->count])->flags |= 6;
        ++self->count;
    }
}
