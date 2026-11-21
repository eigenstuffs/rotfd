/* Original engine stream and record routines.
 * See docs/notes/game-engine-streams.md. */
extern void slot0C__12BaseObject_ZFUl(void *,void **);
extern void *fn_801E9F40(void *,void *,unsigned int);
extern void fn_801F3C70(void *,int);
extern unsigned int fn_801F2E28(void *);
void fn_801B4B38(void *object,void **cursor)  {
    int count;
    void *destination;
    slot0C__12BaseObject_ZFUl(object,cursor);
    *cursor=fn_801E9F40(&count,*cursor,4);
    fn_801F3C70((char *)object+0xc,count);
    destination=*(void **)((char *)object+0x54);
    *cursor=fn_801E9F40(destination,*cursor,fn_801F2E28((char *)object+0xc));
}
