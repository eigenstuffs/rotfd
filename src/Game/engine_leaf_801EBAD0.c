/* Original indexed records, engine setup and allocation-header routines.
 * See docs/notes/game-engine-leaf.md. */

struct Logger {char pad[0x860];int state;char gap[0x41];signed char enabled;char gap2[0x12];float value;};

extern struct {char pad[0x110];struct Logger *logger;char gap[0x100];float value;} lbl_801E9D24;

extern void fn_801FA014(void *,const char *,...);

extern const char lbl_802AD100[],lbl_802AD114[];

extern const float lbl_8037A618;

int fn_801EBAD0(void) {struct Logger *logger=lbl_801E9D24.logger;if(logger->state>2)fn_801FA014(logger,lbl_802AD100);else if(!logger->enabled)fn_801FA014(logger,lbl_802AD114);else if(logger->value>=lbl_8037A618)lbl_801E9D24.value=logger->value;return 1;}

int fn_801EBB54(void) {struct Logger *logger=lbl_801E9D24.logger;if(logger->state>1)fn_801FA014(logger,lbl_802AD100);return 1;}
