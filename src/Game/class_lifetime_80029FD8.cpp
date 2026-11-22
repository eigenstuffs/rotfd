extern "C" {
extern unsigned long lbl_803775B0;
void fn_8025A930();
void fn_8002A014(void*);
void fn_8002A050(void*, short);
void fn_80029FD8()
{
    unsigned long object[0x78 / 4];
    lbl_803775B0 = 0;
    fn_8025A930();
    fn_8002A014(object);
    fn_8002A050(object, -1);
}
}
