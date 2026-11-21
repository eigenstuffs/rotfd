/* Recovered variadic log append methods; see docs/notes/game-logger.md. */
#include "logger_internal.h"

extern "C" {
static inline void set_length(LogLine *entry,const char *text)
{
    entry->length=strlen(text);
}
const char lbl_8037A838[]="\r\n";

static inline void shift_lines(Logger *self,long removed)
{
    removed+=2;
    for(int i=0;i<self->line_count;) {
        LogLine *entry=&self->lines[i];
        if(entry->text-removed<self->buffer) {
            memcpy(entry,entry+1,(--self->line_count-i)*sizeof(LogLine));
        } else {
            self->lines[i++].text-=removed;
        }
    }
}

static inline int drop_text(Logger *self)
{
    int removed=0;
    while(self->buffer[removed]!='\r') ++removed;
    int left=strlen(self->buffer)-(removed+2);
    strncpy(self->buffer,self->buffer+(removed+2),left);
    self->buffer[left]=0;
    return removed;
}

void fn_801FA014(Logger *self,const char *format,...)
{
    char text[1024];
    va_list args;
    if(self->buffer && !(lbl_801E9D24.flags & 0x40)) {
        va_start(args,format);
        vsprintf(text,format,args);
        while(strlen(self->buffer)+strlen(text)+4>0x6000) {
            int removed=drop_text(self);
            shift_lines(self,removed);
        }
        self->last_line=self->buffer+strlen(self->buffer);
        strcat(self->buffer,text);
        strcat(self->buffer,lbl_8037A838);
        self->refresh();
        va_end(args);
    }
}
void fn_801F9D68(Logger *self,const char *format,...)
{
    char text[1024];
    va_list args;
    if(self->buffer && !(lbl_801E9D24.flags & 0x40)) {
        va_start(args,format);
        vsprintf(text,format,args);
        while(strlen(self->buffer)+strlen(text)+4>0x6000) {
            int removed=drop_text(self);
            shift_lines(self,removed);
        }
        if(self->line_count+1>self->line_capacity) {
            int new_capacity=self->line_capacity+16;
            if(new_capacity) {
                if(self->lines) self->lines=(LogLine *)fn_8028FAF4(lbl_8028F698,self->lines,self->line_capacity*sizeof(LogLine),new_capacity*sizeof(LogLine));
                else self->lines=(LogLine *)fn_8028FF24(lbl_8028F698,new_capacity*sizeof(LogLine));
            } else if(self->lines) {
                fn_8028FD50(lbl_8028F698,self->lines,self->line_capacity*sizeof(LogLine));
                self->lines=0;
            }
            self->line_capacity+=16;
        }
        ++self->line_count;
        int index=self->line_count-1;
        LogLine *entry=&self->lines[index];
        entry->text=self->buffer+strlen(self->buffer);
        set_length(&self->lines[index],text);
        self->last_line=self->buffer+strlen(self->buffer);
        strcat(self->buffer,text);
        strcat(self->buffer,lbl_8037A838);
        self->refresh();
        va_end(args);
    }
}


}
