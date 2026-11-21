/* MSL signal handling reconstructed from GSQE78 instructions and data.
 * Original text: 0x80127D1C..0x80127E08.
 * The target maintains six single-use signal handlers.
 */
typedef void (*signal_handler)(int);
#define SIG_DFL ((signal_handler)0)
#define SIG_IGN ((signal_handler)1)
#define SIG_ERR ((signal_handler)-1)
#define SIGABRT 1
extern void exit(int);
extern int errno;
static signal_handler signal_funcs[6];

signal_handler signal(int sig, signal_handler func)
{
    signal_handler old;
    if (sig < 1 || sig > 6) {
        errno = 26;
        return SIG_ERR;
    }
    old = signal_funcs[sig - 1];
    signal_funcs[sig - 1] = func;
    return old;
}

int raise(int sig)
{
    signal_handler func;
    if (sig < 1 || sig > 6)
        return -1;
    func = signal_funcs[sig - 1];
    if (func != SIG_IGN)
        signal_funcs[sig - 1] = SIG_DFL;
    if (func == SIG_IGN || (func == SIG_DFL && sig == SIGABRT))
        return 0;
    if (func == SIG_DFL)
        exit(0);
    (*func)(sig);
    return 0;
}
