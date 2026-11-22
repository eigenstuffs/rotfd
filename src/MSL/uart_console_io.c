#include "stdio_internal.h"

extern int InitializeUART(unsigned long baud_rate);
extern int WriteUARTN(const void* buffer, unsigned long count);
extern int __TRK_write_console(__file_handle, unsigned char*, size_t*, __idle_proc);
static inline int __init_uart_console(void);

int __write_console(__file_handle file, unsigned char* buffer, size_t* count,
                    __idle_proc idle_proc)
{
    if (__init_uart_console() != 0) {
        return 1;
    }
    if (WriteUARTN(buffer, *count) != 0) {
        *count = 0;
        return 1;
    }
    __TRK_write_console(file, buffer, count, idle_proc);
    return 0;
}

static inline int __init_uart_console(void)
{
    static int initialized = 0;
    int ret = 0;

    if (initialized == 0) {
        ret = InitializeUART(0xE100);
        if (ret == 0) {
            initialized = 1;
        }
    }
    return ret;
}
