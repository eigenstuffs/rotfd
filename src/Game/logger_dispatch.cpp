/* Direct console command dispatch, reconstructed from GSQE78. */
#include "logger_commands_internal.h"
extern "C" {
int fn_801FAB38(ConsoleCommands *self,const char *input)
{
    char lowercase[128];
    char alias[128];
    strcpy(lowercase,input);
    fn_801F459C(lowercase);
    for(ConsoleCommand *command=self->commands;command;command=command->next) {
        strcpy(alias,command->name);
        fn_801F459C(alias);
        if(!strcmp(alias,lowercase)) {
            if(!command->callback()) fn_801FA014(self,lbl_8037A89C,command->help);
            return 1;
        }
        strcpy(alias,command->alias);
        fn_801F459C(alias);
        if(!strcmp(alias,lowercase)) {
            if(!command->callback()) fn_801FA014(self,lbl_8037A89C,command->help);
            return 1;
        }
    }
    fn_801F9D68(self,lbl_802AD580,input);
    return 0;
}
}
