/* Native port dispatch constructs a 0xBE8 event context, including two
 * spheres, 64 records and one retained Handle, then submits it to the port.
 * The Handle constructor/destructor remain their existing native providers. */
typedef unsigned long Word;
struct PortPoint {float x,y,z;PortPoint(const PortPoint&p):x(p.x),y(p.y),z(p.z){}};
extern "C" {extern const PortPoint game_vec4_zero;extern const float lbl_8037A58C;void fn_801E15A0(void*);void __construct_array(void*,void(*)(void*),void(*)(void*),unsigned int,unsigned int);void fn_801E2220(void*,void*);void fn_80203D98(void*,void*);extern struct{char unknown00[0x13C];void*service;}lbl_801E9D24;}
struct Handle_801F7F10 {Word word;Handle_801F7F10();~Handle_801F7F10();};
struct PortSphere {PortPoint center;float radius;PortSphere(const PortPoint&p=game_vec4_zero,float r=lbl_8037A58C):center(p),radius(r){}};
struct PortArrayElement {char unknown00[0x24];};
struct PortElementArray {int count;PortArrayElement elements[64];PortElementArray():count(0){__construct_array(elements,fn_801E15A0,0,sizeof(PortArrayElement),64);}};
struct ActorPortContext {Word zero,index,zero08,unknown0C,zero10,zero14,zero18;char unknown1C[0x84];PortSphere first,second;char unknownC0[0x100];PortElementArray array;Word zeroAC4,zeroAC8;char unknownACC[0x118];Handle_801F7F10 handle;ActorPortContext():first(),second(),array(),zeroAC4(0){zero10=0;zero=0;zero08=0;zero14=0;zero18=0;zeroAC8=0;}};
struct ActorPortPrefix {char unknown00[0x278];};
struct ActorPortOwner:ActorPortPrefix {
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
virtual void slotA0();
virtual void slotA4();
virtual void slotA8();
virtual void resetPort(int);
};
extern "C" void fn_801E1494(ActorPortOwner*self,int port){self->resetPort(port);ActorPortContext context;context.index=port;ActorPortOwner*actor=(ActorPortOwner*)((char*)self+port*0x4C);fn_801E2220(actor,&context);if(port==6)fn_80203D98(lbl_801E9D24.service,actor);}

typedef char PortPointSize[sizeof(PortPoint)==12?1:-1];
typedef char PortSphereSize[sizeof(PortSphere)==16?1:-1];
typedef char PortElementSize[sizeof(PortArrayElement)==36?1:-1];
typedef char PortContextSize[sizeof(ActorPortContext)==0xBE8?1:-1];
