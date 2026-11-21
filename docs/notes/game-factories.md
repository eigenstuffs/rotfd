# Game object factories

Nine bounded source fragments reconstruct 111 allocation-and-construction
factories, totaling 9,768 code bytes and 2,220 bytes of compiler-generated
exception metadata. Each function requests an allocation, calls its constructor
when allocation succeeds, and returns the resulting pointer. The source uses
ordinary C++ calls and null checks. It contains no assembly or encoded
instruction bodies.

| Source fragment | Text range | Functions | Code bytes |
| --- | --- | ---: | ---: |
| `factories_8007E160.cpp` | `8007E160..8007EE70` | 38 | 3,344 |
| `factories_800B9040.cpp` | `800B9040..800B9148` | 3 | 264 |
| `factories_800B9934.cpp` | `800B9934..800B99E4` | 2 | 176 |
| `factories_800B9FFC.cpp` | `800B9FFC..800BA8EC` | 26 | 2,288 |
| `factories_800BA9BC.cpp` | `800BA9BC..800BAC24` | 7 | 616 |
| `factories_800BADC4.cpp` | `800BADC4..800BAE1C` | 1 | 88 |
| `factories_800BB1C4.cpp` | `800BB1C4..800BBC6C` | 31 | 2,728 |
| `factories_800BBE74.cpp` | `800BBE74..800BBF24` | 2 | 176 |
| `factories_800BBF80.cpp` | `800BBF80..800BBFD8` | 1 | 88 |

These groups have contiguous text, exception-table and exception-index ranges.
They are provisional fragments, not claims that their boundaries recover full
original translation units. The diagnostic strings identify original headers
and source lines. For example, `fn_8007E8F0` allocates 1,000 bytes with the
`BlueJfishMove.h:30` diagnostic and calls `fn_80098470`. The original
`Anonymous New` label and the header strings remain external. The allocator,
constructors, class layouts, virtual tables and registration data are outside
these source fragments and earn no credit from this work.

GC/1.3.2 with `-proc gekko -fp hardware -enum int -str reuse -common off
-O4,p -inline auto -Cpp_exceptions on` reproduces all functions and their
exception records. Each function emits an eight-byte exception record and a
twelve-byte index entry. No exception-padding normalization is needed.

`scratch/factory/recover.py` records the bounded factory inventory and its
observed allocation size, alignment, header, line and constructor target.
`scratch/factory/verify.py` compiles every source, validates the complete ELF
section/function inventory, resolves all 1,110 relocations using the protected
image's symbol addresses, and compares all allocated bytes with the original
DOL. It does not infer a successful match from a masked instruction score.
The candidate manifests retain the per-function evidence. Full-DOL SHA-1,
direct binary equality and native objdiff are the integration checks.

## Engine registration fragments

The same C++ factory idiom also occurs in 45 engine registrations, totaling
3,960 code bytes in fourteen bounded fragments. These functions use
`-Cpp_exceptions off`, and the original exception index contains no entries
for them. They own no data. Their diagnostic header names include
`CameraEngineZone_Z.h` and `Agent_Z.h`; the original constructor and allocator
calls remain explicit external dependencies.

| Fragment start | Functions | Code bytes |
| --- | ---: | ---: |
| `80209328` | 2 | 176 |
| `80209554` | 8 | 704 |
| `80209910` | 4 | 352 |
| `8020A134` | 2 | 176 |
| `8020A324` | 1 | 88 |
| `8020A3E4` | 1 | 88 |
| `8020A5B0` | 1 | 88 |
| `8020A68C` | 1 | 88 |
| `8020A840` | 9 | 792 |
| `8020AC68` | 3 | 264 |
| `8020AE04` | 2 | 176 |
| `802612C8` | 1 | 88 |
| `80261388` | 9 | 792 |
| `802617A0` | 1 | 88 |

`scratch/factory/recover_late.py` records this inventory;
`scratch/factory/verify.py --late` separately compiles and verifies every
allocated byte and all 360 relocations. The combined factory reconstruction
contains 156 ordinary C++ functions and 13,728 code bytes. It does not include
the neighboring factories whose constructors or post-construction setup
require a different source form.

## Derived construction

An additional 49 factories allocate storage, call a base constructor, and
install the derived virtual-table pointer at offset eight. Their typed
`FactoryObject` view describes only that verified prefix and pointer. The
base constructor and virtual-table object stay external. This source form
reproduces 5,096 code bytes and 860 exception-metadata bytes in thirteen
fragments. Forty-three early game functions have exception records; six
engine functions do not. Their per-object compiler settings preserve that
distinction.

The fragments start at `800B94C8`, `800B96C4`, `800B99E4`, `800BA8EC`,
`800BAC24`, `800BAE1C`, `800BBC6C`, `801EB1EC`, `801EB764`, `8020A37C`,
`8020A43C`, `80261320` and `802616A0`. The manifest for each fragment lists
every factory, diagnostic header and line, allocation size, base constructor,
virtual table, and owned section extent.

`scratch/factory/recover_derived.py` records those observations and emits
ordinary calls and a typed pointer assignment. The strict verification mode
`scratch/factory/verify.py --derived` checks all emitted sections, function
sizes and 576 relocations against the protected original. Across all three
forms, the reconstruction now includes 205 factories, 18,824 code bytes and
3,080 exception-metadata bytes. These counts describe the verified source
fragments; they do not count the still-original constructor implementations
or class data.

The ten remaining plain engine factories in the earlier registration range
add 880 bytes. Five fragments start at `801EB254` (four functions),
`801EB4D8` (two), `801EB6B4` (two), `801EB7CC` (one) and `801EBA70` (one).
`recover_late.py --mid` and `verify.py --mid` record and verify this bounded
group, including all eighty relocations and the absence of exception records.
These common forms total **215 factory functions, 19,704 code bytes and
3,080 exception-metadata bytes**. Eight separately documented
[factories with explicit initialization](game-factory-specials.md) bring the
combined verified source to 223 functions, 20,660 code bytes and 3,100
exception-metadata bytes.
