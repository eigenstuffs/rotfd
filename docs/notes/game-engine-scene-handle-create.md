# Scene Handle lookup, creation and retention

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`fn_8003D5F0` is exact in isolated production recompiles: 852 original code
bytes, 120 original EH bytes and a 12-byte index, with 37 real retained
relocations. Full original-placement DOL acceptance remains the parent
integrator's check. All instructions and actual relocated retained bytes match;
there are no relocation masks or instruction edits.

The owner has count/capacity/Handle-array fields at 170/174/178. The routine
scans valid Handles, compares the target key at 60 and calls the existing target
predicate. It returns the first accepted target. Otherwise it resolves the
service Handle, creates the original hashed Name and asks fn_801FCF20 for a new
Handle. The retained derived Handle is appended if valid, growing the array by
eight through the original allocator entry points. It finally resolves and
returns the retained Handle. Handle stride is four bytes; registry entries
stride 16 with object/generation at 0/C and entries pointer at manager +8.
All unobserved private storage remains opaque.

The native factory returns nontrivial Handle_80020834 through the genuine hidden
return pointer ABI. A default Handle_80020B90 temporary remains alive through
the derived retained Handle construction. An ordinary inline reference-returning
prepareContext helper captures the service root after that temporary initializes
and before the Name constructor. The root variable is initialized to null, and
the function-call sequence points plus this compiler's argument evaluation order
produce the original full-expression sequence without asm, volatile accesses or
instruction-forcing intrinsics. The initial direct expression instead constructed
the Name before root resolution and emitted 856 primary bytes; it is preserved
privately and receives no credit. The helper returning a nontrivial Handle was
not inlined by the original compiler and is also preserved uncredited.

The array element is Handle_80024844 derived from Handle_80020834. That ordinary
view preserves the original BASE action for the placement copy, as well as the
BASE action when constructing the retained local. The private InitWord_D5F0
layer represents the observed first zero initialization; the native derived
constructors add the second zero. The seven retained EH destructor relocations
resolve to the accepted strong Handle_80020834/80020B90/80024844 definitions.
Every original PC action, local offset, base register, action order and end bit
matches. The accepted external C entry and all existing callers remain intact.

GC 1.3.2 uses the normal -O4,s -inline auto -Cpp_exceptions on -use_lmw_stmw on
profile. Four genuine weak backups emit 428 code +176 EH/index bytes, with
25 backup relocations. Those 604 bytes receive no matching credit. Three native
backups resolve to exact accepted individual strong owners; the unique private
InitWord_D5F0 helper is unreferenced by retained code or EH. Complete raw
allocation, symbol, binding and relocation inventories are frozen. Fresh accepted
strong recompilations equal actual production object SHA256s and both strictly
match every original owned section and actual relocation.

The unchanged strict weak/EH core verifies the complete object. An isolated
actual MWLD link with genuine runtime/SDA objects discards all 12 backup
allocations, selects the exact three original strong definitions, and rejects a
wrong fixture basename. The parent must repeat complete actual-game map/ELF
backup-discard and original full-DOL hash checks. No new verifier schema, wrapper,
compiled consumer migration, symbol alias or central ownership change is needed
beyond the proposed original split and established flags.

Complete original exception-index 80015F60..8001F2C0, ctor 80299920..80299980
and dtor 80299980..802999A0 scans show only the owned EH record and no startup
or termination reference. The original assembly body extent is
8003D5F0..8003D944. Initialized-data references, original enclosing object ranges
and current source/header consumers are frozen in ownership_audit.json. This is
a partial original translation unit; all other code/data retain existing owners.

The isolated namespace is scratch/game_engine_scene_handle_create_continuation.
final_integration.json records sections, every retained symbol/real relocation,
all backup symbols/raw hashes and strong owner proofs. final_splits.txt and
final_config.txt are proposals only. verify.py recompiles the production source
and three accepted strong owners; native.py records the actual native link proof.
complete_allocated_inventory.json records all raw allocations and ELF symbols.
handoff.json pins source, note and evidence. No central metadata, shared header,
prior accepted source or frozen verifier core was changed.
