#ifndef GAME_ENGINE_RECORD_BUFFERS_H
#define GAME_ENGINE_RECORD_BUFFERS_H

struct EngineRecordBufferHandle {
    unsigned int value;
};
struct EngineRecordBufferItem {
    int key;
    struct EngineRecordBufferHandle handle;
    float a, b, c, d;
};
struct EngineRecordBufferItems {
    int count, capacity;
    struct EngineRecordBufferItem* items;
};
struct EngineRecordBufferWords {
    int count, capacity;
    unsigned int* items;
};
struct EngineRecordBufferRows {
    int count, capacity;
    struct EngineRecordBufferWords* items;
};
extern char lbl_8028F698[];
extern struct {
    char unknown00[0x118];
    void* manager;
} lbl_801E9D24;
void* fn_8028FAF4(void*,  void*,  int, int);
void* fn_8028FF24(void*,  int);
void fn_8028FD50(void*,  void*,  int);
void fn_801F86C8(void*,  const struct EngineRecordBufferHandle*, int);
void __ct__15Handle_801F7F10Fv(struct EngineRecordBufferHandle*);
void fn_8024B744(struct EngineRecordBufferItems*);
void fn_80025898(struct EngineRecordBufferItems*, int);
void fn_8024BC7C(struct EngineRecordBufferRows*);
void fn_8024BBB8(struct EngineRecordBufferRows*, int);
void fn_801D3088(struct EngineRecordBufferRows*, int, int);
struct EngineRecordBufferWords* fn_8024B8E0(struct EngineRecordBufferWords*, const struct EngineRecordBufferWords*);
int fn_8024B7F4(struct EngineRecordBufferRows*, const struct EngineRecordBufferWords*);

typedef char EngineRecordBufferItemSize[sizeof(struct EngineRecordBufferItem) == 24 ? 1 : -1];
typedef char EngineRecordBufferWordsSize[sizeof(struct EngineRecordBufferWords) == 12 ? 1 : -1];

#endif
