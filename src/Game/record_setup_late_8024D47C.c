/* Original record setup with observed private scalar fields.
 * See docs/notes/game-record-setup-late.md. */
extern const unsigned char lbl_802EC310[];
extern void fn_80243F28(void *object);
void *fn_8024D47C(void *object) {
    fn_80243F28(object);
    *(const void * *)((char *)object+8)=lbl_802EC310;
    *(unsigned int *)((char *)object+116)=0;
    *(unsigned int *)((char *)object+120)=0;
    *(unsigned int *)((char *)object+124)=0;
    *(unsigned int *)((char *)object+128)=0;
    *(unsigned int *)((char *)object+132)=0;
    *(unsigned int *)((char *)object+136)=0;
    *(unsigned int *)((char *)object+140)=0;
    *(unsigned int *)((char *)object+144)=0;
    *(unsigned int *)((char *)object+148)=0;
    *(unsigned short *)((char *)object+108)=3;
    return object;
}
