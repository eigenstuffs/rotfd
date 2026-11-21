# SuperSpray factory and PlayParticles destruction

The existing type registry identifies `fn_802093D8` as the `SuperSpray`
factory with `PlayParticles` as its registered base. The original allocation
diagnostic also names `SuperSpray_Z.h`, line 28. The reconstructed factory
allocates 0x34 bytes and initializes the observed base prefix, two typed handles,
and two floating-point fields. The adjacent destructor belongs to the
intermediate PlayParticles layout.

`src/Game/superspray_factory.cpp` produces 380 retained code bytes at
`0x802093D8..0x80209554`, the 15-byte header string at
`0x802AE078..0x802AE087`, and 25 retained relocations exactly. Run
`python3 scratch/game_superspray/verify.py`. It checks exact function sizes,
every allocated byte, original address alignment, all retained relocations,
and the protected DOL SHA-1. Full-DOL and native objdiff acceptance remain
verified by the complete original DOL SHA-1 and native objdiff after central integration. The single alignment byte at `0x802AE087` is
outside the candidate.

The destructor's native C++ symbol is
`__dt__22PlayParticles_8020949CFv`, replacing `fn_8020949C`. Ordinary native
handle construction/destruction and two inline handle layers recover the
repeated zero stores and null checks. A recovered prefix record retains the
observed virtual-table pointer at offset 8 and invokes the original base
initialization/cleanup routines. The three virtual tables stay external; the
source does not claim their contents or a complete virtual class declaration.
The factory uses ordinary class operator new, constructors, and the compiler's
null-allocation check. The destructor's positive native flag selects the class
operator delete. No assembly or instruction patches are used.

Three unused weak destructor bodies are emitted: ParticleHandle (88 bytes),
HandleLayer (84), and ParticlePrefix (96). The manifest records every extent
and the verifier proves no retained relocation targets them. Their 268 bytes
and eight relocations are excluded through normal linker dead stripping and
receive no matching credit.

The shared zero float at `0x8037AA40` remains external original data. Defining
that named const float in this TU additionally emits a compiler-folded duplicate
constant; the original has only the referenced shared float at this address.
The verifier distinguishes external SDA2 symbols explicitly when applying
relocations. The allocation label and allocator storage likewise remain
external. Earlier prefix-layer evidence is preserved in the scratch directory.
