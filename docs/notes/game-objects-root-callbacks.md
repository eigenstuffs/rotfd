# Objects activation and accumulated-float callbacks

Two integrated C++ fragments reproduce six original functions with **296 exact code bytes**, 19 retained ELF relocations, and **68 owned data bytes**. Full-DOL, native objdiff, and source-section extent checks pass.

| Source | Original range | Functions | Code | Relocations |
| --- | --- | ---: | ---: | ---: |
| `objects_owner_activate.cpp` | `0x802139D8..0x80213A58` | 2 | 128 | 0 |
| `objects_root_callbacks.cpp` | `0x80213E58..0x80213F00` | 4 | 168 | 19 |

The upper header `manipulator_callbacks_internal.h` includes the shared native lower interface in `objects_owner_internal.h`, retaining the established Root prefix and compiler-generated virtual pointer at offset eight. The activation source retains its existing `objects_root_callbacks_internal.h` view. The lower class has two four-byte handle fields at `0x0C/0x10`, a word at `0x14`, and a signed state byte at `0x18`, giving size `0x1C`. The upper class adds an accumulated float at `0x1C`, giving size `0x20`. The shared lower interface supplies the typed four-byte handle members; their construction and destruction belong to the separately recovered lower units. The accepted `objects_constructors_internal.h` is unchanged.

The shared Root interface declares `Root_80207414::slot1C()` as returning
`signed char`, matching the already accepted `root_base.cpp`. Recompiling each
of the two callback objects with only this declaration correction produced
identical whole ELF files. The ABI-only comparison is recorded in
`scratch/game_objects_root_constant/ownership_proof.json`; it adds no code credit.

The address-qualified working identities remain `ObjectsOwner_80213D44` and `ObjectsRoot_80213EBC`, consistent with the adjacent constructor/destructor and existing ObjectsMove constructor chain. The accepted type registry supplies stronger runtime identity evidence: `Activable` derives from `BaseObject`, and `Manipulator` derives from `Activable`. CameraUser and ConsoleInterp registrations name Manipulator as their parent, and their factories call the upper constructor before installing their own tables. This identifies the lower/upper runtime classes as Activable/Manipulator; their exact original C++ spellings, including any suffix, remain unproven. This checkpoint preserves the established native symbol names.

## Original behavior

`fn_802139D8` tests the **signed byte at `+0x18`**. When nonzero, it clears the byte before dispatching virtual slot `+0x24`. `fn_80213A18` performs the opposite transition: when the byte is zero, it sets it to one before dispatching slot `+0x20`. Both retain the original 16-byte frame and conditional virtual call. These helpers were still original/unclassified in the 599-source-unit checkpoint; earlier queue prose incorrectly called `fn_80213A18` accepted and described its effect as deactivation. It activates the state byte; neither helper modifies the word at `+0x14`.

The four upper functions retain their original order and strong identities:

| Original | Recovered native identity | Size | Behavior |
| --- | --- | ---: | --- |
| `fn_80213E58` | `slot34__20ObjectsRoot_80213EBCFv` | 4 | Original empty hook |
| `fn_80213E5C` | `slot3C__20ObjectsRoot_80213EBCFv` | 40 | Reset accumulated float, then activate |
| `fn_80213E84` | `slot2C__20ObjectsRoot_80213EBCFf` | 56 | Add incoming float and dispatch slot `+0x38` |
| `__ct__20ObjectsRoot_80213EBCFv` | unchanged | 68 | Native lower-base construction, upper table installation, zero accumulated float |

The empty hook is an original four-byte function referenced by the original table and directly called at `0x8020EE84`; that caller ignores its return value. It is not an added placeholder or alignment padding. The update uses ordinary single-precision addition and passes the unchanged input float to the virtual callback. The native table has a zero entry at slot `+0x38`, emitted by the ordinary pure virtual declaration `slot38(float) = 0`. No implementation is invented for that callback. The constructor calls native `__ct__21ObjectsOwner_80213D44Fv` at `0x80213D44` and preserves the original returned `this` pointer.

## Verification and ownership

Current production verification uses:

```sh
python3 scratch/game_activable_interface/verify.py --production --skip-upper
python3 scratch/game_manipulator_vtable_emission/verify_replacement.py --production
```

The first includes the unchanged activation source with the established
GC/1.3.2 `-O4,p -inline auto -Cpp_exceptions off -use_lmw_stmw on` settings.
The second compiles the upper callback source with `-O4,s -inline auto`,
exceptions enabled and RTTI disabled. Ordinary source exception pragmas leave
the four callbacks without exception records and enable the deferred inline
destructor's original exception specification. Both verify the protected
original DOL SHA-1 `5da8295a79bf297ab62c620e6ac66210be1c6ef5` and every actual
relocation and allocated output byte. The earlier callback-only script and
records remain historical proof inputs.

The upper unit retains **168 code bytes, 64 table bytes and four constant
bytes**. Its 19 retained relocation records comprise six in the unchanged
callback code and 13 native function pointers in the table. The code uses two
SDA2 references to local `@19`, one branch to `fn_80213A18`, one branch to the
native lower constructor and the HA/LO pair for the now-owned upper table.
The activation pair still emits only its 128 retained code bytes and has no
relocations because its calls dispatch through the existing virtual pointer.

The compiler emits `__vt__20ObjectsRoot_80213EBC` as exactly 64 bytes at
`0x802EB200..0x802EB240`, with natural alignment eight and no tail. Declaring
the native upper destructor inline leaves `slot2C(float)` as its first
non-inline virtual, placing the table with these existing later callbacks.
This ordinary source layout resolves the earlier cycle caused by trying to
place the table with the early destructor. The table's pure slot `38` is
supported by the callback dispatch and the concrete InGame table. The
[table note](game-manipulator-table.md) records its complete native interface.

The callback object also emits an exact **124-byte weak destructor and 52
exception/index bytes**, with **nine excluded relocations**. The independent
production proof compares that duplicate code and metadata against their
canonical originals. Ordinary strong/weak resolution retains the existing
strong destructor at `0x8002798C` and its original 40-byte `extab` and 12-byte
index; the duplicate records receive no additional code, function or data
credit. The table's destructor entry resolves to that early strong definition.
No retained reference points into an extra discarded body or its metadata.

The upper table adds exactly 64 source-owned data bytes to the existing unit.
There is no new code, function or build-unit credit. The lower 44-byte table at
`0x802EB1D0..0x802EB1FC` belongs to the separately integrated lower destructor;
its following four bytes remain original fallback. The InGame table remains
external. No table is manually assembled, relocated through an address alias,
or placed with a forced linker-order override.

Both upper zero assignments still use ordinary `0.0f`. CodeWarrior emits one
local four-byte positive-zero object, now `@19`, at
`0x8037AC50..0x8037AC54`, with natural section alignment eight. Its former
spellings `@9` and `@14` record earlier source-interface stages; its bytes and
both consuming instructions remain unchanged. The independent consumer scan
is preserved in `scratch/game_objects_root_constant/ownership_proof.json`.
The four following original zeros at `0x8037AC54..0x8037AC58` retain their
explicit fallback padding owner and receive no source credit.

The canonical integrated manifests are
`config/GSQE78/candidates/game-objects-root-callbacks.json` and
`game-objects-owner-activate.json`. The callback manifest records 19 retained
and nine excluded relocations, the current source/header/object hashes,
68 owned data bytes and zero owned padding. The current complete upper proof
is `scratch/game_manipulator_vtable_emission/replacement_proof.json`.
Current target assembly is
`build/GSQE78/asm/Game/objects_root_callbacks.s` and
`build/GSQE78/asm/Game/objects_owner_activate.s`.

Full-DOL SHA-1 and direct byte comparison pass. Native objdiff records all
296 retained code bytes, six functions and 68 data bytes as exact across the
two units. The section-extent guard and generated progress checks pass; no
check was relaxed to permit duplicate metadata or alignment tails. No
assembly body, register constraint, binary patch or relocation masking is used.
The documented baseline accounting corrections remain preserved.

The separate [record constructor](game-record-constructor.md) still differs in
four instruction bytes and remains unregistered with zero source credit.
