#ifndef GAME_LOGGER_INTERNAL_H
#define GAME_LOGGER_INTERNAL_H

/* Recovered game log buffer methods; names and layout are inferred. */
typedef unsigned long u32;
typedef struct Logger Logger;
typedef struct { char *text; u32 length; } LogLine;
struct LoggerStorage {
    char *buffer;
    char *last_line;
    int scroll;
    int line_count;
    int line_capacity;
    LogLine *lines;
    unsigned char reserved[0xB10-0x18];
};
struct Logger : LoggerStorage {
    virtual void unknown_0();
    virtual void unknown_1();
    virtual void unknown_2();
    virtual void unknown_3();
    virtual void unknown_4();
    virtual void unknown_5();
    virtual void unknown_6();
    virtual void unknown_7();
    virtual void refresh();
};
extern "C" {
typedef struct { char gpr,fpr,reserved[2]; char *input_arg_area,*reg_save_area; } va_list[1];
void __builtin_va_info(void *);
#define va_start(ap,fmt) ((void)fmt,__builtin_va_info(&ap))
#define va_end(ap) ((void)0)
extern struct { unsigned char reserved[0x104]; u32 flags; } lbl_801E9D24;
extern unsigned char lbl_8028F698[];
void *fn_8028FAF4(void *,void *,u32,u32);
void *fn_8028FF24(void *,u32);
void fn_8028FD50(void *,void *,u32);
void *memset(void *,int,u32);
void *memcpy(void *,const void *,u32);
u32 strlen(const char *);
char *strncpy(char *,const char *,u32);
char *strcat(char *,const char *);
int vsprintf(char *,const char *,va_list);
extern const char lbl_8037A838[];
}

#endif
