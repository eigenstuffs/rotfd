# TeleportVolume recovery

`src/Game/teleport_volume_events.cpp` reconstructs the 752-byte event handler at `800C7D70..800C8060`, its 28-byte compiler-generated jump table at `802C11B0..802C11CC`, and 20 bytes of exception and index records. GC/1.3.2 with size optimization and C++ exceptions emits every allocated byte exactly after 32 relocations. The complete DOL hash, direct byte comparison, native objdiff code/data checks, and original-source regression audit pass.

The first seven event types query or register the observed member-function callback descriptors, inspect flag bits, and retrieve the event index. Subsequent dispatch handles event context, tests the two enabling conditions, invokes the virtual transition callbacks, and clears the event flag. A plain logical-OR expression preserves the compiler's boolean result conversion; the explicit 16-bit mask preserves the original flag update.

The shared callback descriptor pool remains original fallback data. This source unit owns only its compiler-generated switch table. The registration function at `800C7534` is separately exact in an isolated probe but remains unregistered while the complete shared descriptor ownership is recovered. The constructor is integrated as described below; the destructor is now integrated as well; larger transition handlers remain work in progress. The original whole translation-unit identity is not claimed.

Verification inventory: `scratch/game_class_registry/inventory_teleport.json`; command: `python3 scratch/game_class_registry/verify.py --teleport`.

## Lifecycle hooks and property registry

`teleport_volume_hooks.cpp` adds the three consecutive methods at `800C7924..800C7A24`: 256 code bytes and 60 bytes of exact exception/index metadata. The first two call the base lifecycle hook and a virtual reset callback. The third sets an observed 64-bit flag and transfers the generation-counted reference, decrementing the old reference before copying and incrementing the replacement.

`teleport_volume_registry.cpp` adds the four methods at `800C9130..800C9240`: 272 code bytes and 40 metadata bytes. These read/write the class state, enumerate properties across four inherited descriptor sets, and search those sets in order with the original -1 sentinel. All seven methods pass full-DOL integration.

## Parameter configuration and orientation

`teleport_volume_configure.cpp` adds 844 code bytes and 20 metadata bytes at `800C7A24..800C7D70`. It reads seven numeric properties, assigns generation-counted references, selects the active transform, copies the observed positions, and computes the destination orientation. Plain compound multiplication preserves the original floating-point operand order. The complete DOL and native source checks pass.

The three floating constants are shared with the larger handler at `800C8900`, so they remain original data in the integrated fragment. A separate ordinary C++ axis-angle helper in `scratch/game_teleport/configure_owned_pool.cpp` reproduces the complete 12-byte compiler-generated literal pool and every instruction. It is preserved for later coalescing with the remaining handler; compiler-local constants are not exported or counted prematurely. Direct inline scalar literals alone simplify away two original multiplications, whereas the axis-angle helper retains the observed computation.

## Larger transition handler

`scratch/game_teleport/transition.cpp` reconstructs the larger `800C8900..800C9130` handler, including its actual layered handle construction/destruction and five compiler-emitted weak destructor definitions. The best main body is 2,092 bytes against the original 2,096. The initial event-query dispatch, conditional branches, temporary lifetimes, nested generation checks, transform copying, resource transitions, final virtual calls and flag cleanup have matching instruction sequences except for two bounded areas.

The remaining table-read block uses 16-byte entries and the two words at offsets eight and twelve. The compiler currently combines base-plus-index once, whereas the original retains two indexed loads, accounting for one missing instruction. A later target-handle lookup has five register-encoding differences. Direct/member/flat-buffer access, reference helpers, 64-bit pair variants, compiler inline options and several typed resolver views are retained under `scratch/game_teleport`. This unregistered probe has no matched-source credit.

Distinct typed views of the registry preserve the required second table load for nested handles. Holding the target object in a local while copying its position and quaternion preserves the original single pointer load. Those ordinary C++ changes removed all other structural differences. The probe's inferred handle hierarchy must be reconciled with the shared typed-handle declarations before production integration; final acceptance will also verify every weak duplicate and exception record against its canonical original definition.

## Native constructor

`teleport_volume_constructor.cpp` reconstructs the 260-byte constructor at `800C75EC..800C76F0`, plus all 88 exception-table and 12 index bytes. The native derived constructor calls the original Agent constructor, installs the original external virtual table, constructs four typed handles, copies the default positions/quaternion, and clears the observed flags and indices. The constructor and virtual table now use canonical `TeleportVolume` compiler identities.

Declaring the actual virtual destructor makes the compiler write the derived virtual table after the base constructor and before member initialization. The virtual table and undefined methods remain original fallback: the compiler emits no table or helper bodies in this fragment. The retained prefix and member declarations are ABI views; the complete original class interface is not claimed. All allocated bytes and 17 relocations pass the strict Teleport inventory verifier. No instruction or exception-metadata editing is involved.

The constructor is linked from source and passes full-DOL equality, native objdiff code/data checks, and the preserved original-source regression audit.

Further table-read probes for the larger transition handler are preserved in `try_choice_order.py`, `try_choice_types.py`, and `try_choice_views.py`. Distinct record views can recover either indexed load separately, but the complete sequence still differs; the larger handler remains uncredited.

## Native destructor

`teleport_volume_destructor.cpp` reconstructs the native 564-byte destructor at `800C76F0..800C7924`, all 88 exception-table bytes, and its 12-byte index record. It assigns scoped empty typed handles to three references, resets transform/state fields, destroys four typed members and the original Agent base, and frees storage through the game allocator when the compiler-generated deleting flag requests it. Ordinary inherited destructors and a `throw()` deallocator reproduce the original cleanup and exception-specification records.

This fragment uses an explicit ABI view of the virtual pointer at offset eight and restores the original external `TeleportVolume` table. The constructor's virtual interface view and this destructor's observed storage view are partial reconstructions; the complete class declaration, RTTI and 160-byte virtual table remain original data. No replacement virtual table or instruction sequence is emitted as data.

The compiler also emits weak definitions of the three already recovered typed-handle destructors at `80020B90`, `8001FF78` and `8002B67C`. `scratch/game_teleport_destructor/verify.py` resolves every emitted byte, including all three helper bodies and their exception/index records, at their canonical original addresses. All helpers match their existing definitions; they add no duplicate progress. The main destructor has 34 retained relocations. The complete DOL and native objdiff checks pass.

## Begin-transition handler research

The other large handler at `800C8060..800C8900` is now semantically reconstructed in `scratch/game_teleport_begin/copy_correct.cpp`. Its 2,204-byte main body remains four bytes short of the original 2,208, with additional bounded register/temporary differences. Event dispatch, nested reference lookups, transform/state changes and the real handle-copy lifetimes are present. `scratch/game_teleport_begin/README.md` records the unresolved parent-index reuse, binding-handle temporary placement and later register lifetimes. This draft and the `800C8900` draft remain unregistered and earn no source credit.
