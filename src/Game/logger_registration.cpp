template<int N>struct StringBuffer {
    char text[N];
    operator char*(){return text;}
    operator const char*()const{return text;}
    char&operator[](int i){return text[i];}
};
/* Console command registration, reconstructed from GSQE78.
 * See docs/notes/game-console-commands.md. */
typedef unsigned long u32;
struct ConsoleCommand {
    char name[64],help[128];StringBuffer<16>alias;
    signed char (*callback)();
    ConsoleCommand *next,*prev;
    ConsoleCommand() { next=0; prev=0; callback=0; }
};
struct ConsoleCommands {
    unsigned char reserved[0x54];
    ConsoleCommand *commands;
    int history_cursor,history_count;
    char history[16][128];
};
extern "C" {
u32 strlen(const char *);
char *strcpy(char *,const char *);
char *strncpy(char *,const char *,u32);
int strcmp(const char *,const char *);
char *fn_801F459C(char *);
int fn_801FA1F0(void *,const char *);
void fn_801FA014(void *,const char *,...);
void fn_801F9D68(void *,const char *,...);
void *fn_801EFA1C(void *,int,const char *,const char *,int,int);
void fn_801EF610(void *,void *);
extern char lbl_801EF5C8[];
extern const char lbl_8037A89C[4];
extern const char lbl_802AD580[24];
extern const char lbl_802AD598[]="Anonymous New";
extern const char lbl_802AD5A8[]="ConsoleCommand_Z.cpp";
extern const char lbl_802AD5C0[];
extern const char lbl_802AD5D0[];
}
inline void *operator new(u32,void *memory) { return memory; }
extern "C" {

void fn_801FAC64(ConsoleCommands *self,const char *name,signed char (*callback)(),const char *help)
{
    ConsoleCommand *command=new(fn_801EFA1C(lbl_801EF5C8,sizeof(ConsoleCommand),lbl_802AD598,lbl_802AD5A8,22,4))ConsoleCommand;
    strcpy(command->name,name);
    strcpy(command->help,help);
    command->callback=callback;
    int count=0;
    int length=strlen(name);
    for(int i=0;i<length && count<15;++i) {
        if((name[i]>='A' && name[i]<='Z') || (name[i]>='0' && name[i]<='9'))
            command->alias[count++]=name[i];
    }
    command->alias[count]=0;
    for(ConsoleCommand *other=self->commands;other;other=other->next) {
        if(!strcmp(other->alias,command->alias)) {
            fn_801EF610(lbl_801EF5C8,command);
            return;
        }
    }
    command->next=self->commands;
    if(self->commands) self->commands->prev=command;
    self->commands=command;
}
}
