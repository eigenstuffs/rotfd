#ifndef GAME_SCENE_LEAF_MORE_H
#define GAME_SCENE_LEAF_MORE_H
namespace SceneLeafMore {
typedef unsigned int Word;
struct InputRecord;
struct Records { int count; int capacity; InputRecord* data; };
struct ArrayOwner { char unknown00[0x20]; Records records; int index; };
struct ComponentOwner { char unknown00[0x168]; char component[4]; };
struct KeyOwner { char unknown00[0x188]; int key; };
struct Record { Word unknown00[2]; Word value08; Word unknown0C[3]; Word value18; Word unknown1C[2]; void setValue(Word value) { value08=value; } };
}
extern "C" {
int fn_800A5774(SceneLeafMore::Records*, const SceneLeafMore::InputRecord*);
void fn_800A6528(SceneLeafMore::ArrayOwner*);
void slot18__10CActorMoveFv(void*);
void slot34__10CActorMoveFv(void*);
void fn_8007D6A0(void*, int);
signed char slot1C__12BaseObject_ZFv(void*);
void fn_800B3FC8(SceneLeafMore::KeyOwner*);
void fn_8002AE88(void*);
void slot34__13Manipulator_ZFv(void*);
extern SceneLeafMore::Record lbl_80317F98[4];
extern int lbl_803777E0;
}
#endif
