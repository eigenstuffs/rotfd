/* Original scalar operations with private observed layouts.
 * See docs/notes/game-scalar-early.md. */

struct SlotRecord {char pad[0x30];short stats[50];};

struct Slots {char pad[0xf0];int selected;char padf4[0x44];struct SlotRecord *records;char pad13c[12];short stats148[50],stats1ac[50];};

struct SlotRoot {char pad[0x15058];struct Slots *slots;};

extern struct {char pad[0x124];struct SlotRoot *root;} lbl_801E9D24;

static inline struct Slots *slots(void) {return lbl_801E9D24.root->slots;}

short fn_800661B8(void *object,short index) {return slots()->stats1ac[index];}

short fn_800661E0(void *object,short index) {struct Slots *s=slots();return s->records[s->selected].stats[index];}

short fn_80066218(void *object,short index) {return slots()->stats148[index];}
