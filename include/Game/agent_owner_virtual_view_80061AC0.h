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
 virtual void method_80061DD8();
 virtual void method_80061ED4();
 virtual void method_80062CF4();
 virtual void* method_80062CA8();
 virtual float method_80062CA0();
 virtual void* method_80062C98();
 virtual int method_80062C78(int);
 virtual void* method_80062C70();
 virtual int method_80062C34();
 virtual int method_80062BF8();
 virtual int method_80062BBC();
 virtual void method_80062BB8();
 virtual void method_80062B20(const Handle_801F7F10&);
 virtual void method_80062B1C();
 virtual void method_80062B18();
 virtual int method_80062B10();
 virtual void method_80062AD8();
 virtual void method_80062AA0();
 virtual void method_80062A68();
 virtual void method_80062A64();
 virtual void method_80062A40();
 virtual void notifyOwner();
 char unknown08[0x160-8];
};
struct Agent_80061AC0 : PrimaryView_80061AC0, SecondaryView_80061AC0 {
 char unknown1C0[0x1F8-0x1C0]; Owner_80061AC0*owner;
 virtual void notifyOwner();
 virtual void method_80062A40();
 virtual void method_80062A64();
 virtual void method_80062A68();
 virtual void method_80062AA0();
 virtual void method_80062AD8();
 virtual int method_80062B10();
 virtual void method_80062B18();
 virtual void method_80062B1C();
 virtual void method_80062B20(const Handle_801F7F10&);
 virtual void method_80062BB8();
 virtual int method_80062BBC();
 virtual int method_80062BF8();
 virtual int method_80062C34();
 virtual void* method_80062C70();
 virtual int method_80062C78(int);
 virtual void* method_80062C98();
 virtual float method_80062CA0();
 virtual void* method_80062CA8();
 virtual void method_80062CF4();
 virtual void method_80061ED4();
 virtual void method_80061DD8();
 virtual ~Agent_80061AC0();
};

#endif
