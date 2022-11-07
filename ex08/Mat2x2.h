#ifndef MAT2X2_H
#define MAT2X2_H
#include <iostream>

class Mat2x2
{
private:
    float _data[2][2];
    const static int _dim = 2;

public:
    // Default constructor
    Mat2x2();

    // Constructor that takes an array as argument
    Mat2x2(float data[_dim][_dim]);

    // Addition and subtraction
    const Mat2x2 operator+(const Mat2x2 &other);
    const Mat2x2 operator-(const Mat2x2 &other);

    // Matrix multiplication
    const Mat2x2 operator*(const Mat2x2 &other);

    // add/sub/mul and assignment
    Mat2x2 &operator+=(const Mat2x2 &other);
    Mat2x2 &operator-=(const Mat2x2 &other);
    Mat2x2 &operator*=(const Mat2x2 &other);
    Mat2x2 &operator*=(const float scalar);

    // Unary minus
    const Mat2x2 operator-();

    // Function call operator
    const float &operator()(int i, int j);

    // Equality(comparison) operator
    const bool operator==(const Mat2x2 &other);

    // Output stream operator
    friend std::ostream &operator<<(std::ostream &os, const Mat2x2 &m);
};
#endif