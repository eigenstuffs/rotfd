#include "hierarchy_selection_ranges_internal.h"
extern "C" signed char fn_80204E38() {
    if (lbl_801E9D24.console->argc != 2) return 0;
    int selected = (int)lbl_801E9D24.console->arg1Value;
    int index = fn_801FF834(lbl_801E9D24.groups, selected);
    SelectionRangeHandle entry(lbl_801E9D24.groups->entries.data[index]);
    int offset = entry.get()->getOffset();
    if (offset < 0) return 0;
    fn_802008C8(entry.getRange(), selected-offset);
    return 1;
}
