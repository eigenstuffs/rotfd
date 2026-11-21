// Three TeleportVolume callback registrations and original member-pointer constants.
// TeleportVolume.h factory at800BA9BC proves the0xC0-byte object extent.
struct Prefix {union {double alignment;unsigned char storage[8];};};
struct Agent_800C75EC:Prefix {
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
 virtual void slot8C();
 virtual void slot90();
 virtual void slot94();
 virtual void slot98();
 virtual void slot9C();
 unsigned char unknown0C[0xC0-12];
 Agent_800C75EC();~Agent_800C75EC();
};
typedef void (Agent_800C75EC::*MemberFunction)();
extern "C" {
extern unsigned long lbl_80377868;
void fn_800440B0();
void fn_8025E714(Agent_800C75EC*,MemberFunction);
void fn_800C7534(){
 lbl_80377868=0;fn_800440B0();
 Agent_800C75EC object;
 fn_8025E714(&object,&Agent_800C75EC::slot94);
 fn_8025E714(&object,&Agent_800C75EC::slot98);
 fn_8025E714(&object,&Agent_800C75EC::slot9C);
}
}
