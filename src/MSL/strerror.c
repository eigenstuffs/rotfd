extern char* strcpy(char*, const char*);
extern int sprintf(char*, const char*, ...);
static char* strerror_impl(int, char*);

char* strerror(int errnum)
{
    static char buffer[64];
    return strerror_impl(errnum, buffer);
}

static char* strerror_impl(int errnum, char* buffer)
{
    switch (errnum)
    {
    case 7:
        /* Retain the observed leading NUL in the pooled message data. */
        strcpy(buffer, "\0Argument list too long" + 1);
        break;
    case 13:
        strcpy(buffer, "Permission denied");
        break;
    case 11:
        strcpy(buffer, "Resource temporarily unavailable");
        break;
    case 9:
        strcpy(buffer, "Bad file descriptor");
        break;
    case 16:
        strcpy(buffer, "Device busy");
        break;
    case 10:
        strcpy(buffer, "No child processes");
        break;
    case 35:
        strcpy(buffer, "Resource deadlock avoided");
        break;
    case 33:
        strcpy(buffer, "Numerical argument out of domain");
        break;
    case 17:
        strcpy(buffer, "File exists");
        break;
    case 14:
        strcpy(buffer, "Bad address");
        break;
    case 27:
        strcpy(buffer, "File too large");
        break;
    case 40:
        strcpy(buffer, "File Position Error");
        break;
    case 88:
        strcpy(buffer, "Wide character encoding error");
        break;
    case 4:
        strcpy(buffer, "Interrupted system call");
        break;
    case 22:
        strcpy(buffer, "Invalid argument");
        break;
    case 5:
        strcpy(buffer, "Input/output error");
        break;
    case 21:
        strcpy(buffer, "Is a directory");
        break;
    case 24:
        strcpy(buffer, "Too many open files");
        break;
    case 31:
        strcpy(buffer, "Too many links");
        break;
    case 36:
        strcpy(buffer, "File name too long");
        break;
    case 23:
        strcpy(buffer, "Too many open files in system");
        break;
    case 19:
        strcpy(buffer, "Operation not supported by device");
        break;
    case 2:
        strcpy(buffer, "No such file or directory");
        break;
    case 0:
        strcpy(buffer, "No error detected");
        break;
    case 8:
        strcpy(buffer, "Exec format error");
        break;
    case 77:
        strcpy(buffer, "No locks available");
        break;
    case 12:
        strcpy(buffer, "Cannot allocate memory");
        break;
    case 28:
        strcpy(buffer, "No space left on device");
        break;
    case 38:
        strcpy(buffer, "Function not implemented");
        break;
    case 20:
        strcpy(buffer, "Not a directory");
        break;
    case 39:
        strcpy(buffer, "Directory not empty");
        break;
    case 25:
        strcpy(buffer, "Inappropriate ioctl for device");
        break;
    case 6:
        strcpy(buffer, "Device not configured");
        break;
    case 1:
        strcpy(buffer, "Operation not permitted");
        break;
    case 32:
        strcpy(buffer, "Broken pipe");
        break;
    case 34:
        strcpy(buffer, "Result too large");
        break;
    case 30:
        strcpy(buffer, "Read-only file system");
        break;
    case 26:
        strcpy(buffer, "Signal error");
        break;
    case 29:
        strcpy(buffer, "Illegal seek");
        break;
    case 3:
        strcpy(buffer, "No such process");
        break;
    case 99:
        strcpy(buffer, "Unknown error");
        break;
    case 18:
        strcpy(buffer, "Cross-device link");
        break;
    default:
        sprintf(buffer, "Unknown Error (%d)", errnum);
        break;
    }
    return buffer;
}
