#include "Game/animation_name_lookup_table.h"

AnimationNameLookupEntry lbl_802BCFB8[33] = {
    { "anim_wait01", 7 },
    { "anim_wait02", 8 },
    { "anim_wait03", 9 },
    { "anim_wait04", 10 },
    { "anim_wait05", 11 },
    { "anim_walk", 12 },
    { "anim_walk01", 13 },
    { "anim_walk02", 13 },
    { "anim_laugh", 77 },
    { "anim_laugh01", 78 },
    { "anim_laugh02", 79 },
    { "anim_talk_std", 80 },
    { "anim_talk_std01", 81 },
    { "anim_talk_std02", 82 },
    { "anim_talk_std03", 83 },
    { "anim_talk_std04", 84 },
    { "anim_talk_std05", 85 },
    { "anim_talk_std06", 86 },
    { "anim_talk_std07", 87 },
    { "anim_talk_std08", 88 },
    { "anim_talk_std09", 89 },
    { "anim_talk_std10", 90 },
    { "anim_misc", 153 },
    { "anim_misc01", 154 },
    { "anim_misc02", 155 },
    { "anim_misc03", 156 },
    { "anim_misc04", 157 },
    { "anim_misc05", 158 },
    { "anim_misc06", 159 },
    { "anim_misc07", 160 },
    { "anim_misc08", 161 },
    { "anim_misc09", 162 },
    { "anim_misc10", 163 }
};
typedef char AnimationNameLookupEntrySize[sizeof(AnimationNameLookupEntry) == 36 ? 1 : -1];

/* Former original data .data 0x802BD45C..0x802BD468, appended to the unit it follows (its section starts 8-aligned only together with this one). */
#pragma explicit_zero_data on
#pragma force_active on
extern char lbl_803753F0[];
__declspec(section ".data") void* lbl_802BD45C[3] = {
    (void*)lbl_803753F0,
    0,
    0,
};

#pragma force_active reset
