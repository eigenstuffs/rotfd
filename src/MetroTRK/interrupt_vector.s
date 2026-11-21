# MetroTRK exception vector image (__exception.s), GSQE78.
#
# The debugger kernel copies these 0x100-byte vectors over the Gekko
# exception vectors (TRK_copy_vector / __TRK_copy_vectors).  Offset 0 holds
# the kernel banner and offset 0x100 restarts the kernel.  Every other active
# vector saves r2-r4 in SPRG1-3, re-enables address translation in SRR1 and
# enters TRKInterruptHandler with the vector offset in r3; the software
# table-walk vectors first leave the temporary GPR set.  MetroTRK assembles
# this file with mwasmeppc; it is reconstructed in that assembler's syntax.

	.extern TRKInterruptHandler
	.extern __TRK_reset

	.section .init,4,x
	.global gTRKInterruptVectorTable
	.global gTRKInterruptVectorTableEnd
	.type gTRKInterruptVectorTable,@function

gTRKInterruptVectorTable:
	.ascii "Metrowerks Target Resident Kernel for PowerPC"
	.align 4

	.org 0x100                    # system reset
	b __TRK_reset

	.org 0x200                    # machine check
	mtsprg 1, r2
	mfsrr0 r2
	icbi r0, r2
	mfdar r2
	dcbi r0, r2
	mfsprg r2, 1
	mtsprg 1, r2
	mtsprg 2, r3
	mtsprg 3, r4
	mfsrr0 r2
	mfsrr1 r4
	mfmsr r3
	ori r3, r3, 0x30            # MSR[IR|DR]
	mtsrr1 r3
	lis r3, TRKInterruptHandler@h
	ori r3, r3, TRKInterruptHandler@l
	mtsrr0 r3
	li r3, 0x200
	rfi

	.org 0x300                    # DSI
	mtsprg 1, r2
	mtsprg 2, r3
	mtsprg 3, r4
	mfsrr0 r2
	mfsrr1 r4
	mfmsr r3
	ori r3, r3, 0x30            # MSR[IR|DR]
	mtsrr1 r3
	lis r3, TRKInterruptHandler@h
	ori r3, r3, TRKInterruptHandler@l
	mtsrr0 r3
	li r3, 0x300
	rfi

	.org 0x400                    # ISI
	mtsprg 1, r2
	mtsprg 2, r3
	mtsprg 3, r4
	mfsrr0 r2
	mfsrr1 r4
	mfmsr r3
	ori r3, r3, 0x30            # MSR[IR|DR]
	mtsrr1 r3
	lis r3, TRKInterruptHandler@h
	ori r3, r3, TRKInterruptHandler@l
	mtsrr0 r3
	li r3, 0x400
	rfi

	.org 0x500                    # external interrupt
	mtsprg 1, r2
	mtsprg 2, r3
	mtsprg 3, r4
	mfsrr0 r2
	mfsrr1 r4
	mfmsr r3
	ori r3, r3, 0x30            # MSR[IR|DR]
	mtsrr1 r3
	lis r3, TRKInterruptHandler@h
	ori r3, r3, TRKInterruptHandler@l
	mtsrr0 r3
	li r3, 0x500
	rfi

	.org 0x600                    # alignment
	mtsprg 1, r2
	mtsprg 2, r3
	mtsprg 3, r4
	mfsrr0 r2
	mfsrr1 r4
	mfmsr r3
	ori r3, r3, 0x30            # MSR[IR|DR]
	mtsrr1 r3
	lis r3, TRKInterruptHandler@h
	ori r3, r3, TRKInterruptHandler@l
	mtsrr0 r3
	li r3, 0x600
	rfi

	.org 0x700                    # program
	mtsprg 1, r2
	mtsprg 2, r3
	mtsprg 3, r4
	mfsrr0 r2
	mfsrr1 r4
	mfmsr r3
	ori r3, r3, 0x30            # MSR[IR|DR]
	mtsrr1 r3
	lis r3, TRKInterruptHandler@h
	ori r3, r3, TRKInterruptHandler@l
	mtsrr0 r3
	li r3, 0x700
	rfi

	.org 0x800                    # floating-point unavailable
	mtsprg 1, r2
	mtsprg 2, r3
	mtsprg 3, r4
	mfsrr0 r2
	mfsrr1 r4
	mfmsr r3
	ori r3, r3, 0x30            # MSR[IR|DR]
	mtsrr1 r3
	lis r3, TRKInterruptHandler@h
	ori r3, r3, TRKInterruptHandler@l
	mtsrr0 r3
	li r3, 0x800
	rfi

	.org 0x900                    # decrementer
	mtsprg 1, r2
	mtsprg 2, r3
	mtsprg 3, r4
	mfsrr0 r2
	mfsrr1 r4
	mfmsr r3
	ori r3, r3, 0x30            # MSR[IR|DR]
	mtsrr1 r3
	lis r3, TRKInterruptHandler@h
	ori r3, r3, TRKInterruptHandler@l
	mtsrr0 r3
	li r3, 0x900
	rfi

	.org 0xC00                    # system call
	mtsprg 1, r2
	mtsprg 2, r3
	mtsprg 3, r4
	mfsrr0 r2
	mfsrr1 r4
	mfmsr r3
	ori r3, r3, 0x30            # MSR[IR|DR]
	mtsrr1 r3
	lis r3, TRKInterruptHandler@h
	ori r3, r3, TRKInterruptHandler@l
	mtsrr0 r3
	li r3, 0xC00
	rfi

	.org 0xD00                    # trace
	mtsprg 1, r2
	mtsprg 2, r3
	mtsprg 3, r4
	mfsrr0 r2
	mfsrr1 r4
	mfmsr r3
	ori r3, r3, 0x30            # MSR[IR|DR]
	mtsrr1 r3
	lis r3, TRKInterruptHandler@h
	ori r3, r3, TRKInterruptHandler@l
	mtsrr0 r3
	li r3, 0xD00
	rfi

	.org 0xE00                    # floating-point assist
	mtsprg 1, r2
	mtsprg 2, r3
	mtsprg 3, r4
	mfsrr0 r2
	mfsrr1 r4
	mfmsr r3
	ori r3, r3, 0x30            # MSR[IR|DR]
	mtsrr1 r3
	lis r3, TRKInterruptHandler@h
	ori r3, r3, TRKInterruptHandler@l
	mtsrr0 r3
	li r3, 0xE00
	rfi

	.org 0xF00                    # performance monitor
	b perf_monitor

	.org 0xF20                    # AltiVec unavailable
	mtsprg 1, r2
	mtsprg 2, r3
	mtsprg 3, r4
	mfsrr0 r2
	mfsrr1 r4
	mfmsr r3
	ori r3, r3, 0x30            # MSR[IR|DR]
	mtsrr1 r3
	lis r3, TRKInterruptHandler@h
	ori r3, r3, TRKInterruptHandler@l
	mtsrr0 r3
	li r3, 0xF20
	rfi
perf_monitor:
	mtsprg 1, r2
	mtsprg 2, r3
	mtsprg 3, r4
	mfsrr0 r2
	mfsrr1 r4
	mfmsr r3
	ori r3, r3, 0x30            # MSR[IR|DR]
	mtsrr1 r3
	lis r3, TRKInterruptHandler@h
	ori r3, r3, TRKInterruptHandler@l
	mtsrr0 r3
	li r3, 0xF00
	rfi

	.org 0x1000                   # instruction TLB miss
	mtsprg 1, r2
	mfcr r2
	mtsprg 2, r2
	mfmsr r2
	andis. r2, r2, 0x2           # MSR[TGPR]
	beq tgpr_clear_1000
	mfmsr r2
	xoris r2, r2, 0x2
	sync
	mtmsr r2
	sync
	mtsprg 1, r2
tgpr_clear_1000:
	mfsprg r2, 2
	mtcrf 0xFF, r2
	mfsprg r2, 1
	mtsprg 1, r2
	mtsprg 2, r3
	mtsprg 3, r4
	mfsrr0 r2
	mfsrr1 r4
	mfmsr r3
	ori r3, r3, 0x30            # MSR[IR|DR]
	mtsrr1 r3
	lis r3, TRKInterruptHandler@h
	ori r3, r3, TRKInterruptHandler@l
	mtsrr0 r3
	li r3, 0x1000
	rfi

	.org 0x1100                   # data load TLB miss
	mtsprg 1, r2
	mfcr r2
	mtsprg 2, r2
	mfmsr r2
	andis. r2, r2, 0x2           # MSR[TGPR]
	beq tgpr_clear_1100
	mfmsr r2
	xoris r2, r2, 0x2
	sync
	mtmsr r2
	sync
	mtsprg 1, r2
tgpr_clear_1100:
	mfsprg r2, 2
	mtcrf 0xFF, r2
	mfsprg r2, 1
	mtsprg 1, r2
	mtsprg 2, r3
	mtsprg 3, r4
	mfsrr0 r2
	mfsrr1 r4
	mfmsr r3
	ori r3, r3, 0x30            # MSR[IR|DR]
	mtsrr1 r3
	lis r3, TRKInterruptHandler@h
	ori r3, r3, TRKInterruptHandler@l
	mtsrr0 r3
	li r3, 0x1100
	rfi

	.org 0x1200                   # data store TLB miss
	mtsprg 1, r2
	mfcr r2
	mtsprg 2, r2
	mfmsr r2
	andis. r2, r2, 0x2           # MSR[TGPR]
	beq tgpr_clear_1200
	mfmsr r2
	xoris r2, r2, 0x2
	sync
	mtmsr r2
	sync
	mtsprg 1, r2
tgpr_clear_1200:
	mfsprg r2, 2
	mtcrf 0xFF, r2
	mfsprg r2, 1
	mtsprg 1, r2
	mtsprg 2, r3
	mtsprg 3, r4
	mfsrr0 r2
	mfsrr1 r4
	mfmsr r3
	ori r3, r3, 0x30            # MSR[IR|DR]
	mtsrr1 r3
	lis r3, TRKInterruptHandler@h
	ori r3, r3, TRKInterruptHandler@l
	mtsrr0 r3
	li r3, 0x1200
	rfi

	.org 0x1300                   # instruction address breakpoint
	mtsprg 1, r2
	mtsprg 2, r3
	mtsprg 3, r4
	mfsrr0 r2
	mfsrr1 r4
	mfmsr r3
	ori r3, r3, 0x30            # MSR[IR|DR]
	mtsrr1 r3
	lis r3, TRKInterruptHandler@h
	ori r3, r3, TRKInterruptHandler@l
	mtsrr0 r3
	li r3, 0x1300
	rfi

	.org 0x1400                   # system management
	mtsprg 1, r2
	mtsprg 2, r3
	mtsprg 3, r4
	mfsrr0 r2
	mfsrr1 r4
	mfmsr r3
	ori r3, r3, 0x30            # MSR[IR|DR]
	mtsrr1 r3
	lis r3, TRKInterruptHandler@h
	ori r3, r3, TRKInterruptHandler@l
	mtsrr0 r3
	li r3, 0x1400
	rfi

	.org 0x1600                   # reserved
	mtsprg 1, r2
	mtsprg 2, r3
	mtsprg 3, r4
	mfsrr0 r2
	mfsrr1 r4
	mfmsr r3
	ori r3, r3, 0x30            # MSR[IR|DR]
	mtsrr1 r3
	lis r3, TRKInterruptHandler@h
	ori r3, r3, TRKInterruptHandler@l
	mtsrr0 r3
	li r3, 0x1600
	rfi

	.org 0x1700                   # thermal management
	mtsprg 1, r2
	mtsprg 2, r3
	mtsprg 3, r4
	mfsrr0 r2
	mfsrr1 r4
	mfmsr r3
	ori r3, r3, 0x30            # MSR[IR|DR]
	mtsrr1 r3
	lis r3, TRKInterruptHandler@h
	ori r3, r3, TRKInterruptHandler@l
	mtsrr0 r3
	li r3, 0x1700
	rfi

	.org 0x1C00                   # reserved
	mtsprg 1, r2
	mtsprg 2, r3
	mtsprg 3, r4
	mfsrr0 r2
	mfsrr1 r4
	mfmsr r3
	ori r3, r3, 0x30            # MSR[IR|DR]
	mtsrr1 r3
	lis r3, TRKInterruptHandler@h
	ori r3, r3, TRKInterruptHandler@l
	mtsrr0 r3
	li r3, 0x1C00
	rfi

	.org 0x1D00                   # reserved
	mtsprg 1, r2
	mtsprg 2, r3
	mtsprg 3, r4
	mfsrr0 r2
	mfsrr1 r4
	mfmsr r3
	ori r3, r3, 0x30            # MSR[IR|DR]
	mtsrr1 r3
	lis r3, TRKInterruptHandler@h
	ori r3, r3, TRKInterruptHandler@l
	mtsrr0 r3
	li r3, 0x1D00
	rfi

	.org 0x1E00                   # reserved
	mtsprg 1, r2
	mtsprg 2, r3
	mtsprg 3, r4
	mfsrr0 r2
	mfsrr1 r4
	mfmsr r3
	ori r3, r3, 0x30            # MSR[IR|DR]
	mtsrr1 r3
	lis r3, TRKInterruptHandler@h
	ori r3, r3, TRKInterruptHandler@l
	mtsrr0 r3
	li r3, 0x1E00
	rfi

	.org 0x1F00                   # reserved
	mtsprg 1, r2
	mtsprg 2, r3
	mtsprg 3, r4
	mfsrr0 r2
	mfsrr1 r4
	mfmsr r3
	ori r3, r3, 0x30            # MSR[IR|DR]
	mtsrr1 r3
	lis r3, TRKInterruptHandler@h
	ori r3, r3, TRKInterruptHandler@l
	mtsrr0 r3
	li r3, 0x1F00
	rfi
gTRKInterruptVectorTableEnd:
	.size gTRKInterruptVectorTable,gTRKInterruptVectorTableEnd-gTRKInterruptVectorTable
