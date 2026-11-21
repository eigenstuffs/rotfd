/* Original scalar operations with private observed layouts.
 * See docs/notes/game-scalar-early.md. */

struct State {short index;char pad[2];void *pointer;float vector[3];};

extern float game_vec3_zero[3];

void fn_80072AF8(struct State *object) {object->index=-1;object->pointer=0;object->vector[0]=game_vec3_zero[0];object->vector[1]=game_vec3_zero[1];object->vector[2]=game_vec3_zero[2];}
