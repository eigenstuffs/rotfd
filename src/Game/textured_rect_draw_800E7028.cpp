/* fn_800E7028: draws a half-grey textured screen rectangle anchored to the
   viewport's lower-right corner. Partial storage/ABI views only. */
typedef unsigned long Word;

struct Manager;
extern "C" {
extern struct Context { char unknown000[0x118]; Manager* manager; } lbl_801E9D24;
extern char lbl_801EF5C8[];
void fn_801EF610(void*, void*);
void fn_801F86C8(Manager*, const struct Handle_801F7F10*, int);
extern signed char lbl_80377788;
extern const float lbl_80379800; /* 0.0f */
extern const float lbl_80379810; /* 1.0f */
extern const float lbl_80379814; /* 0.5f */
}

struct Handle_801F7F10 {
    union { Word word; struct { signed int tag : 8, index : 24; } bits; };
    Handle_801F7F10();
    ~Handle_801F7F10();
};
struct Handle_8001FF78 : Handle_801F7F10 {
    Handle_8001FF78() { word = 0; }
    ~Handle_8001FF78() {}
    static void operator delete(void* p) throw() { fn_801EF610(lbl_801EF5C8, p); }
};
struct Handle_800A8204 : Handle_8001FF78 {
    Handle_800A8204(const Handle_800A8204& h) { word = h.word; fn_801F86C8(lbl_801E9D24.manager, &h, 1); }
    ~Handle_800A8204() {}
    static void operator delete(void* p) throw() { fn_801EF610(lbl_801EF5C8, p); }
};

/* Resource nodes reached from the owner: target (+0xB8) -> resource (+0x74),
   whose width/height (+0x30/+0x34) size the rectangle. */
struct Node {
    char unknown00[0x30];
    int width, height;
    char unknown38[0x3C];
    Handle_801F7F10 resource;
    char unknown78[0x40];
    Handle_800A8204 target;
};
struct Entry { Node* object; char unknown04[8]; signed char tag; char unknown0D[3]; };
struct Manager { char unknown00[8]; Entry* entries; };
inline Node* resolve(const Handle_801F7F10& h) {
    Entry* e = &lbl_801E9D24.manager->entries[h.bits.index];
    if (e->tag == h.bits.tag) return e->object;
    return 0;
}

/* The owner handle resolves through its own typed manager view. */
struct Owner { char unknown00[0xB8]; Handle_800A8204 target; };
struct OwnerEntry { Owner* object; char unknown04[8]; signed char tag; char unknown0D[3]; };
struct OwnerManager { char unknown00[8]; OwnerEntry* entries; };
inline Owner* resolveOwner(const Handle_801F7F10& h) {
    OwnerEntry* e = &((OwnerManager*)lbl_801E9D24.manager)->entries[h.bits.index];
    if (e->tag == h.bits.tag) return e->object;
    return 0;
}

struct Vec2 { float x, y; void set(float a, float b) { x = a; y = b; } };
struct Color { float x, y, z; };

struct RendererPrefix { char unknown000[0x278]; };
struct Renderer : RendererPrefix {
    virtual void slot08(); virtual void slot0C(); virtual void slot10(); virtual void slot14();
    virtual void slot18(); virtual void slot1C(); virtual void slot20(); virtual void slot24();
    virtual void slot28(); virtual void slot2C(); virtual void slot30(); virtual void slot34();
    virtual void slot38(); virtual void slot3C(); virtual void slot40(); virtual void slot44();
    virtual void slot48(); virtual void slot4C(); virtual void slot50(); virtual void slot54();
    virtual void slot58(); virtual void slot5C(); virtual void slot60(); virtual void slot64();
    virtual void slot68(); virtual void slot6C(); virtual void slot70(); virtual void slot74();
    virtual void slot78();
    virtual void drawRect(const Vec2& minimum, const Vec2& maximum, const Vec2& uvMinimum,
                          const Vec2& uvMaximum, const Color& top, const Color& bottom, float alpha); /* 0x7C */
    virtual void slot80(); virtual void slot84(); virtual void slot88(); virtual void slot8C();
    virtual void slot90(); virtual void slot94(); virtual void slot98(); virtual void slot9C();
    virtual void bindTexture(Handle_800A8204 texture); /* 0xA0 */
};
struct Input { char unknown00[0x48]; Renderer* renderer; };
struct Self {
    char unknown00[0x18];
    signed char enabled;
    char unknown19[0xB];
    Handle_801F7F10 owner;
    float x, y, alpha;
    signed char active;
};

extern "C" void fn_801E2E70(Input*, int* x, int* y, int* width, int* height);

extern "C" void fn_800E7028(Self* self, Input* input) {
    if (!self->enabled || lbl_80377788 || !self->active) return;
    Node* texture = resolve(resolve(resolveOwner(self->owner)->target)->resource);
    int textureWidth = texture->width, textureHeight = texture->height;
    Renderer* renderer = input->renderer;
    int x, y, width, height;
    fn_801E2E70(input, &x, &y, &width, &height);
    Vec2 minimum, maximum;
    Color color;
    Vec2 uvMinimum, uvMaximum;
    uvMinimum.y = uvMinimum.x = lbl_80379800;
    uvMaximum.y = uvMaximum.x = lbl_80379810;
    color.z = color.y = color.x = lbl_80379814;
    int dx = (int)(self->x * width), dy = (int)(self->y * height);
    minimum.set((width - textureWidth) - dx, (height - textureHeight) - dy);
    maximum.set(width - dx, height - dy);
    renderer->bindTexture(resolveOwner(self->owner)->target);
    renderer->drawRect(minimum, maximum, uvMinimum, uvMaximum, color, color, self->alpha);
}
