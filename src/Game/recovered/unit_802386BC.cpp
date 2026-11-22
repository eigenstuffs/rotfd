typedef unsigned long u32;
struct Color {
    float r, g, b, a;
    Color(float r_, float g_, float b_, float a_) : r(r_), g(g_), b(b_), a(a_) {}
};
struct Bitmap {
    char unknown00[0xC];
    void* pixels;       // 0x0C
    void* palette;      // 0x10
    u32 word14, word18, word1C, word20, word24, word28;
    int field2C;
    int width, height;  // 0x30, 0x34
    u32 unknown38;
    unsigned char format; // 0x3C
    char unknown3D;
    unsigned char paletteFormat; // 0x3E
    char unknown3F;
    unsigned char flag40;
};
extern "C" {
extern char lbl_801EF5C8[];
struct Strings { char pixels[0x10]; char file[0x10]; char palette[0x10]; };
extern const Strings lbl_802AEA60;
extern const float lbl_8037B2DC, lbl_8037B2E0, lbl_8037B2F0;
void* fn_801EFA1C(void*, u32, const char*, const char*, int, int);
int fn_80238900(Bitmap*, const Color*);
void fn_802386BC(Bitmap*, Color);
}

extern "C" void fn_802386BC(Bitmap* self, Color color)
{
    switch (self->format) {
    case 1: {
        unsigned char* pixels = (unsigned char*)self->pixels;
        int c = fn_80238900(self, &color);
        unsigned char v = (c & 0xF) + ((unsigned char)c << 4);
        for (int i = 0; i < self->width * self->height / 2; i++) pixels[i] = v;
        break;
    }
    case 2: {
        unsigned char* pixels = (unsigned char*)self->pixels;
        unsigned char v = fn_80238900(self, &color);
        for (int i = 0; i < self->width * self->height; i++) pixels[i] = v;
        break;
    }
    case 7: case 8: case 10: case 11: {
        unsigned short* pixels = (unsigned short*)self->pixels;
        int v = fn_80238900(self, &color);
        unsigned short* p = pixels;
        for (int i = 0; i < self->width * self->height; i++) *p++ = v;
        break;
    }
    case 13: {
        unsigned char* p = (unsigned char*)self->pixels;
        unsigned char r = (int)color.r * 255;
        unsigned char g = (int)color.g * 255;
        unsigned char b = (int)color.b * 255;
        for (int i = 0; i < self->width * self->height; i++) {
            *p = r;
            *p = g;
            *p = b;
            p += 3;
        }
        break;
    }
    case 12: {
        u32* p = (u32*)self->pixels;
        u32 v = ((((unsigned char)(int)color.a * 255 << 24) + ((unsigned char)(int)color.r * 255 << 16)) + ((unsigned char)(int)color.g * 255 << 8)) + (unsigned char)(int)color.b * 255;
        for (int i = 0; i < self->width * self->height; i++) *p++ = v;
        break;
    }
    }
}

typedef unsigned short u16;
inline int paletteSize(unsigned char format)
{
    if (format == 1) return 0x10;
    if (format == 2) return 0x100;
    return 0;
}
inline unsigned char nearestColor(Bitmap* self, unsigned char format, int r, int g, int b, int a)
{
    unsigned char best = 0xFF;
    float bestDistance = lbl_8037B2E0;
    unsigned char cb = b, cg = g, cr = r, ca = a;
    for (int i = 0; i < paletteSize(format); i++) {
        struct { unsigned char r, g, b, a; } p;
        p.a = 0;
        p.b = 0;
        if (self->paletteFormat == 3) {
            p.r = ((unsigned char*)self->palette + i * 4)[0];
            p.g = ((unsigned char*)self->palette + i * 4)[1];
            p.b = ((unsigned char*)self->palette + i * 4)[2];
            p.a = ((unsigned char*)self->palette + i * 4)[3];
        } else if (self->paletteFormat == 2) {
            u16 c = ((u16*)self->palette)[i];
            p.a = 0xFF;
            p.r = (c & 0xF800) >> 8;
            p.g = (c & 0x7E0) >> 3;
            p.b = (c & 0x1F) << 3;
        } else {
            u16 c = ((u16*)self->palette)[i];
            p.r = (c & 0xF00) >> 4;
            p.g = c & 0xF0;
            p.b = (c & 0xF) << 4;
            p.a = (c & 0x7000) >> 7;
        }
        float distance = (float)((p.a - ca) * (p.a - ca)) + ((float)(p.r - cr) * (float)(p.r - cr) + (float)((p.g - cg) * (p.g - cg)) + (float)((p.b - cb) * (p.b - cb)));
        if (distance < bestDistance) {
            bestDistance = distance;
            best = i;
        }
    }
    return best;
}
extern "C" int fn_80238900(Bitmap* self, const Color* color)
{
    int r = (int)(lbl_8037B2F0 * color->r);
    int g = (int)(lbl_8037B2F0 * color->g);
    int b = (int)(lbl_8037B2F0 * color->b);
    int a = (int)(lbl_8037B2F0 * color->a);
    unsigned char format = self->format;
    switch (format) {
    case 8:
        return (u16)((((u16)r >> 3) << 11) + (((u16)g >> 2) << 5) + ((u16)b >> 3));
    case 7:
        return (u16)((((u16)a >> 7) << 15) + (((u16)r >> 3) << 10) + (((u16)g >> 3) << 5) + (u16)((u16)b >> 3));
    case 10:
        return (u16)((((u16)a >> 4) << 12) + (((u16)r >> 4) << 8) + ((u16)((u16)g >> 4) << 4) + (u16)((u16)b >> 4));
    case 11:
    {
        int bt = (u16)((u16)b >> 3);
        bt = (u16)bt << 1;
        int gt = (u16)g;
        gt = (u16)gt >> 3;
        int at = (u16)a;
        at = (u16)at >> 7;
        return (u16)((((((u16)r >> 3) << 11) + (gt << 6)) + bt) + at);
    }
    case 1:
    case 2:
        return nearestColor(self, format, r, g, b, a);
    }
}

inline const char* pixelsText(const Strings* p) { const char (Strings::*m)[0x10] = &Strings::file; const char* s = p->*m; return s - sizeof(p->pixels); }
extern "C" void fn_80238BA8(Bitmap* self, int width, int height, unsigned char format)
{
    const Strings* const strings = &lbl_802AEA60;
    int size;
    int colors;
    self->field2C = -1;
    switch (format) {
    case 1: size = width * height / 2; colors = 0x10; break;
    case 2: size = width * height; colors = 0x100; break;
    case 7: case 8: case 10: case 11: size = width * height * 2; break;
    case 13: size = width * height * 3; break;
    case 12: size = width * height * 4; break;
    }
    if (format == 1 || format == 2)
        self->palette = fn_801EFA1C(lbl_801EF5C8, colors * 4, strings->palette, strings->file, 0x82, 4);
    else
        self->palette = 0;
    self->pixels = fn_801EFA1C(lbl_801EF5C8, size, pixelsText(strings), strings->file, 0x88, 0x20);
    self->width = width;
    self->height = height;
    self->format = format;
    fn_802386BC(self, Color(lbl_8037B2DC, lbl_8037B2DC, lbl_8037B2DC, lbl_8037B2DC));
    self->word14 = 0;
    self->word18 = 0;
    self->word1C = 0;
    self->word20 = 0;
    self->word24 = 0;
    self->word28 = 0;
    self->flag40 = 0;
}
