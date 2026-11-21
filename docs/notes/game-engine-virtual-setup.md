# Virtual setup and callback flags

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Seven ordinary C++ functions match 900 original text bytes and 140 original
exception/index bytes. `fn_80021624` invokes the established virtual slot `0x28`
with argument eleven, sets bit 47 of the 64-bit flags at `0x38`, then invokes
slot `0x98` with two zero arguments. Six related bodies first call `fn_80259258`
and clear the word at `0xB8`, perform the same virtual setup, and set that word
to 31. All existing C entry names remain unchanged.

The private C++ declaration derives its polymorphic view from eight observed
opaque prefix bytes. CodeWarrior puts the table at offset eight and the declared
virtual methods at their observed slots. No virtual method is defined and no
view object is instantiated; no new vtable, helper, or class data is emitted.
Only the observed call slots and fields receive behavioral names. This is a
minimum interface view, not a recovered complete class layout.

Using actual virtual calls and the established 64-bit flags type reproduces the
original r12 call sequence and high-word mask exactly. Plain function-pointer
and 32-bit flag probes were uncredited diagnostics. GC 1.3.2 uses the established
container-base `-O4,s -inline auto -Cpp_exceptions on -use_lmw_stmw on` flags,
emitting each original text extent, eight-byte exception record, and twelve-byte
index. All seven final private probes and fresh production builds match every
allocated byte and actual relocation, with exact emitted symbol extents.

The frozen manifest, source hashes, verifier, split/config suggestions, and
ownership audit are in `scratch/game_engine_virtual_setup_continuation/`.
Complete original exception-index and constructor/destructor table scans confirm
the expected EH pair and no ctor/dtor references per body. Only referenced
undefined ELF symbols appear as dependencies. Other original code and data keep
their owners, and root performs full native executable acceptance.
