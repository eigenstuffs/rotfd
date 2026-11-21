/* Original scalar operations with private observed layouts.
 * See docs/notes/game-scalar-early.md. */

struct Record {char pad[0x2a];unsigned char enabled;char tail[0x69];};

struct Object {char pad[0xf0];int selected;char padf4[0x38];float vector[3];struct Record *records;};

extern float game_vec3_zero[3];

void fn_800567F0(struct Object *object) {object->records[object->selected].enabled=1;object->vector[0]=game_vec3_zero[0];object->vector[1]=game_vec3_zero[1];object->vector[2]=game_vec3_zero[2];}
