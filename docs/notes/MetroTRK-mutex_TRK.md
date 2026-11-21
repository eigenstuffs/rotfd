# MetroTRK mutex adapters

`src/MetroTRK/mutex_TRK.c` recovers all three linked adapters at 0x8011C1DC..0x8011C1F4 (24 bytes). TRKReleaseMutex, TRKAcquireMutex and TRKInitializeMutex each originally return kNoError without accessing the supplied pointer. This target's lack of synchronization is corroborated by the complete Melee C reference; these are original release implementations, not placeholders for unfinished functions. Callers in the event and message-buffer units independently establish their identities. No data or BSS is owned.

GC/1.3.2 with `-proc gekko -fp hardware -enum int -str reuse -common off -O4,p -inline auto,deferred -sdata 0 -sdata2 0 -pool off -use_lmw_stmw on -rostr -i src/MetroTRK -Cpp_exceptions off` reproduces every code byte and relocation. The compile and verification scripts are under scratch/MetroTRK, with exact symbols in the candidate manifest. Full-game equality and native objdiff remain integration checks. Existing shared headers are unchanged.

Reference: https://github.com/doldecomp/melee/blob/master/src/MetroTRK/mutex_TRK.c. Download hashes are recorded under reference/melee-trk.

The registered source now passes the complete DOL SHA-1, direct byte equality, native objdiff code/data checks and the original-source regression audit.
