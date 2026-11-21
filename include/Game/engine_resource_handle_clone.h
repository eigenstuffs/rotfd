#ifndef GAME_ENGINE_RESOURCE_HANDLE_CLONE_H
#define GAME_ENGINE_RESOURCE_HANDLE_CLONE_H

typedef unsigned long ResourceCloneWord;
struct Handle_801F7F10 {
    union {
        ResourceCloneWord value;
        struct { signed int generation : 8, index : 24; } bits;
    };
    Handle_801F7F10();
    ~Handle_801F7F10();
};

struct ResourceCloneElementPrefix { ResourceCloneWord unknown00[2]; };
struct ResourceCloneElement : ResourceCloneElementPrefix {
    virtual ~ResourceCloneElement();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1C();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2C();
    virtual void slot30(Handle_801F7F10&, const Handle_801F7F10&);
};
struct ResourceCloneEntry {
    ResourceCloneElement* object;
    char unknown04[8];
    signed char generation;
    char padding0D[3];
};
struct ResourceCloneManager { int count, capacity; ResourceCloneEntry* entries; };
struct ResourceCloneName {
    ResourceCloneWord word;
    ResourceCloneName(const char*);
};
extern "C" {
extern struct ResourceCloneContext {
    char unknown00[0x118];
    ResourceCloneManager* manager;
} lbl_801E9D24;
extern const char lbl_8037B3D4[8];
extern char lbl_8028F698[];
ResourceCloneWord fn_801F948C(void*, const char*);
void fn_801F86C8(ResourceCloneManager*, const Handle_801F7F10*, short);
void* fn_801F7EB8(const Handle_801F7F10*);
Handle_801F7F10 fn_801B550C(ResourceCloneManager*, const ResourceCloneName&, const ResourceCloneName&);
void* fn_8028FAF4(void*, void*, ResourceCloneWord, ResourceCloneWord);
void* fn_8028FF24(void*, ResourceCloneWord);
void fn_8028FD50(void*, void*, ResourceCloneWord);
}

inline ResourceCloneName::ResourceCloneName(const char* text) {
    word = fn_801F948C(this, text);
}
inline void* operator new(ResourceCloneWord, void* address) { return address; }
struct ResourceCloneHandle1 : Handle_801F7F10 {
    ResourceCloneHandle1() { value = 0; }
    ~ResourceCloneHandle1() {}
};
struct ResourceCloneHandle2 : ResourceCloneHandle1 {
    ResourceCloneHandle2() { value = 0; }
    ~ResourceCloneHandle2() {}
};
struct ResourceCloneCopy1 : ResourceCloneHandle1 {
    ResourceCloneCopy1(const Handle_801F7F10& from) {
        value = from.value;
        fn_801F86C8(lbl_801E9D24.manager, &from, 1);
    }
};
struct ResourceCloneCopy2 : ResourceCloneHandle2 {
    ResourceCloneCopy2(const Handle_801F7F10& from) {
        value = from.value;
        fn_801F86C8(lbl_801E9D24.manager, &from, 1);
    }
};

template<class T> struct ResourceCloneArray {
    int count, capacity;
    T* items;
    inline void storage(int size) {
        if (size) {
            if (items)
                items = (T*)fn_8028FAF4(lbl_8028F698, items,
                    capacity * sizeof(T), size * sizeof(T));
            else
                items = (T*)fn_8028FF24(lbl_8028F698, size * sizeof(T));
        } else if (items) {
            fn_8028FD50(lbl_8028F698, items, capacity * sizeof(T));
            items = 0;
        }
    }
    inline void resize(int size) {
        int i;
        if (size > count) {
            storage(size);
            capacity = size;
            for (i = count; i < size; ++i)
                new (&items[i]) T;
            count = size;
        } else if (size < count) {
            for (i = count - 1; i >= size; --i)
                items[i].~T();
            storage(size);
            capacity = size;
            count = size;
        }
    }
};

/* Same-address partial views; broader class and field names remain inferred. */
struct ResourceCloneOwner {
    ResourceCloneName name;
    char unknown04[12];
    float values[4];
    ResourceCloneArray<ResourceCloneHandle2> array;
};
struct ResourceCloneData : ResourceCloneElement {
    int unknown0C;
    float values[4];
    ResourceCloneArray<ResourceCloneHandle2> array;
};
struct ResourceCloneParent : ResourceCloneElement {
    char unknown0C[0xBC];
    Handle_801F7F10* children;
};
struct ResourceCloneBaseEntry {
    ResourceCloneElementPrefix* object;
    char unknown04[8];
    signed char generation;
    char padding0D[3];
};
struct ResourceCloneBaseManager { int count, capacity; ResourceCloneBaseEntry* entries; };

extern "C" void fn_80245B8C(ResourceCloneOwner*, Handle_801F7F10&, Handle_801F7F10&);

#endif
