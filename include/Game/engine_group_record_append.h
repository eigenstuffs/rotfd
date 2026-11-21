#ifndef GAME_ENGINE_GROUP_RECORD_APPEND_H
#define GAME_ENGINE_GROUP_RECORD_APPEND_H

struct Handle_801F7F10 {
    unsigned long value;
    Handle_801F7F10();
    ~Handle_801F7F10();
};
struct GroupAppendManager;
struct GroupAppendContext {
    char unknown00[0x118];
    GroupAppendManager *manager;
};
extern "C" {
extern GroupAppendContext lbl_801E9D24;
void fn_801F86C8(GroupAppendManager *, const Handle_801F7F10 *, short);
}
struct GroupAppendHandle : Handle_801F7F10 {
    GroupAppendHandle(const GroupAppendHandle &handle) : Handle_801F7F10() {
        value = 0;
        value = handle.value;
        fn_801F86C8(lbl_801E9D24.manager, &handle, 1);
    }
};
struct GroupAppendZero : Handle_801F7F10 {
    GroupAppendZero() { value = 0; }
};
struct GroupAppendWrapped : GroupAppendZero {
    GroupAppendWrapped(const GroupAppendWrapped &handle) {
        value = handle.value;
        fn_801F86C8(lbl_801E9D24.manager, &handle, 1);
    }
};
struct GroupAppendRecord {
    unsigned long words[32];
    unsigned long value80, value84, value88;
    unsigned short value8C;
    GroupAppendWrapped handle90;
    unsigned long value94;
    GroupAppendHandle handle98;
};
template<class T> struct GroupAppendArray {
    int count, capacity;
    T *data;
};
struct GroupAppendOwner {
    char unknown00[0x38];
    GroupAppendArray<GroupAppendRecord *> pointers;
    char unknown44[8];
    GroupAppendArray<GroupAppendRecord> records;
};

typedef char CheckGroupAppendRecordSize[sizeof(GroupAppendRecord) == 0x9C ? 1 : -1];
extern "C" int fn_8021AFE0(GroupAppendOwner *, const GroupAppendRecord *);

#endif
