// Native handle-list destructor reconstructed from GSQE78.
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
HandleList_802007D8::~HandleList_802007D8() {
    if (data) {
        for (int i = 0; i < count; ++i)
            data[i].~ListElementLayer7();
        if (data) {
            fn_8028FD50(lbl_8028F698, data, capacity * 4);
            data = 0;
        }
        data = 0;
    }
}
