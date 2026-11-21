/* GCMovie_Z.cpp: GameCube movie player (8028C1E8..8028DB38).
 *
 * Owner destructor, buffered stream read, stream close, movie playback
 * (open the .THP/.H4M stream, set up video/audio buffers and the two worker
 * threads, pump chunks until the last frame or reset/skip, tear down),
 * video resume/pause/cleanup, init, the audio DMA worker thread and the
 * display thread.  The unit owns the thread/stack/semaphore storage in .bss,
 * the shared decode state in .sbss, its string pool in .rodata and its
 * float pool in .sdata2. */
typedef unsigned long u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef signed short s16;

struct Handle_801F7F10 {
    u32 word;
    Handle_801F7F10();
    ~Handle_801F7F10();
};
struct ZeroHandle : Handle_801F7F10 {
    ZeroHandle() { word = 0; }
    ~ZeroHandle() {}
};
struct File_801F3E1C {
    char unknown00[0x5C];
    File_801F3E1C();
    ~File_801F3E1C();
};

struct GXColor { u8 r, g, b, a; };

struct SoundStorage { char unknown00[0x7C]; };
struct Sound : SoundStorage {
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void start();
    virtual void slot18();
    virtual void slot1C();
    virtual void slot20();
    virtual void stop();
    virtual void slot28();
    virtual void slot2C();
    virtual void setVolume(float);
    virtual float getVolume();
    virtual void setMusicVolume(float);
    virtual float getMusicVolume();
};
struct CallbackStorage { char unknown00[0x1C]; };
struct Callback : CallbackStorage {
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1C();
    virtual void tick(float);
    virtual signed char pressed(int);
};
struct GameStorage { char unknown00[0x278]; };
struct Game : GameStorage {
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void begin();
    virtual void end();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2C();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3C();
    virtual void slot40();
    virtual void slot44();
    virtual void slot48();
    virtual void slot4C();
    virtual void slot50();
    virtual void slot54();
    virtual void slot58();
    virtual void slot5C();
    virtual void slot60();
    virtual void slot64();
    virtual void slot68();
    virtual void setHandle(Handle_801F7F10*);
    virtual void slot70();
    virtual void slot74();
    virtual void slot78();
    virtual void slot7C();
    virtual void slot80();
    virtual void slot84();
    virtual void slot88();
    virtual void slot8C();
    virtual void slot90();
    virtual void slot94();
    virtual void slot98();
    virtual void slot9C();
    virtual void slotA0();
    virtual void slotA4();
    virtual void slotA8();
    virtual void slotAC();
    virtual void slotB0();
    virtual void clear(int, int, int, int);
};
struct Globals {
    char unknown00[0x110];
    void* logger;
    Game* game;
    char unknown118[0x3C];
    Callback* callback;
    Sound* sound;
    struct Movie* movie;
};

struct MovieStorage { signed char paused; signed char skippable; char unknown02[6]; };
struct MovieDispatch : MovieStorage {
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
};
struct Movie {
    signed char paused;
    signed char skippable;
    char unknown02[0xA];
    char file[0x3C];
    u32 word48;
    u32 word4C;
    void* allocation;
    u32 unknown54;
    int hasExtension;
    signed char enabled;
    signed char black;
};
struct MovieHeader {
    char unknown00[0x18];
    u32 frames;
    char unknown1C[8];
    u32 word24;
    u32 videoSize;
    u32 unknown2C;
    u32 audioSize;
    char video34[8];
    u8 channels;
    char unknown3D[3];
    u32 rate;
};
struct FrameHeader {
    char unknown00[8];
    u32 count08;
    u32 count0C;
    u32 unknown10;
};
struct ChunkHeader {
    u16 type;
    u16 format;
    u32 size;
};
struct BufferRecord {
    u32 word00;
    u32 end04;
    char unknown08[8];
    u32 begin10;
    u32 end14;
    char unknown18[0x10];
    u32 begin28;
    u32 end2C;
};

struct Table { u32 unknown[4]; void (*cleanup)(void*); };
struct VideoMode {
    u32 format;
    u16 width;
    u16 unknown06;
    u16 height;
};
struct Decoder { char unknown00[4]; u16 width; u16 height; char unknown08[4]; };

extern "C" {
    extern Globals lbl_801E9D24;
    extern char lbl_801EF5C8[];
    extern char lbl_802F16D0[];
    extern char lbl_802EA0F8[];
    extern u16 lbl_802F15D0[];
    extern signed char lbl_80377FC9;
    extern VideoMode GXNtsc480Int;

    int lbl_803780E8;
    int lbl_803780EC;
    u32 lbl_803780F0[2];
    u32* lbl_803780F8;
    int lbl_803780FC;
    u32 lbl_80378100;
    u32 lbl_80378104;
    char* lbl_80378108;
    char* lbl_8037810C;
    char* lbl_80378110;
    char* lbl_80378114;
    u32 lbl_80378118;
    u32 lbl_8037811C;
    void* lbl_80378120;
    char* lbl_80378124;
    u32* lbl_80378128[2];
    char* lbl_80378130;
    char* lbl_80378134;
    char* lbl_80378138;
    u32 lbl_8037813C;
    char* lbl_80378140;
    u32 lbl_80378144;
    u32 lbl_80378148;
    ChunkHeader lbl_8037814C;
    void* lbl_80378154;
    int lbl_80378158;

    void fn_801FA014(void*, const char*, ...);
    signed char fn_801C9AAC(Movie*, const char*);
    int sprintf(char*, const char*, ...);
    void fn_80207A14(const char*, char*);
    void* fn_801EFA1C(void*, u32, const char*, const char*, int, u32);
    void fn_801EF610(void*, void*);
    u32 strlen(const char*);
    char* strcat(char*, const char*);
    char* strcpy(char*, const char*);
    void* memset(void*, int, u32);
    void* memcpy(void*, const void*, u32);
    int fn_801F4520(const char*, const char*);
    int DVDOpen(const char*, void*);
    int DVDClose(void*);
    void DVDCancelAll();
    void fn_8028C280(Movie*, void*, u32);
    void fn_801C9AA0(Movie*);
    void fn_801C9ABC(void*);
    signed char fn_801C9AC0(void*);
    u32 VIGetTvFormat();
    int OSSuspendThread(void*);
    int OSWaitSemaphore(void*);
    void DCFlushRangeNoSync(void*, u32);
    void DCStoreRange(void*, u32);
    void PPCSync();
    void AIInitDMA(u32, u32);
    void AIStartDMA();
    u32 AIGetDMABytesLeft();
    void fn_802954D0(void*, void*, void*, void*);
    void fn_802959E0(void*, void*, void*, void*);
    void fn_80295A04(void*, void*, void*, void*, void*);
    void fn_8028DB38(void*, void*, u32, u32);
    int AICheckInit();
    void AIReset();
    void AIInit(void*);
    void AISetDSPSampleRate(u32);
    void AIStopDMA();
    void AXQuit();
    void VISetBlack(int);
    void VIFlush();
    void VIWaitForRetrace();
    void VIConfigure(void*);
    void VISetNextFrameBuffer(void*);
    void fn_80294FB4();
    void fn_80294FD4(void*, void*);
    u32 fn_80294FF8(void*);
    void fn_8029506C(void*, void*);
    void fn_80295FAC(void*, void*, u32, u32, u32, void*);
    void GXSetCopyClear(GXColor, u32);
    void GXSetColorUpdate(int);
    void GXDrawDone();
    void GXAbortFrame();
    void LCDisable();
    void DCFlushRange(void*, u32);
    void OSInitSemaphore(void*, int);
    int OSSignalSemaphore(void*);
    int OSCreateThread(void*, void* (*)(void*), void*, void*, u32, int, int);
    int OSResumeThread(void*);
    void OSCancelThread(void*);
    void OSPanic(const char*, int, const char*, ...);
    int OSGetResetSwitchState();
    void OSResetSystem(int, int, int);
    void __PADDisableRecalibration(int);
    void fn_8028EEEC(void*, void*, void*, u32, u32);
    void* fn_8028D8BC(void*);
    void* fn_8028D814(void*);
}

static char sVideoThread[0x318];
static char sVideoStack[0x2000];
static char sAudioThread[0x318];
static char sAudioStack[0x2000];
static char sVideoReady[0xC];
static char sVideoDone[0xC];
static char sAudioReady[0xC];
static char sAudioDone[0xC];
static BufferRecord sRecords[2];
static char sUnknown46C0[0x40];
static Decoder sDecoder;
static char sBootBuffer[0x24];


static inline void fill(u32* first, u32* last, u32 value)
{
    for (; first < last; first++)
        *first = value;
}

static inline void resetAudio()
{
    if (AICheckInit())
        AIReset();
    else
        AIInit(0);
}

static inline void loadBootFile()
{
    char path[0x20];
    char file[0x3C];
    u32 request;
    strcpy(path, "/USER.TSC");
    if (DVDOpen(path, file) != 0u)
        fn_8028EEEC(&request, file, sBootBuffer, 0x10, 0);
}


/* 8028C1E8 */
struct Storage { u32 unknown00[2]; };
struct Dispatch : Storage {
    virtual void slot08();
    virtual void slot0C();
    virtual void cleanup();
};
struct PlatformBase {
    u32 unknown00[2];
    Table* table;
    ~PlatformBase() { table = (Table*)lbl_802EA0F8; ((Dispatch*)this)->cleanup(); }
};
struct PlatformOwner_8028C1E8 : PlatformBase {
    ~PlatformOwner_8028C1E8();
    static void operator delete(void* p) { fn_801EF610(lbl_801EF5C8, p); }
};
PlatformOwner_8028C1E8::~PlatformOwner_8028C1E8()
{
    table = (Table*)lbl_802F16D0;
    ((Dispatch*)this)->cleanup();
}

/* 8028C280: read through the 32-byte aligned stream buffer */
extern "C" void fn_8028C280(Movie* self, void* destination, u32 size)
{
    u32 remaining = size;
    if (self->word48) {
        u32 take = 32 - self->word48;
        if (take >= size)
            take = size;
        memcpy(destination, (char*)self->allocation + self->word48, take);
        if (32 - self->word48 >= size) {
            self->word48 += take;
            if (self->word48 == 32)
                self->word48 = 0;
            return;
        }
        self->word48 = 0;
        remaining -= take;
    }
    if (((remaining + 31) & ~31UL) == remaining) {
        char* out = (char*)destination + (size - remaining);
        if ((long)out % 32) {
            fn_8028EEEC(self->file, self->file, lbl_80378124, remaining, self->word4C);
            self->word4C += remaining;
            memcpy(out, lbl_80378124, remaining);
        } else {
            fn_8028EEEC(self->file, self->file, out, remaining, self->word4C);
            self->word4C += remaining;
        }
        self->word48 = 0;
    } else {
        if (remaining > 32) {
            char* out = (char*)destination + (size - remaining);
            u32 block;
            if ((long)out % 32) {
                block = (remaining - 1) & ~31UL;
                fn_8028EEEC(self->file, self->file, lbl_80378124, block, self->word4C);
                self->word4C += block;
                memcpy(out, lbl_80378124, block);
            } else {
                block = (remaining - 1) & ~31UL;
                fn_8028EEEC(self->file, self->file, out, block, self->word4C);
                self->word4C += block;
            }
            remaining -= ((remaining - 1) & ~31UL);
        }
        fn_8028EEEC(self->file, self->file, self->allocation, 32, self->word4C);
        self->word4C += 32;
        memcpy((char*)destination + (size - remaining), self->allocation, remaining);
        self->word48 = remaining;
    }
}

/* 8028C494 */
extern "C" void fn_8028C494(Movie* self)
{
    if (self->enabled) {
        fn_801C9AA0(self);
        self->enabled = 0;
        DVDClose(self->file);
        self->word4C = 0;
    }
}

int openMovie(Movie* self, const char* path, Globals* globals)
{
    char buffer[0x100];
    u32 i;
    for (i = 0; i < strlen(path); i++) {
        if (path[i] == '\\')
            buffer[i] = '/';
        else
            buffer[i] = path[i];
    }
    buffer[i] = 0;
    fn_801FA014(globals->logger, "Going to check movie file %s", buffer);
    if (fn_801F4520(&buffer[strlen(buffer) - 4], ".H4M") == 0)
        self->hasExtension = 1;
    else
        self->hasExtension = 0;
    if (!self->hasExtension) {
        fn_801FA014(globals->logger, "Found no .H4M or .THP at the end, appending .H4M");
        strcat(buffer, ".H4M");
    }
    fn_801FA014(globals->logger, "Opening movie file %s", buffer);
    if (!DVDOpen(buffer, self->file)) {
        fn_801FA014(globals->logger, "Movie open failed on movie %s", buffer);
        return 0;
    }
    self->word4C = 0;
    self->word48 = 0;
    return 1;
}

extern "C" int fn_8028C4E4(Movie* self, const char* name)
{
    char path[0x80];
    char unixPath[0x80];
    File_801F3E1C file;
    MovieHeader header;
    signed char reset;
    float volume, savedVolume, savedMusic;
    char* audio;
    char* video;
    void* work;
    char* planes;
    char* frame;
    u32 channels;

    lbl_80378158 = 0;
    reset = 0;
    fn_801FA014(lbl_801E9D24.logger, "Playing Movie %s", name);
    volume = lbl_801E9D24.sound->getVolume();
    savedVolume = volume;
    savedMusic = lbl_801E9D24.sound->getMusicVolume();
    volume *= 0.9f;
    volume = (float)lbl_802F15D0[(int)(128.0f * volume)] / 32768.0f;
    fn_801FA014(lbl_801E9D24.logger, "Volume was %f, is now %f", lbl_801E9D24.sound->getVolume(), volume);
    if (!fn_801C9AAC(self, name))
        return 0;
    if (self->enabled)
        ((MovieDispatch*)self)->slot18();
    sprintf(path, "DB:>%s.THP", name);
    fn_80207A14(path, unixPath);
    lbl_80378124 = (char*)fn_801EFA1C(lbl_801EF5C8, 0x44, "Anonymous Alloc", "GCMovie_Z.cpp", 0x24E, 0x20);
    if (!openMovie(self, unixPath, &lbl_801E9D24)) {
        sprintf(path, "DB:>%s.H4M", name);
        fn_80207A14(path, unixPath);
        if (!openMovie(self, unixPath, &lbl_801E9D24))
            return 0;
    }
    fn_8028C280(self, &header, 0x44);
    resetAudio();
    lbl_801E9D24.sound->setVolume(volume);
    self->black = 1;
    VISetBlack(1);
    VIFlush();
    fn_80294FB4();
    VIConfigure(lbl_80378120);
    VIFlush();
    VIWaitForRetrace();
    GXColor clear;
    clear.a = 0;
    clear.b = 0;
    clear.g = 0;
    clear.r = 0;
    GXSetCopyClear(clear, 0xFFFFFF);
    GXSetColorUpdate(1);
    frame = (char*)fn_801EFA1C(lbl_801EF5C8, ((lbl_80378104 + 63) & ~63UL) * 2 + 64,
                               "Anonymous Alloc", "GCMovie_Z.cpp", 0x273, 0x20);
    lbl_80378128[0] = (u32*)((u32)(frame + 63) & ~63UL);
    lbl_80378128[1] = (u32*)((char*)lbl_80378128[0] + lbl_80378104);
    lbl_803780FC = 1;
    fill(lbl_80378128[0], lbl_80378128[1], 0x00800080);
    DCFlushRange(lbl_80378128[0], lbl_80378104);
    { u32* p = lbl_80378128[1]; u32* e = (u32*)((char*)p + lbl_80378104); for (; p < e; p++) *p = 0x00800080; }
    DCFlushRange(lbl_80378128[1], lbl_80378104);
    lbl_803780F0[0] = 1;
    lbl_803780F0[1] = 1;
    lbl_803780F8 = lbl_80378128[0];
    VISetNextFrameBuffer(lbl_80378128[1]);
    VIFlush();
    self->enabled = 0;
    fn_801FA014(lbl_801E9D24.logger, "Movie now playing - 1");
    if (header.audioSize)
        audio = (char*)fn_801EFA1C(lbl_801EF5C8, header.audioSize + 4, "Anonymous Alloc", "GCMovie_Z.cpp", 0x294, 0x20);
    else
        audio = 0;
    video = (char*)fn_801EFA1C(lbl_801EF5C8, header.videoSize + 4, "Anonymous Alloc", "GCMovie_Z.cpp", 0x29C, 0x20);
    fn_801EF610(lbl_801EF5C8, lbl_80378124);
    lbl_80378124 = (char*)fn_801EFA1C(lbl_801EF5C8, header.videoSize + 4, "Anonymous Alloc", "GCMovie_Z.cpp", 0x29F, 0x20);
    fn_80294FD4(&sDecoder, header.video34);
    work = fn_801EFA1C(lbl_801EF5C8, fn_80294FF8(&sDecoder), "Anonymous Alloc", "GCMovie_Z.cpp", 0x2A7, 0x20);
    fn_8029506C(&sDecoder, work);
    lbl_80378118 = sDecoder.width;
    lbl_8037811C = sDecoder.height;
    u32 size = lbl_80378118 * lbl_8037811C + (lbl_80378118 >> 1) * (lbl_8037811C >> 1) * 2;
    planes = (char*)fn_801EFA1C(lbl_801EF5C8, ((size + 31) & ~31UL) * 3, "Anonymous Alloc", "GCMovie_Z.cpp", 0x2AF, 0x20);
    lbl_80378110 = planes;
    lbl_80378108 = lbl_80378110 + size;
    lbl_8037810C = lbl_80378108 + size;
    OSInitSemaphore(sVideoReady, 0);
    OSInitSemaphore(sVideoDone, 1);
    OSInitSemaphore(sAudioReady, 0);
    OSInitSemaphore(sAudioDone, 1);
    if (!OSCreateThread(sVideoThread, fn_8028D8BC, 0, sVideoStack + 0x2000, 0x2000, 0x10, 1))
        OSPanic("GCMovie_Z.cpp", 0x2C6, "Create Disp Thread Error !!\n");
    OSResumeThread(sVideoThread);
    if (audio) {
        if (!OSCreateThread(sAudioThread, fn_8028D814, 0, sAudioStack + 0x2000, 0x2000, 0, 1))
            OSPanic("GCMovie_Z.cpp", 0x2D5, "Create Disp Thread Error !!\n");
        OSResumeThread(sAudioThread);
    }
    fn_801FA014(lbl_801E9D24.logger, "Movie now playing - 2");
    self->enabled = 1;
    if (audio) {
        channels = header.channels;
        lbl_8037813C = header.rate * header.word24 / 1000000;
        lbl_8037813C *= channels;
        lbl_8037813C *= 2;
        lbl_8037813C = (lbl_8037813C + 0x40) & ~31UL;
        lbl_80378140 = (char*)fn_801EFA1C(lbl_801EF5C8, lbl_8037813C * 2, "Anonymous Alloc", "GCMovie_Z.cpp", 0x2E5, 0x20);
        lbl_80378130 = lbl_80378140;
        lbl_80378134 = lbl_80378140 + lbl_8037813C;
        if (header.rate == 32028)
            AISetDSPSampleRate(0);
        else
            AISetDSPSampleRate(1);
        memset(sRecords, 0, 0x60);
        BufferRecord* records = sRecords;
        records[0].begin10 = (u32)lbl_80378130;
        records[0].end14 = (u32)lbl_80378130 + lbl_8037813C;
        records[0].begin28 = (u32)lbl_80378130;
        records[0].end2C = (u32)lbl_80378130 + lbl_8037813C;
        records[1].begin10 = (u32)lbl_80378134;
        records[1].end14 = (u32)lbl_80378134 + lbl_8037813C;
        records[1].begin28 = (u32)lbl_80378134;
        records[1].end2C = (u32)lbl_80378134 + lbl_8037813C;
        lbl_80378148 = 0;
        AIStopDMA();
    }
    u32 frames;
    u32 chunks;
    u32 held;
    Globals* g2; Globals* g = &lbl_801E9D24;
    g->callback->tick(0.0f);
    held = g->callback->pressed(2);
    frames = header.frames;
    while (frames-- != 0 && !reset) {
        if (self->skippable && g->callback->pressed(2) && !held)
            break;
        g2 = g; FrameHeader frameHeader;
        fn_8028C280(self, &frameHeader, 0x14);
        chunks = frameHeader.count08 + frameHeader.count0C;
        while (chunks-- != 0 && !reset) {
            g = g2; signed char state = OSGetResetSwitchState();
            if (lbl_80377FC9 != state) {
                if (!state)
                    reset = 1;
                lbl_80377FC9 = state;
            }
            if (self->skippable) {
                if (g->callback->pressed(2) && !held) {
                    frames = 0;
                    break;
                }
                held = g->callback->pressed(2);
            }
            ChunkHeader chunk;
            fn_8028C280(self, &chunk, 8);
            switch (chunk.type) {
            case 0:
                fn_8028C280(self, audio, chunk.size);
                char* data = audio + 4;
                if (channels) {
                    fn_80295FAC(data, lbl_80378134 + lbl_80378144, channels, chunk.format,
                                *(u32*)audio, &sRecords[(lbl_80378148 + 1) & 1]);
                    u32 i;
                    s16* sample = (s16*)lbl_80378134;
                    for (i = 0; i < *(u32*)audio * channels; i++) {
                        *sample = volume * (float)*sample;
                        sample++;
                    }
                    char* previous = lbl_80378130;
                    lbl_80378130 = lbl_80378134;
                    lbl_80378134 = previous;
                    lbl_80378148 = (lbl_80378148 + 1) & 1;
                    lbl_803780EC = 1;
                    OSSignalSemaphore(sAudioReady);
                    memcpy(&sRecords[(lbl_80378148 + 1) & 1],
                           &sRecords[lbl_80378148], 0x30);
                }
                break;
            case 1:
                fn_8028C280(self, video, chunk.size);
                lbl_80378154 = video + 4;
                lbl_8037814C.type = chunk.type;
                lbl_8037814C.format = chunk.format;
                lbl_8037814C.size = chunk.size;
                lbl_803780E8 = 1;
                OSSignalSemaphore(sVideoReady);
                break;
            }
        }
    }
    OSCancelThread(sVideoThread);
    OSCancelThread(sAudioThread);
    VISetNextFrameBuffer(lbl_803780F8);
    self->black = 0;
    lbl_801E9D24.game->clear(0, 0, 0, 0);
    VISetBlack(1);
    VIFlush();
    VIWaitForRetrace();
    lbl_801E9D24.game->begin();
    lbl_801E9D24.game->end();
    lbl_801E9D24.game->clear(0, 0, 0, 0);
    lbl_801E9D24.game->begin();
    lbl_801E9D24.game->end();
    lbl_801E9D24.game->clear(0, 0, 0, 0);
    lbl_801E9D24.game->begin();
    lbl_801E9D24.game->end();
    self->enabled = 1;
    DVDClose(self->file);
    self->word4C = 0;
    AISetDSPSampleRate(0);
    resetAudio();
    lbl_801E9D24.sound->stop();
    AXQuit();
    lbl_801E9D24.sound->start();
    lbl_801E9D24.sound->setVolume(savedVolume);
    lbl_801E9D24.sound->setMusicVolume(savedMusic);
    VIConfigure((char*)lbl_801E9D24.game + 0x294);
    VIFlush();
    VIWaitForRetrace();
    lbl_801E9D24.game->clear(0, 0, 0, 0);
    VISetBlack(0);
    VIFlush();
    VIWaitForRetrace();
    fn_801EF610(lbl_801EF5C8, video);
    fn_801EF610(lbl_801EF5C8, planes);
    fn_801EF610(lbl_801EF5C8, work);
    fn_801EF610(lbl_801EF5C8, frame);
    fn_801EF610(lbl_801EF5C8, lbl_80378124);
    if (audio) {
        fn_801EF610(lbl_801EF5C8, audio);
        fn_801EF610(lbl_801EF5C8, lbl_80378140);
    }
    self->enabled = 0;
    fn_801FA014(lbl_801E9D24.logger, "Finished playing movie\n");
    ZeroHandle handle;
    handle.word = 0;
    lbl_801E9D24.game->setHandle(&handle);
    fn_801FA014(lbl_801E9D24.logger, "Main renderer set to black");
    if (reset) {
        VISetBlack(1);
        VIFlush();
        VIWaitForRetrace();
        GXDrawDone();
        GXAbortFrame();
        LCDisable();
        DVDCancelAll();
        AXQuit();
        resetAudio();
        lbl_801E9D24.sound->stop();
        __PADDisableRecalibration(0);
        loadBootFile();
        self->black = 1;
        OSResetSystem(0, 0, 0);
    }
    return 1;
}

/* 8028D4CC */
extern "C" void fn_8028D4CC(Movie* self)
{
    if (self->enabled) {
        if (self->paused) {
            VIConfigure(lbl_80378120);
            VIFlush();
            VIWaitForRetrace();
            lbl_803780F0[0] = 1;
            lbl_803780F0[1] = 1;
            VISetBlack(0);
            VIFlush();
            OSResumeThread(sVideoThread);
            self->paused = 0;
        }
    }
    if (self->black)
        VISetBlack(1);
}

/* 8028D560 */
extern "C" unsigned char fn_8028D560(Movie* self)
{
    return self->enabled;
}

/* 8028D568 */
extern "C" void fn_8028D568(Movie* self)
{
    if (self->enabled) {
        if (!self->paused) {
            self->paused = 1;
            fn_801FA014(lbl_801E9D24.logger, "Suspending movie thread 1");
            OSSuspendThread(sVideoThread);
            fn_801FA014(lbl_801E9D24.logger, "Suspending movie thread 2");
            for (int i = 0; i < 2; i++) {
                fill(lbl_803780F8, (u32*)((char*)lbl_803780F8 + lbl_80378104), (u32)0x00800080);
                DCFlushRangeNoSync(lbl_803780F8, lbl_80378104);
                PPCSync();
                VISetNextFrameBuffer(lbl_803780F8);
                VIFlush();
                VIWaitForRetrace();
            }
            fn_801FA014(lbl_801E9D24.logger, "Suspending movie thread 3");
            VIFlush();
            GXDrawDone();
            VIWaitForRetrace();
            fn_801FA014(lbl_801E9D24.logger, "Suspending movie thread 4");
            VIConfigure((char*)lbl_801E9D24.game + 0x294);
            VIFlush();
            VIWaitForRetrace();
            fn_801FA014(lbl_801E9D24.logger, "Suspending movie thread 5");
        }
    }
    if (self->black)
        VISetBlack(0);
}

/* 8028D6FC */
extern "C" void fn_8028D6FC(Movie* self)
{
    if (self->allocation) {
        fn_801EF610(lbl_801EF5C8, self->allocation);
        self->allocation = 0;
    }
    fn_801C9ABC(self);
    if (self->enabled)
        ((MovieDispatch*)self)->slot18();
}

/* 8028D76C */
extern "C" signed char fn_8028D76C(Movie* self)
{
    if (!fn_801C9AC0(self))
        return 0;
    VIGetTvFormat();
    VideoMode* mode = &GXNtsc480Int;
    lbl_80378120 = mode;
    lbl_80378104 = (unsigned short)((((VideoMode*)lbl_80378120)->width + 15) & ~15) * ((VideoMode*)lbl_80378120)->height * 2;
    self->enabled = 0;
    self->black = 0;
    self->word48 = 0;
    self->allocation = fn_801EFA1C(lbl_801EF5C8, 0x60, "Anonymous Alloc", "GCMovie_Z.cpp", 426, 32);
    return 1;
}

/* 8028D814: audio DMA worker thread */
extern "C" void* fn_8028D814(void*)
{
    while (1) {
        OSWaitSemaphore(sAudioReady);
        int pending = lbl_803780EC;
        char* address = lbl_80378130;
        int index = lbl_80378148;
        lbl_80378138 = address;
        if (!pending)
            continue;
        lbl_8037813C = sRecords[index].end04 - (u32)address;
        AIInitDMA((u32)address, lbl_8037813C & ~31UL);
        DCStoreRange(address, lbl_8037813C);
        AIStartDMA();
        lbl_803780EC = 0;
        while (AIGetDMABytesLeft() != 0) {}
        if (lbl_80378134 == lbl_80378138)
            OSSignalSemaphore(sAudioDone);
        lbl_80378138 = 0;
    }
}

/* 8028D8BC: display thread */
extern "C" void* fn_8028D8BC(void*)
{
    Globals* globals = &lbl_801E9D24;
    ChunkHeader* mode;
    int frames = 0;
    mode = &lbl_8037814C;
    while (1) {
        OSWaitSemaphore(sVideoReady);
        switch (mode->format) {
        case 0x10: {
            char* temp = lbl_80378110;
            lbl_80378110 = lbl_8037810C;
            lbl_8037810C = temp;
            fn_802954D0(&sDecoder, lbl_80378154, lbl_80378108, temp);
            temp = lbl_80378108;
            lbl_80378108 = lbl_8037810C;
            lbl_8037810C = temp;
            break;
        }
        case 0x20: {
            char* temp = lbl_8037810C;
            char* other = lbl_80378110;
            lbl_80378110 = temp;
            lbl_8037810C = other;
            fn_802959E0(&sDecoder, lbl_80378154, lbl_80378108, lbl_80378110);
            temp = lbl_80378108;
            lbl_80378108 = lbl_8037810C;
            lbl_8037810C = temp;
            break;
        }
        case 0x30:
            fn_80295A04(&sDecoder, lbl_80378154, lbl_80378108, lbl_80378110, lbl_8037810C);
            break;
        }
        OSSignalSemaphore(sVideoDone);
        if (mode->format != 0x30) {
            lbl_803780F8 = lbl_80378128[lbl_803780FC];
            lbl_803780FC = 1 - lbl_803780FC;
        }
        int index = lbl_803780FC;
        u32* framebuffer = lbl_803780F8;
        lbl_80378114 = lbl_80378108;
        if (((int*)lbl_803780F0)[index]) {
            fill(framebuffer, (u32*)((char*)framebuffer + lbl_80378104), (u32)0x00800080);
            DCFlushRangeNoSync(framebuffer, lbl_80378104);
            lbl_803780F0[index] = 0;
        }
        VideoMode* video = (VideoMode*)lbl_80378120;
        lbl_80378100 = video->width * ((video->height - lbl_8037811C) >> 1) * 2 + ((video->width - lbl_80378118) & ~1UL);
        fn_8028DB38((char*)framebuffer + lbl_80378100, lbl_80378114, lbl_80378118, lbl_8037811C);
        lbl_803780E8 = 0;
        if (frames == 4) {
            globals->movie->black = 0;
            GXSetColorUpdate(0);
            VISetBlack(0);
        }
        lbl_80378158++;
        frames++;
        if (lbl_80378158 != 6) {
            PPCSync();
            VISetNextFrameBuffer(framebuffer);
            lbl_80378114 = 0;
            VIFlush();
        } else {
            lbl_80378158 = 0;
        }
        Callback* callback = globals->callback;
        callback->tick(0.0f);
    }
}
