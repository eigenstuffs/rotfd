# Native member access

`src/Python/structmember.c` reconstructs CPython v2.1's native struct member
get/set interface. `PyMember_Set` and `PyMember_Get` occupy
0x801AB66C..0x801ABCA0 (1,588 bytes). The member-list enumeration helper is
inlined into the getter.

Data occupies 0x802E9648..0x802E970C (196 bytes), including switch tables and
error strings. Two floating-point conversion constants occupy
0x8037A1C0..0x8037A1D0 (16 bytes). Macintosh-only Pascal-string cases are
disabled, matching the linked functions and their jump tables.

GC/2.0 uses the established speed/deferred/no-pooling/no-exception settings.
Isolated verification resolves all 123 relocations, including SDA2 references
through r2, and compares all initialized bytes. The standard `ninja` build
and generated progress provide the integration acceptance result.
