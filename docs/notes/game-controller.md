# Controller callbacks

Six functions at `0x801EFD30..0x801F00B0` reproduce 896 bytes from ordinary
C++. They begin a larger game/engine unit whose original class and method
names have not been recovered. The source uses descriptive names only for
layout and behavior; the original function addresses remain its identifiers.

The first function stores a reciprocal rate at object offset `0x18`, then
conditionally dispatches engine operation 6 through a virtual method. The
second function is an empty callback. The third walks the object's action
array, tests an enabled bit and a C++ member-function pointer, and invokes
each enabled callback with the supplied floating-point argument.

The fourth initializes five actions and assigns member pointers for the rate,
message and script callbacks. The latter two have empty bodies in this build.
Their three 12-byte compiler-generated pointer
objects match the original table at `0x802EA8B0`; four following alignment
bytes are preserved. All three callback bodies are in this unit.
Their descriptive method names identify
the observed action strings, not recovered original identifiers.

Each action has a 128-byte name and a 12-byte CodeWarrior member pointer.
The compiler emits the runtime `__ptmf_test` and `__ptmf_scall` operations
directly from C++ syntax. The engine's virtual pointer is at `0x278`, and the
called slot is at `0xAC`. Unknown virtual declarations preserve this layout;
they have no reconstructed bodies and earn no function credit.

GC/1.3.2 with `-O4,p -inline auto` and the normal Gekko game flags reproduces
all 896 text bytes and 37 relocations, plus 36 table bytes and four padding
bytes. No BSS is owned by this partial split. The registry, reciprocal constant and member-pointer
runtime helpers remain external. `scratch/controller/verify_extended.py` checks the
isolated object; the full DOL hash and native objdiff report establish
integration acceptance.

## Source ownership correction (2026-09-08)

The current emitted `.data` extent is `0x802EA8B0..0x802EA8D4`, 36 bytes.
The following four bytes through `0x802EA8D8` now have a separate NonMatching
original padding owner. This supersedes any padding-inclusive extent above;
all six functions and 896 code bytes remain exact in the full matching DOL.
See the [section-extent audit](source-section-padding.md).
