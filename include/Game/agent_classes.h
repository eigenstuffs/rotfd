#ifndef GAME_AGENT_CLASSES_H
#define GAME_AGENT_CLASSES_H
/* Class hierarchy reconstructed from the original RTTI records and vtables.
 * Slot names are provisional: slotXX/scriptXX name the byte offset of the slot
 * in the vtable of the class that introduces it. */
struct Handle_801F7F10;
struct OpaqueHandle;
struct BaseObject_Z {
    unsigned long unknown0; unsigned long identity;
    virtual ~BaseObject_Z();
    virtual void slot0C(unsigned long);
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1C();
};
struct ABC_Agent : BaseObject_Z {
    virtual unsigned long slot20();
    virtual void slot24(unsigned long);
    virtual void slot28(void*);
    virtual int slot2C(void*);
    virtual void slot30();
    virtual void slot34();
    virtual ~ABC_Agent();
};
struct Agent_Z : ABC_Agent {
    virtual void script10();
    virtual void slot3C();
    virtual void slot40(int);
    virtual void slot44(const OpaqueHandle&);
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
    virtual unsigned long slot20();
    virtual void slot24(unsigned long);
    virtual void slot28(void*);
    virtual int slot2C(void*);
    virtual ~Agent_Z();
    char pad_Agent_Z[0x54];
};
struct CScriptAgent {
    unsigned long unknown00;
    virtual ~CScriptAgent();
    virtual void slot18();
    virtual void script10();
    virtual void script14() = 0;
    virtual void* script18() = 0;
    virtual float script1C() = 0;
    virtual void* script20() = 0;
    virtual signed char script24(int) = 0;
    virtual void* script28() = 0;
    virtual unsigned long GetHealth() = 0;
    virtual unsigned char GetWeaponType() = 0;
    virtual unsigned short GetWeaponDamage() = 0;
    virtual void script38() = 0;
    virtual void script3C(const Handle_801F7F10&) = 0;
    virtual void script40(int, int) = 0;
    virtual void script44(int, void*) = 0;
    virtual int script48(int) = 0;
    virtual void SetHealth(unsigned long) = 0;
    virtual void SetWeaponType(unsigned char) = 0;
    virtual void SetWeaponDamage(unsigned short) = 0;
    virtual void script58();
    virtual void script5C();
    virtual void script60();
    char unknown08[0x160-8];
};
struct CLevelAgent : Agent_Z, CScriptAgent {
    virtual int slot2C(void*); // key function
    virtual void slotD8();
    virtual void slotDC();
    virtual void* script18();
    virtual float script1C();
    virtual void* script20();
    virtual signed char script24(int);
    virtual void script38();
    virtual void script14();
    virtual unsigned long GetHealth();
    virtual unsigned char GetWeaponType();
    virtual unsigned short GetWeaponDamage();
    virtual void* script28();
    virtual void script3C(const Handle_801F7F10&);
    virtual void script40(int, int);
    virtual void script44(int, void*);
    virtual int script48(int);
    virtual void SetHealth(unsigned long);
    virtual void SetWeaponType(unsigned char);
    virtual void SetWeaponDamage(unsigned short);
    virtual void script58();
    virtual void script5C();
    virtual void script60();
    virtual void script10();
    virtual void slot18();
    virtual unsigned long slot20();
    virtual void slot24(unsigned long);
    virtual void slot28(void*);
    virtual void slot30();
    virtual void slot34();
    virtual void slot40(int);
    virtual void slot44(const OpaqueHandle&);
    virtual ~CLevelAgent();
};
struct AnimatedMsgAgent_Z : Agent_Z {
    virtual ~AnimatedMsgAgent_Z();
};
struct AnimatedAgent_Z : AnimatedMsgAgent_Z {
    virtual void slot74();
    virtual void slot64();
    virtual void slot68();
    virtual ~AnimatedAgent_Z();
};
struct MovingAgent_Z : AnimatedAgent_Z {
    virtual void slot78();
    virtual void slot1C();
    virtual void slot30();
    virtual void slot34();
    virtual void slot3C();
    virtual void slot44(const OpaqueHandle&);
    virtual ~MovingAgent_Z();
};
struct Throwable_Z : MovingAgent_Z {
    virtual void slot7C();
    virtual void slot80();
    virtual void slot84();
    virtual void slot88();
    virtual void slot8C();
    virtual void slot90();
    virtual void slot54();
    virtual void slot58();
    virtual void slot5C();
    virtual void slot60();
    virtual ~Throwable_Z();
};
struct LodAgent_Z : Throwable_Z {
    virtual void slot94();
    virtual void slot98();
    virtual void slot9C();
    virtual void slotA0();
    virtual void slotA4();
    virtual void slotA8();
    virtual ~LodAgent_Z();
};
struct CActorAgent : LodAgent_Z {
    virtual void slotAC();
    virtual void slotB0();
    virtual void script10();
    virtual void slot18();
    virtual unsigned long slot20();
    virtual void slot24(unsigned long);
    virtual void slot28(void*);
    virtual int slot2C(void*);
    virtual void slot40(int);
    virtual void slot44(const OpaqueHandle&);
    virtual void slot4C();
    virtual void slot50();
    virtual ~CActorAgent();
    char pad_CActorAgent[0x30];
};
struct CActorScriptAgent : CActorAgent, CScriptAgent {
    virtual int slot2C(void*); // key function
    virtual void slot118();
    virtual void script14();
    virtual void* script18();
    virtual float script1C();
    virtual void* script20();
    virtual signed char script24(int);
    virtual void* script28();
    virtual unsigned long GetHealth();
    virtual unsigned char GetWeaponType();
    virtual unsigned short GetWeaponDamage();
    virtual void script38();
    virtual void script3C(const Handle_801F7F10&);
    virtual void script40(int, int);
    virtual void script44(int, void*);
    virtual int script48(int);
    virtual void SetHealth(unsigned long);
    virtual void SetWeaponType(unsigned char);
    virtual void SetWeaponDamage(unsigned short);
    virtual int slot160(int, void*);
    virtual void script10();
    virtual void slot18();
    virtual unsigned long slot20();
    virtual void slot24(unsigned long);
    virtual void slot28(void*);
    virtual void slot30();
    virtual void slot34();
    virtual void slot3C();
    virtual void slot40(int);
    virtual void slot44(const OpaqueHandle&);
    virtual void slot48();
    virtual void slotB0();
    virtual ~CActorScriptAgent();
};
struct CMediumAgent : CActorScriptAgent {
    virtual ~CMediumAgent(); // key function
    virtual void script10();
    virtual void slot18();
    virtual unsigned long slot20();
    virtual void slot24(unsigned long);
    virtual void slot28(void*);
    virtual int slot2C(void*);
    virtual void slot40(int);
    virtual void slot44(const OpaqueHandle&);
    virtual void slotB0();
};
struct CSimpleAgent : CActorScriptAgent {
    virtual ~CSimpleAgent(); // key function
    virtual void script10();
    virtual void slot18();
    virtual unsigned long slot20();
    virtual void slot24(unsigned long);
    virtual void slot28(void*);
    virtual int slot2C(void*);
    virtual void slot40(int);
    virtual void slot44(const OpaqueHandle&);
    virtual void slotB0();
};
struct CComplexAgent : CActorScriptAgent {
    virtual ~CComplexAgent(); // key function
    virtual void script10();
    virtual void slot18();
    virtual unsigned long slot20();
    virtual void slot24(unsigned long);
    virtual void slot28(void*);
    virtual int slot2C(void*);
    virtual void slot40(int);
    virtual void slot44(const OpaqueHandle&);
    virtual void slotB0();
};
#endif
