// Reconstructed GSQE78 filename splitting and database-path conversion.
typedef unsigned long u32;
struct Globals {
    u32 unknown0;
    char path[128];
    char unknown84[0x190 - 0x84];
    char base[128];
    signed char remap;
};
extern "C" {
extern Globals lbl_801E9D24;
void fn_801F459C(char*);
char* strcpy(char*, const char*);
char* strncpy(char*, const char*, u32);
char* strcat(char*, const char*);
char* strchr(const char*, int);
char* strstr(const char*, const char*);
int strncmp(const char*, const char*, u32);
u32 strlen(const char*);
extern const char lbl_8037A97C[4];
extern const char lbl_8037A980[] = "_MASTER";
}

extern "C" void fn_80207A14(const char* input, char* output)
{
    if (strncmp(input, lbl_8037A97C, 3) == 0) {
        u32 i;
        const char* path = lbl_801E9D24.path;
        strcpy(output, path);
        for (i = 0; i < strlen(input) - 3; ++i) {
            int c = (signed char)input[i + 3];
            if (c == '>')
                output[i + strlen(path)] = '\\';
            else
                output[i + strlen(path)] = c;
        }
        output[i + strlen(path)] = 0;
    } else {
        u32 i;
        for (i = 0; i < strlen(input); ++i) {
            if (input[i] == '>')
                output[i] = '\\';
            else
                output[i] = input[i];
        }
        output[i] = 0;
    }
    if (lbl_801E9D24.remap) {
        fn_801F459C(output);
        char* found = strstr(output, lbl_8037A980);
        if (found) {
            char temp[128];
            strcpy(temp, lbl_801E9D24.base);
            char* suffix = found + strlen(lbl_8037A980);
            strcat(temp, suffix);
            strcpy(output, temp);
        }
    }
}

extern "C" void fn_80207974(const char* input, char* output)
{
    if ((signed char)*input == 0) {
        *output = 0;
        return;
    }
    strcpy(output, lbl_8037A97C);
    strcat(output, input + strlen(lbl_801E9D24.path));
    for (char* p = strchr(output, '\\'); p; p = strchr(p, '\\'))
        *p = '>';
}

extern "C" void fn_802077B4(const char* input, char* drive, char* directory,
                            char* filename, char* extension)
{
    char drivePart[64], directoryPart[128], namePart[128], extensionPart[128];
    drivePart[0] = 0;
    directoryPart[0] = 0;
    namePart[0] = 0;
    extensionPart[0] = 0;
    if ((signed char)*input == 0)
        return;
    int at = strlen(input);
    int length = at;
    for (; at != 0 && input[at] != '.'; --at) {}
    if (at != 0) {
        strncpy(extensionPart, input + at, length - at);
        extensionPart[length - at] = 0;
    } else {
        at = length;
    }
    length = at;
    for (; input[at] != '\\' && at >= 0; --at) {}
    ++at;
    strncpy(namePart, input + at, length - at);
    namePart[length - at] = 0;
    if (at > 0) {
        length = at;
        for (; at != 0 && (signed char)input[at - 1] != ':'; --at) {}
        strncpy(directoryPart, input + at, length - at);
        directoryPart[length - at] = 0;
        strncpy(drivePart, input, at);
        drivePart[at] = 0;
    }
    if (drive)
        strcpy(drive, drivePart);
    if (directory)
        strcpy(directory, directoryPart);
    if (filename)
        strcpy(filename, namePart);
    if (extension)
        strcpy(extension, extensionPart);
}
