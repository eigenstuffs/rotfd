# MSL/string.c

The complete linked MSL string unit is reconstructed in `src/MSL/string.c`. All 908 instruction bytes match the original at `0x80128288–0x80128614`. There are no allocated data sections, alignment bytes, or relocations in this unit.

| Function | Address | Bytes |
| --- | --- | ---: |
| strstr | `0x80128288` | 104 |
| strrchr | `0x801282F0` | 72 |
| strchr | `0x80128338` | 48 |
| strncmp | `0x80128368` | 64 |
| strcmp | `0x801283A8` | 296 |
| strcat | `0x801284D0` | 44 |
| strncpy | `0x801284FC` | 68 |
| strcpy | `0x80128540` | 184 |
| strlen | `0x801285F8` | 28 |

`strncmp` was previously unnamed. The preceding `strerror` and following `atof` belong to separate units.

The candidate uses GC/1.3 with `-O4,p` and `-inline deferred`; the complete flags are in `config/GSQE78/candidates/msl-string.json`. GC/1.3.2 and GC/2.0 produce the same exact bytes. GC/1.3 also matches the neighboring memory routines, supporting this shared runtime configuration. GC/1.2.5 and explicit speed optimization produce different instructions, so these results establish compatible compiler settings without uniquely identifying the original compiler revision. The original optimized word-copy and comparison behavior is retained. Constant word masks compile into instructions and own no data.

The implementations draw on the community reconstructions in [Melee](https://github.com/doldecomp/melee/blob/ae5898ee0dfda41b34fdf846f7d680a33e14779d/src/MSL/string.c) and [SMS](https://github.com/doldecomp/sms/blob/c44637d42e09ec81973c4579e13ece8d0b0f5f58/src/PowerPC_EABI_Support/Msl/MSL_C/MSL_Common/string.c). Unmodified reference files, pinned revisions, and available license information are retained in `reference/melee-msl/` and `reference/sms-msl/`. These are decompilation references, not official SDK sources.

Reproduce the proof from the repository root:

```sh
python3 scratch/msl_string/verify.py
```

The verifier recompiles the source, asserts that `.text` is the sole allocated section, and compares every instruction byte against the DOL with SHA-1 `5da8295a79bf297ab62c620e6ac66210be1c6ef5`. No instruction bits are masked. Full-DOL integration passes the original SHA-1 and native objdiff checks; project totals are reported in [PROGRESS.md](../../PROGRESS.md).
