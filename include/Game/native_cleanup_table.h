#ifndef GAME_NATIVE_CLEANUP_TABLE_H
#define GAME_NATIVE_CLEANUP_TABLE_H
typedef void *(*NativeCleanupFunction)(void *, short);
typedef struct NativeCleanupTable {
    const void *rtti;
    int offset_to_top;
    NativeCleanupFunction cleanup;
} NativeCleanupTable;
extern NativeCleanupTable lbl_802EA8A0;
#endif
