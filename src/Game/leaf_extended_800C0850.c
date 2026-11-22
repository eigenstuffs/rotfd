extern unsigned int lbl_803777D0;

void fn_800C0850(void) { lbl_803777D0 = 0; }

/* Native startup registration for the scalar global initializer. */
__declspec(section ".ctors")
static void (*const scalar_global_init_reference)(void) = fn_800C0850;
