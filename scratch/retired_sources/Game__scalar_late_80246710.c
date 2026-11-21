/* Original scalar operations with private observed layouts.
 * See docs/notes/game-scalar-late.md. */


int fn_80246710(void *object,void *unused,float *out) {const float *source=*(const float **)((char *)object+0xb0);out[0]=source[0];out[1]=source[1];out[2]=source[2];out[3]=source[3];return 1;}
