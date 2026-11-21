# Menu2D lifecycle and render-slot membership

Four ordinary C++ functions in `src/Game/menu2d_lifecycle.cpp` reproduce
**732 code bytes with 35 actual retained relocations and zero differences**.
The full byte-identical DOL and native objdiff now verify this source unit.
The original virtual table and shared float constants remain external.

| Original function | Range | Bytes | Behavior |
| --- | --- | ---: | --- |
| `fn_80215870` | `0x80215870..0x802159A0` | 304 | Native deleting destructor |
| `fn_802159A0` | `0x802159A0..0x80215A44` | 164 | Deactivate, then remove identity from the selected render slot |
| `fn_80215A44` | `0x80215A44..0x80215AF8` | 180 | Store selector, activate and initialize, then insert identity |
| `fn_80215AF8` | `0x80215AF8..0x80215B4C` | 84 | Compute an accumulated-time sine pulse into `+0x78` |

## Identity and observed layout

The accepted factory `fn_80209764` in `factories_80209554.cpp` allocates
`0xCC` bytes and references `Menu2D_Z.h:84`, then calls `fn_80216C9C`.
That constructor installs the same table at `0x802EB240` used by this
destructor. The accepted `type_registry.cpp` registers this factory with
`Menu2D` at `0x8037AA30`, derived from `Menu` at `0x8037AA20`.
This establishes the runtime class identity, while the address-qualified
working class `Menu2D_80216C9C` avoids asserting an exact original C++ spelling.

The shared `menu_base_internal.h` models an observed `0x4C` base prefix for both Menu2D and Menu3D, including the native handle at offset four. Its destructor at
`0x8021D7E4` is referenced by native working identity
`__dt__17MenuBase_8021D7E4Fv`. This spelling is shared with the independent
Menu3D recovery, and the manifest records its original `dtor_8021D7E4` alias.
The recovered derived destructor is `__dt__15Menu2D_80216C9CFv`.
Complete original class declarations and translation-unit boundaries remain
unestablished.

Relevant offsets are the borrowed identity at `+4`, virtual pointer at `+8`,
accumulated float at `+0x1C`, unsigned selector byte at `+0x34`, two-layer
handles at `+0x4C` and `+0x74`, and the output float at `+0x78`. The member
at `+0x68` has signed count, capacity and data pointer at `+0x68/+0x6C/+0x70`;
its elements have stride `0xBC`. Unobserved instance bytes remain opaque and
are not emitted ELF data. Compile-time size checks preserve the `0x4C` base,
`0xCC` derived object and `0xBC` element extents.

## Original behavior and lifetime boundaries

The native destructor installs the original external Menu2D table, destroys
the handle at `+0x74`, destroys the element array, destroys the handle at
`+0x4C`, then invokes the external base destructor with a zero deletion flag.
A positive signed native deletion flag releases the whole object through
`fn_801EF610`. The returned `this` pointer and every native null check match.

The element destructor is empty in this recovery. Its ordinary per-element
C++ destructor loop reproduces the original unrolled counter-only loop,
including its remaining branch instructions. The array's outer pointer check,
inner storage-release check, capacity multiplied by `0xBC`, allocator call and
two null stores arise from the nested destructor/release helper. No dummy
stores, scheduling barriers or handwritten loop instructions are introduced.

The two membership methods use records of stride `0x4C` reached through the
global pointer at `+0x114`, indexed by the object's unsigned byte at `+0x34`.
These are modeled as opaque `RenderSlot` views, not input-controller devices.
Callee `fn_801E1F3C` searches eight handle slots at offsets `0x28..0x44` and
clears the first resolved-identity match; `fn_801E2074` with zero flag inserts
into the first slot whose handle resolves null. The related routine at
`0x801E2E70` copies four words from record offsets `0..0xC`. Accepted LoadingScreen binding/release uses the same
membership calls at global `+0x114` plus `0x1C8`, which is slot index six.
The callee's flag is signed-byte shaped; this source always supplies zero.

Removal first calls the accepted deactivation helper `fn_802139D8`, then
constructs an owned temporary from the object's borrowed identity and calls
`fn_801E1F3C`. Insertion stores the selector, calls activation helper
`fn_80213A18`, calls the still-external initialization routine `fn_80216228`,
then constructs the same temporary and calls `fn_801E2074` with zero flag.
The selector is loaded again after those calls. No bounds check or cached
replacement index is added.

The temporary has a native handle base, two zero-initializing wrapper layers,
and a copy/retain constructor. Its const identity-reference getter preserves
the original saved identity address across native construction. Both zero
stores, the identity copy, retain call, consumer call and final base destruction
are included in the proof. The borrowed identity itself is not destroyed.
The observed calling convention is represented with a const reference to the
temporary; this does not establish the original parameter's by-value/reference
source spelling.

The pulse method occupies virtual slot `0x38`, reached by the accepted upper
`slot2C(float)` callback. It keeps an unused incoming float parameter and reads
the object's accumulated float instead. It computes `0.7f * (1.0f + sin(2.0f *
accumulated))`, then multiplies that named intermediate by `0.5f` and stores
at `+0x78`. The named intermediate preserves the original final multiply
operand order. A fully nested expression changes those register operands.
The purpose of the output beyond this pulse behavior is not established.

## Strict verification and ownership

Run:

```sh
python3 scratch/game_class_80215870/verify.py
```

The compiler is `GC/1.3.2` with the established game settings, including
`-O4,p -inline auto -Cpp_exceptions off -use_lmw_stmw on`. All four functions
remain in their original order. The verifier checks source/header/object
hashes, strong and weak bindings, complete allocated-section and function
coverage, natural alignment and all actual relocation operands before comparing
with the protected original DOL. Its SHA-1 remains
`5da8295a79bf297ab62c620e6ac66210be1c6ef5`.

The object contains only `.text`: 732 retained bytes followed by three unused
weak handle destructors of 92, 88 and 84 bytes. Their six actual relocations
call only the existing native handle destructor and ordinary delete. No retained
reference targets these 264 excluded bytes; normal dead stripping removes them.
There is no owned data, BSS, exception metadata, literal pool or padding.

The table at `0x802EB240` remains external. The four external constants at
`0x8037AD68/6C/70/74` are the original `0.7f`, `1.0f`, `2.0f` and `0.5f`.
The constructor and other Menu2D methods also consume this pool, as recorded
in `scratch/game_class_80215870/literal_external_evidence.json`; this fragment
makes no data-ownership claim.

The candidate is `config/GSQE78/candidates/game_menu2d_lifecycle.json`.
The source/native alias mappings are also saved in
`scratch/game_class_80215870/aliases.json`. Full relocation records, comparison
hashes and weak exclusions are in `strict_result.json`; the original function
snapshot and diagnostic probes remain alongside it. The destructor matched on
its first native C++ probe. Independent Menu3D work supplied the shared exact
membership-temporary and named pulse-intermediate shapes, each reverified
against this Menu2D range. Root integrated both menu units after reconciling their base declaration and verifying every instruction again. The current common header declares renderer parameters through the shared native handle base and activation parameters through the accepted Activable prefix; explicit prefix casts preserve the observed zero-offset calls. Original binary and baseline remain unchanged.

Current integration evidence: `scratch/menu_lifecycle_full_build.log`, the candidate integration hashes, and `scratch/menu_checkpoint.json`. The pre-refinement views remain under `scratch/menu_interface_before/` and `scratch/menu_call_declarations_before/`.
