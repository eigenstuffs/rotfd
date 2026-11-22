extern "C" {
extern unsigned long lbl_803776A0;
void fn_8005BF88();
void fn_8005CD24(void*);
void fn_8005CD68(void*, short);
void fn_8005CCE8()
{
    unsigned long object[0x98 / 4];
    lbl_803776A0 = 0;
    fn_8005BF88();
    fn_8005CD24(object);
    fn_8005CD68(object, -1);
}
}
