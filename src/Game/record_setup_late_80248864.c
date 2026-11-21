/* Original record setup with observed private scalar fields.
 * See docs/notes/game-record-setup-late.md. */
extern const unsigned char lbl_802EA388[];
extern void fn_801CFAB0(void *object);
void *fn_80248864(void *object) {
    fn_801CFAB0(object);
    *(const void * *)((char *)object+8)=lbl_802EA388;
    *(unsigned int *)((char *)object+140)=0;
    *(unsigned int *)((char *)object+144)=0;
    *(unsigned int *)((char *)object+148)=0;
    *(unsigned int *)((char *)object+152)=0;
    *(unsigned int *)((char *)object+156)=0;
    *(unsigned int *)((char *)object+160)=0;
    *(unsigned int *)((char *)object+164)=0;
    *(unsigned int *)((char *)object+168)=0;
    *(unsigned int *)((char *)object+172)=0;
    *(unsigned int *)((char *)object+176)=0;
    *(unsigned int *)((char *)object+180)=0;
    *(unsigned int *)((char *)object+184)=0;
    *(unsigned int *)((char *)object+188)=0;
    *(unsigned int *)((char *)object+192)=0;
    *(unsigned int *)((char *)object+196)=0;
    *(unsigned int *)((char *)object+200)=0;
    *(unsigned int *)((char *)object+204)=0;
    *(unsigned int *)((char *)object+208)=0;
    *(unsigned int *)((char *)object+212)=0;
    *(unsigned int *)((char *)object+216)=0;
    *(unsigned int *)((char *)object+220)=0;
    *(unsigned int *)((char *)object+224)=0;
    *(unsigned int *)((char *)object+228)=0;
    *(unsigned int *)((char *)object+232)=0;
    *(unsigned short *)((char *)object+108)=6;
    return object;
}
