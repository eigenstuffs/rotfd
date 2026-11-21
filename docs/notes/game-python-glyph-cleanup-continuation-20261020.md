# Python event names, input glyph tokens and native cleanup

This continuation adds 284 data bytes and one eight-byte function. The source
was staged NonMatching and compared as complete compiler objects before native
link acceptance.

## Data ownership

`scene_controller_default_constants.c` expands to 88 bytes at `80378650`.
`python_controller_type_names_803786B0.c` supplies 16 bytes and
`python_event_names_80378780.c` supplies 76 bytes. These three complete objects
preserve eight existing bytes and add 172. Their 22 strings, float and natural
alignment are checked against all 38 incoming references in 18 unchanged whole
consumer objects, including two RTTI name pointers. Twenty adjacent original
bytes retain explicit ownership and receive no source credit.

`input_glyph_constants.c` expands to 124 bytes at `8037AB30`, incorporating
the old four-byte scalar owner at `8037ABA8`. The gain is 112 bytes: 15 character
arrays totaling 87 bytes and 25 bytes of natural internal alignment. All 18
GLOBAL definitions and 20 references from the unchanged input-glyph consumer
are preserved. The following 36 original bytes remain a separate unit.

Frozen evidence is in `scratch/python_event_names_20261020_parallel/` and
`scratch/input_glyph_tokens_20261020_parallel/`. Their audits enumerate every
active input, actual relocation and possible raw data pointer. No unrelocated
pointer into either migrated range was found.

## Native cleanup adjustor

The shared `OwnerCleanupVirtualView_80095F4C` declaration makes the existing
228-byte cleanup routine and leaf methods one consistent C++ virtual interface.
The compiler generates the eight-byte secondary-base cleanup adjustor at
`80096524`; the leaf source now owns 24 bytes. The exact primary cleanup and
72 exception bytes remain unchanged.

Four identities are renamed consistently across six complete original virtual
tables totaling 2,564 bytes. All 22 actual incoming references and the unique
GLOBAL/WEAK providers are checked. The compiler's unused 32-byte partial virtual
table remains in the whole object and is discarded by the native linker; it
receives no source credit. No code or object bytes were patched.

Frozen evidence is in
`scratch/resource_finder_inline_20261020/native_owner_adjustor_80096524/`.
The old source files and their historical receipts remain preserved.

## Acceptance

The complete standard build passes DOL SHA-1
`5da8295a79bf297ab62c620e6ac66210be1c6ef5`, with no baseline regressions,
66 tests passing and all 5,749 linked source extents valid. Both native map
outputs agree with the standard ELF at SHA-256
`8eb9d5e88ace242eaa3fc41b92b11a47b41676cbec60b4b8fda2fefdadf6a48b`.

Generated totals are 1,950,304 / 2,607,776 code bytes (74.7880%),
7,997 / 8,803 functions, and 978,173 / 1,030,936 data bytes (94.8820%).
