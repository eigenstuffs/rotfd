typedef unsigned long u32;
typedef signed long s32;
struct File_801F3E1C;
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
int DVDClose(File_801F3E1C*);
void fn_801EF610(void*,void*);
void *fn_801EFA1C(void*,u32,const char*,const char*,int,int);
int atoi(const char*);
double atof(const char*);
}
struct DVDCommandBlock { unsigned long words[12]; };
struct DVDFileInfo { DVDCommandBlock block; u32 start,length; void *callback; };
struct File_801F3E1C {
    DVDFileInfo dvd;
    u32 host;
    void *stream;
    char dvdOpen;
    char padding[3];
    char *buffer;
    u32 size;
    u32 position;
    u32 buffered;
    u32 extra;
    File_801F3E1C();
    ~File_801F3E1C();
    static void operator delete(void*f)throw(){fn_801EF610(lbl_801EF5C8,f);}
};
static inline void closeBacking(File_801F3E1C *f)
{
    if(f->host!=-1) {
        if(*lbl_801E9D24.enabled) FIOFclose(f->host);
        f->host=-1;f->dvdOpen=0;
    }
    if(f->stream) {fclose(f->stream);f->stream=0;f->dvdOpen=0;}
    if(f->dvdOpen) {DVDClose(f);f->dvdOpen=0;}
    if(f->buffer) {fn_801EF610(lbl_801EF5C8,f->buffer);f->size=0;f->buffer=0;}
}
extern "C" {
void fn_801F3C70(File_801F3E1C *f,u32 size)
{
    f->size=size;
    f->buffer=(char*)fn_801EFA1C(lbl_801EF5C8,f->size,lbl_802AD4A0,lbl_802AD4B0,0x2D,32);
    f->host=-1;f->stream=0;f->dvdOpen=0;
    f->position=0;f->buffered=0;f->extra=0;
}
File_801F3E1C *fn_801F3CE8(File_801F3E1C *f,const File_801F3E1C *src)
{
    f->dvd.block=src->dvd.block;
    f->dvd.start=src->dvd.start;f->dvd.length=src->dvd.length;f->dvd.callback=src->dvd.callback;
    f->host=src->host;f->stream=src->stream;
    f->buffer=src->buffer;f->size=src->size;f->position=src->position;
    f->buffered=src->buffered;f->extra=src->extra;f->dvdOpen=src->dvdOpen;
    if(f->size) {
        f->buffer=(char*)fn_801EFA1C(lbl_801EF5C8,f->size,lbl_802AD4A0,lbl_802AD4B0,0x25,32);
        memcpy(f->buffer,src->buffer,f->size);
    }
    return f;
}
}
File_801F3E1C::~File_801F3E1C()
{
    closeBacking(this);
}
File_801F3E1C::File_801F3E1C()
{
    File_801F3E1C *f=this;
    f->dvdOpen=-1;
    f->buffer=0;f->size=0;f->position=0;
    f->dvdOpen=0;f->host=-1;f->stream=0;
}
