struct Record {char pad[16];unsigned int value;char tail[0x80];};

struct RecordObject {char pad[0xf0];int selected;char tail[0x44];struct Record *records;};

unsigned int fn_80055D90(const struct RecordObject *object) {return object->records[object->selected].value;}
