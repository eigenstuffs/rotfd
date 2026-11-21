/* GSQE78 retained MSL file_io.c. Adapted from pinned Strikers/TWW
 * references; recovered retained paths are documented in docs/notes/msl-file-io.md. */
#include "stdio_internal.h"
extern int fseek(FILE*, long, int);
extern void __stdio_atexit(void);
extern void clearerr(FILE*);
extern int __flush_buffer(FILE*, size_t*);
extern void __init_file(FILE*, file_modes, char*, size_t);
extern int __open_file(const char*, file_modes, __file_handle*);
int __get_file_modes(const char*, file_modes*);

FILE* __find_unopened_file(void);

int fclose(FILE* file)
{
    int flush_result, close_result;

    if (file == NULL)
        return (-1);
    if (file->file_mode.file_kind == __closed_file)
        return (0);

    flush_result = fflush(file);

    close_result = (*file->close_fn)(file->handle);

    file->file_mode.file_kind = __closed_file;
    file->handle = 0;

    if (file->file_state.free_buffer)
        __msl_free((FILE*)file->buffer);
    return ((flush_result || close_result) ? -1 : 0);
}

int fflush(FILE* file)
{
    int pos;

    if (file == NULL)
    {
        return __flush_all();
    }

    if (file->file_state.error != 0 || file->file_mode.file_kind == __closed_file)
    {
        return -1;
    }

    if (file->file_mode.io_mode == __read)
    {
        return 0;
    }

    if (file->file_state.io_state >= __rereading)
    {
        file->file_state.io_state = __reading;
    }

    if (file->file_state.io_state == __reading)
    {
        file->buffer_length = 0;
    }

    if (file->file_state.io_state != __writing)
    {
        file->file_state.io_state = __neutral;
        return 0;
    }

    if (file->file_mode.file_kind != __disk_file)
    {
        pos = 0;
    }
    else
    {
        pos = ftell(file);
    }

    if (__flush_buffer(file, 0) != 0)
    {
        file->file_state.error = 1;
        file->buffer_length = 0;
        return -1;
    }

    file->file_state.io_state = __neutral;
    file->position = pos;
    file->buffer_length = 0;
    return 0;
}

FILE* freopen(const char*, const char*, FILE*);
FILE* fopen(const char* filename, const char* mode)
{
    return freopen(filename, mode, __find_unopened_file());
}

FILE* freopen(const char* filename, const char* mode, FILE* file)
{
    file_modes modes;
    __stdio_atexit();
    if (file == NULL)
        return NULL;
    if (file && file->file_mode.file_kind != __closed_file)
    {
        fflush(file);
        (*file->close_fn)(file->handle);
        file->file_mode.file_kind = __closed_file;
        file->handle = 0;
        if (file->file_state.free_buffer)
            __msl_free(file->buffer);
    }
    clearerr(file);
    if (!__get_file_modes(mode, &modes))
        return NULL;
    __init_file(file, modes, NULL, 0x1000);
    if (__open_file(filename, modes, &file->handle))
    {
        file->file_mode.file_kind = __closed_file;
        if (file->file_state.free_buffer)
            __msl_free(file->buffer);
        return NULL;
    }
    if (modes.io_mode & __append)
        fseek(file, 0, SEEK_END);
    return file;
}

int __get_file_modes(const char* mode, file_modes* modes)
{
    int mode_char;
    const char* mode_str;
    unsigned char open_mode;
    int io_mode;

    modes->file_kind = __disk_file;
    modes->file_orientation = 0;
    modes->binary_io = 0;

    mode_char = *mode++;

    switch (mode_char)
    {
    case 'r':
        open_mode = 0;
        break;
    case 'w':
        open_mode = 2;
        break;
    case 'a':
        open_mode = 1;
        break;
    default:
        return 0;
    }

    mode_str = mode + 1;
    modes->open_mode = open_mode;

    switch (*mode)
    {
    case 'b':
        modes->binary_io = 1;
        if (*mode_str == '+')
        {
            mode_char = (mode_char << 8) | '+';
        }
        break;
    case '+':
        mode_char = (mode_char << 8) | '+';
        if (*mode_str == 'b')
        {
            modes->binary_io = 1;
        }
        break;
    }

    switch (mode_char)
    {
    case 'r':
        io_mode = __read;
        break;
    case 'w':
        io_mode = __write;
        break;
    case 'a':
        io_mode = __write | __append;
        break;
    case ('r' << 8) | '+':
        io_mode = __read_write;
        break;
    case ('w' << 8) | '+':
        io_mode = __read_write;
        break;
    case ('a' << 8) | '+':
        io_mode = __read | __write | __append;
        break;
    }

    modes->io_mode = io_mode;
    return 1;
}
