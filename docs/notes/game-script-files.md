# Script-file interpreter

Two bounded parts of the script-file interpreter are source-exact under GC/1.3.2 with the Game flags recorded in their candidate manifests:

- `src/Game/script_file_destructor.cpp`: `801F9598..801F96A8`, 272 text bytes and 12 relocations. It destroys every file record, releases array storage, tears down the base object, and conditionally deletes the interpreter object.
- `src/Game/script_file_open.cpp`: `801F9AD4..801F9D0C`, 568 text bytes and 26 retained relocations. It opens a file, reports the result, copies its name, appends a record, selects the current file, activates the interpreter and invokes its virtual step method.

Both retained text sections match every original byte after relocation. Shared virtual tables and diagnostic strings remain external. The loader also emits an unreferenced 84-byte inline `FileRecord` destructor; the manifest records it for ordinary linker dead stripping, outside matched progress. Both fragments pass the complete DOL SHA-1, direct byte equality and native objdiff code/data audit; the unused helper is normally dead-stripped. Verification transcripts are under `scratch/game_script_files`.

A file record occupies 160 bytes: a 92-byte file object, a line number and a 64-byte name. Its dynamic array grows by eight records. Typed construction and destruction preserve the original nested null checks and member-copy sequences. These are reconstructed names and partial class boundaries; no original complete translation-unit identity is claimed. The original diagnostics identify script interpretation, and the allocation source literal names `File_Z.h`.

## Main interpreter step

`scratch/game_script_files/lastend.cpp` preserves all three routines together, including the unpromoted step at `801F96A8..801F9AD4`. The current step compiles to 1,064 bytes versus the original 1,068. Its instruction-mnemonic sequence differs by exactly one omitted `mr r29,r28` at original `801F96EC`, between the file-record pointer and its file member/base. Saved-register allocation and relative branch displacements consequently differ. This remains fallback and earns no matched credit.

The step handles line numbers, block-comment markers, trailing newline/carriage-return removal, interpreter commands, error reporting and current-file removal. The original early stop flag exits before cleanup. Ordinary inline `last`/`end` character-access helpers recover the original indexed addressing and zero-store ordering; direct indexing produces different code. Natural read-only compiler string pooling emits the exact 105-byte diagnostic/allocation pool at `802AD510..802AD579` in the combined candidate, with the following seven alignment bytes left unclaimed. The operator assigning file records uses allocation line 123 and alignment four, unlike the separately recovered file copy constructor. Those original distinctions are retained.

Pointer/reference, declaration-order, member-call, inheritance, helper-scope and compiler-option probes are durable beside the closest source. No assembly substitutions, volatile qualifiers, original-byte mutation or shared build changes were used.
