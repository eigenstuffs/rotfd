# Actor action and flag selection at 80092E70

`src/Game/actor_action_flag_selection_80092E70.cpp` reconstructs the existing C
entry `fn_80092E70`, all 1,212 text bytes, its 24-byte exception record and 12-byte
index. It checks component states, selects or copies a callback record, assigns
its target Handle, chooses a scalar from observed target flags, updates an actor
counter, performs a named resource operation and forwards two final events.

The private record view has a signed key at 0, words at 4/8, bytes at C/D,
implicit alignment padding at E/F, and words/pointers from 10 through 2C;
its extent is 48 bytes. Making the padding an explicit copied member emits
additional loads/stores. The owner has Handles at 24 and 348 and a component
at 318. Resolved actor fields used here are Handle 28, float 2C and counter 84.
The target view establishes 64-bit flags at 38, byte 70 and shorts 86/8A.
Names and opaque fields remain provisional private layout views.

Only the first flag query materializes a signed-character result; later masks
test the 64-bit field directly. The Handle assignment uses a real full-expression
temporary with the native destructor and exception action at stack 14. A genuine
inline Name helper constructs a named local and returns it by value; this retains
the original Name slots C and 10 while placing that earlier Handle temporary at
14. Returning `Name(text)` directly elides the required copy and emits 1,208 bytes.
The final lookup returns its address as a word, converted at the pointer argument,
which preserves the original lifetime of the first two event arguments.

GC 1.3.2 Gekko with `-O4,s -inline auto -Cpp_exceptions on -use_lmw_stmw on`
matches every owned byte and actual relocation. All allocated sections and symbols
are inventoried; no additional helpers, weak bodies, literals or metadata are
emitted. The complete original exception-index, startup-table and initialized-word
audits find only the expected index pointer into this function. Existing callers,
the C identity, borrowed names/constants and all other original data ownership
remain unchanged. This is a partial original translation unit.

Frozen evidence is under `scratch/game_actor_action_flag_selection_80092e70`.
Isolated strict recompilation passes. Full original-DOL hash, no regressions,
all source extents, tests and linked acceptance remain parent integration
requirements before source credit.
