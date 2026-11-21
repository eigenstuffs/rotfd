/* Original indexed records, engine setup and allocation-header routines.
 * See docs/notes/game-engine-leaf.md. */

extern void VISetBlack(int);

extern void VIFlush(void);

extern void VIWaitForRetrace(void);

extern void GXDrawDone(void);

extern void GXAbortFrame(void);

extern void LCDisable(void);

extern int __PADDisableRecalibration(int);

extern void OSResetSystem(int,unsigned int,int);

void fn_801EBE14(void) {VISetBlack(1);VIFlush();VIWaitForRetrace();GXDrawDone();GXAbortFrame();LCDisable();__PADDisableRecalibration(0);OSResetSystem(1,0,1);}
