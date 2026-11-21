# Small callback controls

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Five ordinary C++ functions are exact in isolated production-object checks:
`8004D974` and `8004E5A4` (96 bytes each), and `80040B90`, `8004EB04`,
`8005123C` (108 bytes each). Their complete 516 code bytes, five original
eight-byte exception headers, five twelve-byte exception indices, and all
27 actual relocations match. Every emitted allocation is retained; there are
no switch tables, weak functions, discarded metadata, or new data globals.
The integrator must still verify the full native executable hash.

The two 96-byte functions query the optional observer at `lbl_803776B8`
through virtual slot `14` of its table at offset four, then forward the
caller's object and event plus that query result and the original float at
`80378560` to `fn_802073E8`. They retain their original C entry names.
`8004D974` is called by the accepted resolved-chain dispatcher `8004D364`;
the caller is unchanged.

`80040B90` calls the object's virtual slots `5C(0)`, `60(0)`, and `68(5)`
through its table at offset eight. Its private prefix establishes only the
two leading words and observed vtable placement. `8004EB04` releases the
Handle word at `60`, copies the word at `58`, retains the source, and stores
the scalar result of `fn_8025E268(self,0)` at `64`. Its named source reference
expresses the original member-pointer lifetime across the release call.

`8005123C` compares floats `74` and `78` with the original zero/reference
constant at `80378570`. Each nonmatching value generates event `8E` for self
through `fn_802073BC`, using respectively the original second float argument
at `80378578` or `8037857C`. Declaring these existing `.sdata2` objects
`extern const float` reproduces the original early constant load in the
prologue. The non-const probe had four scheduling differences and remains
preserved as uncredited history.

The original exception-index scan covers `80015F60..8001F2C0`, and the
startup/shutdown scans cover `80299920..80299980` and
`80299980..802999A0`. Each function has exactly one corresponding exception
record and no startup/shutdown table pointer. The audit records all original
initialized-data code references and compiled consumers; all C identifiers
and external table ownership are preserved. No symbol renames, consumer
migrations, pool partitions, aliases, retention rules, or shared declarations
are requested.

`scratch/game_engine_callback_small_controls_continuation/handoff.json`
freezes the production sources, probes, raw objects and section/symbol
inventories, source-consumer ownership audit, strict actual-relocation
results, and exact split/config proposals. `verify.py` independently
recompiles all five production files and checks complete emitted allocations.
Central metadata and previous frozen work are unchanged.
