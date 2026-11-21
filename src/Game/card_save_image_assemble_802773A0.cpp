// Memory-card save image assembly: comment, banner, icons, shared palette, payload.
typedef unsigned int Word;
typedef unsigned short Half;
typedef unsigned char Byte;
struct CardTextureFile_GR;
struct Image;
struct Descriptor;
extern "C" {
void __ct__13File_801F3E1CFv(CardTextureFile_GR*);
void __dt__13File_801F3E1CFv(CardTextureFile_GR*,short);
signed char fn_801F3814(const char*);
signed char fn_801F3918(CardTextureFile_GR*,const char*,int);
void fn_801F2E30(CardTextureFile_GR*,int,int);
Word fn_801F2E28(CardTextureFile_GR*);
void fn_801F2CB4(CardTextureFile_GR*,void*,Word);
void fn_801F2A98(CardTextureFile_GR*);
void* fn_801EFA1C(void*,Word,const char*,const char*,int,Word);
void fn_801EF610(void*,void*);
void* memcpy(void*,const void*,Word);
Descriptor* TPLGet(Image*,Word);
extern char lbl_801EF5C8[];
extern const char lbl_802AF158[];
}
struct CardTextureFile_GR {
    char storage[0x5C];
    CardTextureFile_GR() { __ct__13File_801F3E1CFv(this); }
    ~CardTextureFile_GR() { __dt__13File_801F3E1CFv(this, -1); }
};
struct Texture {
    Half height, width;
    Word format;
    void* data;
    char unknown0C[0x17];
    Byte unpacked23;
};
struct Palette {
    Half count;
    Byte unpacked02;
    Byte padding;
    Word format;
    void* data;
};
struct Descriptor {
    Texture* texture;
    Palette* palette;
};
struct Image {
    Word version, count;
    Descriptor* descriptors;
};
struct CardIconRecord {
    Word format;
    Word speed;
    const char* name;
};
struct CardImageView {
    char unknown00[0x414];
    Word bytes414;
    char unknown418[4];
    Word bytes41C;
    int hasPalette420;
    Word count424;
    CardIconRecord records428[8];
    char unknown488[0x40];
};
static inline void bind(Image* image) {
    if (image->version==0x0020AF30) {
        image->descriptors=(Descriptor*)((Word)image->descriptors+(Word)image);
        for (Half j=0;j<image->count;++j) {
            if (image->descriptors[j].texture) {
                image->descriptors[j].texture=(Texture*)((char*)image+(Word)image->descriptors[j].texture);
                if (!image->descriptors[j].texture->unpacked23) {
                    image->descriptors[j].texture->data=(char*)image+(Word)image->descriptors[j].texture->data;
                    image->descriptors[j].texture->unpacked23=1;
                }
            }
            if (image->descriptors[j].palette) {
                image->descriptors[j].palette=(Palette*)((char*)image+(Word)image->descriptors[j].palette);
                if (!image->descriptors[j].palette->unpacked02) {
                    image->descriptors[j].palette->data=(char*)image+(Word)image->descriptors[j].palette->data;
                    image->descriptors[j].palette->unpacked02=1;
                }
            }
        }
    }
}
extern "C" void fn_802773A0(CardImageView* self, const void* data, Word length, char* buffer) {
    const char* messages=(const char*)&lbl_802AF158;
    CardTextureFile_GR file;
    Word i;
    int j;
    Descriptor* descriptor;
    char* out;
    Image* image;
    void* palette=0;
    memcpy(buffer,self->unknown488,0x40);
    out=buffer+0x40;
    if (fn_801F3814(messages+0x1A4) && fn_801F3918(&file,messages+0x1A4,1)) {
        fn_801F2E30(&file,0x20,1);
        fn_801F2CB4(&file,out,self->bytes414);
        fn_801F2A98(&file);
        out+=self->bytes414;
    }
    for (i=0;i<self->count424;++i) {
        if (fn_801F3918(&file,self->records428[i].name,1)) {
            image=(Image*)fn_801EFA1C(lbl_801EF5C8,fn_801F2E28(&file),messages+0x4C,messages+0x5C,0x490,32);
            if (image) {
                fn_801F2CB4(&file,image,fn_801F2E28(&file));
                bind(image);
                for (j=0;j<image->count && i<self->count424;++j,++i) {
                    descriptor=TPLGet(image,j);
                    switch (descriptor->texture->format) {
                    case 5:
                        memcpy(out,descriptor->texture->data,0x800);
                        out+=0x800;
                        break;
                    case 9:
                        memcpy(out,descriptor->texture->data,0x400);
                        out+=0x400;
                        if (!palette) {
                            palette=fn_801EFA1C(lbl_801EF5C8,0x200,messages+0x4C,messages+0x5C,0x4AD,4);
                            if (palette)
                                memcpy(palette,descriptor->palette->data,0x200);
                        }
                        break;
                    }
                }
                fn_801EF610(lbl_801EF5C8,image);
            }
            fn_801F2A98(&file);
        }
    }
    if (palette) {
        memcpy(out,palette,0x200);
        fn_801EF610(lbl_801EF5C8,palette);
        out+=0x200;
    }
    memcpy(out,data,length);
}
