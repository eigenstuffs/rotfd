# Owner motion timing

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Three independent units recover random resource notification, timed control selection and scaled velocity integration. The manifest list is `scratch/game_owner_motion_timing/manifest-list.json`; all three consumers of the new frozen `include/Game/owner_motion_timing_views.h` are verified. GC1.3.2 uses standard optimization with extra `['-Cpp_exceptions on']` for each.

| Source | Text | extab | extabindex |
| --- | --- | --- | --- |
| `src/Game/owner_resource_random_notify_8009c304.cpp` | `8009C304..8009C400` (252) | `8000F9DC..8000F9E4` | `8001B0E4..8001B0F0` |
| `src/Game/owner_control_elapsed_8009d42c.cpp` | `8009D42C..8009D4F4` (200) | `8000FB44..8000FB4C` | `8001B1D4..8001B1E0` |
| `src/Game/owner_velocity_integrate_8009d6f4.cpp` | `8009D6F4..8009D7C4` (208) | `8000FB54..8000FB5C` | `8001B1EC..8001B1F8` |

The resource callback resolves the agent owner handle, clears flag `0x20000`, then selects notification one, seven or eight from the existing integer selector's result zero, one or two. The signed integer complement in the 64-bit flag update reproduces both original flag-word stores.

The timed callback runs the base update, accumulates delta at `0x3BC`, and checks the existing threshold while control one or zero is active. On expiry it assigns the external reset value, chooses zero or one, and optionally calls the secondary update before setting control one; otherwise it sets control zero.

The velocity function calls an initial update when high flag `0x80` is absent, then always runs the movement update. It assigns `base + (movement / scale) * delta` to velocity. Ordinary inline vector operators preserve the native temporary at stack eight. Division computes one reciprocal then directly constructs the three multiplied components; introducing another multiplication operator layer changed only register allocation and was superseded by the exact direct form.

Strict verification proves all720allocated bytes: 660 text and60exception/index bytes. Each source emits exactly one function and extab8/index12 with actual local ELF names. All18actual text relocations (three SDA), six EH-index references and three nonallocated metadata references are audited. Full original DOL SHA1 and complete exception/constructor/destructor ownership table checks pass. Original floats/context remain external; no data/BSS, weak helper, padding or original gap ownership is claimed. Full executable acceptance remains centrally owned.
