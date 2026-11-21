/* Dolphin SDK system-time C fragment, GSQE78.
 * Adapted from the public doldecomp/melee SDK reconstruction;
 * see reference/melee-sdk/PROVENANCE.md and docs/notes/OSTime.md.
 * Timebase readers remain original fallback assembly.
 */
extern int OSDisableInterrupts(void), OSRestoreInterrupts(int);
extern long long OSGetTime(void);

long long __OSGetSystemTime()
{
    int enabled;
    long long* timeAdjustAddr;
    long long result;

    timeAdjustAddr = (long long*) 0x800030D8;
    enabled = OSDisableInterrupts();

    result = OSGetTime() + *timeAdjustAddr;
    OSRestoreInterrupts(enabled);
    return result;
}

