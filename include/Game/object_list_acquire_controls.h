#ifndef GAME_OBJECT_LIST_ACQUIRE_CONTROLS_H
#define GAME_OBJECT_LIST_ACQUIRE_CONTROLS_H

struct ObjectListPool;
struct ObjectListNode;
struct SceneListHandle_80260F08;

extern "C" {
ObjectListNode* fn_80285D34(ObjectListPool*);
SceneListHandle_80260F08* fn_80260F08(SceneListHandle_80260F08*, short);
}

#endif
