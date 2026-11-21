struct UnlinkHandle {
    union {
        unsigned long value;
        struct { signed int generation : 8; signed int index : 24; } bits;
    };
};
struct UnlinkObjectEntry { void* object; unsigned long unknown04, unknown08; signed char generation; char unknown0D[3]; };
struct UnlinkObjectManager { int count, capacity; UnlinkObjectEntry* entries; };
struct UnlinkCallbackNode { UnlinkHandle owner; int key; UnlinkCallbackNode* next; };
struct UnlinkCallbackOwner { char unknown00[0x1C]; UnlinkCallbackNode* head; };
extern "C" {
extern struct { char unknown00[0x118]; UnlinkObjectManager* manager; } lbl_801E9D24;
void fn_80285CDC(UnlinkCallbackOwner*, UnlinkCallbackNode*);
}
static inline void* resolveUnlinkHandle(const UnlinkHandle& handle)
{
    UnlinkObjectEntry* entry = &lbl_801E9D24.manager->entries[handle.bits.index];
    return entry->generation == handle.bits.generation ? entry->object : 0;
}
extern "C" void fn_802601C8(UnlinkCallbackOwner* self, void* owner, int key)
{
    UnlinkCallbackNode* previous = 0;
    UnlinkCallbackNode* node = self->head;
    while (node) {
        if (owner == resolveUnlinkHandle(node->owner) && (!key || key == node->key)) {
            if (previous)
                previous->next = node->next;
            else
                self->head = node->next;
            fn_80285CDC(self, node);
            if (previous)
                node = previous->next;
            else
                node = self->head;
        } else {
            previous = node;
            node = node->next;
        }
    }
}
