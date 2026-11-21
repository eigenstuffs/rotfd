# Scene owner construction

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Original fn800B79A4 is recovered as ordinary native C++ construction. The
isolated production source matches all164 text bytes,60 extab bytes,12 index
bytes and12 actual relocations under the established GC1.3.2 space/inlining/EH
flags. It emits no other allocated output. Central native original DOL acceptance
is still required.

The private base Object80260C7C view preserves the existing original C initializer
fn80260FF8 and native destructor identity. The base extent1504C, table at30, and
opaque inherited tail are established by accepted destruction source atB7B28.
The two bytes at15048/49 are observed zeroed by this constructor. The derived
member Object800B7A48 at1504C is the accepted count/capacity/data record of sizeC;
its inline constructor clears those three words. Five following words at15058,
5C,60,64,68 are cleared before the four-byte Handle at1506C is constructed with
two zeroing layers. The accepted native Handle80021BCC destructor is referenced
unchanged. Word1505C is cleared again before the three original setup calls.

The source uses genuine base/member construction and comma expressions in member
initializers to install the derived table, bytes and scalar defaults at their
observed construction stages. Compiler-generated cleanup covers the inherited
base, record member and Handle member with the exact original three-action EH
chain. The opaque private layouts make no claims about unobserved fields. No
helpers, aliases, assembly or unused weak functions are emitted.

The proposed guarded identifier migration is fn800B79A4 to
__ct__15Object_800B79A4Fv at the same original address. The complete source/include
old-name audit found no accepted consumers; original_symbol is frozen. Current
native base/member destructor names are preserved, including the still-assembly
base Object80260C7C which receives no source credit from this partial unit.

The full extabindex80015F60..8001F2C0 audit finds exactly the original record at
8001C170 pointing to extab80011A70, with the exact164-byte function extent. Full
ctor80299920..80299980 and dtor80299980..802999A0 audits have no references.
True original section ranges, owned local metadata symbols, actual undefined
ELF dependencies and source hashes are frozen in final_integration.json and
ownership_audit.json. Existing source, shared metadata and prior frozen handoffs
remain unchanged.
