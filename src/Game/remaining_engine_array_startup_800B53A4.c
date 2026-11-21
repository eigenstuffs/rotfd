/* Original array startup entry; global storage and the element initializer remain external. */
struct StartupRecord { unsigned char opaque[0x50]; };
extern struct StartupRecord lbl_802F4208[300];
extern void fn_800B53E0(void*);
extern void __construct_array(void*,void(*)(void*),void(*)(void*),unsigned int,unsigned int);
void fn_800B53A4(void) { __construct_array(lbl_802F4208,fn_800B53E0,0,sizeof(struct StartupRecord),300); }
__declspec(section ".ctors")
static void (*const array_startup_reference)(void)=fn_800B53A4;
