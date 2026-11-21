# Ordered callback lookup entries

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Eighty-one ordinary C++ functions match 16,752 original text bytes and 1,620
original exception/index bytes. Each forwards its two incoming pointer arguments
and an external global pointer to `fn_8025E70C`, in its observed sequence, and
returns the first result other than minus one. If every lookup returns minus
one, the wrapper returns minus one. Each original function performs two to
eight lookups; original text extents range from 100 to 268 bytes. Existing C
entry names, backing callback routine identity, and external global owners all
remain unchanged. Private declarations expose only observed ABI arguments and
the signed integer result.

The bounded inventory requires every direct call to be the established lookup
routine, with a corresponding loaded global third argument, and no additional
field updates or floating-point operations. Source uses ordinary explicit calls
and early integer returns. All 81 first probes reproduce every instruction and
the eight-byte exception record plus twelve-byte index for each body. The
established GC 1.3.2 container-base `-O4,s -inline auto -Cpp_exceptions on
-use_lmw_stmw on` flags reproduce stack, register, and branch behavior exactly.

The frozen manifest, source hashes, strict verifier, split/config suggestions,
and ownership audit are in
`scratch/game_engine_callback_lookup_continuation/`. Fresh production builds
verify every allocated byte, symbol extent, and actual relocation. No weak
helper, extra allocation, assembly alias, or masked scoring is involved.
Dependencies contain only actually referenced undefined ELF symbols, while local
compiler EH records remain local.

The complete original extabindex and constructor/destructor tables were audited;
each wrapper owns its expected exception pair and has no ctor/dtor reference.
Other original functions and all external global storage remain outside these
bounded partial source fragments. Root performs central integration and full
native executable acceptance.
