# Optional CPython modules present in GSQE78

The original `PyImport_Inittab` pointer at `0x80376EA4` targets the built-in module table at `0x802E95F4`. Reading the original DOL gives:

| Module | Initialization function |
| --- | --- |
| `errno` | `0x801A7628` |
| `new` | `0x801A90E0` |
| `_codecs` | `0x801A96F4` |
| `marshal` | `0x801996D4` |
| `imp` | `0x80195338` |
| `__main__` | NULL, reserved |
| `__builtin__` | NULL, reserved |
| `sys` | NULL, reserved |
| `exceptions` | NULL, reserved |

The next entry is the NULL sentinel. The imported native initialization table does not list `_weakref`, `math`, `array`, `strop`, or `_sre`.

The DOL also contains none of the distinctive `_weakref` module strings checked: `_weakref`, `getweakrefcount`, `ReferenceError`, `weak object has gone away`, and `<weakref at %lx; dead>`. Its `PyObject_ClearWeakRefs` initializer at `0x803762A0` still points to the matched empty callback at `0x801568D8`. This supports treating the CPython 2.1 `Modules/_weakref.c` implementation as absent from the executable.

Presence checks likewise found none of these distinctive strings from the requested optional modules:

- `mathmodule.c`: `math domain error`, `d:acos`, `acos(x)`, and the module documentation prefix `This module is always available.`
- `arraymodule.c`: `array initializer must be list or string`, `array(typecode [, initializer]) -> array`, and the full invalid-typecode error.
- `stropmodule.c`: the terminated module/method names `strop`, `splitfields`, and `joinfields`.

Table omission is supporting evidence, not proof of absence: `Modules/signalmodule.c` is present and explicitly initialized by `PyOS_InitInterrupts`, which calls `initsignal()` and `_PyImport_FixupExtension("signal", "signal")`. It therefore needs no entry in this table.

The `_sre` module name is also absent. These table and string checks guide selection of present code; they do not remove any original functions or bytes from the progress denominator. No candidate units or replacement stubs were created for these absent optional modules.
