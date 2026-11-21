#ifndef GAME_SCENE_MESSAGE_RECORD_CONTROLS_H
#define GAME_SCENE_MESSAGE_RECORD_CONTROLS_H
struct SceneMessageRecord {unsigned long key;char text[256];};
struct SceneMessageRecords {char unknown00[12];SceneMessageRecord*entries;int count;char fallback[256];};
struct SceneMessageSetup {char unknown00[0x28];signed char ready;char unknown29[3];int type;int index;void*service;char unknown38[0x5B4];float position[3];float size[3];};
extern "C" {
extern const float lbl_80379520,lbl_80379524,lbl_80379528,lbl_8037952C,lbl_80379530,lbl_80379534;
void slot18__11Activable_ZFv(void*);void fn_80213920(void*,int);
}
#endif
