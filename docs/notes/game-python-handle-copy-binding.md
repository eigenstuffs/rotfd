# Python typed Handle-copy binding

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

The `800D0A08` binding parses two Python objects, converts their native pointers,
constructs a typed Handle copy, applies it to the owner and destroys the copy
before returning Python None. Its genuine inline C++ base/copy constructors
reproduce all 280 code bytes, 44 exception-table bytes and twelve index bytes,
including original base/local destructor actions and all 22 retained relocations.

The compiler also emits two weak typed destructors: 228 code bytes plus 104
backup exception/index bytes, with fourteen backup relocations. These are never
credited. The bounded native override verifier freezes their complete allocation
and exception groups and binds retained actions to the independently verified
original strong destructor owners at `80020478` and `80020834`. Production and
full native-link checks must prove selection of those original owners and
complete discard of the duplicate bodies and backup exception records.

The destructor declarations preserve the original custom delete operation.
Original exception index and startup/shutdown tables retain complete ownership.
Source, actual-relocation, strong-owner and allocation proofs are frozen under
`scratch/game_python_handle_copy/`. No original input or verifier was changed.
