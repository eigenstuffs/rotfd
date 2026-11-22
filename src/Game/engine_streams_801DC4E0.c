extern void slot0C__12BaseObject_ZFUl(void *,void **);
extern void *fn_801E9F40(void *,void *,unsigned int);
extern struct  {
    char pad[0x118];
    void *handles;
}
lbl_801E9D24;
extern void fn_801B41B8(void *,void *,void **);
extern void fn_801B3FD0(void *,void *,void **);
extern void fn_80243E44(void *,void **);
extern void fn_801B1BEC(void *,void **);
extern void fn_801B1A14(void *,void **);
void fn_801DC4E0(void *object,void **cursor)  {
    fn_80243E44(object,cursor);
    *cursor=fn_801E9F40((char *)object+0x74,*cursor,(unsigned int)((char *)object+0xb4)-(unsigned int)((char *)object+0x74)+4);
    fn_801B1BEC((char *)object+0xb8,cursor);
    fn_801B1BEC((char *)object+0xc8,cursor);
    fn_801B1BEC((char *)object+0xd8,cursor);
    fn_801B1BEC((char *)object+0xe8,cursor);
    fn_801B1BEC((char *)object+0xf8,cursor);
    fn_801B1A14((char *)object+0x108,cursor);
    fn_801B1BEC((char *)object+0x118,cursor);
    fn_801B1BEC((char *)object+0x128,cursor);
    fn_801B1BEC((char *)object+0x138,cursor);
    fn_801B1BEC((char *)object+0x148,cursor);
    fn_801B1A14((char *)object+0x158,cursor);
    fn_801B1BEC((char *)object+0x168,cursor);
    fn_801B1BEC((char *)object+0x178,cursor);
    fn_801B41B8(lbl_801E9D24.handles,(char *)object+0x188,cursor);
}
