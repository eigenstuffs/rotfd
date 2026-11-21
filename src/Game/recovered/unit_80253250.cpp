extern "C" {
extern char lbl_801EF5C8[];
extern char lbl_802AEB18[];
extern char lbl_802AEB38[];
void* fn_801EFA1C(void*, unsigned long, const char*, const char*, int, int);
void fn_801EF610(void*, void*);

struct Str_80253250 {
    char pad[0xC];
    char* data;
    int len;
};

void fn_80253250(Str_80253250* self) {
    int n = 0;
    int i;
    for (i = 0; i < self->len; i++) {
        char c = self->data[i];
        if (c != '[' && c != ']') {
            if (c == ';') n++;
            n++;
        }
    }
    char* buf = (char*)fn_801EFA1C(lbl_801EF5C8, n + 1, lbl_802AEB18, lbl_802AEB38, 0x28, 4);
    int j = 0;
    for (i = 0; i < self->len; i++) {
        char c = self->data[i];
        if (c != '[' && c != ']') {
            if (c == ';') {
                buf[j++] = 10;
                buf[j++] = 13;
            } else {
                buf[j++] = c;
            }
        }
    }
    buf[j] = 0;
    fn_801EF610(lbl_801EF5C8, self->data);
    self->data = buf;
    self->len = n;
}
}
