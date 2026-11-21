#ifndef GAME_ENGINE_OWNER_MATRIX_ASSIGNMENT_H
#define GAME_ENGINE_OWNER_MATRIX_ASSIGNMENT_H

struct MatrixCopyStorage_8023E910 {
    unsigned long words[16];
};

// A complete 64-byte copy view of the matrix allocation.
struct Matrix_8023E910 : MatrixCopyStorage_8023E910 {
    Matrix_8023E910& operator=(const Matrix_8023E910&);
};

#endif
