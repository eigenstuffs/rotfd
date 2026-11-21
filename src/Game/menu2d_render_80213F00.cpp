// fn_80213F00: 2D menu render (one original translation unit with its
// literal pool 0x8037AC58..0x8037AC78). The text helper fn_80216150 is
// declared with a short index, matching the original call sequence
// (extsh at the call); the matched definition reads the register as int.
// Menu2D backdrop and visible-entry rendering. Native body: 80213F00..80214544.
// Own original translation unit: its literal pool is .sdata2 8037AC58..8037AC78
// (0.5f, 0.0f, 1.3f, 1.0f, 1.2f, 4-byte gap, signed int->float bias).
typedef unsigned long Word;

struct Node;
struct Manager;
struct Render;
struct Handle_800A8204;

struct Bits { signed long tag:8, index:24; };

struct Handle_801F7F10 {
    union { Word word; Bits bits; };
    Handle_801F7F10();
    ~Handle_801F7F10();
};

struct Entry {
    Node* object;
    Word unknown04, unknown08;
    signed char tag;
    char unknown0D[3];
    signed char getTag() const { return tag; }
    Node* getObject() const { return object; }
};

struct Manager { Word unknown00, unknown04; Entry* entries; };

struct Viewport {
    char unknown00[0x48];
    Render* render;
    Render* getRender() const { return render; }
};

struct RenderPrefix { char unknown00[0x278]; };

struct Vec2 {
    float x, y;
    Vec2() {}
    Vec2(float a, float b) : x(a), y(b) {}
    Vec2 operator*(float b) const { return Vec2(x * b, y * b); }
};

struct Vec3 { float x, y, z; Vec3(float a, float b, float c) : x(a), y(b), z(c) {} };

struct Vec4 { float x, y, z, w; Vec4(float a, float b, float c, float d) : x(a), y(b), z(c), w(d) {} };

struct Render : RenderPrefix {
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void finish18();
    virtual void finish1C();
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
    virtual void slot6C();
    virtual void slot70();
    virtual void slot74();
    virtual void slot78();
    virtual void draw(const Vec2&, const Vec2&, const Vec2&, const Vec2&, const Vec3&, const Vec3&, float);
    virtual void slot80();
    virtual void fill(const Vec2&, const Vec2&, const Vec4&, float);
    virtual void draw88(const Vec2&, const Vec2&, const Vec2&, const Vec2&, const Vec3&, float);
    virtual void slot8C();
    virtual void slot90();
    virtual void slot94();
    virtual void slot98();
    virtual void slot9C();
    virtual void bind(const Handle_800A8204&);
};

struct Context {
    char unknown00[0x114];
    Render* render;
    Manager* manager;
    char unknown11C[0x30];
    void* scope;
};

extern "C" {
extern Context lbl_801E9D24;
extern char lbl_801EF5C8[];
void fn_801EF610(void*, void*);
void fn_801F86C8(Manager*, const void*, int);
Node* fn_801F7EB8(const Handle_801F7F10*);
void fn_801E2E70(Viewport*, int*, int*, int*, int*);
}

struct Handle_8001FF78 : Handle_801F7F10 {
    Handle_8001FF78() { word = 0; }
    ~Handle_8001FF78() {}
    static void operator delete(void* p) throw() { fn_801EF610(lbl_801EF5C8, p); }
};

struct Handle_800A8204 : Handle_8001FF78 {
    Handle_800A8204() { word = 0; }
    Handle_800A8204(const Handle_801F7F10& h) {
        word = h.word;
        fn_801F86C8(lbl_801E9D24.manager, &h, 1);
    }
    ~Handle_800A8204() {}
    static void operator delete(void* p) throw() { fn_801EF610(lbl_801EF5C8, p); }
};

struct Node { char unknown00[0xB8]; Handle_801F7F10 materialB8; };

inline Node* resolve(const Handle_801F7F10& h) {
    int index = h.bits.index;
    Manager* m = lbl_801E9D24.manager;
    int tag = m->entries[index].getTag();
    return tag == h.bits.tag ? m->entries[index].object : 0;
}

struct Font { char unknown00[12]; };
struct Scope {
    char unknown00[0x24];
    Font* fonts;
    Font* getFont(int i) { return fonts + i; }
};

struct MenuEntry {
    char unknown00[0x8C];
    unsigned short flags;
    char unknown8E[0xB4 - 0x8E];
    Vec2 position;
    const unsigned short& getFlags() const { return flags; }
};

struct Menu {
    char unknown00[0x28];
    short selected;
    short unknown2A;
    short start;
    char unknown2E[0x46 - 0x2E];
    unsigned short count;
    char unknown48[0x54 - 0x48];
    Vec2 lo, hi;
    float opacity;
    char unknown68[8];
    MenuEntry* entries;
    Handle_801F7F10 resource;
    char unknown78[4];
    unsigned char fontIndex;
    char unknown7D[3];
    Vec3 normal, disabledA, disabledB, selectedA, selectedB;
    Vec4 backdrop;
    MenuEntry& getEntry(int i) { return entries[i]; }
};

extern "C" {
// The caller-side prototype takes a short index: the native caller sign-extends
// the loop counter in the argument setup (extsh r4 directly before the call),
// exactly as for a short parameter. The provider (menu2d_item_text.cpp) reads
// the register as int, so both views are ABI-compatible.
int fn_80216150(Menu*, short, char*);
int fn_80261B64(Font*, const char*);
void fn_80261870(Font*, Render*, const char*, int, int, const Vec3&, const Vec3&, float, float);
}

inline Vec2 operator+(const Vec2& a, const Vec2& b) { return Vec2(a.x + b.x, a.y + b.y); }

inline Vec3 operator*(const Vec3& a, float b) { return Vec3(a.x * b, a.y * b, a.z * b); }

extern "C" void fn_80213F00(Menu* self, Viewport* viewport) {
    Render* render = viewport->getRender();

    if (fn_801F7EB8(&self->resource)) {
        Vec2 center = (self->lo + self->hi) * 0.5f;

        int x, y, width, height;
        fn_801E2E70(viewport, &x, &y, &width, &height);

        render->bind(Handle_800A8204());

        {
            Vec2 origin(0.0f, 0.0f);
            Vec2 size((float)width, (float)height);
            Vec4 color(self->backdrop);
            render->fill(origin, size, color, 1.3f);
        }
        render->bind(Handle_800A8204(resolve(self->resource)->materialB8));

        {
            Vec2 hi(1.0f + center.x, 1.0f + center.y);
            Vec2 uvLo(0.0f, 0.0f);
            Vec2 uvHi(1.0f, 1.0f);
            Vec3 color(1.0f, 1.0f, 1.0f);
            render->draw88(self->lo, hi, uvLo, uvHi, color, 1.2f);
        }
        {
            Vec2 lo(center.x, self->lo.y);
            Vec2 hi(self->hi.x, center.y);
            Vec2 uvLo(1.0f, 0.0f);
            Vec2 uvHi(0.0f, 1.0f);
            Vec3 color(1.0f, 1.0f, 1.0f);
            render->draw88(lo, hi, uvLo, uvHi, color, 1.2f);
        }
        {
            Vec2 lo(self->lo.x, center.y);
            Vec2 hi(center.x, self->hi.y);
            Vec2 uvLo(0.0f, 1.0f);
            Vec2 uvHi(1.0f, 0.0f);
            Vec3 color(1.0f, 1.0f, 1.0f);
            render->draw88(lo, hi, uvLo, uvHi, color, 1.2f);
        }
        {
            Vec2 lo(center.x - 1.0f, center.y - 1.0f);
            Vec2 hi(self->hi);
            Vec2 uvLo(1.0f, 1.0f);
            Vec2 uvHi(0.0f, 0.0f);
            Vec3 color(1.0f, 1.0f, 1.0f);
            render->draw88(lo, hi, uvLo, uvHi, color, 1.2f);
        }
    }
    Font* font = ((Scope*)lbl_801E9D24.scope)->getFont(self->fontIndex);

    for (int i = self->start; (short)i < self->start + self->count; ++i) {
        if (!(self->getEntry(i).getFlags() & 2)) {
            unsigned char flags = self->getEntry(i).getFlags();

            char text[128];
            fn_80216150(self, i, text);

            const Vec2& position = self->getEntry(i).position;
            float x = position.x, y = position.y;

            if ((flags & 0x18) == 0x18) x -= (float)fn_80261B64(font, text) / 2.0f;
            else if (flags & 0x10) x -= (float)fn_80261B64(font, text);

            if (self->getEntry(i).getFlags() & 4) {
                Vec3 first = self->disabledA * 0.5f;
                Vec3 second = self->disabledB * 0.5f;
                fn_80261870(font, render, text, (int)x, (int)y, first, second, 1.0f, self->opacity);
            } else if (self->selected == (short)i && (self->getEntry(i).getFlags() & 1))
                fn_80261870(font, render, text, (int)x, (int)y, self->selectedA, self->selectedB, 1.0f, self->opacity);
            else if (flags & 0x40)
                fn_80261870(font, render, text, (int)x, (int)y, self->normal, self->normal, 1.0f, self->opacity);
            else
                fn_80261870(font, render, text, (int)x, (int)y, self->normal, self->normal, 1.0f, self->opacity);
        }
    }
    render->bind(Handle_800A8204());
}
