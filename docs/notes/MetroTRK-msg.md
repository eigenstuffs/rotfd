# MetroTRK message sender — matched

**Status (2026-10-24):** `src/MetroTRK/msg_send.c` matches TRKMessageSend exactly (0x80117FE4..0x801181C0, standard MetroTRK cflags as for msgbuf.c) and is linked as Matching. Three details closed the earlier gap: an `int` loop counter for the unrolled checksum, the FCS written by a one-pass `for (i = 0; i < sizeof(FCSType); i++)` loop (explaining the dead `cmpwi` after the last write), and a block-scoped `u8 fcsByte = (u8)fcs;` inside it. The checksum is `fcs = (FCSType)(fcs + b->fData[i])` then `fcs = fcs ^ 0xFF`. The older research source `src/MetroTRK/msg.c` is kept unregistered for reference.

The history below records the earlier, pending state.

The original TRKMessageSend range is 0x80117FE4..0x801181C0 (476 bytes). This version frames its payload rather than calling the simple block UART writer used by the Melee, SMS and Pikmin 2 references. The function is not configured as matching, and no accepted candidate manifest exists.

Target control flow establishes the protocol: sum payload bytes modulo 256, complement the sum, write delimiter 0x7E, escape payload and checksum bytes 0x7E/0x7D by writing 0x7D then XORing the byte with 0x20, write the closing delimiter, and flush. Every stage preserves the first writer error. Calls identify a byte-buffering writer at 0x8011E36C and its flush routine at 0x8011E394; the names TRKWriteUART1 and TRKFlushUART in this research source are inferred from that behavior.

`src/MetroTRK/msg.c` expresses those algorithms in C. Current GC/1.3.2 output is 468 bytes, with 196 bytes matching at their target positions; register allocation in the unrolled checksum and the final checksum-write control flow remain unresolved. The source owns no data. No native assembly or placeholder is used, and none of these bytes counts as C completion.

The isolated compiler and verifier are `scratch/MetroTRK/compile_msg.py` and `verify_msg.py`. The verifier uses the two independently inspected external target addresses and will only emit a candidate when all relocated text bytes match. The readable revisions and bounded type/inlining experiments are retained in scratch for further work.
