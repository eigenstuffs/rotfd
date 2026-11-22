struct ManagerPrefix{char unknown0[0x24];};struct Manager:ManagerPrefix{virtual void clear();};
extern "C" struct Globals{char unknown0[0x118];Manager*manager;}lbl_801E9D24;
extern "C" int fn_801B4BF4(){lbl_801E9D24.manager->clear();return 1;}
