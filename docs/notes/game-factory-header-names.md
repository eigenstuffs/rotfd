# Factory diagnostic header filenames — isolated, uncredited

The ordinary C++ definitions in `src/Game/factory_header_names_802AE088.cpp`
reproduce 43 native GLOBAL char arrays at `802AE088..802AE327`. A fresh
GC/1.3.2 compilation emits exactly 671 rodata bytes: 602 bytes of NUL-terminated
text and 69 bytes of natural four-byte alignment across 33 internal gaps.
There is no text, BSS, actual relocation, category relocation or helper emission.
The raw verifier checks the full allocated symbol Counter, including the one
genuine anonymous LOCAL section marker. Raw and private native byte checks pass.

The complete original object is 952 bytes, not the 672-byte aligned string run.
Its one-byte boundary at `802AE327..802AE328` and two neighboring compiler
string pools at `802AE328..802AE440` retain original ownership. No capacity,
extra array element, explicit padding, pool alias or other source extent is
inferred from those bytes.

Historical v41 input evidence records 172 distinct union relocation rows,
including 86 original and 86 active rows, for the 43 names. A bytewise scan of
all 501,416 original initialized-data positions finds no pointers to the run;
the complete exception, constructor and destructor tables contain no references.
The historical input evidence is not a post-integration current-build audit.

All 1,791 current canonical metadata files were captured before this source was
created; no source ownership overlaps the run. The native identities, source
history, fresh object, malformed-object controls and private production-name
native link are preserved under
`scratch/root_factory_header_names_802ae088_20261011/`. The source remains
unregistered and receives no progress credit. A current closure, reviewed split
projection and full original-DOL acceptance are still required.
