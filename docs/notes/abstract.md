# Abstract object operations

`src/Objects/abstract.c` reconstructs the retained CPython 2.1 abstract object
API at `0x80130084..0x80134E70`: 60 functions and 19,948 code bytes. Its
initialized data consists of 1,206 diagnostic-string bytes and 78 small-data
bytes; two cached attribute pointers occupy eight BSS bytes.

The implementation comes from the licensed CPython 2.1 reference, with target
ABI declarations and only the linked APIs retained. The target uses the
attribute names `PyAbstract__class__` and `PyAbstract__bases__`, rather than the
upstream strings. Both cache pointers are declared together in their observed
order. Their placement was verified against every original SDA reference.

The diagnostic strings have explicit, descriptive reconstruction identifiers.
Their declaration order preserves the original data layout: in particular,
`len() of unsized object` precedes the containment diagnostic. Ordinary anonymous
string pooling placed those two strings in the opposite order with the recovered
inline settings. These declarations reconstruct readable data, not machine code.

`fn_801308B4` is a target-specific no-argument call helper: it validates the
callable, creates an empty tuple, evaluates the call, and releases the tuple.
Its original identifier is unknown. The remaining APIs retain their identified
Python names. Missing upstream exports and unused standalone inline-helper
copies are omitted; they do not contribute to the matched inventory.

The isolated comparison applied all 934 PowerPC relocations and found zero
byte differences across every initialized section. No branch or data-address
differences were masked. Integration additionally requires the complete DOL's
original SHA-1; generated progress records that result.
