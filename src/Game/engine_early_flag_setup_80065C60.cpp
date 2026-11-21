/* Genuine native constructor; zero-credit refinement of accepted C entry.
 * See docs/notes/game-engine-native-factory-refinement.md. */
#include "Game/engine_native_factory_ctor_views.h"
extern "C" char lbl_802B7098[];
Object_80065C60::Object_80065C60(){vtable=lbl_802B7098;secondaryVtable=lbl_802B7098+0xB4;flags|=0x20000000000ULL;}
