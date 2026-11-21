# Disc wait and display restoration

`src/Game/platform_disc_wait.cpp` reconstructs `8028EF84..8028F29C`:
792 text bytes and the 52-byte compiler-generated switch table at
`802F2300..802F2334`. The names and translation-unit boundary remain provisional.
This is a partial split; diagnostic strings, callback pointers, shared flags,
retry buffer, error display and neighboring poll/error routines retain their
original ownership.

The routine polls the global DVD drive status and pumps the platform each
iteration. Statuses 4, 5, 6 and 11 enter retryable error handling; -1 enters
fatal handling and clears the success result. A shared signed-byte flag
serializes error handling between callers. Completion depends on both the
current status and the preceding reading state. The retry path opens the
original filename into a stack DVD record and submits a 16-byte asynchronous
read. Failed opens log the filename and retry.

If the original error-display flag is set, the routine restores the game
display through its virtual interface at physical offset `278`. The
four-byte temporary handle invokes the original constructor, two native
zero-initializing handle layers and the original base destructor. The display
receives that empty handle and is resized to 640 by 448. Virtual method names
remain placeholders except for their observed arguments.

The final status-to-event mapping is 5 → 0, 4 → 1, 6 → 2, 11 → 3, -1 → 4;
all other values map to -1. The callback is conditional on its pointer and
the original enable flag. Shared flag clearing follows the original branches.

GC/1.3.2 with the registered flags emits the exact body and switch table.
Keeping status at function scope recovers the native register allocation;
assigning the remembered error in the call argument recovers the four
otherwise differing scheduling instructions. These are ordinary C++
expressions, with no assembly, masking or post-compilation patching.

`scratch/game_disc_wait/verify.py --production` checks every retained byte,
all 50 retained relocations, section extents and strong/local bindings.
The compiler also emits two unused weak handle destructors, totaling 172
bytes. They are accounted for, not retained or credited. The linked-byte
proof verifies their absence and all 844 retained code/data bytes in the ELF.

Integration evidence is in `scratch/platform_disc_wait_checkpoint.json`
and `scratch/platform_disc_wait_link_proof.json`. The full DOL matches the
original byte for byte and passes its unchanged SHA-1. All 736 linked
source units remain fully matching; all 23 tooling tests, source extent
and assembly audits pass. Earlier source/header hashes and the original
baseline remain unchanged. The native progress report retains all unknown
units and all code, function and data denominators.

The subsequent poll integration extends this same source unit through
`8028F4B4` (1,328 code bytes and 104 table bytes). The original wait body and
table remain unchanged. Use `verify_wait_poll.py --production` for the current
combined source. Its two unused weak destructors still total 172 bytes and
remain unlinked. See [poll integration](game-platform-disc-poll.md).
