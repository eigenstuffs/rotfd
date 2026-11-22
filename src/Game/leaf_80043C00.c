extern unsigned int lbl_8037763C;
extern unsigned int lbl_80377638;

unsigned int fn_80043C00(void) { return lbl_8037763C; }

void fn_80043C08(void *object, unsigned int value) { lbl_8037763C = value; }

unsigned int fn_80043C10(void) { return lbl_80377638; }

void fn_80043C18(void *object, unsigned int value) { lbl_80377638 = value; }
