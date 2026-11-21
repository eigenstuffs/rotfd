# Fixed group array constructor

`src/Game/group_constructor.cpp` and its private header recover the complete
452-byte function at `0x801FFC94..0x801FFE58`. The reconstructed native C++ name
is `__ct__14Group_801FFC94Fv`; the original class name remains unknown. This is a
bounded source fragment with 27 owned `.rodata` bytes, with no claim that it is
the complete original translation unit.

The constructor builds four `Handle_801FFE58` array elements through the existing
native constructor/destructor callbacks at `0x801FFEBC` and `0x801FFE58`, then
zeros the dynamic list's count, capacity, and pointer. For each fixed slot it
clears the corresponding flag, hashes `CameraUser` and `TmpCameraUser`, obtains
a handle through `fn_801B550C`, and assigns it with reference accounting. It
resolves the resulting handle twice and writes the slot index to object offsets
`0x24` and `0x20`. Finally it clears the paused byte at `0x20` of the group.
The names `identifier` and `order` describe these recovered fields provisionally.

Native C++ array construction emits the original `__construct_array` call with
element size four, count four, and the canonical callback identities. A temporary
handle derives through two zeroing layers before copying the returned base
handle and increasing its reference count. This preserves both zero stores via
the retained temporary address. An explicit second zero in the copy constructor
had the same size but addressed the second store through the stack pointer.
The two repeated lookups require a signed generation byte read at
`table + index * 16 + 12` before forming the typed entry pointer used to read the
object. Forming the entry pointer first gave ten different register encodings;
the final source preserves the observed read order with ordinary C++.

The source now owns `.rodata` at `0x802AD8D8..0x802AD8F3`: the 14-byte
`TmpCameraUser` string including its NUL, two compiler-emitted internal alignment
zeros, and the 11-byte `CameraUser` string including its NUL. Explicit true-size
`const char` definitions precede their first use, which makes CodeWarrior emit
the original `.rodata` rather than `.data`. The section is exactly 27 bytes with
alignment eight; its start satisfies that alignment. The following five original
bytes at `0x802AD8F3..0x802AD8F8` have a separate fallback padding owner and receive
no source credit. No BSS or exception metadata is emitted.

Three unreferenced weak destructors total 264 bytes and six
relocations; the verifier accounts for their complete extents and excludes them
from matching credit through normal linker dead stripping.

The stable manifest is `config/GSQE78/candidates/game_group_constructor.json`.
Run `python3 scratch/game_group_constructor/verify.py` to compile with GC/1.3.2
and compare every retained byte after applying the ELF's actual relocation
records. The recorded isolated result is **452 text bytes, 20 retained
relocations, zero differences**. The literal extension's complete proof is in
`scratch/game_literal_ownership/verification.json`; it also confirms that the
entire raw text and relocation semantics, including all weak bodies, remain
unchanged from the prior accepted constructor. The verifier checks the original DOL SHA-1
`5da8295a79bf297ab62c620e6ac66210be1c6ef5`, all function/section extents,
private source/header hashes, and absence of retained references to discarded
helpers. Full-DOL and native objdiff integration are verified below.
The source and object SHA-256 values are recorded in the manifest and
`scratch/game_group_constructor/verification.txt`.

Central integration passes the original DOL SHA-1 and direct whole-file byte
comparison. Native objdiff records 452/452 code bytes, 1 matching function, and
27/27 owned data bytes. The source-section extent guard and generated progress
checks pass. All linked source remains exact; the original baseline is preserved
with only the documented native-accessor and trailing-padding corrections.
