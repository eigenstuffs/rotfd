# Big-file loader: private matching investigation

The original `8028A88C..8028AC20` routine is 916 bytes. The private candidate in
`scratch/game_audio_stream_open/` has that exact extent and all matching bytes
except eight instructions involving allocation of r27 versus r28 to the second
temporary buffer and loop counter. It remains unregistered and uncredited. The
strict verifier rejects it; `probe_registers.py` is diagnostic only and exits
before producing a manifest. Compiler version and declaration/loop-shape
variants are preserved, without credit.

Verified access relationships give a physical `4EE4`-byte view: 256 64-byte
metadata records at `A28`, DVD information at `4A28`, allocation/type pointers
at `4AD8` and `4ADC`, a 256-entry index map at `4AE0`, and count at `4EE0`.
Metadata accesses cover file offset `14`, size `18`, and presence `1C`. Names
and class relationships remain inferred; this extends the minimum `4AD8` view
needed by the accepted initializer without claiming original class recovery.

The function logs, rejects a null path, accepts an already-open state, opens the
DVD file, reads/copies a `4000`-byte metadata block through the original wait
wrapper, then builds a compact index map and finds the largest present entry.
The first 256-entry pass is compiled with four entries per loop iteration. It
allocates address and type tables and a temporary buffer of maximum size plus
32000. For each present entry it subtracts 28 from the size and rounds down to
four-byte alignment, allocates ARAM, reads the payload, records its first byte
as the type and submits/flushed the ARAM transfer. The optional callback is
invoked on every iteration, including absent entries. The temporary buffer is
freed and success returned; original allocation/read failure behavior is retained.

Repeated direct global field accesses permit the native early logger address
and later loop ARAM address to have separate lifetimes. Retaining a single
long-lived global pointer caused additional register and extent differences.
The ARAM flush leaf's C source does not read a receiver, but the original caller
loads one into r3; the private declaration explicitly represents that physical
caller argument. Its source declaration/callee consistency must be reviewed
before any integration. Diagnostic strings, global state, this function and
its metadata buffers earn no new source credit from this investigation.
