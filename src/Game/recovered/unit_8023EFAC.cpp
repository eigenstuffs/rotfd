typedef unsigned long u32;
struct Manager;
struct Node;
struct Entry { Node* object; int unknown04, unknown08; signed char tag; char unknown0D[3]; };
struct Manager { char unknown00[8]; Entry* entries; };
struct Context { char unknown00[0x118]; Manager* manager; };
extern "C" {
extern Context lbl_801E9D24;
extern char lbl_8028F698[];
void fn_801F86C8(Manager*, const void*, short);
void* fn_8028FAF4(void*, void*, u32, u32);
void* fn_8028FF24(void*, u32);
void fn_8028FD50(void*, void*, u32);
void* fn_8023F660(u32, void*);
}
inline void* operator new(u32, void* p) { return p; }
inline void* operator new(u32 n, void* p, int) { return fn_8023F660(n, p); }
struct RawHandle { signed int tag : 8; signed int index : 24; };
struct Handle_801F7F10 { u32 value; Handle_801F7F10(); ~Handle_801F7F10(); };
struct Handle0 : Handle_801F7F10 { Handle0() { value = 0; } };
struct Handle1 : Handle0 {
    Handle1(const Handle_801F7F10& h) { value = h.value; fn_801F86C8(lbl_801E9D24.manager, &h, 1); }
    void assign(const Handle_801F7F10& h) { value = h.value; fn_801F86C8(lbl_801E9D24.manager, &h, 1); }
    static void addRef(const Handle_801F7F10* h) { fn_801F86C8(lbl_801E9D24.manager, h, 1); }
    Handle1(const Handle1& h) { value = h.value; fn_801F86C8(lbl_801E9D24.manager, &h, 1); }
};
struct Handle_8001FF78 { u32 value; Handle_8001FF78(); ~Handle_8001FF78(); };
struct HandleCopy_8023F5EC : Handle_8001FF78 {
    HandleCopy_8023F5EC(const Handle_8001FF78& h, int) { value = h.value; fn_801F86C8(lbl_801E9D24.manager, &h, 1); }
    HandleCopy_8023F5EC(const HandleCopy_8023F5EC&);
};
struct Handle_80020B90 { u32 value; ~Handle_80020B90(); };
struct HandleCopy_8023F578 { u32 value; HandleCopy_8023F578(const HandleCopy_8023F578&); };
struct Link { char unknown00[0x10]; RawHandle handle10; u32 unknown14; RawHandle handle18; };
struct Node { u32 unknown00; Handle_801F7F10 handle04; char unknown08[8]; RawHandle handle10; u32 unknown14; RawHandle handle18; };
struct HandleArray { int size, capacity; Handle1* data; Handle1* data2() { return data; } Handle1* next() { return &data[size++]; } };
extern "C" {
Handle_8001FF78* fn_8023F73C(void*);
void fn_8023F668(HandleArray*, int);
void fn_8023F45C(HandleArray*, const HandleCopy_8023F578&);
Link* fn_8023C2DC(Manager*, const RawHandle*);
Node* fn_8023C1C8(const RawHandle*);
void fn_8023EFAC(const Node* self, HandleArray* out);
}
static inline Node* resolve(const RawHandle& h)
{
    Entry* e = &lbl_801E9D24.manager->entries[h.index];
    if (e->tag == h.tag) return e->object;
    return 0;
}
static inline void reserve(HandleArray* a, int n)
{
    if (n) {
        if (a->data) a->data = (Handle1*)fn_8028FAF4(lbl_8028F698, a->data, a->capacity * 4, n * 4);
        else a->data = (Handle1*)fn_8028FF24(lbl_8028F698, n * 4);
    } else if (a->data) {
        fn_8028FD50(lbl_8028F698, a->data, a->capacity * 4);
        a->data = 0;
    }
}
static inline void walkLink(Link* link, HandleArray* out)
{
    if (link) {
        { HandleCopy_8023F578 t(*(HandleCopy_8023F578*)fn_8023F73C(link)); fn_8023F45C(out, t); ((Handle_80020B90*)&t)->~Handle_80020B90(); }
        Node* n = fn_8023C1C8(&link->handle10);
        if (n) fn_8023EFAC(n, out);
        n = fn_8023C1C8(&link->handle18);
        if (n) fn_8023EFAC(n, out);
    }
}
static inline void walkChild(Node* child, HandleArray* out)
{
    if (child) {
        {
            HandleCopy_8023F5EC tmp(*fn_8023F73C(child), 0);
            if (out->size + 1 > out->capacity) {
                fn_8023F668(out, out->capacity + 0x20);
                out->capacity += 0x20;
            }
            Handle1* d = out->data; int i = out->size++; new (&d[i], 0) HandleCopy_8023F5EC(tmp);
        }
        walkLink(fn_8023C2DC(lbl_801E9D24.manager, &child->handle10), out);
        walkLink(fn_8023C2DC(lbl_801E9D24.manager, &child->handle18), out);
    }
}
static inline const Handle_801F7F10* getHandle(Node* n) { return &n->handle04; }
static inline const Handle_801F7F10& getHandleRef(Node* n) { return n->handle04; }
extern "C" void fn_8023EFAC(const Node* self, HandleArray* out)
{
    {
        const Handle_801F7F10& src = self->handle04; Handle1 tmp(src);
        if (out->size + 1 > out->capacity) {
            reserve(out, out->capacity + 0x20);
            out->capacity += 0x20;
        }
        new (&out->data[out->size++]) Handle1(tmp);
    }
    walkChild(resolve(self->handle10), out);
    walkChild(resolve(self->handle18), out);
}
