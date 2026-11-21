# Early lookup binding wrappers

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`fn_80060240` and `fn_800609B8` are two exact 100-byte ordinary C++ wrappers, compiled with GC/1.3.2 `-O4,s -Cpp_exceptions on`. Each looks up a genuine by-value `Handle_801F7F10` through `fn_801B52EC`, passes it directly to `fn_8025A3C8`, and then invokes `fn_8005C0A8`. Their only difference is the original external resource-name label (0x8029B848 or 0x8029B900).

The return declaration establishes the hidden result pointer and full-expression temporary lifetime. The compiler invokes the native raw Handle destructor with flag -1 and emits the exact 24-byte exception record and 12-byte index. Both first probes match; no assembly, manual temporary destruction, aliases, or native identity migrations are used.

Strict verification proves all 200 text bytes and 72 owned exception/index bytes, actual ELF local names/extents, and all 22 retained relocations plus two nonallocated category references. There are no emitted weak functions, literals, BSS, or padding allocations. The full original extabindex 0x80015F60..0x8001F2C0, constructor array 0x80299920..0x80299980 and destructor array 0x80299980..0x802999A0 are audited; only the retained exception entries refer to these text ranges. Original text gaps immediately after both functions stay outside the source ownership.

Frozen manifests/recheck scripts: `scratch/game_early_lookup_bind/manifest-list.json`. Handoff: `scratch/game_engine_batch87/HANDOFF.md`. Central original-hash acceptance remains pending. Private larger query research at `scratch/game_early_resource_state` is uncredited and released.
