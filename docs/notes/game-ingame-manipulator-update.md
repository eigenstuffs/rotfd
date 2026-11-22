# InGameObjectsManipulator rotation update

Current InGame interface verification is recorded in [the native interface note](game-ingame-manipulator-interface.md); its five production objects and newly owned 76-byte table pass the full DOL and native objdiff checks. Earlier isolated proofs below preserve their original source views.


`src/Game/ingame_manipulator_update.cpp` reproduces `fn_80212674`, the original
**384-byte** routine at `0x80212674..0x802127F4`. The isolated proof passes all
19 actual ELF relocations and every allocated output byte: 384 code bytes,
20 initialized constant bytes, and five zero-initialized static bytes. Full-DOL
byte equality, the original SHA-1, and complete native objdiff code/data
matching pass; the 25 data/BSS bytes are integrated with the routine.

The runtime identity is `InGameObjectsManipulator`, registered as a child of
`Manipulator` in `src/Game/type_registry.cpp`. Its registered factory
`fn_80209380` allocates `0x24` bytes, reports
`InGameObjectsManipulator_Z.h:35`, and calls the constructor at `0x802128A0`.
This identifies the native working class
`InGameObjectsManipulator_802128A0` (33 characters). `ManipulatorDraw` is a
separate registered class. The constructor, destructor, assignment and borrowed
handle getter are separate source units; this update claims no virtual table.

The method first performs native initialization of a function-local static
`float phase = 0.0f`. This happens before checking the object's handle. The
phase is shared by calls to this function, rather than stored in each object.
The handle at object offset `0x20` is checked using `fn_801F7EB8`, then resolved
again through the manager at global offset `0x118`. The resolved object's handle
at `0x44` identifies the final transform. Both inline resolutions compare signed
generation bytes against a signed 8-bit generation and signed 24-bit index in
the four-byte handle; records have stride 16. The original does not add a null
check between the repeated first resolution and reading its related handle.

When the final transform resolves, the method writes an axis-angle quaternion
for the Y axis into its floats at `0xC8..0xD4`. Calls at `0x8028506C` and
`0x80284FA8` supply the cosine and sine of half the phase. The phase then gains
`2*pi*delta/6`. It subtracts `2*pi` once only when the result is strictly greater
than `2*pi`; it neither loops nor applies a modulo operation. An unresolved
final handle leaves the phase unchanged after its initial setup.

The private header contains observed layout views, not a claim that all original
class declarations have been recovered. Its const related-manager view retains
the second table load. A named first resolved object keeps that load at its
original use; nesting both resolutions in one expression hoists the load too
early. The inline axis-angle helper preserves the original zero/one axis
multiplications, and `angle / 2.0f` preserves the original half-angle multiply
operand order. Compiler-generated paired-single save/restore instructions and
the local static initialization guard arise from ordinary C++.

| Emitted section | Original range | Bytes | Natural alignment | Objects |
| --- | --- | ---: | ---: | --- |
| `.text` | `0x80212674..0x802127F4` | 384 | 4 | one strong function |
| `.sbss` | `0x80378008..0x8037800D` | 5 | 8 | local `phase$10` (4), `init$11` (1) |
| `.sdata2` | `0x8037AC38..0x8037AC4C` | 20 | 8 | local `@35..@39`, four bytes each |

The five floats are positive zero, one half, one, the exact `0x40C90FDB` float
encoding of `2*pi`, and six. Their original section start satisfies the emitted
alignment of eight. The coarse original `lbl_8037AC48` extent was eight bytes; integration
narrows it to the emitted four-byte last constant. Its following four zero bytes at
`0x8037AC4C..0x8037AC50` remain original padding. Likewise the three bytes at
`0x8037800D..0x80378010` following the compiler's one-byte guard remain original
BSS padding. Neither tail receives source credit. There is no internal emitted
padding, weak function, excluded helper body or other allocated section.

`scratch/game_ingame_manipulator_update/ownership.json` records an independent
scan of 4,074 configured original target objects. All 14 relocations into these
two data windows belong to this function, and a separate scan of every original
DOL text section finds the same 14 direct r2/r13 SDA instructions. Neither tail
has a consumer. There are no missing target objects or ambiguous section bases;
the 42 unrelated unresolved linker/runtime names are retained in the report as
a limitation of the relocation inventory. The vtable at `0x802EB180` and all
neighboring data remain external.

The historical command `python3 scratch/game_ingame_manipulator_update/verify.py` produced the strict
proof and `python3 scratch/game_ingame_manipulator_update/inspect_ownership.py`
for the consumer inventory. The compiler is `GC/1.3.2`, using Gekko hardware
floating point, `-O4,p -inline auto -Cpp_exceptions off -use_lmw_stmw on`.
The verifier checks the protected original DOL SHA-1
`5da8295a79bf297ab62c620e6ac66210be1c6ef5`, applies every actual retained ELF
relocation, compares complete allocated sections, checks symbol bindings and
natural alignment, and records source/header/object hashes. BSS is checked
against the original DOL's zero-initialized BSS range. No opcode masks,
binary patches, hand-written assembly or fabricated storage are used.

The original assembly snapshot is
`scratch/game_ingame_manipulator_update/original_update.s`, copied from the
then-current `build/GSQE78/asm/auto_03_8021266C_text.s` before this routine is
split into its source target. Earlier 368/380-byte probes and the 384-byte
hoisted-load near result remain in the same scratch directory. The candidate
manifest is `config/GSQE78/candidates/game-ingame-manipulator-update.json`.

Integration evidence is `scratch/manipulator_checkpoint_full_build.log`;
The two original tails it once recorded in
`config/GSQE78/ingame_manipulator_update_padding.json` are now ordinary
linker alignment padding (no split or manifest).

For current source, use `python3 scratch/game_ingame_manipulator_interface/verify.py --production`; the original command above applies to the preserved pre-interface snapshot.
