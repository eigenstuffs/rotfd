/* Original scalar operations with private observed layouts.
 * See docs/notes/game-scalar-late.md. */
struct Item {char pad[28];struct Item *next;char pad20[8];unsigned short flags;};struct List {char pad[16];struct Item *head;};

void fn_8025ECB4(const struct List *object) { struct Item *item=object->head; while(item) { item->flags &= 0xfffb;item=item->next; } }
