// Recovered GSQE78 selection commands; original class and method names are unknown.
#include "hierarchy_selection_transform_internal.h"
extern "C" signed char fn_802047B8(int finalCommand,int thirdCommand,int secondCommand) {
    if (lbl_801E9D24.console->argc < 2) return 0;
    if (!lbl_801E9D24.console->arg1IsNumeric) return 0;
    int index=(int)lbl_801E9D24.console->arg1Value;
    if(index >= lbl_801E9D24.game->count)return 0;
    SelectionHandle5 first;
    SelectionHandle2 second;
    SelectionHandle3 target;
    fn_801FE6BC(lbl_801E9D24.groups,index,&first,&target,&second);
    if(!fn_801F7EB8(&target))return 0;
    if(lbl_801E9D24.console->argc>=3 && lbl_801E9D24.console->arg2IsNumeric)
        resolve(target.token)->command(secondCommand,lbl_801E9D24.console->arg2Value);
    if(lbl_801E9D24.console->argc>=4 && lbl_801E9D24.console->arg3IsNumeric)
        resolve(target.token)->command(thirdCommand,lbl_801E9D24.console->arg3Value);
    if(lbl_801E9D24.groups->flags[index]) {
        char command[128];
        sprintf(command,lbl_802AD984,index);
        fn_801FAB38(lbl_801E9D24.console,command);
    }
    resolve(target.token)->command(finalCommand,lbl_8037A928);
    return 1;
}
