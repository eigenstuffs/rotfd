# Related-handle forwarding methods

`src/Game/related_handle_forward.cpp` and its private header recover four
contiguous functions at `0x8025CEA4..0x8025D054`, totaling 432 bytes. The original
symbols remain unchanged. Their common source boundary is reconstructed; the
original translation-unit extent and class name remain unknown.

| Function | Bytes | Recovered operation |
| --- | ---: | --- |
| `fn_8025CEA4` | 104 | Resolve the handle at self `+0x68`, then return the membership predicate `fn_801E48EC`, forwarding the borrowed handle pointer unchanged. |
| `fn_8025CF0C` | 120 | Resolve self `+0x60`, then call hierarchy traversal `fn_801FC26C` with mask 11, identity at self `+4`, and unchanged context and float arguments. |
| `fn_8025CF84` | 104 | Resolve self `+0x6C`, then return the event query `fn_801C4968`, forwarding its key, output pointer, and first-key-only flag. |
| `fn_8025CFEC` | 104 | Resolve self `+0x6C`, then return the default event query `fn_801C4B7C`, forwarding its output pointer. |

The registry lookup uses the established signed 24-bit index and signed
8-bit generation within the manager's 16-byte entries. A generation mismatch
produces a null target which is forwarded unchanged; no new validity guard is
introduced. No owned handle is constructed or destroyed by these wrappers.
The event key and output pointers remain opaque private ABI views rather than
asserting an original event structure name.

The membership predicate is consumed as a signed byte by the accepted hierarchy
search `fn_802067A0`. The event wrapper return widths are independently visible
in the original Python bridge callers: the call to `fn_8025CFEC` at `0x800DE178`
is followed by `extsb r3,r3` at `0x800DE17C`, and the call to `fn_8025CF84` at
`0x800DE278` is followed by the same instruction at `0x800DE27C`, before
`PyInt_FromLong`. The original default-event callee selects key `0x23` and calls
`fn_801C4968` with first-key-only matching. Those deeper callees remain external
and receive no credit from this source.

The notification wrapper explicitly keeps the incoming float in `f1`; its lack
of floating-point instructions does not mean the parameter is absent. The
accepted traversal source consumes and forwards it. Resolving the target into
an ordinary local before preparing the mask/identity/context arguments
reproduces the original argument schedule. The first natural source probe
matches all four instruction sequences without special compiler settings.

The stable manifest is
`config/GSQE78/candidates/game_related_handle_forward.json`. Run
`python3 scratch/game_related_handle_forward/verify.py` for the strict isolated
proof: **432 text bytes, 12 actual ELF relocations, zero byte differences**.
The verifier checks source/header hashes, every function and allocated-section
extent, retained physical function order, the original DOL SHA-1
`5da8295a79bf297ab62c620e6ac66210be1c6ef5`, and complete bytes after applying
real relocations. There are no weak tails, data, BSS, exception metadata, or
padding to discard or credit.

Production hashes and the strict result are recorded in the manifest and
`scratch/game_related_handle_forward/verification.txt`. Central integration
passes the original DOL SHA-1 and direct whole-file byte comparison. Native
objdiff records 432/432 code bytes and four exact functions, with zero owned
data. The source-section extent guard and generated progress checks pass;
the documented baseline accounting corrections remain preserved.
