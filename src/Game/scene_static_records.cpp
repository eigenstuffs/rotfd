#include "Game/scene_static_records.h"

// The existing array-startup entry initializes the selection records at runtime.
// The token loader clears and populates its independent 400-record array.
extern "C" {
SceneSelectionRecord lbl_802F4208[300];
SceneResourceTokenRecord lbl_802F9FC8[400];
}
