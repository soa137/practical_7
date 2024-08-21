#include "c_api.h"
#include <src/matrix.h>


struct Matrix : public math::Matrix
{
public:
    Matrix(const struct math::Matrix &M) : math::Matrix(M){};
};

Matrix* MATRIXLIB_EXPORT math_createMatrix(int rows, int cols)
{
    return new Matrix(math::Matrix(rows, cols));
}

void MATRIXLIB_EXPORT math_deleteMatrix(Matrix *M)
{
    delete M;
}

real MATRIXLIB_EXPORT math_get(const Matrix *M, int row, int col)
{
    return M->operator()(row, col);
}

void MATRIXLIB_EXPORT math_set(Matrix *M, int row, int col, real val)
{
    M->operator()(row, col) = val;
}

Matrix* MATRIXLIB_EXPORT math_add(const Matrix *A, const Matrix *B)
{
    return new Matrix(*A + *B);
}

void MATRIXLIB_EXPORT math_add_assign(Matrix* M, const Matrix* A)
{
     M->operator+=(*A);
}

Matrix* MATRIXLIB_EXPORT math_subtract(const Matrix *A, const Matrix *B)
{
    return new Matrix(*A - *B);
}

void MATRIXLIB_EXPORT math_subtract_assign(Matrix* M, const Matrix* A)
{
     M->operator-=(*A);
}

Matrix* MATRIXLIB_EXPORT math_dot(const Matrix *A, const Matrix *B)
{
    return new Matrix(*A * *B);
}

void MATRIXLIB_EXPORT math_dot_assign(Matrix* M, const real val)
{
     M->operator*=(val);
}

void MATRIXLIB_EXPORT math_print(const Matrix *M)
{
    std::cout << *M;
}

void MATRIXLIB_EXPORT math_cin(Matrix *M)
{
    std::cin >> *M;
}