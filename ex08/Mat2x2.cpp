#include "Mat2x2.h"

// Default constructor
Mat2x2::Mat2x2()
{
    // Generate identity matrix
    for (int i = 0; i < _dim; i++)
        for (int j = 0; j < _dim; j++)
            _data[i][j] = i == j ? 1 : 0;
}

// Constructor that takes an array as argument
Mat2x2::Mat2x2(float data[_dim][_dim])
{
    for (int i = 0; i < _dim; i++)
        for (int j = 0; j < _dim; j++)
            _data[i][j] = data[i][j];
}

// Addition and subtraction
const Mat2x2 Mat2x2::operator+(const Mat2x2 &other)
{
    Mat2x2 result;
    for (int i = 0; i < _dim; i++)
        for (int j = 0; j < _dim; j++)
            result._data[i][j] = _data[i][j] + other._data[i][j];

    return result;
}
const Mat2x2 Mat2x2::operator-(const Mat2x2 &other)
{
    Mat2x2 result;
    for (int i = 0; i < _dim; i++)
        for (int j = 0; j < _dim; j++)
            result._data[i][j] = _data[i][j] - other._data[i][j];

    return result;
}

// Matrix multiplication
const Mat2x2 Mat2x2::operator*(const Mat2x2 &other)
{
    Mat2x2 result;
    for (int i = 0; i < _dim; i++)
        for (int j = 0; j < _dim; j++)
        {
            result._data[i][j] = 0;
            for (int k = 0; k < _dim; k++)
                result._data[i][j] += (_data[i][k] * other._data[k][j]);
        }

    return result;
}

// ADD/SUB/MUL and assignment
Mat2x2 &Mat2x2::operator+=(const Mat2x2 &other)
{
    *this = *this + other;
    return *this;
}
Mat2x2 &Mat2x2::operator-=(const Mat2x2 &other)
{
    *this = *this - other;
    return *this;
}
Mat2x2 &Mat2x2::operator*=(const Mat2x2 &other)
{
    *this = *this * other;
    return *this;
}
Mat2x2 &Mat2x2::operator*=(const float scalar)
{
    for (int i = 0; i < _dim; i++)
        for (int j = 0; j < _dim; j++)
            _data[i][j] *= scalar;

    return *this;
}

// Unary minus
const Mat2x2 Mat2x2::operator-()
{
    Mat2x2 result;
    for (int i = 0; i < _dim; i++)
        for (int j = 0; j < _dim; j++)
            result._data[i][j] = -_data[i][j];

    return result;
}

// Function call operator
const float &Mat2x2::operator()(int i, int j)
{
    return _data[i][j];
}

// Equality(comparison) operator
const bool Mat2x2::operator==(const Mat2x2 &other)
{
    for (int i = 0; i < _dim; i++)
        for (int j = 0; j < _dim; j++)
            if (_data[i][j] != other._data[i][j])
                return false;

    return true;
}

// Output stream operator
std::ostream &operator<<(std::ostream &os, const Mat2x2 &m)
{
    os << "{";
    for (int i = 0; i < m._dim; i++)
    {
        os << "{";
        for (int j = 0; j < m._dim; j++)
            os << m._data[i][j] << ((m._dim - 1 == j) ? "" : ", ");

        os << ((m._dim - 1 == i) ? "}" : "}, ");
    }
    os << "}";

    return os;
}