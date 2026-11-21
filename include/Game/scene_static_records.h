#ifndef GAME_SCENE_STATIC_RECORDS_H
#define GAME_SCENE_STATIC_RECORDS_H

// Fields established by the record initializer, selection and snapshot routines.
struct SceneSelectionRecord {
    int key;
    int group;
    int unknown08;
    char text[64];
    signed char enabled;
    signed char previous;
    signed char changed;
    char unknown4F;
};

struct SceneResourceTokenRecord {
    char text[128];
    unsigned long flags;
};

typedef char SceneSelectionRecordSize[(sizeof(SceneSelectionRecord) == 80) ? 1 : -1];
typedef char SceneResourceTokenRecordSize[(sizeof(SceneResourceTokenRecord) == 132) ? 1 : -1];

extern "C" {
extern SceneSelectionRecord lbl_802F4208[300];
extern SceneResourceTokenRecord lbl_802F9FC8[400];
}

#endif
