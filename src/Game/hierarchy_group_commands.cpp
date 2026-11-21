// Recovered GSQE78 commands that act on the named object's group.
#include "hierarchy_commands_internal.h"
extern "C" {
void fn_801FEE10(Groups*,int);
void fn_801FEF6C(Groups*,int);
void fn_801FEC4C(Groups*,int,int);
signed char fn_802055A8() {
    if (lbl_801E9D24.console->argc != 2) return 0;
    CommandOwnedHandle found(fn_801B5054(lbl_801E9D24.manager,
        NameHash(lbl_801E9D24.console->arg1), NameType(NameHash(lbl_8037A918))));
    if (!fn_801F7EB8(&found)) return 0;
    int group=fn_801FE99C(lbl_801E9D24.groups,&found);
    if (group<0) return 0;
    fn_801FEE10(lbl_801E9D24.groups,group);
    return 1;
}
signed char fn_802056DC() {
    if (lbl_801E9D24.console->argc != 2) return 0;
    CommandOwnedHandle found(fn_801B5054(lbl_801E9D24.manager,
        NameHash(lbl_801E9D24.console->arg1), NameType(NameHash(lbl_8037A918))));
    if (!fn_801F7EB8(&found)) return 0;
    int group=fn_801FE99C(lbl_801E9D24.groups,&found);
    if (group<0) return 0;
    fn_801FEF6C(lbl_801E9D24.groups,group);
    return 1;
}
signed char fn_80205810() {
    if (lbl_801E9D24.console->argc != 3) return 0;
    CommandOwnedHandle found(fn_801B5054(lbl_801E9D24.manager,
        NameHash(lbl_801E9D24.console->arg1), NameType(NameHash(lbl_8037A918))));
    if (!fn_801F7EB8(&found)) return 0;
    int group=fn_801FE99C(lbl_801E9D24.groups,&found);
    if (group<0) return 0;
    fn_801FEC4C(lbl_801E9D24.groups,group,(int)lbl_801E9D24.console->arg2Value);
    return 1;
}
}
