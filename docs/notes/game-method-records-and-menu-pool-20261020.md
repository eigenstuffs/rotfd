# Further method records and menu strings

Twelve source units now reconstruct 893 additional data bytes. GC/1.3.2 with
the established flags emits exact sections, global symbol sizes/offsets and
133 new pointer relocations. All new enclosing sections end on eight-byte
boundaries.

Seven existing `native_rtti_base_lists_*.cpp` sources absorb neighboring native
method/base records:

| Source suffix | Added range | Added bytes |
| --- | --- | ---: |
| `802B8B90` | `802B8BA4..802B8BC0` | 28 |
| `802BB210` | `802BB230..802BB248` | 24 |
| `802BD530` | `802BD5C4..802BD720` | 348 |
| `802BF5E8` | `802BF5F4..802BF618` | 36 |
| `802C8DD8` | `802C8DF8..802C8E28` | 48 |
| `802C9248` | `802C9268..802C9280` | 24 |
| `802C9540` | `802C9554..802C9580` | 44 |

The original jump tables at `802BD720..802BD740` and `802BF618..802BF650`
remain in explicit original splits. This work does not reconstruct their
functions or claim complete original translation units.

Three complete 72-byte callback member arrays at `802B6270`, `802B65D0` and
`802C8A78` now have source owners. Each holds six native three-word member
descriptors; the previously reconstructed registries and dispatchers establish
their layout and slots. Their preceding original method records are retained.
The 48-byte platform audio method table at `802F16D0` also matches, including
all ten real pointer relocations.

`menu_parser_literal_pools_802A0250.cpp` absorbs the complete 76-byte pooled
string symbol `lbl_802A03B4`. Its natural alignment after the preceding pool
accounts for one further byte. The complete `.rodata` extent is now
`802A0250..802A0400` (432 bytes), without padding declarations.

Production object verification, original DOL SHA-1, empty `ninja changes`,
source extent audit (5,784 linked sources / 6,757 data/BSS sections), and all
66 tests pass. Generated matched data is 955,181 / 1,030,936 bytes (92.6518%);
matched code remains 1,920,872 / 2,607,776 bytes.

Manifests, identity-checked relocation evidence, original source backups and
integration snapshots are preserved in
`scratch/remaining_method_data_scout_20261020_parallel/`.
