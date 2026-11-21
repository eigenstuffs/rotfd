/* Original record setup with observed private scalar fields.
 * See docs/notes/game-record-setup-late.md. */
extern const float lbl_8037B3B0;
extern const unsigned char lbl_802EC1B8[];
extern void fn_80243F28(void *object);
void *fn_802441F0(void *object) {
    fn_80243F28(object);
    *(const void * *)((char *)object+8)=lbl_802EC1B8;
    *(unsigned short *)((char *)object+108)=16;
    *(float *)((char *)object+116)=lbl_8037B3B0;
    *(float *)((char *)object+120)=lbl_8037B3B0;
    *(float *)((char *)object+124)=lbl_8037B3B0;
    *(unsigned char *)((char *)object+128)=1;
    return object;
}
