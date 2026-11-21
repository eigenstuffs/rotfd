# Native Manipulator destructor and virtual interface

Current InGame interface verification is recorded in [the native interface note](game-ingame-manipulator-interface.md); its five production objects and newly owned 76-byte table pass the full DOL and native objdiff checks. Earlier isolated proofs below preserve their original source views.


Three ordinary C++ fragments reproduce **136 code bytes in three functions**,
with **52 exception-metadata bytes** and **nine actual relocations**. Strict
verification, the complete original DOL check and native objdiff all pass.
The existing later callback unit now owns the **64-byte upper virtual table**.
The early destructor remains the same strong definition and owns its original
52 metadata bytes; the callback unit's exact weak destructor and metadata
duplicates are discarded without duplicate credit.

| Source | Original range | Code | Owned data | Relocations |
| --- | --- | ---: | ---: | ---: |
| `manipulator_destructor.cpp` | `8002798C..80027A08` | 124 | 52 | 9 |
| `manipulator_empty_hook.cpp` | `80028108..8002810C` | 4 | 0 | 0 |
| `ingame_manipulator_query.cpp` | `8021266C..80212674` | 8 | 0 | 0 |

The native working class `ObjectsRoot_80213EBC` corresponds to runtime
Manipulator. Its lower base is the recovered Activable class,
`ObjectsOwner_80213D44`. The upper class adds a float at `+0x1C` and has size
`0x20`; the runtime registry and accepted constructor chain establish this
inheritance independently of the lifetime probe. Exact original C++ spellings
and translation-unit boundaries remain unproven.

## Native lifetime and exception metadata

The recovered destructor is
`__dt__20ObjectsRoot_80213EBCFv`, replacing original `dtor_8002798C`. Its source
uses an explicit virtual-pointer ABI view in the integrated source. Its body
assigns the upper table, defined in the callback unit, to the observed pointer field at
`+8`; ordinary native C++ destruction then destroys the Activable base and
invokes the class-specific delete operation when the signed native deletion
flag is positive. The compiler preserves the returned `this` pointer and the
base-destructor flag-zero call. This is ordinary C++ with the original native
symbol and destructor ABI, not extracted assembly.

An earlier complete polymorphic-class probe used an empty destructor body:
the compiler installed and emitted the upper table automatically. All of that
probe's code, table and metadata matched in isolation, but its combined
ownership could not be integrated in the original section order. The production
view retains the exact destructor and metadata; ordinary native table emission
in the later callback unit now resolves ownership, as detailed below.

The upper class declares its static `operator delete(void*)` with the ordinary
C++98 `throw()` specification and calls the existing allocator
`fn_801EF610(lbl_801EF5C8, p)`. With C++ exceptions enabled, the compiler emits
the original exception-specification path to `__unexpected` and the original
metadata. Those bytes are part of the retained proof, including code that is
not reached during successful normal deletion.

The verified compiler settings are GC/1.3.2, `-O4,s -inline auto`,
`-Cpp_exceptions on`, `-RTTI off`, and the established Gekko hardware-float and
`-use_lmw_stmw on` settings. The two leaf hooks use the same settings with C++
exceptions disabled. The source uses no new alignment override or ABI-specific
assembly.

The destructor's 52 metadata bytes are:

- Compiler-local `@16`: 40-byte `extab` at `80006500..80006528`, alignment four.
- Compiler-local `@17`: 12-byte `extabindex` at `80016590..8001659C`, alignment
  four, with the real destructor pointer, 124-byte length and exception-table
  pointer.

Its nine relocations comprise seven in code and two in the exception index.
The table's HA/LO references resolve to the callback unit's table at its original address.
Every relocation is applied to its actual original address before comparison;
none is masked or skipped. The former native-table probe named the identical
metadata bytes `@21`/`@22`; the compiler-local names changed to `@16`/`@17` in
the production ABI view.

## Native table ownership and resolved placement

The later callback unit naturally emits the global
`__vt__20ObjectsRoot_80213EBC` as exactly **64 bytes** in `.data`, aligned to
eight, at `802EB200..802EB240`, with no extra tail or padding. Its 13 actual
function-pointer relocations and every table byte pass strict verification,
full-DOL integration and native objdiff. The table inherits the verified
Root/Activable slots, selects the native upper destructor at slot `08`, and
adds these upper entries:

| Slot | Entry | Original target |
| --- | --- | --- |
| `2C` | Accumulate input float and dispatch callback | `80213E84` |
| `30` | Original empty upper hook | `80028108` |
| `34` | Original empty upper hook | `80213E58` |
| `38` | Genuine pure virtual `slot38(float)` | zero |
| `3C` | Reset accumulated float and activate | `80213E5C` |

The `slot38(float) = 0` declaration produces the observed zero table entry
through the compiler's native virtual interface. This is supported by the
upper callback dispatch at slot `38` and the concrete InGame table, which
places `fn_80212674` at that same offset. It does not justify adding a null
slot to the separate lower Activable table: that table's verified extent
remains 44 bytes, followed by four uncredited original zeros.

The first native probe assigned both early text at `8002798C` and this later
table to one object, creating a cross-section link-order cycle. That historical
probe and its review remain under
`scratch/game_manipulator_destructor/native_table_proof/` and
`scratch/game_manipulator_destructor/independent_review.json`.

The accepted source resolves placement by declaring the upper destructor
inline in `manipulator_callbacks_internal.h`, leaving `slot2C(float)` as the
first non-inline virtual method. CodeWarrior therefore emits the native table
with the existing later callback source. The early strong destructor remains
unchanged. The callback object also emits an exact weak native destructor of
124 bytes and its 40-byte exception table plus 12-byte index. Ordinary
strong/weak resolution retains the early definition and discards these duplicate
records. The table's destructor pointer resolves to `8002798C`; no retained
reference targets an extra weak body or its metadata.

The callback proof covers 168 retained code bytes, 64 table bytes and the
existing four-byte zero constant, now compiler-local `@19`. It applies **19
retained relocations and nine excluded relocations**, verifying the weak code
and metadata against their canonical originals before exclusion. Source-level
exception pragmas preserve callbacks without exception records and the native
destructor's original exception specification. No forced section ordering,
manual replacement table, object patch or extra source unit is needed.

The production early destructor still emits no `.data` table; its reference
now resolves to the separately source-owned table. The InGame lifetime
fragments also reference this table without claiming it. The distinct InGame
table at `802EB180` remains original external storage. The
[table note](game-manipulator-table.md) records the full placement proof.

`slot30__20ObjectsRoot_80213EBCFv` is a distinct, original four-byte empty
method. The InGame function at `8021266C`, observed in its table at slot `48`,
returns a zero word. Its exact source return type is unknown; the fragment
uses an unsigned-long result to represent the observed 32-bit return value
and retains the existing `fn_8021266C` identity. Neither function is a new
placeholder or alignment fragment.

## Strict proof and current status

`python3 scratch/game_manipulator_destructor/verify.py` compiles current source
according to `inventory.json`. It checks strong global function identities,
every allocated section and exact size/alignment, all real relocation targets,
and every retained byte against the protected original DOL with SHA-1
`5da8295a79bf297ab62c620e6ac66210be1c6ef5`.

The three `candidate_*.json` files in that scratch directory record the exact
source/header/object hashes and ownership. The complete relocation evidence
is in the corresponding `*_relocations.json` files. These three source objects
retain all their functions and emit **no weak helper bodies, excluded code,
BSS, extra constants or padding**. Strict production results are 124/4/8 exact code bytes, 52 exact
metadata bytes, nine actual relocations and zero differences.

Full-DOL SHA-1 and direct byte comparison, native objdiff and all-source checks
pass after integration. This batch contributes exactly **136 code bytes,
three functions and 52 metadata bytes**. The later callback unit adds exactly
64 table bytes, with no new code, functions or source units. The resulting
checkpoint is 906,016 code bytes, 2,941 functions, 300,797 data bytes and 616
completed source units. The full checkpoint delta is 1,620 code bytes, 17
functions, 205 data/BSS bytes and eleven source units.

The [Activable interface](game-activable-interface.md) and its pointer-shaped
handle-lookup declaration remain exact. Current production verification uses
`python3 scratch/game_activable_interface/verify.py --production --skip-upper`
for the unchanged lower/activation units and
`python3 scratch/game_manipulator_vtable_emission/verify_replacement.py --production`
for the updated upper unit. The canonical callback candidate is
`config/GSQE78/candidates/game-objects-root-callbacks.json`.
