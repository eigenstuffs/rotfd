#ifndef GAME_PLATFORM_RECORD_HANDLE_RELEASE_H
#define GAME_PLATFORM_RECORD_HANDLE_RELEASE_H

struct PlatformReleaseRecord {
    char unknown00[0x3C];
    unsigned long handle3C;
};
extern "C" void fn_8028BFA4(PlatformReleaseRecord*);

#endif
