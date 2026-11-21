# Six display-list buffers

Ordinary C++ reconstructs **892 code bytes and 41 actual relocations** at 802715C8..80271944. Production integration and original-DOL acceptance are pending.

When signed flag 88 is set, the routine resets eight UV coordinates from the original two external float constants. It allocates six 64-byte buffers through the original allocator context, then builds a separate display list for each face. Each list invalidates its buffer, resets the GX write-gather pipe, begins a four-vertex primitive, writes eight position/texture index bytes to the hardware FIFO, records the returned list length and stores the buffer cache range. All six original index sequences and calls are preserved.

The first isolated source and fresh production compilation both match with standard GC1.3.2 `-O4,p`, exceptions off. Ordinary inline face and vertex helpers naturally reproduce the original expanded bodies. The fixed FIFO address is the original volatile MMIO destination `CC008000`; no object payload, original storage identity or symbol alias is changed.

The compiler emits only the complete retained text entry. There is no data, BSS, weak helper, EH, startup allocation or owned padding. The allocator context, both float constants and all GX/cache routines retain their original external identities and ownership. The receiver is a partial field view of flag 88, UV data 8C..AC and six twelve-byte buffer records AC..F4; accepted six-handle class declarations and callers remain unchanged. This unit does not claim the complete original class or translation unit.

Current symbol-address, canonical-range and prior-body censuses find no earlier source owner or body probe. Complete original exception-index, constructor/destructor and initialized-pointer audits require no additional ownership. The frozen handoff is `scratch/engine_six_display_lists_20261011iw/final_integration.json`, with every emitted byte/symbol/allocation, actual relocations, source/header hashes and fresh strict verification. Root owns central registration and full original-DOL/regression acceptance.
