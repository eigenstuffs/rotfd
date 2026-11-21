# Streaming removal and lifetime fragments

These partial source units reconstruct 616 text bytes and 92 BSS bytes of the
GSQE78 streaming implementation. Original translation-unit boundaries and class
names remain inferred. The larger channel cleanup and streaming setup/thread
functions remain original.

## Owned ranges

| Source | Range | Functions or objects |
| --- | --- | --- |
| `platform_audio_stream_remove.cpp` | `80289968..80289ADC` | removal by name, 372 bytes |
| `platform_audio_stream_lifetime.cpp` | `8028AF48..8028B03C` | destructor and constructor fragments, 244 bytes |
| `platform_audio_stream_file_globals.cpp` | `8035E970..8035E9CC` | 60-byte DVD record and 32-byte path buffer |

All three functions are strong globals. The two BSS objects occupy exactly the
compiler-emitted 92 bytes; the following four alignment bytes remain original.
The constructor initializes the existing source-owned mutex, clears the trailing
allocation pointer at `4AD4`, and clears the first path byte. The destructor
cancels the embedded thread at `338`, frees the allocation at `670`, conditionally
frees the allocation at `4AD4`, clears that pointer, conditionally closes the
shared DVD record, and frees the enclosing object only for a positive signed
short deletion flag. Its physical layout is in the new lifetime header; the
opaque ranges and relationships to the existing streaming view are not recovered
class declarations.

The removal function returns -1 for a null name. Under the mutex it compares the
queued registry name at `80`, edits the head or predecessor link, and calls the
original allocator release. Its native ordering is unusual: the head-removal
path continues through the old node, and the subsequent-node path passes the
predecessor to release after unlinking its successor. The source deliberately
preserves those observed operands and operations. It then searches six 16-byte
active names, calls the original channel cleanup for a match, clears its flags
and name, and returns the selected index. This is reconstruction evidence, not a
claim that the original list logic is correct.

## Verification

`python3 scratch/game_audio_stream_release/verify.py --production` checks every
text byte after applying all 42 actual relocations, section extents, function
binding/types, and all included headers. `verify_globals.py --production` checks
both BSS symbols, their exact offsets and sizes, NOBITS storage, original DOL BSS
bounds, and absence of helper code or relocations. No extracted assembly or
masked comparison earns progress. Final integration additionally requires the
original SHA-1, native objdiff completeness, source extent and assembly audits,
all previous matches, and the tooling tests.

## Cleanup probe, subsequently integrated

The initially private `platform_audio_stream_release.cpp` reconstructs `8028A4F0` and its
record/voice field accesses. A void signature and unsigned channel comparison
produce the native 468-byte extent; ordinary diagnostic argument evaluation
still differs in scheduling around the two calls. A volatile logger experiment
reduces the differences but does not match. These variants and two local string
objects remain private and uncredited; the existing shared cleanup declaration
has not been changed. Full signature and data ownership must be resolved before
integrating that function.

The scheduling difference is now resolved and the complete function plus both
strings are linked from source. See [indexed cleanup evidence](game-platform-audio-stream-cleanup.md)
for the accepted implementation and shared declaration correction. Historical
failed alternatives remain uncredited.
