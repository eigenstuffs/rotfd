# Repeated callback forwarding entries

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Eighty-one ordinary C++ functions match 10,452 original text bytes and 1,620
original exception/index bytes. Each function forwards its two incoming pointer
arguments and a directly loaded external global pointer to `fn_8025ED38`, in the
original sequence. There are two to eight calls per function, yielding original
text extents from 68 to 164 bytes. All existing C entry names are preserved.
Private declarations expose only the three observed pointer arguments; the
external callback routine and global storage keep their existing owners.

The bounded inventory requires every direct call to be `fn_8025ED38`, a matching
load of its global third argument for every call, and no additional conditional
flow, floating-point work, or field updates. Source expresses the observed
sequence as ordinary C++ calls. All 81 initial probes match every instruction
and each compiler-emitted exception pair. GC 1.3.2 with the established
container-base `-O4,s -inline auto -Cpp_exceptions on -use_lmw_stmw on` flags
reproduces the original eight-byte exception record and twelve-byte index for
each body, as well as its original stack/register allocation.

The frozen manifest, source hashes, strict verifier, split/config suggestions,
and ownership audit are under
`scratch/game_engine_callback_forward_continuation/`. Fresh production
compilation verifies every allocated byte, exact function/object extent, and
actual relocation. No unused weak helpers, added allocation, assembly aliases,
or masked acceptance are involved. All dependencies are actually referenced
undefined ELF symbols; compiler-local EH objects stay local.

The complete original extabindex and constructor/destructor tables were audited.
Each function has precisely its expected original exception pair and no ctor/dtor
table reference. Original neighboring code, globals, and other data keep their
original owners. Each address remains a separate bounded partial source fragment.
Root performs central integration and full native executable acceptance.
