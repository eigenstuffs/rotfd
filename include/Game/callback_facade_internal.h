#ifndef GAME_CALLBACK_FACADE_INTERNAL_H
#define GAME_CALLBACK_FACADE_INTERNAL_H

extern "C" {
extern void *lbl_80378078,*lbl_80378080,*lbl_80378028;
extern char lbl_801E9D24[];
void fn_8025ED38(void*,void*,void*);
int fn_8025E70C(void*,void*,void*);
void fn_80287B8C(void*,int);
void fn_80287B9C(void*,unsigned char);
void fn_80256370(void*);
void fn_802560D8(void*);
}
struct Global {char unknown0[0x144];void *target;};
struct Parameter {char unknown0[0x2C];float value;};
struct Storage {char unknown0[8];};
struct VirtualView:Storage {
 virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1C();virtual void slot20();virtual void slot24();virtual void slot28(int);
};

#endif
