# Flag query, angle correction, frame update and name pools

Ten source units pass the standard matching build. This continuation adds
1,024 code bytes across three functions and 22,188 initialized data bytes.
The original code, function and data denominators remain unchanged.

| Source | Original range | Code bytes | Data bytes |
| --- | --- | ---: | ---: |
| `Game/object_flag_mask_query_800280B4.cpp` | `800280B4..800280E8` | 52 | 0 |
| `Game/angle_wrap_80075854.cpp` | `80075854..800758B0` | 92 | 0 |
| `Game/engine_frame_update_tick_8020c248.cpp` | `8020C248..8020C5B8`, `8037AA78..8037AA80` | 880 | 8 |
| `Game/python_binding_method_names_802A5C38.cpp` | `802A5C38..802A880F` | 0 | 11,223 |
| `Game/factory_header_names_802AE088.cpp` | `802AE088..802AE327` | 0 | 671 |
| `Game/script_type_event_names_802A8810.cpp` | `802A8810..802AAE1B` | 0 | 9,739 |
| `Game/script_type_event_names_802AAE20.cpp` | `802AAE20..802AAF3A` | 0 | 282 |
| `Game/script_type_event_names_802AAF40.cpp` | `802AAF40..802AAFA2` | 0 | 98 |
| `Game/script_type_event_names_802AAFA8.cpp` | `802AAFA8..802AB042` | 0 | 154 |
| `Game/script_type_event_names_802AB048.cpp` | `802AB048..802AB055` | 0 | 13 |

The flag query tests the inherited 64-bit field at offset `0x30` against its
64-bit argument. Ordinary C++ with CodeWarrior `GC/1.2.5n`, `-O4,p` produces
all 52 original bytes, with no relocations or owned data. The default Game
compiler instead selects a different branchless result sequence. The existing
neighboring flag setters/getter are unchanged.

The angle helper applies three bounded corrections using the existing 360,
zero and 180 constants. It is not a general modulo operation for arbitrary
multi-revolution inputs. Saving the initial angle in a local reproduces the
original floating register allocation with the default `GC/1.3.2` Game flags.
Its five actual SDA references resolve to `lbl_80378998`, `lbl_8037899C` and
`lbl_803789A0`; those constants keep their original owners. The adjacent two
C++ adjustment thunks remain original code.

The frame-update function and both name pools were preserved, unregistered
source candidates before this continuation. Their source files are unchanged.
The frame update retains its lazy clock initialization, pause checks, service
update order, renderer calls and optional timing/counter text. Its eight-byte
integer-conversion literal is emitted by the compiler. The name pools contain
420 ordinary character-array definitions, including their compiler-emitted
internal alignment. The two final one-byte boundaries at `802A880F` and
`802AE327` have separate original-padding owners and receive no source credit.
The original type descriptors, method tables, shared context and clocks remain
outside these partial source splits.

The three preserved candidates' narrow configure/symbol/split changes come
from `scratch/world_python_factory_frame_three_20261011/private_v2/`.
Their source SHA256 values were verified before adoption. The changes were
applied as contextual deltas, preserving the two new functions and every
unrelated existing edit. The original frozen preparation is unchanged;
this continuation's build receipts are separate from its historical proof
packages.

The five additional script-name units reconstruct 562 NUL-terminated ASCII
strings: binding type names, message identifiers, animation identifiers and
class/diagnostic names. Every string is a separate ordinary exported character
array at its original address. The source uses the default Game compiler and
flags. Original symbol sizes, contents, interior NUL absence and the compiler's
natural four-byte inter-array spacing were checked before compilation.
Five larger gaps delimit the source units; their 26 bytes remain original-owned.
The first full link displaced later allocations when those boundaries were
unnamed. Explicit original-only GLOBAL byte-aligned boundary labels restored
the original placements without changing any source or padding payload. The
failed link log remains in `scratch/continuation_20261012/build-script-names.log`;
the accepted rebuild is `build-script-boundaries.log` in the same directory.
Each complete `.rodata` section compares at 100% in objdiff. Together with the
prepared pools this continuation owns 982 character arrays. No pointer table,
Python bytecode or extracted script contributes to this data credit.

## Verification

Each unit was first registered NonMatching and compiled for objdiff. Its whole
owned code/data sections compared at 100% before promotion. Full production
linking then passed the original DOL SHA1
`5da8295a79bf297ab62c620e6ac66210be1c6ef5`.

- `ninja baseline` was run before source changes; that baseline remains intact.
- `ninja` passes the original hash and regenerates the native report/progress.
- `ninja changes` reports no match regressions.
- The allocated source-extent audit and `tools/progress.py --check` pass.
- The native ELF audit verifies all three original function addresses/sizes,
  all 982 GLOBAL character arrays, the conversion literal and the five new
  padding symbols against the original executable bytes.
- `python3 -m unittest discover -s tests -v`: all 47 tests pass.

The final snapshot is 1,857,172 / 2,607,776 matched code bytes (71.2166996%),
7,751 / 8,803 matched functions and 542,742 / 1,030,936 matched data bytes.
There are 4,784 completed build units out of 5,867 provisional units. These
partial splits do not establish complete original translation-unit boundaries.

New diagnostic probes for selected-record lookup, record-key search, scalar
packing and indexed-statistic access remain under
`scratch/continuation_20261012/`. Their unresolved instruction differences earn
no source credit. The documented shared-pool blockers for owner-route updates,
text-color conversion and callback selectors remain unresolved.

Reproducible allocation checks and the final acceptance receipt are retained
in `scratch/continuation_20261012/check_native_allocations.py`,
`native-allocation-proof.json` and `acceptance-final.json`.
