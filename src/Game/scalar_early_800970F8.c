/* Original scalar operations with private observed layouts.
 * See docs/notes/game-scalar-early.md. */

static inline void add3(float *out,float x,float y,float z) {out[0]+=x;out[1]+=y;out[2]+=z;}

void accumulate_800970F8__15Object_800969F0FPCf(float *object,const float *source) {float scale=object[221];add3(object+0x358/4,source[0]*scale,source[1]*scale,source[2]*scale);}
