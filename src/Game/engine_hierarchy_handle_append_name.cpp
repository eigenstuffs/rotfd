#include "Game/engine_hierarchy_handle_append.h"

extern "C" HierarchyCreatedHandle fn_80260BA4(HierarchyCreateOwner* self, const char* name) {
    return fn_80260868(self, HierarchyCreateName(name), 0);
}
