typedef unsigned long Word;
struct Handle_801F7F10 {
    union { Word word; struct { signed int tag:8, index:24; } bits; };
    Handle_801F7F10();
    ~Handle_801F7F10();
};
struct HandleManager;
struct FontGlobals { char unknown00[0x118]; HandleManager* manager; };
extern "C" {
extern FontGlobals lbl_801E9D24;
void fn_801F86C8(HandleManager*, const Handle_801F7F10*, int);
unsigned long strlen(const char*);
extern const float lbl_8037B5A8, lbl_8037B5AC, lbl_8037B5B0, lbl_8037B5B4;
}
struct ZeroHandle : Handle_801F7F10 {
    ZeroHandle() { word = 0; }
    ~ZeroHandle() {}
};
struct NullHandle : ZeroHandle {
    NullHandle() { word = 0; }
};
struct LocalHandle : ZeroHandle {
    LocalHandle(const Handle_801F7F10& h) {
        word = h.word;
        fn_801F86C8(lbl_801E9D24.manager, &h, 1);
    }
};
struct Vec2 { float x, y; Vec2(float x_, float y_) : x(x_), y(y_) {} };
struct Color3 { float r, g, b; };
struct FontGlyph { Vec2 min, max; float height; };
struct FontTable { int rowHeight; float scaleU, scaleV; FontGlyph glyphs[144]; };
struct Font { Word unknown00; Handle_801F7F10 texture; FontTable* table; };
struct RendererBase { char unknown00[0x278]; };
struct Renderer : RendererBase {
    virtual void v08(); virtual void v0C(); virtual void v10(); virtual void v14();
    virtual void v18(); virtual void v1C(); virtual void v20(); virtual void v24();
    virtual void v28(); virtual void v2C(); virtual void v30(); virtual void v34();
    virtual void v38(); virtual void v3C(); virtual void v40(); virtual void v44();
    virtual void v48(); virtual void v4C(); virtual void v50(); virtual void v54();
    virtual void v58(); virtual void v5C(); virtual void v60(); virtual void v64();
    virtual void v68(); virtual void v6C(); virtual void v70(); virtual void v74();
    virtual void v78();
    virtual void drawQuad(const Vec2&, const Vec2&, const Vec2&, const Vec2&, float, const Color3*, void*);
    virtual void v80(); virtual void v84(); virtual void v88(); virtual void v8C();
    virtual void v90(); virtual void v94(); virtual void v98(); virtual void v9C();
    virtual void setA0(const Handle_801F7F10&);
    virtual void setA4(const Handle_801F7F10&);
};
extern "C" void fn_80261870(Font* self, Renderer* r, const char* text, int x, int y, float scale, float z, const Color3* color, void* extra)
{
    r->setA0(NullHandle());
    r->setA4(LocalHandle(self->texture));
    int length = strlen(text);
    const char* p = text;
    FontGlyph* glyphs = self->table->glyphs;
    float px = (float)x;
    float py = (float)y;
    float s = scale;
    for (int i = 0; i < length; i++, p++) {
        unsigned char c = *p - 0x20;
        
        float w = glyphs[c].max.x - glyphs[c].min.x;
        if (glyphs[c].height >= 0.0f) {
            if (c == 0x5c || c == 0x5e) s = 0.85f; else s = scale;
            float off = s * glyphs[c].height;
            float gh = s * (glyphs[c].max.y - glyphs[c].min.y);
            Vec2 p0(px, py + off);
            Vec2 p1(w * s + px, off + (py + gh));
            float su = self->table->scaleU; float sv = self->table->scaleV;
            Vec2 uv0(su * (0.25f + glyphs[c].min.x), sv * (0.25f + glyphs[c].min.y));
            Vec2 uv1(su * (0.25f + glyphs[c].max.x), sv * (0.25f + glyphs[c].max.y));
            if (c <= 0x5a) {
                r->drawQuad(p0, p1, uv0, uv1, z, color, extra);
            } else {
                Color3 white;
                white.r = 0.5f; white.g = 0.5f; white.b = 0.5f;
                r->drawQuad(p0, p1, uv0, uv1, z, &white, &white);
            }
        }
        px += w * s;
    }
}
