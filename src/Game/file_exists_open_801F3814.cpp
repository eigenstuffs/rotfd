/* Game file existence test (fn_801F3814) and open (fn_801F3918), GSQE78.
 * Continues src/Game/file_io.cpp (801F2A4C..801F3814) and precedes
 * src/Game/file_lifecycle.cpp; same File layout and compiler flags.
 * Both functions inline the slash-normalizing path copy and an 8.3-style
 * filename check whose result is discarded (the emptied "basename too long"
 * block leaves the original `bne; b` pair; the basename counter survives).
 * The check's counters are declared before `i` and zeroed after strlen.
 * The diagnostic pool lbl_802AD4A0..802AD4E0 ("Anonymous Alloc",
 * "File_Z.cpp", "DvdRoot//", "[Zouna] File size = %d\n") stays external;
 * the offset-0 string is reached through a member pointer to the +0x10
 * string minus 0x10 (extern string pool recipe). lbl_8037A730 is the 3-byte
 * fopen mode in .sdata2. lbl_80377FE8/lbl_80377FE9 are a function-local
 * static and its guard in .sbss, written as an explicit guard on the
 * existing labels (original compiler-generated guard has the same code). */
typedef unsigned long u32;
typedef signed long s32;
struct DVDCommandBlock { unsigned long words[12]; };
struct DVDFileInfo { DVDCommandBlock block; u32 start,length; void *callback; };
struct File {
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
};
struct FilePool {
    char allocName[0x10];
    char sourceName[0xC];
    char hostRoot[0xC];
    char sizeMessage[0x18];
};
struct HostConfig { char unknown[0xC8]; signed char hostDirect; };
struct HostGlobals { char unknown[0x118]; HostConfig *config; };
extern "C" {
extern HostGlobals lbl_801E9D24;
extern char lbl_801EF5C8[];
extern const FilePool lbl_802AD4A0;
extern const char lbl_8037A730[3];
extern signed char lbl_80377FE8;
extern signed char lbl_80377FE9;
u32 strlen(const char*);
char *strcpy(char*,const char*);
char *strcat(char*,const char*);
void *fopen(const char*,const char*);
int fseek(void*,s32,int);
long DVDConvertPathToEntrynum(const char*);
signed char DVDOpen(const char*,File*);
int DVDClose(File*);
void TTYPrintf(const char*,...);
void *fn_801EFA1C(void*,u32,const char*,const char*,int,int);
signed char fn_8028EEEC(File*,File*,void*,u32,int);
}
inline const char*sourceText(const FilePool*p){const char(FilePool::*m)[0xC]=&FilePool::sourceName;return p->*m;}
inline const char*allocText(const FilePool*p){return sourceText(p)-sizeof(p->allocName);}
static inline void convertPath(const char *src,char *dst)
{
    int i=0;
    while(src[i]) {
        if(src[i]=='\\') dst[i]='/'; else dst[i]=src[i];
        ++i;
    }
    dst[i]=0;
}
static inline bool validPath(const char *path)
{
    unsigned int extension;
    unsigned int basename;
    int i;
    i=strlen(path)-1;
    extension=0;
    basename=0;
    for(;i>0;--i) {
        ++extension;
        if(path[i]=='.') {
            if(extension>4)return 0;
            break;
        }
    }
    if(i-1>=0) {
        for(int j=i-1;j>0;--j) {
            ++basename;
            if(path[j]=='.'||path[j]=='/') {
                if(basename>8)return 0;
                break;
            }
        }
    }
    return 1;
}
extern "C" bool fn_801F3814(const char *filename)
{
    char path[128];
    convertPath(filename,path);
    validPath(path);
    return DVDConvertPathToEntrynum(path)>=0;
}
extern "C" bool fn_801F3918(File *f,const char *name,u32 flags)
{
    const FilePool*const pool=&lbl_802AD4A0;
    if(f->buffer)return 1;
    if(flags&4)return 0;
    if(!lbl_80377FE9) {lbl_80377FE8=0;lbl_80377FE9=1;}
    if(lbl_80377FE8)return 0;
    char path[128];
    char hostPath[1024];
    convertPath(name,path);
    validPath(path);
    if(flags&2) {
        const char *p=path;
        if(path[0]=='/')p=path+1;
        const char *open=p;
        if(!lbl_801E9D24.config->hostDirect) {
            strcpy(hostPath,pool->hostRoot);
            strcat(hostPath,p);
            open=hostPath;
        }
        f->stream=fopen(open,lbl_8037A730);
        if(!f->stream)return 0;
        f->buffer=(char*)fn_801EFA1C(lbl_801EF5C8,0x18000,allocText(pool),pool->sourceName,0x65,32);
        f->position=0;f->extra=0;f->buffered=0;f->size=0;
    } else if(flags&1) {
        if(!DVDOpen(path,f))return 0;
        f->dvdOpen=1;f->position=0;
        int size;
        if(f->stream) {
            size=fseek(f->stream,0,2);
            TTYPrintf(pool->sizeMessage,size);
            fseek(f->stream,0,0);
        } else size=f->dvd.length;
        if(flags&0x10) {f->size=size;return 1;}
        if(size) {
            u32 aligned=(size+31)&~31;
            f->size=size;
            f->buffer=(char*)fn_801EFA1C(lbl_801EF5C8,aligned+2,allocText(pool),pool->sourceName,0x9D,32);
            if(!fn_8028EEEC(f,f,f->buffer,aligned,0))size=0;
            f->buffer[size]='\n';
            f->buffer[size+1]=0;
        }
        DVDClose(f);
        f->dvdOpen=0;
        return size!=0;
    }
    return 1;
}
