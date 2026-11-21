# One-table native destruction with existing external names

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Sixty-eight ordinary C++ implementations preserve existing C entry names while
matching each 124-byte destruction body and its original 40-byte EH record plus
12-byte index. Total isolated production coverage is 8,432 text bytes, 3,536
exception/index bytes, and 612 actual relocations. The frozen handoff is
`scratch/game_engine_fn_forward_eh_continuation/final_integration.json` with
source hashes, ownership audit, exact split/config suggestions, and verifier.
Root performs central acceptance. Protected `fn_80020FE8` is excluded.

Each body accepts the observed object pointer and native deletion flag. A null
object returns unchanged. Otherwise it updates the directly observed table at
offset zero or eight, calls its established base cleanup with deletion flag zero,
and releases the allocation when the signed low 16 bits of its deletion flag
are positive. Ordinary inline `dispose(void*) throw()` produces the exact
existing exception-specification handler. This C-entry shape was first established
for protected `dtor_80024E50`; the first three new representative probes also
matched immediately before applying the bounded family to the other bodies.

Private views expose only the observed table location, with eight opaque prefix
bytes where required. No full class size or additional member semantics is
claimed. The compiler receives ordinary C++ control flow and native external
calls, with no assembly, alias, or instruction encoding. All 68 existing C names
are retained, including names used by pre-existing compiled callers; no caller
source or ABI entry name is changed.

Calls to the queued reset-root `80094A2C` use its genuine native destructor name
`__dt__15Object_80094A2CFv`, with guarded `original_symbol=fn_80094A2C`
dependency mapping. This avoids adding callers of the old name while root
integrates that separately frozen original function. Other native Agent/Object
base names and established C cleanup entries remain intact. `fn_800C5390` and
`fn_8002AE0C` are reconstructed under their existing C names, preserving both
their accepted callers and calls from other fragments in this batch.

GC 1.3.2 with established container-base `-O4,s -inline auto -Cpp_exceptions on
-use_lmw_stmw on` flags emits only the original text/EH/index extents. Every
allocated byte matches after applying the real relocations; each unit has nine
allocated-section relocations. No unused weak helper, extra allocation, or
padding is emitted. Strict production recompilation verifies frozen source
digests and exact emitted symbol extents, metadata, and relocation records.

The complete original extabindex, constructors, and destructors tables were
audited. Every body owns exactly its expected exception pair, has no ctor/dtor
table reference, and has its complete original instruction extent. External
dependencies contain only actually referenced undefined ELF symbols; local
compiler EH literals remain local. Every address is a separate bounded partial
source fragment; neighboring original data and functions retain their owners.
