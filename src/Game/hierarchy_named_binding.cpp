// Recovered GSQE78 named-object binding command; original class names are unknown.
#include "hierarchy_named_binding_internal.h"
extern "C" signed char fn_80205F1C(signed char mode) {
    if(lbl_801E9D24.console->argc<4 || !lbl_801E9D24.console->arg2IsNumeric)return 0;
    CommandOwnedHandle found(fn_801B5054(lbl_801E9D24.manager,
        NameHash(lbl_801E9D24.console->arg1),NameType(NameHash(lbl_8037A918))));
    if(!fn_801F7EB8(&found))return 0;
    int number=(int)lbl_801E9D24.console->arg2Value;
    int index;
    if(number<1 || number>1 || !fn_801FEADC(lbl_801E9D24.groups,found,number,&index))return 0;
    if(mode) {
        if(lbl_801E9D24.console->argc==5) {
            Object* target=resolve(lbl_801E9D24.groups->entries.data[index]);
            fn_80200EEC(target,number,
                NameType(NameHash(lbl_801E9D24.console->arg3)),(int)lbl_801E9D24.console->arg4Value);
        } else {
            Object* target=resolve(lbl_801E9D24.groups->entries.data[index]);
            fn_80200EEC(target,number,
                NameType(NameHash(lbl_801E9D24.console->arg3)),0);
        }
    } else {
        if(lbl_801E9D24.console->argc==5) {
            Object* target=resolve(lbl_801E9D24.groups->entries.data[index]);
            fn_802017D8(target,number,
                NameType(NameHash(lbl_801E9D24.console->arg3)),(int)lbl_801E9D24.console->arg4Value);
        } else {
            Object* target=resolve(lbl_801E9D24.groups->entries.data[index]);
            fn_802017D8(target,number,
                NameType(NameHash(lbl_801E9D24.console->arg3)),0);
        }
    }
    return 1;
}
