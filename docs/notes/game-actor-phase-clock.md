# Actor phase clock update (800A36D0)

`fn_800A36D0` first invokes the inherited phase update at `8009DF78` with
its original pointer and delta, then stores `delta + elapsed` in the float
at offset `0x394`. The addition operand order is retained because it controls
the original instruction and floating-point behavior.

The ordinary C++ body emits 76 bytes of text, an 8-byte exception record,
and its 12-byte exception index. There are three actual relocations, no
literal pool, helpers, weak definitions, or startup entries. The inherited
phase implementation remains supplied by its existing original owner.

Isolated complete-object verification passed; full matching build integration
and final native retention are recorded separately by the root checkpoint.
