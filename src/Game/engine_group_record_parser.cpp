#pragma readonly_strings on
#include "Game/engine_group_record_parser.h"

extern "C" void fn_8021A340(void* self, void* stream) {
    GroupRecord_FQ record;
    char token[128];
    unsigned char flags = 0;
    fn_801F372C(stream, token);
    while (strcmp(token, lbl_8037AF20))
        fn_801F372C(stream, token);
    while (strcmp(token, lbl_8037AF64)) {
        if (!strcmp(token, lbl_8037AF24)) {
            while (fn_801F2F3C(stream) != '{') {}
            fn_801F372C(stream, token);
            record.next = token;
            while (fn_801F2F3C(stream) != '}') {}
        }
        if (!strcmp(token, lbl_8037AF2C)) {
            while (fn_801F2F3C(stream) != '{') {}
            fn_801F372C(stream, token);
            record.previous = token;
            while (fn_801F2F3C(stream) != '}') {}
        }
        if (!strcmp(token, lbl_8037AF34)) {
            while (fn_801F2F3C(stream) != '{') {}
            fn_801F372C(stream, token);
            record.keyword = token;
            while (fn_801F2F3C(stream) != '}') {}
        }
        if (!strcmp(token, lbl_8037AF3C)) {
            fn_801F372C(stream, token);
            if (!strcmp(token, lbl_8037AF44)) flags |= 1;
        }
        if (!strcmp(token, lbl_8037AF4C)) {
            fn_801F372C(stream, token);
            if (!strcmp(token, lbl_8037AF44)) flags |= 2;
        }
        if (!strcmp(token, lbl_8037AF54)) {
            fn_801F372C(stream, token);
            if (!strcmp(token, lbl_8037AF44)) flags |= 4;
        }
        if (!strcmp(token, lbl_8037AF5C)) {
            fn_801F2F54(stream, token);
            record.handle90 = GroupWrappedHandle_FQ(
                fn_80263308(lbl_801E9D24.resources, &GroupName_FQ(token)));
        }
        if (!strcmp(token, "FOREVERACCESS")) {
            fn_801F372C(stream, token);
            if (!strcmp(token, lbl_8037AF44)) flags |= 0x100;
        }
        fn_801F372C(stream, token);
    }
    record.flags = flags;
    fn_8021AFE0(self, &record);
}
