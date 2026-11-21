#include "Game/engine_menu_item_parser.h"

extern "C" void fn_8021C7F4(void* self, void* stream) {
    MenuParsedItem record;
    char token[128], text[128];
    strcpy(record.name, MenuItemStringView("MENU_ITEM"));
    record.keyword = "ITEM_KEYWORD";
    record.next = "ITEM_NEXT";
    record.previous = "ITEM_PREC";
    char* name;
    unsigned char flags = 0;
    fn_801F372C(stream, token);
    while (strcmp(token, lbl_8037AFD8) != 0) fn_801F372C(stream, token);
    while (strcmp(token, lbl_8037AFDC) != 0) {
        if (strcmp(token, lbl_8037AFE0) == 0) {
            name = record.name;
            name[0] = 0;
            fn_801F372C(stream, text);
            while (strcmp(text, lbl_8037AFD8) == 0) fn_801F372C(stream, text);
            while (strcmp(text, lbl_8037AFDC) != 0) {
                strcpy(name, text);
                fn_801F372C(stream, text);
            }
        }
        if (strcmp(token, lbl_8037AFE8) == 0) {
            while (fn_801F2F3C(stream) != '{') {}
            fn_801F372C(stream, token);
            record.next = token;
            while (fn_801F2F3C(stream) != '}') {}
        }
        if (strcmp(token, lbl_8037AFF0) == 0) {
            while (fn_801F2F3C(stream) != '{') {}
            fn_801F372C(stream, token);
            record.previous = token;
            while (fn_801F2F3C(stream) != '}') {}
        }
        if (strcmp(token, lbl_8037AFF8) == 0) {
            while (fn_801F2F3C(stream) != '{') {}
            fn_801F372C(stream, token);
            record.keyword = token;
            while (fn_801F2F3C(stream) != '}') {}
        }
        if (strcmp(token, lbl_8037B000) == 0) {
            fn_801F372C(stream, token);
            if (strcmp(token, lbl_8037B008) == 0) flags |= 1;
        }
        if (strcmp(token, lbl_8037B010) == 0) {
            fn_801F372C(stream, token);
            if (strcmp(token, lbl_8037B008) == 0) flags |= 2;
        }
        if (strcmp(token, lbl_8037B018) == 0) {
            fn_801F372C(stream, token);
            if (strcmp(token, lbl_8037B008) == 0) flags |= 4;
        }
        fn_801F372C(stream, token);
    }
    record.flags = flags;
    fn_8021C558(self, &record);
}
