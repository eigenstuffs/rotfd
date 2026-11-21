# Platform I/O compatibility

`src/Platform/python_io.c` reconstructs the three original compatibility routines immediately after the native Python code: `unlink` at `0x801AC7D8` (8 bytes), `isatty` at `0x801AC7E0` (24 bytes), and `fileno` at `0x801AC7F8` (4 bytes). The original translation-unit filename is unknown; the repository path describes its purpose rather than claiming an upstream source identity.

The original port uses a stream pointer as its integer file descriptor. `fileno` returns that unchanged pointer value, and `isatty` compares it with the first entry in the MSL `__files` array, standard input. `unlink` returns zero without acting on the pathname. These are observed original semantics, not substitute implementations to increase progress.

All 36 bytes compile exactly using GC/2.0 with the verified runtime flags. `scratch/python_io/verify.py` resolves the sole external data reference to `__files` and compares all instructions with the original DOL, reporting `TEXT 36 36`. The unit owns no data. At `0x801AC7FC` the executable resumes game object code, which is outside this native Python support group.
