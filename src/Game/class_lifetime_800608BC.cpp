extern "C" {
extern unsigned long lbl_803776F0;
void fn_8005BF88();
void fn_800608F8(void*);
void fn_8006093C(void*, short);
void fn_800608BC()
{
    unsigned long object[0x98 / 4];
    lbl_803776F0 = 0;
    fn_8005BF88();
    fn_800608F8(object);
    fn_8006093C(object, -1);
}
}
