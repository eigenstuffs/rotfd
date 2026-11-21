# Handle-resource callbacks and lifetime

`src/Game/handle_resource.cpp` owns five functions in
`801E7544..801E7B98` (1,620 bytes) and the native 32-byte virtual table at
`802EA820..802EA840`. The existing factory references `MaterialObj_Z.h:20`
and allocates 24 bytes; the provisional class name is retained until its full
interface is recovered. It contains the Resource base and a three-word
array of retained handles at offset C.

The native destructor releases array elements and storage before base cleanup.
The lookup returns a retained handle for a resolved object with matching name.
The reference callback visits the array after an inlined resize-to-current-size
operation. Its original comparison and unreachable resize branches are
preserved by ordinary C++, rather than removed from the matching build.
The loader invokes the Root loader, reads the array count, resizes the array,
and reads each reference. The status callback requires the Root status and
each valid referenced object's virtual status; the original double lookup
for each valid handle is preserved.

`scratch/game_handle_resource/verify.py --production` verifies all retained
code and table bytes with 75 actual relocations. The object emits 188 extra
weak code bytes and a 32-byte weak Resource table. The unused OwnerHandle
helper is absent from the final ELF; original strong Resource definitions
override the other weak copies. None receives new source credit. The emitted
OwnerHandle helper lies between retained functions, so the proof uses each
function's actual object offset.

Only the virtual-table identifier changes in the existing factory source;
reversing that replacement reproduces its saved source hash. Its 132 bytes
remain exact. All 658 source units are exact, the DOL is byte-identical,
and all 23 tests and progress/extent/assembly checks pass. The initial baseline
is unchanged. Existing fallback/native-padding accounting warnings remain
without source regressions. Evidence: `scratch/handle_resource_checkpoint.json`.
This is a bounded build unit; neighboring resources and shared data remain
outside its ownership.
