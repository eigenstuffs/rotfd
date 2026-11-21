typedef unsigned long u32;
typedef unsigned short u16;
struct Pool {
    char blanking[0x24];
    char anonymous[0x10];
    char file[0x18];
    char playing[0x1C];
    char exists[0x28];
    char bigFileMode[0x10];
    char standaloneMode[0x10];
    char greater[0x24];
    char smaller[0x24];
};
struct CommandBlock { u32 words[12]; };
struct FileInfo { CommandBlock block; u32 start; u32 length; void* callback; };
struct Record {
    u32 size;
    FileInfo file;
    u32 begin, current, total, remaining, end, flags;
    int type;
};
struct Voice {
    void* voice;
    u32 buffer;
    u32 index;
    void* unknown0C;
    u32 unknown10, unknown14, unknown18;
    char unknown1C[0x18];
    u32 played, queued;
};
struct MusicVoice {
    void* voice[2];
    u32 buffer;
    void* allocation;
    u32 unknown10, unknown14, unknown18;
    char unknown1C[0x18];
    u32 played, queued;
};
struct Entry {
    char name[0x14];
    u32 offset;
    u32 size;
    u32 present;
    char unknown20[0x20];
};
struct State {
    Record records[6];
    union {
        Voice voices[6];
        MusicVoice music[6];
    };
    char unknown390[0x698];
    Entry entries[256];
    FileInfo fileInfo;
    u32 unknown4A64;
    signed char opened;
    char unknown4A69[3];
    float musicLevel, effectsLevel;
    char names[6][16];
    void* allocation4AD4;
    u32* samples;
    u16* firstBytes;
    int indices[256];
    int count;
};
struct Registry {
    char path[0x80];
    char name[0x80];
};
struct Handle { union { u32 word; struct { signed int tag:8, index:24; } bits; }; };
struct HandleEntry { void* object; char unknown04[8]; signed char tag; char pad[3];
    signed char getTag() const { return tag; } };
struct Manager { char unknown00[8]; HandleEntry* entries; };
struct Owner { char unknown00[0x18]; Handle handle; };
struct Linked { char unknown00[0x48]; Handle handle; };
struct Listener { char unknown00[0x134]; void (*callback)(); void* argument; };
struct Aram { char unknown00[8]; u32 buffer; };
struct Globals {
    char unknown000[0x110];
    void* logger;
    char unknown114[4];
    Manager* manager;
    char unknown11C[8];
    Owner* owner;
    char unknown128[0x64];
    Aram* audio;
};
extern "C" {
extern Globals lbl_801E9D24;
extern const Pool lbl_802AF548;
extern char lbl_801EF5C8[];
extern char lbl_8035E9AC[32];
extern FileInfo lbl_8035E970;
extern char lbl_803780D8;
extern u32 lbl_803780D4;
extern const char lbl_8037B8F0[7];
void fn_801FA014(void*, const char*, ...);
void* fn_801EFA1C(void*, u32, const char*, const char*, int, int);
int strncmp(const char*, const char*, u32);
char* strncpy(char*, const char*, u32);
void* memset(void*, int, u32);
int fn_801F4520(const char*, const char*);
u32 DVDOpen(const char*, void*);
int DVDClose(void*);
u32 fn_80285784(Aram*, u32);
u32 fn_80285800(Aram*, u32);
void* AXAcquireVoice(u32, void*, u32);
void MIXInitChannel(void*, u32, int, int, int, int, int, int);
void fn_8028AE40();
}
template <class T> inline T* resolve(const Handle& h)
{
    int index = h.bits.index;
    Manager* m = lbl_801E9D24.manager;
    int tag = m->entries[index].getTag();
    return tag == h.bits.tag ? (T*)m->entries[index].object : 0;
}
inline u32 streamBuffer(Aram* aram, u32 size)
{
    if (!aram->buffer) {
        aram->buffer = fn_80285784(aram, size);
    }
    return aram->buffer;
}
extern "C" int fn_80289ADC(State* self, Registry* node, int kind, signed char loop)
{
    const Pool* const pool = &lbl_802AF548;
    if (!node) {
        return -1;
    }
    u32 length = 0;
    u32 found = (u32)-1;
    const char* name = node->name;
    signed char ok = 0;
    FileInfo info;
    u32 i;
    for (i = 0; i < 6; i++) {
        if (!strncmp(name, self->names[i], 16)) {
            fn_801FA014(lbl_801E9D24.logger, pool->exists, self->names[i], i);
            return -2;
        }
    }
    if (lbl_801E9D24.owner) {
        Linked* linked = resolve<Linked>(lbl_801E9D24.owner->handle);
        if (linked) {
            Listener* listener = resolve<Listener>(linked->handle);
            if (listener) {
                listener->callback = fn_8028AE40;
                listener->argument = self;
            }
        }
    }
    if (self->opened) {
        fn_801FA014(lbl_801E9D24.logger, pool->bigFileMode);
        for (i = 0; i < 256; i++) {
            if (self->entries[i].present && !strncmp(name, self->entries[i].name, 16)) {
                info = self->fileInfo;
                found = i;
                ok = 1;
            }
        }
    }
    if (!ok) {
        fn_801FA014(lbl_801E9D24.logger, pool->standaloneMode);
        if (fn_801F4520(node->path, lbl_8035E9AC)) {
            if (DVDOpen(node->path, &info)) {
                if (lbl_8035E9AC[0]) {
                    DVDClose(&lbl_8035E970);
                }
                ok = 1;
                strncpy(lbl_8035E9AC, node->path, 0x20);
                lbl_8035E970 = info;
            }
            lbl_803780D8 = 0;
            lbl_803780D4 = length = info.length;
        } else if (lbl_8035E9AC[0]) {
            lbl_803780D8 = 1;
            ok = 1;
            info = lbl_8035E970;
            length = lbl_803780D4;
        }
    }
    if (!ok) {
        return -1;
    }
    if (kind == 1) {
        for (int j = 0; j < 4; j++) {
            if (!(self->records[j].flags & 2)) {
                Record* record = &self->records[j];
                Voice* voice = &self->voices[j];
                strncpy(self->names[j], name, 16);
                record->file = info;
                record->flags = 6;
                if (self->opened) {
                    record->flags |= 0x80000000;
                }
                record->type = 1;
                record->end = 0x8000;
                record->size = 0x8000;
                if (self->opened) {
                    record->begin = self->entries[found].offset;
                    record->current = self->entries[found].offset;
                    record->total = self->entries[found].size;
                    record->remaining = self->entries[found].size;
                    record->flags |= 0x1000;
                } else {
                    record->begin = 0;
                    record->current = 0;
                    record->total = length;
                    record->remaining = length;
                    record->flags |= 0x1000;
                }
                if (record->total > 0x8000) {
                    fn_801FA014(lbl_801E9D24.logger, pool->greater);
                } else {
                    fn_801FA014(lbl_801E9D24.logger, pool->smaller);
                }
                if (record->flags & 0x1000) {
                    fn_801FA014(lbl_801E9D24.logger, lbl_8037B8F0);
                }
                if (self->opened && found != (u32)-1) {
                    record->flags |= 0x1004;
                    voice->buffer = self->samples[self->indices[found]];
                    record->end = self->entries[found].size;
                    record->size = self->entries[found].size;
                } else {
                    voice->buffer = fn_80285800(lbl_801E9D24.audio, record->size);
                }
                voice->voice = AXAcquireVoice(31, 0, 0);
                MIXInitChannel(voice->voice, 0, 0, -904, -904, 64, 127, 0);
                if (self->opened) {
                    voice->index = found;
                } else {
                    voice->index = (u32)-1;
                }
                voice->played = 0;
                voice->queued = 0;
                return j;
            }
        }
    } else if (kind == 2) {
        if (self->records[4].flags & 2) {
            return -1;
        }
        Record* record = &self->records[4];
        strncpy(self->names[4], name, 16);
        record->begin = 0;
        record->current = 0;
        record->total = length;
        record->remaining = length;
        record->size = 0x10000;
        record->file = info;
        record->flags = 6;
        if (loop) {
            record->flags |= 0x800;
        }
        record->type = kind;
        self->music[4].buffer = streamBuffer(lbl_801E9D24.audio, record->size);
        self->music[4].allocation = fn_801EFA1C(lbl_801EF5C8, 0x10000, pool->anonymous, pool->file, 0x2EF, 0x20);
        if (!self->music[4].allocation) {
            return -1;
        }
        memset(self->music[4].allocation, 0, 0x10000);
        self->music[4].unknown14 = 0;
        self->music[4].unknown18 = 1;
        return 4;
    } else if (kind == 3) {
        return 5;
    }
    return -3;
}
