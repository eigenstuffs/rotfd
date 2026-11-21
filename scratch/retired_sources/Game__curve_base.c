/* Minimal base operations shared by the reconstructed curve arrays. */
extern struct { char reserved[16]; } lbl_801EF5C8;
extern void fn_801EF610(void *,void *);
void *__dt__18CurveBase_801B1088Fv(void *object,short delete_flag)
{
    if (object && delete_flag>0)
        fn_801EF610(&lbl_801EF5C8,object);
    return object;
}
void __ct__18CurveBase_801B1088Fv(unsigned short *object)
{
    *object=1;
}
