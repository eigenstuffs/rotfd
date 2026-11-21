/* Original engine destruction with compiler-emitted exception metadata.
 * See docs/notes/game-engine-virtual-setup.md. */
struct Prefix{char unknown00[8];};
struct View:Prefix{
virtual void slot08();
virtual void slot0C();
virtual void slot10();
virtual void slot14();
virtual void slot18();
virtual void slot1C();
virtual void slot20();
virtual void slot24();
virtual void slot28(int);
virtual void slot2C();
virtual void slot30();
virtual void slot34();
virtual void slot38();
virtual void slot3C();
virtual void slot40();
virtual void slot44();
virtual void slot48();
virtual void slot4C();
virtual void slot50();
virtual void slot54();
virtual void slot58();
virtual void slot5C();
virtual void slot60();
virtual void slot64();
virtual void slot68();
virtual void slot6C();
virtual void slot70();
virtual void slot74();
virtual void slot78();
virtual void slot7C();
virtual void slot80();
virtual void slot84();
virtual void slot88();
virtual void slot8C();
virtual void slot90();
virtual void slot94();
virtual void slot98(int,int);
char unknown0C[0x2C];unsigned long long flags38;char unknown40[0x78];unsigned int stateB8;
};
extern "C" void fn_80259258(void*);
extern "C" void fn_80023288(View*self){
fn_80259258(self);self->stateB8=0;
self->slot28(11);self->flags38|=0x800000000000ULL;self->slot98(0,0);
self->stateB8=31;
}
