// Named-world group creation command.
#include "hierarchy_named_binding_internal.h"
extern "C" { void fn_801FF4F8(Groups*, const void*, const char*, int, signed char, const NameType&); extern const char lbl_802AD998[]; }
extern "C" signed char fn_802062F4(signed char shared) {
    if (lbl_801E9D24.console->argc < 3 || !lbl_801E9D24.console->arg2IsNumeric)
        return 0;
    CommandOwnedHandle found(fn_801B5054(lbl_801E9D24.manager,
        NameHash(lbl_801E9D24.console->arg1), NameType(NameHash(lbl_8037A918))));
    int number = (int)lbl_801E9D24.console->arg2Value;
    if (!fn_801F7EB8(&found)) return 0;
    if (number < 1 || number > 1 || number > 4) return 0;
    if (lbl_801E9D24.console->argc == 4)
        fn_801FF4F8(lbl_801E9D24.groups, &found, lbl_801E9D24.console->arg1,
            number, shared, NameType(NameHash(lbl_801E9D24.console->arg3)));
    else
        fn_801FF4F8(lbl_801E9D24.groups, &found, lbl_801E9D24.console->arg1,
            number, shared, NameType(NameHash(lbl_802AD998)));
    return 1;
}
