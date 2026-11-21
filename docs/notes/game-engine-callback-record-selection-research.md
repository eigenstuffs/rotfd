# Record-selection callback research (uncredited)

The isolated ordinary C++ probe for `fn_80071A64` reconstructs its 1,252-byte
extent, eight-byte exception header, twelve-byte index, and both original
switch tables. The best probes still differ in nineteen or twenty register
operands, so no source is proposed for integration and no progress is claimed.
All sources, raw compiler objects, disassembly, resolved-relocation reports
and bounded source-form experiments remain in
`scratch/game_engine_callback_record_selection_continuation/`.

Observed owner fields are selected index `64`, target index `68`, group `6C`,
flags `70/71`, and records starting at `74`. Each twenty-byte record contains
a short identifier at zero, actor pointer at four, and three floats at eight.
The reset loop establishes nine such records. Selection rows begin at `128`
with stride `44` and four-byte entries; the complete row count is unknown.
The actor has a Handle at `70` and current record identifier at `92`.

Action nine queries selector `9C`; action ten sets flag `71`; action eleven
returns whether the selected row entry is negative; action twelve clears
flag `71`, resolves all nine actors' Handles and sends control message three,
then clears callback bit two. Action fourteen reports a nonnegative row
entry. Action fifteen validates the selected actor with `fn_80072468`, and
when flag `70` is clear, copies the target record's position into the resolved
object at `19C`, calls `fn_8007340C`, sends control message one, swaps record
actor pointers while updating their identifiers, sets flag `70`, and advances
the selected index. It always sends the original two-float notification.
The adjacent `8007340C` body contains a reciprocal-square-root/reciprocal
estimate sequence already known to need unsupported compiler behavior; this
investigation does not claim that function.

A genuine inline conditional helper reproduces the native swap control flow.
Direct boolean assignment reproduces the original availability conversion,
and the typed nine-record loop reproduces the native loop extent. Remaining
saved-register permutations place selected actor, old identifier, replacement
actor, loop counter and offset in different registers. Method/free-helper
forms, named references, local declaration permutations, and ordinary accessor
forms did not remove the remaining differences. Related private `71660` and
`71904` findings from the world agent report similar register permutations.

The two compiler tables occupy `802B791C..802B795C`; their combined section
starts four modulo eight. A future exact source must therefore audit native
alignment. The five complete original member-pointer records immediately
before them start at the eight-aligned address `802B78E0` and remain original
assembly. No pool adoption or synthetic padding was attempted. No central,
accepted source, protected source, or previously frozen handoff was changed.
