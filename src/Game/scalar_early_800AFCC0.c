/* Original scalar operations with private observed layouts.
 * See docs/notes/game-scalar-early.md. */

struct GlobalRecord {int key;char pad4[0x48];signed char enabled,previous,changed;char tail;};

extern struct GlobalRecord lbl_802F4208[300];

void fn_800AFCC0(void) {int i;for(i=0;i<300;++i){lbl_802F4208[i].changed=0;lbl_802F4208[i].enabled=lbl_802F4208[i].previous;}}
