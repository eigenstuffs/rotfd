#ifndef GAME_ENGINE_MENU_TRANSITION_H
#define GAME_ENGINE_MENU_TRANSITION_H

typedef unsigned long MenuTransitionWord;
struct MenuTransitionHandle {
    union {
        MenuTransitionWord word;
        struct { signed int generation: 8, index: 24; } bits;
    };
};
struct MenuTransitionVector {
    float x, y, z;
    MenuTransitionVector() {}
    MenuTransitionVector(float a, float b, float c): x(a), y(b), z(c) {}
    MenuTransitionVector& operator=(const MenuTransitionVector& value) {
        x = value.x; y = value.y; z = value.z;
        return *this;
    }
    MenuTransitionVector operator+(const MenuTransitionVector& value) const {
        return MenuTransitionVector(x + value.x, y + value.y, z + value.z);
    }
};
struct MenuTransitionNode {
    char unknown00[0xC];
    MenuTransitionHandle parent;
    char unknown10[0xA8];
    MenuTransitionVector position;
    char unknownC4[0x14];
    MenuTransitionVector scale;
};
struct MenuTransitionEntry {
    MenuTransitionNode* object;
    char unknown04[8];
    signed char generation;
    char unknown0D[3];
    signed char getGeneration() const { return generation; }
};
struct MenuTransitionManager {
    int count, capacity;
    MenuTransitionEntry* entries;
};
struct MenuTransitionGlobals {
    char unknown00[0x118];
    MenuTransitionManager* manager;
};
struct MenuTransition {
    char unknown00[0x24];
    MenuTransitionHandle resource;
    char unknown28[0x24];
    MenuTransitionHandle current, target;
    float elapsed;
    unsigned char unknown58, active;
    char unknown5A[2];
    MenuTransitionVector velocity;
    float angularVelocity, speed;
};
extern "C" {
    extern MenuTransitionGlobals lbl_801E9D24;
    extern const float lbl_8037AF9C, lbl_8037AFA4, lbl_8037AFA8, lbl_8037AFAC;
    extern const float lbl_8037AFCC, lbl_8037AFB8, lbl_8037AFD0[2];
    extern const MenuTransitionVector game_vec3_zero;
    void fn_8023DE28(MenuTransitionNode*);
    float fn_8023BE00(MenuTransitionNode*, int);
    void fn_8023C31C(MenuTransitionNode*, int, float);
    void fn_801F86C8(MenuTransitionManager*, const void*, short);
    void fn_802073E8(MenuTransition*, int, MenuTransitionNode*, float);
    void fn_8021C030(MenuTransition*, float);
    void fn_8021C248(MenuTransition*, float);
}
static inline MenuTransitionNode* menuTransitionResolve(const MenuTransitionHandle& handle) {
    MenuTransitionEntry* entry = &lbl_801E9D24.manager->entries[handle.bits.index];
    return entry->generation == handle.bits.generation ? entry->object : 0;
}
static inline MenuTransitionNode* menuTransitionResolveBytes(const MenuTransitionHandle& handle) {
    struct ByteManager { int count, capacity; char* entries; };
    MenuTransitionEntry* entry = (MenuTransitionEntry*)
        (((ByteManager*)lbl_801E9D24.manager)->entries + handle.bits.index * 16);
    return entry->generation == handle.bits.generation ? entry->object : 0;
}
static inline MenuTransitionWord menuTransitionResolveMessage(const MenuTransitionHandle& handle) {
    int index = handle.bits.index;
    MenuTransitionManager* manager = lbl_801E9D24.manager;
    int generation = manager->entries[index].getGeneration();
    if (generation == handle.bits.generation) return (MenuTransitionWord)manager->entries[index].object;
    return 0;
}
static inline void menuTransitionAssign(MenuTransitionHandle& to, const MenuTransitionHandle& from) {
    fn_801F86C8(lbl_801E9D24.manager, &to, -1);
    to.word = from.word;
    fn_801F86C8(lbl_801E9D24.manager, &from, 1);
}

#endif
