/* Original scalar operations with private observed layouts.
 * See docs/notes/game-scalar-early.md. */

struct GlobalRecord {int key;char pad4[0x48];signed char enabled,previous,changed;char tail;};

extern struct GlobalRecord lbl_802F4208[300];

static inline struct GlobalRecord *find_record(int key) {int i;struct GlobalRecord *found=0;for(i=0;i<300;++i)if(key==lbl_802F4208[i].key){found=&lbl_802F4208[i];break;}return found;}

void fn_800B41A0(int key) {struct GlobalRecord *found=find_record(key);if(found){found->changed=1;found->enabled=1;}}

void fn_800B41F0(int key) {struct GlobalRecord *found=find_record(key);if(found){found->changed=0;}}
