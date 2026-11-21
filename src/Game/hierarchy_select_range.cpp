#include "hierarchy_selection_ranges_internal.h"
extern "C" signed char fn_80204CC0() {
    if (lbl_801E9D24.console->argc != 2) return 0;
    if (!lbl_801E9D24.console->arg1IsNumeric) return 0;
    int selected = (int)lbl_801E9D24.console->arg1Value;
    for (int i=0; i<lbl_801E9D24.groups->entries.count; ++i) {
        if (fn_801F7EB8(&lbl_801E9D24.groups->entries.data[i])) {
            int offset = resolve(lbl_801E9D24.groups->entries.data[i])->getOffset();
            if (offset >= 0) {
                int end = offset + resolveRange(lbl_801E9D24.groups->entries.data[i])->getWidth();
                if (selected > offset && selected <= end) {
                    fn_801FEDA0(lbl_801E9D24.groups, i);
                    return 1;
                }
            }
        }
    }
    return 0;
}
