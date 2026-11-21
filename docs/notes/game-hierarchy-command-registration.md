# Hierarchy command registration and final-list search

`src/Game/hierarchy_command_registration.cpp` reconstructs two adjacent observed methods at `0x80206524..0x80206868`: command registration (636 bytes) and final-list search (200 bytes). Strict isolated verification passes for all 836 retained bytes with 84 actual relocations applied. Full-DOL and native objdiff verification pass as recorded below. The original complete translation-unit and class names remain unknown.

## Registration

`fn_80206524` registers 24 original console commands, in original order, covering group creation/activation/removal, player membership, camera control and RTC loading/playback. Each entry passes the current console, original command name, original callback address and original help string to `fn_801FAC64`. Source comments preserve the original displayed spelling, including mixed-case names.

All strings remain external original storage. The original method retains `lbl_802AD958` as its shared literal-pool base and uses offsets from it; four shorter command names retain their original `.sdata2` symbols at `0x8037A938`, `0x8037A940`, `0x8037A948` and `0x8037A950`. The source declares an unbounded external char array as a view of this existing pool. It does not claim that the currently named ten-byte first string is the complete pool, merge central symbols, define any literal, or claim original inter-string padding. `external_literals.json` in the scratch directory records the referenced strings and their actual byte extents from the protected original.

The const local pointer `const char* const strings = lbl_802AD958` preserves the original single pool-base register. A mutable local pointer, direct global expressions and an array reference each emitted 848 bytes by rematerializing the base and retaining individual help addresses. The const pointer reproduces all 636 bytes without assembly or compiler patches.

Declarations preserve the existing accepted callbacks' signed-char or void return types. Explicit conversion to the registration API's `int (*)()` callback type records the existing untyped registration convention; no callback implementation is changed or wrapper introduced. The unrecovered `fn_80204F80` declaration follows the signed-char command-result convention inferred from its zero/one returns and neighboring callbacks; this registration only takes its address, so it does not independently establish that return type.

## Search

`fn_802067A0` scans the list with count at `0xD0` and data at `0xD8`. It skips invalid handles, resolves each valid entry with the known signed generation/index layout, and returns the first index whose `fn_8025CEA4` predicate accepts the borrowed input handle. It returns -1 if none matches. No handles are copied, acquired or released.

The validity helper is declared with its established object-pointer return type. The predicate has a signed-char result, preserving the original `extsb.` test. Its second argument remains the borrowed handle pointer: original `fn_8025CEA4` resolves the entry's related handle at `0x68` and forwards r4 unchanged into `fn_801E48EC`, whose original implementation compares resolved handles in an active-member list. No deeper class identity is asserted.

## Complete emitted-section proof

Run `python3 scratch/game_hierarchy_registry/verify.py`. It checks the protected original DOL SHA-1, applies real ELF relocations, and compares every retained byte without masks. The compiler is GC/1.3.2 with `-O4,p -inline auto -Cpp_exceptions off -use_lmw_stmw on`; complete flags and source/object hashes are recorded in `config/GSQE78/candidates/game-hierarchy-command-registration.json`.

The compiler emits exactly one allocated `.text` section of 836 bytes, containing only these two functions in address order. There are no weak helper bodies, data, BSS, exception tables, unaccounted alignment bytes or other allocated sections. All 84 relocations belong to retained code. The verifier checks exact function extents and complete contiguous section coverage.

Central integration passes the original DOL SHA-1 and direct whole-file byte
comparison. Native objdiff records 836/836 code bytes and 2 matching functions;
owned data is zero. The source-section extent guard and generated progress
checks pass. All linked source remains exact; the original baseline is preserved
with only the documented native-accessor and trailing-padding corrections.
