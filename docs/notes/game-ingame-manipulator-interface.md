# InGameObjectsManipulator native interface

Status: integrated and verified in the full byte-identical DOL. Five native source objects preserve all six recovered functions (780 code bytes) and the update method's existing 25 bytes of constants and static state. The destructor now owns the actual 76-byte virtual table at `0x802EB180..0x802EB1CC`, adding 76 data bytes with no duplicate code, function or source-unit credit.

The runtime registry, the accepted factory's `InGameObjectsManipulator_Z.h:35` diagnostic, and its native constructor support the runtime class identity **InGameObjectsManipulator**, derived from **Manipulator**. The address-qualified C++ spelling remains a working name. The private native interface inherits the already integrated Root / Activable / Manipulator declarations through `manipulator_callbacks_internal.h`, and adds the existing four-layer handle at offset `0x20`; the complete object remains `0x24` bytes.

| Table offset | Original address | Recovered interface |
| --- | --- | --- |
| `00`, `04` | zero | Native RTTI-disabled table prefix |
| `08` | `802127F4` | InGame destructor |
| `0C` | `802072A0` | Root `slot0C(unsigned long)` |
| `10`, `14` | `80023950`, `80023954` | Root empty hooks |
| `18` | `80213B68` | Activable list append |
| `1C` | `80207354` | Root signed-byte query |
| `20`, `24`, `28` | `8002810C`, `80028110`, `80028114` | Activable hooks |
| `2C` | `80213E84` | Manipulator accumulation and virtual update |
| `30`, `34` | `80028108`, `80213E58` | Manipulator empty hooks |
| `38` | `80212674` | InGame update override taking a float |
| `3C` | `80213E5C` | Manipulator reset and activation |
| `40` | `802125F8` | Assign the owned handle |
| `44` | `80212664` | Return a borrowed pointer to the handle |
| `48` | `8021266C` | Return the observed zero word |

Metrowerks generates this strong native table from the ordinary virtual declarations and empty derived destructor. It is exactly 76 bytes with natural alignment 8, including 17 real pointer relocations. The four original zero bytes at `0x802EB1CC..0x802EB1D0` remain separate fallback padding with no source credit. There is no invented `slot4C`. The following Activable table starts at `0x802EB1D0`.

The native methods retain the accepted behavior. Assignment releases the old handle before copying the incoming token and retaining it; it introduces no self-assignment check. The borrowed getter only computes `this + 0x20`; its private `const` spelling follows the accepted read-only ABI view, but these eight bytes cannot establish the original C++ qualifier or pointer-versus-reference spelling. Similarly, the zero query uses `unsigned long` to express the observed word result without claiming the original declared result type. All slot names remain descriptive address/offset-based working names.

The update method still checks the handle through the pointer-shaped native lookup, then performs two generation-checked lookups and writes a Y-axis quaternion from the shared phase. It preserves the first lookup through the declared manager entry type and the second through the separate const related-object view. Casting both manager accesses through new views incorrectly coalesced the table reload and shortened the function to 380 bytes; retaining the established type boundary restores all 384 original bytes. The native declaration changes only compiler-local names: `phase$23` / `init$24` replace `phase$10` / `init$11`, and `@48..@52` replace `@35..@39`. Their addresses, five constant words, four-byte phase, one-byte guard, and natural alignments remain unchanged.

| Integrated source | Retained code | Actual retained relocations | Retained data |
| --- | ---: | ---: | ---: |
| Destructor | 172 | 26 (9 code, 17 table) | 76-byte native table |
| Constructor | 100 | 4 | 0 |
| Handle assignment and getter | 116 | 4 | 0 |
| Zero query | 8 | 0 | 0 |
| Update | 384 | 19 | 20 initialized bytes and 5 BSS bytes |
| Total | 780 | 53 | 101 bytes, of which 76 are newly reconstructed |

The common native header causes the constructor to emit five **unreferenced weak** destructor bodies after its 100 retained bytes. The four handle wrappers retain their earlier 96 / 92 / 88 / 84-byte extents (360 bytes, eight relocations). An additional weak upper destructor occupies object offset `0x1CC..0x234` (104 bytes, six relocations). It is an ordinary `-O4,p`, exceptions-off emission of the inline upper destructor, not a match for the accepted 124-byte strong destructor compiled under that function's original settings. No retained code or data references any of these weak bodies; no exception metadata is emitted in this constructor object. All 464 bytes and 14 relocations are enumerated and excluded from source credit. The existing linked strong upper destructor at `0x8002798C` remains authoritative. The final-link checker requires its single strong 124-byte identity and the unchanged original DOL.

All five objects use GC/1.3.2, `-O4,p -inline auto -Cpp_exceptions off -RTTI off`, plus the existing Gekko settings. The production build includes the two new internal headers from `src/Game`, and the production verifier hashes them and the two accepted inherited headers. The update's original external tails (`0x8037800D..0x80378010`, three BSS bytes; `0x8037AC4C..0x8037AC50`, four constant-section bytes) also remain uncredited.

Evidence is under `scratch/game_ingame_manipulator_interface/`: `inventory.json`, the five `candidate_*.json` files, per-object real relocation inventories, `verify.py`, `current_strong_owner.json`, `proposed_source.patch`, and `patch_files.json`. `before/` preserves the accepted source/header views. The verifier compiles ordinary C++, applies every retained ELF relocation, compares all retained allocated bytes directly with the untouched original DOL, checks function identities and natural section alignments, and accounts for every unlinked weak body. `verify.py --production` passes all five source objects. `verify_link.py` and `linked_proof.json` confirm all six final function identities, the 76-byte native table, the single strong 124-byte upper destructor and the unchanged original DOL. `config/GSQE78/ingame_manipulator_table_padding.json` records the uncredited four-byte table tail.
