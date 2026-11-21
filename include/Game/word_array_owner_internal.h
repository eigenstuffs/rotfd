#ifndef GAME_WORD_ARRAY_OWNER_INTERNAL_H
#define GAME_WORD_ARRAY_OWNER_INTERNAL_H

extern "C" {
extern char lbl_8028F698[];
extern char lbl_801EF5C8[];
void fn_8028FD50(void*, void*, unsigned long);
void fn_801EF610(void*, void*);
}

typedef unsigned long OwnedWord;
struct OwnedWordArray {
    int count, capacity;
    OwnedWord* data;
    void clear() {
        if (data) {
            for (int i = 0; i < count; ++i)
                data[i].~OwnedWord();
            if (data) {
                fn_8028FD50(lbl_8028F698, data, capacity * sizeof(OwnedWord));
                data = 0;
            }
            data = 0;
        }
    }
};

typedef char CheckOwnedWordArray[sizeof(OwnedWordArray) == 12 ? 1 : -1];
#endif
