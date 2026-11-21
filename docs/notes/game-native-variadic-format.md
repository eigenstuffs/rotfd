# Native variadic formatter

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`src/Game/native_variadic_format.cpp` reconstructs `fn_801BA714`, `801BA714..801BA7A0`, as the native variadic wrapper around `vsprintf`. The Metrowerks `__builtin_va_info` entry is the same compiler facility used by the existing logger source; the local argument-list layout is the platform ABI's GPR/FPR counters and save-area pointers. The wrapper discards the formatter return value, matching its established caller declarations.

Standard GC/1.3.2 emits exactly140 bytes of `.text` and one actual relocation to `vsprintf`. No inline helpers, initialized data, BSS, padding, or additional allocated sections are emitted. The original extabindex (`80015F60..8001F2C0`), ctors (`80299920..80299980`), and dtors (`80299980..802999A0`) contain no ownership for this range. The original DOL SHA1 remains `5da8295a79bf297ab62c620e6ac66210be1c6ef5`.

Run `python3 scratch/game_native_variadic_format/verify.py` for complete allocated-byte, extent, actual-relocation identity and original-table verification. The manifest and evidence are frozen in that directory. The partial text split claims no neighboring functions or data. Central whole-DOL acceptance is pending.
