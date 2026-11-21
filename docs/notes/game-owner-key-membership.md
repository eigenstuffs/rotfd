# Owner key membership

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`src/Game/owner_key_membership.cpp` reconstructs `fn_8005B0F0`, `8005B0F0..8005B1FC`, as a lookup against seven provider keys. The object holds a provider pointer at `EC` and two key words at `F0/F4`. Provider records are checked in order `28`, `78`, `198`, `1A8`, `1B8`, `1C8`, `188`; their two words are stored in the reverse order to the owner's pair. The function returns one for a match and zero otherwise.

The source caches the owner's first word and reuses two comparison locals across the records. This preserves the native load and register allocation while retaining ordinary C++ expressions. Earlier per-record scopes and value-returning key wrappers remain private diagnostic probes in `scratch/game_owner_key_membership`; they are not matching source.

Standard GC/1.3.2 emits exactly 268 bytes of `.text`, with no actual code relocations, extra functions, data, BSS, or padding. The complete original extabindex (`80015F60..8001F2C0`), ctors (`80299920..80299980`), and dtors (`80299980..802999A0`) have no ownership for the retained range. The original DOL SHA1 remains `5da8295a79bf297ab62c620e6ac66210be1c6ef5`.

Run `python3 scratch/game_owner_key_membership/verify.py` to reproduce the complete allocated-byte, extent, relocation identity and original-table audit. This partial text split claims no adjacent functions or data. Central whole-DOL acceptance is pending.
