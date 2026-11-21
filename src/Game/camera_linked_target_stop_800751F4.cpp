// Stop the target reached through the controlled camera actor's owner chain.
struct CameraIndex {
    int value;
    CameraIndex(int v) : value(v) {}
    operator const int&() const { return value; }
};

struct CameraHandle {
    union {
        unsigned long value;
        struct { signed int tag : 8; signed int index : 24; } bits;
    };
};
struct CameraEntry {
    void* object;
    char unknown04[8];
    signed char tag;
    char unknown0D[3];
    bool matchesTag(signed char expected) const { return tag == expected; }
};
struct CameraManager { int count, capacity; CameraEntry* entries; };
struct CameraContext { char unknown00[0x118]; CameraManager* manager; };
extern "C" CameraContext lbl_801E9D24;

// The ordinary lookup keeps its index value and generation as separate inputs.
template<class T> inline T* resolveCamera(const CameraHandle& handle) {
    CameraManager* manager = lbl_801E9D24.manager;
    CameraIndex index(handle.bits.index);
    signed char generation = handle.bits.tag;
    if (manager->entries[index].matchesTag(generation))
        return static_cast<T*>(manager->entries[index].object);
    return 0;
}

// Resource lookup takes a typed entry snapshot before testing its generation.
template<class T> inline T* resolveCameraResource(const CameraHandle& handle) {
    CameraEntry* entry = lbl_801E9D24.manager->entries + handle.bits.index;
    if (entry->tag == handle.bits.tag)
        return static_cast<T*>(entry->object);
    return 0;
}

struct CameraObjectPrefix { char unknown00[8]; };
struct CameraObject : CameraObjectPrefix {
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1C();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2C();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3C();
    virtual void slot40();
    virtual void slot44(int);
    char unknown0C[0x4C];
    CameraHandle owner;
};
struct CameraResource { char unknown00[0x10]; CameraHandle child; };
struct CameraChild { char unknown00[0x20]; CameraHandle target; };
struct CameraWrapperNode { char unknown00[0x24]; CameraHandle agent; };
struct CameraWrapper { char unknown00[8]; CameraWrapperNode* node; };

extern "C" {
    int fn_8025E9FC(CameraObject*, int);
    void fn_8025795C(CameraObject*, int, void*);
    void* fn_801F7EB8(CameraHandle*);
}

extern "C" void fn_800751F4(CameraWrapper* self) {
    CameraObject* node = resolveCamera<CameraObject>(self->node->agent);
    if (static_cast<signed char>(fn_8025E9FC(node, 0x8D))) {
        fn_8025795C(node, 0x82, 0);
        if (fn_801F7EB8(&resolveCameraResource<CameraResource>(node->owner)->child))
            resolveCamera<CameraObject>(
                resolveCamera<CameraChild>(
                    resolveCameraResource<CameraResource>(node->owner)->child
                )->target
            )->slot44(-1);
    }
}
