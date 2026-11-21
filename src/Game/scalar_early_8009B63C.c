/* Original scalar operations with private observed layouts.
 * See docs/notes/game-scalar-early.md. */

extern const float lbl_80378D5C,lbl_80378D64;

static inline void add3(float *out,float x,float y,float z) {out[0]+=x;out[1]+=y;out[2]+=z;}

void fn_8009B63C(float *object) {add3(object+0x358/4,lbl_80378D5C,lbl_80378D64*object[0x354/4],lbl_80378D5C);}
