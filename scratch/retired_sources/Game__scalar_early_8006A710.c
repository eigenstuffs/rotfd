/* Original scalar operations with private observed layouts.
 * See docs/notes/game-scalar-early.md. */

struct Record {char pad[0x24];float value;char pad28[10];unsigned short flags;char tail[0x40];};

struct FourRecords {struct Record records[4];};

extern const float lbl_803787D4;

void fn_8006A710(struct FourRecords *object) {int i;for(i=0;i<4;++i){object->records[i].value=lbl_803787D4;object->records[i].flags&=0xffe9;}}
