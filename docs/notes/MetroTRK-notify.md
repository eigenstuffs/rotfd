# MetroTRK stop notification

`src/MetroTRK/notify.c` recovers TRKDoNotifyStopped at 0x8011C1F4..0x8011C2CC (216 bytes). The Melee C reference provides the algorithm: allocate a request buffer, append the notification command, add stop or exception information, send the request with acknowledgement retries, and release the request and successful reply buffers. The original overwrites the append result with the request-send result and ignores the target-information helper's return; this behavior is preserved. Local buffer declaration order reproduces the original stack layout. No data or BSS is owned.

GC/1.3.2 with `-proc gekko -fp hardware -enum int -str reuse -common off -O4,p -inline auto,deferred -sdata 0 -sdata2 0 -pool off -use_lmw_stmw on -rostr -i src/MetroTRK -Cpp_exceptions off` reproduces every code byte and relocation. The compile and verification scripts are under scratch/MetroTRK, with exact symbols in the candidate manifest. Full-game equality and native objdiff remain integration checks. Existing shared headers are unchanged.

Reference: https://github.com/doldecomp/melee/blob/master/src/MetroTRK/notify.c. Download hashes are recorded under reference/melee-trk.

The registered source now passes the complete DOL SHA-1, direct byte equality, native objdiff code/data checks and the original-source regression audit.
