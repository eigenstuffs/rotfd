#ifndef GAME_ENGINE_GROUP_RECORD_PARSER_H
#define GAME_ENGINE_GROUP_RECORD_PARSER_H

typedef unsigned long Word;

struct Handle_801F7F10 {
    Word word;
    Handle_801F7F10();
    ~Handle_801F7F10();
};
struct GroupManager_FQ;
struct GroupGlobals_FQ {
    char unknown00[0x118];
    GroupManager_FQ* manager;
    char unknown11C[0x30];
    void* resources;
};

extern "C" {
extern GroupGlobals_FQ lbl_801E9D24;
extern const char lbl_8037AF20[2], lbl_8037AF24[8], lbl_8037AF2C[8];
extern const char lbl_8037AF34[8], lbl_8037AF3C[7], lbl_8037AF44[5];
extern const char lbl_8037AF4C[5], lbl_8037AF54[5], lbl_8037AF5C[7];
extern const char lbl_8037AF64[2];
void fn_801F86C8(GroupManager_FQ*, const void*, short);
Word fn_801F948C(void*, const char*);
char* strcpy(char*, const char*);
int strcmp(const char*, const char*);
void fn_801F372C(void*, char*);
signed char fn_801F2F3C(void*);
void fn_801F2F54(void*, char*);
void fn_8021AFE0(void*, const void*);
}

struct GroupZeroHandle_FQ : Handle_801F7F10 {
    GroupZeroHandle_FQ() { word = 0; }
};
extern "C" GroupZeroHandle_FQ fn_80263308(void*, const void*);

struct GroupWrappedHandle_FQ : GroupZeroHandle_FQ {
    GroupWrappedHandle_FQ() { word = 0; }
    GroupWrappedHandle_FQ(const Handle_801F7F10& h) {
        word = h.word;
        fn_801F86C8(lbl_801E9D24.manager, &h, 1);
    }
    void operator=(const GroupWrappedHandle_FQ& h) {
        fn_801F86C8(lbl_801E9D24.manager, this, -1);
        word = h.word;
        fn_801F86C8(lbl_801E9D24.manager, &h, 1);
    }
};

struct GroupName_FQ {
    Word word;
    GroupName_FQ() { word = 0; }
    GroupName_FQ(const char* text) { word = fn_801F948C(this, text); }
    void operator=(const char* text) { word = fn_801F948C(this, text); }
};
struct GroupStringView_FQ {
    const char* text;
    GroupStringView_FQ(const char* value) : text(value) {}
    operator const char*() const { return text; }
};
struct GroupRecordBase_FQ {
    char name[128];
    GroupName_FQ keyword, next, previous;
    unsigned short flags;
    GroupRecordBase_FQ() : flags(0) {
        strcpy(name, GroupStringView_FQ("MENU_ITEM"));
        keyword = "ITEM_KEYWORD";
        next = "ITEM_NEXT";
        previous = "ITEM_PREC";
    }
};
struct GroupRecord_FQ : GroupRecordBase_FQ {
    GroupWrappedHandle_FQ handle90;
    int value94;
    GroupWrappedHandle_FQ handle98;
    GroupRecord_FQ() {
        value94 = -1;
        handle98 = GroupWrappedHandle_FQ();
    }
};

extern "C" void fn_8021A340(void* self, void* stream);

#endif
