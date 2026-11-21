/* Original scalar operations with private observed layouts.
 * See docs/notes/game-scalar-early.md. */

void fn_80069AEC(void *object,unsigned char index,short value) {((int *)((char *)object+0x4c))[index]=value;}

struct SlotRecord {char pad[0x30];short stats[50];};

struct Slots {char pad[0xf0];int selected;char padf4[0x44];struct SlotRecord *records;char pad13c[12];short stats148[50],stats1ac[50];};

struct SlotRoot {char pad[0x15058];struct Slots *slots;};

extern struct {char pad[0x124];struct SlotRoot *root;} lbl_801E9D24;

static inline struct Slots *slots(void) {return lbl_801E9D24.root->slots;}

void fn_80069B00(void *object,unsigned char index,short value) {slots()->stats1ac[index]=value;}

void fn_80069B24(void *object,unsigned char index,short value) {struct Slots *s=slots();s->records[s->selected].stats[index]=value;}

void fn_80069B58(void *object,unsigned char index,short value) {slots()->stats148[index]=value;}
