#include "Game/engine_card_texture_register.h"

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
extern struct { char unknown00[0x110]; void* log; } lbl_801E9D24;
void fn_801FA014(void*,const char*,...);
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
struct CardTextureRegistrationView {
    char unknown00[0x41C];
    Word bytes41C;
    int hasPalette420;
    Word count424;
    char records428[8 * 12];
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
extern "C" void fn_80276C40(CardTextureRegistrationView* self, const char* name, int option) {
    const char* messages=(const char*)&lbl_802AF158;
    int size;
    int paletteSize;
    Word j;
    CardTextureFile_GR file;
    if (!name || self->count424>=8) return;
    if (!fn_801F3814(name)) return;
    if (fn_801F3918(&file,name,1)) {
        Image* image=(Image*)fn_801EFA1C(lbl_801EF5C8,fn_801F2E28(&file),messages+0x4C,messages+0x5C,0x5D7,32);
        if (image) {
            fn_801F2CB4(&file,image,fn_801F2E28(&file));
            bind(image);
            for (j=0;j<image->count && self->count424<8;++j) {
                Descriptor* descriptor=TPLGet(image,j);
                int format;
                switch (descriptor->texture->format) {
                case 5:
                    format = 2;
                    size = 0x800;
                    paletteSize = 0;
                    break;
                case 9:
                    format = 1;
                    size = 0x400;
                    paletteSize = 0x200;
                    break;
                default:
                    fn_801FA014(lbl_801E9D24.log,messages+0x70);
                    format=-1;
                    break;
                }
                if (format!=-1) {
                    if (descriptor->texture->width!=32 || descriptor->texture->height!=32) {
                        fn_801FA014(lbl_801E9D24.log,messages+0xB8,32,32);
                    } else {
                        *(Word*)(self->records428+self->count424*12+4)=option;
                        *(const char**)(self->records428+self->count424*12+8)=name;
                        *(Word*)(self->records428+self->count424*12)=format;
                        self->bytes41C+=size;
                        if (paletteSize && !self->hasPalette420) {
                            self->bytes41C+=paletteSize;
                            self->hasPalette420=1;
                        }
                        ++self->count424;
                    }
                }
            }
            fn_801EF610(lbl_801EF5C8,image);
        }
        fn_801F2A98(&file);
    }
}
