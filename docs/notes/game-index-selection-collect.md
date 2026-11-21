# Selected-index collection

`src/Game/index_selection_collect.cpp` reconstructs the 172-byte routine
`fn_802654E8` at `802654E8..80265594`. It returns zero when the cursor at `18`
is negative. Otherwise it asks the bitset at `1C` for each next set bit, writes
that index to a signed-short output buffer, and advances the member cursor.
It stops on exhaustion or when the signed-short view of the produced count
equals the signed-short caller limit. The return value retains the full
integer produced-count register. Names remain provisional.

The view borrows the already verified native bitset declaration. It owns no
bitset code, constants, data, BSS or padding, and does not assert a recovered
original translation-unit boundary. The original bit-search implementation
at `80207B94` remains an external original-code dependency.

GC/1.3.2 with `-O4,p -inline auto -Cpp_exceptions off -RTTI off
-use_lmw_stmw on` reproduces every emitted instruction. The complete object
contains exactly 172 text bytes and one function; its single branch relocation
is applied to the verified target `80207B94` before comparison. No weak cleanup
functions or other allocations are emitted. Run:

```
python3 scratch/game_index_selection_collect/verify.py
```

This split is integrated and passes the original DOL SHA-1 and native objdiff.
The candidate and applied-relocation evidence are in the same scratch folder.
