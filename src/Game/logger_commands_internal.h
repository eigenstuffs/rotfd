/* Private observed console command layout; see docs/notes/game-console-commands.md. */
#ifndef GAME_LOGGER_COMMANDS_INTERNAL_H
#define GAME_LOGGER_COMMANDS_INTERNAL_H
typedef unsigned long u32;
struct ConsoleCommand {
    char name[64],help[128],alias[16];
    signed char (*callback)();
    ConsoleCommand *next,*prev;
};
struct ConsoleCommands {
    unsigned char reserved[0x54];
    ConsoleCommand *commands;
    int history_cursor,history_count;
    char history[16][128];
};
extern "C" {
char *strcpy(char *,const char *);
int strcmp(const char *,const char *);
char *fn_801F459C(char *);
void fn_801FA014(void *,const char *,...);
void fn_801F9D68(void *,const char *,...);
extern const char lbl_8037A89C[4];
extern const char lbl_802AD580[24];
}
#endif
