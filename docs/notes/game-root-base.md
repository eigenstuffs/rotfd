# Base-object methods and virtual table

`src/Game/root_base.cpp` recovers seven consecutive methods at
`0x802072A0..0x802074F4` (596 retained code bytes), including the native
constructor/destructor and the compiler-generated 32-byte base virtual table at
`0x802EAF60..0x802EAF80`. The wider original translation-unit extent and original
class names remain unknown.

The recovered prefix matches the existing hierarchy destructor's model: a name
word at offset zero, raw four-byte identity storage at offset four, and the
native virtual pointer at offset eight. The constructor sets the virtual table,
clears the name, and initializes identity through the already verified native
handle initializer. The destructor creates a scoped empty identity, assigns it
through `fn_801F7914`, destroys that temporary, then cleans up its own identity.
The compiler generates the outer deleting-destructor test and custom heap free.

Identity remains explicit raw storage as in the accepted enclosing layout.
Its initialization and cleanup calls use the recovered native ABI directly;
these are ordinary C++ calls with typed declarations, not assembly or object
patches. Modeling identity as an automatically constructed nontrivial member of
a separate base introduced a pre-vtable constructor call and an extra base
null check, which do not occur in the original. That alternative remains in
`scratch/game_root_base/automatic_storage.cpp`, uncredited.

The temporary's ordinary bitfield constructor clears the 24-bit index and then
the signed generation byte. Its containing object's destruction naturally
passes the member flag `-1` to the native handle destructor. This reproduces the
original bitfield read/modify/write and byte store without a machine-code array
or forced stack/register placement.

The name-update helper copies the caller's name and conditionally writes it to
the generation-checked registry entry. It retains the original upper-bound-only
index check. A signed-byte local for generation is required for the original
load/sign-extension register allocation. Record-field accessors express the
observed 16-byte stride and offsets 12 (generation) and 4 (name).
The remaining routines forward registration, world update and identity calls,
and implement the virtual mark-once method, returning false when already marked.

The compiler emits one unused weak `EmptyIdentity` destructor (84 bytes,
two relocations), located between retained destructor and constructor in the
object. The manifest records its complete extent. Ordinary linker dead stripping
removes it, and those bytes receive no source-match credit. Every retained
function, both allocated sections, all emitted function extents and all 30
retained relocations pass the strict isolated verifier:

```
python3 scratch/game_root_base/verify.py
```

GC/1.3.2 with `-O4,p -inline deferred`, exceptions/RTTI off and
`-use_lmw_stmw on` yields **596 code bytes and 32 data bytes exact**. The verifier
also checks ELF alignment and protected original DOL SHA-1
`5da8295a79bf297ab62c620e6ac66210be1c6ef5`. Full-DOL byte equality, native objdiff code/data checks and the preserved
original-source regression audit pass. Native constructor and virtual mark-once names are
listed alongside prior names in the manifest for central canonicalization.

## Signed-byte lifecycle result

The recovered hierarchy lifecycle caller establishes a signed-byte result for
`slot1C`, refining the earlier `bool` declaration. The source now uses
`signed char` consistently. Fresh isolated compiles before and after this
refinement produce identical complete object hashes; all instructions, owned
data, relocations and vtable entries remain exact. See the
[lifecycle evidence](game-hierarchy-lifecycle.md).
