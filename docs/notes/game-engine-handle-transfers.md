# Engine retained handle copies and child transfers

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Frozen isolated handoff: three ordinary C++ routines, 864 retained text bytes, zero data bytes, and 26 actual retained relocations. Existing external names are preserved. GC/1.3.2 uses the ordinary hardware Gekko optimization flags with exceptions off; `fn_801CBC64` additionally uses `-use_lmw_stmw on`.

| Function | Retained range | Bytes | Actual relocations |
| --- | --- | ---: | ---: |
| `fn_801C97B8` | 0x801C97B8..0x801C9878 | 192 | 11 |
| `fn_801CA1E8` | 0x801CA1E8..0x801CA308 | 288 | 7 |
| `fn_801CBC64` | 0x801CBC64..0x801CBDE4 | 384 | 8 |

`fn_801C97B8` copies the owner's +4 handle into a retained native temporary, copies that value into a second retained temporary, destroys the first, and dispatches the second through `fn_8023A6D8` on the global +0x120 service. Ordinary nontrivial C++ temporaries reproduce the exact native constructor, zero initialization, retain and destructor sequence. A named reference to the source handle preserves the original adjusted member pointer across construction.

`fn_801CA1E8` resolves the handles at +0x20 and +0x1C through the generation-checked registry view, calls virtual slot +0x20 on the first resolved child when present, then assigns a default handle from the global +0x14C object's +0x28C field if the owner's +0x24 handle has no resolved object. The assignment releases, copies, and retains in the observed order.

`fn_801CBC64` resolves the owner's +0x104 handle, assigns the child's +0x28 handle into the target's +0x28 field, copies the child's +0x24 handle into owner +0x108, then copies that into +0x10C. It resolves +0x108 again, copies six cached floats from child +0x90..+0xA4 into owner +0xDC..+0xF0, and dispatches the child's +0x84 vector through virtual slot +0x34 on the embedded owner +0x4C interface. Named references to the two source handles reproduce the original pointer lifetimes and five saved registers. Private declarations specify only observed layouts and calls.

The temporary-copy object emits four trailing unreferenced weak destructors: `Second_801C97B8` 92 bytes at offset 192, `First_801C97B8` 92 bytes at offset 284, `Layer_801C97B8` 88 bytes at offset 376, and `Native_801C97B8` 84 bytes at offset 464. Their exact mangled names, weak bindings, raw SHA256 and eight actual unused relocations are frozen in the manifest. These 356 bytes receive no source credit; central acceptance requires every weak symbol to be absent from the final ELF. The other two objects emit no extra functions.

`final_integration.json` under `scratch/game_engine_handle_transfers_continuation` freezes source SHA256, empty recursive quoted-header inventories, all retained and unused symbol extents, every allocated section and actual relocation. Proposed central split/config edits and `ownership_audit.json` are siblings. Strict production recompile through `verify.py` passes all 1,220 emitted text bytes. No data, BSS or padding is emitted; full original extabindex, constructor and destructor table audits find no owned records. Other original text remains assembly: 0x801C9FA4..0x801CA1E8 and 0x801CA308..0x801CA30C, plus 0x801CBDE4..0x801CC4F0. Parent final DOL and regression acceptance remain required. No assembly or relocation masking was used.
