#ifndef GAME_PLATFORM_MOVIE_STORAGE_H
#define GAME_PLATFORM_MOVIE_STORAGE_H
#include "os/OSThread_abi.h"
typedef struct MovieSemaphore {
    s32 count;
    OSThreadQueue queue;
} MovieSemaphore;
typedef struct MovieBufferRecord {
    u32 word00;
    u32 end04;
    u32 word08, word0C;
    void* buffer10;
    void* end14;
    u32 word18, word1C, word20, word24;
    void* buffer28;
    void* end2C;
} MovieBufferRecord;
typedef struct MoviePlatformStorage {
    OSThread displayThread;
    u8 displayStack[0x2000];
    OSThread dmaThread;
    u8 dmaStack[0x2000];
    MovieSemaphore displayReady;
    MovieSemaphore displayAvailable;
    MovieSemaphore dmaReady;
    MovieSemaphore dmaAvailable;
    MovieBufferRecord records[2];
    u8 unknown46C0[0x40];
    u8 decoder4700[0x30];
} MoviePlatformStorage;
typedef char CheckMovieThread[sizeof(OSThread)==0x318?1:-1];
typedef char CheckMovieSemaphore[sizeof(MovieSemaphore)==12?1:-1];
typedef char CheckMovieBufferRecord[sizeof(MovieBufferRecord)==0x30?1:-1];
typedef char CheckMoviePlatformStorage[sizeof(MoviePlatformStorage)==0x4730?1:-1];

#define MOVIE_STORAGE_OFFSET(field) ((u32)&((MoviePlatformStorage*)0)->field)
typedef char CheckMovieOffset_displayThread[MOVIE_STORAGE_OFFSET(displayThread)==0x0?1:-1];
typedef char CheckMovieOffset_displayStack[MOVIE_STORAGE_OFFSET(displayStack)==0x318?1:-1];
typedef char CheckMovieOffset_dmaThread[MOVIE_STORAGE_OFFSET(dmaThread)==0x2318?1:-1];
typedef char CheckMovieOffset_dmaStack[MOVIE_STORAGE_OFFSET(dmaStack)==0x2630?1:-1];
typedef char CheckMovieOffset_displayReady[MOVIE_STORAGE_OFFSET(displayReady)==0x4630?1:-1];
typedef char CheckMovieOffset_displayAvailable[MOVIE_STORAGE_OFFSET(displayAvailable)==0x463C?1:-1];
typedef char CheckMovieOffset_dmaReady[MOVIE_STORAGE_OFFSET(dmaReady)==0x4648?1:-1];
typedef char CheckMovieOffset_dmaAvailable[MOVIE_STORAGE_OFFSET(dmaAvailable)==0x4654?1:-1];
typedef char CheckMovieOffset_records[MOVIE_STORAGE_OFFSET(records)==0x4660?1:-1];
typedef char CheckMovieOffset_unknown46C0[MOVIE_STORAGE_OFFSET(unknown46C0)==0x46C0?1:-1];
typedef char CheckMovieOffset_decoder4700[MOVIE_STORAGE_OFFSET(decoder4700)==0x4700?1:-1];
#undef MOVIE_STORAGE_OFFSET
#endif
