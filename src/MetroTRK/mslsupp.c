#include "msghndlr_abi.h"
#include "../MSL/stdio_internal.h"

extern u8 GetUseSerialIO(void);
extern int GetTRKConnected(void);
extern u32 TRKAccessFile(u32, u32, u32*, u8*);
extern u32 TRKOpenFile(u32, const char*, u8, u32*);
extern u32 TRKCloseFile(u32, u32);
extern u32 TRKPositionFile(u32, u32, u32, u8);
static inline int __access_file(__file_handle, u8*, size_t*, __idle_proc, MessageCommandID);
static unsigned int convertFileMode(const file_modes*);

enum { kDSIONoError = 0, kDSIOError = 1, kDSIOEOF = 2 };

int __read_console(__file_handle file, u8* buffer, size_t* count, __idle_proc idle)
{
    if (GetUseSerialIO() == 0) return __io_error;
    return __read_file(0, buffer, count, idle);
}

int __TRK_write_console(__file_handle file, u8* buffer, size_t* count, __idle_proc idle)
{
    if (GetUseSerialIO() == 0) return __io_error;
    return __write_file(1, buffer, count, idle);
}

int __close_console(__file_handle file)
{
    return __close_file(file);
}

int __read_file(__file_handle file, u8* buffer, size_t* count, __idle_proc idle)
{
    return __access_file(file, buffer, count, idle, kDSReadFile);
}

int __write_file(__file_handle file, u8* buffer, size_t* count, __idle_proc idle)
{
    return __access_file(file, buffer, count, idle, kDSWriteFile);
}

int __open_file(const char* name, const file_modes* modes, __file_handle* handle)
{
    u32 result;
    if (GetTRKConnected() == 0) return __io_error;
    result = convertFileMode(modes);
    result = TRKOpenFile(kDSOpenFile, name, (u8)result, handle);
    switch ((u8)result) {
    case kDSIONoError: return __no_io_error;
    case kDSIOEOF: return __io_EOF;
    }
    return __io_error;
}

int __close_file(__file_handle file)
{
    u32 result;
    if (GetTRKConnected() == 0) return __io_error;
    result = TRKCloseFile(kDSCloseFile, file);
    switch ((u8)result) {
    case kDSIONoError: return __no_io_error;
    case kDSIOEOF: return __io_EOF;
    }
    return __io_error;
}

int __position_file(__file_handle file, fpos_t* position, int mode, __idle_proc idle)
{
    u32 origin = 0;
    u32 result;
    if (GetTRKConnected() == 0) return __io_error;
    if (mode == SEEK_SET) origin = 0;
    else if (mode == SEEK_CUR) origin = 1;
    else if (mode == SEEK_END) origin = 2;
    result = TRKPositionFile(kDSPositionFile, file, *position, (u8)origin);
    switch ((u8)result) {
    case kDSIONoError: return __no_io_error;
    case kDSIOEOF: return __io_EOF;
    }
    return __io_error;
}

#pragma dont_inline on
static unsigned int convertFileMode(const file_modes* modes)
{
    unsigned int result = 0;
    int openMode = modes->open_mode;
    int ioMode = modes->io_mode;
    u32 binary = modes->binary_io;
    switch (openMode) {
    case 0: result |= 1; break;
    case 2: result |= 2; break;
    case 1: result |= 4; break;
    }
    switch (ioMode) {
    case 1: result |= 1; break;
    case 2: result |= 2; break;
    case 6: result |= 4; break;
    case 3: result |= 0x12; break;
    case 7: result |= 7; break;
    }
    if (binary == 1) result = (result | 8) & 0xFF;
    return result;
}
#pragma dont_inline reset

static inline int __access_file(__file_handle file, u8* buffer, size_t* count,
                               __idle_proc idle, MessageCommandID command)
{
    size_t countTemp;
    u32 result;
    if (GetTRKConnected() == 0) return __io_error;
    countTemp = *count;
    result = TRKAccessFile(command, file, &countTemp, buffer);
    *count = countTemp;
    switch ((u8)result) {
    case kDSIONoError: return __no_io_error;
    case kDSIOEOF: return __io_EOF;
    }
    return __io_error;
}
