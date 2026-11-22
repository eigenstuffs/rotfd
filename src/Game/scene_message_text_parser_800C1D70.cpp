typedef unsigned long Word;

struct Name {
    Word value;
    Name(const char* text);
};
extern "C" Word fn_801F948C(Name*, const char*);
inline Name::Name(const char* text) { value = fn_801F948C(this, text); }

struct Message {
    Word name;
    char text[256];
    Message();
};
struct Buffer { char text[2048]; };

extern "C" {
extern const char lbl_803794F8[5], lbl_80379508[4], lbl_8037950C[2];
extern const Buffer lbl_802A19F8;
void fn_801F372C(void*, char*);
signed char fn_801F2E04(void*);
void fn_801F3168(void*, char*, int);
int strcmp(const char*, const char*);
char* strcat(char*, const char*);
char* strrchr(char*, int);
char* strcpy(char*, const char*);
void* __copy(void*, const void*, unsigned long);
void fn_800C1F44(void*, char*, const signed char*);
}

inline Message::Message() {
    name = 0;
    name = Name(lbl_803794F8).value;
    text[0] = 0;
}

struct Owner {
    char unknown00[0xC];
    Message* messages;
};

extern "C" signed char fn_800C1D70(Owner* self, void* stream, int index) {
    char token[256];
    Message message;
    Buffer buffer = lbl_802A19F8;

    fn_801F372C(stream, token);
    while ((unsigned char)token[0] != '{') {
        fn_801F372C(stream, token);
        if (fn_801F2E04(stream)) return 0;
    }
    while ((unsigned char)token[0] != '}') {
        fn_801F372C(stream, token);
        if (!strcmp(token, lbl_80379508)) {
            if (fn_801F2E04(stream)) return 0;
            fn_801F372C(stream, token);
            message.name = Name(token).value;
            break;
        }
    }
    while (1) {
        token[0] = 0;
        fn_801F3168(stream, token, 0);
        if ((unsigned char)token[0] == '}' || fn_801F2E04(stream)) break;
        fn_800C1F44(self, buffer.text, (const signed char*)token);
        strcat(buffer.text, lbl_8037950C);
    }
    char* last = strrchr(buffer.text, 10);
    if (last) *last = 0;
    strcpy(message.text, buffer.text);
    Message& target = self->messages[index];
    target.name = message.name;
    __copy(target.text, message.text, 255);
    return 1;
}
