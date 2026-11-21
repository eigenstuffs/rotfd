/* Original delegate; partial views described in docs/notes/game-small-delegates-20261011.md. */
struct ManagerPrefix{char unknown0[0x24];};struct Manager:ManagerPrefix{virtual void slot08();virtual void slot0C();virtual void slot10();virtual void slot14();virtual void slot18();virtual void slot1C();virtual void reset();char unknown28[0xCA-0x28];unsigned char active;};
extern "C" struct Globals{char unknown0[0x118];Manager*manager;}lbl_801E9D24;
extern "C" int fn_801B3A90(){lbl_801E9D24.manager->active=0;lbl_801E9D24.manager->reset();return 1;}
