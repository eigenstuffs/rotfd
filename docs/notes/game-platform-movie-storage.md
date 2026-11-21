# Movie thread and buffer storage

`src/Game/platform_movie_storage.c` owns the original zero-initialized object
at `8036E9D0..80373100`, exactly `4730` bytes (18,224 bytes). This data-only
split adds no code or functions. The original anchor, extent and eight-byte
alignment are preserved, so existing pooled references retain their addresses.

The original movie setup function establishes this physical layout:

| Offset | Storage | Evidence |
| --- | --- | --- |
| `0000` | Display OSThread, `318` bytes | OSCreateThread/OSResumeThread arguments |
| `0318` | Display stack, `2000` bytes | Stack high address `2318`, size `2000` |
| `2318` | DMA OSThread, `318` bytes | OSCreateThread/OSResumeThread arguments |
| `2630` | DMA stack, `2000` bytes | Stack high address `4630`, size `2000` |
| `4630` | Display-ready semaphore | OSInitSemaphore with initial count zero |
| `463C` | Display-available semaphore | OSInitSemaphore with initial count one |
| `4648` | DMA-ready semaphore | OSInitSemaphore with initial count zero |
| `4654` | DMA-available semaphore | OSInitSemaphore with initial count one |
| `4660` | Two `30`-byte buffer records | Memset of `60` bytes, `30`-byte copies and index modulo two |
| `46C0` | Unclassified `40` bytes | Original pool extent; interpretation remains unknown |
| `4700` | Decoder storage, `30` bytes | Decoder-call base and remaining original pool extent |

Offsets and sizes in the table are hexadecimal. The source reuses the already
recovered SDK OSThread and OSContext ABI. Each semaphore is a signed count plus
the eight-byte thread queue. Observed buffer/end fields at record offsets
`10/14` and `28/2C` are typed pointers; remaining record words retain offset
labels. Size and member-offset assertions are checked by the target compiler.

The last 112 bytes are explicitly opaque fields. Their zero initialization and
extent match; their original types, decoder class and internal behavior are
not claimed as recovered. The aggregate struct describes the verified memory
layout without asserting that the original TU declared one aggregate object.
Shared small-data flags and unfinished movie/decoder functions remain separate.

GC/1.3.2 emits exactly one global BSS object of 18,224 bytes, with no allocated
code, initialized data, extra symbols, helpers or relocations.
`scratch/game_movie_platform/verify_storage.py --production` verifies its
original BSS bounds and unchanged next object at `80373100`. The linked ELF,
full DOL, source extents, previous matches/source/header hashes, immutable
baseline and all 23 tests pass. The native data denominator remains 1,030,936;
the partial split adds two provisional build units. See
`scratch/platform_movie_storage_checkpoint.json` for acceptance evidence.
