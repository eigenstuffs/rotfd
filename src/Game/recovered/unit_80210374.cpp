// Unit auto_03_80210374_text: DrawRecord text formatting (fn_80210374) and
// layout (fn_80210444, vtable __vt__19DrawRecord_802EB0E0 slot 0x44).
// Data: lbl_802AE4D0 / lbl_802AE4F4 are the zero initialisers of the local
// alignment tables; .sdata2 lbl_8037ABE0 (100.0f), lbl_8037ABE8 (signed bias),
// lbl_8037ABF0 (unsigned bias).
struct Handle { signed int tag:8; signed int index:24; };
struct Node {
    char unknown00[8];
    virtual void s08(); virtual void s0C(); virtual void s10(); virtual void s14();
    virtual void s18(); virtual void s1C(); virtual void s20(); virtual void s24();
    virtual void s28(); virtual void s2C(); virtual void s30(); virtual void s34();
    virtual void s38(); virtual void s3C(); virtual void s40(); virtual void s44();
    virtual void s48(); virtual void s4C(); virtual void s50(); virtual void s54();
    virtual void s58(); virtual void s5C(); virtual void s60(); virtual void s64();
    virtual void s68(); virtual void s6C();
    virtual int s70(void*, void*);
};
struct Entry { Node* object; int unknown04, unknown08; signed char tag; char unknown0D[3]; };
struct Manager { char unknown00[8]; Entry* entries; };
struct FontInfo { int height; };
struct Font { char unknown00[8]; FontInfo* info; };
struct Scope { char unknown00[0x24]; Font* fonts; };
struct Viewport { char unknown00[0x4C]; };
struct Context {
    char unknown00[0x114];
    Viewport* viewports;
    Manager* manager;
    char unknown11C[0x30];
    Scope* scope;
};
struct Vec2 { float x, y; };
struct Record {
    Handle bitmap;
    int field04;
    char field08[0x80];
    int items88[4];
    int results98[4];
    unsigned char countA8;
    unsigned char flags;
    char unknownAA[2];
    Vec2 pos;
    unsigned char line, column, font;
    char unknownB7[0x19];
    float speed;
};
struct Self {
    char unknown00[0x20];
    int count;
    char unknown24[4];
    Record* records;
    int viewport;
    Handle handle30;
};
struct Texture { char unknown00[0x30]; int width, height; };
struct Material { char unknown00[0x74]; Handle texture; };
struct Bitmap { char unknown00[0xB8]; Handle material; };
struct Grid { unsigned int v[3][3]; };
struct Groups { int v[16]; };
extern "C" {
extern Context lbl_801E9D24;
extern const Grid lbl_802AE4D0;
extern const Groups lbl_802AE4F4;
void fn_801F44DC(void*, void*, void*);
void fn_801E2E70(Viewport*, int*, int*, int*, int*);
void* fn_801F7EB8(const Handle*);
int fn_80261B64(Font*, const char*);
}
static inline Node* resolve(const Handle& h)
{
    Context* context = &lbl_801E9D24;
    Entry* e = &context->manager->entries[h.index];
    if (e->tag == h.tag) return e->object;
    return 0;
}
static inline void* lookup(const Handle& h)
{
    int index = h.index;
    Manager* m = lbl_801E9D24.manager;
    int tag = m->entries[index].tag;
    return tag == h.tag ? m->entries[index].object : 0;
}
static inline Record* rec2(Self* self, int index) { index = index; return (Record*)((char*)self->records + index * sizeof(Record)); }
static inline int fh(Font* f) { int h = f->info->height; h = h; return h; }
static inline Viewport* getViewport(Context* c, int idx) { return &c->viewports[idx]; }
static inline Record* rec(Self* self, int index) { return (Record*)((char*)self->records + index * sizeof(Record)); }
extern "C" void fn_80210374(Self* self, int index, void* out)
{
    Context* ctx = &lbl_801E9D24;
    int i;
    int n;
    Record* r;
    for (i = 0, n = 0; i < rec(self, index)->countA8; n++, i++) {
        r = rec(self, index);
        Entry* e = &lbl_801E9D24.manager->entries[self->handle30.index];
        r->results98[n] = (e->tag == self->handle30.tag ? e->object : 0)->s70(&r->field04, &r->items88[n]);
    }
    r = rec(self, index);
    fn_801F44DC(out, r->field08, r->results98);
}

extern "C" void fn_80210444(Self* self)
{
    if (self->count == 0) return;
    Context* ctx = &lbl_801E9D24;
    Viewport* viewport = getViewport(ctx, self->viewport);
    Grid heights = lbl_802AE4D0;
    Font* font;
    int i;
    int col;
    int row;
    for (i = 0; i < self->count; i++) {
        Record* r = &self->records[i];
        unsigned char flags = r->flags;
        if (flags & 1) continue;
        row = 0;
        col = 0;
        float speed = r->speed;
        if ((flags & 0xC) == 0xC) col = 1;
        else if (flags & 4) col = 0;
        else if (flags & 8) col = 2;
        if ((flags & 0x30) == 0x30) row = 1;
        else if (flags & 0x10) row = 0;
        else if (flags & 0x20) row = 2;
        Font* fnt = &lbl_801E9D24.scope->fonts[r->font];
        font = fnt;
        heights.v[col][row] += (unsigned int)(speed * (float)fnt->info->height);
    }
    int x, y, w, h;
    fn_801E2E70(viewport, &x, &y, &w, &h);
    x = 16;
    w -= 32;
    y = 16;
    h -= 32;
    Grid offsets;
    int k, c;
    for (c = 0; c < 3; c++) {
        for (k = 0; k < 3; k++) {
            offsets.v[c][k] = 16;
            switch (k) {
            case 1: offsets.v[c][k] += (h - heights.v[c][k]) / 2; break;
            case 2: offsets.v[c][k] += h - heights.v[c][k]; break;
            }
            heights.v[c][k] = 0;
        }
    }
    Groups counts = lbl_802AE4F4;
    int groups[16][8];
    int numGroups = 0;
    for (int i = 0; i < self->count; i++) {
        unsigned char flags = *((unsigned char*)&self->records->flags + i * 0xD4);
        if (flags & 1) continue;
        if ((flags & 0x40) != 0x40) continue;
        signed char found = 0;
        for (int g = 0; g < numGroups; g++) {
            for (int k = 0; k < counts.v[g]; k++) {
                if (self->records[i].line == self->records[groups[g][k]].line && self->records[i].column == self->records[groups[g][k]].column) {
                    found = 1;
                    break;
                }
            }
            if (found) groups[g][counts.v[g]++] = i;
        }
        if (!found) {
            groups[numGroups][counts.v[numGroups]++] = i;
            numGroups++;
        }
    }
    Record* first;
    for (int g = 0; g < numGroups; g++) {
        first = &self->records[groups[g][0]];
        int n = counts.v[g];
        float py = (float)y + (float)(h * first->column) / 100.0f;
        py -= (float)(n * font->info->height / 2);
        float px = (float)x + (float)(w * first->line) / 100.0f;
        first->pos.x = px;
        first->pos.y = py;
        for (int k = 1; k < counts.v[g]; k++) {
            py += (float)fh(font);
            Vec2* p = &rec2(self, groups[g][k])->pos;
            p->x = px;
            p->y = py;
        }
    }
    for (i = 0; i < self->count; i++) {
        Record* cur = &self->records[i];
        unsigned char flags = cur->flags;
        if (flags & 1) continue;
        if (flags & 0x40) continue;
        char text[128];
        struct { char* v; } tb; tb.v = text;
        struct { Font* v; } fb; fb.v = &ctx->scope->fonts[self->records[i].font];
        float speed = self->records[i].speed;
        fn_80210374(self, i, tb.v);
        float px = (float)x;
        int row;
        int col;
        int iconW;
        iconW = 0;
        row = 0;
        col = 0;
        if (fn_801F7EB8(&self->records[i].bitmap)) {
            Texture* tex = (Texture*)lookup(((Material*)lookup(((Bitmap*)lookup(self->records[i].bitmap))->material))->texture);
            iconW = (int)((float)tex->width * speed);
            iconW += 4;
        }
        flags = *((unsigned char*)&self->records->flags + i * 0xD4);
        if ((flags & 0xC) == 0xC) {
            col = 1;
            px = (float)(x + (w >> 1));
        } else if (flags & 4) {
            col = 0;
            px = (float)x;
        } else if (flags & 8) {
            px = (float)(x + w);
            px -= (float)(iconW + fn_80261B64(fb.v, text) + 8);
            col = 2;
        }
        flags = *((unsigned char*)&self->records->flags + i * 0xD4);
        if ((flags & 0x30) == 0x30) row = 1;
        else if (flags & 0x10) row = 0;
        else if (flags & 0x20) row = 2;
        float py = (float)(offsets.v[col][row] + heights.v[col][row]);
        heights.v[col][row] += (unsigned int)(speed * (float)fb.v->info->height);
        Vec2* p = &self->records[i].pos;
        p->x = px;
        p->y = py;
    }
}
