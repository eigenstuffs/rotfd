/* Timer advancement and callback dispatch through the observed partial view.
 * See docs/notes/game-engine-timer-dispatch.md. */
typedef unsigned long Word;

struct Handle_EDB54 {
    union {
        Word word;
        struct { signed int generation : 8, index : 24; } bits;
    };
};
struct Node_EDB54 {
    char unknown00[0x120];
    Word flags;
};
struct Entry_EDB54 {
    Node_EDB54* object;
    char unknown04[8];
    signed char generation;
    char unknown0D[3];
    signed char getGeneration() const { return generation; }
};
struct Manager_EDB54 {
    char unknown00[8];
    Entry_EDB54* entries;
};
extern "C" struct Global_EDB54 {
    char unknown00[0x118];
    Manager_EDB54* manager;
} lbl_801E9D24;

struct Callback_EDB54 {
    long adjustment, dispatch;
    Word target;
};
struct Timer_EDB54 {
    char unknown00[0x20];
    Handle_EDB54 owner;
    float period;
    char unknown28[0x50];
    Callback_EDB54 callback;
    char unknown84[0x38];
    unsigned short flags;
    char unknownBE[2];
    float current, limit, previous;
};

extern "C" {
extern const float lbl_8037A648;
void fn_801ECC98(Callback_EDB54*, Timer_EDB54*, float, float, float);
void fn_801ED468(Timer_EDB54*, Node_EDB54*);
void fn_801EDB54(Timer_EDB54*, float);
}

inline Node_EDB54* resolveOwnerEDB54(const Handle_EDB54& handle) {
    int index = handle.bits.index;
    Manager_EDB54* manager = lbl_801E9D24.manager;
    int generation = manager->entries[index].getGeneration();
    if (generation == handle.bits.generation)
        return manager->entries[index].object;
    return 0;
}

extern "C" void fn_801EDB54(Timer_EDB54* self, float delta) {
    Node_EDB54* owner = resolveOwnerEDB54(self->owner);
    if (owner && !(owner->flags & 0x100000) && !(self->flags & 0x100)
        && (self->flags & 2)) {
        if (self->flags & 0x80) {
            self->current = self->previous + delta;
            if (self->current > self->period) {
                while (self->current > self->period)
                    self->current -= self->period;
            }
            return;
        }
        self->previous = self->current;
        self->flags |= 0x80;
        self->current += delta;
        if (self->limit != lbl_8037A648) {
            if (self->current > self->limit) {
                self->previous = lbl_8037A648;
                float excess = self->current - self->limit;
                if ((!(signed char)(self->flags & 1)
                     && (self->flags & 0x28) != 0x28)
                    || (self->flags & 0x38) == 0x28) {
                    self->flags |= 7;
                    self->flags &= ~0x20;
                    if (self->flags & 0x100)
                        self->flags ^= 0x100;
                    else {
                        self->flags &= ~0x80;
                        self->limit = lbl_8037A648;
                        self->current = lbl_8037A648;
                        fn_801EDB54(self, excess);
                    }
                }
            } else
                return;
        }
        if (self->current > self->period) {
            if (self->flags & 8) {
                self->flags |= 0x20;
                self->current = self->period;
            }
            while (self->current > self->period)
                self->current -= self->period;
        }
        if ((self->flags & 4) && self->callback.dispatch)
            fn_801ECC98(&self->callback, self, self->previous,
                       self->current, self->period);
        fn_801ED468(self, owner);
    }
}
