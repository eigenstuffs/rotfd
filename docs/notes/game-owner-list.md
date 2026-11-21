# Activable handle-list construction and update

Two source fragments recover **664 text bytes in four functions**. The list
layout follows the accepted Activable append/destructor evidence: head at
`+0`, tail at `+4`, and a signed byte at `+8`. The new update loop establishes
that a nonzero byte restricts updates to active objects whose word at `+0x14`
is 8; zero updates every active object. This is a mode filter, not an overall
list enable/disable flag. The original C++ list name and complete translation-
unit boundary remain unestablished.

| Source | Original function/range | Bytes | Behavior |
| --- | --- | ---: | --- |
| `owner_list_constructor.cpp` | `fn_80213824`, `0x80213824..0x80213920` | 252 | Construct the two one-layer handles, assign empty temporaries, and clear the mode filter. |
| `owner_list_update.cpp` | `fn_80212904`, `0x80212904..0x80212910` | 12 | Set the filter byte to zero. |
| `owner_list_update.cpp` | `fn_80212910`, `0x80212910..0x8021291C` | 12 | Set the filter byte to one. |
| `owner_list_update.cpp` | `fn_8021291C`, `0x8021291C..0x80212AA0` | 388 | Traverse borrowed object pointers from the head and dispatch eligible objects' virtual update slot. |

The constructor's integrated native symbol is
`__ct__18OwnerList_80213824Fv`. Native member construction reproduces the
original extra `this` copies for the first handle at offset zero. Its later
assignments preserve release/copy/retain operations and destroy each empty
temporary before constructing the next. The final signed-byte store is zero.
The private list view is exactly `0xC` bytes, including three untouched bytes
after the flag; these are instance layout bytes, not owned ELF data.

The update function resolves the head before reading the list filter. It
compares signed generation values in the manager's 16-byte entries, with the
established signed 24-bit handle index and signed eight-bit generation.
Generation mismatch returns null and ends traversal. There is no added index
bound check. For each eligible object it calls vtable slot `+0x2C`, passing
the original float argument. Eligibility always requires a nonzero signed
object activation byte at `+0x18`; a nonzero list filter additionally requires
word `+0x14` to equal 8.

The next handle at object `+0x10` is read and resolved **after** the callback.
The source does not cache the next node before dispatch or retain the current
object. It adds no ownership temporary to the traversal. The two branches use
ordinary `while` loops; CodeWarrior naturally emits the same extra unreachable
branch instructions found in the original, and the proof includes those
bytes.

The first getter model used a ternary return and emitted three extra register
copies. Returning the object through an ordinary `if` statement followed by
`return 0` produces direct assignments to the saved cursor register and matches
all 388 bytes. A private `Entry::getGeneration() const` returns a signed byte,
promoted to the local `int` before comparison, preserving the established
lookup evaluation order. No special compiler pragma, assembly, forced
scheduling dependency, volatile access, or address substitution is used.

The private `ListObject` virtual declarations establish only the observed
prefix and the offset of the update slot. No constructor/destructor bodies or
virtual tables for that view are emitted. The lower Activable interface is also reconstructed separately. The list view
retains the known Root slot0C word argument and signed-char slot1C return;
correcting those unused declarations left both entire ELF objects unchanged.
That comparison is retained in `scratch/game_owner_list/known_root_abi`.

## Isolated verification

The manifests are
`config/GSQE78/candidates/game_owner_list_constructor.json` and
`config/GSQE78/candidates/game_owner_list_update.json`. Run:

```sh
python3 scratch/game_owner_list/verify.py owner_list_constructor
python3 scratch/game_owner_list/verify.py owner_list_update
```

Both pass with the standard GC/1.3.2 game settings:
**664 retained text bytes, 14 real ELF relocations, zero byte differences**.
The constructor has 12 retained relocations and emits one unused weak handle
destructor (84 bytes, two relocations), fully enumerated and left to ordinary
dead stripping. The update source has two retained relocations to the existing
globals and no weak bodies. Its virtual dispatches are indirect calls, not
missing ELF relocations.

The verifier checks source/private-header/object hashes, all strong/weak
function bindings, complete function and allocated-section coverage, physical
retained-function order, original section alignment, and every real relocation
operand before comparing the complete retained bytes with the protected DOL.
Its SHA-1 remains `5da8295a79bf297ab62c620e6ac66210be1c6ef5`. No retained
reference targets an excluded weak body. Only `.text` is emitted: there is no
owned data, BSS, exception metadata, literal pool, or padding.

Strict output and initial getter probes are retained in
`scratch/game_owner_list`. Both sources are integrated: full-DOL byte equality,
the protected original SHA-1 and complete native objdiff code matching pass.
See `scratch/manipulator_checkpoint_full_build.log`. No owned data is added.
The adjacent [unlink routine](game-owner-list-unlink.md) remains an uncredited
1,316-byte near-match with ten differing bytes in seven instructions.
