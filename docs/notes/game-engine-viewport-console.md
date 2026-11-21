# Engine viewport console selection

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Frozen isolated handoff: `src/Game/engine_viewport_console_801E0F48.cpp` recovers
one original function, 240 text bytes, zero data and twelve real relocations.
There are no extra functions, allocated data or padding. Existing names remain
unchanged. Exact integration, production source SHA-256, quoted-header hashes
(none), all emitted allocations and actual relocation list are in
`scratch/game_engine_viewport_console_continuation/final_integration.json`, with
adjacent split/configuration proposals and `ownership_audit.json`.

The routine reads console argument count at +860. Fewer than two arguments logs
usage and returns zero. With exactly three arguments and the signed-byte flag
at +8A6 set, it converts the float at +8BC to a signed viewport index; otherwise
index zero is selected. It rejects negative indices or indices at/above the
signed viewport count at +214. Valid requests build a key from the argument
string at console +868 and forward a copy to `fn_801E1AC4`, indexing the original
0x4C-byte viewport records. The global console and viewport pointers remain at
+110/+114. Unknown fields are opaque private storage.

GC/1.3.2 uses ordinary `-O4,p` flags with C++ exceptions off. Strict production
verification applies actual relocations and compares every original byte, exact
function extent and emitted allocated section. The full original exception
index and constructor table contain no record for this function. Original split
ownership is text only, and neighboring functions, referenced tables, strings
and globals remain outside this partial text split. Root must pass full native
hash, regression and extent checks before promotion. No central metadata or
full build was changed by this agent.

## Uncredited adjacent probes

`fn_801E1038` has a semantic reconstruction with only one differing instruction:
its first usage-string argument is originally `addi r4,r31,0`, while the ordinary
external pointer and array/member-address forms emit `mr r4,r31`. All other
instructions and real relocation targets match. The source is preserved only in
scratch; it is excluded from the frozen manifest. A compiler-managed literal
pool may explain the original zero-offset addition, but literal publication
would require resolving shared string-label ownership at `lbl_802ACD70` and
must not duplicate or discard existing original data.

`fn_801E1378` resolves each viewport's handle through the global manager and
forwards valid objects to `fn_801E81AC`. Its bounded loop probes reproduce the
instruction sequence but retain register-allocation differences; these are
uncredited. `fn_801E1108` is preserved as an initial manual lifetime probe and
is also uncredited. It needs the observed nontrivial native handle return/copy
lifetime and a two-word initialized lookup context. No source or progress credit
is claimed for these research probes.
