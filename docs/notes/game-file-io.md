# Game file I/O

The first 16 contiguous functions at `801F2A4C..801F3814` are reconstructed and verified: 3,528 bytes of ordinary C++ and 46 retained relocations, with no initialized data or BSS owned by this partial unit. Full-DOL SHA1 and native objdiff code/data checks pass. The source is `src/Game/file_io.cpp`; original class names, method names and the full original translation-unit boundary are not claimed.

The recovered object begins with a 0x3C-byte DVD file-info region, followed by an unsigned host handle, stdio stream, signed-byte DVD-open flag, backing buffer, total size, current offset and buffered-write count. An invalid host handle is `0xFFFFFFFF`. The buffer supports 0x18000-byte writes and 32-byte transfers through an aligned temporary allocation. These details are inferred directly from the original instructions and call sites.

The verified operations are path-slash normalization; closing all backing resources; flushing the output buffer; buffered write; host/stdio/memory read; end-of-file and size queries; seek; byte access; quoted or ordinary token reading; line reading; four numeric readers; and word reading. The four numeric destinations are 16-bit integer, two 32-bit integer variants and float. The original typedef distinction between the two identical 32-bit readers is not established.

## Compiler and source findings

Use GC/1.3.2 with `-proc gekko -fp hardware -enum int -str reuse -common off -O4,p -inline auto -Cpp_exceptions off -use_lmw_stmw on`. Multiple-register save/restore is required by buffered write. The narrower functions retain the ordinary individual-register prologues.

- Indexed path copying lets the compiler introduce the exact source and destination pointer induction variables. A manually advanced output pointer is equivalent C but gives different register allocation.
- The aligned read length is an unsigned long. Treating it as int and converting at the allocator call changes argument-register setup even though both types have the same width.
- Seek remains out of line with the existing project's `#pragma dont_inline` convention. Otherwise auto-inlining specializes seek inside quoted-token reading and changes the original control flow.
- A shared whitespace helper accepts the caller's initial offset; its one-argument overload supplies the current offset. Reusing the quoted-token reader's saved offset in the first comparison reproduces the original register data flow. All numeric and word readers use the same implementation and compile exactly.
- Byte/status values are char, rather than C++ bool or unsigned char. Their promotion and return conventions explain the original sign-extension instructions.

No original bounds checks or parsing quirks were changed. In particular, several parsing loops read the current buffer byte before checking the position, and numeric scanning accepts the original punctuation/exponent character set.

## Verification and remaining scope

`scratch/game_file_io/verify.py file_io` checks the original DOL SHA1, complete allocated-section inventory, exact text extent, every function extent, all relocated bytes and external symbol addresses. It writes `config/GSQE78/candidates/game_file_io.json`. The original SHA1 is `5da8295a79bf297ab62c620e6ac66210be1c6ef5`.

The broader file layer continues beyond this partial split: path existence at `801F3814`, file opening at `801F3918`, allocation/copy/destruction through `801F3F30`, and a subsequent asynchronous DVD wrapper. Those functions remain under recovery. Shared diagnostics and memory-manager references stay with their current owners; this partial source introduces no synthetic string or storage definitions.

## Lifecycle continuation

`src/Game/file_lifecycle.cpp` reconstructs the four contiguous functions at `801F3C70..801F3F30`: allocation/initialization (120 bytes), copy construction (308), destruction (236), and default initialization (40). All 704 bytes and 26 relocations match in isolated verification. Full-DOL SHA1 and native objdiff code/data integration pass. The close helper is fully inlined into destruction and matches the already integrated close operation; no extra helper text or data is emitted.

The DVD file-info header contains a 48-byte command-block subobject followed by start, length and callback fields. Copying the command block as a nested object and the three trailing fields separately reproduces the original copy instruction ordering. Assigning all 60 bytes as a single aggregate gives a different final load/store schedule. The deleting-destructor flag is a signed short. The default initializer preserves the original initial `dvdOpen = -1` store followed by its later zero store.

The existence/open candidates and their shared data remain in `scratch/game_file_io`. Internal const arrays reproduce the original 64-byte diagnostic pool at `802AD4A0..802AD4E0`; the write mode is three bytes at `8037A730`, and selection state is two bytes at `80377FE8..80377FEA`. The current unresolved source detail is the unused basename counter retained in both original inlined filename-validation scans. An extra SDK argument used in an exploratory probe is not a claimed prototype and is not promoted.

## Asynchronous DVD group

`src/Game/file_async.cpp` reconstructs six contiguous functions at `801F3F30..801F44DC`: resolving an entry when the drive is ready, polling a read operation, submitting an asynchronous sector read, performing the blocking read variant, opening a named file, and default construction. The complete object matches 1,452 text bytes, a 24-byte diagnostic string at `802AD4E0` and a one-byte empty string at `8037A738`, with all 32 relocations applied. The seven following small-data alignment bytes are left as fallback. Full-DOL SHA1 and native objdiff code/data integration pass.

The object has an entry index at offset zero, DVD file information at offset four, a 128-byte path at offset `0x40`, and signed sector count, current chunk, position, state and error fields at `0xC8..0xD8`. Sector reads shift counts and offsets by eleven, corresponding to 2,048-byte sectors. These field roles and offsets come from the observed operations; original type and enum names remain unknown.

This group requires `-bool off` in addition to the first group's flags, and uses `-str reuse,readonly`. The default C++ bool setting changes three logical-OR intermediate tests to byte-masking instructions; with bool disabled they match the original integer comparisons. Declaring the recovery error local before the drive-status local reproduces the saved-register allocation. The open routine first keeps the file size in bytes, resets the position, then assigns its signed division by 2,048 to the sector count; precomputing the division gives different scratch-register allocation.

`scratch/game_file_io/verify.py file_async` verifies every allocated section and emits `config/GSQE78/candidates/game_file_async.json`. The corresponding transcript is `scratch/game_file_io/async_verification.txt`.

The async empty-string split is followed by an explicit original-assembly padding unit at `8037A739..8037A740`, aligned to one byte. DTK requires that explicit split for an odd-address boundary. Those seven bytes remain original fallback and are not counted as reconstructed source data.

## String compatibility helpers

`src/Game/file_strings.cpp` matches the entire 252-byte range `801F44DC..801F45D8`, with one relocation and no data. It contains a wrapper that builds the twelve-byte PowerPC varargs descriptor and calls `vsprintf`, a case-tolerant character comparison loop, and ASCII uppercase conversion. The comparison preserves the original arithmetic behavior: differences of positive or negative 32 are accepted without an additional alphabetic-range test.

The comparison function is 124 bytes, including an unreachable trailing `blr` at `801F4598` emitted naturally by the compiler. The earlier function detector classified that final instruction as a separate four-byte function. The corrected source inventory has three functions in this range; the total code-byte denominator is unchanged.

Uppercase conversion tests a plain char but performs the subtraction on an explicitly unsigned byte. That type boundary preserves the repeated byte load seen in the original; using a plain-char load for both operations lets the compiler reuse the earlier load and emits four fewer bytes. No volatile accesses or assembly are introduced. The source uses the async group's bool-off flag, with ordinary reusable strings. Strict proof is `scratch/game_file_io/strings_verification.txt`; full-DOL SHA1 and native objdiff code/data integration pass.
