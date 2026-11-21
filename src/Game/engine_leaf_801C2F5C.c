/* Original indexed records, engine setup and allocation-header routines.
 * See docs/notes/game-engine-leaf.md. */

struct Record {char pad[0x40];char field[0x68];};

void *fn_801C2F5C(void *object,int index) {return &(*(struct Record **)((char *)object+0x188))[index].field;}
