extern float lbl_802F4148[3];

extern const float lbl_8037859C,lbl_803785AC;

void fn_8005BF6C(void) {lbl_802F4148[0]=lbl_8037859C;lbl_802F4148[1]=lbl_803785AC;lbl_802F4148[2]=lbl_8037859C;}

__declspec(section ".ctors")
static void (*const scalar_global_init_reference)(void) = fn_8005BF6C;
