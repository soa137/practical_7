#include <iostream>

struct Matrix;

#ifdef __cplusplus
extern "C"
{
#endif
    extern Matrix*  math_createMatrix(int, int);
    extern void  math_deleteMatrix(Matrix *);
    extern double  math_get(Matrix *, int, int);
    extern void  math_set(Matrix *, int, int, double);
    extern void  math_print(Matrix *);

    extern Matrix*  math_add(Matrix *, Matrix *);
    extern void  math_add_assign(Matrix *, Matrix *);
    extern Matrix*  math_subtract(Matrix *, Matrix *);
    extern void  math_subtract_assign(Matrix *, Matrix *);
    extern Matrix*  math_dot(Matrix *, Matrix *);
    extern void  math_dot_assign(Matrix *, double);
    extern void  math_cin(Matrix *);
#ifdef __cplusplus
}
#endif

int main()
{
    Matrix *m1 = math_createMatrix(3, 3);

    math_set(m1, 0, 0, 1.);
    math_set(m1, 1, 1, 1.);
    math_print(m1);

    Matrix *m2 = math_createMatrix(0, 0);
    std::cout << "Enter the number of rows and columns for the matrix:" << std::endl;
    math_cin(m2);
    math_set(m2, 0, 0, 2.);
    math_set(m2, 1, 1, 3.);
    math_print(m2);

    std::cout << std::endl;

    Matrix *m3 = math_add(m1, m2);
    math_print(m3);

    std::cout << std::endl;

    Matrix *m4 = math_subtract(m3, m2);
    math_print(m4);

    std::cout << std::endl;

    Matrix *m5 = math_dot(m3, m2);
    math_print(m5);

    std::cout << std::endl;

    math_add_assign(m5, m3);
    math_print(m5);

    std::cout << std::endl;

    math_subtract_assign(m5, m4);
    math_print(m5);

    std::cout << std::endl;

    math_dot_assign(m5, 3.0);
    math_print(m5);

    // в конце обязательно вызываем деструктор
    math_deleteMatrix(m1);
    math_deleteMatrix(m2);
    math_deleteMatrix(m3);
    math_deleteMatrix(m4);
    math_deleteMatrix(m5);
    return 0;
}