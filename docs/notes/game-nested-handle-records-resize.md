# Nested Handle record array resize

Accepted matching source: the production build passes the original DOL hash,
strict allocated-byte/extent and actual-relocation checks, baseline regression
checks, generated progress verification and all 26 repository tests.

Isolated ordinary C++ source for `fn_801AD438`, original text range `801AD438..801AD678`, matches all 576 retained bytes and 22 actual relocations with GC 1.3.2, Gekko, `-O4,p`, exceptions off. Two fresh strict production recompiles pass. Final native placement, original DOL hash and regression acceptance remain with the root integrator.

The 16-byte records contain a two-byte key followed by a 12-byte array of 8-byte retained Handle elements. Growth reserves when capacity is too small or retention is disabled, placement-constructs the new records, and updates count. Shrink destroys nested Handle arrays backward, retains capacity when requested, and otherwise resizes allocation to the new count. A genuine key base initializes before the nested array; the two inline Handle layers reproduce the original null checks and native base destructor calls. No register forcing or assembly is used.

The compiler also emits one unused 212-byte weak backup, `__dt__52NestedHandleResizeArray<25NestedHandleResizeElement>Fv`, with five actual relocations. Its binding, complete bytes, extent and relocation targets are frozen. No retained text or exception metadata refers to it. Both final native ELF/map outputs must show the entire backup absent; these bytes receive no matching credit. The primary owns no data, BSS, padding, EH or startup allocation.

Preflight resolves the current original C symbol and scans 1,665 canonical manifests plus 43,482 C/C++/header files for prior ownership. The stable input snapshot scans 5,584 objects, 119,086 actual relocations and all 777,360 initialized words; original definition is sole and GLOBAL, no aliases or initialized data pointers overlap, and the private weak backup is absent from all inputs. The original DOL contains one direct caller at `801AD1D0` within the same original assembly unit. Existing source consumers and identifier migrations are absent.

The full original extabindex range `80015F60..8001F2C0`, including its descriptor, constructor table `80299920..80299980`, and destructor table `80299980..802999A0` have no references to this extent. Frozen handoff: `scratch/game_engine_batch242/manifest-list.json`; source, complete allocated-section proof and original ownership inventories: `scratch/game_nested_handle_records_resize_801ad438/`. The root integrator must repeat fresh active/native ownership after configuration.
