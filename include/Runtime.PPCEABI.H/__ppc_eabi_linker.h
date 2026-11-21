#ifndef __PPC_EABI_LINKER_H
#define __PPC_EABI_LINKER_H

typedef struct __eti_init_info {
    void* eti_start;
    void* eti_end;
    unsigned long code_size;
} __eti_init_info;

extern __eti_init_info _eti_init_info[];

#endif /* __PPC_EABI_LINKER_H */
