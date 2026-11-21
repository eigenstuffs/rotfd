# Actor motion clamp at 0x80092DAC: private source probe

The original 128-byte function checks the 64-bit actor flag at `+0x30`,
caps the sum of fields `+0x160` and `+0x35C` against `+0x3E4`, adds a
product of `+0x350`, `+0x354` and the incoming float, then clamps the
result's absolute value against `+0x378` before adding it to `+0x148`.

The private source and compiler variants are in
`scratch/actor_motion_clamp_80092DAC/`. GC/1.3.2 at `-O4,s` generates the
original 128-byte extent with an ordinary incremental accumulator and an
explicit intermediate product. The closest probe matches 24 of 32
instruction words at their original positions; the remaining words use
different floating point registers for the first sum, maximum and final
position update. Reordering arithmetic, changing the function signature,
using the C front end and trying nearby compiler versions did not yield an
exact match. No source, split or progress credit was added for this probe.
