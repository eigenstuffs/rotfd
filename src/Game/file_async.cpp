/* Asynchronous DVD file wrapper, reconstructed from GSQE78. */
typedef unsigned long u32;
struct DVDFileInfo { char command[48]; int start,length; void *callback; };
struct AsyncFile {
    int entry;
    DVDFileInfo dvd;
    char name[128];
    int unknownC0,unknownC4;
    int sectors,chunk,position,state,error;
    char ready;
};
struct HostGlobals { char unknown[0x110]; void *logger; };
extern "C" {
extern HostGlobals lbl_801E9D24;
static const char async_error_message[]="IsToBeResolvedError: %d";
static const char async_empty_name[]="";
int DVDGetDriveStatus();
int DVDGetCommandBlockStatus(void*);
int DVDConvertPathToEntrynum(const char*);
int DVDFastOpen(int,DVDFileInfo*);
int DVDCancelAll();
int DVDClose(DVDFileInfo*);
int DVDReadAsyncPrio(DVDFileInfo*,void*,int,int,void*,int);
void fn_801F2A4C(const char*,char*);
int fn_8028F4B4();
void fn_801FA014(void*,const char*,...);
void fn_8028EF84(AsyncFile*);
char fn_8028EEEC(AsyncFile*,DVDFileInfo*,void*,u32,int);
char *strcpy(char*,const char*);
char *fn_801F459C(char*);
}
static inline int driveError(int status)
{
    if(status==4)return 2;
    if(status==5)return 4;
    if(status==6)return 3;
    return 1;
}
static inline void cancelFile(AsyncFile *f)
{
    DVDCancelAll();
    DVDClose(&f->dvd);
    f->entry=-1;
    f->ready=0;
}
static inline char recoverable(int error)
{
    return error==4 || error==5 || error==6 || error==11 || error==-1;
}
extern "C" {
char fn_801F3F30(AsyncFile *f)
{
    if(DVDGetDriveStatus()!=0)return 0;
    char path[128];
    fn_801F2A4C(f->name,path);
    int entry=DVDConvertPathToEntrynum(path);
    f->entry=entry;
    if(entry<0)f->ready=0;else f->ready=1;
    return f->ready;
}
int fn_801F3FA4(AsyncFile *f)
{
    int error;
    f->error=0;
    int status=DVDGetCommandBlockStatus(&f->dvd);
    if(status==1){f->state=0;return 0;}
    if(status==0){
        f->position+=f->chunk;
        if(f->position>=f->sectors){cancelFile(f);f->state=4;return 4;}
        f->state=1;return 1;
    }
    f->error=driveError(status);
    error=fn_8028F4B4();
    if(error)fn_801FA014(lbl_801E9D24.logger,async_error_message,error);
    if(recoverable(error)){
        fn_8028EF84(f);f->state=0;return 0;
    }
    f->state=6;return 6;
}
int fn_801F415C(AsyncFile *f,void *buffer,int count)
{
    f->error=0;
    int status=DVDGetDriveStatus();
    if(status!=0){cancelFile(f);f->error=driveError(status);f->state=6;return 6;}
    if(f->ready){DVDFastOpen(f->entry,&f->dvd);f->ready=0;}
    f->chunk=count;
    if(!DVDReadAsyncPrio(&f->dvd,buffer,count<<11,f->position<<11,0,2)){
        cancelFile(f);f->error=1;f->state=6;return 6;
    }
    f->state=5;return 5;
}
int fn_801F42A8(AsyncFile *f,void *buffer,int count)
{
    f->error=0;
    int status=DVDGetDriveStatus();
    if(status!=0){f->error=driveError(status);f->state=7;return 7;}
    if(f->ready){DVDFastOpen(f->entry,&f->dvd);f->ready=0;}
    if(!fn_8028EEEC(f,&f->dvd,buffer,count<<11,0)){
        cancelFile(f);f->error=1;f->state=7;return 7;
    }
    f->position+=count;f->state=5;return 5;
}
int fn_801F43D0(AsyncFile *f,const char *name)
{
    int byteSize;
    f->error=1;
    strcpy(f->name,name);
    fn_801F459C(f->name);
    char path[128];
    fn_801F2A4C(f->name,path);
    f->entry=DVDConvertPathToEntrynum(path);
    if(f->entry<0){f->state=7;return 7;}
    DVDFastOpen(f->entry,&f->dvd);
    byteSize=f->dvd.length;
    f->position=0;f->sectors=byteSize/2048;
    f->ready=0;f->state=5;return 5;
}
AsyncFile *fn_801F4474(AsyncFile *f)
{
    f->entry=-1;
    f->sectors=0;f->chunk=0;f->unknownC0=0;f->unknownC4=0;f->position=0;
    f->state=4;f->error=0;f->ready=0;
    strcpy(f->name,async_empty_name);
    return f;
}
}
