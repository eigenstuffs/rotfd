typedef unsigned long Word;

struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float ax, float ay, float az) : x(ax), y(ay), z(az) {}
    Vec3 operator-(const Vec3& o) const { return Vec3(x - o.x, y - o.y, z - o.z); }
    float dot(const Vec3& o) const { return x * o.x + y * o.y + z * o.z; }
};
struct Sphere { Vec3 c; float r; };
struct Matrix { float a[16]; };
struct Owner;
struct Handle { signed int tag : 8; signed int index : 24; Owner* get() const; };
struct Element { Word word; Handle handle; Sphere sphere; };
struct ElementArray { int count, capacity; Element* data;
    const Element& operator[](int i) const;
};
struct Owner {
    char unknown00[0x120];
    Word flags;
    Matrix* local;
    Word getFlags() const;
};
//ORDER
struct Entry { void* object; char unknown04[8]; signed char tag; char unknown0D[3];
    signed char getTag() const { return tag; } };
struct Manager { char unknown00[8]; Entry* entries; };
extern "C" struct Global {
    char unknown00[0x118];
    Manager* manager;
} lbl_801E9D24;
#define DEF_FLAGS inline Word Owner::getFlags() const { return flags; }
#define DEF_OP inline const Element& ElementArray::operator[](int i) const { return data[i]; }
#define DEF_GET inline Owner* Handle::get() const { int index = this->index; Manager* m = lbl_801E9D24.manager; int tag = m->entries[index].getTag(); Owner* r; if (tag == this->tag) r = (Owner*)m->entries[index].object; else r = 0; return r; }
DEF_GET DEF_OP DEF_FLAGS
struct PairOut { Word next; int index[2]; unsigned char flag[2]; char pad0E[2]; Word word[2]; char unknown18[0xC]; Owner* object[2]; char unknown2C[4]; };

extern "C" {
Sphere fn_80099A00(const Matrix*, const Sphere*);
void fn_801F1080(const Matrix*, const Matrix*, Matrix*);
}
inline Matrix product(const Matrix& a, const Matrix& b) { Matrix r; fn_801F1080(&a, &b, &r); return r; }

struct Collider;

inline const Element* elemAt(const ElementArray* arr, int i) { const Element* p; return p = &arr->data[i]; }
extern "C" int fn_8028B03C(Collider* self, const ElementArray* a, const ElementArray* b, const Matrix* m, PairOut* out)
{
    const Element* pa; const Element* pb; Word fb; int count = 0;
    int na = a->count;
    int nb = b->count;
    for (int i = 0; i < na; i++) {
        pa = elemAt(a, i);
        Owner* oa = pa->handle.get();
        Word fa = oa->getFlags();
        if (fa & 0x1000) continue;
        Sphere sa = fn_80099A00(oa->local, &pa->sphere);
        bool flagA = (fa & 0x40000) != 0 ? true : false;
        for (int j = 0; j < nb; j++) {
            pb = elemAt(b, j);
            Owner* ob = pb->handle.get();
            fb = ob->getFlags();
            if (fb & 0x1000) continue;
            Matrix mm = product(*m, *ob->local);
            Sphere sb = fn_80099A00(&mm, &pb->sphere);
            float rs = sa.r + sb.r;
            const Vec3& d = sa.c - sb.c;
            if (d.dot(d) < rs * rs) {
                if (count == 32) return count;
                out->index[0] = i;
                out->flag[0] = flagA;
                out->word[0] = pa->word;
                out->index[1] = j;
                out->flag[1] = (fb & 0x40000) != 0;
                out->word[1] = pb->word;
                out->object[0] = oa;
                out->object[1] = ob;
                out++;
                count++;
            }
        }
    }
    return count;
}
