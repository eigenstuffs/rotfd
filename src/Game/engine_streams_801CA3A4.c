extern void slot0C__12BaseObject_ZFUl(void *,void **);
extern void *fn_801E9F40(void *,void *,unsigned int);
extern struct  {
    char pad[0x118];
    void *handles;
}
lbl_801E9D24;
extern void fn_801B41B8(void *,void *,void **);
extern void fn_801B3FD0(void *,void *,void **);
void fn_801CA3A4(void *object,void **cursor)  {
    slot0C__12BaseObject_ZFUl(object,cursor);
    fn_801B41B8(lbl_801E9D24.handles,(char *)object+0xc,cursor);
    fn_801B41B8(lbl_801E9D24.handles,(char *)object+0x10,cursor);
    fn_801B41B8(lbl_801E9D24.handles,(char *)object+0x14,cursor);
    fn_801B41B8(lbl_801E9D24.handles,(char *)object+0x18,cursor);
    fn_801B41B8(lbl_801E9D24.handles,(char *)object+0x1c,cursor);
    fn_801B3FD0(lbl_801E9D24.handles,(char *)object+0x20,cursor);
    fn_801B41B8(lbl_801E9D24.handles,(char *)object+0x24,cursor);
    fn_801B41B8(lbl_801E9D24.handles,(char *)object+0x28,cursor);
    fn_801B41B8(lbl_801E9D24.handles,(char *)object+0x2c,cursor);
    *cursor=fn_801E9F40((char *)object+0x30,*cursor,(unsigned int)((char *)object+0x120)-(unsigned int)((char *)object+0x30)+4);
    *cursor=fn_801E9F40(*(void **)((char *)object+0x124),*cursor,0x40);
    *cursor=fn_801E9F40(*(void **)((char *)object+0x128),*cursor,0x40);
}
