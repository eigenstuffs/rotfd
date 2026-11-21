/* Command parsing and conditional definitions, reconstructed from GSQE78.
 * Names and private layouts are inferred; the original class identity is unknown.
 * The original fixed-buffer and unmatched-quote behavior is preserved.
 */
typedef unsigned long u32;
struct Command {
    char name[64];
    char help[128];
    char alias[16];
    signed char (*callback)();
    Command *next;
};
struct CommandState {
    unsigned char prefix[0x54];
    Command *commands;                 /* 0x054 */
    unsigned char reserved[0x860-0x58];
    int argc;                          /* 0x860 */
    char *argv[16];
    signed char numeric[16];
    float values[16];
    int define_count;                  /* 0x8F4 */
    char defines[16][32];
    int depth;                         /* 0xAF8 */
    signed char active[20];
};
extern "C" {
u32 strlen(const char *);
char *strcpy(char *,const char *);
int strcmp(const char *,const char *);
double atof(const char *);
int fn_801F4520(const char *,const char *);
char *fn_801F459C(char *);
void fn_801FA014(void *,const char *,...);
void fn_801F9D68(void *,const char *,...);
extern const char lbl_8037A840[]="TRUE";
extern const char lbl_8037A848[]="On";
/* Addressable constant tables preserve the original pool order. */
extern const float lbl_8037A84C[1]={1.0f};
extern const char lbl_8037A850[]="FALSE";
extern const char lbl_8037A858[]="Off";
extern const float lbl_8037A85C[1]={0.0f};
extern const char lbl_8037A860[]="#define";
extern const char lbl_8037A868[]="#set";
extern const char lbl_8037A870[]="#unset";
extern const char lbl_8037A878[]="#if";
extern const char lbl_8037A87C[]="#ifnot";
extern const char lbl_8037A884[]="#else";
extern const char lbl_8037A88C[]="#endif";
extern const char lbl_8037A894[]="> %s";
extern const char lbl_8037A89C[]="\t%s";
extern const char lbl_802AD580[]="%s : Unknown command...";

static inline signed char parse_number(const char *text,float &value)
{
    signed char valid=1;
    u32 i=0;
    if(text[0]=='-') i=1;
    u32 dots=0;
    u32 length=strlen(text);
    if(text[length-1]=='f') --length;
    for(;i<length && valid;++i) {
        if(text[i]>='0' && text[i]<='9') valid=1;
        else if(text[i]=='.') {
            if(++dots>1) valid=0;
        } else valid=0;
    }
    if(valid) value=(float)atof(text);
    return valid;
}
static inline signed char is_defined(const CommandState *self,const char *text)
{
    for(int i=0;i<self->define_count;++i)
        if(!fn_801F4520(self->defines[i],text)) return 1;
    return 0;
}
static inline void unset_define(CommandState *self,const char *name)
{
    const char *text=name;
    for(int i=0;i<self->define_count;++i) {
        if(!fn_801F4520(self->defines[i],text)) {
            --self->define_count;
            for(;i<self->define_count;++i)
                strcpy(self->defines[i],self->defines[i+1]);
            break;
        }
    }
}
static inline void push_condition(CommandState *self,signed char value)
{
    if(self->depth && !self->active[self->depth-1]) value=0;
    self->active[self->depth++]=value;
}
static inline int token_count(const CommandState *state) { return state->argc; }
static inline int nesting(const CommandState *self) { return self->depth; }
int fn_801FA1F0(CommandState *self,const char *input)
{
    char tokens[16][128];
    char command_name[128];
    char alias[128];
    char lowercase[128];
    if(!strlen(input)) return 0;
    self->argc=0;
    int pos=0;
    while(input[pos]==' ' || input[pos]=='\t') ++pos;
    while(self->argc<16 && input[pos]) {
        int length=0;
        while(input[pos+length]!=' ' && input[pos+length]!=0 && input[pos+length]!='\t') {
            if(input[pos+length]=='"') {
                while(input[pos+length+1]!='"') {
                    tokens[self->argc][length]=input[pos+length+1];
                    ++length;
                }
                pos+=2;
            } else {
                tokens[self->argc][length]=input[pos+length];
                ++length;
            }
        }
        tokens[self->argc][length]=0;
        self->argv[self->argc]=tokens[self->argc];
        float value;
        if(parse_number(tokens[self->argc],value)) {
            self->numeric[self->argc]=1;
            self->values[self->argc]=value;
        } else self->numeric[self->argc]=0;
        if(!fn_801F4520(self->argv[self->argc],lbl_8037A840) || !fn_801F4520(self->argv[self->argc],lbl_8037A848)) {
            self->numeric[self->argc]=1;
            self->values[self->argc]=lbl_8037A84C[0];
        }
        if(!fn_801F4520(self->argv[self->argc],lbl_8037A850) || !fn_801F4520(self->argv[self->argc],lbl_8037A858)) {
            self->numeric[self->argc]=1;
            self->values[self->argc]=lbl_8037A85C[0];
        }
        pos+=length;
        while(input[pos]==' ' || input[pos]=='\t') ++pos;
        ++self->argc;
    }
    if(token_count(self)==0) return 0;
    if(!fn_801F4520(lbl_8037A860,tokens[0])) {
        --self->argc;
        for(int i=0;i<self->argc;++i) {
            strcpy(tokens[i],tokens[i+1]);
            self->values[i]=self->values[i+1];
            self->numeric[i]=self->numeric[i+1];
        }
    }
    if(self->argc>=2 && !fn_801F4520(lbl_8037A868,tokens[0])) {
        input=tokens[1];
        if(!is_defined(self,input)) {
            char *dest=self->defines[self->define_count++];
            strcpy(dest,input);
        }
        return 1;
    }
    if(self->argc>=2 && !fn_801F4520(lbl_8037A870,tokens[0])) {
        unset_define(self,tokens[1]);
        return 1;
    }
    if(self->argc>=2 && !fn_801F4520(lbl_8037A878,tokens[0])) {
        signed char value=is_defined(self,tokens[1]);
        push_condition(self,value);
        return 1;
    }
    if(self->argc>=2 && !fn_801F4520(lbl_8037A87C,tokens[0])) {
        signed char value=!is_defined(self,tokens[1]);
        push_condition(self,value);
        return 1;
    }
    if(!fn_801F4520(lbl_8037A884,tokens[0])) {
        if(self->depth<2 || self->active[self->depth-2]) self->active[nesting(self)-1]=!self->active[nesting(self)-1];
        return 1;
    }
    if(!fn_801F4520(lbl_8037A88C,tokens[0])) { --self->depth; return 1; }
    if(self->depth && !self->active[self->depth-1]) return 1;
    fn_801FA014(self,lbl_8037A894,input);
    strcpy(command_name,tokens[0]);
    strcpy(lowercase,command_name);
    fn_801F459C(lowercase);
    for(Command *command=self->commands;command;command=command->next) {
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
    fn_801F9D68(self,lbl_802AD580,command_name);
    return 0;
}
}
