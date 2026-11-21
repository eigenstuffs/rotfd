# Native Python factory bindings expanded

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Five creation wrappers reconstruct the original native placement construction and pointer encoding:
`800D97A0`, `800DB4B0`, `800DD88C`, `800DE53C` and `800DEF34`.
Each has 296 original text bytes, eight exception-table bytes and a twelve-byte
exception index record. All allocated extents and twenty actual relocations per
wrapper match in isolated production-form objects.

The constructors are the recovered CallbackPair, CallbackSingle, CallbackClock,
CallbackFlag and ContainerLayer entries. Each source includes the frozen native
class header and allocates `sizeof` that class before placement construction.
The ordinary new-expression includes the original allocation-failure branch.
A separate explicit conditional assignment changes register allocation and is
preserved only as an uncredited probe.

The complete original exception index, startup and shutdown tables are scanned;
all original ownership remains in the source. No additional helpers, data, BSS
or alignment bytes are emitted by these wrappers. Isolated source/header hashes,
actual relocations and original table findings are frozen in
`scratch/game_python_native_factory_expanded/final_integration.json`.
Central production compilation and full-DOL acceptance are required before credit.
