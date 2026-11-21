#include "hierarchy_selection_actions_internal.h"
extern "C" signed char fn_80204580() {
    if (lbl_801E9D24.console->argc != 2)
        return 0;
    if (!lbl_801E9D24.console->arg1IsNumeric)
        return 0;
    int index = (int)lbl_801E9D24.console->arg1Value;
    if (index >= lbl_801E9D24.game->count)
        return 0;
    SelectionHandle5 first;
    SelectionHandle2 second;
    SelectionHandle3 target;
    fn_801FE6BC(lbl_801E9D24.groups, index, &first, &target, &second);
    if (!fn_801F7EB8(&target))
        return 0;
    resolve(target.token)->command(70, lbl_8037A928);
    return 1;
}
