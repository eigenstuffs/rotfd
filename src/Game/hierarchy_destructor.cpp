// Native hierarchy destruction reconstructed from the GSQE78 executable.
typedef unsigned long u32;
extern "C" {
extern char lbl_801EF5C8[];
extern char lbl_8028F698[];
void fn_801EF610(void*, void*);
void fn_8028FD50(void*, void*, u32);
}

struct Handle_801F7F10 { ~Handle_801F7F10(); u32 value; };
struct ListElementLayer1:Handle_801F7F10 { ~ListElementLayer1() {} };
struct ListElementLayer2:ListElementLayer1 { ~ListElementLayer2() {} };
struct ListElementLayer3:ListElementLayer2 { ~ListElementLayer3() {} };
struct ListElementLayer4:ListElementLayer3 { ~ListElementLayer4() {} };
struct ListElementLayer5:ListElementLayer4 { ~ListElementLayer5() {} };
struct ListElementLayer6:ListElementLayer5 { ~ListElementLayer6() {} };
struct ListElementLayer7:ListElementLayer6 { ~ListElementLayer7() {} };
struct HandleList_802007D8 {
    int count, capacity;
    ListElementLayer7* data;
    ~HandleList_802007D8();
    static void operator delete(void* memory) {
        fn_801EF610(lbl_801EF5C8, memory);
    }
};

// Inline wrapper destruction preserves the observed typed-handle layers.
// These names describe the recovered layout, not original debug names.
template<int N> struct HierarchyHandleLayer : HierarchyHandleLayer<N - 1> {
    ~HierarchyHandleLayer() {}
};
template<> struct HierarchyHandleLayer<0> : Handle_801F7F10 {
    ~HierarchyHandleLayer() {}
};

template<int N> struct HierarchyHandleList {
    int count, capacity;
    HierarchyHandleLayer<N - 1>* data;
    ~HierarchyHandleList() {
        if (data) {
            for (int i = 0; i < count; ++i)
                data[i].~HierarchyHandleLayer<N - 1>();
            if (data) {
                fn_8028FD50(lbl_8028F698, data, capacity * 4);
                data = 0;
            }
            data = 0;
        }
    }
};

struct RootStorage_80207414 { u32 unknown0, identity; };
struct BaseObject_Z : RootStorage_80207414 {
    virtual ~BaseObject_Z();
    virtual void slot0C(u32);
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual signed char slot1C();
    static void operator delete(void* memory) {
        fn_801EF610(lbl_801EF5C8, memory);
    }
};

struct Hierarchy_80200478 : BaseObject_Z {
    HierarchyHandleLayer<1> owner;  // 0x0C
    char unknown10[0x80];
    HierarchyHandleList<3> list90;
    HierarchyHandleList<5> list9C;
    HandleList_802007D8 listA8;
    HierarchyHandleList<2> listB4;
    HierarchyHandleLayer<2> related; // 0xC0
    HierarchyHandleList<2> listC4;
    HierarchyHandleList<4> listD0;
    ~Hierarchy_80200478();
    virtual signed char slot1C();
};

Hierarchy_80200478::~Hierarchy_80200478() {}
