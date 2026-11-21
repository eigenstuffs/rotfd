/* MSL termination support reconstructed for GSQE78.
 * Based on the pinned Melee and SMS abort_exit.c references; target abort
 * path and retained callback ownership recovered from original instructions.
 * Provenance: reference/melee-msl/, reference/sms-msl/.
 * Original text: 0x80120FB0..0x80121104.
 */
#define NULL 0
extern void __destroy_global_chain(void);
extern void (*_dtors[])(void);
extern void _ExitProcess(void);
extern int raise(int);
static void (*__atexit_funcs[64])(void);
void (*__console_exit)(void);
void (*__stdio_exit)(void);
static int __atexit_curr_func;
int __aborting;

static inline void __exit(int status)
{
    while (__atexit_curr_func > 0)
        __atexit_funcs[--__atexit_curr_func]();
    if (__console_exit != NULL) {
        __console_exit();
        __console_exit = NULL;
    }
    _ExitProcess();
}

void abort(void)
{
    raise(1);
    __aborting = 1;
    __exit(1);
}

void exit(int status)
{
    void (**dtor)(void);
    if (!__aborting) {
        __destroy_global_chain();
        dtor = _dtors;
        while (*dtor != NULL) {
            (*dtor)();
            dtor++;
        }
        if (__stdio_exit != NULL) {
            __stdio_exit();
            __stdio_exit = NULL;
        }
    }
    __exit(status);
}
