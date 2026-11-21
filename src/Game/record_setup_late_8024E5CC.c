/* Original record setup with observed private scalar fields.
 * See docs/notes/game-record-setup-late.md. */
extern const unsigned char lbl_802EA5B0[];
extern void fn_8024E18C(void *object);
void *__ct__19SplineZone_8024E5CCFv(void *object) {
    fn_8024E18C(object);
    *(const void * *)((char *)object+8)=lbl_802EA5B0;
    *(unsigned int *)((char *)object+160)=0;
    *(unsigned int *)((char *)object+164)=0;
    *(unsigned int *)((char *)object+168)=0;
    *(unsigned int *)((char *)object+204)=0;
    *(unsigned int *)((char *)object+208)=0;
    *(unsigned int *)((char *)object+212)=0;
    *(unsigned short *)((char *)object+108)=9;
    return object;
}
