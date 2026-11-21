/* Original scalar operations with private observed layouts.
 * See docs/notes/game-scalar-late.md. */
struct Node { char pad[8];struct Node *next; };struct Queue { char pad[32];struct Node *head,*tail;char pad28[24];int state; };

void fn_8025EA74(struct Queue *object,struct Node *node) { if(object->tail) object->tail->next=node; else object->head=node; object->tail=node;node->next=0;if(object->state!=2)object->state=3; }
