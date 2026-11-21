// Recovered GSQE78 three-component selection command.
#include "hierarchy_selection_transform_internal.h"
extern "C" signed char fn_80204AA8() {
    int index=0;
    if(lbl_801E9D24.console->argc==5) {
        if(!lbl_801E9D24.console->arg4IsNumeric)return 0;
        index=(int)lbl_801E9D24.console->arg4Value;
    } else if(lbl_801E9D24.console->argc!=4) return 0;
    if(!lbl_801E9D24.console->arg1IsNumeric && !lbl_801E9D24.console->arg2IsNumeric && !lbl_801E9D24.console->arg3IsNumeric)return 0;
    if(index>=lbl_801E9D24.game->count)return 0;
    SelectionHandle5 first;
    SelectionHandle2 second;
    SelectionHandle3 target;
    fn_801FE6BC(lbl_801E9D24.groups,index,&first,&target,&second);
    // Preserve the observed component read order before vector construction.
    float z=lbl_801E9D24.console->arg3Value;
    float y=lbl_801E9D24.console->arg2Value;
    float x=lbl_801E9D24.console->arg1Value;
    Vector3 value(x,y,z);
    if(!fn_801F7EB8(&first))return 0;
    resolve(first.token)->setVector(value);
    return 1;
}
