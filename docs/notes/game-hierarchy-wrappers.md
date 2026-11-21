# Hierarchy/group forwarding, entry actions and assignment

Nine partial source units recover 17 routines and 2,152 code bytes in the broader
Hierarchy engine region. GC/1.3.2 with `-O4,p -inline auto -Cpp_exceptions off
-use_lmw_stmw on` reproduces the retained code and all 42 retained relocations.
No source-owned data, exception records, vtable or RTTI is emitted.

| Source stem under `src/Game/` | Original range | Functions | Code bytes |
| --- | --- | ---: | ---: |
| `hierarchy_entry_actions.cpp` | `0x80201A14..0x80201C14` | 2 | 512 |
| `hierarchy_relative_action.cpp` | `0x80201F10..0x80201F94` | 1 | 132 |
| `hierarchy_entry_assignment.cpp` | `0x80201F94..0x802020AC` | 1 | 280 |
| `hierarchy_list_actions.cpp` | `0x802022FC..0x80202464` | 1 | 360 |
| `hierarchy_related_update.cpp` | `0x8020349C..0x80203510` | 1 | 116 |
| `hierarchy_command_modes.cpp` | `0x80204734..0x802047B8` | 3 | 132 |
| `hierarchy_mode_a.cpp` | `0x802062AC..0x802062F4` | 2 | 72 |
| `hierarchy_mode_b.cpp` | `0x802064DC..0x80206524` | 2 | 72 |
| `hierarchy_group_forward.cpp` | `0x80206E28..0x80207004` | 4 | 476 |

The related update checks the signed state at offset 0xE4, resolves the handle at
0x0C through the manager, and forwards the floating-point update argument. The
group wrappers use the existing group list at 0x14 (data pointer at 0x1C), resolve
the selected handle by its signed 24-bit index and signed 8-bit generation, then
forward the remaining arguments. They preserve the original unchecked index
behavior and the null result when generations differ. Existing callers and
callee instructions support the integer arguments and floating update value;
the final resource-name argument stays an opaque pointer until its exact type
is established.

The entry actions call virtual slots 0x30 or 0x34 on the primary list entry, then
call the same slot on the corresponding secondary entry if its handle is valid.
Their list offsets are 0x90 and 0xA8. The relative action subtracts the state at
0xE4 from the supplied index before selecting the primary entry. The list action
walks the count at 0xDC, performs the paired slot-0x30 calls, and invokes the
related-object helper after the loop.

The assignment method copies a retained handle from the hierarchy list at 0xB4
into the selected 0x4C-byte game record's handle at 0x14. It decrements the old
reference, copies the value, increments the new reference, forwards a scoped
copy of the hierarchy owner, then calls slot 0x34 on the primary entry. An inline
reference accessor for the game record preserves the original register lifetime;
a direct array expression changes seven register-encoding bytes. The native
scoped copy and destruction otherwise match exactly. Two unreferenced compiler
destructors (88 and 84 bytes, four relocations) are accounted for separately and
removed by ordinary dead stripping. They receive no progress credit, and the
strict verifier rejects any retained reference to those unlinked bodies.

The three command wrappers pass the observed identifier tuples
(0x45, 0x47, 0x47), (0x43, 0x47, 0x48), and (0x44, 0x47, 0x49). Two more pairs
select one or zero for their corresponding routines. These numeric identifiers
are retained without assigning unverified command names. All substantive callees
remain their original source or fallback owners; these partial splits do not
claim the surrounding translation unit.

The established `group_runtime_internal.h` layout was reused without edits.
Each candidate records its hash in addition to the source hash. The four strict
verifiers under `scratch/game_hierarchy_wrappers/` (`verify.py`,
`verify_actions.py`, `verify_list.py`, and `verify_assignment.py`) check the original hash, all
retained ELF bytes, every function's address/size and each resolved relocation.
The three wrapper/action verifiers check complete allocated output; the assignment verifier also
accounts for the exact unlinked weak tails. All nine units pass the full original DOL SHA-1, direct byte comparison and
complete native objdiff code/data matching after central integration.

The recovered `fn_80205F1C` now proves a signed-byte mode parameter and return
value. The two mode-A wrappers declare that exact signature and continue to
discard its return. Their arguments are the constants one and zero; fresh
compiles before and after the refinement produce identical complete object
bytes and SHA-256. All 72 wrapper bytes and both relocations are preserved.
The original callee's `extsb.` test supplies the parameter-width evidence.

The mode-B wrappers now likewise declare the recovered `fn_802062F4` signed-byte
return and shared-mode parameter. Fresh before/after compiles have identical
complete object bytes and SHA-256, preserving both 36-byte bodies and their two
relocations. The full DOL and all twelve wrapper functions remain exact.
