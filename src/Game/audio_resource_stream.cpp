struct AudioNativeHeader {
    unsigned short unknown00[2];
    unsigned short startHi, startLo;
    unsigned short endHi, endLo;
    unsigned short loopHi, loopLo;
    char unknown10[0x3C];
};
struct AudioStreamOwner {
    char unknown00[0xC];
    char record[0xC];
    unsigned long size;
    unsigned long aram;
    AudioNativeHeader* header;
};
extern "C" {
extern char lbl_801EF5C8[], lbl_802AF340[], lbl_802AF350[];
extern struct { char unknown00[0x18C]; void* audio; } lbl_801E9D24;
void slot0C__12BaseObject_ZFUl(void*, void**);
void* fn_801E9F40(void*, const void*, unsigned long);
void* fn_801EFA1C(void*, unsigned long, const char*, const char*, int, int);
unsigned long fn_80285800(void*, unsigned long);
void DCStoreRange(void*, unsigned long);
void fn_8028533C(void*, void*, unsigned long, unsigned long, int);
void fn_801EF610(void*, void*);
}
extern "C" void fn_802793E4(AudioStreamOwner* self, void** cursor)
{
    slot0C__12BaseObject_ZFUl(self, cursor);
    *cursor = fn_801E9F40(self->record, *cursor,
        (unsigned long)&self->size - (unsigned long)self->record + 4);
    self->header = (AudioNativeHeader*)fn_801EFA1C(lbl_801EF5C8, 0x4C,
        lbl_802AF340, lbl_802AF350, 0x13, 4);
    *cursor = fn_801E9F40(self->header, *cursor, 0x4C);
    unsigned long aram = fn_80285800(lbl_801E9D24.audio, self->size);
    self->aram = aram;
    AudioNativeHeader* header = self->header;
    header->startHi = (aram * 2 + 2) >> 16;
    header->startLo = aram * 2 + 2;
    header->endHi = ((aram + (self->size & ~31UL)) * 2 - 1) >> 16;
    header->endLo = (aram + (self->size & ~31UL)) * 2 - 1;
    header->loopHi = header->startHi;
    header->loopLo = header->startLo;
    void* temporary = fn_801EFA1C(lbl_801EF5C8, self->size,
        lbl_802AF340, lbl_802AF350, 0x25, 0x20);
    *cursor = fn_801E9F40(temporary, *cursor, self->size);
    DCStoreRange(temporary, self->size);
    fn_8028533C(lbl_801E9D24.audio, temporary, aram, self->size, 0);
    fn_801EF610(lbl_801EF5C8, temporary);
}
