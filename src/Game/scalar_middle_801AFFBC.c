/* Original scalar operations with private observed layouts.
 * See docs/notes/game-scalar-middle.md. */
static inline void set3(float *out,float x,float y,float z) {out[0]=x;out[1]=y;out[2]=z;}

void fn_801AFFBC(float *out,const float *source,float scale) {set3(out,source[0]*scale,source[1]*scale,source[2]*scale);}
