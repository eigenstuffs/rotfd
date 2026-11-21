# Hierarchy constructor

`src/Game/hierarchy_constructor.cpp` recovers the complete 360-byte constructor
at `0x802039A8..0x80203B10`. The source emits the canonical strong C++ symbol
`__ct__18Hierarchy_80200478Fv`; the previous address-based identity was
`fn_802039A8`, used by the already recovered `0xEC`-byte factory. A compile-time
layout check confirms that complete size.

The constructor invokes the native root constructor, installs the existing
hierarchy vtable, initializes the observed owner/related handle layers and six
empty lists, clears the counters and active byte, then looks up `ObjectsGame`
and assigns its retained handle to the related field. The offset becomes `-1`
after both temporary handles are destroyed. The source preserves the distinct
deletion flags for the typed temporary and native returned handle.

The hierarchy vtable at `0x802EAF40` remains owned by the previously recovered
destructor unit; no new vtable, RTTI, or exception records are emitted.
This source now owns the 12-byte `ObjectsGame` literal including its NUL at
`0x802AD948..0x802AD954`. Its explicit `const char[12]` definition precedes first
use, producing exactly 12 allocated `.rodata` bytes with alignment eight. The
following four original bytes at `0x802AD954..0x802AD958` have a separate fallback
padding owner and receive no source credit. Constructor field assignments are written in
the observed order; chained assignments reverse several stores under MW.

`scratch/game_hierarchy_construct/verify.py` uses GC/1.3.2 with `-O4,p`,
`-inline auto`, and `-use_lmw_stmw on`. All 360 retained bytes and all 16 retained
relocations match the protected original DOL. Three unused weak wrapper
destructors total 264 bytes; their extents, bindings, six relocations, and lack
of references from retained output are checked. They are removed by normal
linker dead stripping and receive no source credit.

The literal extension is independently verified in
`scratch/game_literal_ownership/verification.json`: all 12 emitted data bytes
match, and the entire raw text and relocation semantics, including the weak
tail, remain unchanged from the previously accepted constructor.

The candidate is `config/GSQE78/candidates/game_hierarchy_constructor.json`.
Central integration maps the former address-based constructor identity to
the emitted C++ name, including its recovered factory caller. Full-DOL and
native objdiff integration pass for all 360 code bytes, one function, and 12
owned data bytes. The original DOL SHA-1 and direct whole-file comparison pass,
as do the source-section extent guard and generated progress checks. Existing
factory callers use the reconciled native constructor name and remain exact;
the documented baseline accounting corrections remain preserved.
