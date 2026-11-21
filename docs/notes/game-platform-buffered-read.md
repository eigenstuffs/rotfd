# Platform buffered read

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

`fn_8028C280` reads through a 32-byte staging buffer. It consumes any unread
portion first, reads aligned whole blocks directly when the destination is
aligned, and otherwise uses the original global scratch buffer before copying.
A final partial block remains in the object's staging buffer for the next call.
The original signed pointer-remainder alignment test is preserved.

The reader's opaque file state begins at0x0c, its consumed-byte count at0x48,
file offset at0x4c and staging pointer at0x50. The file-read callee receives the
same file state in its first two argument slots. The global scratch pointer at
80378124 stays external. Larger platform ownership and the file-state type
remain unresolved; these declarations represent observed storage and ABI.

Ordinary C++ compiles to exactly532text bytes with GC1.3.2 standard Game flags
and LMW enabled. All actual references are resolved to original addresses.
No data, literals, BSS, weak helpers, padding or exception/startup records are
emitted or credited. The full original exception-index, constructor and
destructor tables are scanned before integration. This is a partial text-only
translation unit; neighboring platform routines/data remain outside it.
