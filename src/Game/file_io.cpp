typedef unsigned long u32;
typedef signed long s32;
struct File;
struct HostGlobals { char unknown[0x188]; char *enabled; };
extern "C" {
extern HostGlobals lbl_801E9D24;
extern char lbl_801EF5C8[];
extern const char lbl_802AD4A0[],lbl_802AD4B0[];
int FIOFclose(int);
u32 FIOFread(int,void*,u32);
u32 FIOFseek(int,s32,u32);
int fclose(void *);
int fflush(void *);
u32 fwrite(const void*,u32,u32,void*);
u32 fread(void*,u32,u32,void*);
int fseek(void*,s32,int);
void *memset(void*,int,u32);
void *memcpy(void*,const void*,u32);
int DVDClose(File*);
void fn_801EF610(void*,void*);
void *fn_801EFA1C(void*,u32,const char*,const char*,int,int);
int atoi(const char*);
double atof(const char*);
}
struct File {
    unsigned char dvd[0x3C];
    u32 host;
    void *stream;
    char dvdOpen;
    char padding[3];
    char *buffer;
    u32 size;
    u32 position;
    u32 buffered;
    u32 extra;
};
extern "C" {
void fn_801F2A4C(const char *src,char *dst)
{
    int i=0;
    while(src[i]) {
        if(src[i]=='\\') dst[i]='/'; else dst[i]=src[i];
        ++i;
    }
    dst[i]=0;
}
void fn_801F2A98(File *f)
{
    if(f->host!=-1) {
        if(*lbl_801E9D24.enabled) FIOFclose(f->host);
        f->host=-1;f->dvdOpen=0;
    }
    if(f->stream) {fclose(f->stream);f->stream=0;f->dvdOpen=0;}
    if(f->dvdOpen) {DVDClose(f);f->dvdOpen=0;}
    if(f->buffer) {fn_801EF610(lbl_801EF5C8,f->buffer);f->size=0;f->buffer=0;}
}
void fn_801F2B58(File *f)
{
    if(f->buffered) {
        memset(f->buffer+f->buffered,0,0x18000-f->buffered);
        fwrite(f->buffer,1,(f->buffered+31)&~31,f->stream);
        f->buffered=0;
        fflush(f->stream);
    }
}
void fn_801F2BD4(File *f,const char *data,int size)
{
    if(size) {
        int available=0x18000-f->buffered;
        int remaining=size;
        int offset=0;
        while(remaining>0) {
            if(remaining<=available) {
                memcpy(f->buffer+f->buffered,data+offset,remaining);
                f->buffered+=remaining;
                remaining=0;
            } else {
                memcpy(f->buffer+f->buffered,data+offset,available);
                remaining-=available;
                offset+=available;
                fwrite(f->buffer,1,0x18000,f->stream);
                f->buffered=0;
                available=0x18000;
            }
        }
        f->size+=size;
    }
}
void fn_801F2CB4(File *f,void *dst,u32 size)
{
    if(size) {
        if(f->host!=-1) {
            void *temp=fn_801EFA1C(lbl_801EF5C8,size,lbl_802AD4A0,lbl_802AD4B0,0x1D4,32);
            FIOFread(f->host,temp,(size+31)&~31);
            memcpy(dst,temp,size);
            fn_801EF610(lbl_801EF5C8,temp);
        } else if(f->stream) {
            void *temp=fn_801EFA1C(lbl_801EF5C8,size,lbl_802AD4A0,lbl_802AD4B0,0x1DC,32);
            fread(temp,1,(size+31)&~31,f->stream);
            memcpy(dst,temp,size);
            fn_801EF610(lbl_801EF5C8,temp);
        } else memcpy(dst,f->buffer+f->position,size);
        f->position+=size;
    }
}
char fn_801F2E04(const File *f){return f->position>=f->size;}
u32 fn_801F2E28(const File *f){return f->size;}
#pragma dont_inline on
u32 fn_801F2E30(File *f,int offset,unsigned int origin)
{
    if(f->host!=-1) {
        int position=0;
        if(origin==1)position=offset;
        if(origin==0)position=offset+f->position;
        if(origin==2)position=f->size-offset;
        FIOFseek(f->host,position,0);
        f->position=position;
    } else if(f->stream) {
        int position=0;
        if(origin==1)position=offset;
        if(origin==0)position=offset+f->position;
        if(origin==2)position=f->size-offset;
        fseek(f->stream,position,0);
        f->position=position;
    } else {
        if(origin==1)f->position=offset;
        if(origin==0)f->position+=offset;
        if(origin==2)f->position=f->size-offset;
    }
    return f->position;
}
#pragma dont_inline reset
char fn_801F2F3C(File *f){return f->buffer[f->position++];}
}
static inline char skipWhitespace(File *f,u32 start)
{
    if(start>=f->size)return 0;
    while(f->buffer[f->position]==' ' || f->buffer[f->position]=='\r' || f->buffer[f->position]=='\t' || f->buffer[f->position]=='\n') {
        if(f->position>=f->size)return 0;
        ++f->position;
    }
    return 1;
}
static inline char skipWhitespace(File *f){return skipWhitespace(f,f->position);}
static inline char readWord(File *f,char *out)
{
    *out=0;
    if(!skipWhitespace(f))return 0;
    while(f->buffer[f->position]!=' ' && f->buffer[f->position]!='\t' && f->buffer[f->position]!='\r' && f->buffer[f->position]!='\n') {
        if(f->position>=f->size)break;
        *out++=f->buffer[f->position];
        ++f->position;
    }
    *out=0;
    return 1;
}
static inline char readNumber(File *f,char *out)
{
    if(!skipWhitespace(f))return 0;
    while(f->buffer[f->position]=='-' || f->buffer[f->position]=='.' || f->buffer[f->position]=='E' || f->buffer[f->position]=='+' || (f->buffer[f->position]>='0' && f->buffer[f->position]<='9')) {
        if(f->position>=f->size)break;
        *out++=f->buffer[f->position];
        ++f->position;
    }
    *out=0;
    return 1;
}
extern "C" {
char fn_801F2F54(File *f,char *out)
{
    int start=f->position;
    char success=skipWhitespace(f,start);
    if(fn_801F2F3C(f)=='"') {
        int length=0;
        char c=fn_801F2F3C(f);
        while(c!='"') {
            out[length++]=c;
            c=fn_801F2F3C(f);
        }
        out[length]=0;
    } else {
        fn_801F2E30(f,start,1);
        success=readWord(f,out);
    }
    return success;
}
char fn_801F3168(File *f,char *out,int *lines)
{
    if(lines)*lines=0;
    while(f->buffer[f->position]=='\r'||f->buffer[f->position]=='\n') {
        if(f->position>=f->size)return 0;
        if(lines && f->buffer[f->position]=='\n') ++*lines;
        ++f->position;
    }
    while(f->buffer[f->position]!='\r'&&f->buffer[f->position]!='\n') {
        if(f->position>=f->size)return 0;
        *out++=f->buffer[f->position];
        ++f->position;
    }
    *out=0;
    return 1;
}
char fn_801F3238(File *f,short *out)
{
    char buf[128];
    if(!readNumber(f,buf))return 0;
    *out=atoi(buf);
    return 1;
}
char fn_801F3374(File *f,int *out)
{
    char buf[128];
    if(!readNumber(f,buf))return 0;
    *out=atoi(buf);
    return 1;
}
char fn_801F34B0(File *f,long *out)
{
    char buf[128];
    if(!readNumber(f,buf))return 0;
    *out=atoi(buf);
    return 1;
}
char fn_801F35EC(File *f,float *out)
{
    char buf[128];
    if(!readNumber(f,buf))return 0;
    *out=(float)atof(buf);
    return 1;
}
char fn_801F372C(File *f,char *out){return readWord(f,out);}
}
