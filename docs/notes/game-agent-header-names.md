# Agent header filenames and allocation diagnostic

The isolated ordinary source `src/Game/agent_header_names_802A0E78.cpp`
contains 46 original GLOBAL strings at `802A0E78..802A11D1`.
The full read-only allocation is 857 bytes: 784 bytes of NUL-terminated
strings and 73 bytes in 36 natural four-byte alignment intervals.
The preceding accepted agent-type registry ends exactly at `802A0E78`.
The existing GLOBAL three-byte zero gap `802A11D1..802A11D4` remains
original-only; the following opaque 544-byte object is untouched.

The strings name the native agent headers used by allocation diagnostics.
The source uses ordinary external `const char[]` definitions in original
order, with no padding objects, aliases, helpers, relocations or startup.
Historical canonical, split and source-history preflight found no ownership
overlap or previous definitions. A fresh production compiler object and an
actual private MWLD link reproduce every byte, symbol identity and map owner.

The complete 501,416-position initialized-DOL scan finds no pointers into
the strings, natural gaps or external tail. The complete extabindex,
constructor and destructor tables likewise have no references to them.
Current code relocations remain to be classified after Root's v41 release.

The frozen static proposal is
`scratch/game_agent_header_names_802a0e78_20261011/static_handoff.json`.
It is unregistered and earns zero source credit. Future integration must
preserve the original GLOBAL all-type inventory, exact multiplicity of all
36 internal gap identities, original-only tail ownership, the complete
accepted fallback owner and unrelated existing sources. Root alone changes
shared build files and runs full-game hash, native-link and regression gates.
