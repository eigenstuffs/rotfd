/* Genuine native constructor; zero-credit refinement of accepted C entry.
 * See docs/notes/game-engine-native-factory-refinement.md. */
#include "Game/engine_native_factory_ctor_views.h"
extern "C" {extern char lbl_802B14E0[];extern float game_vec3_zero[3];}
Object_8002AD98::Object_8002AD98(){vtable=lbl_802B14E0;field78=0;field7C=-1;vector80[0]=game_vec3_zero[0];vector80[1]=game_vec3_zero[1];vector80[2]=game_vec3_zero[2];field8C=0;field90=0;}
