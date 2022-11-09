#ifndef MAT_H
#define MAT_H
#include <iostream>

template <typename T, int N>
class Mat
{
private:
    T _data[N][N];

public:
    // Default constructor
    Mat()
    {
        // Generate identity matrix
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                _data[i][j] = i == j ? 1 : 0;
    }

    // Constructor that takes an array as argument
    Mat(T data[N][N])
    {
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                _data[i][j] = data[i][j];
    }

    // Addition and subtraction
    const Mat operator+(const Mat<T, N> &other)
    {
        Mat<T, N> result;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                result._data[i][j] = _data[i][j] + other._data[i][j];

        return result;
    }
    const Mat operator-(const Mat<T, N> &other)
    {
        Mat<T, N> result;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                result._data[i][j] = _data[i][j] - other._data[i][j];

        return result;
    }

    // Matrix multiplication
    const Mat operator*(const Mat<T, N> &other)
    {
        Mat<T, N> result;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
            {
                result._data[i][j] = 0;
                for (int k = 0; k < N; k++)
                    result._data[i][j] += (_data[i][k] * other._data[k][j]);
            }

        return result;
    }

    // ADD/SUB/MUL and assignment
    Mat operator+=(const Mat<T, N> &other)
    {
        *this = *this + other;
        return *this;
    }
    Mat operator-=(const Mat<T, N> &other)
    {
        *this = *this - other;
        return *this;
    }
    Mat operator*=(const Mat<T, N> &other)
    {
        *this = *this * other;
        return *this;
    }

    // Unary minus
    const Mat operator-()
    {
        Mat result;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                result._data[i][j] = -_data[i][j];

        return result;
    }

    // Function call operator
    const T &operator()(int i, int j)
    {
        return _data[i][j];
    }

    // Equality(comparison) operator
    const bool operator==(const Mat<T, N> &other)
    {
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                if (_data[i][j] != other._data[i][j])
                    return false;

        return true;
    }

    // Output stream operator
    friend std::ostream &operator<<(std::ostream &os, const Mat<T, N> &mat)
    {
        os << "{";
        for (int i = 0; i < N; i++)
        {
            os << "{";
            for (int j = 0; j < N; j++)
                os << mat._data[i][j] << ((N - 1 == j) ? "" : ", ");

            os << ((N - 1 == i) ? "}" : "}, ");
        }
        os << "}";

        return os;
    }
};
#endif