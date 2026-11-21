/* fn_8023BB18 -> __ct__27PlatformAudioOwner_8023BB18Fv: platform audio track
 * owner constructor (real C++ constructor; the inlined RegistryBase base
 * constructor keeps the two `this` copies that no extern "C" function
 * reproduces). Owns its TU's .rodata string pool, whose base the compiler
 * loads at function entry. */
typedef unsigned long u32;

/* The translation unit's .rodata string pool (0x802AEAA0..0x802AEAF1). The
 * first two strings belong to stripped code; MeshData is also used by
 * named_handle_key_transfer.cpp. */
#pragma force_active on
extern "C" const char lbl_802AEAA0[] __attribute__((aligned(8))) = "%s\\%s.txt";
extern "C" const char lbl_802AEAAC[] = "BeginDefinitions";
extern "C" const char lbl_802AEAC0[] = "PlayMUsic";
extern "C" const char lbl_802AEACC[] = " MusicName";
extern "C" const char lbl_802AEAD8[] = "StopMUsic";
extern "C" const char lbl_802AEAE8[] __attribute__((aligned(8))) = "MeshData";
#pragma force_active reset
#define OWNER PlatformAudioOwner_8023BB18
struct Console;
struct Manager;
extern "C" {
extern const char lbl_802EAA98[], lbl_802EC030[];
void fn_80208830(void*, int);
void __ct__21TripleRecord_8023BD78Fv(void*);
void fn_8020B860(void*, int);
void __construct_array(void*, void (*)(void*), void (*)(void*, int), unsigned long, unsigned long);
void fn_801F86C8(Manager*, const void*, short);
typedef signed char (*ConsoleCallback)();
void fn_801FAC64(Console*, const char*, ConsoleCallback, const char*);
signed char fn_8023ADB8();
signed char fn_8023AE38();
}
struct Globals { char unknown00[0x110]; Console* console; char unknown114[4]; Manager* manager; };
extern "C" Globals lbl_801E9D24;

struct Handle_801F7F10 {
    u32 value;
    Handle_801F7F10();
    ~Handle_801F7F10();
};
struct OwnerHandle : Handle_801F7F10 {
    OwnerHandle() { value = 0; }
    OwnerHandle& operator=(const OwnerHandle& h)
    {
        fn_801F86C8(lbl_801E9D24.manager, this, -1);
        value = h.value;
        fn_801F86C8(lbl_801E9D24.manager, &h, 1);
        return *this;
    }
};
struct TrackHandle {
    u32 value;
    TrackHandle& operator=(const Handle_801F7F10& h)
    {
        fn_801F86C8(lbl_801E9D24.manager, this, -1);
        value = h.value;
        fn_801F86C8(lbl_801E9D24.manager, &h, 1);
        return *this;
    }
};
struct Track {
    TrackHandle owner, first, second;
    u32 unknown0C;
    float timer;
    signed char running;
    char unknown15[3];
    u32 unknown18;
};

struct WordArray { int count, capacity; u32* data; };
struct BitSet_80207EE8 : WordArray {
    int bits;
    BitSet_80207EE8();
    ~BitSet_80207EE8();
};
template<class T> struct StorageC { int size, capacity; T* data; StorageC() : size(0), capacity(0), data(0) {} };
template<class T> struct PoolC : StorageC<T> { BitSet_80207EE8 flags; int limit, count; PoolC() : limit(0), count(0) {} ~PoolC(); };
struct HashTable { int cursor, capacity, count; void** slots; };
struct RegistryRoot {
    int cursor, capacity, count; void** slots;
    RegistryRoot(const void* vtable, int size) { ((const void**)this)[0x7c / 4] = vtable; fn_80208830(this, size); }
};
struct RegistryBaseC {
    RegistryRoot root; PoolC<u32> first, second; PoolC<HashTable> tables; const void* vtable;
    RegistryBaseC() : root(lbl_802EAA98, 0x40) {}
    ~RegistryBaseC();
};

struct OWNER : RegistryBaseC {
    Track tracks[32];
    int start;
    u32 unknown404;
    u32 flags;
    OWNER();
};

OWNER::OWNER()
{
    vtable = lbl_802EC030;
    __construct_array(tracks, __ct__21TripleRecord_8023BD78Fv, fn_8020B860, sizeof(Track), 32);
    fn_801FAC64(lbl_801E9D24.console, lbl_802AEAC0, fn_8023AE38, lbl_802AEACC);
    fn_801FAC64(lbl_801E9D24.console, lbl_802AEAD8, fn_8023ADB8, lbl_802AEACC);
    for (int i = 0; i < 32; ++i) {
        tracks[i].unknown18 = 0;
        tracks[i].running = 0;
        { OwnerHandle empty; empty.value = 0; tracks[i].owner = empty; }
        { OwnerHandle empty; empty.value = 0; tracks[i].first = empty; }
        { OwnerHandle empty; empty.value = 0; tracks[i].second = empty; }
    }
    start = 0;
    flags = 0;
}
