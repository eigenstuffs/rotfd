# Console command dispatch and help

The group after the main parser manages command history, direct dispatch, registration, and help output. The allocation metadata for the registration function identifies `ConsoleCommand_Z.cpp:22`; the complete original source-file boundary remains unestablished. The reconstructed node is 220 bytes, with a 64-byte name, 128-byte help text, 16-byte abbreviation, callback at `0xD0`, and next/previous links at `0xD4`/`0xD8`.

Two source fragments have strict isolated matches:

- `src/Game/logger_dispatch.cpp`: `0x801FAB38..0x801FAC64`, one 300-byte routine. It finds a case-insensitive name or abbreviation, invokes the zero-argument callback, prints help if that callback returns false, and logs an unknown-command message when nothing matches. Its two messages are references to already-owned parser literals. It owns no data. `scratch/game_logger_dispatch/verify.py` applies all 15 relocations and compares the entire allocated text section.
- `src/Game/logger_help.cpp`: `0x801FADD0..0x801FAE58`, the 128-byte help printer and two four-byte empty hooks. It owns 31 `.rodata` bytes at `0x802AD5C0..0x802AD5DF`: two 15-byte strings and one internal alignment byte. The byte at `0x802AD5DF` is outside this source's ownership. `scratch/game_logger_help/verify.py` applies six relocations and compares every allocated code/data byte.

Both use GC/1.3.2 with `-O4,p -inline deferred -use_lmw_stmw on`. The verifiers resolve external small-data relocations using the dependency's actual section, preserving the original `r2` addressing for the shared help format. Both fragments passed full-DOL identity and native objdiff integration, including every owned data byte. No raw assembly, patched instructions, masked comparisons, or volatile workarounds are used.

`src/Game/logger_registration.cpp` passes central full-DOL integration and native objdiff: 364 text bytes at `801FAC64..801FADD0`, 37 rodata bytes at `802AD598..802AD5BD`, and all 14 relocations are exact. It allocates a node, initializes its links and callback, copies its name/help, constructs an abbreviation from uppercase letters and digits, rejects duplicate abbreviations, and prepends the node to the list. An ordinary fixed `StringBuffer<16>` member with character-pointer conversion and indexed access preserves the 220-byte node layout and reproduces the original abbreviation address mode and registers. Ordinary placement new and the observed inline constructor reproduce the null check. The three following alignment bytes remain separate original data.

## History wrapper near-match

The 300-byte history/semicolon wrapper at `801FAA0C..801FAB38` remains original fallback and earns no matched credit. It updates the fixed history list, splits input on semicolons, invokes the main parser for each part, and returns the final command's result. The closest standalone source is `scratch/game_console_remaining/history_nearmatch.cpp`; its relocation-aware result is preserved in `history_nearmatch_verification.txt`. All seven relocations resolve, and only seven bytes in three instructions differ:

| Address | Original | Candidate |
| --- | --- | --- |
| `801FAA94` | `li r26,0` | `li r27,0` |
| `801FAA9C` | `mr r27,r26` | `mr r28,r27` |
| `801FAAA0` | `mr r28,r26` | `li r26,0` |

Every other instruction is exact. A byte cursor through the history records, decremented before the index, recovers the history loop's original register allocation. The remaining distinction is counter/terminator initialization. C++ method boundaries, inline history helpers, equivalent initialization and loop forms, indexing wrappers, index types and bounded optimizer probes did not resolve it. No instructions are patched or ignored. The earlier complete six-function draft remains preserved at `scratch/game_logger_commands/near-match.cpp`; new bounded probes live under `scratch/game_console_remaining`.

The protected original DOL SHA-1 remains `5da8295a79bf297ab62c620e6ac66210be1c6ef5`.

## Script interpreter callback

`src/Game/logger_interpreter.cpp` now matches the complete 400-byte callback at `801FAE58..801FAFE8`, plus the 14-byte `ConsoleInterp` string at `802AD5E0..802AD5EE`. All 22 retained relocations and both allocated sections pass strict isolated comparison. The two following alignment bytes remain outside ownership. Central full-DOL integration and native objdiff code/data checks both pass.

The callback copies the current argument arrays, lazily obtains the script interpreter by hashed name, resolves its generation-checked handle, initializes it and loads the requested script. It retains the observed 92-byte file-object storage. The actual `Handle_801F7F10` constructor/destructor ABI is essential: a derived handle wrapper with two inline initialization layers retains the original saved pointer and both zero stores. Its scope exit naturally calls the base destructor with flag zero. The factory's hidden result pointer is explicit, followed by destruction of that temporary with flag minus one; fully implicit C++ factory temporaries preserve the instructions but reorder four stack slots. This distinction is recorded as reconstructed ABI handling, not an original class hierarchy claim.

Three unreferenced local inline destructors totaling 264 bytes are emitted after the retained callback. The manifest records them for ordinary linker dead stripping and excludes them from progress. No retained relocation refers to those helpers. The full verification transcript is `scratch/game_console_remaining/logger_interpreter_verification.txt`.
