/* Console command history and semicolon splitting, reconstructed from GSQE78.
 * Layout matches src/Game/logger_commands_internal.h (ConsoleCommands).
 * fn_801FA1F0 parses and runs one command (src/Game/logger_parser.cpp).
 *
 * Register allocation note: the original reuses its two counters across the
 * function. `length` first holds the strcmp result, then walks the history,
 * then measures each command; `pos` first holds the history count, then the
 * command start. Those earlier live ranges are what make the parse loop's
 * zero initialisation come out as `li r26,0; mr r27,r26; mr r28,r26`. With
 * single-use counters every zero gets its own `li`.
 */
typedef unsigned long u32;
struct ConsoleCommands {
    unsigned char reserved[0x54];
    void *commands;
    int history_cursor,history_count;
    char history[16][128];
};
extern "C" {
char *strcpy(char *,const char *);
char *strncpy(char *,const char *,u32);
int strcmp(const char *,const char *);
int fn_801FA1F0(void *,const char *);
}

extern "C" int fn_801FAA0C(ConsoleCommands *self,const char *input)
{
    char part[128];
    int length,pos;
    length=strcmp(self->history[0],input);
    if(length) {
        length=self->history_count;
        char *dst=(char *)self+length*128;
        for(;length>0;dst-=128,--length)
            strcpy(dst+0x60,self->history[length-1]);
        strcpy(self->history[0],input);
        pos=self->history_count;
        if(pos<16) self->history_count=pos+1;
        self->history_cursor=-1;
    }
    pos=0;
    length=0;
    while(input[pos+length]) {
        if(input[pos+length]==';') {
            strncpy(part,input+pos,length);
            part[length]=0;
            fn_801FA1F0(self,part);
            pos+=length;
            length=0;
            ++pos;
        } else ++length;
    }
    if(length>0) {
        strncpy(part,input+pos,length);
        part[length]=0;
        return fn_801FA1F0(self,part);
    }
    return 1;
}
