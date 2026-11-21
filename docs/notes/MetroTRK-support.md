# MetroTRK host file support

`src/MetroTRK/support.c` recovers all five linked C functions at 0x8011B940..0x8011C1DC (2,204 bytes). No initialized data or BSS is owned.

The [Melee support source](https://github.com/doldecomp/melee/blob/master/src/MetroTRK/support.c) supplies segmented file transfers and the send/wait/retry loop. Open, close and position request helpers follow the [Pikmin 2 source family](https://github.com/projectPiki/pikmin2/blob/main/src/Dolphin/TRK_MINNOW_DOLPHIN/support.c), with the target's earlier serialized protocol recovered directly from its original instructions. This target sends a one-byte command and compact parameters, then reads a one-byte I/O result. Its seek helper accepts the position by value and does not return an updated position. The newer reference's fixed-size packet header is absent.

Transfers use chunks of at most 2,048 bytes. The reply logic preserves the original malformed-length handling, partial transfer results and buffer cleanup. Interactive reads from handle zero disable the polling timeout; other requests use the original bounded loop and retry limit. Separate named read/write minimum reply lengths both evaluate to 5 in this protocol. A local interactiveRead value is evaluated after initializing reply fields; this ordinary C boundary reproduces the original register allocation. The reference's comma-expression matching workaround is not included.

GC/1.3.2 with `-proc gekko -fp hardware -enum int -str reuse -common off -O4,p -inline auto,deferred -sdata 0 -sdata2 0 -pool off -use_lmw_stmw on -rostr -i src/MetroTRK -Cpp_exceptions off` reproduces every function and all relocations. The private protocol header is reused read-only; no integrated source or shared header was changed. The compile and relocation-verification scripts are under scratch/MetroTRK, and the complete function list is in config/GSQE78/candidates/MetroTRK-support.json. Full-game equality and native objdiff are integration checks.

The registered source now passes the complete DOL SHA-1, direct byte equality, native objdiff code/data checks and the original-source regression audit.
