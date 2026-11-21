/* Original engine stream and record routines.
 * See docs/notes/game-engine-streams.md. */
extern void slot0C__12BaseObject_ZFUl(void *,void **);
extern void *fn_801E9F40(void *,void *,unsigned int);
extern struct  {
    char pad[0x118];
    void *handles;
}
lbl_801E9D24;
extern void fn_801B41B8(void *,void *,void **);
extern void fn_801B3FD0(void *,void *,void **);
extern void fn_801B1440(void *,void **);
extern void fn_801B1618(void *,void **);
extern void fn_801B17F0(void *,void **);
extern void fn_801B1A14(void *,void **);
extern void fn_801B1BEC(void *,void **);
void fn_801C98BC(void *object,void **cursor)  {
    slot0C__12BaseObject_ZFUl(object,cursor);
    *cursor=fn_801E9F40((char *)object+0xc,*cursor,1);
    *cursor=fn_801E9F40((char *)object+0xb4,*cursor,4);
    fn_801B17F0((char *)object+0x10,cursor);
    fn_801B1440((char *)object+0x20,cursor);
    fn_801B1440((char *)object+0x30,cursor);
    fn_801B1BEC((char *)object+0x40,cursor);
    fn_801B1A14((char *)object+0x50,cursor);
    fn_801B1A14((char *)object+0x60,cursor);
    fn_801B1BEC((char *)object+0x70,cursor);
    fn_801B1618((char *)object+0x80,cursor);
    fn_801B1618((char *)object+0x90,cursor);
    fn_801B1618((char *)object+0xa0,cursor);
    fn_801B41B8(lbl_801E9D24.handles,(char *)object+0xb8,cursor);
}
