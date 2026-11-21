#include "Game/handle_array_clear_internal.h"

extern "C" void* memcpy(void*, const void*, unsigned long);
struct ResolvedEraseNative : Handle_801F7F10 {};
struct ResolvedEraseHandle : ResolvedEraseNative {};
struct ResolvedEraseArray {
    int count, capacity;
    ResolvedEraseHandle* data;
    ResolvedEraseHandle& operator[](int i) { return data[i]; }
    void erase(int i) {
        (*this)[i].~ResolvedEraseHandle();
        memcpy(&(*this)[i], &(*this)[i] + 1, (--count - i) * sizeof(ResolvedEraseHandle));
    }
};

extern "C" void fn_80263524(ResolvedEraseArray* self, const Handle* target)
{
    for (int i = 0; i < self->count; ++i) {
        if (equal(*target, (*self)[i])) {
            self->erase(i);
            break;
        }
    }
}
