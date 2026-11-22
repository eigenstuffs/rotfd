extern void slot0C__12BaseObject_ZFUl(void *,void **);
extern void *fn_801E9F40(void *,void *,unsigned int);
extern void fn_801F77A4(void *,void **);
extern void fn_801AE240(void *,void **);
extern void fn_801ADF58(void *,void **);
extern void fn_801B378C(void *,int,int);
extern void fn_801B353C(void *,int,int);
extern void fn_801B3288(void *,int,int);
void fn_801B311C(void *object,void **cursor)  {
    int count,i;
    slot0C__12BaseObject_ZFUl(object,cursor);
    *cursor=fn_801E9F40((char *)object+0x30,*cursor,4);
    *cursor=fn_801E9F40((char *)object+0x34,*cursor,2);
    *cursor=fn_801E9F40(&count,*cursor,4);
    fn_801B378C((char *)object+0x24,count,0);
    for(i=0;i<count;++i)fn_801F77A4(*(char **)((char *)object+0x2c)+i*0x1c,cursor);
    *cursor=fn_801E9F40(&count,*cursor,4);
    fn_801B353C((char *)object+0xc,count,0);
    for(i=0;i<count;++i)fn_801AE240(*(char **)((char *)object+0x14)+i*0x50,cursor);
    *cursor=fn_801E9F40(&count,*cursor,4);
    fn_801B3288((char *)object+0x18,count,0);
    for(i=0;i<count;++i)fn_801ADF58(*(char **)((char *)object+0x20)+i*0x8c,cursor);
}
