/* Release both node lists and report whether either list was nonempty.
 * The head value captures the first node before the two-list emptiness check.
 * Node storage and the pool release operation retain their existing owners.
 */
#include "Game/object_list_pool_internal.h"

struct ObjectListHead {
    ObjectListNode* pointer;
    ObjectListHead(ObjectListNode* node) : pointer(node) {}
    operator ObjectListNode*() const { return pointer; }
    ObjectListNode* get() const { return pointer; }
};

struct ObjectListClearGroup : ObjectListGroup {
    ObjectListHead first() const { ObjectListHead head(firstHead); return head; }
    ObjectListHead second() const { ObjectListHead head(secondHead); return head; }
};
typedef char CheckObjectListClearGroup[sizeof(ObjectListClearGroup)==0x28 ? 1 : -1];

extern "C" signed char fn_80285E10(ObjectListClearGroup* self) {
    signed char result;
    ObjectListNode* node;
    ObjectListNode* next;
    ObjectListHead first = self->first();
    node = first;
    result = first.get() || self->secondHead;
    while (node) {
        next = node->next;
        fn_80285CDC(objectListPool(), node);
        node = next;
    }
    self->firstHead = 0;
    self->firstTail = 0;
    node = self->second();
    while (node) {
        next = node->next;
        fn_80285CDC(objectListPool(), node);
        node = next;
    }
    self->secondHead = 0;
    self->secondTail = 0;
    return result;
}
