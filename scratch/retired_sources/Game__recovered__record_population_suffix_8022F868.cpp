typedef unsigned long u32;
struct Manager;
struct Context { char unknown00[0x118]; Manager* manager; };
extern "C" { extern Context lbl_801E9D24; void fn_801F86C8(Manager*, const void*, short); }
struct PodHandle { struct { signed int tag : 8; signed int index : 24; } bits; };
struct Handle_801F7F10 {
    union {
        u32 value;
        struct { signed int tag : 8; signed int index : 24; } bits;
    };
    Handle_801F7F10();
    ~Handle_801F7F10();
};
struct Handle1 : Handle_801F7F10 { Handle1() { value = 0; } ~Handle1() {} };
struct Handle2 : Handle1 { Handle2() { value = 0; } ~Handle2() {} };
struct HandleCopy : Handle2 {
    HandleCopy(const PodHandle& input) { value = *(const u32*)&input; fn_801F86C8(lbl_801E9D24.manager, &input, 1); }
    ~HandleCopy() {}
};
typedef PodHandle Handle;
struct Vec3 { float x, y, z; };
struct Sphere { float x, y, z, radius;
    Sphere() {}
    Sphere(const Sphere& o) : x(o.x), y(o.y), z(o.z), radius(o.radius) {}
    Sphere& operator=(const Sphere& o) { x = o.x; y = o.y; z = o.z; radius = o.radius; return *this; }
};
struct Matrix { float m[16]; };
struct Node;
struct Entry { Node* object; int unknown04, unknown08; signed char tag; char unknown0D[3]; };
struct Manager { char unknown00[8]; Entry* entries; };
struct NodeStorage { char unknown00[8]; };
struct Node : NodeStorage {
    virtual void s08(); virtual void s0C(); virtual void s10(); virtual void s14();
    virtual void s18(); virtual void s1C(); virtual void s20(); virtual void s24();
    virtual void s28(); virtual void s2C(); virtual void s30(); virtual void s34();
    virtual signed char s38(Node*, int, int);
    virtual Sphere* s3C();
    virtual void s40(); virtual void s44();
    virtual void s48(); virtual void s4C(); virtual void s50(); virtual void s54();
    virtual void s58(); virtual void s5C(); virtual void s60(); virtual void s64();
    virtual void s68(); virtual void s6C(); virtual void s70(); virtual void s74();
    virtual void s78(); virtual void s7C(); virtual void s80(); virtual void s84();
    virtual void s88(); virtual void s8C();
    virtual int s90();
    virtual int s94(int);
    virtual void s98();
    virtual Handle* s9C(int);
    char unknown0C[0x24];
    unsigned long long flags30;
    char unknown38[0x34];
    Handle* array6C;
    char unknown70[0x18];
    Handle* array88;
    char unknown8C[0x3C];
    Handle* fieldC8;
    char unknownCC[0x58];
    Matrix* field124;
    char unknown128[0x40];
    Handle handle168;
    Handle handle16C;
    char unknown170[0x38];
    Handle handle1A8;
    char unknown1AC[0x20];
    int* array1CC;
};
extern "C" {
Sphere fn_80099A00(const Matrix*, const Sphere*);
Sphere fn_801F0A20(const Sphere&, const Sphere&);
void fn_801F1080(const Matrix*, const Matrix*, Matrix*);
}
struct EntryB { Node* object; int unknown04, unknown08; signed char tag; char unknown0D[3]; };
struct ManagerB { char unknown00[8]; EntryB* entries; };
static inline Node* resolve(const Handle& h)
{
    Entry* e = &lbl_801E9D24.manager->entries[h.bits.index];
    if (e->tag == h.bits.tag) return e->object;
    return 0;
}
static inline Node* resolveA(const Handle& h)
{
    int index = h.bits.index; signed char tag = h.bits.tag;
    Entry* e = &(*(Entry**)((char*)lbl_801E9D24.manager + 8))[index];
    if (e->tag == tag) return e->object;
    return 0;
}
static inline Node* resolveB(const Handle& h)
{
    int index = h.bits.index; signed char tag = h.bits.tag;
    EntryB* e = &((ManagerB*)lbl_801E9D24.manager)->entries[index];
    if (e->tag == tag) return e->object;
    return 0;
}
static inline Node* resolveC(const Handle& h)
{
    EntryB* e = &((ManagerB*)lbl_801E9D24.manager)->entries[h.bits.index];
    signed char tag = h.bits.tag;
    if (e->tag == tag) return e->object;
    return 0;
}
static inline Node* resolveD(const Handle& h)
{
    EntryB* e = &((ManagerB*)lbl_801E9D24.manager)->entries[h.bits.index];
    if (e->tag == h.bits.tag) return e->object;
    return 0;
}

/* first owner lookup: entries pointer and result share one variable (forces the
   entries reload at the next lookup, as in the original) */
static inline Node* resolveQ(const Handle& h){ int index=h.bits.index; signed char tag=h.bits.tag; void* r=lbl_801E9D24.manager->entries; Entry* e=(Entry*)r+index; if(e->tag==tag) r=e->object; else r=0; return (Node*)r; }
static inline Matrix product(const Matrix* a, const Matrix* b) { Matrix r; fn_801F1080(a, b, &r); return r; }
extern "C" int fn_8022F868(Node* self, Sphere* out)
{
    int i = self->s90();
    if (i < 0) return 0;
    Node* a = resolve(*(const Handle*)&(const Handle_801F7F10&)HandleCopy(*resolveD(resolve(self->handle1A8)->handle168)->fieldC8));
    Node* c = resolveB(resolveQ(self->handle1A8)->handle16C);
    Node* d = resolveB(*resolveC(self->handle1A8)->s9C(0));
    signed char first = 1;
    for (; i >= 0; i = self->s94(i)) {
        Node* n = resolve(*self->s9C(i));
        Matrix m = product(d->field124, n->field124);
        int k = self->array1CC[i];
        Node* child = resolveA(c->array6C[k]);
        if (first) {
            *out = fn_80099A00(&m, (Sphere*)((char*)resolve(a->array88[k]) + 0xC));
        } else {
            *out = fn_801F0A20(fn_80099A00(&m, (Sphere*)((char*)resolve(a->array88[k]) + 0xC)), *out);
        }
        if (self->flags30 & 0x2000) {
            if (child->s38(n, 0, 0)) {
                *out = fn_801F0A20(fn_80099A00(&m, child->s3C()), *out);
            }
        }
        first = 0;
    }
    return 1;
}
