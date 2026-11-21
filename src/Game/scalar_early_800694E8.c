/* Original scalar operations with private observed layouts.
 * See docs/notes/game-scalar-early.md. */

struct TimedRecord {unsigned char enabled;char pad[3];float value;char tail[4];};

struct TimedRecords {char pad[0x88];struct TimedRecord records[1];};

void fn_800694E8(struct TimedRecords *object,short index,float value) {object->records[index].enabled=1;object->records[index].value=value;}

void fn_80069504(struct TimedRecords *object,short index,float value) {object->records[index].value+=value;}

extern void *lbl_803776BC;

void fn_80069520(struct TimedRecords *object,signed char enabled,short index) {lbl_803776BC=enabled==1?&object->records[index]:0;}
