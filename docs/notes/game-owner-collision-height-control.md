# Owner collision-height control

The isolated ordinary source for original GLOBAL C entry `fn_801BDCAC` is exact
at `801BDCAC..801BDEF8`:588 text bytes and eight actual ELF relocations. It is
pending root integration and whole-game acceptance. There is no source credit
before that checkpoint.

The routine copies an input position, asks virtual slot6C for a radius, raises
the copied Y coordinate, and casts a downward ray of that radius through
`fn_80269230`. A hit dispatches virtual slot5C with the result, original input
position and index. On a miss, flag bit49 enables a second ray toward the
virtual slot70 height plus radius. Its length is the absolute Y difference.
A successful second ray updates slot74 with the result's Y displacement;
a miss clears bit49 through slotE0 and sets slot74 to zero. SlotE4 performs the
flag query. All flag arguments retain the genuine64-bit calling convention.

The new source and header preserve the original C entry identity. The virtual
owner is an honest partial class view with eight bytes before vptr08. The
32-byte ray and aligned result view retain unknown fields; this does not claim
the complete original classes or translation unit. The three original GLOBAL
SDA floats remain borrowed: `lbl_8037A2F0` is the threshold near1e-6,
`lbl_8037A2F8` is zero, and `lbl_8037A2FC` is minus one. Their original symbols,
payloads and external consumers remain unchanged, with no data credit.

GC1.3.2 with Gekko, O4,p, exceptions off and FP contraction on emits the exact
frameE0 and all scalar saves/restores. Reusing the local distance variable for
the height and then absolute ray length naturally closes the last seven FPR
operand words. Declaring distance before a separate target local independently
produces the same exact result. Reusing the existing position copy for the
second ray removes an extra Vec3 temporary and its twelve store bytes. No
assembly, forced registers, payload patch, alias, relabel or core change is
needed.

The complete original table census scans3144 exception-index slots including
descriptors and trailing padding, plus24 constructors and8 destructors. None
references this function range. The compiler emits only one text allocation,
no helper, vtable, literal, BSS or exception allocation, eight allocated
relocations and one nonallocated compiler-category relocation.

The original/current union consumer census covers10,428 inputs,204,101
allocated actual relocations and501,416 initialized original data positions.
All34 function entry references are original zero-addend absolute data
pointers, and all13 references to the three borrowed constants are named
zero-addend SDA relocations. There are no calls or interior function pointers.
The34 initialized entry pointers agree with the actual data relocations.
The separate current-only diagnostic is preserved. Fresh production compiles
are identical, ten adverse strict/allocation/dependency cases reject, and an
actual private MWLD link verifies all588 retained bytes and eight resolved
relocations using the original borrowed SDA input. The private link establishes
retention and targets; full original SDA placement and both whole-game ELFs
remain the root acceptance requirement.

All frozen evidence is under
`scratch/engine_collision_control_20261011ky`. Root owns registration,
configuration, splits, symbols, promotion, full DOL hash, regression checks and
progress. Accepted neighbors and previous near-match artifacts are unchanged.
