/* Engine context storage (0x21C bytes, zero in the DOL). The original
 * executable keeps this global inside .text, directly before the stream copy
 * helper fn_801E9F40 (src/Game/stream_copy_801E9F40.c). Matched sources
 * reference it as `extern "C" ... lbl_801E9D24;` through private partial
 * views (+0x110 logger, +0x118 handle manager, ...). CodeWarrior warns that the
 * RW object changes the section permission; the emitted .text keeps flags AX
 * and 4-byte alignment like the original split. */
struct EngineContext_801E9D24 {
    unsigned long words[0x21C / 4];
};

__declspec(section ".text") struct EngineContext_801E9D24 lbl_801E9D24;
