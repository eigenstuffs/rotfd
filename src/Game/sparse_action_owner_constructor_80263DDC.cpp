/* auto_03_80263DDC_text (s4): EXACT-WEAK-DATA as __ct__26SparseActionOwner_80263DDCFv
 * with the destructor neighbour's flags (engine_sparse_action_owner_destructor.cpp:
 * -O4,p, -Cpp_exceptions off; the target has no extab). Owns .rodata
 * 0x802AEF48..0x802AEFD0 (all seven strings keep their global names). */
/* fn_80263DDC -> __ct__26SparseActionOwner_80263DDCFv: sparse action owner constructor
 * (destructor is fn_80263B08, engine_sparse_action_owner_destructor.cpp).
 *
 * The original translation unit defined its own .rodata string pool
 * (0x802AEF48..0x802AEFD0); the compiler addresses the pool through one base
 * register loaded in the prologue, which only happens for data defined in this
 * file. The four strings other matched units use keep their global names. */
typedef unsigned long u32;

#pragma force_active on
extern "C" const char lbl_802AEF48[] = ".TGAMEOBJ";
extern "C" const char lbl_802AEF54[] = "RemoveObjects not found : %s";
extern "C" const char lbl_802AEF74[] = ".TOTEMBITMAP";
extern "C" const char lbl_802AEF84[] = "LoadObjects already done : %s";
extern "C" const char lbl_802AEFA4[] = "MaterialAnim";
extern "C" const char lbl_802AEFB4[] = "Material";
extern "C" const char lbl_802AEFC0[] = "DefaultLight";
#pragma force_active reset

struct Handle_801F7F10 {
    union {
        u32 value;
        struct { signed int generation : 8, index : 24; } bits;
    };
    Handle_801F7F10();
    ~Handle_801F7F10();
};
struct SparseActionHandle1 : Handle_801F7F10 { SparseActionHandle1() { value = 0; } ~SparseActionHandle1() {} };
struct SparseActionHandle2 : SparseActionHandle1 { SparseActionHandle2() { value = 0; } ~SparseActionHandle2() {} };
struct SparseActionHandle3 : SparseActionHandle2 { SparseActionHandle3() { value = 0; } ~SparseActionHandle3() {} };

struct BitSet_80207EE8 {
    int count, capacity;
    u32* data;
    int bits;
    BitSet_80207EE8();
    ~BitSet_80207EE8();
};
struct WorldHandleArray_801E55C4 {
    char unknown[576];
    WorldHandleArray_801E55C4();
    ~WorldHandleArray_801E55C4();
};

struct Vec3 {
    float x, y, z;
    Vec3(float a, float b, float c) : x(a), y(b), z(c) {}
};
struct Prefix { char bytes[8]; };
struct SceneObject : Prefix {
    virtual void slot08(); virtual void slot0C(); virtual void slot10(); virtual void slot14();
    virtual void slot18(); virtual void slot1C(); virtual void slot20(); virtual void slot24();
    virtual void slot28(); virtual void slot2C(); virtual void slot30();
    virtual void setPosition(const Vec3&);
    inline void clearPosition();
    char unknown0C[0xAC];
    SparseActionHandle2 linked;
};

struct Entry { SceneObject* object; char pad[8]; signed char generation; char tail[3]; };
struct Manager { int count, capacity; Entry* entries; };
struct Global { char pad[0x118]; Manager* manager; };
struct Name { u32 value; Name(const char*); };

extern "C" {
extern Global lbl_801E9D24;
extern const char lbl_8037B5E8[6];
extern const float lbl_8037B5F0;
void fn_801F86C8(Manager*, const void*, int);
Handle_801F7F10 fn_801B52EC(Manager*, const char*);
Handle_801F7F10 fn_801B550C(Manager*, const Name&, const Name&);
u32 fn_801F948C(void*, const char*);
}

inline void SceneObject::clearPosition() { setPosition(Vec3(lbl_8037B5F0, lbl_8037B5F0, lbl_8037B5F0)); }
inline Name::Name(const char* s) { value = fn_801F948C(this, s); }

struct HandleCopy1 : SparseActionHandle1 {
    HandleCopy1(const Handle_801F7F10& h) { value = h.value; fn_801F86C8(lbl_801E9D24.manager, &h, 1); }
};
struct HandleCopy2 : SparseActionHandle2 {
    HandleCopy2(const Handle_801F7F10& h) { value = h.value; fn_801F86C8(lbl_801E9D24.manager, &h, 1); }
};
inline void assign(Handle_801F7F10& to, const Handle_801F7F10& from)
{
    fn_801F86C8(lbl_801E9D24.manager, &to, -1);
    to.value = from.value;
    fn_801F86C8(lbl_801E9D24.manager, &from, 1);
}
inline SceneObject* resolve(const Handle_801F7F10& h)
{
    Entry* e = lbl_801E9D24.manager->entries + h.bits.index;
    return e->generation == h.bits.generation ? e->object : 0;
}
inline SceneObject* resolveBytes(const Handle_801F7F10& h)
{
    int index = h.bits.index;
    char* table = (char*)lbl_801E9D24.manager->entries;
    signed char generation = *(signed char*)(table + index * 16 + 12);
    Entry* entry = (Entry*)(table + index * 16);
    return generation == h.bits.generation ? entry->object : 0;
}

template<class T> struct SparseActionArray {
    int count, capacity;
    T* data;
    SparseActionArray() : count(0), capacity(0), data(0) {}
};
struct SparseActionRecord { u32 word; SparseActionHandle2 handle; u32 other; };
struct SparseActionRecords {
    int count, capacity;
    SparseActionRecord* data;
    SparseActionRecords() : count(0), capacity(0), data(0) {}
};
struct SparseActionPool : SparseActionRecords {
    BitSet_80207EE8 occupied;
    int limit, used;
    SparseActionPool() : limit(0), used(0) {}
};

struct SparseActionOwner_80263DDC {
    SparseActionArray<SparseActionHandle2> first, second;
    SparseActionHandle2 scalar;
    SparseActionPool records;
    WorldHandleArray_801E55C4 fixed;
    SparseActionHandle2 h280, h284, h288;
    SparseActionHandle3 h28C;
    SparseActionOwner_80263DDC();
};

SparseActionOwner_80263DDC::SparseActionOwner_80263DDC()
{
    assign(h288, HandleCopy1(fn_801B52EC(lbl_801E9D24.manager, lbl_802AEFA4)));
    assign(h284, HandleCopy1(fn_801B52EC(lbl_801E9D24.manager, lbl_802AEFB4)));
    SceneObject* actor = resolve(h288);
    assign(actor->linked, h284);
    assign(h28C, HandleCopy2(fn_801B550C(lbl_801E9D24.manager, Name(lbl_8037B5E8), Name(lbl_802AEFC0))));
    resolveBytes(h28C)->clearPosition();
}
