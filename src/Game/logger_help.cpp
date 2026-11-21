/* Console command help output and empty hooks, reconstructed from GSQE78. */
#include "logger_commands_internal.h"
extern "C" {
extern const char lbl_802AD5C0[]="--------- HELP";
extern const char lbl_802AD5D0[]="  . %s (%s)\t%s";
void fn_801FAE54(ConsoleCommands *) {}
void fn_801FAE50(ConsoleCommands *) {}
void fn_801FADD0(ConsoleCommands *self)
{
    fn_801FA014(self,lbl_802AD5C0);
    for(ConsoleCommand *command=self->commands;command;command=command->next)
        fn_801FA014(self,lbl_802AD5D0,command->name,command->alias,command->help);
}
}
