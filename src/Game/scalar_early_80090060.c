/* Original scalar operations with private observed layouts.
 * See docs/notes/game-scalar-early.md. */

extern float lbl_802F4198[3],game_vec3_zero[3];

static inline void set3(float *out,float x,float y,float z) {out[0]=x;out[1]=y;out[2]=z;}

void fn_80090060(void) {set3(lbl_802F4198,game_vec3_zero[0],game_vec3_zero[1],game_vec3_zero[2]);}

__declspec(section ".ctors")
static void (*const scalar_global_init_reference)(void) = fn_80090060;

struct State {const void *vtable;unsigned char enabled;};

extern const char lbl_802B92D0[];

void fn_80090084(struct State *object) {object->vtable=lbl_802B92D0;object->enabled=0;}
