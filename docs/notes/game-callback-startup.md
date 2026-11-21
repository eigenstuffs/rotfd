# Callback startup temporaries

**Accepted matching source.** Production objects pass strict byte and actual
relocation checks; the full DOL retains its original hash with no baseline
regressions. Source extents, progress exports, and all 26 tests pass.

Two complete functions reconstruct 276 text bytes: `802598F4..80259968`
(116) and `8025BCC4..8025BD64` (160). Each clears its original external small
state word, calls the original parent initialization, and initializes a
128-byte stack temporary with the observed table pointer and 64-bit state
field. The prefix names describe observed storage rather than original class
identity or unobserved member behavior.

`802598F4` uses an ordinary inline C++ constructor and destructor. Initialization
calls original `8025BC5C`, installs table `802EC8A8`, clears flag 4 and sets flag
8; destruction invokes original native cleanup with flag minus one.

`8025BCC4` uses an ordinary inline initializer calling original `8025A58C`,
installs table `802ECC00`, clears flag 1 and sets flag 4, copies the original
three-word callback descriptor, registers it through `8025E714`, and invokes
native temporary cleanup with flag minus one. The descriptor, tables and
small state retain their original external data ownership.

Inlining at the recovered initializer boundary resolves the earlier 10- and
five-word register differences in direct field-update probes. Those probes
remain preserved. An automatic-destructor alternative for the second startup
emits an unused weak helper and remains uncredited; final sources emit only
their two complete functions, with no helpers, data, BSS, exception sections
or padding.

`scratch/game_callback_startup/verify.py` recompiles frozen final source and
checks every allocated byte, complete global extents and actual relocations.
Full original exception/constructor/destructor table scans find no ownership
for these runtime-invoked startup functions. Central production verification,
original full-DOL hash and baseline regressions must pass before acceptance.
