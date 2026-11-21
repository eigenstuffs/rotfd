# Native source continuation checkpoint

Verified on 2026-10-12 after the [storage and virtual-method checkpoint](continuation-2026-10-12-storage-mi-checkpoint.md).
This remains an active, incomplete decompilation.

The standard build links 1,919,576 of 2,607,776 code bytes (73.6097%) and
7,965 of 8,803 functions from source. Matched data is 911,815 of 1,030,936
bytes. Compared with the saved start report, this is 62,404 additional code
bytes, 214 functions and 369,073 additional matched data bytes. Unit counts
remain provisional; byte and function denominators are unchanged.

The [native virtual-method note](continuation-2026-10-12-native-owner-hook.md)
now records the final cleanup groups, their shared declarations and exact
existing direct callers. In total these recover 384 genuine adjustment-thunk
bytes, with discarded partial tables and weak backups excluded from progress.
The ordinary TRK dispatcher also adds 132 code bytes. New typed game searches
at `800A78E4` and `80262AB4` add 76 and 72 bytes; inline identity comparison
preserves their observed register lifetimes. The 56-byte aligned-size helper
at `802781AC` includes a full alignment step even when already aligned. The
80-byte `80275ED4` query checks sixteen flag slots across 64-byte records.
These functions emit no helpers, data or actual relocations.

The five [typed engine-storage units](game-typed-global-storage.md) add 14,160
BSS bytes. The [SDK and small-state note](sdk-game-typed-storage-2026-10-12.md)
describes float limits, errno, scalar DSP/card globals, the frozen-module
registry, matrix constants, callback/event state and the 56-entry factory
registry. Every accepted symbol retains its native visibility and exact
allocation. Serialized frozen Python code remains original; only typed names,
records and the registry pointer are reconstructed. Factory registry storage
owns 224 bytes; its 24 trailing alignment bytes remain original.

The cache binding interface is now genuinely virtual in the shared header.
The existing 12-byte base binding method emits its complete 12-byte GLOBAL
vtable at `802EA868`. The existing 408-byte concrete binding unit emits both
complete 12-byte tables at `802F1490` and `802F149C`. Reversing the two ordinary
member definitions with `-inline auto,deferred` preserves native text and
data order together. Other shared-header consumers retain their complete
raw allocations, symbols and relocations. A separate typed cleanup ABI record
at `802EA8A0` owns 12 bytes and one real function-pointer relocation; its
four trailing bytes remain original. These four tables add 48 matched data
bytes while preserving all 420 existing code bytes.

Four more typed cleanup tables preserve exact provider signatures and add 48
data bytes. The existing 36-byte Curve50 reset is a genuine virtual member and
now emits its complete 12-byte table. A coherent five-slot Handle assignment
interface preserves 124 existing code bytes and emits its full 28-byte table;
its four-byte prefix places the vptr at the native offset. Typed registry,
array, hash-key and service interfaces add another 304 data bytes. Every
relocation names a real native provider with a compatible signature. The
complete source objects, symbols and actual relocations match; twenty affected
interface consumers retain their expected complete compiler objects.

Later typed storage adds the 512-byte audio lookup, 92 bytes of movie and saved
transform state, 116 bytes of callbacks, service state and collision constants,
and 152 bytes of dictionary pointers, callback groups, vectors and sprite
corners. Their existing initialization code remains outside each storage
fragment. Original tails and the complete neighboring character buffer at
`802F4154..802F4198` remain original. Six independently audited resource
routines add 48 code bytes, retaining all original function identities and
verified direct-call or virtual-slot signatures.

The byte reader at `802912D0` adds 100 code bytes; ordinary inline read state
and `-opt nopropagation` reproduce its count lifetime without helper code.
The ready-action dispatcher and key-filter clearing routine add 380 code
bytes; the verified handle generations remain signed bytes. Two existing
engine fragments each gain an eight-byte float getter using their original
external constants. No conversion pool or extra data is claimed by these
code fragments.

The previous- and next-menu-selection routines at `8021CFBC` and `8021D26C`
add 1,376 code bytes. Ordinary value wrappers preserve saved-index, visible
count and selectable-flag lifetimes. Each 688-byte source object emits only
its original GLOBAL function, six actual relocations and one compiler category
record. Complete DOL audits find one direct caller each, no interior targets,
and no initialized-data, exception-table or constructor/destructor references.
Their borrowed logger state and diagnostic string remain original.

Further complete typed interface records add 380 platform data bytes, 84
curve-owner bytes and 288 owner/viewport bytes. The 192-byte viewport identity
contains both its 176-byte primary record and complete embedded 16-byte
record. Original providers whose code is not reconstructed retain zero code
credit; their receiver and return ABI inferences are documented in the frozen
handoffs. The interface handoffs preserve thirty complete consumer objects. Eight
small constant groups add 164 data bytes, with all 38 native GLOBAL objects
preserved. Four internal string-to-float alignment bytes are natural compiler
output; external padding, the viewport prefix and the full neighboring string
at `80378C64..80378C69` stay original.

A further complete path-owner interface adds 44 data bytes. The animation
lookup defines 33 named 36-byte records (1,188 bytes), and the 1,024-byte card
CRC table expands eight reflected polynomial steps for each byte value. The
CRC reader retains its complete compiler object. Platform math and four scalar
pairs add 92 bytes with all 17 native GLOBAL values preserved. Five early
record, constructor and menu-color groups add 140 bytes; the actual separating
float at `80378224` remains original and is not counted as padding.

The complete SWIG module initializer now owns 656 code bytes, 20 bytes of
exception metadata and 25,544 bytes of typed registration data. It supersedes
the earlier registration and type-array fragments. The native hexadecimal
prefix remains GLOBAL; the compiler emits the 6,080-byte method array as LOCAL.
Likewise the GLOBAL agent-type prefix precedes genuine LOCAL initial-type and
constant arrays. A fresh audit of every active input relocation and every
original initialized-data byte position verifies these coarse-label refinements.
All 1,657 actual relocations and native allocations match. The ordinary source
references retain the complete registration closure during linker dead stripping.
All 402 affected complete compiler objects remain identical; with the other
table handoffs, 435 complete consumer objects are verified.

The Node, Node Python factory, HandleDraw constructor and timeline append units
add 2,300 code bytes and 20 exception bytes. Genuine class declarations preserve
native constructor identities and their existing consumers. The timeline retains
the original uninitialized float behavior. The complete callback selector adds
1,248 code bytes and 327 owned data bytes, including compiler-local switch tables
and strings. Its earlier 264-byte data fragment is superseded, with the old source
and proof retained as history. Seventeen later constant owners add 565 data bytes;
ambiguous padded scalar pairs remain original.

Fourteen more scalar owners preserve 100 native GLOBAL float objects and add
400 data bytes. The original 3,616 bytes between and after these fragments
remain explicitly original, including positive neighboring allocations.
Const declaration corrections preserve four complete consumer objects. Twelve
box-edge pairs and six box-face quads add 192 typed data bytes; their geometry
code remains original. A genuine Object constructor adds 156 code bytes and
40 exception bytes, preserving all 50 affected compiler objects apart from
three same-address GLOBAL name refinements. Its two borrowed virtual tables
remain original. The 120-byte child-handle getter preserves the hidden-return
ABI and discards its three unused weak destructors.

Seventeen scalar triples add another 204 bytes with all 51 native GLOBAL
identities retained. Their original 4,172 neighboring bytes remain original;
six existing original fragments are explicitly refined into complete original
subfragments around the new source. The controller mode diagnostic adds
292 code bytes, a 36-byte compiler-local switch table and 20 exception bytes.
Its borrowed format pool remains unchanged, and the complete adjacent switch
table beginning at `802BD8D4` stays original.

The [font pixel unit](game-font-glyph-pixels.md) reconstructs all 14,272 bytes
of `lbl_802EDCD0` as 223 editable 8-by-8 glyphs. Compile-time row-mask expansion
emits exactly one GLOBAL byte-pixel array, with no helper code or relocations.
The original constructor's index offset, loop count and 64-byte stride establish
the layout; its code remains uncredited. These are typed native data records,
not recovered Python scripts or disassembly credited as source.

Acceptance evidence is retained under `scratch/continuation_20261012_b/`.
`build-box-collision-promote.log` passes the unchanged DOL SHA-1;
`changes-box-collision-promote.log` reports no regressions. Native allocation and
complete-table proofs verify all compiler allocations, symbols, relocation
records and final native bytes. `check_complete_coverage.py` checks exact
section-address coverage against the starting report and confirms the saved
objdiff baseline is immutable. Original prefixes, trailing padding and real
neighbor globals remain explicitly original where alignment would otherwise
hide them. Source extents pass 4,997 linked units and 5,979 data/BSS sections;
all 66 unit tests pass. Native reports retain every unknown original unit.

The complete late-screen registration closure now owns 4,572 code bytes and
708 data bytes. It preserves 3,500 previously matching callback bytes and
140 switch-table bytes, adding 1,072 code bytes, two functions and 568 data
bytes. Ordinary C++ member pointers emit 36 genuine LOCAL records; the
complete 108-byte GLOBAL screen table and six compiler LOCAL switches retain
their native identities. Fresh incoming-reference and all-byte pointer audits
justify refining the coarse pool label. All 516 unused weak helper bytes
are discarded normally; the original strong Handle providers are preserved.
Three old source units are explicitly superseded with their historical receipts
retained, and all six affected complete compiler objects remain unchanged.
The four bytes after the data closure remain original with alignment one.

The property dispatch at `80226434` adds 196 bytes, and the sorted-record
link routine at `80271BD8` adds 412 bytes. Their ordinary declarations preserve
the native 64-bit argument alignment and ushort cursor lifetimes respectively.
Both emit only their owned text, with no helpers, data, padding or exception
records. The full DOL, baseline comparison, all native allocation and consumer
proofs, complete section coverage, source extents and all 66 tests pass.

The clock and flag registration closures preserve all their existing callbacks
and tables, adding 992 code bytes, two functions and 288 compiler LOCAL
member-pointer bytes. Complete original pool-reference audits support each
closure; unused weak helpers are discarded normally and ten complete affected
compiler objects remain unchanged. Original boundary words remain explicit.

Two more callback registration closures preserve 2,548 existing code bytes
and 340 data bytes while recovering 144 genuine LOCAL member-pointer bytes.
The skin object contains interleaved unused weak functions, so its proof
checks the full raw object and each native function placement independently.
Eighteen complete affected compiler objects remain unchanged. Twenty-six
GLOBAL scalar pairs add another 208 data bytes. Their 52 native identities
and all surrounding 4,488 original bytes are preserved, with one const
declaration refinement retaining the complete existing consumer object.

The breakable callback startup at `8025959C` adds 144 code bytes. Its ordinary
stack-object construction inlines the accepted breakable constructor; the
complete eight-byte GLOBAL state and original vtable remain borrowed. All
1,096 unused weak helper bytes are absent from the native ELF. Seven helpers
are identical copies of earlier unused weak definitions; the native map
identifies each unused winner, and full raw function and actual-relocation
equality proves the copy relationship. The unique helper is directly unused.

The retained-control selection at `800B4D1C` adds 300 code bytes and 56 owned
exception/index bytes. Its four-byte Name type uses an implicit copy
constructor, which naturally preserves the original by-value argument store.
Both existing complete header consumers remain unchanged. The established
strict weak-EH verifier and full native map prove original strong Handle
resolution and discard all 348 backup code and 156 backup metadata bytes.
The original callable tables and function identity remain unchanged.

Four further functions add 580 code bytes and 56 owned exception/index bytes.
The retained assignment at `80094920` uses the observed non-const Handle
reference; all existing strong destructor providers remain exact, with 472
weak backup code bytes and 208 backup metadata bytes discarded. The sparse
slot-key acquisition at `801ADB28` uses ordinary key accessors and supported
`-opt noloop` to preserve the original loop-address lifetime. The viewport
update at `801E1378` uses a member Handle resolver and seven observed
0x4C-byte records; its existing complete table object remains unchanged.
The 16-byte key packer at `800596E4` takes two signed shorts. Its accepted
caller declaration is refined accordingly, with the full 356-byte compiler
object unchanged. Full native mapped and standard DOL hashes, original
coverage, baseline, all allocation/consumer proofs and 66 tests pass.

The box nearest-hit query at `801DDBFC` adds 1,156 code bytes. A shared
ordinary loop counter across transform, corner, edge and face passes preserves
the native register lifetimes. Declaring the face-array pointer before the
result preserves the final two saved registers. Its sole compiler text
section and all 12 actual relocations match, with no helpers, pools, data,
exception records or padding. All cube points, topology records, constants
and three query callees retain their established original identities.
The two original callers use the observed 64-bit identity argument alignment.
The complete native link, baseline, raw/allocation and consumer proofs, source
extents and 66 tests pass; the standard build reaches 71.7717% code coverage.

The owner detach-and-transfer routine at `8021FD9C` adds 232 code bytes.
Named index, manager and tag accessors preserve its observed handle lookup
lifetimes. The complete compiler object has 172 additional weak destructor
bytes; both unique definitions have native UNUSED map rows and are absent
from the linked ELF. All 12 actual allocated relocations and three compiler
category records are accounted for. Original strong handle providers and
borrowed state remain unchanged. Full native hashes, coverage, baseline,
allocation and consumer proofs, source extents and 66 tests pass.

The viewport handoff's raw-section receipt typo is preserved in the original
frozen handoff. A separate versioned addendum corrects the section SHA to the
fresh strict report; the complete object inventory and accepted source bytes
were already correct. This receipt correction changes no matching credit.

The owner cache conversion at `801D864C` adds 352 code bytes. A named resolved
resource pointer in the outer body preserves the original three saved
registers. All linked-index unlink/prepend operations and the record loop
match, with five actual relocations and no helpers or owned data. Its two
original callable-table pointers and following function remain unchanged.
Thirty-two typed GLOBAL scalar owners add 140 data bytes: 29 floats and three
doubles, with their original identities and natural compiler alignment.
Forty-six explicit original fragments preserve all 1,944 surrounding bytes,
including positive neighboring objects. All 74 source/header receipts and
58 complete existing consumer objects (23,160 allocated bytes) remain exact.
Standard and mapped native hashes, baseline, full coverage, allocation and
consumer proofs, source extents and all 66 tests pass.

The native runtime type record batch adds 33,652 data bytes in 238 units.
Its 1,579 complete GLOBAL objects preserve their canonical sizes, addresses
and bindings. Ordinary typed base lists and type records emit exactly 4,573
ADDR32 relocations. All 254 original neighbor fragments retain 47,668 bytes;
none of their positive objects or alignment bytes earns source credit.
An independent census checks 4,163 original pointer positions, including
unaligned positions, and proves all 1,579 objects reachable from original
outside data. Existing source and header files remain unchanged. Standard
and mapped DOL hashes, baseline, complete coverage, native allocation proofs,
source extents and all 66 tests pass. Matched data reaches 86.5200%.

Fifty-seven additional complete float owners add 228 data bytes. Four menu
literal units add 1,020 bytes; the parser's declaration is qualified const,
with its complete compiler object and strict weak/EH proof unchanged.
Explicit frozen source binding supersession preserves the old receipts.

Seventy-four readable string units add 8,258 data bytes across 122 complete
GLOBAL arrays. Every original positive neighbor retains its native extent
and binding; original zero gaps use explicit align1 and earn no source credit.
All 152 existing source/header receipts and 134 original code consumers remain
verified, with original pointer targets preserved even at unaligned positions.

The nested pair-pool destructor at `801EB89C` adds 468 code bytes through an
ordinary compiler-generated destructor. Its sole 120-byte caller changes
only the canonical destructor spelling; allocated and relocation bytes stay
identical. Two cache destructors add 1,208 code bytes. A const scalar reference
in the index API preserves the native loop register lifetimes. All 46 actual
relocations and three compiler category records are exact; no helper or
storage bytes are emitted. Standard and mapped original DOL hashes, baseline,
complete coverage, all current and prior native allocation/consumer proofs,
source extents (5,406 linked units) and all 66 tests pass. Matched data reaches
87.4421%; 949 functions remain outside linked source.

Seven further readonly string units add 1,475 data bytes: twenty complete
GLOBAL arrays (1,466 bytes) and nine genuine compiler alignment bytes.
Twenty caller declarations are refined to const, with complete compiler
ELFs unchanged. Two strict weak/EH gates pass with explicit source binding
supersession. Four DTK-generated synthetic gap labels are superseded by
anonymous compiler alignment, without aliases or new named data objects.
An exhaustive original-byte, native-materialization and 7,002-input actual
RELA audit proves those nine bytes have no incoming references. Six separate
original gap objects remain explicit GLOBAL align1 and uncredited. All prior
native proofs, standard/mapped hashes, baseline, coverage, source extents
(5,413 units) and 66 tests pass. Matched data is now 902,947 bytes.

The remaining typed-float batch adds 1,192 data bytes through 298 complete
GLOBAL float objects with natural eight-byte section alignment. An independent
original instruction census confirms all 663 direct accesses are LFS reads;
there are no initialized pointers into these objects. Ninety-two complete
partitions preserve 5,368 original neighbor bytes and every positive provider.
Eleven source/header files and both complete linked consumer objects remain
unchanged. Standard/mapped original hashes, baseline, coverage, all native
proofs, source extents (5,711 linked units) and 66 tests pass. Matched data
reaches 87.7008%.

Three genuine dynamic initializer closures now replace the earlier unaccepted
GLOBAL startup probes. Each owns its ordinary compiler LOCAL initializer,
natural constructor record and existing GLOBAL arrays. Complete incoming
closure audits justify refining the inferred startup names to compiler-local
identities. The three units add 376 code bytes and twelve constructor bytes;
the existing 292 BSS bytes retain all GLOBAL names, extents and bindings.
Historical storage-only and text-only owners remain preserved as superseded
research. There are no aliases, detached constructor splits or promotions
of compiler LOCAL symbols.

The actor orientation routine adds 316 code bytes and twenty exception bytes.
TeleportVolume callback registration adds 184 code bytes, 96 explicit typed
virtual-call ABI descriptor bytes and 36 exception bytes. Its shared callback
consumer retains its entire native compiler object after the declaration
correction; preceding original RTTI objects retain all 4,408 bytes and positive
extents. This partial unit does not claim the later original callback pools.
All five full compiler objects, actual symbols and relocations, standard and
mapped original DOL hashes, immutable baseline, coverage and prior native
proofs pass. Source extents cover 5,713 linked units and 6,697 data/BSS sections;
all 66 tests pass. There are 944 functions outside accepted linked source.

Two related handle registry removal routines add 596 exact code bytes. A typed
signed index value and signed eight-bit generation preserve the original
register lifetimes, entry stride and key access. Their four original incoming
function pointers and all nineteen allocated relocations remain exact.

The local-owner callback registration routine adds 292 code bytes and 36
exception metadata bytes. Its genuine external constructor declaration removes
an artificial saved receiver lifetime. The compiler also emits a 276-byte weak
destructor and 52 metadata bytes; native linker duplicate/UNUSED rows prove that
all 328 backup bytes are discarded against the unchanged existing strong owner.
All 656 emitted bytes and forty relocations match before selection. The complete
5,356-byte caller object and eighteen original native providers remain unchanged.
Standard and mapped hashes, coverage, all prior and new native proofs, baseline,
source extents (5,716 units/6,699 data+BSS sections) and all 66 tests pass. There
are 941 functions outside accepted linked source.

The two handle erasure routines at `8022B9F8` and `8022BCFC` add 624 exact
code bytes. Const typed indices and signed generation comparisons preserve
resource resolution, the original destructor calls and array compaction.
Each emits only its 312-byte text section and four allocated relocations;
no helpers, literals or data are emitted. The existing complete 936-byte caller
object and all native providers remain unchanged. Standard and mapped original
DOL hashes, baseline, coverage, all prior native proofs, source extents
(5,718 units/6,699 data+BSS sections) and all 66 tests pass. There are 939
functions outside accepted linked source.

Four related handle routines add another 1,588 exact code bytes: owner erase
308, unique append456, name erase388 and path erase436. Signed typed index and
generation values preserve resolution and key comparison; placement copying,
reference counts, growth and compaction retain native behavior. All 49 allocated
relocations, complete production compiler objects and existing callers match.
One scene caller now declares the name-erasure return type as `int`; its complete
compiler object is byte-identical after this single declaration correction.
Standard and mapped original DOL hashes, baseline, coverage, all native proofs,
source extents (5,722 units/6,699 data+BSS sections) and all 66 tests pass.
There are 935 functions outside accepted linked source.

The separate registration at `800E8130` has an exact private 152-byte text
probe but remains unaccepted. Its native exception action word differs from
supported compiler output, and DTK requires its exception index and function
to share one build unit. The attempted separate original metadata split was
rejected before linking and is preserved in the research logs. Its temporary
build registration was removed, restoring the full original auto unit; no
part of this candidate contributes to source progress.

The render-buffer factory adds 172 code bytes through genuine C++ class
construction and virtual dispatch. Four existing provider bodies (632 bytes)
retain their exact instructions after their declarations are reconciled with
the real class hierarchy; six existing consumers remain exact. Six canonical
GLOBAL identities change spelling at the same positive addresses, extents and
bindings, without aliases. Three complete 88-byte native tables retain original
ownership and receive no source data credit. The factory emits a genuine weak
104-byte Resource destructor and 32-byte table; all 136 backup bytes and actual
relocations match the native providers before normal linker duplicate removal.
The original strong providers remain in place. Historical source and candidate
receipts remain preserved with narrowly pinned migration checks.

The paired handle erasure adds 356 exact code bytes and five allocated
relocations, preserving its complete 936-byte caller. All twelve compiler
objects involved in this checkpoint match their frozen production probes.
Actual standard and mapped link maps prove source ownership; the standard map
relink is complete-ELF identical to the production link. Standard and mapped
DOL hashes, immutable baseline, complete original coverage, all native proofs,
source extents (5,724 linked units/6,699 data+BSS sections) and all 66 tests pass.
Accepted linked code is now 1,878,408 bytes; 933 functions remain outside it.

Three further handle routines add 964 exact code bytes: serialized pointer
readback260, scene disable192 and named sphere record lookup512. Const typed
indices, signed generation comparison and an ordinary four-byte Name class
recover the original saved-register lifetimes. The scene callback also owns
its genuine twenty LOCAL exception metadata bytes, with exact native positive
extents and source map ownership. No caller declaration changes are needed.
Both original readback callback tables, the complete 84-byte scene table
fragment and the accepted complete 964-byte sphere-query caller remain exact.

The readback compiler also emits two ordinary weak destructors totaling
172 bytes and four allocated relocations. Actual native map UNUSED rows prove
that both are discarded from the standard and mapped ELFs; they receive no
source credit. Every source object, raw symbol and actual relocation matches
its frozen production probe. Standard and mapped original DOL hashes, baseline,
coverage, all prior and new native proofs, source extents (5,727 linked units/
6,701 data+BSS sections) and all 66 tests pass. Accepted linked code is now
1,879,372 bytes; 930 functions remain outside it.

The scene callback exception records contribute twenty matched data bytes in
the native report, bringing matched data to 904,359 bytes (87.7221%).

Four further routines add 1,256 exact code bytes: normalized path lookup 412,
actor port-event context 268, scene vector-owner construction 176 and type-registry
record append 400. Const typed handle indices, signed generations, real automatic
member lifetimes and supported optimizer settings reproduce the native register
lifetimes. The registry routine preserves all 249 incoming calls and the complete
six caller objects; its factory argument is an actual function pointer.

The genuine scene constructor shares its complete class declaration with the
existing destructor, whose entire 204-byte compiler object remains byte-identical.
Its GLOBAL constructor identity changes spelling at the same address and extent;
the sole original factory caller retains every byte and relocation except that
explicit symbol-name migration. The constructor owns twenty exact LOCAL exception
bytes. Its unreferenced weak destructor and metadata total 120 bytes; the port-event
context emits a separate 88-byte weak destructor. Actual standard and mapped
link-map UNUSED rows prove all 208 backup bytes are discarded without source credit.
The paired destructor's historical source and candidate receipts remain preserved
through a narrow source/header migration proof.

All complete production objects, raw symbols, actual relocations and borrowed
provider bindings pass. Standard and mapped original DOL hashes, immutable
baseline, original section coverage, all prior and new native proofs, source
extents (5,731 linked units/6,703 data+BSS sections) and all 66 tests pass.
Accepted linked code is now 1,880,628 bytes; 926 functions remain outside it.
Matched data is 904,379 bytes (87.7241%).

The callback factory at `800E3094` adds 300 exact code bytes and twenty LOCAL
exception metadata bytes. Its ordinary constructor and member lifetimes retain
the original argument and callback-entry order. Its complete existing caller
remains byte-identical. The factory shares the existing record-owner declaration
with its original constructor; that constructor's complete 180-byte compiler
object remains unchanged after the declaration moves into the shared header.
All original providers and borrowed data retain their ownership and identities.

The earlier vector-owner constructor's historical sole caller is now this
matching source factory. A frozen successor proof retains all original native
fixtures, constructor checks and discarded weak-helper checks while verifying
the new caller's complete raw compiler output and one explicit constructor
symbol migration. The original historical checks and sources remain preserved.
Standard and mapped original DOL hashes, baseline regression, section coverage,
all native proofs, source extents (5,732 linked units/6,705 data+BSS sections)
and all 66 tests pass. Accepted code is 1,880,928 bytes; 925 functions remain
outside linked source. Matched data is 904,399 bytes (87.7260%).

The bounded StreamFile construction view at `801C9210` adds128 code bytes.
Its real AsyncFile storage layout, original64-byte table and156-byte destructor
remain unchanged. Its sole176-byte factory caller now uses ordinary placement
construction; every allocated raw byte and actual relocation remains identical
except the constructor's explicit GLOBAL spelling refinement at its original
address. Three unreferenced compiler member cleanup functions total232 bytes;
actual standard and mapped native UNUSED rows prove all are discarded.

The full factory source/object/canonical migration and generated native assembly
spelling change have narrow frozen historical proofs. Adding `-mapunused` to
the standard map relink preserves complete ELF identity while providing unused
rows. Standard and mapped original DOL hashes, baseline, complete section
coverage, all native proofs, source extents (5,733 linked units/6,705 data+BSS
sections) and all66 tests pass. Accepted code is1,881,056 bytes;924 functions
remain outside linked source. Matched data remains904,399 bytes.


The matrix-slot allocator at `801C9E3C` adds 196 bytes. A shared typed pool
view refines the existing Node constructor declaration while preserving its
complete 1,684-byte compiler text allocation and whole object hash. The two
incoming calls, original borrowed identity float and all actual relocations
retain their existing owners. The control-flag synchronizer at `800936D0`
adds 648 code bytes and 20 bytes of genuine LOCAL exception/index metadata;
its complete 296-byte caller allocation remains unchanged.

A genuine worker-color class startup at `80269A30` adds 52 code bytes and its
natural four-byte LOCAL startup pointer. It takes ownership of the previously
accepted 1,616-byte BSS extent with identical GLOBAL object identities, sizes
and alignment. The old typed-storage source and four frozen historical
contracts remain preserved. Eleven full consumer objects are unchanged, and
the neighboring 16-byte padding remains original and uncredited. The actual
borrowed constants are `8037B650 = 0.0` and `8037B654 = 1.0`; this verified
observation supersedes the earlier preflight's reversed values. No alias or
artificial startup symbol was introduced.

Both full native links retain the original DOL hash. Baseline comparison,
complete section coverage, every preceding ownership audit, 5,735 source-unit
extents with 6,708 data/BSS sections, and all 66 tests pass. An initial final
audit caught the old Node source hash; a narrow replay preserves its original
source witness and complete object contract while separately checking the
new source and shared header. Its failed log is preserved. The checkpoint
receipt is `scratch/continuation_20261012_b/matrix-worker-control-acceptance.json`.


The bounded related-record owner destructor at `801D9FC0` adds 2,112 bytes
with its original GLOBAL C identity and `void*(void*, int)` ABI. Its eleven
typed arrays, nested block/BitSet lifetime, retained Handles and unsigned
record-ID sentinel preserve all 54 retained actual relocations. A scoped
nonowning ID view borrows the existing 104-byte record only during release;
its explicit empty destructor is an inferred source lifetime, with no claim
that the original class name is known. The emitted 60-byte weak backup is
unreferenced and appears UNUSED under the actual source owner in both native
maps, receiving no credit. The sole full existing caller and original
96-byte vtables remain unchanged. Both native hashes, every preceding audit,
5,736 source extents with 6,708 data/BSS sections and all 66 tests pass. Receipt:
`scratch/continuation_20261012_b/related-destroy-acceptance.json`.


Dimension reset at `80071508` adds 312 code bytes, 20 bytes of genuine LOCAL
exception/index metadata and three natural compiler LOCAL doubles (24 bytes).
The complete active relocation and original all-byte pointer census establishes
sole ownership of the original constants at `803788E0..803788F8`. Their previous
inferred GLOBAL names are retired with no aliases; the original `Agent_Z` string
and four zero bytes remain in the 12-byte align1 prefix. The prior float contract
and full 36-byte original fragment fixture are unchanged. Only its exact three
old provider rows and one old fragment row replay through the strict successor
proof; all other historical rows keep their original checks. The emitted
`.sdata2` flags and all six allocated relocations are verified without masks.

Slot invalidation at `801D8580` adds 164 code bytes while retaining its original
GLOBAL C entry. A scoped readonly child view and typed array access preserve the
original address computation and final alias-sensitive reload. The two full
88-byte original table consumers stay unchanged. Its unreferenced 60-byte weak
view destructor is UNUSED under the real source owner in both native maps. Both
full native hashes, baseline comparison, every prior audit, 5,738 source-unit
extents with 6,711 data/BSS sections and all 66 tests pass. Receipt:
`scratch/continuation_20261012_b/dimension-slot-acceptance.json`.


The bounded cached-record destructor at `801D87AC..801D890C` adds 352 code
bytes. Its readonly index view borrows each 104-byte record while releasing
the registry owner field; the actual record array is destroyed afterward. The
already established native base-cleanup entry receives flag zero. A new shared
forward ABI declaration makes the typed primary and its sole existing C++
caller coherent; the complete 388-byte caller compiler ELF remains byte
identical, including all raw symbols and actual relocations. Only the archived
source receipt for that caller is routed through a fixed narrow proof, preserving
the immutable old RTTI receipt and complete old source/object fixtures. Both
actual native maps retain exactly 352 new source bytes and mark the inferred
view's 60-byte backup destructor UNUSED. Complete original base and table
providers, all prior audits, the unchanged DOL hash, baseline changes, 5,739
source extents across 6,711 data/BSS sections, and all 66 tests pass. The frozen
root receipt is `scratch/continuation_20261012_b/cache-destroy-acceptance.json`.


The quartic and cubic real-root solvers at `801DE498..801DEF20` add 2,696
code bytes and sixteen naturally emitted LOCAL doubles (128 bytes). Ordinary
real-root formulas and the supported double reciprocal-square-root intrinsic
preserve every allocated byte, actual symbol and 113 real relocations. The
full active graph and original all-byte census establish the sole literal
owner; sixteen inferred GLOBAL literal labels are retired without aliases.
The original twelve-byte prefix and its two genuine GLOBAL constants remain
original. The complete coarse original caller fixture remains immutable; its
retired labels resolve only inside a SHA-pinned historical snapshot check,
with the live resolver restored afterward.

A genuine 2,048-byte `Buffer` default at `802A19F8..802A21F8` now emits the
existing parser's exact typed zero-initializer object. Its sole existing
parser compiler ELF, both HA/LO references, surrounding alignment and
following readable pool remain unchanged. The replacement has no code,
helpers or relocations. Native GLOBAL ownership uses the actual linker map,
unique active provider, complete compiler object and objdiff source record;
ELF FILE symbols precede the GLOBAL region and do not label later GLOBALs.
Both native DOL hashes, all preceding allocation/consumer audits, baseline
comparison, 5,741 source extents across 6,713 data/BSS sections, and all 66
tests pass. Root receipt: `scratch/continuation_20261012_b/polynomial-buffer-acceptance.json`.

The state-descriptor group at `80374A18..80374BFC` adds 484 matched data
bytes: a genuine velocity-scale float and sixty typed runtime descriptors.
Its complete compiler object emits 61 GLOBAL objects and 119 actual relocations,
with no code or hidden allocations. All 87 complete consumers and 178 incoming
references remain unchanged. The final descriptor's provisional twelve-byte
annotation is refined to its real eight-byte type; the original four-byte zero
tail remains original and uncredited. Exact historical rows replay through the
full successor proof while immutable old fixtures remain preserved. Both native
hashes, all preceding checks, 5,742 source extents across 6,714 data/BSS sections
and all 66 tests pass. Receipt:
`scratch/continuation_20261012_b/state-rtti-acceptance.json`.

The platform and memory-card descriptor groups add 344 data bytes, including the
native signed error enum, three default-name pointers and forty-one typed RTTI
records. Both complete objects emit45 GLOBAL allocations and82 actual relocations.
Their32 complete consumers and311 incoming references stay unchanged. Only the
two last provisional twelve-byte annotations become genuine eight-byte records;
each following four-byte zero tail remains original and uncredited.

The token text storage unit owns144 BSS bytes with two character buffers and the
previously accepted float[3] vector, adding132 matched bytes. Fifteen complete
consumers and114 incoming references remain exact. The old vector source and
its complete evidence stay immutable; its exact historical contract row now
replays through the complete current sole-owner proof. Both native hashes,
baseline changes, all prior audits,5,744 source extents across6,716 data/BSS sections
and all66 tests pass. Root receipt:
`scratch/continuation_20261012_b/other-rtti-token-acceptance.json`.

Five bounded platform storage units add72 BSS/SBSS bytes: the32-byte disc read
buffer, disc poll status and flags, movie decoder integers, frame flags and
timestamps, and actor elapsed time. Thirteen real GLOBAL objects retain their
existing accepted declaration types, including the already established volatile
frame flag. Seven natural compiler alignment bytes belong to these complete
sections; no padding members are invented. Ten complete consumers and66 incoming
references remain unchanged. All six surrounding original fragments retain
pinned complete objects, exact symbol inventories and actual native map rows.
The sole provisional eight-byte status annotation becomes its declared four-byte
word; its original four-byte tail stays uncredited. Both native hashes, baseline
comparison, every preceding audit,5,749 source extents across6,721 data/BSS
sections and all66 tests pass. Root receipt:
`scratch/continuation_20261012_b/small-storage-acceptance.json`.


Accepted actor triple-vector reset on 2026-10-15: ordinary member setters
recover `fn_800966D8`, 200 exact code bytes and 20 native exception/index
bytes. The target flag, three vector assignments and control-stop calls
retain their original order. Seven allocated relocations and the compiler
metadata relocation are exact. The original operation-table consumer,
global zero-vector provider and control-stop provider remain complete and
unchanged. Both native links, original DOL hash, baseline regression checks,
all preceding ownership proofs, complete coverage, source extents and all
66 tests pass. The accepted receipt is
`scratch/continuation_20261012_b/actor-three-reset-acceptance.json`.
The original 204-byte near probes remain preserved and uncredited.


Accepted state operation records on 2026-10-15: the complete 560-byte group at
`802B87C0..802B89F0` now comes from ordinary typed C++ records. Twelve operation
records and eleven base lists retain all 23 GLOBAL identities and all 95 actual
relocations. The 23 source consumers now use typed declarations; their complete
compiler objects are byte-for-byte unchanged. All 55 provider objects, 59 incoming
references and original initialized-pointer targets remain verified. Original
providers outside this data group earn no code credit.

The historical source and RTTI fixtures stay immutable. Exact old rows route
through the current sole-owner proof. The first acceptance attempt exposed that
MWLD lists individual LOCAL exception-index entries instead of a section header;
the corrected verifier checks every entry and full contiguous coverage. Canonical
checks preserve frozen complete proposals and require exact current owned rows.
Both native hashes, all previous proofs, baseline comparison, complete coverage,
5,751 source extents across 6,724 data/BSS sections and all 66 tests pass. Receipt:
`scratch/continuation_20261012_b/state-native-acceptance.json`.


### Property handles and complete object-list clearing, 2026-10-15

The property-handle slot routine at `80059BA8` adds 432 code bytes and 108
owned exception-metadata bytes. Its ten-iteration loop constructs named
handles, retains each slot, destroys all temporary handles and dispatches the
resolved result. The native creation entry receives the address of a separate
four-byte Name copy. This explicit C-entry view has a different C++ function
type from existing by-value declarations, but the compiler and callee audit
prove the same native copy-address ABI; the callee reads that copy without
writing or retaining it. The three earlier callers, all eight existing
compiler objects and thirteen native providers remain unchanged.

All five emitted weak destructor backups and their ten EH/index records are
discarded. Four weak bodies resolve to their existing strong definitions in
the linker symbol-resolution tree; the fifth has an individual UNUSED row.
The initial strict checker incorrectly expected five UNUSED layout rows and
interpreted raw input-section summary sizes as retained extents. Its frozen
successor instead checks all four exact resolution branches, the private
UNUSED row, every discarded metadata row, and all three retained positive
symbol allocations. The original failed log, checker and source are preserved;
neither source bytes nor compiler objects changed for this correction.

The object-list group clear at `80285E10` adds 200 code bytes, four actual
allocated relocations and one compiler metadata relocation. It saves each next
node before returning the current node to the pool, clears both head/tail pairs,
and returns whether either list was initially nonempty. An ordinary head-value
wrapper and local initialization order reproduce the original saved-register
allocation. The two complete callers and two borrowed providers remain
unchanged. Together with the earlier 128-byte node acquisition, this closes all
1,556 code bytes and twelve functions in `80285C74..80286288`; pool storage and
external constants retain their separate ownership.

Both native outputs pass the immutable original DOL hash, all earlier proofs,
complete section coverage, source extents, baseline comparison and all 66 tests.
The combined receipt is
`scratch/continuation_20261012_b/property-list-acceptance.json`.


### Costume state operation records, 2026-10-15

The complete 320-byte data block at `802B89F0..802B8B30` is now supplied by
typed operation records and base-class lists in
`src/Game/costume_native_operations_802B89F0.cpp`. It retains twelve GLOBAL
object identities and all 55 actual pointer relocations. Of the block, 88 bytes
were already accepted base-list source; the net gain is 232 data bytes. Three
prior source units and three original fragments retire from the active link,
while their source, compiler objects and historical proofs remain preserved.

The shared header describes the exact callback signatures. Four genuine C++
destructors retain their native self/short/returned-self convention, and two
cleanup entries retain their C signatures. Declaration-only corrections in
eleven consumers leave all eleven complete compiler objects byte-identical.
The full incoming census and all original initialized pointer positions remain
conserved. Earlier RTTI proofs transfer only the six exact retired owners and
their physically unchanged relocations; unrelated providers remain strict.

The earlier scene-disable proof expected its caller in an original 84-byte
fragment. Its pinned successor verifies that entire original fragment and the
new complete source, then accepts only the same ADDR32 relocation at physical
address `802B8A80`: offset 20 in the retired object becomes offset 144 in the
new object. The original failed log and checker are preserved. No code or data
bytes were changed to accommodate the checker.

Both native outputs pass the original DOL hash, all previous proofs, full
section coverage, source extents, baseline comparison and all 66 tests.
The receipt is `scratch/continuation_20261012_b/costume-native-acceptance.json`.


### Bootstrap closure, defeated entry and optional stream read, 2026-10-15

Three source units add 1,200 code bytes and four functions. The bootstrap
closure at `8001F614..800200F8` reconstructs nine contiguous functions together
with all 344 exception metadata bytes and 241 bytes of compiler-local strings.
It adds 536 code bytes and 40 newly owned metadata bytes, preserving the 2,252
code bytes and 545 data bytes supplied by eight earlier accepted units.
Their historical sources, complete compiler objects and proofs remain preserved.
The original compiler-local object identities replace three coarse GLOBAL
string-pool labels; no string bytes or neighboring allocations change.

The defeated-state entry at `80088FF4` adds 236 code and 36 exception metadata
bytes. Its two weak Handle backups and their exception metadata are discarded
under existing strong providers and receive no credit. The optional resource
stream read at `801B3FD0` adds 428 code bytes without owned data or helpers.
Its six complete incoming objects and eight entry calls remain unchanged.

Matched data rises by 180 bytes: 76 newly reconstructed metadata bytes plus
104 already source-owned metadata bytes that now match in the combined
bootstrap object. The frozen reporting ledger retains both original objdiff
reports and replays the complete old object relocations. The 104 bytes are
not counted as newly reconstructed data, and the 241 literal bytes are migration
only. Caller proofs transfer the exact physical registry call at `8001F9B0`
and the retired string-pool contract to the complete bootstrap owner; all
unrelated checks remain strict.

Both native outputs preserve the original DOL hash. Full acceptance includes
all previous proofs, original section coverage, source extents, baseline
comparison and all 66 tests. The receipt is
`scratch/continuation_20261012_b/bootstrap-defeated-stream-acceptance.json`.


### Selected state operation records and nested-array search, 2026-10-15

Eight complete data ranges between `802B8B30` and `802B9250` now own 1,008
bytes: twenty-one native operation records and their twenty-one base-class
lists. The ranges preserve all 42 GLOBAL object identities and 168 actual
pointer relocations. The net gain is 588 data bytes; 420 previously accepted
base-list bytes migrate unchanged. All gaps and neighboring records retain
their existing owners. These are typed native C-entry operation records,
without a claim that the compiler emitted C++ vtables.

Twenty destructor slots retain the genuine C++ self/short/returned-self ABI,
verified by explicit destruction and delete probes. The remaining cleanup
slot retains its C signature. The shared declarations preserve all accepted
callback signatures, including event argument counts. Existing scalar
forwarders do not uniquely distinguish float from double; the declarations
retain the accepted formal type without asserting new precision evidence.
All 42 declaration-corrected consumers retain byte-identical complete compiler
objects. The NameHandle constructor's discarded weak code and metadata remain
excluded. Earlier RTTI proofs transfer only the exact old source/fragments and
physical relocation sites, preserving all unrelated evidence.

The 108-byte function at `8024A800` searches nested integer arrays and returns
the first outer index containing a key, or -1. Ordinary count and const-index
accessors reproduce the original loop structure without helpers, owned data
or actual text relocations. Its two complete original caller objects retain
all 3,064 bytes and 49 relocations.

All 51 production compiler objects match the frozen complete objects. Both
native outputs pass the original DOL hash, every historical proof, complete
section coverage, source extents, baseline comparison and all 66 tests.
The receipt is `scratch/continuation_20261012_b/selected-state-array-acceptance.json`.


### Interpreter initialization, owner lists and actor callbacks, 2026-10-15

Six complete functions add 6,232 code bytes, and their metadata, constants and
the audio gain table add 380 data bytes. The standard and mapped ELF outputs
are byte-identical, the original DOL hash passes, and every historical proof,
coverage/extents check, baseline comparison and all 66 tests pass. The receipt
is `scratch/continuation_20261012_b/initializer-owner-audio-actor-acceptance.json`.

The 396-byte interpreter initializer at `8001F38C` now owns its 20-byte exception
metadata and the four already-accepted GLOBAL cache objects totaling 3,224 BSS
bytes. The BSS migration earns no additional data credit. A shared internal
cache declaration preserves the opaque pointer payload and the separate Python
record payload. Both the initializer and previously accepted module lifecycle
retain their complete compiler objects. Original startup code and its constructor
entry remain outside this partial unit. The historical bootstrap, registry and
storage proofs transfer only explicitly pinned ownership and declaration changes.

The adjacent owner-list unlink and reorder routines at `80212AA0..80213824`
now match as a 3,460-byte unit with 89 retained relocations. A typed index that
converts to a const integer reference, a typed entry array and a signed generation
comparison reproduce the original register lifetimes. Both complete external
callers remain unchanged. The compiler's 84-byte weak destructor stays unlinked.

The audio gain curve at `802F15D0` owns 128 unsigned 16-bit entries, generated by
the exact integer quadratic formula. Its 48-byte original neighbor retains all
ten pointer relocations. The C-unit checker accounts for the build system's
standard `-lang=c` insertion; the first failed checker log remains preserved.

Camera field-of-view jitter at `80079094` contributes 524 bytes, the random actor
resource callback at `8005DD34` contributes 772, and queued actor resource events
at `8005C6F0` contribute 1,080. Each owns its exact exception metadata and sole
compiler-local integer-to-floating conversion bias. The three original constant
fragments total 68 bytes: 24 migrate to genuine LOCAL bias objects, while all 44
neighbor bytes retain original ownership. No global alias is added. Full incoming
reference scans, native providers and complete caller objects are pinned.

The two actor callbacks pass an opaque pointer through virtual slot 78, supported
by the accepted named-effect caller. Their two identical 84-byte weak destructor
bodies and metadata remain discarded. The camera unit's three weak destructor
bodies also remain uncredited. Seven complete production compiler objects match
their frozen proofs, with all allocated bytes and actual relocations accounted for.

The historical replay also exposed a missing public helper in the initializer's
bootstrap wrapper. A versioned successor executes the previous verifier unchanged
and restores the exact original assembly-receipt function. Three callers change
only their pinned helper path and hash. Positive and negative API checks pass;
the source, compiler objects and native output are unchanged by this correction.


### Scene, screen and actor controls, 2026-10-15

Thirteen complete functions add 7,804 code bytes and 656 data bytes. The standard
and mapped native outputs are identical and retain the original DOL SHA1.
All historical acceptance gates, baseline regression, complete coverage/source
extent checks and 66 tests pass. The complete acceptance receipt is
`scratch/continuation_20261012_b/scene-actor-control-acceptance.json`.

Scene transition at `80046D60` contributes 1,808 bytes and world reinitialization
at `800BD6A8` contributes 992. The two genuine LOCAL conversion biases own 16
bytes within 368 original floating bytes; all 352 neighbor bytes retain original
ownership and every old positive identity. Plot setup now declares the actual
fourth integer mode argument, preserving its complete 828-byte compiler object.
The original scene routines' other data and their unlinked weak backups remain
outside the new partial units.

Camera shutdown at `800751F4` contributes 428 bytes with an ordinary typed entry
array and no alternate manager cast. The 360-byte position and 356-byte stop
routines likewise retain all their compiler allocations and no helper or pool.
Stop forwards one opaque word through its ignored query argument. Its delegate
and Python binding use consistent declarations; Python still parses an unsigned
byte, and both complete caller objects are unchanged. Only the two exact old
source receipts have bounded native successors.

Named scene setup at `800C10BC` contributes 548 bytes and 56 exception/index
bytes. Its Name parameter uses genuine nontrivial by-value copying. Its 112-byte
Handle destructor backup independently matches the existing strong owner and is
not credited again; the private 76-byte return-wrapper backup and all unlinked
metadata are discarded normally. The two migrated screen callers preserve their
exact Name-callee calls; all other complete caller and provider witnesses remain
unchanged under a narrowly pinned successor of the original proof.

Five actor-array routines at `800842B0`, `80084578`, `80086654`, `80086C7C` and
`80087394` contribute 2,436 bytes. Ordinary typed index and entry accessors retain
the native handle lookup evaluation. The accepted Array declaration and strong
destructor remain unchanged. Each source's weak destructor and exception metadata
are discarded normally, and the original callback tables retain every pointer.

Actor direction setup at `80084A14` contributes 568 bytes using one opaque-pointer
entry representation for both typed object views. Its 20 exception/index bytes,
original table pointer and eight complete providers are proven; no constants or
BSS ownership is added. Scoped property reset at `80084DCC` contributes 308 bytes
and 36 exception/index bytes, with all three genuine Handle-layer destructor
backups resolving to their existing strong owners without new credit.

The RTTI census preserves all 311 references, 82 providers and 32 complete
consumers. Exactly ten unchanged original symbol records move into the preserved
308-byte original prefix; the complete 992-byte scene reset and its LOCAL bias
partition provide the independent ownership proof. A token-storage source scan
permits exactly one unused extern declaration in the direction routine; its
complete compiler object has no symbol or relocation to those BSS objects.
The earlier checkers and audit inputs remain immutable.

The historical witnesses, superseded helper versions, rejected probes and failed
checker logs remain preserved. All native source credit derives from complete
production compiler objects and actual relocations, not private text scores.


### Owner queries, input threshold and five property slots, 2026-10-15

Four complete routines add 1,272 code bytes and 224 exception/index bytes.
The standard and mapped native outputs are identical and preserve the original
DOL SHA1. Historical acceptance, baseline regression, complete coverage, source
extents and all 66 tests pass. The full receipt is
`scratch/continuation_20261012_b/lookup-input-acceptance.json`.

Current-owner lookup at `8005E9A0` owns 296 code and 56 metadata bytes. An ordinary
inline accessor preserves the observed handle lifetime; the 112-byte destructor
backup and its 52 metadata bytes resolve to an unchanged strong owner. Input
threshold at `80085298` owns 284 code and 20 metadata bytes. Its local double-axis
snapshot is normalized in place, leaving input storage unchanged. It emits no
helpers or constants, and all existing feedback-interface consumers are intact.

Available-handle lookup at `80059AA4` owns 260 code and 40 metadata bytes. The
slot resolver retains the owner/member/index structure. The returned four-byte
handle uses the observed native hidden-return ABI; the two accepted callers
remain byte-identical. Its 228 weak destructor bytes and 104 metadata bytes are
independently exact at their existing strong providers and receive no new credit.
The historical factory-provider checks retain their old witnesses under bounded
successors for the new source owner.

Five-slot property setup at `8005848C` owns 432 code and 108 metadata bytes.
Its Name-copy structure follows the already accepted ten-slot routine. The
explicit native C-entry view of the initialized Name copy is documented without
claiming identical source-level formals. Four strong destructor providers
resolve weak backups; the private return-wrapper destructor and all ten weak
metadata atoms are genuinely unused in the native map. All 540 weak code and
228 metadata bytes remain uncredited. The sole original external caller at
`8005863C` is preserved as a complete 316-byte object with its metadata.

The two property routines emit identical 76-byte weak return-wrapper destructors.
The native linker reports one unused representative from the five-slot source;
neither copy contributes linked bytes. A bounded successor proves both complete
objects, identical raw code and relocations, all four discarded-only references
and all four unused metadata atoms. The original checkers remain preserved, and
the ownership change adds no source credit.

All four sources retain their complete compiler sections, raw symbols and actual
relocations. No new literal, BSS, shared-header or original-input changes were
needed. The earlier proof versions and private probes remain preserved.


### Primary bounds, mode selection and queue construction, 2026-10-15

Three routines add 1,024 code bytes and 60 exception/index bytes. Standard and
mapped native executables are identical and retain the original DOL SHA1.
Historical acceptance, baseline regression, complete coverage, source extents
and all 66 tests pass. The complete acceptance receipt is
`scratch/continuation_20261012_b/queue-mode-bounds-acceptance.json`.

The primary resource sphere query at `8021F340` owns 472 code bytes with no
helpers, constants or exception data. Its enclosing resource accessor produces
the original register allocation. All 31 external table pointers, 28 complete
consumers and three complete provider objects remain verified. A bounded proof
successor permits exactly one unrelated virtual-table symbol rename in one
whole original data input, conditional on the full queue-constructor proof.

Mode resource selection at `8005863C` owns 316 code and 60 metadata bytes.
Its four-byte hidden-return convention matches all three existing caller
objects. Two destructor backups and their 104 metadata bytes resolve to existing
strong owners; their 228 code bytes receive no new credit. The native proof
identifies LOCAL caller metadata by its full address, extent and map owner;
repeated compiler-local names in unrelated units are not global identities.
The immutable property-setup and scene-controller witnesses remain preserved
under finite successors for this original-to-source provider transfer.

The queue constructor at `802318C0` owns 236 code bytes. A genuine C++ constructor
initializes four groups of eight handles and emits the observed array helper
calls without an assembly wrapper. Its constructor and virtual-table names
replace the two original GLOBAL names; no aliases are introduced. Two accepted
source consumers change only those names. Their 220 code bytes and the original
64-byte virtual table remain byte-identical and receive no new credit.


### Matrix cache, child rebind, vector callback and memory-card dispatch, 2026-10-15

The four new routines add 1,056 code bytes. Standard and mapped native executables
are identical and retain the original DOL SHA1. Historical acceptance, baseline
regression, complete coverage, source extents and all 66 tests pass. The receipt
is `scratch/continuation_20261012_b/matrix-child-callback-memcard-acceptance.json`.

The genuine MatrixCache_Z constructor adds 576 bytes. Its complete source also
contains the already matched 164-byte destructor, four-byte record constructor
and 12-byte compiler virtual table, with no duplicate credit. Four original
GLOBAL identities migrate to compiler-generated C++ names. The sole original
factory consumer changes only its undefined constructor spelling; all 1,476
bytes, both function identities and the remaining original table tail survive.
All 42 allocated relocations and three compiler category references are checked.

Child-handle rebind at 801D0518 contributes 192 bytes. The source preserves both
incoming table pointers and all complete consumers and providers. Its typed
handle-reference argument and short reference-count parameter agree with the
accepted provider. It emits no helpers, data or exception metadata.

The vector callback at 802567DC contributes 280 bytes. Ordinary scalar dot-product
helpers reproduce the original floating-point schedule. Public arguments agree
with the existing Python binding, and Matrix3 agrees with its accepted provider.
The adjacent two original functions retain all 1,700 bytes, raw symbols and
13 relocations in their own original input. No helper or data bytes are emitted.

The memory-card partial virtual interface preserves the existing 1,756 code
and 40 metadata bytes and recovers its authentic eight-byte secondary dispatch
thunk. Its partial view table and destructor thunk are normally discarded in
both native links. The complete original table and destructor thunk remain
original-owned. Finite historical successors preserve earlier immutable
source and object receipts; no complete original class reconstruction is claimed.


### Stream readers, startup and virtual dispatch, 2026-10-15

This batch adds 3,508 matching code bytes across 17 functions, plus 40 bytes of
exception metadata. Both complete native links retain the original DOL SHA1.
All previous native ownership checks, baseline regression, complete coverage,
source extents and 66 repository tests pass. The acceptance receipt is
`scratch/continuation_20261012_b/agent-stream-tree-startup-acceptance.json`.

Two stream readers contribute 876 and 1,420 bytes. Their ordinary array, index
and stream abstractions reproduce the complete compiler objects without helper
or data allocations. The 444-byte existing cursor caller has a corrected stream
formal and forwarding expression; its whole compiler object remains identical.
The smaller reader's former original provider is transferred through a bounded
successor that requires the larger reader's complete native proof.

The screen event routine contributes 280 bytes and 20 exception bytes. The early
service initializer adds 216 bytes and 20 exception bytes through genuine C++
allocation and complete constructor class declarations. Its three pooled string
addresses are verified against their separate original owners, with no string
credit. The original 1,476-byte caller remains intact.

Tree handle propagation contributes 620 bytes. Its two const Handle reference
arguments agree with the typed field and derived Handle at its sole external
caller. The corrected 704-byte caller object remains identical. All recursive
calls and 16 retained relocations are conserved, while three natural unused
destructor helpers totaling 264 bytes receive no credit. Discarded duplicate
helpers in a separate input are resolved against six original strong winners.

Twelve genuine compiler-generated secondary dispatch thunks contribute the
remaining 96 bytes: eight Agent thunks and four callback thunks. Existing method
code and exception data remain preserved without duplicate credit. Original
full tables and destructor-thunk remainders retain their original owners. The
complete native maps prove unowned partial view tables and destructor backups
are discarded. No complete original translation-unit or class claim is made.

The first new native preflight exposed a variable-shadowing error in the motion
pair checker: a coincidence symbol record replaced the object filename used by
the map filters. The immutable V2 failure and exact V3 checker correction are
preserved. The correction changes no source, object, native bytes or ownership
requirement; the expected unused thunk rows are present in both maps.

The first full acceptance run also identified older frozen reference lists that
needed bounded successors. One Name call keeps its exact instruction and target
while its 280-byte caller transfers from original input to source. Four complete
original callback tables retain every byte while eight undefined method names
and their corresponding relocations acquire the genuine compiler identities.
Both successors require the complete current native proofs, preserve the old
receipts and pass 94 mutation guards. They add no source or data credit.


### Handle lifetime, queue selection and callback work, 2026-10-15

This batch adds 4,596 matching code bytes across 13 functions, plus 60 bytes of
exception metadata and one 4-byte constructor entry. Both complete native links
retain the original DOL SHA1. All previous native ownership checks, baseline
regression, complete coverage, source extents and 66 repository tests pass.
The acceptance receipt is
`scratch/continuation_20261012_b/array-callback-handle-acceptance.json`.

Two retained-array assignments contribute 1,048 bytes. The queue selector and
named-target binder contribute 1,316 bytes through a coherent two-source proof:
the selector's original defined binder reference becomes an undefined reference
to the matching source binder, preserving the complete native call and the
6,008-byte original suffix. Natural discarded destructor helpers receive no
credit. Related-handle replacement contributes 544 bytes, and owner reset adds
616 bytes with the original complete-object root and typed index semantics.

A generation-checked lookup contributes 416 code and 40 exception bytes. Its
by-value temporary is destroyed before comparison, while complete original
callers preserve the four-byte C-entry return convention. The natural weak
Handle destructor and its unused exception metadata remain discarded behind
the accepted strong provider. Callback Handle assignment adds 236 bytes with
its existing shared header unchanged. The final pointer-return guard reproduces
the observed comparison without an assembly directive or fabricated register
constraint. A 28-byte flag routine reproduces its two zero-result paths using
the documented unoptimized compiler setting.

The platform startup contributes 92 bytes and its complete LOCAL 4-byte .ctors
pointer in the same build unit. Its borrowed context and original 12-byte BSS
provider receive no new storage credit. The source uses the existing opaque
destructor-chain declaration. Native preflight identified the linker-generated
GLOBAL `_ctors` symbol spanning the unchanged 80-byte table. A narrow checker
correction verifies that complete table and the LOCAL source entry independently;
64 mutation guards pass, and the original failed checker and log are preserved.

Two callback groups add 300 bytes across three functions, including a clamp and
two genuine secondary dispatch thunks, plus 20 exception bytes. Existing
method code and exception data remain preserved. Their full original virtual
tables retain their ownership; bounded checker successors recognize only the
specific compiler symbol and relocation names that change, with no table data
credit. The primary-bounds successor requires both complete new callback native
proofs before accepting those exact name changes.


### Child dispatch, registry release and reflection setup, 2026-10-15

Six complete compiler source objects add 2,532 code bytes across six functions
and 60 exception bytes. Both native outputs preserve the original DOL SHA1;
all historical ownership checks, baseline regression, complete coverage, source
extents and 66 tests pass. The acceptance receipt is
`scratch/continuation_20261012_b/child-paired-selection-acceptance.json`.

The 500-byte owner/child dispatcher uses the verified Root and Handle layouts,
a reference-taking typed entry array, and the observed virtual slots. Its
complete 3,264-byte original table input retains its original ownership.

The 240-byte paired dispatcher and adjacent 404-byte registry-release routine
replace their complete original 644-byte input together. The independent proof
conserves all 12 original code relocations, checks both whole compiler objects,
and preserves nine complete relevant original/provider inputs and four table
references. Four existing spatial Handle weak definitions remain discarded;
their actual UNUSED map rows are verified and receive no source credit. The
registry call uses its verified pointer-to-word key arguments. These partial
class views establish the accessed ABI without claiming complete class identity.

The 260-byte selection-record lookup uses an ordinary record-array member and
the existing shared record declaration. It also owns its natural 20-byte
exception metadata. The 592-byte owner/controller flag synchronization uses
an ordinary owner predicate and the supported compiler propagation setting.
Its four complete callers preserve seven real calls, while two instruction
coincidences retain their complete owners. Its natural 20-byte exception data
is source-owned; borrowed managers, resources and providers receive no credit.
The 536-byte reflection setup uses one physical resource-entry table and
ordinary typed accessors. Its returned four-byte Handle temporary is released
once; the unchanged constructor, retain/release and destructor providers are
checked in full. Its natural 92-byte unused destructor and 20-byte unused
exception backup remain discarded and receive no credit. The source owns
536 code bytes and its separate 20-byte exception metadata.
Only the six original private exception symbol names change to their natural
compiler LOCAL names. All existing GLOBAL identities, source and headers remain
preserved.


### World handle fill, record population and Handle copy, 2026-10-15

Three complete compiler objects add 1,824 retained code bytes. The 728-byte
world handle fill uses the verified ObjectsOwner base and a borrowed pointer
value. Its five natural weak helpers, totaling 452 bytes, remain discarded.
The 580-byte record population routine uses the complete verified 168-byte
record and four-byte Handle layouts, one physical registry view and ordinary
typed accessors. Its 172 bytes of weak destructor output remain discarded.
The original 2,336-byte provider is partitioned into a 392-byte original prefix,
the 580-byte source routine and a 1,364-byte original suffix; neither original
fragment receives source credit. The 516-byte Handle copy leaves its adjacent
928-byte assignment routine in original assembly. Both original object
partitions conserve their bytes, symbols and actual relocations.

The historical 108-byte lookup and 236-byte queue constructor retain their
original claims through finite provider-transfer checks. All unchanged callers,
providers, positive native identities and discarded helpers remain checked.
Two readable GLOBAL character arrays add 912 data bytes for commands and audio
diagnostics; complete source consumers and boundary owners remain unchanged.
The additional 56-byte readable animation array preserves the original
48-byte prefix and all seven original gap bytes. Its consumer declaration gains
the verified const qualifier without changing its compiler object. The canonical
source receipt and the finite historical source route preserve that exact
declaration-only change.

Both native links reproduce the original DOL SHA1. Complete ownership checks,
baseline regression, source extents, complete coverage and all 66 tests pass.
The acceptance receipt is
`scratch/continuation_20261012_b/world-record-copy-acceptance.json`.
