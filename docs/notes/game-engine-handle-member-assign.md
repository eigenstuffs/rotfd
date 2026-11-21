# Handle member assignment and service application

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Four original C entries are frozen:8002F59C,8002F728,80062B20 and800B4E48.
They reproduce 604 original code bytes,224 extab/index bytes,46 retained actual
relocations using GC1.3.2 space optimization, automatic inlining, exceptions,
and lmw/stmw. The first three construct a retained Handle copy, release the
existing owner member, assign the copied four-byte word and retain it, then
destroy the temporary. Observed member offsets are30,24 and1F4 respectively.
The fourth calls original reset802139D8, copies the Handle at owner4, and applies
it to the slot indexed by owner byte34 with stride4C at context114.

Native Handle801F7F10 construction/cleanup and context manager118 are unchanged.
The first two use Handle80020834 over Handle80020478; 62B20 uses Handle80021BCC
over Handle80021C40. B4E48 uses Handle8002F6B0 over Handle80021BCC, with a private
initial zeroing layer. The number and placement of zero stores, retain/release
calls, pointer lifetimes and compiler cleanup states follow the original code.
All original C entry names are preserved; no aliases or assembly are introduced.

Each retained metadata record refers to existing original strong native Handle
destructors. Canonical owner manifest/source/header hashes, actual relocations,
production object hashes and independent identical recompilation proof are
frozen per unit. The adopted bounded strong override verifier relocates retained
EH to those actual strong definitions, checks every retained byte, and accounts
for every emitted symbol/allocation. Aggregate uncredited backup output is1,032
text bytes and468 EH/index bytes, with63 backup relocations. B4E48 includes one
private ZeroHandle_800B4E48 backup; it has no retained references and must be
absent from the final ELF. Every backup text/EH/index group must be discarded
by the final native link; only original retained extents receive credit.

Function80094920 is a private near-match only. Its three zeroing layers, all
calls and whole function extent agree, but the compiler schedules its source
word load before the final zero stores, with register differences from the
original manager-first sequence. Ordinary inline copy helpers, a raw word view
and generated base assignment did not close that bounded probe. No production
source or credit is claimed for it.

Full extabindex80015F60..8001F2C0 audits establish one original record per retained
function and its exact function size. Full ctor80299920..80299980 and
dtor80299980..802999A0 audits contain no references. True function extents,
original section ranges and original unit ownership are frozen separately.
Only actual undefined ELF relocation targets enter dependency_symbols; all
local backup metadata remains local. Sources, recursive quoted header hashes,
private verification scripts and manifests are frozen in handoff.json. Shared
metadata and existing accepted source remain untouched. Central original DOL
hash acceptance and native backup discard audits are required.
