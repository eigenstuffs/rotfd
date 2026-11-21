/* Original record resource lifecycle; see docs/notes/game-engine-record-lifecycle.md. */
typedef unsigned long u32;struct Prefix{u32 unknown00,unknown04;};struct Object:Prefix{virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1C();};
struct View{char opaque00[0xB2EC];Object*memberB2EC;};
extern "C" signed char slot1C__12BaseObject_ZFv(View*);
extern "C" signed char fn_800E85E4(View*self){if(!slot1C__12BaseObject_ZFv(self))return 0;self->memberB2EC->slot1C();return 1;}
