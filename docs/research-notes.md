# Historical research notebook

Preserved from the previous README on 2026-09-07. Build status and some early
hypotheses below are historical. See [current progress](../PROGRESS.md) and
[newer unit notes](notes/) for verified updates.

# SpongeBob SquarePants: Revenge of the Flying Dutchman (USA) - GSQE78

Reverse engineering workspace for the GameCube dev master disc.

## Disc layout (non-standard!)

The disc header's boot-info fields differ from the standard GCN layout:

| Offset | Value     | Meaning                                   |
|--------|-----------|-------------------------------------------|
| 0x420  | 0x1EC00   | Main executable (DOL) file offset         |
| 0x424  | 0x316000  | FST offset                                |
| 0x428  | 0x2722    | FST size                                  |
| 0x42C  | 0x2722    | FST max size                              |
| 0x430  | 0x803FD8C0| FST load address (RAM)                    |

The apploader (at 0x2440, dated 2002/09/05) was reverse-engineered to
confirm this mapping (state machine at 0x81200728; states 5-9 read the FST
and the custom executable).

## Main executable (custom DOL format)

The executable at 0x1EC00 uses a CUSTOM 18-section header instead of the
standard DOL header:

```
+0x00: u32 text_offsets[7]
+0x1C: u32 data_offsets[11]
+0x48: u32 text_addrs[7]
+0x64: u32 data_addrs[11]
+0x90: u32 text_sizes[7]
+0xAC: u32 data_sizes[11]
+0xD8: u32 bss_addr
+0xDC: u32 bss_size
+0xE0: u32 entry
```

- Entry point: 0x80003140
- Text: 2 sections (0x80003100, 0x8001F2C0), Data: 8 sections,
  BSS at 0x802F3460
- Note: data sections 6/7 load INSIDE the bss range (dev-build quirk)

`extracted/main.dol` is a conversion to the standard DOL format
(18 sections reordered, offset by the redundant 0x100-byte custom header
which was stripped).

## FST (file system table)

- 426 entries, 12 bytes each
- Root "next" field is an entry COUNT (not last-index like standard GCN)
- Type bits INVERTED vs standard: type=1 = directory, type=0 = file
- Dir children = entries (i+1) .. (next-1); parent fields are unreliable
- String table names are offset-0 based (root dir itself is named "enums")

## Extracted files (338 files, `extracted/files/`)

```
enums/                  (root dir name)
  game/, engine/        C source headers left on disc! (Sound_Symbol_Game.h,
                        Anim_Symbol_Game.h, ABC_Message_Game.h ...)
  LevelTSC/             TSC script files (lvl_*.tsc, Init.tsc, Script.tsc ...)
  Speech/English/       voice lines: VO_*.txt (subtitles) + vo_*.sgc (audio)
  DATA/                 TotemTech level data: *.DGC (binary) + *.NGC (text refs)
                        per level: DN, GL, CA, JF, DG, TD, BB + COSTUMES + menus
  DB/movies/            *.h4m (THQ video), nicklogo.thp
  Music/                *.WAV (48kHz stereo PCM)
  Costumes/             AddJF.tsc etc. (costume scripts), radar.bin
  EXTRAS/               Gallery/Hints/Opening/Trailer.tsc + save icon
  thpdemo/, axdemo/     Nintendo AX SDK demo data (dev disc leftovers)
```

## Engine

- **TotemTech v1.73** - Kalisto Entertainment (c) 1999-2002
  (SPONGE.DGC header; embedded source comments in the executable)
- **TSC** = plain-text scripting language (CRLF):
  `OpenBF`, `LoadMap`, `SetGame`, `SetDBPath`, `InitEnumFiles`,
  `LoadMaterialLib`, `LoadObjectLib`, `CameraAgent`, `SBSetCostume` ...
- **.DGC** = TotemTech binary data files
  **.NGC** = resource lists with hashed names
  (`1311518683 "MATERIALOBJ"`, `-1942719122 "DB:>LEVELS>..."`)

## Ghidra project

- `ghidra_project/rotfd` - analyzed program "main.dol"
  - PowerPC:BE:32:default, image base 0x80000000
  - 7,542 functions decompiled
- `decomp/all_functions.c` - decompiled C for every function (~10 MB)
- `ghidra_scripts/SetupDol.java` - pre-analysis script that rebuilds the
  DOL memory layout (uses the importer's FileBytes so it persists on save)
- `ghidra_scripts/ExportDecomp.java` - dumps all decompiled functions

### Rebuilding the project

```
analyzeHeadless ghidra_project rotfd \
  -import extracted/main.dol \
  -loader BinaryLoader -processor "PowerPC:BE:32:default" \
  -overwrite -analysisTimeoutPerFile 1200 \
  -scriptPath "$PWD/ghidra_scripts" \
  -preScript SetupDol.java \
  -postScript ExportDecomp.java "$PWD/decomp/all_functions.c"
```

## Live memory inspection (Dolphin, macOS)

Memory access goes through a small dylib (`memserver.c`) injected into the
debuggable Dolphin copy via `DYLD_INSERT_LIBRARIES`. It serves the process's
OWN memory over the GDB remote protocol on localhost - no root, no
`task_for_pid`, read AND write. From the client side it is indistinguishable
from Dolphin's built-in GDB stub (which official macOS builds compile but
never activate - the `Core.cpp` call sites are `#ifdef`'d out).

- One-time setup: `./make_debuggable_dolphin.sh` copies `/Applications/Dolphin.app`
  to `~/Applications/Dolphin-debug.app`, re-signs the copy with
  `get-task-allow` + `cs.allow-dyld-environment-variables`
  (`dolphin_debug.entitlements`), and compiles/installs the server via
  `install_memserver.sh`. If the copy already exists, run
  `./install_memserver.sh` directly (also after changing `memserver.c`;
  Dolphin must be quit first - it re-signs the app)
- Start Dolphin with `./launch_dolphin.sh`; look for
  `[gcwatch] memserver listening on 127.0.0.1:55556`. MEM1 is readable only
  once the game has booted; the server re-scans for it automatically
- `gcwatch.py` - memory inspector, **no sudo**. Three UI levels, all share
  the same pinned-array config (`gcwatch.json`) and speak the same protocol:
  - **No-terminal flow**: double-click `gcwatch_gui.command` after the game is
    running. Global hotkeys while you play: **8** = mark ("start listening"),
    **9** = list everything that changed since the mark (named: `Global1`,
    `WorldVar1`, ...), **7** = clear noise (everything that moved so far is
    discarded and listening restarts from now - press it right before the
    moment you care about, e.g. just before touching an object), **0** = full
    reset. Buttons do the same with the mouse.
    Hotkeys need Accessibility permission for your terminal app
    (System Settings -> Privacy & Security -> Accessibility); the buttons
    always work. `python3 gcwatch.py gui --mark-key '<f7>' ...` rebinds keys
    (use this if 8/9/0 collide with your game controls)
  - **HUD flow**: `locate` (auto-pins the Global/WorldVar/LevelVar arrays
    from the save's known values - one command, no in-game action) then
    `overlay --log` (always-on-top named table plus a CSV of EVERY change).
    Afterwards `logfind --top/--addr/--seq` analyzes the log
  - **Expert flow**: `python3 gcwatch.py shell` (scan / setbase / watch /
    poke / read / resume / regions)
  Multiple clients can connect at once, so a poke works while the GUI/HUD
  runs. Variable names come from `ENUMS.PYC`
- `gdbstub.py` - the GDB remote-serial-protocol client gcwatch uses
- Port is 55556 by default: on this machine the Cisco Secure Client socket
  filter vetoes bind() on 55555 (`EADDRINUSE` with nothing listening).
  Override with `$GCWATCH_PORT` / `.gcwatch_port` if it collides again
- The mach-read fallback (`sudo python3 gcwatch.py ...`) is still in the code
  but no longer needed
- `VARS.md` - procedure for locating the three arrays. They are not resolvable
  statically: the API name strings in the DOL have no code or data references,
  because the Python method table is built at runtime

## Matching decompilation (dtk / CodeWarrior)

Goal: rebuild `main.dol` byte-identically from C/C++ (dtk-template layout on
top of the analysis above). Status: infrastructure green, 5/8803 functions
matched (the two Metrowerks runtime TUs).

- Fixed DOL: `gcm_extract.py` now emits a TRUE standard DOL header
  (sha1 `5da8295a79bf297ab62c620e6ac66210be1c6ef5`); golden copy lives in
  `orig/GSQE78/main.dol`
- Toolchain: `tools/dtk` (v1.8.3), `tools/objdiff-cli`; CodeWarrior GC
  1.0-3.0a5.2 auto-downloaded to `build/compilers/` and run through
  `build/tools/wibo` (works natively on this arm64 Mac)
- Build: `python3 configure.py --dtk tools/dtk --objdiff tools/objdiff-cli`
  then `ninja` (splits DOL into 3617 objects, compiles matched TUs, relinks,
  SHA-checks against `config/GSQE78/build.sha1`)
- Dev-build lcf quirk: `_db_stack_addr = _stack_addr + 0x200000` (2 MB TRK
  reservation, not the retail 0x2000) - encoded in `config/GSQE78/ldscript.tpl`;
  without it exactly 8 bytes (4 lis/addi pairs) mismatch
- Runtime match: `src/Runtime.PPCEABI.H/{global_destructor_chain.c,
  __init_cpp_exceptions.cpp}` = Melee-era layout (three refs declared in the
  exceptions TU + a duplicate dtor ref from the chain TU); function ORDER in
  file must follow the binary (destroy before register; GetR2, fini, init)
- TU discovery: dev disc left 230 original source filenames in the binary;
  `python3 tools/map_source_strings.py` maps them to referencing functions via
  relocations -> `config/GSQE78/filemap.json` (TotemTech engine, SDK, and the
  whole embedded Python interpreter at ~0x80136000-0x80190xxx)
- Embedded Python: Kalisto-modified CPython ~1.5/1.6 (unicodeobject.c present!);
  reference sources in `reference/cpython-1.5.2/` (Objects/, Python/, Include/).
  Note PyTuple_GetItem INCREFs in this build (vanilla 1.5.2 does not)
- Compiler version PROBED: `python3 tools/version_probe.py` compiles the
  verbatim CPython 1.5.2 `tuplehash` (found at 0x801647AC) with every CW
  version and diffs against the original: **GC 1.3.2 .. 2.6 are byte-identical,
  1.1/1.2.5 and 2.7+ ruled out** (working default: GC/2.0, MWVER=... overrides)
- Kalisto game-code flags (required to kill the `subi;cmpwi`->`subic.`
  peephole fusion): `-proc gekko -fp hardware -enum int -str reuse -common off
  -opt level=4,nopeephole -inline auto`
- tupleobject.c TU layout decoded from data: tuple_as_sequence @0x802D67B0
  (has an 8th Kalisto-added sq_contains slot!), PyTuple_Type @0x802D67D8 with
  tp_compare=NULL, tp_name in .sdata, + Kalisto-ext slots at +0x5C/+0x64;
  fn map: dealloc=fn_80164A24 print=fn_8016494C repr=fn_80164840
  hash=tuplehash(0x801647AC) item=tupleitem(0x801646AC) slice=fn_80164510
  concat=fn_80164408 repeat=fn_80164324 contains=fn_80164710, strings
  @0x802D6844+ live in .data (no -str readonly)

- Note: function-level splits fail when TU-local (static) fns are referenced by
  un-split TU data (PyTuple_Type->tp_hash) - TUs must match whole (text+data)

### Workflow to match a TU (playbook)
1. Pick TU; identify extent: text via fn addresses + filemap.json anchors,
   data via type objects/string pools in .data (dump RAM region, read structs)
2. Rename symbols in symbols.txt (fn_XXXX -> real names; verify sizes via
   neighbors or you get "overlaps" errors)
3. Add ranges to config/GSQE78/splits.txt (text+data+rodata+sdata as needed)
4. Write source in src/<path> (K&R CPython style; check reference/cpython-1.5.2)
5. Add Object(Matching, "<path>") to a lib in configure.py with game cflags
   (per-object mw_version= / cflags= overrides supported)
6. `python3 configure.py --dtk tools/dtk --objdiff tools/objdiff-cli && ninja`
   - iterate on link errors (rename more symbols), then byte-diff the region
7. Compare: `python3` byte-diff of orig vs build at the TU's file offsets, or
   objdiff GUI/CLI per function
- Known identities: PyTuple_Type@0x802D67D8 (tp_compare=NULL, +0x5C/+0x64
  Kalisto slots=fn_80164290/fn_80164020), tuple_as_sequence@0x802D67B0
  (8 slots incl Kalisto sq_contains), PyMethod_Type@0x802D4280,
  moduleobject.c strings @0x802D42EC+, tuple strings @0x802D6844+,
  PyErr_SetString@0x801911B0, PyObject_Hash candidate=fn_80157628,
  tuple functions: dealloc=fn_80164A24 print=fn_8016494C repr=fn_80164840
  slice=fn_80164510 concat=fn_80164408 repeat=fn_80164324 contains=fn_80164710
- Embedded Python is ~1.6 (exceptions doc string, unicodeobject.c present)

### moduleobject.c fully identified (next match target)
- .text 0x80155C4C..0x80156580 (binary fn order != vanilla source order):
  fn_80155C4C module_setattr | fn_80155D98 module_getattr | fn_80155EC4
  module_repr (inlines GetFilename: "__file__" + "module filename missing") |
  fn_80156024 module_dealloc (compiler-INLINES _PyModule_Clear!) | fn_801561EC
  _PyModule_Clear | fn_8015636C PyModule_GetName | fn_801563F0 PyModule_GetDict
  (vanilla verbatim, __LINE__=41) | fn_8015643C PyModule_New (malloc+PyObject_Init)
- PyModule_GetFilename does NOT exist; PyModule_Type @0x802D4280,
  .data range 0x802D4280..0x802D4404; extension slots: +0x54=0x6B, +0x5C=fn_80155C0C
- Kalisto deviations from vanilla 1.5.2 found so far:
  * getattr/setattr error: PyErr_Format(PyExc_AttributeError,
    "'%.50s' module has no attribute '%.400s'", PyModule_GetName(m), name)
    (with inlined GetName incl. "nameless module" path)
  * PyModule_New uses malloc()+PyObject_Init instead of PyObject_NEW macro
  * PyString_Type @0x802D6030, strcmp=fn_801283A8, PyDict_GetItemString=fn_8013E580,
    PyDict_SetItemString=fn_8013E2FC, PyDict_DelItemString=fn_8013E14C,
    PyDict_Next=fn_80140620, PyDict_SetItem=fn_80140948, PyString_AsString=fn_80163858,
    PyString_FromString=fn_80163AB0, PyDict_New=fn_80141230, PyErr_Format=fn_8018FC28,
    PyErr_SetString=0x801911B0, PyErr_BadArgument=fn_80190718, PyErr_Clear=fn_80190870,
    PyErr_BadInternalCall(...)=fn_80190194 (fmt "%s:%d: bad argument to internal
    function"), PySys_WriteStderr=fn_801A26A8, Py_None via sdata (r13-0x5BB0),
    malloc=fn_8001F2C0, free=fn_8001F35C
- Iteration tool: `python3 tools/compile_probe.py src.c 0xADDR 0xSIZE --func NAME`
  (validated: tuplehash 34/37 words, remaining 3 = bl relocations)

## Tooling notes

- Ghidra 12.x removed the GameCube DOL loader; import as raw binary and
  reconstruct blocks with SetupDol.java (FileBytes created via the script
  API do NOT persist across saves - reuse the importer's FileBytes!)
- wit (Wiimms ISO Tools) crashes on this disc (exit 137)

## DGC bigfile format (CRACKED!)

The `.DGC` files use the "BigFile" container format:
- `0x000-0x100`: "TotemTech Data v1.73..." magic header
- u32 @ 0x100: directory size (33 blocks of 0x800, = 0x10800 stride)
- File entries scattered as a hash table, each = 85-byte records:
  `[u32 type_hash][u32 file_hash][u32 file_hash][u32 data_size][data...]`
- Record type hashes match the `.NGC` manifest hashes (e.g. `0x09C82847` = "MATERIALANIM")
- Files inside: Python 1.5 bytecode (.PYC), RTC scripts (.TRTC), textures, etc.

### Embedded Python (Kalisto-modified Python 1.5)

- Per-level AI/event logic in `DB:>SCRIPTS>LVL_*>PYTHON/*.PYC` (inside level .DGC)
- Custom marshal: code object = `'c' + 4x u16 (argcount,nlocals,stacksize,flags) + 's' + u32 len + code + consts + names + varnames + freevars + cellvars + filename + name + u16 firstlineno + lnotab`
- Floats marshalled as `'f' + u8 len + repr string`; instructions are 3 bytes (opcode + u16 arg)
- Extraction: `extract_pycs.py` -> `pycs/` (raw marshal blobs)
- Decompilation: `decomp_pycs.py` -> `python_src/*.py` (readable!):
  - `LIBPYTHON.PYC` (434 methods - the CSimpleAgent API/runtime)
  - `LVL_AGENT.PYC` - level progression state machine (WorldVar/LevelVar/Global flags,
    task system via ScriptTaskCreate, delivery quest, teleport volume gating)
  - `EELTHUG*.PYC` - enemy AI (distance-threshold states, Local0/Local1 flags)
  - `SANDY/PATRICKDB/MRKRABS/FERALSNAIL/SCRIPT_MANHOLE` - character agents
  - `ENUMS.PYC` - WorldVar/LevelVar/Global/State enum definitions

## Treedome early-entry analysis (speedrun research)

Levels: TDGL = treedome ground floor, TDUR = treedome upstairs/karate area
(both inside LVL_TD*.DGC; agents in python_src_all/TD*_*.py)

> NOTE: `decomp_pycs.py` flattens ALL branches to indent level 0, so its output
> cannot distinguish "gated by the condition above" from "sibling of it".
> Use `nest_pycs.py <file.PYC> [Method]` instead - it reconstructs nesting from
> the JUMP_IF_FALSE targets. Several conclusions below were wrong until it existed.

### Variable scoping (confirmed)
- `GlobalN`/`WorldVarN`/`LevelVarN` enums are plain array indices (Global1 == 1 etc.)
- **Globals** = whole save file. Global1 is referenced ONLY by TD\* and BBEX scripts
- **WorldVars** = per two-letter world (TD, BB, GL, JF, DN, CA, DG), shared across
  its sub-levels. TDGL and TDUR share WorldVar1/2/14/…; the same WorldVar2 means
  something completely different in GL/DG/CA
- **LevelVars / Locals** = per level load, NOT persisted (so `LocalN == 0` guards
  re-arm on every reload)

### The Global1 progression chain (main quest gates)
- Global1 == 1: start (BBEX SQUIDCHAIR, first talk)
- Global1 == 2: BBEX SQUIDCHAIR: `SDCount >= 200` then `SDCountInc(-200)` - jar spawns
- Global1 == 3: BBEX LVL_AGENT EnterVolume: `VOL_TELEPORT_TDGL` + carrying HIVEJAR
- Global1 == 4: TDGL SCRIPT_SANDY_SWIM Think - **see the bypass below**
- Global1 == 5: TDUR BEEHIVE_SCRIPT (belly-slam the beehive)
- Global1 == 6: TDUR SCRIPT_SANDY_SWIM - karate unlocked (SC_KARATE_SANDY active)

Global1 is only ever *set*, never incremented, at 7 sites total; 4 is the sole
entry point to everything above it.

### Global1 >= 4 is the single gate on ALL wasp/bee content
- TDGL WASP1-4 `Init`: `if Global1 < 4: SetVisible(FALSE); CharSuspend(self)`
  and `Think` is wrapped in `if Global1 >= 4`
  (an earlier version of this file wrongly listed the ground-floor wasps as ungated)
- TDUR BEE1-8 `Init`: same `if Global1 < 4` suspend
- TDUR BEEHIVE_SCRIPT `Init`: visible only on `Global1 == 4` exactly

### The Global1 = 4 write is NOT gated on the honey jar
`TDGL_SCRIPT_SANDY_SWIM.Think`, verified against raw jump targets
(the HIVEJAR branch at bytecode 285 lands at 438; the SCRIPT_OBJ_2 test starts
at 449, so it is a **sibling** of the jar check, not a child of it):

```
if LevelVar40 == 1:                        # set by Message 905 = "cutscene over"
    if WorldVar2 == 0:                     # only ever set by RTCEnd(420), i.e. after this
        ...
        if HeroCarryingObj('HIVEJAR'):     # <- this whole branch closes at 438
            if WorldVar1 == 10 and Global1 == 3 and Local0 == 0:
                PlayVoiceOver(400)         # just a voice line
        if DistanceToObject('SCRIPT_OBJ_2') < 1.0:      # <- starts at 449, sibling
            if Local3 == 0:
                SetCollideable(FALSE); SetVisible(FALSE); KeyframeAnim(STOP)
                PlayVoiceOver(420)
                GlobalSet(Global1, 4)      # <-- no jar, no Global1 == 3 check
```

Everything else in that chain is free on an early visit:
- `WorldVar1 == 10` (persistent) comes from the 10 acorns -> SCRIPT_SANDY reaches
  SCRIPT_OBJ_2 -> `Timer 5` -> `WorldVar1 = 10`. The acorns are ungated
  (STATIC_ACORN Init only checks WorldVar1 itself)
- `WorldVar2` in the TD world is written at exactly one place: `RTCEnd(420)`, the
  cutscene that this very block starts. So it is 0 for the whole early visit
- `Local3`/`Local6` are per-load, so Sandy's entrance re-arms on every TDGL entry
- SCRIPT_SANDY_SWIM is the *active* Sandy exactly when `WorldVar1 == 10` and
  `Global1 <= 3` - i.e. precisely the early-visit state

So the remaining question is purely physical: **can Sandy_SWIM get within 1.0 of
SCRIPT_OBJ_2 without RTC 415?** Normally RTC 410 (HeroGive jar) -> anim_talk_std05
-> AnimEnd -> VO 415 -> `RTCEnd(415)`: `SetTarget(SCRIPT_OBJ_2)` +
`KeyframeAnim(UNPAUSE)` - the UNPAUSE implies her walk path is paused partway.

### TDGL node positions (Y is up)
Extracted from LVL_TDGL.DGC: node records store a 4x4 matrix immediately before
the name hash; **translation = 3 BE floats at (crc32(name) offset - 0x1C)**, with
1.0 at -0x10. Name hash = standard CRC-32 (same as the .NGC manifest).

| node | x | y | z |
|------|------|------|------|
| SCRIPT_OBJ_2 (the trigger) | -35.257 | 0.401 | 8.606 |
| CAMERA_LOOK1 | -35.757 | -1.024 | 7.102 |
| LTILEO2 | -35.136 | -2.215 | 7.963 |
| CAMERA_POS1 | -34.284 | -0.165 | 12.098 |
| FRONTDOOR | -24.121 | -0.113 | -3.967 |
| SCRIPT_OBJ_1 (acorn walk end) | 34.156 | -4.602 | -5.601 |
| END_OF_LEVEL | -19.440 | -0.007 | -0.000 |

FRONTDOOR -> SCRIPT_OBJ_2 is a 16.8-unit walk. Trigger radius is 1.0.

### Still gated
- Honey jar itself: Global1 == 2 needs 200 sand dollars (and spends them)
- Karate tile LTILEG: Global1 == 6 + WorldVar15 == 1
- LTILEE: Global1 == 5 (which needs the beehive, which needs Global1 == 4)

### Other ungated content on an early visit
- WHEEL minigame (TDGL WHEEL_TRIGGER): WorldVar33 == 0 -> 60s timer ->
  LTILEN spawns (WorldVar33=1) -> gather -> **WorldVar33 = 2 (persistent)**
- LTILES: spawns in TDGL once WorldVar1 == 10 -> gather -> **WorldVar3 = 1**
- The bed event (TDUR LVL_AGENT Init): Global21 == 10 -> teleport to BED_MOVER_DUMMY

### Next test (in Dolphin, watch Globals[1])
1. Enter TDGL early via the glitch, collect all 10 acorns, let SCRIPT_SANDY walk
   to SCRIPT_OBJ_2 -> WorldVar1 = 10 (persistent)
2. Leave and re-enter TDGL. SCRIPT_SANDY_SWIM's entrance fires from
   `Think: if WorldVar1 == 10 and Local6 == 0` -> Timer(2.3, 1) -> `KeyframeAnim(START)`
3. Watch whether her keyframe path runs all the way to (-35.257, 0.401, 8.606).
   If it does, Global1 flips 1 -> 4 with no jar and every wasp/bee spawns.
   If it stops at the door, try body-blocking/pushing her the last few units.
