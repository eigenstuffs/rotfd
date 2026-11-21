# Scene storage, owner controls and MetroTRK memory handling

The standard native build verifies 2,128 additional code bytes, ten functions
and 153,690 additional source-owned data bytes against the prior checkpoint.
It retains the original code, data and function denominators. Native objdiff
reports, compiler probes and acceptance evidence are preserved separately under
`scratch/continuation_20261012_b/`; earlier frozen experiments are unchanged.

| Source or group | New code | New data |
| --- | ---: | ---: |
| `Game/scene_static_records.cpp` | 0 | 76,800 |
| `Game/platform_audio_stream_file_globals.cpp` extension | 0 | 65,536 |
| `MetroTRK/dispatch_data.c` | 0 | 140 |
| 63 `Game/engine_game_strings_*.cpp` units | 0 | 11,074 |
| `Game/owner_counter_update_8006C230.cpp` | 244 | 20 |
| `Game/owner_handle_copy_8006C620.cpp` | 140 | 56 |
| Three owner statistic helpers at `80069C08..80069CA8` | 160 | 0 |
| Two owner flag setters at `800975A4` and `8009770C` | 48 | 0 |
| `Game/scene_record_value_800C085C.cpp` | 24 | 0 |
| `dolphin/gx/GXTev_order.c` | 472 | 36 |
| `MetroTRK/msghndlr_commands.c` extension | 1,040 | 28 |

The two scene arrays retain their original GLOBAL identities and occupy
`802F4208..80306E08`: 300 selection records of 80 bytes followed by 400 resource
tokens of 132 bytes. Existing native array startup and token-loading routines
establish these element counts. Their ordinary POD definitions add no startup
or destructor code. The audio first-read cache owns `8035E9CC..8036E9CC`;
its inferred 64 KiB capacity excludes the four following alignment bytes.
The existing 92 bytes of audio globals remain unchanged. Four-byte trailing
boundaries for the audio cache and TRK dispatcher count retain original owners.

The string units define 611 ordinary exported character arrays with exact
original bytes and natural internal alignment. Their manifest is
`scratch/continuation_20261012_b/string-groups.json`. All 63 complete compiler
`.rodata` sections match; original pointer tables and boundary padding receive
no credit. Fifty-four explicit original-padding splits preserve the native
linker's placement. A first split attempt exposed an unaligned automatic
fragment; its failed log remains preserved alongside the corrected splits.
These are bounded partial data units, not asserted original translation units.

The owner counter uses a signed short promoted to an integer local. The handle
copy uses the real derived handle types and external reference manager. Its
compiler emits weak destructor backups, but the native executable retains the
existing strong 112- and 116-byte providers at `80020478` and `80020834`, plus
the original exception records. Backup code and metadata receive zero credit.
The statistic helpers' repeated inline getters and the record pointer's
volatile qualification recover observed native loads. The two flag setters
operate on a 64-bit field, explaining the original LIS/OR instruction pair.
The scene record setter retains the external four-record array and its inline
record accessor. Owner controls use `GC/1.3` where documented in configure;
the flag and scene setters use `GC/1.3.2`.

`GXSetTevOrder` owns `801162E8..801164C0` and its genuine LOCAL nine-element
conversion table at `802CFC28..802CFC4C`. Its four following bytes remain
original padding. All eight actual relocations and invalid-coordinate behavior
match using the existing GX compiler flags. The TRK dispatcher table retains
34 entries, including its two terminal nulls, and its separate four-byte count.
The dispatcher loop itself remains unfinished.

The TRK command unit extends the existing source with the read-memory handler
at `8011A8B4..8011ACC4`. Its adjacent read/write jump tables form one natural
56-byte data section. All nine functions, 7,140 code bytes, both LOCAL tables
and 144 actual relocations match. The new handler's volatile 16-bit count
preserves the original API-result store/reload. Existing eight functions and
their addresses remain unchanged. The child's separate combined source file
is an unregistered research artifact; production uses only the extended
`msghndlr_commands.c`.

Verification passes: native original-DOL SHA1, `ninja changes` with the saved
pre-edit baseline, source extents, generated progress check and all 47 tests.
`check_native_allocations.py` checks 702 native symbols, all 63 complete string
sections, original NOBITS extents, retained strong destructor providers and
exception/jump tables. The original DOL SHA1 remains
`5da8295a79bf297ab62c620e6ac66210be1c6ef5`.

The checkpoint is 1,859,300 / 2,607,776 code bytes (71.2983%), 7,761 / 8,803
functions and 696,432 / 1,030,936 data bytes. Completed build units are
4,858 / 6,011. The provisional unit denominator grows because partial source
and original-padding owners replace automatic fragments; no original byte or
function is removed. Shared conversion-pool closures, native C++ adjustment
thunks and the remaining ordinary routines continue as active work.
