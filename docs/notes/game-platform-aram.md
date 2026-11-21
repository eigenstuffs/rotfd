# Platform ARAM requests and cursors

Nine partial source units reconstruct **1,836 code bytes in eight functions** and
**4,608 BSS bytes**. The original class/file names are unknown; source names
and field names describe verified behavior or offsets.

| Source / entry | Native range | Bytes |
| --- | --- | ---: |
| `platform_aram_flush.cpp`: `fn_8028531C` | `8028531C..8028533C` | 32 |
| `platform_aram_transfer.cpp`: `fn_8028533C` | `8028533C..80285458` | 284 |
| `platform_aram_acquire.cpp`: `fn_80285458` | `80285458..80285730` | 728 |
| `platform_aram_reset.cpp`: `fn_80285730` | `80285730..80285784` | 84 |
| `platform_aram_cursors.cpp`: `fn_80285784` | `80285784..80285800` | 124 |
| `platform_aram_cursors.cpp`: `fn_80285800` | `80285800..8028581C` | 28 |
| `platform_aram_init.cpp`: `fn_8028581C` | `8028581C..802859A8` | 396 |
| `platform_aram_transfer_complete.cpp`: `fn_80285A6C` | `80285A6C..80285B0C` | 160 |
| `platform_aram_requests.cpp`: request bank | `8035D528..8035DE28` | 2,304 |
| `platform_aram_dma_requests.cpp`: secondary bank | `8035DE58..8035E758` | 2,304 |

Token acquisition searches for a vacant bit, increments the used count and
stores the supplied byte. When no vacancy exists, it grows byte storage by
256 entries as needed, appends the byte, expands the bitset and sets the new
slot's bit before incrementing the limit. Reused slots also receive the byte.
The reset helper clears the owner's pointer at `8`, resets the offset-4 cursor
to `ARGetBaseAddress() + 0x8000`, resets offset `0` to the base plus `0xBB8000`,
and returns that cursor. Both routines match every byte without owned data.
The bitset's private view is 16 bytes at pool offset `C`; a saved local pointer
would add a register and change the generated code, so each operation obtains
the view from the owner at its use site.

The flush wrapper calls the existing matching SDK `ARQFlushQueue`. The cursor
helpers round the requested size up to 32 bytes, advance independent unsigned
cursors at offsets `0` and `4`, and return the previous cursor. The offset-4
helper reports exhaustion when its updated cursor reaches or exceeds
`ARGetBaseAddress() + 0xBB8000`. Its message and reporter remain borrowed from
original data at `802AF3E8` and global offset `110`.

Each bank contains 64 entries with stride 36 and an occupied flag at `20`.
The first bank's 32-byte request prefix is confirmed by `ARQPostRequest` and
its completion callback, and agrees with the already matching SDK's request
layout. The matching initialization routine clears 64 flags in the secondary bank; its
association with the same slot layout is inferred from that stride and extent.
No secondary-bank transfer consumer has yet been established.

Submission scans the first bank for an unoccupied request, marks it occupied,
acquires a byte-pool token, and posts a high-priority MRAM-to-ARAM request with
length rounded down to a multiple of eight. When the asynchronous argument is
zero, it polls the acquired token's occupancy bit. Completion reads the
request's owner field, clears that token if occupied, decrements the pool's
used count, and clears the matching request-bank flag. The reconstructed code
preserves the observed argument values and bounds behavior.

`include/Game/platform_aram_internal.h` shares the request, cursor and token
pool views. The pool has byte storage at `0/4/8`, bitset words at `C/10/14`,
pending bit count at `18`, limit at `1C`, and used count at `20`. Returning an
integer from its bounds-checked occupancy helper and narrowing at the caller
reproduces the single native signed-byte test. The completion helper's
reference-based word accessor and signed-byte test reproduce the native
boolean conversion and second word load before clearing the bit.

Initialization calls `ARInit` and `ARQInit`, clears the secondary bank's flags,
sets both cursors to the ARAM base address, allocates and clears a 4,096-byte
buffer, submits its DMA transfer, flushes the queue and frees the buffer. It
then advances the cursors by `0xBB8000` and `0x8000` and reports initialization
through the existing reporter. Source-file, allocation-site and report strings
remain original; their native offsets are applied without relocation masking.

GC/1.3.2 with the recorded standard optimized flags produces exact retained
code after all **75 actual relocations**. Both banks emit only zero-initialized
NOBITS sections of 2,304 bytes, aligned to eight, with one strong array symbol
each. No helper, constructor, alignment tail or unrelated data is credited.
The four bytes at `8035D524..8035D528` remain original alignment storage. An
explicit symbol and NonMatching original-padding split preserve those bytes in
the native report's denominator; neither is counted as reconstructed source.
The token pool at `8035DE34`, its registration record at `8035DE28`, startup,
owner initialization and destructor now also match. The shared pool declaration
now contains its actual storage base and bitset member; earlier code and data
remain byte-identical. See [lifetime and constructor recovery](game-platform-aram-lifetime.md)
for current ownership and full reproof evidence. These partial splits do not
establish a complete original translation unit.

Reproduce the strict proofs with
`python3 scratch/game_platform_aram/verify.py --production` and
`python3 scratch/game_platform_aram/verify_bss.py --production`. Full build,
linked-byte, source extent, source assembly, progress, baseline preservation
and tooling-test evidence is recorded in `scratch/platform_aram_checkpoint.json`.
