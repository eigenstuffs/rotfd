#ifndef GAME_AGENT_CLEANUP_VIRTUAL_VIEW_8006590C_H
#define GAME_AGENT_CLEANUP_VIRTUAL_VIEW_8006590C_H

/* Inferred partial derived virtual view; original full tables retain ownership. */
// Inferred partial observed interface only; complete inheritance/type/key provenance unknown.
struct Handle;struct OpaqueHandle;
struct PrimaryPrefix_8006590C {unsigned long unknown00[2];};
struct PrimaryView_8006590C:PrimaryPrefix_8006590C {
 virtual void*cleanup(int);
 virtual void slot_00C();
 virtual void slot_010();
 virtual void slot_014();
 virtual void slot18();
 virtual void slot_01C();
 virtual unsigned long slot20();
 virtual void slot24(unsigned long);
 virtual void slot28(void*);
 virtual int slot2C(void*);
 virtual void slot_030();
 virtual void slot_034();
 virtual void script10();
 virtual void slot_03C();
 virtual void slot40(int);
 virtual void slot44(const OpaqueHandle&);
 virtual void slot_048();
 virtual void slot_04C();
 virtual void slot_050();
 virtual void slot_054();
 virtual void slot_058();
 virtual void slot_05C();
 virtual void slot_060();
 virtual void slot_064();
 virtual void slot_068();
 virtual void slot_06C();
 virtual void slot_070();
 virtual void slot_074();
 virtual void slot_078();
 virtual void slot_07C();
 virtual void slot_080();
 virtual void slot_084();
 virtual void slot_088();
 virtual void slot_08C();
 virtual void slot_090();
 virtual void slot_094();
 virtual void slot_098();
 virtual void slot_09C();
 virtual void slot_0A0();
 virtual void slot_0A4();
 virtual void slot_0A8();
 virtual void slot_0AC();
 virtual void slotB0();
 virtual void slot_0B4();
 virtual void slot_0B8();
 virtual void slot_0BC();
 virtual void slot_0C0();
 virtual void slot_0C4();
 virtual void slot_0C8();
 virtual void slot_0CC();
 virtual void slot_0D0();
 virtual void slot_0D4();
 virtual void slot_0D8();
 virtual void slot_0DC();
 virtual void slot_0E0();
 virtual void slot_0E4();
 virtual void slot_0E8();
 virtual void slot_0EC();
 virtual void slot_0F0();
 virtual void slot_0F4();
 virtual void slot_0F8();
 virtual void slot_0FC();
 virtual void slot_100();
 virtual void slot_104();
 virtual void slot_108();
 virtual void slot_10C();
 virtual void slot_110();
 virtual void slot_114();
 virtual void slot_118();
 virtual void slot_11C();
 virtual void slot_120();
 virtual void slot_124();
 virtual void slot_128();
 virtual void slot_12C();
 virtual const Handle*getControllerHandle();
 char unknown0C[0x28-0xC];unsigned long actor28;float scalar2C;
 char unknown30[0x84-0x30];unsigned long value84;unsigned char value88;char unknown89;unsigned short value8A;char unknown8C[4];
};
struct SecondaryPrefix_8006590C {unsigned long unknown00;};
struct SecondaryView_8006590C:SecondaryPrefix_8006590C {
 virtual void*cleanup(int);
 virtual void slot18();
 virtual void script10();
 virtual void script14();
 virtual void*script18();
 virtual float script1C();
 virtual void script20();
 virtual int script24(int);
 virtual void*script28();
 virtual unsigned long GetHealth();
 virtual unsigned char GetWeaponType();
 virtual unsigned short GetWeaponDamage();
 virtual void script38();
 virtual void script3C(const OpaqueHandle&);
 virtual void script40(int,int);
 virtual void script44(int,void*);
 virtual void script48(int);
 virtual void SetHealth(unsigned long);
 virtual void SetWeaponType(unsigned char);
 virtual void SetWeaponDamage(unsigned short);
 char unknown08[0x160-8];
};
struct AgentCleanupBase_8006590C:PrimaryView_8006590C,SecondaryView_8006590C {
 virtual void SetWeaponDamage(unsigned short);
 virtual void SetWeaponType(unsigned char);
 virtual void SetHealth(unsigned long);
 virtual void script48(int);
 virtual void script44(int,void*);
 virtual void script40(int,int);
 virtual void script3C(const OpaqueHandle&);
 virtual void script38();
 virtual unsigned short GetWeaponDamage();
 virtual unsigned char GetWeaponType();
 virtual unsigned long GetHealth();
 virtual void*script28();
 virtual int script24(int);
 virtual void script20();
 virtual float script1C();
 virtual void*script18();
 virtual void script14();
 virtual void script10();
 virtual void slot18();
 virtual void*cleanup(int);
 char unknown1F0[0x10];
};

// The accepted native CT/DT establishes CSimpleAgent : AgentCleanupBase_8006590C and secondary +0x90.
// Virtual names/signatures are address-qualified inferred observed interfaces, not recovered spelling.
struct CSimpleAgent:AgentCleanupBase_8006590C {
 virtual void script10();
 virtual void slot40(int);
 virtual void slot44(const OpaqueHandle&);
 virtual void slotB0();
 virtual unsigned long slot20();
 virtual void slot24(unsigned long);
 virtual void slot28(void*);
 virtual int slot2C(void*);
 virtual void slot18();
 virtual void*cleanup(int);
 CSimpleAgent();
};
typedef char AgentSize[(sizeof(AgentCleanupBase_8006590C)==0x200)?1:-1];
typedef char ObjectSize[(sizeof(CSimpleAgent)==0x200)?1:-1];


#endif
