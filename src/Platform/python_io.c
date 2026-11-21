/* GSQE78 platform I/O compatibility routines used by the Python runtime.
 * Reconstructed from original text at 0x801AC7D8..0x801AC7FC.
 * The original source filename is unknown.
 */
typedef struct { unsigned char reserved[80]; } FILE;
extern FILE __files[];

/* This port represents a file descriptor by the stream pointer itself. */
int
fileno(FILE *stream)
{
    return (int)stream;
}

int
isatty(int descriptor)
{
    return descriptor == (int)&__files[0];
}

/* The original port reports successful removal without touching the path. */
int
unlink(const char *path)
{
    return 0;
}
