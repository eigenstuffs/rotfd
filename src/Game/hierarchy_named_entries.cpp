// Recovered GSQE78 named-object group and entry commands.
// Definition order accounts for MW deferred emission; retained functions link in address order.
#include "hierarchy_named_entries_internal.h"
extern "C" signed char fn_80205D98() {
    if(lbl_801E9D24.console->argc!=3)return 0;
    int number=(int)lbl_801E9D24.console->arg2Value;
    int index;
    if(!fn_801FEADC(lbl_801E9D24.groups,CommandOwnedHandle(fn_801B5054(lbl_801E9D24.manager,
        NameHash(lbl_801E9D24.console->arg1),NameType(NameHash(lbl_8037A918)))),number,&index)) return 0;
    fn_80200CBC(resolve(lbl_801E9D24.groups->entries.data[index]),number-1,1);
    return 1;
}
extern "C" signed char fn_80205C18() {
    if(lbl_801E9D24.console->argc!=3)return 0;
    int number=(int)lbl_801E9D24.console->arg2Value;
    int index;
    if(!fn_801FEADC(lbl_801E9D24.groups,CommandOwnedHandle(fn_801B5054(lbl_801E9D24.manager,
        NameHash(lbl_801E9D24.console->arg1),NameType(NameHash(lbl_8037A918)))),number,&index)) return 0;
    fn_80201B14(resolve(lbl_801E9D24.groups->entries.data[index]),number-1);
    return 1;
}
extern "C" signed char fn_80205A98() {
    if(lbl_801E9D24.console->argc!=3)return 0;
    int number=(int)lbl_801E9D24.console->arg2Value;
    int index;
    if(!fn_801FEADC(lbl_801E9D24.groups,CommandOwnedHandle(fn_801B5054(lbl_801E9D24.manager,
        NameHash(lbl_801E9D24.console->arg1),NameType(NameHash(lbl_8037A918)))),number,&index)) return 0;
    fn_80201A14(resolve(lbl_801E9D24.groups->entries.data[index]),number-1);
    return 1;
}
extern "C" signed char fn_80205964() {
    if (lbl_801E9D24.console->argc != 2) return 0;
    CommandOwnedHandle found(fn_801B5054(lbl_801E9D24.manager,
        NameHash(lbl_801E9D24.console->arg1), NameType(NameHash(lbl_8037A918))));
    if (!fn_801F7EB8(&found)) return 0;
    int group=fn_801FE99C(lbl_801E9D24.groups,&found);
    if (group<0) return 0;
    fn_801FED04(lbl_801E9D24.groups,group);
    return 1;
}
