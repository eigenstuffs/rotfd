/* Platform owner destructor; see docs/notes/game-platform-owner-destructor.md. */
#include "Game/service_interface_tables.h"
typedef unsigned long Word;struct Table{Word unknown[4];void(*cleanup)(void*);};
extern "C"{extern char lbl_801EF5C8[],lbl_802F16D0[];void fn_801EF610(void*,void*);}
struct Storage{Word unknown00[2];};struct Dispatch:Storage{virtual void slot08();virtual void slot0C();virtual void cleanup();};
struct PlatformBase{Word unknown00[2];Table*table;~PlatformBase(){table=(Table*)&lbl_802EA0F8;((Dispatch*)this)->cleanup();}};
struct PlatformOwner_8028C1E8:PlatformBase{~PlatformOwner_8028C1E8();static void operator delete(void*p){fn_801EF610(lbl_801EF5C8,p);}};
PlatformOwner_8028C1E8::~PlatformOwner_8028C1E8(){table=(Table*)lbl_802F16D0;((Dispatch*)this)->cleanup();}
