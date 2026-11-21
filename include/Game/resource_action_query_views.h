#ifndef GAME_RESOURCE_ACTION_QUERY_VIEWS_H
#define GAME_RESOURCE_ACTION_QUERY_VIEWS_H

struct ActionHandle {
    union {
        unsigned long value;
        struct { signed int tag : 8; signed int index : 24; } bits;
    };
};

struct ActionEntry {
    char* object;
    char unknown04[8];
    signed char tag;
    char unknown0D[3];
};

struct ActionManager {
    int count, capacity;
    ActionEntry* entries;
};

struct ActionContext {
    char unknown00[0x118];
    ActionManager* manager;
    char unknown11C[0x38];
    struct ActionSpeaker* speaker;
};

extern "C" ActionContext lbl_801E9D24;

inline char* resolveAction(const ActionHandle& handle)
{
    ActionEntry* entry = &lbl_801E9D24.manager->entries[handle.bits.index];
    if (entry->tag == handle.bits.tag)
        return entry->object;
    return 0;
}

struct ActionResource {
    char unknown00[0x38];
    unsigned long long flags;
    char unknown40[0x18];
    ActionHandle handle;
    char unknown5C[0x19C];
    void* registration;
};

struct ActionPrefix {
    int unknown00;
};

struct ActionQuery : ActionPrefix {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual ActionResource* getResource();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual const ActionHandle* getHandle();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void ensureRegistration();
};


extern "C" {
extern ActionQuery* lbl_803776B8;
extern const float lbl_80378800, lbl_803787FC, lbl_803787D4, lbl_80378804;
void* fn_8007D074(void*);
void fn_8007622C(void*, float, float);
void fn_802073BC(void*, int, void*, float, float);
void fn_80024A5C(void*, void*);
}

struct ActionSpeakerPrefix {
    char unknown00[0x1C];
};

struct ActionSpeaker : ActionSpeakerPrefix {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void update(int, int, int);
};

struct ActionVector {
    float x, y, z;
    ActionVector(float a, float b, float c) : x(a), y(b), z(c) {}
};
struct ActionModel {
    char unknown00[0x30];
    ActionVector position;
};
struct ActionOwner {
    char unknown00[0x124];
    ActionModel* model;
    char unknown128[0x270];
    ActionVector target;
};

#endif
