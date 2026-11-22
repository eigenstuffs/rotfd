#ifndef GAME_RESOURCE_LIFETIME_801F0518_INTERNAL_H
#define GAME_RESOURCE_LIFETIME_801F0518_INTERNAL_H
typedef unsigned long u32;
struct ResourceLifetimeView {
 char unknown0[8]; void *vtable; char unknownC[0x68];
 char stored[0x78]; char extension[0x40];
};
extern "C" {
extern char lbl_802EA958[],lbl_801EF5C8[];
void *fn_80243E90(void*,short);
void fn_801EF610(void*,void*);
void fn_80243E44(void*,void**);
void *fn_801E9F40(void*,void*,u32);
}
#endif
