extern "C" {
extern unsigned long lbl_80377588;
void fn_8002AD5C();
void fn_80028184(void*);
void fn_800281C0(void*, short);
void fn_80028148()
{
    unsigned long object[0x98 / 4];
    lbl_80377588 = 0;
    fn_8002AD5C();
    fn_80028184(object);
    fn_800281C0(object, -1);
}
}
