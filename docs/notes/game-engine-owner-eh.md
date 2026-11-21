# Root-derived typed owner cleanup

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Frozen isolated handoff: two ordinary C++ destructors, 528 retained text bytes plus 104 exact compiler-emitted exception bytes, 29 actual relocations. Original `dtor_80075AF8` (308) and `dtor_80075DE4` (220) map to native Object destructor names through guarded original-symbol entries; accepted source/header/assembly audits find no old-name callers. Parent staging, full DOL hash and regression acceptance remain required.

Both functions use the observed root prefix through offset 0x24, inherited typed handles at 0x24 and 0x28, table updates, and the existing native ObjectsOwner destructor. The 0x80075AF8 subtype adds a handle at 0x7C and invokes the virtual method at table slot 0x4C before member/base destruction. An uninstantiated private polymorphic view with the observed eight-byte prefix expresses this virtual call and produces the original `r12` load sequence; it emits no table or helper. Opaque fields establish only observed offsets. These are private destruction/dispatch views rather than complete original class declarations.

GC/1.3.2 uses the established container-base `-O4,s -inline auto -Cpp_exceptions on -use_lmw_stmw on`, hardware Gekko, with normal operator delete declared `throw()`. Strict production verification checks every allocated byte, exact symbol extents, actual relocations, source SHA256 and empty recursive quoted-header inventories. Dependencies include only referenced undefined ELF symbols. Each function owns exactly 40 extab bytes and one 12-byte extabindex record. Full original-table audits cover extabindex 0x80015F60..0x8001F2C0, ctors 0x80299920..0x80299980 and dtors 0x80299980..0x802999A0; there are no ctor/dtor-table entries, weak/helpers, padding, BSS or other data. Original surrounding data/functions retain their ownership. Frozen manifest, splits/configuration, strict verifier and ownership audit are under `scratch/game_engine_owner_eh_continuation/`.
