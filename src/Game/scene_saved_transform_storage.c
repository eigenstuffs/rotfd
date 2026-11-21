/* Saved position and rotation used when switching the selected scene node. */
struct SavedScenePoint { float x, y, z; };
struct SavedSceneRotation { float x, y, z, w; };
struct SavedSceneRotation lbl_80306E14;
struct SavedScenePoint lbl_80306E08;

typedef char SavedScenePointSizeCheck[sizeof(struct SavedScenePoint) == 12 ? 1 : -1];
typedef char SavedSceneRotationSizeCheck[sizeof(struct SavedSceneRotation) == 16 ? 1 : -1];
