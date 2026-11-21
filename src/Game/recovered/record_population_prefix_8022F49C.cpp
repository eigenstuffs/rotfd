struct Handle { signed int tag:8; signed int index:24; };
struct Vec3 { float x, y, z; Vec3() {} Vec3(const Vec3& o) : x(o.x), y(o.y), z(o.z) {} };
struct Sphere { Vec3 center; float radius; };
struct Node;
struct Entry { Node* object; int unknown04, unknown08; signed char tag; char unknown0D[3]; };
struct Manager { char unknown00[8]; Entry* entries; };
struct Context { char unknown00[0x118]; Manager* manager; };
struct NodeStorage { char unknown00[8]; };
struct Node : NodeStorage {
    virtual void s08(); virtual void s0C(); virtual void s10(); virtual void s14();
    virtual void s18(); virtual void s1C(); virtual void s20(); virtual void s24();
    virtual void s28(); virtual void s2C(); virtual void s30(); virtual void s34();
    virtual void s38(); virtual void s3C(); virtual void s40(); virtual void s44();
    virtual void s48(); virtual void s4C(); virtual void s50(); virtual void s54();
    virtual void s58(); virtual void s5C(); virtual void s60(); virtual void s64();
    virtual void s68(); virtual void s6C(); virtual void s70(); virtual void s74();
    virtual void s78(); virtual void s7C(); virtual void s80(); virtual void s84();
    virtual void s88(); virtual void s8C(); virtual void s90(); virtual void s94();
    virtual void s98();
    virtual Handle* s9C(int);
    char unknown0C[0x68];
    void* field74;
    char unknown78[0xAC];
    void* field124;
    char unknown128[0x40];
    Handle handle168;
    char unknown16C[0x3C];
    Handle handle1A8;
};
extern "C" {
extern Context lbl_801E9D24;
Sphere fn_80099A00(void*, void*);
void fn_8022ED80(Node*, Vec3*, int);
}
struct EntryB { Node* object; int unknown04, unknown08; signed char tag; char unknown0D[3]; };
struct ManagerB { char unknown00[8]; EntryB* entries; };
static inline Node* resolve(const Handle& h)
{
    int index = h.index; signed char tag = h.tag;
    Entry* e = &(*(Entry**)((char*)lbl_801E9D24.manager + 8))[index];
    if (e->tag == tag) return e->object;
    return 0;
}
static inline Node* resolveB(const Handle& h)
{
    int index = h.index; signed char tag = h.tag;
    EntryB* e = &((ManagerB*)lbl_801E9D24.manager)->entries[index];
    if (e->tag == tag) return e->object;
    return 0;
}
static inline Node* resolveC(const Handle& h)
{
    EntryB* e = &((ManagerB*)lbl_801E9D24.manager)->entries[h.index];
    signed char tag = h.tag;
    if (e->tag == tag) return e->object;
    return 0;
}
extern "C" void fn_8022F49C(Node* self, int arg)
{
    void* p = resolveB(resolve(self->handle1A8)->handle168)->field74;
    if (p) {
        Sphere s = fn_80099A00(resolveB(*resolveC(self->handle1A8)->s9C(0))->field124, p);
        Vec3 v = s.center;
        fn_8022ED80(self, &v, arg);
    }
}
