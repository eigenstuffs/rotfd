/* Original scalar operations with private observed layouts.
 * See docs/notes/game-scalar-early.md. */

struct Subrecord {char pad[20];unsigned char *bytes14,*bytes18,*bytes1c;};

struct Record {char pad[44];struct Subrecord *sub;char tail[100];};

struct RecordObject {char pad[0xf0];int selected;unsigned int subindex;char padf8[32];int counter118,counter11c,counter120;char pad124[20];struct Record *records;};

unsigned char fn_80056570(struct RecordObject *object,int *out) {if(object->counter118>=250)return 0;*out=object->counter118;++object->counter118;return object->records[object->selected].sub[object->subindex].bytes14[*out];}
