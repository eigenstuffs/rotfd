/* Segment hit query from a node's position (fn_80269A64): resolves the node
   behind `handle`, casts from its matrix position by `offset`, looks up the
   collision mesh under the start point (fn_80269DE0, any selection) and runs
   the mesh segment test (fn_80242C34) with the collected hit owner.  Handle
   and HandleOwner_8007B3C8 shapes follow camera_capture_owner_update_80236BF4.cpp;
   their inline destructors appear as weak extras that the linker discards. */
typedef unsigned long Word;
struct Handle_801F7F10 { union { Word word; struct { signed int tag : 8, index : 24; } bits; }; Handle_801F7F10(); ~Handle_801F7F10(); };
struct Node;
struct Entry { Node* object; Word unknown04, unknown08; signed char tag; char unknown0D[3]; signed char getTag() const { return tag; } };
struct Manager { int count, capacity; Entry* entries; };
struct Context { char unknown00[0x118]; Manager* manager; };
extern "C" { extern Context lbl_801E9D24; void fn_801F86C8(Manager*, const Handle_801F7F10*, short); }
struct Zero1_9A64 : Handle_801F7F10 { Zero1_9A64() { word = 0; } ~Zero1_9A64() {} };
struct Zero2_9A64 : Zero1_9A64 { Zero2_9A64() { word = 0; } ~Zero2_9A64() {} };
struct Zero3_9A64 : Zero2_9A64 { Zero3_9A64() { word = 0; } ~Zero3_9A64() {} };
struct Zero4_9A64 : Zero3_9A64 { Zero4_9A64() { word = 0; } ~Zero4_9A64() {} };
struct Handle_80075D64 : Zero4_9A64 {
    Handle_80075D64() { word = 0; }
    ~Handle_80075D64() {}
    Handle_80075D64& operator=(const Handle_80075D64& h)
    {
        fn_801F86C8(lbl_801E9D24.manager, this, -1);
        word = h.word;
        fn_801F86C8(lbl_801E9D24.manager, &h, 1);
        return *this;
    }
};
struct Record { char opaque[0x44]; };
extern "C" { void fn_8007B464(void*); void __construct_array(void*, void (*)(void*), void*, Word, Word); }
struct HandleOwner_8007B3C8 {
    int selected; Handle_80075D64 handle; int count; int items[4]; Record records[4];
    HandleOwner_8007B3C8() { __construct_array(records, fn_8007B464, 0, sizeof(Record), 4); selected = -1; handle = Handle_80075D64(); }
    ~HandleOwner_8007B3C8() {}
};
struct VecData { float x, y, z; };
struct Vec : VecData {
    Vec() {}
    Vec(float a, float b, float c) { x = a; y = b; z = c; }
    Vec(const Vec& v) { x = v.x; y = v.y; z = v.z; }
    Vec& operator=(const Vec& v) { x = v.x; y = v.y; z = v.z; return *this; }
    Vec operator+(const Vec& v) const { return Vec(x + v.x, y + v.y, z + v.z); }
};
struct Matrix { float m[4][4]; };
struct Node { char unknown00[0x124]; Matrix* transform; };
struct Query;
inline Node* resolve(const Handle_801F7F10& h)
{
    int index = h.bits.index; Manager* m = lbl_801E9D24.manager;
    int tag = m->entries[index].getTag();
    return tag == h.bits.tag ? m->entries[index].object : 0;
}
extern "C" {
    signed char fn_80269DE0(Node*, const Vec*, HandleOwner_8007B3C8*, Word);
    signed char fn_80242C34(Node*, Vec*, const Vec*, const HandleOwner_8007B3C8*, Query*);
}

extern "C" signed char fn_80269A64(Node* self, const Handle_801F7F10& handle, const Vec* offset, Query* query)
{
    const Vec& p = *(const Vec*)&resolve(handle)->transform->m[3][0];
    Vec start(p.x, p.y, p.z);
    Vec end = start + *offset;
    HandleOwner_8007B3C8 hits;
    if (fn_80269DE0(self, &start, &hits, -1)) return fn_80242C34(resolve(hits.handle), &start, &end, &hits, query);
    return 0;
}
