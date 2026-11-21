#ifndef GAME_ANIMATION_NAME_LOOKUP_TABLE_H
#define GAME_ANIMATION_NAME_LOOKUP_TABLE_H

/* Animation-name lookup used by the actor stream reader. */
typedef struct AnimationNameLookupEntry {
    char name[32];
    int animation;
} AnimationNameLookupEntry;
#ifdef __cplusplus
extern "C" {
#endif
extern AnimationNameLookupEntry lbl_802BCFB8[33];
#ifdef __cplusplus
}
#endif
#endif
