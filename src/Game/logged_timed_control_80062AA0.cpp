/* Original logged and timed control delegates; see docs/notes/game-logged-timed-control-delegates.md. */
struct Context{char opaque00[0x110];void*logger;};extern "C"{extern Context lbl_801E9D24;extern const char lbl_8029BAFC[];void fn_801FA014(void*,const char*,...);}extern "C"void fn_80062AA0(void*ignored){fn_801FA014(lbl_801E9D24.logger,lbl_8029BAFC);}
