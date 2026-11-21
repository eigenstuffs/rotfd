# Cached render color update

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Isolated exact source; central full-DOL acceptance pending.

`src/Game/render_cached_color_update.cpp` reconstructs `fn_80272708`, all 280
bytes at `80272708..80272820`. It compares the supplied RGB values against the
cached vector at receiver offset `0x3A0` with the original tolerance, updates
that cache only when a component differs, scales the components to bytes,
sets alpha to 255 and uploads TEV color register 2.

The two-component comparison returns an integer initialized to zero through
explicit nested comparisons. The enclosing comparison returns a signed byte.
Those ordinary source expressions preserve the original result registers and
signed-byte test; equivalent logical forms produced different instructions.
The input component evaluations follow X, Z, Y, matching the original float
register allocation. The color argument is a normal four-byte aggregate by
value, including its original outgoing stack copy.

GC/1.3.2 with the recorded optimized Game flags reproduces all 280 allocated
bytes and four actual relocations. The original tolerance and scale constants
remain external under their existing owners. The object emits only this global
text function: no additional helpers, literals, data, BSS, padding, exception
records or startup/shutdown entries. Full original exception-index, ctor and
dtor scans find no references requiring additional ownership.

`scratch/game_render_projection_updates/color_final_integration.json` records
the frozen source/object hashes, exact callable inventory and actual resolved
references. `freeze_color.py` preserves the production recompile evidence.
Adjacent matrix/projection probes in that directory are private and receive
no progress credit. The projection body is exact but its eight-byte conversion
constant still has other original consumers; the transpose loader remains near.
