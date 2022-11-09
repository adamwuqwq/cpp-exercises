#include "Mat.h"
#include <random>
#include <cmath>

#define RND_MAX 10
#define RND_MIN -10

// Function to generate random matrices
template <typename T, int N>
Mat<T, N> mat_gen()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dist(RND_MIN, RND_MAX);
    T result[N][N];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            result[i][j] = floor(dist(gen) *100) /100;

    return Mat<T,N>(result);
}

int main(void)
{
    // Identity matrices
    Mat<int, 2> id_mat_int_2;
    Mat<float, 3> id_mat_float_3;
    Mat<double, 4> id_mat_double_4;

    // Declare matrices for test
    Mat<int, 2> mat_int_2_1 = mat_gen<int, 2>();
    Mat<int, 2> mat_int_2_2 = mat_gen<int, 2>();
    Mat<float, 3> mat_float_3_1 = mat_gen<float, 3>();
    Mat<float, 3> mat_float_3_2 = mat_gen<float, 3>();
    Mat<double, 4> mat_double_4_1 = mat_gen<double, 4>();
    Mat<double, 4> mat_double_4_2 = mat_gen<double, 4>();

    // Test for addition and subtraction
    std::cout << mat_int_2_1 << " + " << mat_int_2_2 << " = " << mat_int_2_1 + mat_int_2_2 << std::endl;
    std::cout << mat_float_3_1 << " + " << mat_float_3_2 << " = " << mat_float_3_1 + mat_float_3_2 << std::endl;
    std::cout << mat_double_4_1 << " - " << mat_double_4_2 << " = " << mat_double_4_1 - mat_double_4_2 << std::endl;

    // Test for matrix multiplication
    std::cout << mat_int_2_1 << " * " << id_mat_int_2 << " = " << mat_int_2_1 * id_mat_int_2 << std::endl;
    std::cout << mat_float_3_1 << " * " << mat_float_3_2 << " = " << mat_float_3_1 * mat_float_3_2 << std::endl;
    std::cout << mat_double_4_1 << " * " << mat_double_4_2 << " = " << mat_double_4_1 * mat_double_4_2 << std::endl;

    // Test for compound add / sub / mul
    std::cout << mat_int_2_1 << " += " << mat_int_2_2;
    mat_int_2_1 += mat_int_2_2;
    std::cout << ": mat_int_2_1 = " << mat_int_2_1 << std::endl;
    std::cout << mat_float_3_1 << " -= " << id_mat_float_3;
    mat_float_3_1 -= id_mat_float_3;
    std::cout << ": mat_float_3_1 = " << mat_float_3_1 << std::endl;
    std::cout << mat_double_4_1 << " *= " << id_mat_double_4;
    mat_double_4_1 *= id_mat_double_4;
    std::cout << ": mat_double_4_1 = " << mat_double_4_1 << std::endl;

    // Test for unary minus
    std::cout << "-mat_int_2_2 = " << -mat_int_2_2 << std::endl;
    std::cout << "-mat_float_3_2 = " << -mat_float_3_2 << std::endl;
    std::cout << "-mat_double_4_2 = " << -mat_double_4_2 << std::endl;

    // Test for function call operator
    std::cout << mat_float_3_1 << ": " << std::endl;
    std::cout << "mat_float_3_1 (1,1): " << mat_float_3_1(1, 1) << std::endl;
    std::cout << "mat_float_3_1 (2,1): " << mat_float_3_1(2, 1) << std::endl;
    std::cout << "mat_float_3_1 (2,2): " << mat_float_3_1(2, 2) << std::endl;

    // Test for equality(comparison) operator
    double val_double_3[3][3] = {{-1.1, 2.2, 3.3}, {4.4, -5.5, 6.6}, {7.7, 8.8, -9.9}};
    Mat<double, 3> mat_double_3_1(val_double_3);
    Mat<double, 3> mat_double_3_2(val_double_3);
    Mat<double, 3> mat_double_3_3 = mat_gen<double, 3>();
    std::cout << mat_double_3_1 << " == " << mat_double_3_2 << ": " << ((mat_double_3_1 == mat_double_3_2) ? "true" : "false") << std::endl;
    std::cout << mat_double_3_2 << " == " << mat_double_3_3 << ": " << ((mat_double_3_2 == mat_double_3_3) ? "true" : "false") << std::endl;

    return 0;
}