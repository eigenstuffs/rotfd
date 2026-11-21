/* Original scalar operations with private observed layouts.
 * See docs/notes/game-scalar-early.md. */

struct Countdown {char pad[4];unsigned char state;char pad5[3];float timer;char padc[2];unsigned char count;char padf;void *members[4];};

extern const float lbl_80378240,lbl_80378248;

void fn_80024A04(struct Countdown *object,const void *member) {((unsigned char *)object->members[*((signed char *)member+0x1ec)])[0x10]=0;--object->count;if(object->count<=3){if(lbl_80378240==object->timer)object->timer=lbl_80378248;object->state=4;}}
