#ifndef GAME_ENGINE_RECORD_APPEND_H
#define GAME_ENGINE_RECORD_APPEND_H

struct Handle_801F7F10 {
    unsigned long value;
    Handle_801F7F10();
    ~Handle_801F7F10();
};
struct AppendManager;
struct AppendContext {
    char unknown00[0x118];
    AppendManager *manager;
};
extern "C" {
extern AppendContext lbl_801E9D24;
void fn_801F86C8(AppendManager *, const Handle_801F7F10 *, short);
}
struct AppendHandle : Handle_801F7F10 {
    AppendHandle(const AppendHandle &handle) : Handle_801F7F10() {
        value = 0;
        value = handle.value;
        fn_801F86C8(lbl_801E9D24.manager, &handle, 1);
    }
};
struct AppendPair { unsigned long first, second; };
struct AppendRecord {
    AppendHandle handle;
    unsigned long value04;
    unsigned long words[32];
    unsigned long value88, value8C, value90, value94;
    AppendPair pair98, pairA0;
    unsigned char valueA8, valueA9;
    float valueAC, valueB0;
    unsigned char valueB4, valueB5, valueB6;
    float valueB8, valueBC, valueC0, valueC4, valueC8, valueCC, valueD0;
};
struct AppendArray {
    int count, capacity;
    AppendRecord *data;
};

typedef char CheckAppendRecordSize[sizeof(AppendRecord) == 0xD4 ? 1 : -1];
extern "C" int fn_80210014(AppendArray *, const AppendRecord *);

#endif
