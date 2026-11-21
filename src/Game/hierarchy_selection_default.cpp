#include "hierarchy_selection_actions_internal.h"
extern "C" signed char fn_802043FC() {
    int index = 0;
    if (lbl_801E9D24.console->argc == 2 && lbl_801E9D24.console->arg1IsNumeric)
        index = (int)lbl_801E9D24.console->arg1Value;
    SelectionHandle5 first;
    SelectionHandle2 second;
    SelectionHandle3 target;
    fn_801FE6BC(lbl_801E9D24.groups, index, &first, &target, &second);
    if (!fn_801F7EB8(&target))
        return 0;
    resolve(target.token)->slot12();
    return 1;
}
