# Flag-selected member query

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`src/Game/flag_member_query.cpp` reconstructs `fn_8005EE10`, `8005EE10..8005EED4`. It reads the 64-bit flags at `38` and checks masks `10000000`, `10000000000`, `20000000000`, and `8000000000` in order. The first three select the subobject at `90`; the last selects the subobject at `60`. No matching flag returns null.

The local type view models a `60`-byte prefix followed by two `30`-byte base subobjects. Ordinary C++ base-pointer conversions preserve the native null-pointer adjustments. The first test uses a signed-byte predicate with a mask argument; the later tests directly use the 64-bit mask expressions. The names describe the observed layout rather than recovered original class names. All methods inline without emitted backups.

Standard GC/1.3.2 emits exactly 196 bytes of `.text`, with no actual code relocations, extra functions, data, BSS, padding, or headers. The complete original extabindex (`80015F60..8001F2C0`), ctors (`80299920..80299980`), and dtors (`80299980..802999A0`) have no ownership for this range. The original DOL SHA1 remains `5da8295a79bf297ab62c620e6ac66210be1c6ef5`.

Run `python3 scratch/game_flag_member_query/verify.py` to reproduce the complete allocated-byte, extent, relocation identity and original-table audit. This partial text split claims no adjacent functions or data. Central whole-DOL acceptance is pending.
