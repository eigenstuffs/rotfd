#ifndef GAME_EARLY_LOOKUP_BIND_VIEWS_H
#define GAME_EARLY_LOOKUP_BIND_VIEWS_H
struct Handle_801F7F10{unsigned long value;Handle_801F7F10();~Handle_801F7F10();};
struct LookupBindManager;
struct LookupBindContext{char unknown00[0x118];LookupBindManager*manager;};
extern "C" LookupBindContext lbl_801E9D24;
extern "C" {Handle_801F7F10 fn_801B52EC(LookupBindManager*,const char*);void fn_8025A3C8(void*,const Handle_801F7F10&);void fn_8005C0A8(void*);extern const char lbl_8029B848[],lbl_8029B900[];}
#endif
