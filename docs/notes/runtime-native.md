# Native PowerPC runtime boundaries

The remaining `0x8011F460..0x8011FAC4` helper family is explicitly handwritten assembly in the [pinned Wind Waker `ptmf.c`](https://github.com/zeldaret/tww/blob/11d6aa597a6b6218a38eff2726c841a31f851a57/src/PowerPC_EABI_Support/Runtime/Src/ptmf.c) and [`runtime.c`](https://github.com/zeldaret/tww/blob/11d6aa597a6b6218a38eff2726c841a31f851a57/src/PowerPC_EABI_Support/Runtime/Src/runtime.c). The unchanged references and existing upstream license are preserved under `reference/tww-msl/`.

| Original range | Native routines |
| --- | --- |
| `0x8011F460..0x8011F4F4` | Member-function-pointer test, comparison, and dispatch |
| `0x8011F4F4..0x8011F550` | `__cvt_fp2unsigned` |
| `0x8011F550..0x8011F680` | Floating-point and general-register save/restore entry points |
| `0x8011F680..0x8011F9F8` | 64-bit divide, remainder, and shifts |
| `0x8011F9F8..0x8011FAC4` | `__cvt_dbl_usll` |
| `0x8011FB40..0x8011FD88` | Native exception context restore and throw entry |

The original unnamed 60-byte function at `0x8011F490` is `__ptmf_cmpr`; its six loads and three condition-register comparisons agree with the primary reference. The 1,636-byte arithmetic/member-pointer family and 584-byte exception entry family remain original assembly fallback. Recovering names or supplying C constant definitions does not add their code to matching-source counts. The existing initialization unit between these ranges remains separate and unchanged.

Two data-only source portions are now verified. `src/Runtime/ptmf.c` defines the original twelve-byte null member-function pointer at `0x802ABA18`; four zero alignment bytes follow under a separate NonMatching padding owner. `src/Runtime/runtime.c` defines the original 24-byte word array at `0x802ABA28`, encoding the double constants zero, 2³², and 2³¹ for the native conversion helper. The descriptive external symbol permits the separate original assembly object to reference this partial source unit.

Run `python3 scratch/runtime_ptmf/verify.py` and `python3 scratch/runtime_constants/verify.py` for whole-object checks. Both pass without relocations. Their manifests record zero code bytes and zero functions; only the owned constants contribute to data progress.

The two ordinary C++ `std::exception` methods in the audited interval are now
integrated with their owned class data, as documented in
[the exception note](runtime-exception.md). The rest of this audited native
family contains no overlooked ordinary C implementation in the pinned reference.
