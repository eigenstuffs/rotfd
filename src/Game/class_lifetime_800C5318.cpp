extern "C" {
extern unsigned long lbl_80377808;
void fn_8002AD5C();
void fn_800C5354(void*);
void fn_800C5390(void*, short);
void fn_800C5318()
{
    unsigned long object[0x98 / 4];
    lbl_80377808 = 0;
    fn_8002AD5C();
    fn_800C5354(object);
    fn_800C5390(object, -1);
}
}
