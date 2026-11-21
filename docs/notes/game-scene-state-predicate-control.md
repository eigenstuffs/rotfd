# Scene state predicate control

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

The isolated source recovers fn_800E54DC (308 bytes) and its complete eight-byte exception record and twelve-byte index. It enables event0x7A with argument15 when the actor enters state0x30 or0x11, and disables that event when the actor leaves both states. The retained byte at owner+58 prevents repeated notifications.

The actor pointer at owner+8, state at actor+320 and Handle at actor+24 are partial views of original accesses. Handle resolution preserves generation comparison, signed index extraction and the original manager/entry layout. The event routines and global manager keep their existing original ownership.

An ordinary inline helper returning int followed by the caller's signed-char conversion recovers the original result lifetime and instruction scheduling. Earlier direct boolean, explicit byte, short and return variants remain private and uncredited. Every retained allocated byte and all eight actual relocations match; there are no weak backups, non-EH data, BSS, padding or symbol migrations. Full original exception/startup/shutdown scans and initialized-data pointer inventory are frozen in the proposal. Central production DOL acceptance is required before credit.
