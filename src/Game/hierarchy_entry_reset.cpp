#include "hierarchy_entry_reset_internal.h"

// Clear the existing entries before constructing the requested count.
extern "C" void fn_80207004(Hierarchy* self, int count) {
    self->entries.resize(0, 1);
    self->entries.resize(count, 0);
}
