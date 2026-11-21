/* Original engine setup and record routines with private observed layouts.
 * See docs/notes/game-scalar-middle-more.md. */

struct Array50 {char pad[80];};

struct Array8C {char pad[140];};

struct Arrays {char pad[12];int count50;char gap[4];struct Array50 *array50;int count8C;char gap2[4];struct Array8C *array8C;};

extern void fn_801AE1DC(void *);

extern void fn_801ADF18(void *);

void fn_801B3028(struct Arrays *object) {int i;for(i=0;i<object->count50;++i)fn_801AE1DC(&object->array50[i]);for(i=0;i<object->count8C;++i)fn_801ADF18(&object->array8C[i]);}

extern void fn_801AE21C(void *);

void fn_801B30B8(struct Arrays *object) {int i;for(i=0;i<object->count50;++i)fn_801AE21C(&object->array50[i]);}
