/* Dolphin SDK module-list initialization, GSQE78.
 * Adapted from the public doldecomp/melee SDK reconstruction;
 * see reference/melee-sdk/PROVENANCE.md.
 */
struct OSModuleInfo;
typedef struct { struct OSModuleInfo *head, *tail; } OSModuleQueue;
OSModuleQueue __OSModuleInfoList : 0x800030C8;
const void *__OSStringTable : 0x800030D0;

void __OSModuleInit(void) {
  __OSModuleInfoList.head = __OSModuleInfoList.tail = 0;
  __OSStringTable = 0;
}
