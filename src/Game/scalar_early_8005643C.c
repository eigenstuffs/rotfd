/* Original scalar operations with private observed layouts.
 * See docs/notes/game-scalar-early.md. */

struct Subrecord {char pad[20];unsigned char *bytes14,*bytes18,*bytes1c;};

struct Record {char pad[44];struct Subrecord *sub;char tail[100];};

struct RecordObject {char pad[0xf0];int selected;unsigned int subindex;char padf8[32];int counter118,counter11c,counter120;char pad124[20];struct Record *records;};

unsigned char fn_8005643C(struct RecordObject *object,int *out) {if(object->counter11c>=100)return 0;*out=object->counter11c;++object->counter11c;return object->records[object->selected].sub[object->subindex].bytes18[*out];}
