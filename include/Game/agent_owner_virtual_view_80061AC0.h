#ifndef GAME_AGENT_OWNER_VIRTUAL_VIEW_80061AC0_H
#define GAME_AGENT_OWNER_VIRTUAL_VIEW_80061AC0_H
/* Inferred partial virtual view; original full tables remain external. */
// Partial observed virtual slots/base extents; method names and complete class provenance are inferred.
struct Owner_80061AC0; struct Handle_801F7F10;
struct PrimaryPrefix_80061AC0 { unsigned long unknown00[2]; };
struct PrimaryView_80061AC0 : PrimaryPrefix_80061AC0 { virtual ~PrimaryView_80061AC0(); char unknown0C[0x60-0xC]; };
struct SecondaryPrefix_80061AC0 { unsigned long unknown00; };
struct SecondaryView_80061AC0 : SecondaryPrefix_80061AC0 {
 virtual ~SecondaryView_80061AC0();
 virtual void slot18();
 virtual void script10();
 virtual void script14();
 virtual void* script18();
 virtual float script1C();
 virtual void* script20();
 virtual int script24(int);
 virtual void* script28();
 virtual int GetHealth();
 virtual int GetWeaponType();
 virtual int GetWeaponDamage();
 virtual void script38();
 virtual void script3C(const Handle_801F7F10&);
 virtual void script40(int,int);
 virtual void script44(int,void*);
 virtual int script48(int);
 virtual void SetHealth(unsigned long);
 virtual void SetWeaponType(unsigned char);
 virtual void SetWeaponDamage(unsigned short);
 virtual void script58();
 virtual void script5C();
 virtual void script60();
 char unknown08[0x160-8];
};
struct CLevelAgent : PrimaryView_80061AC0, SecondaryView_80061AC0 {
 char unknown1C0[0x1F8-0x1C0]; Owner_80061AC0*owner;
 virtual void script60();
 virtual void script5C();
 virtual void script58();
 virtual void SetWeaponDamage(unsigned short);
 virtual void SetWeaponType(unsigned char);
 virtual void SetHealth(unsigned long);
 virtual int script48(int);
 virtual void script44(int,void*);
 virtual void script40(int,int);
 virtual void script3C(const Handle_801F7F10&);
 virtual void script38();
 virtual int GetWeaponDamage();
 virtual int GetWeaponType();
 virtual int GetHealth();
 virtual void* script28();
 virtual int script24(int);
 virtual void* script20();
 virtual float script1C();
 virtual void* script18();
 virtual void script14();
 virtual void script10();
 virtual void slot18();
 virtual ~CLevelAgent();
};

#endif
