extern "C" {
extern unsigned long lbl_803775B8;
void fn_8002AD5C();
void fn_8002A80C(void*);
void fn_8002A848(void*, short);
void fn_8002A7D0()
{
    unsigned long object[0x98 / 4];
    lbl_803775B8 = 0;
    fn_8002AD5C();
    fn_8002A80C(object);
    fn_8002A848(object, -1);
}
}
