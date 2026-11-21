# Owner rotation start

`src/Game/owner_rotation_start.cpp` reconstructs `fn_80229EE0`,
`0x80229EE0..0x8022A160` (640 bytes), using standard GC 1.3.2 settings.
The isolated production compilation matches every original byte and actual
relocation. Central integration and full-DOL acceptance are pending.

It clears the target through a four-zero default handle, resets base motion,
sets owner flags `0x23E00`, clears `0x800000000`, and calls virtual `0x118`
with `(1,0)`. The primary object from virtual `0x9C` at index zero gains flag
`0x40000`; its parent receives virtual `0x44` with `-1`. The primary quaternion
at `0xC8` is copied to both owner quaternions at `0x188` and `0x198`, followed
by both zero and period stores to phase `0x1A8`. After virtual `0x12C`, velocity
is zeroed, handle `0x184` receives a four-zero empty handle, and handle `0x180`
receives that second handle. Lexical handle lifetimes and the second handle's
reference accessor reproduce the native temporary slots and retained source.

Run `python3 scratch/game_owner_rotation_start/verify.py` for the frozen
source proof: all 640 retained bytes, 16 actual relocations, and 1,000 allocated
text bytes are checked. Four unused weak destructor backups total 360 bytes;
their eight relocations are inventoried, no retained reference targets them,
and they must be absent from the final ELF. Complete original extabindex,
constructor and destructor table scans show no retained ownership. No data,
BSS, or padding is owned. This partial text split leaves the containing
original translation unit outside its scope.
