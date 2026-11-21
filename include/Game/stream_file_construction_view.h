#ifndef GAME_STREAM_FILE_CONSTRUCTION_VIEW_H
#define GAME_STREAM_FILE_CONSTRUCTION_VIEW_H

/* AsyncFile is the existing file_async.cpp storage type, repeated unchanged. */
struct DVDFileInfo { char command[48]; int start,length; void *callback; };
struct AsyncFile {
    int entry;
    DVDFileInfo dvd;
    char name[128];
    int unknownC0,unknownC4;
    int sectors,chunk,position,state,error;
    char ready;
};
extern "C" {
AsyncFile *fn_801F4474(AsyncFile *);
void __ct__13Manipulator_ZFv(void *);
extern char lbl_802EA080[];
}

struct StreamFileBaseStorage_801C9210 {
    unsigned long unknown00[2];
    void *table;
    char unknown0C[0x14];
    StreamFileBaseStorage_801C9210() {
        __ct__13Manipulator_ZFv(this);
        table = lbl_802EA080;
    }
};
/* This member's observed destruction has no file operation. Its empty cleanup
 * retains the file state lifetime across later member construction. */
struct StreamFileAsyncState_801C9210 {
    AsyncFile file;
    char unknownE0[0x10];
    int fieldF0;
    char unknownF4[4];
    int fieldF8;
    char unknownFC[8];
    StreamFileAsyncState_801C9210() { fn_801F4474(&file); }
    ~StreamFileAsyncState_801C9210() {}
};
struct Handle_801F7F10 {
    unsigned long value;
    Handle_801F7F10();
    ~Handle_801F7F10();
};
struct StreamFileZeroHandle_801C9210 : Handle_801F7F10 {
    StreamFileZeroHandle_801C9210() { value=0; }
};
struct StreamFileTwoZeroHandle_801C9210 : StreamFileZeroHandle_801C9210 {
    StreamFileTwoZeroHandle_801C9210() { value=0; }
};
/* Bounded construction view: the existing original vtable and C destructor
 * remain separately owned; no virtual declaration or table is synthesized. */
struct StreamFileInit_801C9210 : StreamFileBaseStorage_801C9210 {
    StreamFileAsyncState_801C9210 async;
    StreamFileTwoZeroHandle_801C9210 handle;
    char unknown128[8];
    unsigned char flag130,flag131,flag132,flag133;
    int field134;
    char unknown138[4];
    StreamFileInit_801C9210();
};
typedef char StreamFileAsyncSize[(sizeof(AsyncFile)==0xE0)?1:-1];
typedef char StreamFileAsyncStateSize[(sizeof(StreamFileAsyncState_801C9210)==0x104)?1:-1];
typedef char StreamFileInitSize[(sizeof(StreamFileInit_801C9210)==0x13C)?1:-1];
#endif
