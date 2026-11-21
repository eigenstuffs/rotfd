# Resolved resource float setters

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Eight independent source units recover float member assignments through the query's virtual handle getter at table offset `0x28`. The generation-tagged handle resolver matches the manager at context offset `0x118`, sixteen-byte entries and signed generation byte at entry offset `0xC`.

| Source suffix | Function/text range | Member | extab | extabindex |
| --- | --- | --- | --- | --- |
| `8006bcc8` | `8006BCC8..8006BD50` (136) | `0x3B8` | `8000C178..8000C180` | `80018E34..80018E40` |
| `8006bd50` | `8006BD50..8006BDD8` (136) | `0x3BC` | `8000C180..8000C188` | `80018E40..80018E4C` |
| `8006bdd8` | `8006BDD8..8006BE60` (136) | `0x3C0` | `8000C188..8000C190` | `80018E4C..80018E58` |
| `8006be60` | `8006BE60..8006BEE8` (136) | `0x36C` | `8000C190..8000C198` | `80018E58..80018E64` |
| `8006bee8` | `8006BEE8..8006BF70` (136) | `0x3B0` | `8000C198..8000C1A0` | `80018E64..80018E70` |
| `8006bf70` | `8006BF70..8006BFF8` (136) | `0x3B4` | `8000C1A0..8000C1A8` | `80018E70..80018E7C` |
| `8006c88c` | `8006C88C..8006C910` (132) | `0x3E0` | `8000C21C..8000C224` | `80018EF4..80018F00` |
| `8006c910` | `8006C910..8006C994` (132) | `0x3E4` | `8000C224..8000C22C` | `80018F00..80018F0C` |

Production paths are `src/Game/resource_float_SUFFIX.cpp`. The first six return signed byte one; the last two return void, preserving existing Python callers' declared behavior. Each routine keeps its input in nonvolatile floating register 31 across the virtual call. Their original exception records describe exactly that saved floating register.

The new frozen `include/Game/resource_float_update_views.h` declares the generation resolver, query and owner member layouts. All eight consumers are verified. GC 1.3.2 uses standard optimization and Object extra `['-Cpp_exceptions on']`.

The per-function strict verifiers under `scratch/game_resource_float_updates/` prove all 1,240 allocated bytes: 1,080 text and 160 exception/index bytes. Each source emits only its one function, eight extab bytes and twelve extabindex bytes. Actual ELF symbol names, sixteen actual text relocations, sixteen owned EH-index relocations and eight nonallocated metadata relocations are audited. Full original DOL SHA1 and full exception/constructor/destructor table ownership checks pass. No weak helper, literal, BSS, padding or intervening range is claimed. Manifest list: `scratch/game_resource_float_updates/manifest-list.json`.
