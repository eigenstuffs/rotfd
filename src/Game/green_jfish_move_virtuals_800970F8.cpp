/* Part of the original CGreenJfishMove source: slot1A0, with the vtable, RTTI
 * records and adjustor thunks that the compiler emits for the class (key
 * function: slot1A0).  See include/Game/move_classes.h. */
#include "Game/move_classes.h"

static inline void add3(float *out,float x,float y,float z) {out[0]+=x;out[1]+=y;out[2]+=z;}

void CGreenJfishMove::slot1A0(const float* source) {float* object=reinterpret_cast<float*>(this);float scale=object[221];add3(object+0x358/4,source[0]*scale,source[1]*scale,source[2]*scale);}

/* Objects of this unit ahead of the compiler RTTI data. */
extern "C" const char lbl_8029DF28[] = "GreenJfishMove.cpp";
extern "C" const float lbl_80378C90 = 1.0f;
