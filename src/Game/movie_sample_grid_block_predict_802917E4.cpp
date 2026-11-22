typedef unsigned char Byte;
typedef unsigned short U16;

extern "C" {
extern unsigned char lbl_80373140[512];
extern int lbl_80373340[16];
}

struct BitReader {
    unsigned int* data;
    unsigned int bits;
    unsigned int word08;
    int position;
    unsigned int* buffer;
};

struct HuffmanTree {
    int word00;
    int root;
    int child[2][512];
};

struct ByteStream {
    unsigned char* data;
    unsigned char unknown04[12];
};

struct Workspace {
    unsigned long unknown00;
    Byte* pixels;
    U16 blockWidth;
    U16 blockHeight;
    U16 stride;
    Byte unknown000E[0x6150 - 0x0E];
    BitReader readers[3];
    Byte unknown618C[0x61DC - 0x618C];
    ByteStream streams[3];
    Byte unknown620C[0x625C - 0x620C];
    U16 sampleWidth;
    U16 sampleHeight;
    Byte transpose;
    Byte samples[0x6CD0 - 0x6261];
    Byte shift;
};


extern "C" void fn_802917E4(Workspace* self, int x, int y) {
    Byte* row;
    Byte* dst;
    int copyWidth;
    int mirrorHeight;
    int copyHeight;
    int n;
    int rows;
    int width;
    int zeroWidth;
    int stride;
    int height;
    int zeroHeight;
    Byte* src;
    int mirrorWidth;
    Byte* prior;
    Byte* from;
    stride=self->stride;
    width=self->blockWidth;
    height=self->blockHeight;
    row=self->pixels+2*(x+y*stride);
    if(width<self->sampleWidth) {
        copyWidth=width;
        if((mirrorWidth=self->sampleWidth-width)>width)mirrorWidth=width;
        zeroWidth=self->sampleWidth-(width+mirrorWidth);
    } else {
        copyWidth=self->sampleWidth;
        zeroWidth=0;
        mirrorWidth=0;
    }
    if(height<self->sampleHeight) {
        copyHeight=height;
        if((mirrorHeight=self->sampleHeight-height)>height)mirrorHeight=height;
        zeroHeight=self->sampleHeight-(height+mirrorHeight);
    } else {
        copyHeight=self->sampleHeight;
        zeroHeight=0;
        mirrorHeight=0;
    }
    dst=self->samples;
    for(rows=copyHeight;rows>0;--rows) {
        src=row;
        n=copyWidth;
        while(n>0) {
            *dst++=(*src>>4)&15;
            src+=2;
            --n;
        }
        n=mirrorWidth;
        while(n>0) {
            src-=2;
            *dst++=(*src>>4)&15;
            --n;
        }
        n=zeroWidth;
        while(n>0) {
            *dst++=0;
            --n;
        }
        row+=stride*2;
    }
    prior=dst-self->sampleWidth;
    for(rows=mirrorHeight;rows>0;--rows) {
        from=prior;
        n=self->sampleWidth;
        while(n>0) {
            *dst++=*from++;
            --n;
        }
        prior-=self->sampleWidth;
    }
    for(rows=zeroHeight;rows>0;--rows) {
        n=self->sampleWidth;
        while(n>0) {
            *dst++=0;
            --n;
        }
    }
}

#define CLAMP (lbl_80373140 + 128)
extern "C" void fn_80291B88(unsigned char* out, int stride, unsigned char c,
    unsigned char a, unsigned char b, unsigned char l, unsigned char r)
{
    int dy;
    int dx;
    int d2;
    int base;
    int al;
    int bn;
    int ar;
    int bm;
    int br;
    int bl;
    int am;
    int an;
    dy = a - b;
    dx = l - r;
    d2 = dy - dx;
    base = c * 8 + 4;
    al = a + l - (c * 2);
    bn = b - r;
    ar = a + r - (c * 2);
    bm = b - l;
    an = a - r;
    bl = l + b - (c * 2);
    am = a - l;
    br = b + r - (c * 2);
    out[0] = CLAMP[(al + (base + (dy + dx))) >> 3];
    out[1] = CLAMP[(am + (base + (dy + dx))) >> 3];
    out[2] = CLAMP[(an + (base + d2)) >> 3];
    out[3] = CLAMP[(ar + (base + d2)) >> 3];
    out += stride;
    out[0] = CLAMP[((base + (dy + dx)) - am) >> 3];
    out[1] = CLAMP[(base - br) >> 3];
    out[2] = CLAMP[(base - bl) >> 3];
    out[3] = CLAMP[((base + d2) - an) >> 3];
    out += stride;
    out[0] = CLAMP[((base - d2) - bm) >> 3];
    out[1] = CLAMP[(base - ar) >> 3];
    out[2] = CLAMP[(base - al) >> 3];
    out[3] = CLAMP[((base - (dy + dx)) - bn) >> 3];
    out += stride;
    out[0] = CLAMP[(bl + (base - d2)) >> 3];
    out[1] = CLAMP[(bm + (base - d2)) >> 3];
    out[2] = CLAMP[(bn + (base - (dy + dx))) >> 3];
    out[3] = CLAMP[(br + (base - (dy + dx))) >> 3];
}
#undef CLAMP

