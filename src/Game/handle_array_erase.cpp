#include "Game/handle_array_clear_internal.h"

extern "C" void* memcpy(void*, const void*, unsigned long);

struct EraseHandle : Handle_801F7F10 {};
struct EraseHandles {
    int count, capacity;
    EraseHandle* data;
    EraseHandle& operator[](int i) { return data[i]; }
    void erase(int i) {
        (*this)[i].~EraseHandle();
        memcpy(&(*this)[i], &(*this)[i] + 1, (--count - i) * sizeof(EraseHandle));
    }
};
struct EraseView { char unknown00[0x34]; EraseHandles handles; };

extern "C" void fn_80260744(EraseView* self, const Handle* target) {
    for (int i = 0; i < self->handles.count; ++i) {
        if (equal(self->handles[i], *target)) {
            self->handles.erase(i);
            break;
        }
    }
}
