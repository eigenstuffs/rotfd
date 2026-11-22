extern "C" {
extern unsigned long lbl_803776A8;
void fn_8005BF88();
void fn_8005D49C(void*);
void fn_8005D4E0(void*, short);
void fn_8005D460()
{
    unsigned long object[0x98 / 4];
    lbl_803776A8 = 0;
    fn_8005BF88();
    fn_8005D49C(object);
    fn_8005D4E0(object, -1);
}
}
