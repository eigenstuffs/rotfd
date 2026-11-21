#include "Game/engine_owner_matrix_assignment.h"

Matrix_8023E910& Matrix_8023E910::operator=(const Matrix_8023E910& source)
{
    static_cast<MatrixCopyStorage_8023E910&>(*this) =
        static_cast<const MatrixCopyStorage_8023E910&>(source);
    return *this;
}
