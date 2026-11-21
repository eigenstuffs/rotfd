/* fn_80272968: render material bind (texture handles 0x74/0x78, flag bits at
 * owner+0x2D0, current material at +0x2D4, transposed 3x3 texture matrix ->
 * GXLoadTexMtxImm(TEXMTX0), material/TEV colours).  Flags as neighbouring
 * render_handle_select.cpp (GC/1.3.2 -O4,p, no exceptions).
 * The texture matrix must be built by a 3-iteration pointer loop: LICM hoists
 * the shared 0.0f (lbl_8037B6DC) out of it before unrolling, which gives the
 * original f0 (constant) / f1 (copied values) allocation; straight-line
 * assignments put the constant in f1. */
typedef unsigned long Word;
struct Handle { union { Word word; struct { signed int tag : 8, index : 24; } bits; }; };
struct Texture { char unknown00[0x3F]; unsigned char kind; };
struct Entry { Texture* object; Word unknown04, unknown08; signed char tag; char unknown0D[3];
    signed char getTag() const { return tag; } };
struct Manager { int count, capacity; Entry* entries; };
struct Context { char unknown00[0x118]; Manager* manager; };
struct Color { unsigned char r, g, b, a; };
typedef float Mtx[3][4];

extern "C" {
extern Context lbl_801E9D24;
extern const float lbl_8037B6DC, lbl_8037B6EC, lbl_8037B6F0;
Texture* fn_801F7EB8(const Handle*);
void fn_80281830(void*, Texture*, int, int, int);
void DCStoreRange(void*, unsigned long);
void GXLoadTexMtxImm(const Mtx, unsigned long, int);
void GXSetChanMatColor(int, Color);
void GXSetTevColor(int, Color);
void fn_800F6D0C(Mtx);
}

inline Texture* resolve(const Handle& h) {
    int index = h.bits.index;
    Manager* m = lbl_801E9D24.manager;
    int tag = m->entries[index].getTag();
    return tag == h.bits.tag ? m->entries[index].object : 0;
}
inline void* texturePool() { return *(void**)((char*)&lbl_801E9D24 + 0x184); }

struct Material {
    char unknown00[0xC];
    float color[3];
    float alpha;
    float tev[3];
    float scale;
    float matrix[3][3];
    char unknown50[0x18];
    Word flags;
    char unknown6C[8];
    Handle texture;
    Handle second;
};

struct Owner {
    char unknown00[0x2D0];
    unsigned short flags;
    char unknown2D2[2];
    Material* current;
    char unknown2D8[0x9EC - 0x2D8];
    float scale;
};

inline signed char translucent(Material* material) {
    if (fn_801F7EB8(&material->texture) && resolve(material->texture)->kind == 2) return 1;
    if (material->alpha < lbl_8037B6F0) return 1;
    if (material->flags & 8) return 1;
    return 0;
}

extern "C" void fn_80272968(Owner* self, Material* material, int channel) {
    Mtx m;
    Color color;
    if (material) {
        Texture* texture = resolve(material->texture);
        if (material != self->current) {
            int wrapS = ((material->flags >> 1) & 1) ^ 1;
            int wrapT = ((material->flags >> 2) & 1) ^ 1;
            if (texture) {
                self->flags |= 8;
                switch (texture->kind) {
                case 1: self->flags |= 2; break;
                case 2: self->flags |= 1; break;
                }
                fn_80281830(texturePool(), texture, wrapS, wrapT, 0);
            }
            self->current = material;
        } else if (texture) {
            self->flags |= 8;
            if (texture->kind == 1) self->flags |= 2;
            else if (texture->kind == 2) self->flags |= 1;
        }
        float scale = material->scale;
        Texture* second = resolve(material->second);
        if (lbl_8037B6DC != scale) {
            self->scale = scale;
            if (second) {
                self->flags |= 0x4000;
                fn_80281830(texturePool(), second, 0, 0, 2);
            }
        }
        if (material->alpha < lbl_8037B6F0 || translucent(material)) {
            if (material->flags & 8) self->flags |= 4;
            else self->flags |= 1;
            color.a = lbl_8037B6EC * material->alpha;
        } else {
            color.a = 0xFF;
        }
        const float* s = &material->matrix[0][0];
        float (*d)[4] = m;
        for (int i = 0; i < 3; i++, s++, d++) {
            (*d)[0] = s[0];
            (*d)[1] = s[3];
            (*d)[2] = s[6];
            (*d)[3] = lbl_8037B6DC;
        }
        DCStoreRange(m, sizeof(Mtx));
        GXLoadTexMtxImm(m, 0x1E, 0);
        color.r = lbl_8037B6EC * material->color[0];
        color.g = lbl_8037B6EC * material->color[1];
        color.b = lbl_8037B6EC * material->color[2];
        GXSetChanMatColor(channel, color);
        color.a = 0xFF;
        color.r = lbl_8037B6EC * material->tev[0];
        color.g = lbl_8037B6EC * material->tev[1];
        color.b = lbl_8037B6EC * material->tev[2];
        GXSetTevColor(1, color);
    } else {
        self->current = 0;
        fn_800F6D0C(m);
        GXLoadTexMtxImm(m, 0x1E, 0);
        color.r = 0;
        color.g = 0;
        color.b = 0;
        color.a = 0xFF;
        GXSetChanMatColor(channel, color);
        GXSetTevColor(1, color);
    }
}
