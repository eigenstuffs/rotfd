#ifndef GAME_BASE_DESTRUCTOR_INTERNAL_H
#define GAME_BASE_DESTRUCTOR_INTERNAL_H

struct BaseDestructorView {
    int unknown00, unknown04;
    void* table;
};
extern "C" {
extern char lbl_801EF5C8[];
void fn_801EF610(void*, void*);
}

#endif
