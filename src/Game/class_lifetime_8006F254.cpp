extern "C" {
extern unsigned long lbl_80377730;
void fn_8002B58C();
void fn_8006F290(void*);
void fn_8006F2E0(void*, short);
void fn_8006F254()
{
    unsigned long object[0xa0 / 4];
    lbl_80377730 = 0;
    fn_8002B58C();
    fn_8006F290(object);
    fn_8006F2E0(object, -1);
}
}
