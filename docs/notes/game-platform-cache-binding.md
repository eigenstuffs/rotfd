# Platform cache binding

Two partial source units reconstruct **420 code bytes in three functions**:

| Source | Native entry | Original range | Bytes |
| --- | --- | --- | ---: |
| `platform_cache_base_bind.cpp` | Base binding sentinel | `801EC748..801EC754` | 12 |
| `platform_cache_bind.cpp` | Ten-entry cache binding | `8027D6B8..8027D784` | 204 |
| `platform_cache_bind.cpp` | 900-entry cache binding | `8027D784..8027D850` | 204 |

The base operation returns unsigned 16-bit sentinel `FFFF`. Each concrete
binding operation takes the previous index from the final list node,
subtracts one with 16-bit narrowing, and selects node `index + 1`. If that
node's former mapping index is valid, it resolves its retained handle through
the manager's generation check. A live object has its old mapping entry reset
to `FFFF`. The operation stores the incoming mapping index, delegates native
handle assignment to `801F7914`, and returns the selected cache index.

The object-side mapping pointer is at `+38` for the ten-entry cache and
`+104` for the 900-entry cache. Mapping records have four-byte stride and a
16-bit index at offset zero. Their remaining halfword is unidentified.
The cache node contains its native four-byte handle, mapping index at `+4`,
unidentified halfword at `+6`, and unsigned 16-bit list neighbors at `+8/+A`.
These verified halfwords refine the earlier unknown word without changing
any storage offsets. Unknown surrounding object fields remain opaque.

The shared cache declaration uses an explicit vptr at `+14`, after the
observed storage base. Its three binding functions keep their original native
C++ identities. The original 12-byte base table at `802EA868` and the two
12-byte concrete tables at `802F1490`/`802F149C` retain original ownership.
Their single virtual slot is binding, and the cache destructors are nonvirtual.
This interface view preserves the native layout and separates matching code
from shared data whose original translation-unit placement is unresolved.

A full native virtual-class probe also matches all 408 concrete binding code
bytes, but emits the concrete tables in reverse order. Inline-only definitions
emit no retained functions without an original instantiation context. Those
probes are preserved under `scratch/game_platform_cache_bind/`; they do not
receive source credit. The explicit interface source emits no tables or weak
helpers. The earlier two 604-byte cache destructor candidates remain private
with 32 register-allocation instruction differences each.

`scratch/game_platform_cache_bind/verify.py --production` accounts for every
emitted byte, symbol and allocated section, and applies all **six actual
relocations**. GC/1.3.2 uses the established `-O4,p -inline auto`, exceptions/
RTTI disabled and `-use_lmw_stmw on` settings. The shutdown routine is also
rechecked with the refined shared header before integration. No data, BSS,
metadata, padding, assembly, masked probes or altered original input is credited.
Original class/template/file names remain unknown; address names are provisional.

Integration passes the full byte-identical DOL and native objdiff checks.
All 673 source units remain exact; the refined cache header preserves the
previous shutdown bytes and physical layout. All 23 tests, progress exports,
and source extent/assembly audits pass. The original baseline is unchanged.
Evidence is recorded in `scratch/platform_cache_bind_checkpoint.json`.

## Native table continuation

`scratch/game_platform_cache_tables/` now preserves a native base binding/table
probe with exact 12-byte code and 12-byte data. The concrete binding probe
retains its exact 408-byte code, but emits the two 12-byte tables in reverse
order. Reversing class declaration order does not change that result. Reversing
method definition order corrects the table identities' order while also
reversing the native function placement, so the combined object cannot yet
replace the original. These tables remain uncredited. The source-order probes
are preserved; the production source and existing table ownership are unchanged.
