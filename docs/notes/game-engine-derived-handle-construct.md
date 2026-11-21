# Derived container and manipulator construction

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Six isolated ordinary C++ constructors reproduce 1,104 original code bytes,
268 extab bytes and 72 extabindex bytes. Production recompilation verifies all
87 real relocation targets and every allocated byte and symbol extent. No
additional code, weak backup destructor, literal, helper or padding is emitted.
The sources are private partial units and require full central DOL acceptance.

| Original entry | Code | EH/index | Real relocations | Observed derived setup |
| --- | ---: | ---: | ---: | --- |
| 8004904C | 164 | 40 | 14 | Handle70, scalar74, vector78 |
| 80049CE8 | 200 | 60 | 16 | Handles70/74, vector84, four scalars90..9C |
| 8004ABA0 | 260 | 80 | 19 | Handles70/74/78, vectors7C/88, quaternion94 |
| 8004DB2C | 180 | 60 | 15 | Handles70/74, vector84 |
| 800504F4 | 156 | 60 | 13 | Byte7D, Handles80/84 |
| 800E6EF4 | 144 | 40 | 10 | Word20, Handle24, scalars28/2C/30, byte34 |

The first five share the established 0x60-byte container view followed by
Agent80044118's opaque60..68, enabled byte68 and opaque69..70. Its constructor
installs table802B4B50 after the inline container table802ECF88 and sets byte68.
The root inline constructor calls the existing native ContainerBase constructor
at802563CC; the extra genuine inline lifetime reproduces the original self
pointer and base pointer register allocation. Its destructor identity is the
existing native Agent80044118 at8004426C. Unknown bytes remain opaque.

The manipulator constructor uses the established 0x20-byte ObjectsRoot extent
and the same-size ManipulatorDraw view, installing the original Draw table
before its final table802C8E88. Its owned exception record references the existing
native ManipulatorDraw destructor at800A6004. The two Handle zeroing layers use
native Handle80020B90; the first Handle in8004ABA0 uses the one-layer native
Handle8002B67C. All constructors call the original native Handle constructor at
801F7F04. Vector and quaternion constants are mutable external originals, so
ordinary member assignments preserve their precise original loads, including
the quaternion's first update-address load. Scalar constants remain external
small-data originals. Every external dependency is an actual undefined ELF
symbol; local exception objects are not published as external dependencies.

The proposed native constructor symbols carry original_symbol guards. The five
container entries have exactly one declaration and one call each in accepted
factories_800B9FFC.cpp; E6EF4 has exactly those two occurrences in accepted
factories_8007E160.cpp. The pending migration records freeze both current source
and canonical candidate hashes. The integrator must apply its accepted
identifier-only migration gate with preserved original/current snapshots and
prove identical consumer allocated bytes and resolved relocation targets. This
handoff modifies no consumer, shared declaration or central metadata.

The ownership audit scans the full original extabindex, constructor and
destructor tables, confirms true code extents and accounts for all original
section ownership. Each entry owns one exact EH/index record and appears in no
startup table. Scanning every initialized data section finds only that entry's
extabindex function pointer; there are no additional callable data-table
pointers. Original external tables and base constructor/destructor definitions
remain outside these partial units. The frozen manifests include all source
hashes and empty recursive header inventories because these private units have
no quoted includes. Isolated matches receive no full-build credit until root
acceptance passes.
