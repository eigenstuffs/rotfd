extern "C" {
extern unsigned long lbl_80377714;
void fn_80064D70();
void fn_80064D90(void*);
void fn_80064CF4(void*, short);
void fn_80064CB8()
{
    unsigned long object[0x78 / 4];
    lbl_80377714 = 0;
    fn_80064D70();
    fn_80064D90(object);
    fn_80064CF4(object, -1);
}
}
