# Fallback disc error display

`src/Game/platform_disc_display.cpp` owns the 1,108-byte routine at
`8028EA98..8028EEEC`, fifteen message arrays at `802AF908..802AFA84`
(380 bytes) and the compiler-generated eight-byte conversion constant at
`8037B980..8037B988`. These are provisional partial TU boundaries. The text
renderer, texture pixels/object, shared state, other strings and float
constants retain their earlier ownership and earn no additional credit.

The routine begins the game's display interface, clears the current picture
through the original temporary handle lifetime, and sets up an orthographic
GX projection. Width and height are unsigned halfwords at game offsets `298`
and `29C`; the shifted halves are truncated to halfwords before signed float
conversion. The three stack matrices preserve their native order and layout.
A 64 by 96 I4 texture supplies the fallback font. Event 0 displays the open
cover message, events 1 and 2 request the game disc, event 3 reports an unreadable
disc, and event 4 displays the fatal instructions then waits forever after
ending the display interface. Other paths end the interface and return.

The message arrays use verified fixed extents, including their original zero
terminators, rather than borrowing offset pointers into a whole pool. This
reproduces the native pooled address calculation, including `addi r6,r31,0`
for the first message. The original global anchor `lbl_802AF908` remains
exported for earlier code; remaining strings beyond `802AFA84` stay original.
GC/1.3.2 with `-rostr` reproduces all code and owned data. The two unused weak
handle destructors (172 bytes) remain unlinked and excluded from progress.

`scratch/game_disc_display/verify.py --production` validates all 1,496 retained
bytes and 65 real relocations without masks, assembly or patched object bytes.
The linked ELF proof verifies each owned symbol and excludes helper bodies.
The full DOL remains byte-identical with the original SHA-1. All 738 source
units remain fully matched, all earlier source/header hashes are unchanged,
and all 23 tooling tests pass. See `scratch/platform_disc_display_checkpoint.json`.
Code/function/data denominators are unchanged; provisional build units grow
by three because the original text, message pool and conversion data split.
