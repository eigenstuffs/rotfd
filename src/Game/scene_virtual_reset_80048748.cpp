/* Original virtual callback reset; see docs/notes/game-repeated-virtual-resets.md. */
struct Prefix{unsigned long unknown00[2];};
struct Object_80048748:Prefix{
 virtual void slot08();
 virtual void slot0C();
 virtual void slot10();
 virtual void slot14();
 virtual void slot18();
 virtual void slot1C();
 virtual void slot20();
 virtual void slot24();
 virtual void slot28();
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
 virtual void reset(unsigned long,unsigned long);
};
extern "C" {void fn_80256370(void*);void fn_802073E8(Object_80048748*,int,Object_80048748*,float);extern const float lbl_80378560;}
extern "C" void fn_80048748(Object_80048748*self){
 self->reset(0,0);
 self->reset(0,0);
}
