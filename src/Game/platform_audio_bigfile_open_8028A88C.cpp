typedef unsigned long u32;
typedef unsigned short u16;
typedef unsigned char u8;
struct Pool {
    char blanking[0x24];
    char anonymous[0x10];
    char file[0x18];
    char streamMessages[0xAC];
    char releaseNames[0x20];
    char initialized[0x1C];
    char nullName[0x10];
    char alreadyEnabled[0x14];
};
struct BigEntry {
    char unknown00[0x14];
    u32 offset;
    u32 size;
    u32 present;
    char unknown20[0x20];
};
struct BigState {
    char unknown0000[0xA28];
    BigEntry entries[256];
    char fileInfo[0x34];
    u32 length;
    char unknown4A60[4];
    u32 unknown4A64;
    signed char opened;
    char unknown4A69[0x6F];
    void** samples;
    u16* firstBytes;
    int indices[256];
    int count;
};
struct Globals {
    char unknown000[0x110];
    void* logger;
    char unknown114[0x78];
    void* audio;
};
extern "C" {
extern Globals lbl_801E9D24;
extern const Pool lbl_802AF548;
extern char lbl_801EF5C8[];
void fn_801FA014(void*, const char*, ...);
void* fn_801EFA1C(void*, u32, const char*, const char*, int, int);
void fn_801EF610(void*, void*);
u32 DVDOpen(const char*, void*);
void fn_8028EEEC(BigState*, void*, void*, u32, u32);
void* memcpy(void*, const void*, u32);
void* fn_80285784(void*, u32);
void fn_8028533C(void*, void*, void*, u32, int);
void fn_8028531C(void*);
}
extern "C" int fn_8028A88C(BigState* self, const char* name, void (*callback)())
{
    const Pool* const pool = &lbl_802AF548;
    fn_801FA014(lbl_801E9D24.logger, pool->initialized);
    if (!name) {
        fn_801FA014(lbl_801E9D24.logger, pool->nullName);
        return 0;
    }
    if (self->opened) {
        fn_801FA014(lbl_801E9D24.logger, pool->alreadyEnabled);
        return 1;
    }
    self->unknown4A64 = 0;
    self->opened = 0;
    if (!DVDOpen(name, self->fileInfo)) {
        return 0;
    }
    void* header = fn_801EFA1C(lbl_801EF5C8, 0x4000, pool->anonymous, pool->file, 0xEA, 0x20);
    fn_8028EEEC(self, self->fileInfo, header, 0x4000, 0);
    memcpy(self->entries, header, 0x4000);
    fn_801EF610(lbl_801EF5C8, header);
    self->unknown4A64 = self->length;
    self->opened = 1;
    self->count = 0;
    u32 maxSize = 0;
    int i;
    for (i = 0; i < 256; i++) {
        if (self->entries[i].present) {
            self->indices[i] = self->count;
            if (self->entries[i].size > maxSize) {
                maxSize = self->entries[i].size;
            }
            self->count++;
        } else {
            self->indices[i] = -1;
        }
    }
    self->samples = (void**)fn_801EFA1C(lbl_801EF5C8, self->count * 4, pool->anonymous, pool->file, 0x10E, 0x20);
    self->firstBytes = (u16*)fn_801EFA1C(lbl_801EF5C8, self->count * 2, pool->anonymous, pool->file, 0x10F, 0x20);
    u8* buffer = (u8*)fn_801EFA1C(lbl_801EF5C8, maxSize + 0x7D00, pool->anonymous, pool->file, 0x110, 0x20);
    for (i = 0; i < 256; i++) {
        if (self->entries[i].present) {
            self->entries[i].size = (self->entries[i].size - 0x1C) & ~3;
            self->samples[self->indices[i]] = fn_80285784(lbl_801E9D24.audio, self->entries[i].size);
            fn_8028EEEC(self, self->fileInfo, buffer, self->entries[i].size, self->entries[i].offset);
            self->firstBytes[self->indices[i]] = buffer[0];
            fn_8028533C(lbl_801E9D24.audio, buffer, self->samples[self->indices[i]], self->entries[i].size, 0);
            fn_8028531C(lbl_801E9D24.audio);
        }
        if (callback) {
            callback();
        }
    }
    fn_801EF610(lbl_801EF5C8, buffer);
    return 1;
}
