# GBA transfer polling

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`fn_800C0908` (`800C0908..800C0B1C`, 532 bytes) is an ordinary C++ reconstruction of the transfer-record polling state machine. Cases 6, 7, and 8 deliberately fall through to advance the send/read handshake in a single update. Signed channel values feed the native GBA status, write, and read APIs. Status failures and exhausted timeouts use the original external diagnostic pool.

The first isolated GC 1.3.2 `-proc 750 -O4,s` compile matches every allocated byte and actual relocation: 532 text bytes, 8 extab bytes, and 12 extabindex bytes. The processor setting follows the original metadata's absent ELF-vector flag. The compiler owns local EH symbols `@30` and `@31`; it emits no weak backups, literals, BSS, jump tables, or padding.

The full original exception table and descriptor, constructor/destructor tables, initialized DOL pointer words, and existing compiled-source callers are inventoried in `scratch/game_gba_transfer_poll_800c0908/ownership_audit.json`. The original C entry and the diagnostic/global-record identities remain unchanged. Isolated production validation is complete; central native placement, complete DOL hash, regression checks, and tests remain with the integrator.
