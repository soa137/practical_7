#pragma once
#include <vector>
#include <iostream>

namespace math
{
     typedef double real;
    class Matrix
    {
    private:
        int cols_;
        int rows_;
        std::vector<real> mvec_;
    public:
        Matrix(){};

        Matrix(int rows, int cols) : cols_(cols), rows_(rows), mvec_(std::vector<real>(rows * cols)) {};

        real& operator()(int row, int col);

        real operator()(int row, int col) const;

        void print() const;

        friend Matrix operator+(const Matrix& A, const Matrix& B);

        friend Matrix operator-(const Matrix& A, const Matrix& B);

        friend Matrix operator*(const Matrix& A, const Matrix& B);

        // метод для перегрузки оператора += (сложение матриц с присваиванием)
        Matrix& operator+=(const Matrix& A);

        // метод для перегрузки оператора −= (вычитание матриц с присваиванием)
        Matrix& operator-=(const Matrix& A);

        // метод для перегрузки оператора *= (умножение матрицы на число с присваиванием)
        Matrix& operator*=(const real r);

        // метод для перегрузки операторов <<
        friend std::ostream& operator<< (std::ostream &out, const Matrix &A);

        // метод для перегрузки операторов >>
        friend std::istream& operator>> (std::istream &in, Matrix &A);
    };
    
    
    
}