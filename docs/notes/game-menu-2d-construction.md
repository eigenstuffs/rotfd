# Menu2D construction at 800B2CD0

The isolated ordinary C++ constructor matches all 364 original text bytes,
104 exception-table bytes and the 12-byte exception index. It is not yet
accepted in the full native target. The proposed source is
`src/Game/menu_2d_construct_800B2CD0.cpp`; frozen evidence is under
`scratch/game_menu_2d_construct_800b2cd0`.

The native identity is `Object_800B4F28`, already established by its accepted
destructor at 800B4F28. Both bodies install the original 88-byte table at
802BD858. The required identifier changes are `fn_800B2CD0` to
`__ct__15Object_800B4F28Fv` and `lbl_802BD858` to
`__vt__15Object_800B4F28`. The table stays with its original owner. No alias,
assembly thunk, manual hidden return argument or new data definition is used.
An earlier unadopted class-name proposal is preserved in `identity_v1`;
`established_class_identity_proof.json` proves identical allocated bytes and
normalized actual relocation targets after correcting that identity.

The accepted factory at 8007ECB8 allocates 0x1A4 bytes, with the original
`Menu2D.h` line-168 reference. The private construction view has a 0x4C-byte
MenuBase, Handle fields at 0x4C and 0x74, a dynamic record container at 0x68,
sixteen floats at 0x80, ten trivial 20-byte records at 0xC0, and a word at
0x188. Bytes 0x18C..0x1A4 remain opaque. The fixed array uses the original
`__construct_array` call and external empty record constructor at 800B2E3C;
that constructor receives no credit here. This fixed 20-byte array is
distinct from the dynamic container's separately established record layout.

The constructor calls the original MenuBase constructor with 0 and 255,
constructs its members, clears observed flags and inherited fields, assigns
a genuine default Handle temporary, and initializes the observed float
fields from the five existing external constants. Its source preserves the
native member destruction actions and temporary lifetime. The inline native
Handle delete declaration uses the already established allocator function.

GC/1.3.2, `-proc gekko -fp hardware -enum int -str reuse -common off -O4,s
-inline auto -Cpp_exceptions on -RTTI off -use_lmw_stmw on` emits 556 text,
152 extab and 36 index bytes. Exactly 364 text and 116 metadata bytes are
retained. The remaining 192 text and 72 metadata bytes are inventoried weak
backups and receive no credit. There are 26 retained actual relocations and
11 discarded actual relocations. The existing GLOBAL Handle destructor at
800723F4 is independently recompiled from its accepted canonical and source;
the unchanged strict weak-override inspector resolves the retained EH
references to that exact strong owner. An actual MWLD link proves all six
backup allocations discarded and rejects a wrong input-object basename.
The native source and original table placement still require root's full
target checks.

Four accepted source files require identifier-only changes: the 8007E160
factory unit, 800B4EDC vector setup, and the 800B4F28/800B5254 menu destructor
units. `consumer-proposal/proof.json` preserves complete before/after source,
canonical and object evidence for each. Both versions recompile strictly;
all allocated bytes, normalized symbols and resolved relocation targets are
identical. None of those accepted files has been changed by this handoff.

The full original extabindex table 80015F60..8001F2C0 identifies exactly the
owned 364-byte function and its 104-byte EH record. Complete constructor and
destructor table scans find no entry into this function. External table,
literal, global and destructor ownership remains outside this partial unit.
All earlier probe failures, the unadopted identity proposal and the initial
native SDA-input failure remain archived with the successful proof.
