# Agent secondary-base adjustor at 80062D98

The native compiler now supplies the eight-byte secondary-base adjustment at
`80062D98..80062DA0`. It subtracts 96 from `this` and branches to the existing
56-byte control delegate at `80061ED4`. The source uses the observed C++ virtual
method and multiple inheritance layout; the compiler emits the adjustor.

The unchanged partial class view was extracted into
`include/Game/agent_owner_virtual_view_80061AC0.h`. The whole existing
`agent_owner_virtual_methods_80062A14.o` remains byte-identical. The delegate
becomes `AgentVirtualView_80061AC0::method_80061ED4`, with its complete object
changing only that function's identity. Its 56 code bytes and 20 exception
bytes remain exact. All used undefined symbols have GLOBAL binding.

The caller audit covers all 6,875 active linker inputs, all original immediate
branches and every initialized original data byte position. The old C function
name had no external source callers. The original function-pointer roots are
its own exception index and the primary and secondary entries of the external
304-byte table at `802B6140`.

Only eight new code bytes and one function are credited. The existing 900 code
bytes and 236 exception bytes remain owned by the MI source unit. The original
304-byte table remains outside source ownership. The compiler's partial
200-byte table, unused adjacent adjustors and weak Handle backups retain their
existing discard or strong-provider handling. The adjacent `80062DA0` method
adjustor and `80062DA8` destructor adjustor remain original.

The frozen private handoff is
`scratch/resource_finder_inline_20261020/agent96_remaining_methods/`; use its
`exact-overlay/` payload, not its separate unsuccessful companion experiment.
The production integration and complete object/native checks are recorded in
`scratch/agent96_adjustor_integration_20261020/`. The standard DOL hash, baseline
regression comparison, source extent audit and tooling tests are acceptance
gates. Historical receipts are preserved separately from current successors.
