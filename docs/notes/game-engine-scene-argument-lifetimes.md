# Scene argument Handle lifetimes

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Two ordinary C++ routines match all original retained code, exception bytes,
and actual relocations in strict isolated production recompiles. Original
full-DOL acceptance remains the parent integrator's check.

| Entry | Text bytes | Original EH + index | Actual retained relocations |
| --- | ---: | ---: | ---: |
| `fn_8003E058` | 200 | 24 + 12 | 11 |
| `fn_8003F1F8` | 140 | 24 + 12 | 8 |

Total: 340 text +72 original metadata bytes, 19 retained relocations.
GC 1.3.2 uses the standard -O4,s -inline auto -Cpp_exceptions on
-use_lmw_stmw on profile. No literal/data pools, instruction edits, relocation
masks, entry renames, migrations, or new verifier adapters are proposed.

E058 reads the scene's first target at +15058 and tests signed short +210 for
one. If true, it obtains a nontrivial Handle_8003E120 return through the real
hidden return pointer ABI, resolves it, invokes the original target operation
with zero/four, and destroys the temporary. Otherwise it tests signed service
byte +50 and conditionally invokes the original second-target helper. Both
paths return one. An ordinary Scene::first inline accessor preserves the
original global/target GPR allocation; the initial direct-field source has the
same 200-byte extent but differing operands and remains privately uncredited.
The native returned Handle uses the accepted destructor's two empty inherited
layers above the base Handle; the names of original template arguments remain
unknown. Every local offset, PC action, destructor identity, and action end bit
matches the original retained exception record.

F1F8 captures the first target, checks signed numeric-argument presence +8A5,
and if present default-constructs a Handle_80020834, truncates float +8B8 to
int, passes the target/index/Handle to the original helper, and destroys the
temporary. It returns one. The ordinary private InitWord_F1F8 layer and native
derived constructor represent the two observed zero writes after the base
constructor. The first primary probe was exact, including the temporary's
exception lifetime. The four-byte Handle uses signed 8-bit generation and
signed 24-bit index. Registry entries are 16 bytes with object +0/generation +C,
and manager entries pointer +8. All other private storage stays opaque.

E058 emits one uncredited 120-byte native destructor backup, plus 40 EH and
12 index bytes. F1F8 emits the 116-byte native backup and a private 76-byte
InitWord_F1F8 backup, plus 72 metadata bytes. Together the three backups are
312 text +124 metadata bytes and 18 backup relocations; none earns source
credit. Each retained EH pointer resolves to its accepted original global
strong Handle destructor (8003E120 or 80020834). Exact accepted canonical,
source, recursive header, production object, and fresh recompile hashes and
all original sections/actual relocation proofs are frozen. The unique private
helper has no retained references. Every emitted allocation, symbol binding,
raw hash, and real relocation is inventoried.

The unchanged strict weak/EH core accepts both complete production objects.
Isolated actual MWLD links with genuine runtime/SDA objects discard all nine
backup text/EH/index allocations, select the exact original strong owners,
and reject wrong fixture basenames. The parent must repeat complete actual-game
map/ELF backup-discard and original full-DOL hash acceptance.

Complete original exception-index 80015F60..8001F2C0, ctor 80299920..80299980,
and dtor 80299980..802999A0 scans show one owned exception record per primary
and no startup or termination reference. Original assembly extents, all
initialized-data references and their enclosing original objects, and compiled
source/header consumer hashes are frozen in ownership_audit.json. This is
partial original translation-unit recovery; all other code/data keep their
existing owners and all C entry identities remain intact.

The isolated namespace is scratch/game_engine_scene_argument_lifetimes_continuation.
final_integration.json inventories retained ranges/symbols, every real relocation,
all backup raw hashes and strong owner proofs. Split/config files are proposals
only. verify.py recompiles both production sources and accepted strong owners;
native.py records actual native links. complete_allocated_inventory.json records
all raw sections and ELF symbols. handoff.json pins source, note, and evidence.
All shared metadata, old source/header files, and verifier cores remain unchanged.
