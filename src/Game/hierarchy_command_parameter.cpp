// Reconstructed optional-parameter hierarchy command from GSQE78 instructions.
#include "hierarchy_commands_internal.h"
extern "C" signed char fn_80204000() {
    if (lbl_801E9D24.console->argc < 3)
        return 0;
    CommandOwnedHandle found(fn_801B5054(lbl_801E9D24.manager,
        NameHash(lbl_801E9D24.console->arg1), NameType(NameHash(lbl_8037A918))));
    if (!fn_801F7EB8(&found))
        return 0;
    int group = fn_801FE99C(lbl_801E9D24.groups, &found);
    if (group < 0)
        return 0;
    int selection = (int)lbl_801E9D24.console->arg2Value;
    if (lbl_801E9D24.console->argc == 4)
        fn_80206E9C(lbl_801E9D24.groups, group, selection - 1,
                   (int)lbl_801E9D24.console->arg3Value);
    else
        fn_80206E9C(lbl_801E9D24.groups, group, selection - 1, -1);
    return 1;
}
