# World handle loader — private near-match

The 3,064-byte loader at `801E8E2C..801E9A24` remains original and uncredited.
Its current private reconstruction is
`scratch/game_world_handle_loader/near4.cpp`. It has the original size;
after applying actual relocations, only four instructions differ: the
order of loading the requested and previous sizes for the two fixed
handle arrays. No instruction bytes or relocations are masked or patched.

The loader first invokes Root loading, reads the requested entry-pool
size, and optionally calls the now-matching pool resize at `801E9A24`.
It then sizes and loads dynamic two-layer handle arrays at `C`, `24` and
`18`, loads the handle at `30`, and loads three index structures. It also
sizes and loads the one-layer handles at `C100`, five-layer fixed arrays
at `C110` and `C140`, three-layer dynamic handles at `C134`, and the final
handles at `C164` and `C168`. Native default construction and destruction
establish these inheritance depths. The `C100` loop uses the member count;
the other loader loops use the count read from the stream.

A fixed-array index initialized from its current size, followed by a
comparison against the member count, reproduces all registers, branches,
constructor/destructor calls and loop increments. The two load-order pairs
remain unresolved. Shared outer loop indices are needed for the original
zero initialization reuse. Ordinary source variants, diagnostic disassembly
and actual-relocation comparisons are preserved in the same scratch folder.
The loader has not undergone production ownership acceptance and must stay
NonMatching until all bytes and allocations have been verified.
