# Recovered CPython configuration

Complete translation-unit matches establish CPython **v2.1** as the strongest
source reference for this target. Earlier 1.5/1.6 suggestions in the preserved
research notebook predate these results. This does not imply the entire
interpreter is an unmodified upstream release: diagnostic line numbers and
some helper/cache arrangements differ.

## Compiler and layout

- CodeWarrior GC/2.0: Gekko, hardware floating point, integer enums, reused
  string literals, common symbols off, `-opt level=4,nopeephole,speed`.
- Most recovered units use `-inline auto,deferred -pool off` and disabled
  C++ exceptions. Tuple uses ordinary `-inline auto`; check each unit's flags.
- Deferred emission reverses function order. Mark helpers explicitly inline
  when the executable contains their expanded code but no standalone copy.
- Pointers, `int`, and `long` are four bytes. `PyObject` has reference count at
  0 and type pointer at 4; variable objects add size at 8. `PyTypeObject` is
  0x6C bytes. `PyCellObject` has a variable header and its value pointer at 0xC.
- Cyclic-GC allocation headers/bookkeeping are disabled. Traversal callbacks
  and the separate trash-chain mechanism remain. Default type flags are 0x6B.
- `PyObject_NEW` expands to malloc plus `PyObject_Init`; `PyObject_New` calls
  `_PyObject_New`. Their disposal macros likewise differ. Keep the original
  spelling rather than replacing allocation APIs indiscriminately.
- The recovered `_PyMem_EXTRA` value is 1. CString classification uses MSL's
  byte tables and masks. `tolower` checks EOF before indexing the unsigned
  byte table; casts can affect register allocation.
- SDA uses r13 base 0x8037BE40; SDA2 uses r2 base 0x803801C0. Relocation-aware
  checks must distinguish the two.

## Source and split evidence

Retain observed algorithms, including historical bugs. For example,
CPython v2.1's tuple comparison contains the `ws <= ws` expression present in
the target. Unused upstream APIs are omitted only when the linked function
inventory and surrounding code/data support their absence.

The initial symbol inventory is heuristic. Complete source established that
the isolated return instructions at 0x801406E0 and 0x80152F90 belong to
`PyDict_Next` and `long_hash`. Their enclosing function sizes increased by
four bytes and the two false function entries were removed. The total code
denominator did not change.

Likewise, several four-byte BSS pointers initially included four following
alignment bytes in their size. Give the pointer its compiled size and preserve
the padding separately. Explicit boundary symbols keep decomp-toolkit's
automatic gap symbols from crossing source splits. Class small data includes
an empty string at 0x80376014: its size is one byte, followed by padding.

Never use a perfect probe score as integration acceptance. Every promoted
unit must pass the complete DOL hash check, and generated progress must refer
to that build. `ninja changes` may show removed/renamed automatic units or
zero-denominator percentages; inspect matched byte counts for the existing
source units before interpreting those as regressions.

## Additional confirmed compiler settings

The evaluator and compiler use `-enum min`: the evaluator's why_code and the
compiler's comparison enum occupy one byte. Most other recovered interpreter
units use `-enum int`. Keep these overrides per source file.

Unicode's default UTF-16 byte order follows the source's little-endian branch:
WORDS_BIGENDIAN was not defined in this target configuration. Preserve that
observed behavior even though the host CPU is big-endian.

Ordinary unreferenced helper bodies may remain in a source object. The
Metrowerks linker discards them when they have no retained references, while
retaining shared literals in their original order. pythonrun and compile use
this mechanism and pass the full DOL hash plus complete objdiff matching.
Isolated checks must account for retained function addresses after stripping;
extra unlinked bodies do not count as matched functions or bytes.

Parser/assert.h is a separate, active assertion mechanism. It prints a fixed
message and aborts even when Py_DEBUG is absent. Do not apply the object
interpreter's disabled-assert convention to these parser units.
