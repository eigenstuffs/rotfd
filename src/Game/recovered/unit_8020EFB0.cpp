// fn_8020EFB0: DrawRecord 2D draw (vtable __vt__19DrawRecord_802EB0E0 slot 0x40).
// Literal pool .sdata2 0x8037AAF8..0x8037AB0C (0.333f, 1.0f, 0.5f, 0.0f, int->float bias).
typedef unsigned long Word;

struct Node;
struct Render;

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
};

struct Manager { Word unknown00, unknown04; Entry* entries; };

struct Viewport {
    char unknown00[0x48];
    Render* render;
};

struct RenderPrefix { char unknown00[0x278]; };

struct Vec2 {
    float x, y;
    Vec2() {}
    Vec2(float a, float b) : x(a), y(b) {}
};

struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(float a, float b, float c) : x(a), y(b), z(c) {}
};

inline Vec3 operator*(const Vec3& a, float b) { return Vec3(a.x * b, a.y * b, a.z * b); }

struct Handle_800A8204;

struct Render : RenderPrefix {
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1C();
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
    virtual void slot84();
    virtual void slot88();
    virtual void slot8C();
    virtual void slot90();
    virtual void slot94();
    virtual void slot98();
    virtual void slot9C();
    virtual void bind(const Handle_800A8204&);
};

struct Font { char unknown00[12]; };
struct Scope {
    char unknown00[0x24];
    Font* fonts;
};

struct Context {
    char unknown00[0x118];
    Manager* manager;
    char unknown11C[0x30];
    Scope* scope;
};

extern "C" {
extern Context lbl_801E9D24;
void fn_801F86C8(Manager*, const void*, int);
Node* fn_801F7EB8(const Handle_801F7F10*);
}

struct Handle_8001FF78 : Handle_801F7F10 {
    Handle_8001FF78() { word = 0; }
    ~Handle_8001FF78() {}
};

struct Handle_800A8204 : Handle_8001FF78 {
    Handle_800A8204() { word = 0; }
    Handle_800A8204(const Handle_801F7F10& h) {
        word = h.word;
        fn_801F86C8(lbl_801E9D24.manager, &h, 1);
    }
    ~Handle_800A8204() {}
};

struct Texture { char unknown00[0x30]; int width, height; };
struct Material { char unknown00[0x74]; Handle_801F7F10 texture; };
struct Node { char unknown00[0xB8]; Handle_801F7F10 material; };

inline Node* resolve(const Handle_801F7F10& h) {
    int index = h.bits.index;
    Manager* m = lbl_801E9D24.manager;
    int tag = m->entries[index].getTag();
    return tag == h.bits.tag ? m->entries[index].object : 0;
}

struct DrawItem {
    Handle_801F7F10 bitmap;
    Word name;
    char text[128];
    Word actions[4];
    Word actionValues[4];
    unsigned char count, flags;
    char unknownAA[2];
    Vec2 position;
    unsigned char line, unknownB5, font;
    char unknownB7;
    Vec3 start, end;
    float speed;
};

struct DrawRecord {
    char unknown00[0x18];
    signed char visible;
    char unknown19[7];
    int count;
    char unknown24[4];
    DrawItem* items;
};

extern "C" {
int fn_80210374(DrawRecord*, short, char*);
int fn_80261B64(Font*, const char*);
void fn_80261870(Font*, Render*, const char*, int, int, const Vec3&, const Vec3&, float, float);
}

inline Font* getFont(unsigned char f) { return lbl_801E9D24.scope->fonts + f; }
inline Render* getRender(Viewport* v) { return v->render; }
inline void getSize(Texture* t, float s, int& w, int& h) { w = (unsigned int)((float)t->width * s); h = (unsigned int)((float)t->height * s); }
extern "C" void fn_8020EFB0(DrawRecord* self, Viewport* viewport)
{
    if (!self->visible) return;
    Font* font;
    Render* render = getRender(viewport);
    int i;
    for (i = 0; (short)i < self->count; i++) {
        unsigned char flags = self->items[i].flags;
        if (flags & 1) continue;
        float scale = (flags & 2) ? 0.333f : 1.0f;
        font = getFont(self->items[i].font);
        Vec2 pos = self->items[i].position;
        float speed = self->items[i].speed;
        char text[128];
        fn_80210374(self, i, text);
        if (fn_801F7EB8(&self->items[i].bitmap)) {
            DrawItem& item = self->items[i];
            int w, h; getSize((Texture*)resolve(((Material*)resolve(resolve(item.bitmap)->material))->texture), speed, w, h);
            if ((item.flags & 0xC) == 0xC)
                pos.x -= (float)(double)((speed * (float)fn_80261B64(font, text) + (float)w) / 2.0f);
            render->bind(Handle_800A8204(resolve(self->items[i].bitmap)->material));
            {
                Vec2 hi(pos.x + (float)w, pos.y + (float)h);
                Vec2 uvLo(0.0f, 0.0f);
                Vec2 uvHi(1.0f, 1.0f);
                render->draw(pos, hi, uvLo, uvHi, Vec3(1.0f, 1.0f, 1.0f) * scale, Vec3(1.0f, 1.0f, 1.0f) * scale, 1.0f);
            }
            pos.x += (float)(w + 4);
        } else if ((self->items[i].flags & 0xC) == 0xC) {
            pos.x -= speed * (float)fn_80261B64(font, text) / 2.0f;
        }
        fn_80261870(font, render, text, (int)pos.x, (int)pos.y, self->items[i].start * scale,
            self->items[i].end * scale, speed, 1.0f);
    }
}
