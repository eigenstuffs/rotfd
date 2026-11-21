# Mesh transform/reflection dispatch: bounded private reconstruction

`fn_8026D184`, `8026D184..8026D834` (1,712 original bytes), remains original
assembly. Ordinary source/probes are preserved in
`scratch/engine_mesh_transform_update_20261011kg/`; no production source or
matching credit is claimed.

The function updates a nonempty mesh, selects geometry and material handles for
the current context index, chooses one of two resolved matrix references or a
fallback, and dispatches the geometry virtually. A flagged type-3/type-6 path
reflects position, quaternion components and scale, saves the context matrix,
builds and combines the reflected transforms, dispatches again, and restores the
matrix. Full 64-byte matrix copy/assignment temporaries explain much of the
original stack and general-register activity.

Concrete Geometry, Matrix, Material and Object entry views restore the native
manager-entry reload between the first differently typed resolves. The initial
probe reproduces the complete 356-byte resolver/selection/first-dispatch region
`8026D1AC..8026D310`. All ten actual relocation identities/targets are known.
The remaining body does not match: matrix/vector temporary allocation, floating
register scheduling and aggregate-copy scheduling differ. An ordinary
quaternion copy constructor selects floating loads/stores; an aggregate copy
selects integer loads/stores. Both forms are preserved. A translation reference
avoids an extra materialized point, but the compiler retains translation values
where the original reloads them after the transform stores.

The coherent `quaternion_copy.cpp` probe emits one 1,700-byte text allocation,
with ten actual relocations and 321 full-original-word differences including the
12 missing original bytes. Its fresh full object is identical to the frozen
fixture. The original function is not an exact-size match. A separate mirror
helper probe happens to emit a 1,712-byte primary function but additionally emits
and calls a 40-byte weak point-multiply helper; it is also nonmatching and is not
an eligible replacement. No masked relocation score is used.

GC1.3.2 O4,p, exceptions off, lmw/stmw on, FP contraction on was used. Bounded
variants include named normal copies/references, returned/output-reference
points, explicit vector setters, matrix row/common-field views, ordinary mirror
full-expression temporaries, and inline depth/deferred options. No generated
instructions or object payload were patched. The full original EH index and
ctor/dtor tables have no ownership in this range; borrowed globals/literals and
all existing producers/consumers remain unchanged.

`verify_private.py` checks frozen preservation, recompiles the coherent probe,
compares complete symbols/allocations and all actual relocations, and retains the
full mismatch evidence. A first verification-only assumption that the best
quaternion probe retained the initial probe's exact region was rejected and
preserved as `verify_private_v1_region_assumption.py`; the two fixtures are
explicitly distinguished in the final check. All findings remain uncredited.
