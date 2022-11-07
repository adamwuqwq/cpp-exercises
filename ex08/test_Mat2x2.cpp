#include "Mat2x2.h"

int main(void)
{
    // Identity matrix
    Mat2x2 mat_1;

    // Assign value to mat_2, mat_3
    float mat_val_2[2][2] = {{1, 4}, {5, 7}};
    float mat_val_3[2][2] = {{2, 9}, {3, -1}};
    float mat_val_4[2][2] = {{1, 4}, {5, 7}};
    Mat2x2 mat_2(mat_val_2);
    Mat2x2 mat_3(mat_val_3);
    Mat2x2 mat_4(mat_val_4);

    // Test for addition and subtraction
    std::cout << mat_1 << " + " << mat_2 << " = " << mat_1 + mat_2 << std::endl;
    std::cout << mat_3 << " + " << mat_4 << " = " << mat_3 + mat_4 << std::endl;
    std::cout << mat_2 << " - " << mat_3 << " = " << mat_2 - mat_3 << std::endl;
    std::cout << mat_4 << " - " << mat_1 << " = " << mat_4 - mat_1 << std::endl;

    // Test for matrix multiplication
    std::cout << mat_1 << " * " << mat_2 << " = " << mat_1 * mat_2 << std::endl;
    std::cout << mat_3 << " * " << mat_1 << " = " << mat_3 * mat_1 << std::endl;
    std::cout << mat_2 << " * " << mat_4 << " = " << mat_2 * mat_4 << std::endl;

    // Test for compound add / sub / mul
    std::cout << mat_1 << " += " << mat_3;
    mat_1 += mat_3;
    std::cout << ": mat_1 = " << mat_1 << std::endl;
    std::cout << mat_2 << " -= " << mat_4;
    mat_2 -= mat_4;
    std::cout << ": mat_2 = " << mat_2 << std::endl;
    std::cout << mat_4 << " *= " << mat_1;
    mat_4 *= mat_1;
    std::cout << ": mat_4 = " << mat_4 << std::endl;

    // Test for unary minus
    std::cout << "-mat_3 = " << -mat_3 << std::endl;
    std::cout << "-mat_1 = " << -mat_1 << std::endl;

    // Test for function call operator
    std::cout << mat_3 << ": " << std::endl;
    std::cout << "mat_3(1,1): " << mat_3(1, 1) << std::endl;
    std::cout << "mat_3(0,1): " << mat_3(0, 1) << std::endl;

    // Test for equality(comparison) operator
    float mat_val_5[2][2] = {{3, 9}, {3, 0}};
    Mat2x2 mat_5(mat_val_5);
    std::cout << mat_5 << " == " << mat_1 << ": " << ((mat_5 == mat_1) ? "true" : "false") << std::endl;
    std::cout << mat_3 << " == " << mat_4 << ": " << ((mat_3 == mat_4) ? "true" : "false") << std::endl;

    return 0;
}