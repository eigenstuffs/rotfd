/* Original scalar operations with private observed layouts.
 * See docs/notes/game-scalar-early.md. */

struct Object {char pad[12];const float *target;char pad10[12];float scale;};

static inline void set3(float *out,float x,float y,float z) {out[0]=x;out[1]=y;out[2]=z;}

void fn_800AB440(float *out,const struct Object *object) {const float *v=object->target;set3(out,v[0x9c/4]*object->scale,v[0xa0/4]*object->scale,v[0xa4/4]*object->scale);}
