extern "C" {
extern unsigned long lbl_803776B0;
void fn_8005BF88();
void fn_8005DA68(void*);
void fn_8005DAAC(void*, short);
void fn_8005DA2C()
{
    unsigned long object[0x98 / 4];
    lbl_803776B0 = 0;
    fn_8005BF88();
    fn_8005DA68(object);
    fn_8005DAAC(object, -1);
}
}
