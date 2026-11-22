extern "C" {
extern unsigned long lbl_80377608;
void fn_80039434();
void fn_80039454(void*);
void fn_80039508(void*, short);
void fn_800393F8()
{
    unsigned long object[0xe0 / 4];
    lbl_80377608 = 0;
    fn_80039434();
    fn_80039454(object);
    fn_80039508(object, -1);
}
}

// The retained base hook forwards to its common projectile initializer.
extern "C" {
void fn_8003522C();
void fn_80039434() { fn_8003522C(); }
}
