#include "Game/handle_array_clear_internal.h"

extern "C" void* memcpy(void*, const void*, unsigned long);
struct KeyEraseNative : Handle_801F7F10 {};
struct KeyEraseHandle : KeyEraseNative {};
struct KeyEraseArray {
    int count, capacity;
    KeyEraseHandle* data;
    KeyEraseHandle& operator[](int i) { return data[i]; }
    void erase(int i) {
        (*this)[i].~KeyEraseHandle();
        memcpy(&(*this)[i], &(*this)[i] + 1, (--count - i) * sizeof(KeyEraseHandle));
    }
};
struct KeyEraseView { char unknown00[12]; KeyEraseArray handles; };

extern "C" signed char fn_8026413C(KeyEraseView* self, const unsigned long* target)
{
    for (int i = 0; i < self->handles.count; ++i) {
        unsigned long key = *(unsigned long*)fn_801F7EB8(&self->handles[i]);
        unsigned long other = *target;
        if (key == other) {
            self->handles.erase(i);
            return 1;
        }
    }
    return 0;
}
