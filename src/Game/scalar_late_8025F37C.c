/* Original scalar operation with private observed layouts.
 * See docs/notes/game-scalar-late.md. */
struct TaggedEntry {int key;unsigned char value;char pad[3];};struct TaggedArray {char pad[16];int count;char pad14[4];struct TaggedEntry *entries;};

unsigned char fn_8025F37C(const struct TaggedArray *object,int needle) {int i;for(i=0;i<object->count;++i)if(object->entries[i].key==needle)return *((unsigned char *)object->entries+(i*8+4));return 0;}
