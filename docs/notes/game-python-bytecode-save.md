# Python bytecode file saving

The272-byte routine at8001FFE8 formats and converts a bytecode path, opens
the file for writing, marshals the Python object, writes its string bytes,
flushes/closes the file and releases the Python result. It returns the
original signed-char file-open result. A predeclared result and ordinary
nested size/string arguments preserve all original instruction scheduling.
The existing historical Python object declarations and File C API remain
unchanged.

This is an explicit partial text-only split, allowed by the repository
contribution instructions. GC1.3.2 with exceptions disabled emits exactly
272 text bytes and no other allocated sections. Normal-path File cleanup
is explicit in the reconstructed body. The original24-byte exception
action table at8000573C and12-byte index at80015FFC remain assembly-owned,
with zero source credit. Their cleanup interval54..EC still invokes the
original236-byte dtor_801F3E1C on stack local8; those bytes and references
must remain exact in both complete native links at every checkpoint.

Full original exception/startup tables, descriptor padding, every
initialized byte offset for function pointers, all allocated extents and
actual relocations have been audited. Original literal pools, global
identities, callers and lifecycle functions are external and unchanged.
Production hash, regressions and full checkpoint acceptance remain pending.
