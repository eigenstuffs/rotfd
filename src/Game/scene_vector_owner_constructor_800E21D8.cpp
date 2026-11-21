#include "Game/scene_vector_owner_800E2288.h"

Object_800E2288::Object_800E2288(SceneWord a, SceneWord b)
    : prefix(a, b),
      value((prefix.root.vtable = lbl_802C85D0, 0)),
      scale(lbl_80379788),
      phase(lbl_80379788),
      rate(lbl_80379788) {
    prefix.root.enabled = 1;
    value = prefix.first;
    rate = lbl_80379784;
}
