/* Original record setup with observed private scalar fields.
 * See docs/notes/game-record-setup-late.md. */
extern const float lbl_8037B390;
extern const float lbl_8037B394;
extern const float lbl_8037B398;
extern const unsigned char lbl_802EA230[];
extern void fn_80243F28(void *object);
void *fn_80243D84(void *object) {
    fn_80243F28(object);
    *(const void * *)((char *)object+8)=lbl_802EA230;
    *(float *)((char *)object+116)=lbl_8037B390;
    *(float *)((char *)object+120)=lbl_8037B394;
    *(float *)((char *)object+124)=lbl_8037B394;
    *(float *)((char *)object+128)=lbl_8037B398;
    *(unsigned short *)((char *)object+108)=15;
    return object;
}
