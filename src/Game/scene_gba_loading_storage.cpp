/* GBA boot image, four channel records and loading-screen particle storage.
 * Existing loading and array-startup routines retain initialization ownership. */
#include "Game/scene_leaf_more_controls.h"

struct LoadingParticle {
    float first, second, third, fourth, fifth;
    unsigned char active;
    char unknown15[3];
};
typedef char LoadingParticleSize[(sizeof(LoadingParticle) == 24) ? 1 : -1];

extern "C" {
unsigned char lbl_80306E28[70000];
SceneLeafMore::Record lbl_80317F98[4];
LoadingParticle lbl_80318028[100];
}
