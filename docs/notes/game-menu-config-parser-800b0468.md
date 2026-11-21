# Menu configuration parser at 800B0468

The reconstructed parser reads menu configuration tokens, resource and font
handles, names and color values. Its partial object views contain only the
observed fields. Typed Handle temporaries reproduce the original destruction
order and exception actions.

The complete source body is 2,120 bytes at 800B0468..800B0CB0, with 124 bytes
of exception actions at 80011224 and a 12-byte index at 8001BEF4. Its 192-byte
small-data section spans 80379178..80379238. Those small-data bytes were already
source-owned by `scalar_constant_80379218.c`; their transfer earns no new data
credit. The scalar provider retains the exact 136-byte suffix at
80379238..803792C0.

All 24 prefix token symbols keep their GLOBAL identities and extents. Four
exclusive literals become their natural compiler LOCAL symbols: the 255.0f
color divisor, FONT, _MASK and signed conversion bias. The complete active
input census finds all 12 references to those four literals in this function.
The compiler emits their original alignment naturally, with no source filler.

The parser emits four weak Handle destructor backups totaling 460 code bytes
and 208 exception/index bytes. The accepted current providers are the Python
resource lifecycle group for 8001FF04/8001FF78 and the standalone providers for
80020B90/800723F4. Fresh recompilation verifies all three complete provider
objects. Every weak body and actual operand relocation agrees with its strong
provider. An isolated native link selects the strong definitions and discards
all 12 backup allocations. Backup output earns no additional source credit.

Frozen candidate, ownership census, literal migration, complete symbol and
relocation inventories, compiler logs, and native proofs are in
`scratch/menu_config_parser_800B0468_20261020_parallel/`. The read-only verifier
is `verify.py` there. Root integration receipts live in
`scratch/menu_config_integration_20261020/`.

The production objects, full native map, original DOL SHA-1, baseline regression
check, source extent audit and all 66 unit tests pass. The map proves all
12 parser backup allocations discarded and both buffer initializers retained.
The generated report records 74.1341% code and 94.6604% data matched, with
7,984 of 8,803 functions reconstructed. Code and data denominators are unchanged.

The retained exception symbols use their native LOCAL names @217 and @218.
Matching these names in the original comparison object lets objdiff recognize
the complete 136 exception/index bytes alongside the discarded weak metadata.
