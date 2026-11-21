# Final small cleanup entries and protected base lifetimes

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Six ordinary C++ fragments match 1,044 original text bytes plus 332 original
exception/index bytes. Five keep existing C entries, and the `80020F2C`
destructor keeps its already established native `Object_80020F2C` identity.
No function, dependency, alias, or caller name changes are proposed.

`fn_800C14A8` updates tables at eight and `0x318`, with the second pointer equal
to the first plus `0x170`, then calls current native `Object_8007F578` with
flag zero. `fn_800C18EC` adds one inline base destruction layer with the same
observed secondary-table arrangement. `fn_80061D18` traverses the observed
pointer array at `0x10` with an unsigned-byte index bounded by the count byte
at `0x0D`, releases each pointer and clears its slot. Its separate inner and
outer ordinary `throw()` release sites emit the original 60-byte exception
record, including both active-catch slots, plus its 12-byte index.

`fn_8001F518` performs the observed Python decref sequence on globals
`lbl_8037754C`, `lbl_80377550`, and `lbl_80377540`, invoking the type deallocator
at offset `0x18` when a count reaches zero, then calls `Py_Finalize`. The private
Python view exposes only the established reference count and type pointer.
Those external globals and their storage retain their original owners.

Root explicitly authorized new source for the previously protected unowned
`fn_80020FE8` and native destructor at `80020F2C` after the preserved-C-entry
method proved exact. `fn_80020FE8` updates the directly observed table at eight
and invokes native `Object_80021064(this, 0)`. The `Object_80020F2C` native
destructor updates its table at eight, destroys the observed Handle storage at
`0x80` through six ordinary inline lifetime layers, then calls the unchanged
C entry `fn_80020FE8(this, 0)`. These new separate files own only the previously
unowned original extents. Their private views do not replace any accepted
function or shared class declaration.

The initial callback startup source and its header remain byte-identical.
`CallbackStartupPrefix` still has the table at eight and flags at `0x38`; its
startup call remains `fn_80020FE8(&object, -1)` and its C declaration remains
`void fn_80020FE8(void*, int)`. The reconstructed native entry returns the
original object in r3, as the original instructions do; existing callers ignore
that returned register. `protected_provenance.json` records SHA256 and exact
references for all eleven pre-existing protected caller/header files, verified
unchanged after preparation. It also inventories all eleven aligned original
data-pointer references to these two addresses, including existing EH references,
their own exception indices, and destructor slots `802EC818` and `802ECC08` in
external tables `lbl_802EC810` and `lbl_802ECC00`. None of that pointer/table
storage transfers ownership or changes contents.

GC 1.3.2 uses established container-base `-O4,s -inline auto
-Cpp_exceptions on -use_lmw_stmw on` flags. All six first probes match exact
instructions and compiler-emitted metadata. Fresh production compilation
verifies every allocated byte, symbol extent, and actual relocation. There are
no extra weak functions, unaccounted allocations, assembly aliases, or masked
acceptance scores. Each entry returns its original pointer and uses the observed
signed-low-16-bit positive deletion flag for outer allocation release.

Frozen sources, hashes, strict verifier, exact split/config suggestions,
protected provenance and ownership audit are in
`scratch/game_engine_fn_final_cleanup_eh_continuation/`. Full original
extabindex and constructor/destructor tables confirm the expected original
exception pair for each body and no ctor/dtor table ownership. Only actually
referenced undefined ELF symbols appear as dependencies. These are bounded
partial source fragments; other original code and data keep their owners.
Root performs complete native executable acceptance.
