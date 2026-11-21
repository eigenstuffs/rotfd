# Handle and container cleanup entries

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Ten ordinary C++ fragments match 2,184 original text bytes and 520 original
exception/index bytes. Eight retain their original C entries, including
`fn_80036D98`, whose established compiled callers remain unchanged. The array
owner at `800C421C` and loading-screen layer at `800C0600` have no compiled
callers of their former `fn_*` names; their genuine native destructors use
`Object_800C421C` and `Object_800C0600`, with guarded original-symbol mappings.
Root validates those mappings before central integration.

The two array cleanups at `8008A830` and `80036D98` own observed three-word
count/capacity/pointer records at offsets `0x40` and `0x88`. They destroy each
four-byte native Handle through three inline layers, release capacity times
four bytes through the established sized allocator, and clear the pointer.
The `80020D0C` count/capacity/pointer cleanup has the original empty per-element
loop and releases capacity times the observed `0x48` stride. The empty loop
remains in generated code exactly; no element semantics beyond that observed
operation are invented.

`800CB000` clears bit one of the optional global context target's word at
`0x234`, then destroys Handle members at `0x24` and `0x20` through two and three
inline layers. `800E745C` has a two-layer Handle at `0x24`; `8008F4B0` has a
four-layer Handle at `0x40`; `800C4334` has a two-layer Handle at `0x2C`.
`800E1AB4` destroys a nested group at `0x10` whose two three-layer Handles reside
at owner offsets `0x9C` and `0xA0`, then clears its base words at eight and twelve.
Private inline root/draw destruction views update directly observed tables and
invoke the established original base destructors with deletion flag zero.

The native `800C421C` destructor contains three genuine four-byte
`Handle_800723F4` array members starting at `0x40`; automatic array destruction
emits the original `__destroy_arr` call without an added null test. The native
`800C0600` destructor uses two ordinary inline screen base classes. Their
three-layer Handles are at `0x50` and `0x48`, followed by the established native
`Object_8025F0D8` base destructor. Native outer destructor definitions reproduce
the original register allocation and repeated member null tests exactly; the
initial preserved-C probes for these two remain in `initial_probes` as
uncredited evidence. All other C entries match without renaming.

GC 1.3.2 with established container-base `-O4,s -inline auto
-Cpp_exceptions on -use_lmw_stmw on` flags emits exactly each original text
extent, its 40-byte exception record, and 12-byte index. Fresh production
compilation verifies every allocated byte, symbol extent, and actual relocation.
There are no weak backup functions, unaccounted allocations, assembly aliases,
or relocation-masked acceptance scores. The Handle/root/draw declarations are
private minimum destruction views, not claims of full original class layouts.

The frozen manifest, hashes, strict verifier, split/config suggestions, and
ownership audit are in
`scratch/game_engine_fn_handle_cleanup_eh_continuation/`. Complete original
extabindex and constructor/destructor table scans confirm one expected EH pair
and no ctor/dtor references for every body. Dependencies contain only referenced
undefined ELF symbols. Original globals, tables, other data, and neighboring
functions remain outside these bounded partial fragments. Protected
`fn_80020FE8` and the associated `80020F2C` experiment remain excluded.
Root performs full native executable acceptance.
