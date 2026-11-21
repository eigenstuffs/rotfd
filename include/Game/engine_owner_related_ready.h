#ifndef GAME_ENGINE_OWNER_RELATED_READY_H
#define GAME_ENGINE_OWNER_RELATED_READY_H

typedef unsigned long RelatedReadyWord;
struct RelatedReadyHandle {
    signed int generation : 8;
    signed int index : 24;
};
struct RelatedReadyRootStorage {
    RelatedReadyWord unknown00;
    RelatedReadyHandle identity;
};
struct BaseObject_Z : RelatedReadyRootStorage {
    BaseObject_Z();
    virtual ~BaseObject_Z();
    virtual void slot0C(RelatedReadyWord);
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual signed char slot1C();
};
struct RelatedReadyOwner : BaseObject_Z {
    char unknown0C[4];
    RelatedReadyHandle first;
    char unknown14[4];
    RelatedReadyHandle next, primary, secondary;
    RelatedReadyHandle related24, related28, related2C;
    char unknown30[0x100];
    RelatedReadyHandle related130;
};
struct RelatedReadyEntry {
    BaseObject_Z* object;
    char unknown04[8];
    signed char generation;
    char unknown0D[3];
    signed char getGeneration() const { return generation; }
};
struct RelatedReadyManager {
    char unknown00[8];
    RelatedReadyEntry* entries;
};
extern "C" {
    extern struct {
        char unknown00[0x118];
        RelatedReadyManager* manager;
    } lbl_801E9D24;
    BaseObject_Z* fn_801F7EB8(const void*);
    signed char fn_80240FC4(RelatedReadyOwner*);
}
static inline BaseObject_Z* relatedReadyResolve(const RelatedReadyHandle& handle) {
    int index = handle.index;
    RelatedReadyManager* manager = lbl_801E9D24.manager;
    int generation = manager->entries[index].getGeneration();
    return generation == handle.generation ? manager->entries[index].object : 0;
}

typedef char RelatedReadyHandleSize[sizeof(RelatedReadyHandle) == 4 ? 1 : -1];
typedef char RelatedReadyEntrySize[sizeof(RelatedReadyEntry) == 16 ? 1 : -1];
typedef char RelatedReadyRootSize[sizeof(BaseObject_Z) == 12 ? 1 : -1];
typedef char RelatedReadyOwnerSize[sizeof(RelatedReadyOwner) == 0x134 ? 1 : -1];
#endif
