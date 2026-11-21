#include "Game/early_context_startup_views.h"

#include "Game/early_service_allocation_views_8007EE70.h"

inline void* operator new(unsigned long size, const char* file,
                          const char* function, int line, int alignment) {
    return fn_801EFA1C(lbl_801EF5C8, size, file, function, line, alignment);
}

extern "C" void fn_8007EE70() {
    // These addresses identify distinct, externally owned pooled strings.
    const unsigned long strings =
        reinterpret_cast<unsigned long>(game_type_registry_SpongeBob___RegisterGameClasses);
    fn_801FA014(lbl_801E9D24.logger,
               reinterpret_cast<const char*>(strings + 0x534));
    lbl_801E9D24.input = reinterpret_cast<StartupInput*>(
        new (reinterpret_cast<const char*>(strings + 0x2EC),
             reinterpret_cast<const char*>(strings + 0x550), 0xA8, 4)
            Object_800B5EC8);
    lbl_801E9D24.scene = reinterpret_cast<StartupScene*>(
        new (reinterpret_cast<const char*>(strings + 0x2EC),
             reinterpret_cast<const char*>(strings + 0x550), 0xA9, 4)
            Object_800B79A4);
    lbl_801E9D24.aux->enabled = 1;
    lbl_801E9D24.flags &= ~0x10;
}
