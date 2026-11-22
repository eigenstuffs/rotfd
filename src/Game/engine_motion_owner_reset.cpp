#include "Game/engine_motion_owner_reset.h"
#include "objects_owner_internal.h"

typedef unsigned long MotionResetWord;

extern "C" {
extern char lbl_8028F698[];
void* fn_8028FAF4(void*, void*, MotionResetWord, MotionResetWord);
void* fn_8028FF24(void*, MotionResetWord);
void fn_8028FD50(void*, void*, MotionResetWord);
void fn_80213920(void*, int);
}

inline void* operator new(MotionResetWord, void* address)
{
    return address;
}

struct MotionResetItem12 {
    MotionResetWord words[3];
    MotionResetItem12() {}
    ~MotionResetItem12() {}
};

struct MotionResetItem16 {
    MotionResetWord words[4];
    MotionResetItem16() {}
    ~MotionResetItem16() {}
};

struct MotionResetItem40 {
    char unknown00[0x10];
    MotionResetWord count;
    MotionResetWord pointer;
    char unknown18[0x10];
    MotionResetItem40() { pointer = 0; count = 0; }
    ~MotionResetItem40() {}
};

struct MotionResetZeroHandle : Handle_801F7F10 {
    MotionResetZeroHandle() { value = 0; }
    ~MotionResetZeroHandle() {}
};

struct MotionResetHandle : MotionResetZeroHandle {
    MotionResetHandle() { value = 0; }
    ~MotionResetHandle() {}
};

template<class T> struct MotionResetArray {
    int count;
    int capacity;
    T* items;

    inline void storage(int size)
    {
        if (size) {
            if (items)
                items = (T*)fn_8028FAF4(lbl_8028F698, items,
                    capacity * sizeof(T), size * sizeof(T));
            else
                items = (T*)fn_8028FF24(lbl_8028F698, size * sizeof(T));
        } else if (items) {
            fn_8028FD50(lbl_8028F698, items, capacity * sizeof(T));
            items = 0;
        }
    }

    inline void resize(int size)
    {
        int i;
        if (size > count) {
            storage(size);
            capacity = size;
            for (i = count; i < size; ++i)
                new (&items[i]) T;
            count = size;
        } else if (size < count) {
            for (i = count - 1; i >= size; --i)
                items[i].~T();
            storage(size);
            capacity = size;
            count = size;
        }
    }
};

struct MotionResetTripleHandle : MotionResetHandle {
    MotionResetTripleHandle() { value = 0; }
    ~MotionResetTripleHandle() {}
};

struct MotionResetPoint {
    float x, y, z;
    MotionResetPoint& operator=(const MotionResetPoint& value)
    {
        x = value.x;
        y = value.y;
        z = value.z;
        return *this;
    }
};

extern "C" {
extern const MotionResetPoint game_vec3_zero;
extern const float lbl_8037B084;
}

static inline void assignMotionReset(Handle_801F7F10& destination,
    const Handle_801F7F10& value)
{
    fn_801F86C8(lbl_801E9D24.manager, &destination, -1);
    destination.value = value.value;
    fn_801F86C8(lbl_801E9D24.manager, &value, 1);
}

struct MotionOwnerReset : Activable_Z {
    char unknown1C[4];
    MotionResetHandle handle20;
    MotionResetWord unknown24;
    MotionResetTripleHandle handle28;
    MotionResetWord unknown2C;
    unsigned long long flags;
    MotionResetArray<MotionResetItem12> first;
    MotionResetArray<MotionResetItem16> second;
    MotionResetArray<MotionResetItem12> third;
    MotionResetArray<MotionResetHandle> fourth;
    MotionResetHandle handle68;
    MotionResetArray<MotionResetItem40> fifth;
    char unknown78[0x58];
    float valueD0;
    char unknownD4[0x70];
    MotionResetPoint movement, velocity;
};

extern "C" void slot18__12ObjectMove_ZFv(MotionOwnerReset* self)
{
    self->Activable_Z::slot18();
    self->movement = game_vec3_zero;
    self->velocity = game_vec3_zero;
    self->flags = 0xC000ULL;
    self->valueD0 = lbl_8037B084;
    assignMotionReset(self->handle20, MotionResetHandle());
    assignMotionReset(self->handle68, MotionResetHandle());
    assignMotionReset(self->handle28, MotionResetTripleHandle());
    fn_80213920(self, 1);
    self->first.resize(1);
    self->second.resize(1);
    self->third.resize(1);
    self->fourth.resize(1);
    self->fifth.resize(1);
}
