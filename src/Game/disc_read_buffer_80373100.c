/* Buffer used by the disc-recovery read; its native allocation is 32 bytes. */
char lbl_80373100[32];
typedef char DiscReadBufferExtent[sizeof(lbl_80373100) == 32 ? 1 : -1];
