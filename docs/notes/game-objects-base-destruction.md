# ObjectsBase native destruction and exception metadata

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

The genuine C++ `ObjectsBase_802EB3F8::~ObjectsBase_802EB3F8()` matches all 772 original code bytes at `80026F28..8002722C`, its 40-byte exception table at `80006240..80006268`, and its 12-byte exception index at `80016500..8001650C`. Source: `src/Game/objects_base_destruction.cpp`. Strict verifier: `python3 scratch/game_objects_base_destruction/verify.py`. No helper, padding, BSS, vtable, constant or other original data receives credit.

The private native lifetime view agrees with the accepted constructor's 0x168-byte extent. An empty destructor body installs the external ObjectsBase table. Automatic member destruction emits the two-layer handles at +12C and +68, a trivial 40-byte record array at +6C, a two-layer handle array at +5C, trivial arrays with 12/16/12-byte elements at +50/+44/+38, and three/two/two handle layers at +28/+24/+20. The inline root destructor installs the external ObjectsRoot table and calls the existing native ObjectsOwner destructor with delete flag zero. Opaque fields remain unclaimed.

The ordinary array destructors preserve the compiler's empty element-destruction loops and repeated data null stores. Native destructor lowering supplies the original entry null guard, member-address tests, short delete flag, custom allocator and returned this. GC/1.3.2 uses the established destructor settings `-O4,s -inline auto -Cpp_exceptions on -use_lmw_stmw on`. The allocator's ordinary `throw()` specification generates the original unexpected-exception path and both complete metadata records, including their actual index relocations. No manually authored table, assembly, relocation masking or object patch is used.

The original provisional base destructor spelling was already reconciled to this native name by the accepted ObjectsMove destructor, preserving its address and extent. This unit supplies that same strong definition without another symbol migration or caller edit. It emits only the three owned sections and one complete native function. The original external vtables, allocator object and complete class interfaces remain outside this fragment. Central production, original-hash and regression acceptance are required before promotion.
