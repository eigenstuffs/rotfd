/* Append message text to a buffer, decoding "\x"/"\X" two-digit hex escapes. */
extern "C" {
extern const char lbl_80379510[3], lbl_80379514[3]; /* "\\x", "\\X" */
unsigned long strlen(const char*);
int strncmp(const char*, const char*, unsigned long);
}

#define IS_HEX_DIGIT(c) \
    (((c) >= '0' && (c) <= '9') || ((c) >= 'a' && (c) <= 'f') || ((c) >= 'A' && (c) <= 'F'))

/* The non-const text pointer is required: with const char* the compiler
   sign-extends the initial character copy. */
extern "C" void fn_800C1F44(void* self, char* dest, char* text) {
    dest += strlen(dest);
    while (*text) {
        char c = *text;
        if (!strncmp(lbl_80379510, text, 2) || !strncmp(lbl_80379514, text, 2)) {
            if (IS_HEX_DIGIT(text[2])) {
                text += 2;
                if (*text >= 'a') c = *text - 'a' + 10;
                else if (*text >= 'A') c = *text - 'A' + 10;
                else c = *text - '0';
                if (IS_HEX_DIGIT(text[1])) {
                    text++;
                    c <<= 4;
                    if (*text >= 'a') c |= *text - 'a' + 10;
                    else if (*text >= 'A') c |= *text - 'A' + 10;
                    else c |= *text - '0';
                }
                if ((unsigned char)c == 0x83) c = '#';
            }
        }
        *dest = c;
        text++;
        *++dest = 0;
    }
}
